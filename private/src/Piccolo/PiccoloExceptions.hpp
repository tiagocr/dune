//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// $Id:: PiccoloExceptions.hpp 12647 2013-01-21 03:03:19Z robot           $:*
//***************************************************************************

#ifndef PICCOLO_EXCEPTIONS_HPP_INCLUDED_
#define PICCOLO_EXCEPTIONS_HPP_INCLUDED_

// ISO C++ headers.
#include <stdexcept>

namespace Piccolo
{
  class InvalidChecksum: public std::exception
  {
  };

  class InvalidPacket: public std::exception
  {
  };
}

#endif
