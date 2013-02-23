//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************
// $Id:: PiccoloConverters.hpp 12770 2013-01-28 17:38:25Z jfortuna        $:*
//***************************************************************************

#ifndef PICCOLO_CONVERTERS_HPP_INCLUDED_
#define PICCOLO_CONVERTERS_HPP_INCLUDED_

#define GPS_EPOCH 315964800

#include <time.h>

namespace Piccolo
{
  void gps_to_ymdhms(uint32_t gps_week, uint32_t ITOW, uint16_t *year, uint8_t *month,
      uint8_t* day, uint8_t *hours, uint8_t *minutes, float *seconds)
  {
    *seconds = (float) (ITOW % 1000) / 1000;

    long gps_sec_since_1970 = GPS_EPOCH + 7 * 24 * 60 * 60 * gps_week + ITOW / 1000;

    time_t t = gps_sec_since_1970;

    struct tm* utc;

    utc = gmtime(&t);

    *year = utc->tm_year + 1900;
    *month = utc->tm_mon +1;
    *day = utc->tm_mday;
    *hours = utc->tm_hour;
    *minutes = utc->tm_min;
    *seconds += utc->tm_sec;
  }

  void gps_to_ymdt(uint32_t gps_week, uint32_t ITOW, uint16_t *year, uint8_t *month,
        uint8_t* day, float *time)
  {
    uint8_t hours;
    uint8_t minutes;
    float seconds;

    gps_to_ymdhms(gps_week, ITOW, year, month, day, &hours, &minutes, &seconds);

    *time = 3600 * hours + 60 * minutes + seconds;
  }
}

#endif
