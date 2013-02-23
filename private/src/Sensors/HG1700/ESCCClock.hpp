//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************

#ifndef SENSORS_HG1700_ESCC_CLOCK_HPP_INCLUDED_
#define SENSORS_HG1700_ESCC_CLOCK_HPP_INCLUDED_

namespace Sensors
{
  namespace HG1700
  {
    struct ESCCClock
    {
      unsigned long clockbits;
      unsigned numbits;
    };
  }
}

#endif
