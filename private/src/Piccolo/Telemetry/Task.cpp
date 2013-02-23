//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************
// $Id:: Task.cpp 12695 2013-01-23 22:54:41Z rasm                         $:*
//***************************************************************************

// ISO C++ 98 headers.
#include <iomanip>
#include <iostream>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Sensors
{
  namespace Piccolo
  {
    namespace Telemetry
    {
      using DUNE_NAMESPACES;
      using namespace DUNE::Piccolo;

      struct Arguments
      {
        bool low_res;  // Use low resolution packets.
        bool extended; // Extended telemetry.
        uint16_t bandwidth_mode; //  Bandwidth mode.
        std::string servo_sys_entity; // Servo system entity label.
        std::string power_sys_entity; // Power system entity label.
        std::string static_pressure_entity; // Static pressure entity label.
        std::string dynamic_pressure_entity; // Dynamic pressure entity label.
      };

      struct Task: public APPacketProcessor
      {
        Arguments m_args;

        struct
        {
          bool ap_on : 1;
          bool engine_killed : 1;
          bool tracking : 1;
          bool initialized : 1;
        } m_sta;

        Time::Counter<double> m_telemetry_tstep;
        APTelemetry m_telemetry;
        APPacket m_pkt;
        APWaypoint m_wpts[NUM_FP_POINTS];
        APWaypointMask m_wmask;
        IMC::CacheControl m_cc;
        IMC::GpsFix m_gpsfix;

        // IMC standard telemetry.
        IMC::EstimatedState m_estate; // Navigational state estimate
        IMC::EstimatedStreamVelocity m_wv; // Wind velocity estimate.
        IMC::IndicatedSpeed m_ias; // Indicated air speed.
        IMC::TrueSpeed m_tas; // True air speed.
        IMC::Rpm m_rpm; // RPMs.
        IMC::RSSI m_rssi; // RSSI.
        IMC::Temperature m_temp; // Internal temperature.
        IMC::Pressure m_static_p; // Static pressure.
        IMC::Pressure m_dynamic_p; // Dynamic pressure.
        IMC::Voltage m_power_v; // Internal voltage.
        IMC::Current m_power_c; // Internal current.
        IMC::Voltage m_servo_v; // Servo voltage.
        IMC::Current m_servo_c; // Servo current.
        IMC::PiccoloTrackingState m_tstate; // Piccolo traking state.

        // IMC extended telemetry
        IMC::Acceleration m_accel; // Acceleration.
        IMC::AngularVelocity m_agvel; // Angular Velocity.
        IMC::DesiredPath m_dpath; // Desired path.
        IMC::DesiredHeading m_dhead; // Desired heading.
        IMC::DesiredZ m_dz; // Desired depth.
        IMC::DesiredRoll m_droll; // Desired roll.
        IMC::DesiredSpeed m_dspeed; // Desired speed.
        IMC::DesiredVerticalRate m_dvr; // Desired vertical rate.
        IMC::SetControlSurfaceDeflection m_scsd; // Set control surface deflection.

        Task(const std::string& name, Tasks::Context& ctx):
          APPacketProcessor(name, ctx)
        {
          std::memset(&m_sta, 0, sizeof(m_sta));

          param("Low Resolution Telemetry", m_args.low_res)
          .defaultValue("false")
          .description("Piccolo bandwidth mode");

          param("Bandwidth Mode", m_args.bandwidth_mode)
          .minimumValue("0")
          .maximumValue("8")
          .defaultValue("4")
          .description("Piccolo bandwidth mode");

          param("Extended Telemetry", m_args.extended)
          .defaultValue("false")
          .description("Provide extended telemetry");

          param("Servos - Entity Label", m_args.servo_sys_entity)
          .defaultValue("Piccolo Servo System")
          .description("Entity label for servo system data");

          param("Power - Entity Label", m_args.power_sys_entity)
          .defaultValue("Piccolo")
          .description("Entity label for power data");

          param("Static Pressure - Entity Label", m_args.static_pressure_entity)
          .defaultValue("Static Pressure")
          .description("Entity label for static pressure data");

          param("Dynamic Pressure - Entity Label", m_args.dynamic_pressure_entity)
          .defaultValue("Dynamic Pressure")
          .description("Entity label for dynamic pressure data");

          // Setup packet handlers
          hAP(TELEMETRY_HI_RES, &Task::onTelemetry);
          hAP(TELEMETRY_LO_RES, &Task::onTelemetry);
          hAP(SYSTEM_VERSION, &Task::onSystemVersion);
          hAP(SYSTEM_STATUS_HI_RES, &Task::onSystemStatus);
          hAP(SYSTEM_STATUS_LO_RES, &Task::onSystemStatus);
          hAP(USER_WARNING, &Task::onUserWarning);
          hAP(WAYPOINT, &Task::onWaypointPacket);
          hAP(WAYPOINT_LIST, &Task::onWaypointListPacket);

          //hAP(BANDWIDTH_MODE, &Task::onBandwidthMode);

          // Set IMC message handlers
          bind<IMC::ListPiccoloWaypoints>(this);
        }

        ~Task(void)
        { }

        void
        onUpdateParameters(void)
        {
          m_tstate.status = 0;
          std::memset(m_wmask, 0, sizeof(m_wmask));
        }

        void
        onEntityReservation(void)
        {
          unsigned eid = reserveEntity(m_args.servo_sys_entity);
          m_servo_c.setSourceEntity(eid);
          m_servo_v.setSourceEntity(eid);

          eid = reserveEntity(m_args.power_sys_entity);
          m_power_c.setSourceEntity(eid);
          m_power_v.setSourceEntity(eid);

          m_static_p.setSourceEntity(reserveEntity(m_args.static_pressure_entity));
          m_dynamic_p.setSourceEntity(reserveEntity(m_args.dynamic_pressure_entity));
        }

        void
        sendSetupPackets(void)
        {
          BandwidthMode_t bmode = {0xFF, m_args.low_res, m_args.bandwidth_mode, 0, 0, 0, 0};
          FormBandwidthModePacket(&m_pkt, bmode);
          sendToAP(&m_pkt);

          MakeAutopilotPacket(&m_pkt, SYSTEM_VERSION, 0);
          sendToAP(&m_pkt);

          requestWaypoints();
        }

        void
        requestWaypoints(void)
        {
          APWaypointMask mask;
          std::memset(mask, 0xFF, sizeof(mask));
          FormWaypointListPacket(&m_pkt, mask, 2);
          inf(DTR("requesting waypoint list"));
          sendToAP(&m_pkt);
        }

        void
        onTelemetry(const APPacket* pkt)
        {
          BOOL r;

          if (pkt->PktType == TELEMETRY_LO_RES)
            r = DecodeTelemetryLoResPacket(pkt, &m_telemetry);
          else
            r = DecodeTelemetryHiResPacket(pkt, &m_telemetry);

          if (!r)
          {
            err(DTR("error decoding telemetry packet"));
            return;
          }

          m_telemetry_tstep.reset();

          if (m_telemetry.AvailableData.GPS)
          {
            m_estate.vx = m_telemetry.GPS.VNorth;
            m_estate.vy = m_telemetry.GPS.VEast;
            m_estate.vz = m_telemetry.GPS.VDown;

            m_gpsfix.utc_time = 3600.0*m_telemetry.GPS.hours
                + 60.0 * m_telemetry.GPS.minutes
                + m_telemetry.GPS.seconds;
            m_gpsfix.utc_day = m_telemetry.GPS.day;
            m_gpsfix.utc_month = m_telemetry.GPS.month;
            m_gpsfix.utc_year = m_telemetry.GPS.year;

            m_gpsfix.satellites = m_telemetry.GPS.TrackedSats;

            m_gpsfix.lat = m_telemetry.GPS.Latitude;
            m_gpsfix.lon = m_telemetry.GPS.Longitude;
            m_gpsfix.height = m_telemetry.GPS.Altitude;

            m_gpsfix.cog = m_telemetry.GPS.Direction;
            m_gpsfix.sog = m_telemetry.GPS.Speed;

            //Testing
            m_gpsfix.hdop = m_telemetry.GPS.PDOP;

            if(m_telemetry.GPS.year>=2012)
              m_gpsfix.validity |= IMC::GpsFix::GFV_VALID_TIME | IMC::GpsFix::GFV_VALID_DATE;

            if(m_telemetry.GPS.PDOP<5)
              m_gpsfix.validity |= IMC::GpsFix::GFV_VALID_POS;

            dispatch(m_gpsfix);

            double distance_to_ref = WGS84::distance(m_estate.lat,m_estate.lon,0,
                m_telemetry.GPS.Latitude,m_telemetry.GPS.Longitude,0);

            if(distance_to_ref>1000)
            {
              m_estate.lat = m_telemetry.GPS.Latitude;
              m_estate.lon = m_telemetry.GPS.Longitude;
              m_estate.height = m_telemetry.GPS.Altitude;

              m_estate.x = 0;
              m_estate.y = 0;
              m_estate.z = 0;
            }
            else
            {
              WGS84::displacement(m_estate.lat, m_estate.lon, m_estate.height,
                  m_telemetry.GPS.Latitude, m_telemetry.GPS.Longitude, m_telemetry.GPS.Altitude,
                  &m_estate.x, &m_estate.y, &m_estate.z);
            }
          }

          if (m_telemetry.AvailableData.CalSensor)
          {
            m_estate.phi = Angles::normalizeRadian(m_telemetry.Euler[ROLL_AXIS]);
            m_estate.theta = Angles::normalizeRadian(m_telemetry.Euler[PITCH_AXIS]);
            m_estate.psi = Angles::normalizeRadian(m_telemetry.Euler[YAW_AXIS]);

            if (m_telemetry.AvailableData.GPS)
            {
              // Body-fixed frame velocity components
              BodyFixedFrame::toBodyFrame(m_estate.phi, m_estate.theta, m_estate.psi,
                                          (m_telemetry.GPS.VNorth - m_telemetry.WindSouth),
                                          (m_telemetry.GPS.VEast - m_telemetry.WindWest),
                                          (m_telemetry.GPS.VDown),
                                          &m_estate.u, &m_estate.v, &m_estate.w);
            }

            // True air speed
            m_tas.value = m_telemetry.TAS;

            // Wind stream
            m_wv.x = -m_telemetry.WindSouth;
            m_wv.y = -m_telemetry.WindWest;
            m_wv.z = 0;

            m_rpm.value = m_telemetry.LeftRPM;

            // Dispatch messages
            dispatch(m_tas);
            dispatch(m_wv);
            dispatch(m_rpm);
          }

          if (m_telemetry.AvailableData.RawSensor)
          {
            // Angular rates
            m_estate.p = m_telemetry.Gyro[ROLL_AXIS];
            m_estate.q = m_telemetry.Gyro[PITCH_AXIS];
            m_estate.r = m_telemetry.Gyro[YAW_AXIS];

            // Indicated Air Speed
            m_ias.value = m_telemetry.IAS;

            // Static & dynamic pressure
            // Note that IMC::Pressure uses hecto-Pascal as unit.
            m_static_p.value = m_telemetry.Pstatic * 0.01;
            m_dynamic_p.value = m_telemetry.Pdynamic * 0.01;

            // Dispatch messages
            dispatch(m_ias);
            dispatch(m_static_p);
            dispatch(m_dynamic_p);

            // Acceleration / Angular velocity.
            if (m_args.extended)
            {
              m_accel.time = Clock::getSinceEpoch();
              m_agvel.time = m_accel.time;
              m_accel.x = m_telemetry.Accel[X_AXIS];
              m_accel.y = m_telemetry.Accel[Y_AXIS];
              m_accel.z = m_telemetry.Accel[Z_AXIS];
              m_agvel.x = m_telemetry.Gyro[ROLL_AXIS];
              m_agvel.y = m_telemetry.Gyro[PITCH_AXIS];
              m_agvel.z = m_telemetry.Gyro[YAW_AXIS];

              dispatch(m_agvel);
              dispatch(m_accel);
            }
          }

          dispatch(m_estate);

          if (m_args.extended)
          {
            for (int i = 0; i < m_telemetry.AvailableData.NumActuators; i++)
            {
              m_scsd.id = i;
              m_scsd.angle = m_telemetry.Actuators[i];
              dispatch(m_scsd);
            }
          }
        }

        void
        onSystemVersion(const APPacket* pkt)
        {
          Version_t v;
          Board_t b;

          if (!DecodeSystemVersionPacket(pkt, &v, &b))
          {
            err(DTR("could not decode system version packet"));
            return;
          }

          inf(DTR("software version %d.%d.%d patch %d %4d-%02d-%02d"),
              (int)v.MajorVersion, (int)v.MinorVersion, (int)v.SubVersion, (int)v.PatchNum,
              (int)v.Date.year, (int)v.Date.month, (int)v.Date.day);

          inf(DTR("hardware board - SN %d FN %d rev %d config %d %d-%02d-%02d"),
              b.SerialNumber, b.FeatureCode, b.Rev, (unsigned)b.Config, b.Date.year, b.Date.month, b.Date.day);
        }

        void
        check(uint8_t mask, bool is_on, const char* desc)
        {
          bool was_on = (m_tstate.status & mask) != 0;

          if (was_on != is_on)
          {
            if (is_on)
              m_tstate.status |= mask;
            else
              m_tstate.status &= ~mask;

            war(DTR("%s is %s"), desc, (is_on ? "enabled" : "disabled"));
          }
        }

        void
        onSystemStatus(const APPacket* pkt)
        {
          BOOL r = false;
          BOOL dummy = true;

          if (pkt->PktType == SYSTEM_STATUS_LO_RES)
            r = DecodeSystemStatusLoResPacket(pkt, &m_telemetry.System, &m_telemetry.Nav, &m_telemetry.AP, &dummy);
          else
            r = DecodeSystemStatusHiResPacket(pkt, &m_telemetry.System, &m_telemetry.Nav, &m_telemetry.AP, &dummy);

          if (!r)
          {
            err(DTR("error decoding system status packet"));
            return;
          }

          AutopilotStatus_t& status = m_telemetry.AP;

          check(PiccoloTrackingState::STA_AUTOPILOT, status.GlobalOn, "autopilot");
          check(PiccoloTrackingState::STA_ENGINE_KILLED, !status.EngineKill, "engine");
          check(PiccoloTrackingState::STA_TRACKER, status.TrackerStatus, "tracker");

          if (m_tstate.status & PiccoloTrackingState::STA_TRACKER)
          {
            double los_bearing = 0;
            double  los_range = 0;
            double v_dir, v_speed = 0;

            toPolar(m_telemetry.GPS.VNorth, m_telemetry.GPS.VEast, &v_dir, &v_speed);

            if (!status.Orbit)
            {
              m_tstate.from = status.WaypointFrom >= 100 ? 100 : status.WaypointFrom;
              m_tstate.loiter = PiccoloTrackingState::LTR_NO;

              double track_bearing = 0;
              double track_range = 0;

              WGS84::getNEBearingAndRange(status.Waypoint1.Lat, status.Waypoint1.Lon,
                                          status.Waypoint2.Lat, status.Waypoint2.Lon,
                                          &track_bearing, &track_range);

              WGS84::getNEBearingAndRange(status.Waypoint1.Lat, status.Waypoint1.Lon,
                                          m_telemetry.GPS.Latitude, m_telemetry.GPS.Longitude,
                                          &los_bearing, &los_range);

              los_bearing -= track_bearing;
              m_tstate.x = track_range - std::cos(los_bearing) * los_range;
              m_tstate.y = std::sin(los_bearing) * los_range;
              v_dir -= track_bearing;
            }
            else
            {
              m_tstate.from = 100;
              m_tstate.loiter = PiccoloTrackingState::LTR_YES;

              WGS84::getNEBearingAndRange(status.Waypoint2.Lat, status.Waypoint2.Lon,
                                          m_telemetry.GPS.Latitude, m_telemetry.GPS.Longitude,
                                          &los_bearing, &los_range);
              m_tstate.x = 0;
              m_tstate.y = los_range - status.OrbitRadius;
              v_dir = v_dir - c_pi - los_bearing - c_half_pi;
            }

            m_tstate.to = status.WaypointTo;
            m_tstate.eta = status.ETA;
            m_tstate.vx = std::cos(v_dir) * v_speed;
            m_tstate.vy = std::sin(v_dir) * v_speed;
          }

          dispatch(m_tstate);

          if (m_args.extended)
          {
            if (status.TrackerStatus)
            {
              m_dpath.start_lat = status.Waypoint1.Lat;
              m_dpath.start_lon = status.Waypoint1.Lon;
              m_dpath.end_lat = status.Waypoint2.Lat;
              m_dpath.end_lon = status.Waypoint2.Lon;
              m_dpath.lradius = status.Orbit ? status.OrbitRadius : 0;
              m_dpath.flags = 0;
              dispatch(m_dpath);
            }
            m_dhead.value = status.LoopTargets[AP_LOOP_HEADING];
            m_dz.value = -status.LoopTargets[AP_LOOP_ALT];
            m_dz.z_units = IMC::Z_DEPTH;
            m_droll.value = status.LoopTargets[AP_LOOP_BANK];
            m_dvr.value = status.LoopTargets[AP_LOOP_VRATE];
            m_dspeed.value = status.LoopTargets[AP_LOOP_IAS];
            m_dspeed.speed_units = IMC::SUNITS_METERS_PS;

            dispatch(m_dhead);
            dispatch(m_dz);
            dispatch(m_dvr);
            dispatch(m_droll);
            dispatch(m_dspeed);
          }

          SystemDiagnostic_t& system = m_telemetry.System;

          // Internal temperature
          m_temp.value = system.AvionicsTemp;

          // Internal + servo current & voltage
          m_power_c.value = system.InputCurrent;
          m_power_v.value = system.InputVoltage;
          m_servo_c.value = system.ServoCurrent;
          m_servo_v.value = system.ServoVoltage;

          // Report RSSI
          m_rssi.value = 100.0 * (system.RSSI - c_min_rssi) / (c_max_rssi - c_min_rssi);

          dispatch(m_rssi);
          dispatch(m_temp);
          dispatch(m_power_v);
          dispatch(m_power_c);
          dispatch(m_servo_v);
          dispatch(m_servo_c);
        }

        void
        onUserWarning(const APPacket* pkt)
        {
          char* msg;
          uint8_t type, code;
          // Dumb SDK API forces direct dirty cast in the following line, even though the call is harmless.
          msg = DecodeUserWarningPacket((APPacket*)pkt, &type, &code);

          if (!msg)
            err(DTR("error decoding USER_WARNING packet"));
          else
            war(DTR("AP message: %s (error type %d, code %d)"), msg, (int)type, (int)code);
        }

        bool
        equalWaypoints(const APWaypoint& w1, const APWaypoint& w2)
        {
          return
          w1.Next == w2.Next &&
          w1.AGL == w2.AGL &&
          std::fabs(w1.OrbitRadius - w2.OrbitRadius) < 1e-02 &&
                                                       (w1.OrbitRadius <= 0 || w1.OrbitTime == w2.OrbitTime) &&
          std::fabs(w1.Point.Lat - w2.Point.Lat) < 1e-06 &&
                                                   std::fabs(w1.Point.Lon - w2.Point.Lon) < 1e-06 &&
                                                                                            std::fabs(w1.Point.Alt - w2.Point.Alt) < 1e-02;
        }

        void
        onWaypointPacket(const APPacket* pkt)
        {
          APWaypoint w;
          uint8_t idx = DecodeWaypointPacket(pkt, &w);

          if (idx >= NUM_FP_POINTS)
          {
            err(DTR("error decoding waypoint packet"));
            return;
          }

          if (!GetFPMaskBit(m_wmask, idx) || !equalWaypoints(m_wpts[idx], w))
          {
            std::memcpy(&m_wpts[idx], &w, sizeof(w));
            SetFPMaskBit(m_wmask, idx);

            inf(DTR("w #%d -- lat: %0.5f lon: %0.5f alt: %0.1f orbit: %0.1f / %u / %d"),
                idx, Angles::degrees(w.Point.Lat), Angles::degrees(w.Point.Lon),
                w.Point.Alt, w.OrbitRadius, w.OrbitTime, w.Direction);
          }

          IMC::PiccoloWaypoint imc_pw;
          imc_pw.index = idx;
          imc_pw.next = w.Next;
          imc_pw.lat = w.Point.Lat;
          imc_pw.lon = w.Point.Lon;
          imc_pw.depth = -w.Point.Alt;
          imc_pw.lradius = w.OrbitRadius;
          imc_pw.ltime = w.OrbitTime;
          imc_pw.ldirection = w.Direction ? IMC::PiccoloWaypoint::LD_CLOCKW : IMC::PiccoloWaypoint::LD_CCLOCKW;

          dispatch(imc_pw);
        }

        void
        onWaypointListPacket(const APPacket* pkt)
        {
          APWaypointMask mask;
          uint8_t flags = DecodeWaypointListPacket(pkt, mask);

          if (flags != 0)
            return;

          // See if any waypoints were deleted.
          for (int idx = FindFirstFPMaskBitSet(m_wmask); idx >= 0 && idx < NUM_FP_POINTS; idx = FindNextFPMaskBitSet(m_wmask, idx))
          {
            if (!GetFPMaskBit(mask, idx))
            {
              IMC::PiccoloWaypointDeleted wpt_del;
              wpt_del.index = idx;
              dispatch(wpt_del);

              inf(DTR("w #%d -- deleted"), idx);
            }
          }

          std::memcpy(m_wmask, mask, sizeof(mask));
        }

        void
        consume(const IMC::ListPiccoloWaypoints* lpw)
        {
          (void)lpw;
          requestWaypoints();
        }

        void
        onMain(void)
        {
          m_telemetry_tstep.setTop(std::max(2.0, 3.0 / c_telemetry_rates[m_args.bandwidth_mode]));

          m_telemetry_tstep.reset();
          while (!stopping())
          {
            waitForMessages(1.0);

            if (m_telemetry_tstep.overflow())
            {
              if (getEntityState() != IMC::EntityState::ESTA_ERROR)
                setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_MISSING_DATA);
            }
            else if (getEntityState() != IMC::EntityState::ESTA_NORMAL)
            {
              sendSetupPackets();
              setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
            }
          }
        }
      };
    }
  }
}

DUNE_TASK
