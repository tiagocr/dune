//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// $Id:: ESCCSetup.hpp 12303 2013-01-01 02:14:25Z jbraga                  $:*
//***************************************************************************

#ifndef SENSORS_HG1700_ESCC_SETUP_HPP_INCLUDED_
#define SENSORS_HG1700_ESCC_SETUP_HPP_INCLUDED_

namespace Sensors
{
  namespace HG1700
  {
    struct ESCCSetup
    {
      unsigned cmdr;
      unsigned mode;
      unsigned timr;
      unsigned xbcl;
      unsigned xbch;
      unsigned ccr0;
      unsigned ccr1;
      unsigned ccr2;
      unsigned ccr3;
      unsigned ccr4;
      unsigned tsax;
      unsigned tsar;
      unsigned xccr;
      unsigned rccr;
      unsigned bgr;
      unsigned iva;
      unsigned ipc;
      unsigned imr0;
      unsigned imr1;
      unsigned pvr;
      unsigned pim;
      unsigned pcr;
      unsigned xad1;
      unsigned xad2;
      unsigned rah1;
      unsigned rah2;
      unsigned ral1;
      unsigned ral2;
      unsigned rlcr;
      unsigned aml;
      unsigned amh;
      unsigned pre;
      unsigned xon;
      unsigned xoff;
      unsigned tcr;
      unsigned dafo;
      unsigned rfc;
      unsigned tic;
      unsigned mxn;
      unsigned mxf;
      unsigned synl;
      unsigned synh;
      unsigned n_rbufs;
      unsigned n_tbufs;
      unsigned n_rfsize_max;
      unsigned n_tfsize_max;
    };
  }
}

#endif
