//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// $Id:: ESCCBoard.hpp 12303 2013-01-01 02:14:25Z jbraga                  $:*
//***************************************************************************

#ifndef SENSORS_HG1700_ESCC_BOARD_HPP_INCLUDED_
#define SENSORS_HG1700_ESCC_BOARD_HPP_INCLUDED_

namespace Sensors
{
  namespace HG1700
  {
    struct ESCCBoard
    {
      unsigned base;
      unsigned irq;
      unsigned channel;
      unsigned dmar;
      unsigned dmat;
    };
  }
}

#endif
