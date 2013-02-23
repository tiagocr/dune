//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************

#ifndef PICCOLO_LINK_HPP_INCLUDED_
#define PICCOLO_LINK_HPP_INCLUDED_

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Network/TCPSocket.hpp>
#include <DUNE/System/IOMultiplexing.hpp>
#include <DUNE/Hardware/SerialPort.hpp>

namespace Piccolo
{
  using DUNE_NAMESPACES;

  class PiccoloLink
  {
  public:
    PiccoloLink():
      m_uart(0),
      m_sock(0)
    { };

    ~PiccoloLink()
    {
      if (m_sock)
        delete m_sock;
      if(m_uart)
        delete m_uart;
    }

    PiccoloLink(Address addr, int16_t port):
      m_uart(0),
      m_sock(0)
    {
      m_addr = addr;
      m_port = port;

      m_sock = new Network::TCPSocket;

      try
      {
        m_sock->connect(addr, port);
        m_sock->addToPoll(m_iom);
      }
      catch(std::exception& e)
      {
        delete m_sock;
        m_sock = 0;
        throw;
      }
    }

    PiccoloLink(const std::string& uart_name, uint16_t baud):
      m_uart(0),
      m_sock(0),
      m_addr(),
      m_port(0)
    {
      m_uart = new SerialPort(uart_name, baud);
    }

    int
    receive(uint8_t* m_buf)
    {
      if(m_uart)
      {
        return m_uart->read(m_buf, sizeof(m_buf));
      }
      if(m_sock)
      {
        try
        {
          return m_sock->read((char*) m_buf, sizeof(m_buf));
        }
        catch (std::exception& e) {
          DUNE_DBG("Piccolo Link", "connection lost, retrying");
          m_sock->delFromPoll(m_iom);
          delete m_sock;

          m_sock = new Network::TCPSocket;
          m_sock->connect(m_addr, m_port);
          m_sock->addToPoll(m_iom);
          return 0;
        }
      }
      return 0;
    }

    bool
    poll(double timeout)
    {
      if(m_uart)
      {
        return m_uart->hasNewData(timeout) == System::IOMultiplexing::PRES_OK;
      }
      if(m_sock)
      {
        if (m_iom.poll(timeout))
          return m_sock->wasTriggered(m_iom);
        else
          return false;
      }
      return false;
    }

    template <class PM>
    int
    send(PM* m)
    {
      Piccolo::PiccoloPacket pkt;
      uint8_t* bfr = new uint8_t[255];
      int size;

      size = pkt.serialize(m, bfr);

      if(m_uart)
      {
        return m_uart->write((char*)bfr);
      }
      if(m_sock)
      {
        return m_sock->write((char*)bfr, size);
      }
      return 0;
    }

  private:
    SerialPort* m_uart;
    TCPSocket* m_sock;
    System::IOMultiplexing m_iom;
    Address m_addr;
    int16_t m_port;
  };
}


#endif
