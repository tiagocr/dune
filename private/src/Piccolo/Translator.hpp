//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************

#ifndef DUNE_PICCOLO_TRANSLATOR_HPP_INCLUDED_
#define DUNE_PICCOLO_TRANSLATOR_HPP_INCLUDED_

#include <sstream>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include "Piccolo.hpp"

namespace Piccolo
{
  using DUNE_NAMESPACES;

  class Translator
  {
  public:
    Translator(Task* t):
      task(t), ref_lat(0.0), ref_lon(0.0), ref_hei(-5000)
  { }

    void
    translate(TelemetryHighRes* pkt, bool simulator)
    {
      IMC::EstimatedState e_state;
      IMC::EstimatedStreamVelocity stream_vel;
      IMC::GpsFix gps_fix;
      IMC::IndicatedSpeed ind_speed;
      IMC::Acceleration accel;

      if(pkt->data_flags & TelemetryHighRes::DATA_GPS)
      {
        fp64_t rcv_lat = marcs2rad * pkt->lat;
        fp64_t rcv_lon = marcs2rad * pkt->lon;
        fp32_t rcv_hei = 0.01 * pkt->height - 1000; //cm to m

        double distance_to_ref = WGS84::distance(ref_lat,ref_lon,ref_hei,
            rcv_lat,rcv_lon,rcv_hei);

        if(distance_to_ref>1000)
        {
          e_state.lat = rcv_lat;
          e_state.lon = rcv_lon;
          e_state.height = rcv_hei;

          e_state.x = 0;
          e_state.y = 0;
          e_state.z = 0;

          ref_lat = rcv_lat;
          ref_lon = rcv_lon;
          ref_hei = rcv_hei;
        }
        else
        {
          WGS84::displacement(ref_lat, ref_lon, ref_hei,
              rcv_lat, rcv_lon, rcv_hei,
              &e_state.x, &e_state.y, &e_state.z);

          e_state.lat = ref_lat;
          e_state.lon = ref_lon;
          e_state.height = ref_hei;
        }

        e_state.vx = (float) pkt->vnorth / 100;
        e_state.vy = (float) pkt->veast / 100;
        e_state.vz = (float) pkt->vdown / 100;

        Piccolo::gps_to_ymdt(pkt->gps_week, pkt->gps_tow,
            &gps_fix.utc_year, &gps_fix.utc_month, &gps_fix.utc_day,
            &gps_fix.utc_time);

        gps_fix.lat = rcv_lat;
        gps_fix.lon = rcv_lon;
        gps_fix.height = rcv_hei;

        gps_fix.satellites = (int) pkt->sat_status & TelemetryHighRes::GPS_TRACKED_SATS;

        gps_fix.validity |= GpsFix::GFV_VALID_DATE;
        gps_fix.validity |= GpsFix::GFV_VALID_TIME;

        if( (pkt->gps_status & TelemetryHighRes::GPS_FIX_TYPE) == 0xE000)
          gps_fix.validity |= GpsFix::GFV_VALID_POS;

        task->dispatch(gps_fix, Tasks::DF_LOOP_BACK);
      }


      if(pkt->data_flags & TelemetryHighRes::DATA_SENSOR)
      {
        e_state.phi = (float) pkt->roll / 10000;
        e_state.theta = (float) pkt->pitch / 10000;
        e_state.psi = (float) pkt->yaw / 10000;

        e_state.alt = (float)(pkt->altitude) / 100.0 - 1000.0;

        stream_vel.x = (double) pkt->wind_south / 100;
        stream_vel.y = (double) pkt->wind_west / 100;

        accel.x = (fp64_t)pkt->x_accel * 0.005;
        accel.y = (fp64_t)pkt->y_accel * 0.005;
        accel.z = (fp64_t)pkt->z_accel * 0.005;

        task->dispatch(stream_vel);
        task->dispatch(accel);
      }

      if( (pkt->data_flags & TelemetryHighRes::DATA_SENSOR) &&
          (pkt->data_flags & TelemetryHighRes::DATA_GPS) )
      {
        // Body-fixed frame velocity components
        BodyFixedFrame::toBodyFrame(e_state.phi, e_state.theta, e_state.psi,
                                   (e_state.vx - stream_vel.x),
                                   (e_state.vy - stream_vel.y),
                                    (double)e_state.vz,
                                    &e_state.u, &e_state.v, &e_state.w);
      }

      if(pkt->data_flags & TelemetryHighRes::DATA_RAW_SENSOR)
      {
        e_state.p = (float) pkt->p / 10000;
        e_state.q = (float) pkt->q / 10000;
        e_state.r = (float) pkt->r / 10000;

        ind_speed.value = 0.01 * (double) (pkt->ias - 2000);
        task->dispatch(ind_speed);
      }

      if(!simulator)
      {
        task->dispatch(e_state);
        return;
      }

      //! Simulated State is necessary for ardupilot simulations
      IMC::SimulatedState sim_state;

      sim_state.lat = e_state.lat;
      sim_state.lon = e_state.lon;
      sim_state.height = e_state.height;

      sim_state.x = e_state.x;
      sim_state.y = e_state.y;
      sim_state.z = e_state.z;

      sim_state.phi = e_state.phi;
      sim_state.theta = e_state.theta;
      sim_state.psi = e_state.psi;

      sim_state.u = e_state.u;
      sim_state.v = e_state.v;
      sim_state.w = e_state.w;

      sim_state.p = e_state.p;
      sim_state.q = e_state.q;
      sim_state.r = e_state.r;

      task->dispatch(sim_state);
    }

    void
    translate(GroundStationTelemetry* pkt)
    {
      IMC::EstimatedState e_state;

      fp64_t rcv_lat = marcs2rad * pkt->lat;
      fp64_t rcv_lon = marcs2rad * pkt->lon;
      fp32_t rcv_hei = 0.01 * pkt->height; //cm to m

      double distance_to_ref = WGS84::distance(ref_lat,ref_lon,ref_hei,
          rcv_lat,rcv_lon,rcv_hei);

      if(distance_to_ref>1000)
      {
        e_state.lat = rcv_lat;
        e_state.lon = rcv_lon;
        e_state.height = rcv_hei;

        e_state.x = 0;
        e_state.y = 0;
        e_state.z = 0;

        ref_lat = rcv_lat;
        ref_lon = rcv_lon;
        ref_hei = rcv_hei;
      }
      else
      {
        WGS84::displacement(ref_lat, ref_lon, ref_hei,
            rcv_lat, rcv_lon, rcv_hei,
            &e_state.x, &e_state.y, &e_state.z);

        e_state.lat = ref_lat;
        e_state.lon = ref_lon;
        e_state.height = ref_hei;
      }

      task->dispatch(&e_state);
    }
    void
    translate(SystemStatusHighRes* pkt)
    {
      IMC::PathControlState pcs;
      IMC::Parameter* param = new IMC::Parameter;

      pcs.eta = (uint16_t)pkt->track_status & SystemStatusHighRes::TRACK_ETA;

      if(pcs.eta <= 3)
        pcs.flags |= PathControlState::FL_NEAR;

      param->param = "curr_waypoint";

      param->setDestinationEntity((uint8_t)pkt->waypoint_to); //This is very stupid, need a better way TODO this
//      std::string waypoint = Utils::String::str((uint8_t)pkt->waypoint_to);
//      param->value = waypoint;

      task->dispatch(pcs);
      task->receive(param);
    }

    ~Translator(void)
    {}

  private:
    Task* task;
    fp64_t ref_lat;
    fp64_t ref_lon;
    fp32_t ref_hei;
  };
}

#endif
