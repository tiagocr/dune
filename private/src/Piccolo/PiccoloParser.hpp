//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
// Author: Joao Fortuna                                                     *
//***************************************************************************

#ifndef PICCOLO_PACKET_PARSER_HPP_INCLUDED_
#define PICCOLO_PACKET_PARSER_HPP_INCLUDED_

// Piccolo headers.
#include "PiccoloMessage.hpp"
#include "PiccoloPacket.hpp"

namespace Piccolo
{
  // Export DLL Symbol.
  class DUNE_DLL_SYM PiccoloParser;

  class PiccoloParser
  {
  public:
    PiccoloParser(void);

    ~PiccoloParser(void);

    void
    reset(void);

    bool
    parse(uint8_t byte);

    PiccoloPacket
    getPacket(void)
    {
      return m_packet;
    }

  private:
    enum ParseState
    {
      STATE_SYNC,
      STATE_SYNC1,
      STATE_DEST_HI,
      STATE_DEST_LO,
      STATE_SOURCE_HI,
      STATE_SOURCE_LO,
      STATE_SEQUENCE_HI,
      STATE_SEQUENCE_LO,
      STATE_ACK_HI,
      STATE_ACK_LO,
      STATE_STREAM,
      STATE_FLAGS,
      STATE_SIZE,
      STATE_HEADER_CHECK,
      STATE_DATA,
      STATE_CRC_HI,
      STATE_CRC_LO
    };

    //! Current parser state.
    ParseState m_state;
    //! Packet buffer.
    PiccoloPacket m_packet;
    //! Packet data index.
    uint8_t m_data_index;
    //! Header checksum.
    uint8_t m_header_check;
    //! Current CRC value.
    uint16_t m_crc;
    //! Temporary variable for 16 bit fields.
    uint8_t m_tmp8;
  };
}

#endif
