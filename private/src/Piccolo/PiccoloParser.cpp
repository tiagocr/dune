//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
// Author: Joao Fortuna                                                     *
//***************************************************************************

// Piccolo headers.
#include "PiccoloParser.hpp"
#include "PiccoloExceptions.hpp"
#include "PiccoloPacket.hpp"

#include <stdio.h>

// DUNE headers.
#include <DUNE/Algorithms/CRC16.hpp>
#include <DUNE/Streams/Terminal.hpp>

namespace Piccolo
{
  PiccoloParser::PiccoloParser(void)
  {
    reset();
  }

  PiccoloParser::~PiccoloParser(void)
  { }

  void
  PiccoloParser::reset(void)
  {
    m_data_index = 0;
    m_header_check = 0;
    m_crc = 0;
    m_tmp8 = 0;
    m_state = STATE_SYNC;
  }

  bool
  PiccoloParser::parse(uint8_t byte)
  {
    uint8_t current_byte = byte;

    switch (m_state)
    {
      case STATE_SYNC:
        if (current_byte == 0x5A)
        {
          m_header_check = current_byte;
          m_data_index = 0;
          m_crc = DUNE::Algorithms::CRC16::compute(current_byte);
          m_state = STATE_SYNC1;
        }
        break;

      case STATE_SYNC1:
        if (current_byte != 0xA5)
        {
          m_state = STATE_SYNC;
          break;
        }
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_DEST_HI;
        break;

      case STATE_DEST_HI:
        m_tmp8 = current_byte;
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_DEST_LO;
        break;

      case STATE_DEST_LO:
        m_packet.setDestination((m_tmp8 << 8) | current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_SOURCE_HI;
        break;

      case STATE_SOURCE_HI:
        m_tmp8 = current_byte;
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_SOURCE_LO;
        break;

      case STATE_SOURCE_LO:
        m_packet.setSource((m_tmp8 << 8) | current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_SEQUENCE_HI;
        break;

      case STATE_SEQUENCE_HI:
        m_tmp8 = current_byte;
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_SEQUENCE_LO;
        break;

      case STATE_SEQUENCE_LO:
        m_packet.setSequenceNumber((m_tmp8 << 8) | current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_ACK_HI;
        break;

      case STATE_ACK_HI:
        m_tmp8 = current_byte;
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_ACK_LO;
        break;

      case STATE_ACK_LO:
        m_packet.setAcknowledgeNumber((m_tmp8 << 8) | current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_STREAM;
        break;

      case STATE_STREAM:
        m_packet.setStream(current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_FLAGS;
        break;

      case STATE_FLAGS:
        m_packet.setFlags(current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_SIZE;
        break;

      case STATE_SIZE:
        m_packet.setSize(current_byte);
        m_header_check ^= current_byte;
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_HEADER_CHECK;
        break;

      case STATE_HEADER_CHECK:
        if (m_header_check != current_byte)
        {
          m_state = STATE_SYNC;
          throw InvalidChecksum();
        }
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        m_state = STATE_DATA;
        break;

      case STATE_DATA:
        m_packet.setData(current_byte, m_data_index);
        if (++m_data_index == m_packet.getSize())
        {
          m_data_index = 0;
          m_state = STATE_CRC_HI;
        }
        m_crc = DUNE::Algorithms::CRC16::compute(current_byte, m_crc);
        break;

      case STATE_CRC_HI:
        if (((m_crc >> 8) & 0xff) != current_byte)
        {
          reset();
          throw InvalidChecksum();
        }
        m_state = STATE_CRC_LO;
        break;

      case STATE_CRC_LO:
        m_state = STATE_SYNC;
        if ((m_crc & 0xff) != current_byte)
          throw InvalidChecksum();
        reset();
        return true;
    }

    return false;
  }
}
