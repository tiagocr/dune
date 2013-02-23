//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************
// $Id:: Task.cpp 12695 2013-01-23 22:54:41Z rasm                         $:*
//***************************************************************************

// ISO C++ 98 headers.
#include <iomanip>
#include <iostream>
#include <map>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Transports
{
  namespace Piccolo
  {
    namespace Link
    {
      using DUNE_NAMESPACES;
      using namespace DUNE::Piccolo;

      struct Arguments
      {
        std::string conn_type;
        std::string uart_path;
        uint16_t uart_baud;
        Address tcp_server;
        uint16_t tcp_port;
        bool payload_stream;
        std::vector<std::string> transports;
        std::vector<std::string> rlim;
      };

      static const double c_keepalive_period = 5;

      struct Task: public DUNE::Tasks::Task
      {
        // Arguments.
        Arguments m_args;

        // Piccolo addresses.
        Addresses m_addrs;

        // State variables grouped in single structure
        struct
        {
          double keepalive_time; // Time of next keep-alive packet.
          bool gateway_active : 1;  // Gateway is active.
          bool gimbal_processor_active : 1; // Gateway is active.
        } m_sta;

        // Autopilot communications handle and data.
        Connection* m_conn;
        //! Piccolo packet message.
        IMC::PiccoloPacket m_pkt;

        // Payload stream related.
        struct PSHandler
        {
          IMC::Parser parser;
          ByteBuffer buf;
          RateLimiters rl;
        } m_pstream;

        Task(const std::string& name, Tasks::Context& ctx):
          DUNE::Tasks::Task(name, ctx),
          m_addrs(ctx),
          m_conn(0)
        {
          param("Connection Type", m_args.conn_type)
          .description("Type of connection to Piccolo ('TCP' or 'Serial')");

          param("Serial Port - Path", m_args.uart_path)
          .defaultValue("")
          .description("Serial port path for serial port connections");

          param("Serial Port - Baud Rate", m_args.uart_baud)
          .defaultValue("57600")
          .description("Serial port baud rate for serial port connections");

          param("TCP Server - Host", m_args.tcp_server)
          .defaultValue("127.0.0.1")
          .description("Server address for TCP connections");

          param("TCP Server - Port", m_args.tcp_port)
          .defaultValue("2001")
          .description("Server address for TCP connections");

          param("IMC Over Payload Stream", m_args.payload_stream)
          .description("Enable IMC over payload stream")
          .defaultValue("false");

          param("Transports", m_args.transports)
          .description("IMC messages to transport")
          .defaultValue("");

          param("Rate Limiters", m_args.rlim)
          .description("Rate limiters for IMC messages")
          .defaultValue("");

#if BROKEN
          bind<Task, IMC::PiccoloPacket>(*this, c_q_connection);
#endif
        }

        ~Task(void)
        {
          onResourceRelease();
        }

        void
        onUpdateParameters(void)
        {
          memset(&m_sta, 0, sizeof(m_sta));

          if (m_args.payload_stream)
          {
            m_pstream.parser.reset();
            m_pstream.rl.setup(m_args.rlim);
            bind<Task>(*this, m_args.transports);
          }
        }

        bool
        targetPiccoloAddress(const IMC::Message* m, uint16_t& piccolo_addr)
        {
          uint16_t imc_addr = m->getDestination();

          if (imc_addr == IMC::AddressResolver::invalid())
            piccolo_addr = m_addrs.self();
          else
            piccolo_addr = m_addrs.toPiccoloAddress(imc_addr);

          if (piccolo_addr == m_addrs.c_invalid)
          {
            err(DTR("cannot identify Piccolo address for sending '%s' message with destination '%s'"),
                m->getName(), resolveSystemId(imc_addr));

            return false;
          }
          return true;
        }

        void
        consume(const IMC::Message* msg)
        {
          if (m_pstream.rl.filter(msg))
            return;

          uint16_t piccolo_addr;

          if (!targetPiccoloAddress(msg, piccolo_addr))
            return;

          trace("IMC OUT | %s", msg->getName());

          unsigned int n = msg->getSerializationSize();
          m_pstream.buf.grow(n);

          uint8_t* p = m_pstream.buf.getBuffer();
          msg->serialize(p, n);

          m_conn->sendStreamData(piccolo_addr, PAYLOAD_STREAM, p, n);
        }

        void
        onResourceAcquisition(void)
        {
          if (m_args.conn_type == "Serial")
          {
            inf(DTR("creating a serial connection | %s %u"), m_args.uart_path.c_str(), m_args.uart_baud);
            m_conn = new SerialPortConnection(m_args.uart_path, m_args.uart_baud);
          }
          else
          {
            inf(DTR("creating a TCP connection | %s %u"), m_args.tcp_server.c_str(), m_args.tcp_port);
            m_conn = new TCPConnection(m_args.tcp_server, m_args.tcp_port);
          }

          inf(DTR("Piccolo interface initialized"));
        }

        void
        onResourceRelease(void)
        {
          if (m_conn)
          {
            delete m_conn;
            m_conn = 0;
          }
        }

        void
        onMain(void)
        {
          StreamPacket stream_pkt;
          StreamPacket keepalive_pkt;
          typedef std::map<uint16_t, APPacket*> PktMap;
          PktMap pktmap;

          makeStreamPacket(0, 0, BROADCAST_ADDRESS, ENUMERATION_STREAM, &keepalive_pkt);

          memset(&stream_pkt, 0, sizeof(stream_pkt));

          double last_packet_time = 0;
          const double c_data_timeout = 5.0;

          while (!stopping())
          {
            double now = Clock::get();
            consumeMessages();

            if (now >= m_sta.keepalive_time)
            {
              m_conn->sendPacket(&keepalive_pkt);
              m_sta.keepalive_time = now + c_keepalive_period;

              trace("OUT | keep alive packet");;
            }

            if (!m_conn->checkForPacket(&stream_pkt, 0.005))
            {
              if (now - last_packet_time > c_data_timeout && getEntityState() != IMC::EntityState::ESTA_ERROR)
              {
                setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_COM_ERROR);
                err("%s", DTR(Status::getString(Status::CODE_COM_ERROR)));
              }
              continue;
            }

            if (getEntityState() != IMC::EntityState::ESTA_NORMAL)
            {
              setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
              war("%s", DTR(Status::getString(Status::CODE_ACTIVE)));
            }

            last_packet_time = now;

            trace("IN | %s %u | %s %u | %s | %u | %u",
                  srctype(&stream_pkt), src(&stream_pkt),
                  dsttype(&stream_pkt), dst(&stream_pkt),
                  stream(&stream_pkt), stream_pkt.Size,
                  size(&stream_pkt));

            if (m_args.payload_stream && stream_pkt.Stream == PAYLOAD_STREAM)
            {
              uint8_t* p = stream_pkt.Data;
              uint8_t* e = p + stream_pkt.Size;

              while (p != e)
              {
                IMC::Message* m = m_pstream.parser.parse(*p);
                ++p;

                if (m)
                {
                  dispatch(m, DF_KEEP_TIME);

                  trace("IMC IN | %s", m->getName());

                  delete m;
                }
              }
            }

            if (stream_pkt.Stream == GIMBAL_STREAM && m_sta.gimbal_processor_active)
              pktToBus(&stream_pkt, c_q_gimbal_processor);

            if (m_sta.gateway_active)
              pktToBus(&stream_pkt, c_q_gateway);

            if (stream_pkt.Stream != AUTOPILOT_STREAM || src(&stream_pkt) != m_addrs.self())
              continue;

            uint8_t* data = stream_pkt.Data;
            UInt32 len = stream_pkt.Size;
            UInt32 pos = 0;

            uint16_t from = src(&stream_pkt);

            PktMap::iterator it = pktmap.find(from);
            APPacket* pkt = NULL;
            if (it == pktmap.end())
            {
              pkt = new APPacket;
              memset(pkt, 0, sizeof(APPacket));
              pktmap.insert(std::pair<uint16_t, APPacket*>(from, pkt));
            }
            else
            {
              pkt = it->second;
            }

            while (pos < len)
            {
              UInt32 used;
              if (LookForSimplePacketInBuf(data + pos, pkt, len - pos, &used))
              {
                if(!from)
                {
                  pktToBus(pkt,qGS(pkt->PktType));
                }
                else
                {
                  pktToBus(pkt,qAP(pkt->PktType));
                }

                trace("IN | %s | %d", name(pkt, !from), size(pkt));
                memset(pkt, 0, sizeof(APPacket));
              }
              pos += used;
            }
          }

          for (PktMap::iterator itr = pktmap.begin(); itr != pktmap.end(); ++itr)
            delete itr->second;
        }

        void
        pktToBus(const StreamPacket* sdk_stream_pkt, int qualifier)
        {
          m_pkt.id = qualifier;
          m_pkt.setTimeStamp();
          m_pkt.payload.clear();

          copy(sdk_stream_pkt, &m_pkt);
#if BROKEN
          bus().dispatch(&m_pkt, this, qualifier);
#endif
        }

        void
        pktToBus(uint8_t* data, int len, int qualifier)
        {
          m_pkt.id = qualifier;
          m_pkt.setTimeStamp();
          m_pkt.payload.assign((const char*)data, (const char*)data + len);
#if BROKEN
          bus().dispatch(&m_pkt, this, qualifier);
#endif
        }

        void
        pktToBus(const APPacket* sdk_pkt, int qualifier)
        {
          m_pkt.id = qualifier;
          m_pkt.payload.clear();

          copy(sdk_pkt, &m_pkt);
          m_pkt.setTimeStamp();
#if BROKEN
          bus().dispatch(&m_pkt, this, qualifier);
#endif
        }

        void
        consume(const IMC::PiccoloPacket* msg)
        {
          if (!m_conn)
            return;

          uint16_t piccolo_addr;
          const StreamPacket* pkt;

          // Handle gateway or gimbal processor cases
          switch (msg->id)
          {
            case c_q_gateway:
            case c_q_gimbal_processor:
              // Already in stream packet form
              pkt = streamPkt(msg);
              trace("OUT - Stream %s | %d", stream(pkt), size(pkt));

              m_conn->sendPacket(pkt);
              return;
            case c_q_gateway_active:
              inf(DTR("enabling routing of packets to gateway"));
              m_sta.gateway_active = true;
              return;
            case c_q_gateway_idle:
              inf(DTR("disabling routing of packets to gateway"));
              m_sta.gateway_active = false;
              return;
            case c_q_gimbal_processor_active:
              inf(DTR("enabling routing of packets to gimbal processor"));
              m_sta.gimbal_processor_active = true;
              return;
            case c_q_gimbal_processor_idle:
              inf(DTR("disabling routing of packets to gimbal processor"));
              m_sta.gimbal_processor_active = false;
              return;
          }

          uint8_t stream;

          if (isAPq(msg->id))
          {
            if (!targetPiccoloAddress(msg, piccolo_addr))
              return;

            stream = AUTOPILOT_STREAM;

            trace("OUT - AP - '%s'", name(apPkt(msg), false));
          }
          else
          {
            piccolo_addr = GS_ADDRESS;
            stream = GS_STREAM;

            trace("OUT - GS - '%s'", name(apPkt(msg), true));
          }

          m_conn->sendStreamData(piccolo_addr, stream, msg);
        }
      };
    }
  }
}

DUNE_TASK
