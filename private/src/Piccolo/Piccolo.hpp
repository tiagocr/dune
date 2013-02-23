//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************
// $Id:: Piccolo.hpp 12919 2013-02-14 17:12:13Z jfortuna                  $:*
//***************************************************************************

#ifndef PICCOLO_HPP_INCLUDED_
#define PICCOLO_HPP_INCLUDED_

namespace Piccolo
{
  static const fp64_t deg2rad = (DUNE::Math::c_pi / 180);
  static const fp64_t marcs2rad = (deg2rad / 3600000);
}

#include "PiccoloDefinitions.hpp"
#include "PiccoloExceptions.hpp"
#include "PiccoloFactory.hpp"
#include "PiccoloMessage.hpp"
#include "PiccoloPacket.hpp"
#include "PiccoloParser.hpp"
#include "PiccoloConverters.hpp"
#include "PiccoloLink.hpp"
#include "PiccoloAddresses.hpp"

#endif
