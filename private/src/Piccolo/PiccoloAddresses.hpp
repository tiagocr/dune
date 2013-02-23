//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************

#ifndef PICCOLO_ADDRESSES_HPP_INCLUDED_
#define PICCOLO_ADDRESSES_HPP_INCLUDED_

// ISO C++ 98 headers
#include <map>

// DUNE headers.
#include <DUNE/Tasks/Context.hpp>
#include <DUNE/DUNE.hpp>


namespace Piccolo
{
  class PiccoloAddresses
  {
  public:
    PiccoloAddresses(DUNE::Tasks::Context& ctx);

    ~PiccoloAddresses(void);

    uint16_t
    toIMCAddress(uint16_t piccolo_addr) const;

    uint16_t
    toPiccoloAddress(uint16_t imc_address) const;

    uint16_t
    self(void) const;

    static const uint16_t c_invalid = 0xFFFF;
  private:
    typedef std::map<uint16_t, uint16_t> AddrMap;
    AddrMap m_imc2pa, m_pa2imc;
    uint16_t m_self;

    uint16_t lookup(const AddrMap&, uint16_t) const;

  };
}
#endif
