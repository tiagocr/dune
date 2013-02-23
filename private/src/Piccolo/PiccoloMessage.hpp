//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************
// $Id:: PiccoloMessage.hpp 12667 2013-01-22 02:44:42Z rasm               $:*
//***************************************************************************

#ifndef PICCOLO_MESSAGE_HPP_INCLUDED_
#define PICCOLO_MESSAGE_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

#include <DUNE/DUNE.hpp>

typedef uint32_t uint24_t;
typedef fp32_t fp16_t;

namespace Piccolo
{
  // Export symbol.
  class DUNE_DLL_SYM PiccoloMessage;

  class PiccoloMessage
  {
  public:
    //! Default Constructor
    PiccoloMessage(void)
    {
      m_src = 0;
      m_dst = 0;
      m_id = 0;
    };

    //! Default destructor.
    virtual
    ~PiccoloMessage(void)
    { }

    //! Reset message's fields.
    virtual void
    clear(void) = 0;

    //! Retrieve message's name.
    //! @return message's name.
    virtual const char*
    getName(void) const = 0;

    //! Retrieve message's identification number.
    //! @return message's identification number.
    virtual uint16_t
    getId(void) const = 0;

    //! Get message's source.
    //! @return message's source.
    uint16_t
    getSource(void) const
    {
      return m_src;
    }

    //! Set message's source.
    //! @param src message's source.
    void
    setSource(uint16_t src)
    {
      m_src = src;
    }

    //! Retrieve message's destination.
    //! @return message's destination.
    uint16_t
    getDestination(void) const
    {
      return m_dst;
    }

    //! Set message's destination.
    //! @param dst message's destination.
    void
    setDestination(uint16_t dst)
    {
      m_dst = dst;
    }

    virtual uint8_t*
    serializeFields(uint8_t* bfr) const = 0;

    //! Deserialize message fields from a packet.
    //! @param bfr stream of bytes (packet)
    //! @param len length of the byte stream.
    //! @return number of bytes processed.
    virtual void
    deserializeFields(const uint8_t* bfr) = 0;

  protected:
    uint16_t m_src;
    uint16_t m_dst;
    uint16_t m_id;
  };
}

#endif
