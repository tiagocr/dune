//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
// Author: Joao Fortuna                                                     *
//***************************************************************************
// $Id:: PiccoloPacket.hpp 12875 2013-02-06 11:24:38Z jfortuna            $:*
//***************************************************************************

#ifndef PICCOLO_PACKET_HPP_INCLUDED_
#define PICCOLO_PACKET_HPP_INCLUDED_

#include "PiccoloMessage.hpp"
#include "PiccoloFactory.hpp"

// DUNE headers.
#include <DUNE/Streams/Terminal.hpp>

namespace Piccolo
{
  // Export DLL Symbol.
  class DUNE_DLL_SYM PiccoloPacket;

  class PiccoloPacket
  {
  public:
    PiccoloPacket(void):
      m_dest(0),
      m_source(0),
      m_sequence(0),
      m_ack(0),
      m_stream(0),
      m_flags(0),
      m_size(0)
  { }

    void
    setDestination(uint16_t dest)
    {
      m_dest = dest;
    }

    uint16_t
    getDestination(void) const
    {
      return m_dest;
    }

    void
    setSource(uint16_t source)
    {
      m_source = source;
    }

    uint16_t
    getSource(void) const
    {
      return m_source;
    }

    void
    setSequenceNumber(uint16_t sequence)
    {
      m_sequence = sequence;
    }

    uint16_t
    getSequenceNumber(void) const
    {
      return m_sequence;
    }

    void
    setAcknowledgeNumber(uint16_t ack)
    {
      m_ack = ack;
    }

    uint16_t
    getAcknowledgeNumber(void) const
    {
      return m_ack;
    }

    void
    setStream(uint8_t stream)
    {
      m_stream = stream;
    }

    uint8_t
    getStream(void) const
    {
      return m_stream;
    }

    void
    setFlags(uint8_t flags)
    {
      m_flags = flags;
    }

    uint8_t
    getFlags(void) const
    {
      return m_flags;
    }

    void
    setSize(uint8_t size)
    {
      m_size = size;
    }

    uint16_t
    getSize(void) const
    {
      return m_size;
    }

    void
    setData(uint8_t byte, uint8_t index)
    {
      m_data[index] = byte;
    }

    PiccoloMessage*
    deserializeData(void)
    {
//      DUNE_DBG("Piccolo Packet", "stream: " << (int) m_stream << ", packet: " << (int) m_data[2]);
      PiccoloMessage* m = 0;

      if(m_stream == 4) // CAN packet
        return m;
      if(m_stream == 5) // Gimbal packet
        return m;
      if(m_stream == 6) // Payload packet
        return m;
      if(m_stream == 7) // Payload packet
        return m;
      if(m_stream == 8) // DBG packet
        return m;

      if(m_source == 0) // GS packet
        m_stream = 4;

      int id = (int)m_data[2] + 256 * (int)m_stream;

      m = PiccoloFactory::produce(id);

      if(!m)
        return m;

      m->setSource(m_source);
      m->setDestination(m_dest);
      m->deserializeFields(m_data+4); // First bytes contain useless header

      return m;
    }

    template <class PM>
    int
    serialize(PM* msg, uint8_t* bfr)
    {
      uint8_t* data = new uint8_t[255];
      uint8_t* eob;
      int step = 0;
      uint8_t header_chks = 0;
      uint16_t crc16 = 0;

      m_dest = msg->getDestination();
      m_source = msg->getSource();

      m_stream = (int) msg->getId() / 256;

      if(m_stream == 4)
        m_stream = 0;

      eob = msg->serializeFields(data);
      m_size = eob - data;

      while(true)
      {
        switch (step)
        {
          case 0:
          {
            *(bfr + step) = 0x5A;
            header_chks = *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step));
            step++;
            break;
          }
          case 1:
          {
            *(bfr + step) = 0xA5;
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 2:
          {
            *(bfr + step) = (uint8_t) ((m_dest >> 8) & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 3:
          {
            *(bfr + step) = (uint8_t) (m_dest & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 4:
          {
            *(bfr + step) = (uint8_t) ((m_source >> 8) & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 5:
          {
            *(bfr + step) = (uint8_t) (m_source & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 6:
          {
            *(bfr + step) = (uint8_t) ((m_sequence >> 8) & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 7:
          {
            *(bfr + step) = (uint8_t) (m_sequence & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 8:
          {
            *(bfr + step) = (uint8_t) ((m_ack >> 8) & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 9:
          {
            *(bfr + step) = (uint8_t) (m_ack & 0x00FF);
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 10:
          {
            *(bfr + step) = m_stream;
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 11:
          {
            *(bfr + step) = m_flags;
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 12:
          {
            *(bfr + step) = m_size;
            header_chks ^= *(bfr + step);
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 13:
          {
            *(bfr + step) = header_chks;
            crc16 = DUNE::Algorithms::CRC16::compute(*(bfr + step), crc16);
            step++;
            break;
          }
          case 14:
          {
            std::memcpy((bfr+step), data, m_size);
            crc16 = DUNE::Algorithms::CRC16::compute(data, m_size, crc16);
            step++;
            break;
          }
          case 15:
          {
            *(bfr + m_size + step -1) = (uint8_t) ((crc16 >> 8) & 0x00FF);
            step++;
            break;
          }
          case 16:
          {
            *(bfr + m_size + step -1) = (uint8_t) (crc16 & 0x00FF);
            return (int) (16 + m_size);
          }
        }
      }
    }

  private:
    //! Destination address.
    uint16_t m_dest;
    //! Source address.
    uint16_t m_source;
    //! Sequence number.
    uint16_t m_sequence;
    //! Acknowledge number.
    uint16_t m_ack;
    //! Stream/endpoint identifier.
    uint8_t m_stream;
    //! Flags.
    uint8_t m_flags;
    //! Data size.
    uint8_t m_size;
    //! Data.
    uint8_t m_data[255];
  };
}

#endif
