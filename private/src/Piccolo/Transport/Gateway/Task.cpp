//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Transports
{
  namespace Piccolo
  {
    namespace Gateway
    {
      using DUNE_NAMESPACES;
      using namespace DUNE::Piccolo;

      struct Arguments
      {
        uint16_t port; // Server port
        uint8_t max_clients;  // Maximum number of clients.
        bool gimbal_direct; // Route directly to gimbal.
      };

      static const double c_connection_timeout = 30;

      struct Task: public DUNE::Tasks::Task
      {
        // Task arguments.
        Arguments m_args;

        // Server socket related.
        TCPSocket* m_sock;
        IOMultiplexing m_iom;
        uint8_t m_buf[2048];

        // Client data.
        struct Client
        {
          TCPSocket* socket; // Socket handle.
          Address address; // Client address.
          uint16_t port; // Client port.
          StreamPacket pkt; // Packet buffer.
          double last; // Time of data last received.
        };

        typedef std::list<Client> ClientList;

        ClientList m_clients;

        // Messages.
        IMC::PiccoloPacket m_pkt;

        Task(const std::string& name, Tasks::Context& ctx):
          Tasks::Task(name, ctx),
          m_sock(0)
        {
          param("Port", m_args.port)
          .defaultValue("3001")
          .description("Gateway server port");

          param("Maximum Clients", m_args.max_clients)
          .minimumValue("1")
          .defaultValue("5")
          .description("Maximum number of client connections");

          param("Route Directly To Gimbal", m_args.gimbal_direct)
          .defaultValue("false")
          .description("Route gimbal stream packets directly to TASE driver");

          std::string s = String::str(DTR("OK (%d clients)"), m_clients.size());
          setEntityState(IMC::EntityState::ESTA_NORMAL, s);
        }

#if BROKEN
          bind<Task, IMC::PiccoloPacket>(*this, c_q_gateway);
#endif
        }

        ~Task(void)
        {
          onResourceRelease();
        }

        void
        onResourceRelease(void)
        {
          for (ClientList::iterator itr = m_clients.begin(); itr != m_clients.end(); ++itr)
          {
            delete itr->socket;
          }

          m_clients.clear();

          if (m_sock)
          {
            m_sock->delFromPoll(m_iom);
            delete m_sock;
            m_sock = 0;
          }
        }

        void
        onUpdateParameters(void)
        { }

        void
        onResourceAcquisition(void)
        {
          m_sock = new TCPSocket;
          m_sock->bind(m_args.port);
          m_sock->listen(5);
          m_sock->addToPoll(m_iom);

          inf(DTR("created server socket on port %u"), m_args.port);
        }

        void
        consume(const IMC::PiccoloPacket* pkt)
        {
          if (!m_clients.size())
            return;

          const StreamPacket* spkt = streamPkt(pkt);

          ClientList::iterator itr = m_clients.begin();

          while (itr != m_clients.end())
          {
            try
            {
              itr->socket->write((char*)spkt, size(spkt));

              report("OUT", *itr, spkt);
              ++itr;
            }
            catch (std::runtime_error& e)
            {
              inf(DTR("error sending message - %s:%u - %s"),
                  itr->address.c_str(), itr->port, e.what());
              itr = closeConnection(itr);
            }
          }
          if (m_clients.size() == 0)
            deactivate();
        }

        void
        onMain(void)
        {
          while (!stopping())
          {
            consumeMessages();

            // Poll for connections and client data
            if (!m_iom.poll(0.005))
              continue;

            // Check for new clients.
            if (m_sock->wasTriggered(m_iom))
              acceptNewClient();

            // Check for client data
            handleClientData();
          }
        }

        void
        acceptNewClient(void)
        {
          Client c;
          c.socket = 0;
          try
          {
            c.socket = m_sock->accept(&c.address, &c.port);

            if (m_clients.size() >= m_args.max_clients)
            {
              err(DTR("maximum number of clients is %u, connection refused"),
                  m_args.max_clients);
              delete c.socket;
              return;
            }

            c.socket->addToPoll(m_iom);
            c.last = Clock::get();
            memset(&c.pkt, 0, sizeof(c.pkt));
            m_clients.push_back(c);

            inf(DTR("connected - %s:%u - clients now: %lu"),
                c.address.c_str(), c.port, (unsigned long)m_clients.size());

            if (m_clients.size() == 1)
              activate();
          }
          catch (std::runtime_error& e)
          {
            if (c.socket)
              delete c.socket;
            err(DTR("error accepting new client connection: %s"), e.what());
          }
        }

        ClientList::iterator
        closeConnection(ClientList::iterator itr)
        {
          itr->socket->delFromPoll(m_iom);
          delete itr->socket;
          return m_clients.erase(itr);
        }

        void
        handleClientData(void)
        {
          double now = Clock::get();

          ClientList::iterator itr = m_clients.begin();

          while (itr != m_clients.end())
          {
            if (!itr->socket->wasTriggered(m_iom))
            {
              if (now - itr->last >= c_connection_timeout)
              {
                err(DTR("data receive timeout - closing connection - %s:%u"),
                    itr->address.c_str(), itr->port);
                itr = closeConnection(itr);
              }
              else
              {
                ++itr;
              }
              continue;
            }

            int n;
            try
            {
              n = itr->socket->read((char*)m_buf, sizeof(m_buf));
            }
            catch (std::runtime_error& e)
            {
              err(DTR("receive error - %s:%u - %s"),
                  itr->address.c_str(), itr->port, e.what());
              n = 0;
            }

            if (n <= 0)
            {
              inf(DTR("disconnected - %s:%u - clients now: %lu"),
                  itr->address.c_str(), itr->port,
                  (unsigned long)(m_clients.size() - 1));

              itr = closeConnection(itr);
              continue;
            }

            itr->last = now;

            for (int j = 0; j < n; ++j)
            {
              if (LookForStreamPacketInByte(&itr->pkt, m_buf[j]) == 0)
              {
                report("IN", *itr, &itr->pkt);

                copy(&(itr->pkt), &m_pkt);
                m_pkt.id = c_q_gateway;

                if (itr->pkt.Stream == GIMBAL_STREAM && m_args.gimbal_direct)
                  sendPacket(c_q_gimbal_processor);
                else
                  sendPacket();
              }
            }
            ++itr;
          }

          if (m_clients.size() == 0)
            deactivate();
        }

        void
        report(const char* desc, Client& c, const StreamPacket* pkt)
        {
          trace("%s: %s:%u stream: %s size: %u", desc, c.address.c_str(),
                c.port, stream(pkt), size(pkt));
        }

        void
        activate(void)
        {
          inf(DTR("gateway is active"));
          m_pkt.payload.clear();
          m_pkt.id = c_q_gateway_active;
          sendPacket();
        }

        void
        deactivate(void)
        {
          inf(DTR("gateway is idle"));
          m_pkt.payload.clear();
          m_pkt.id = c_q_gateway_idle;
          sendPacket();
        }

        void
        sendPacket(int qualification = c_q_connection)
        {
          m_pkt.setTimeStamp();
#if BROKEN
          bus().dispatch(&m_pkt, this, qualification);
#endif
        }
      };
    }
  }
}

DUNE_TASK
