//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************

// DUNE headers.
#include <DUNE/IMC/AddressResolver.hpp>
#include <DUNE/IMC/Bus.hpp>

#include "PiccoloAddresses.hpp"

namespace Piccolo
{
  using DUNE_NAMESPACES;

  PiccoloAddresses::PiccoloAddresses(DUNE::Tasks::Context& ctx)
  {
    std::vector<std::string> vehicles = ctx.config.options("Piccolo Addresses");

    IMC::AddressResolver& imcr = ctx.resolver;
    std::string nname = imcr.name();

    for (unsigned i = 0; i < vehicles.size(); ++i)
    {
      uint16_t addr = c_invalid;

      ctx.config.get("Piccolo Addresses", vehicles[i], "", addr);

      if (addr == c_invalid)
        throw std::runtime_error("invalid Piccolo address for "+vehicles[i]);

      uint16_t imc_addr = imcr.resolve(vehicles[i]);

      if (imc_addr == IMC::AddressResolver::invalid())
        throw std::runtime_error("no IMC address for " + vehicles[i]);

      m_imc2pa[imc_addr] = addr;
      m_pa2imc[addr] = imc_addr;
    }

    if (ctx.profiles.isSelected("Simulation"))
      m_self = 1;
    else
      m_self = toPiccoloAddress(imcr.id());


    if (m_self == c_invalid)
      throw std::runtime_error("no Piccolo address for " + nname);
  }

  PiccoloAddresses::~PiccoloAddresses(void)
  {

  }

  uint16_t
  PiccoloAddresses::lookup(const AddrMap& map, uint16_t v) const
  {
    AddrMap::const_iterator itr = map.find(v);

    if (itr == map.end())
      return c_invalid;

    return itr->second;
  }

  uint16_t
  PiccoloAddresses::toIMCAddress(uint16_t piccolo_addr) const
  {
    return lookup(m_pa2imc, piccolo_addr);
  }

  uint16_t
  PiccoloAddresses::toPiccoloAddress(uint16_t imc_addr) const
  {
    return lookup(m_imc2pa, imc_addr);
  }

  uint16_t
  PiccoloAddresses::self(void) const
  {
    return m_self;
  }
}
