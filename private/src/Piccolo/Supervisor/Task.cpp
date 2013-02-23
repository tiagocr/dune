//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************

// ISO C++ 98 headers.
#include <iomanip>
#include <iostream>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Supervisors
{
  namespace Piccolo
  {
    using DUNE_NAMESPACES;
    using namespace DUNE::Piccolo;

    // Entity state description labels.
    static const char* c_state_desc[] =
    {
      "",
      DTR("ready"),
      DTR("external PCC control"),
      DTR("active control"),
      DTR("resetting control state")
    };

    const double c_telemetry_timeout = 8.0;

    struct Task: public APPacketProcessor
    {
      APPacket m_pkt;
      APMissionLimits m_ml;

      IMC::Abort m_abort;
      IMC::EstimatedState m_estate;
      IMC::PiccoloTrackingState m_ts;
      IMC::PiccoloControlConfiguration m_cfg;

      double m_telemetry_time;
      double m_try_reset_time;

      // Conditions.
      typedef uint16_t cndmask_t;

      static const cndmask_t c_telemetry = 0x01; // Telemetry is arriving.
      static const cndmask_t c_autopilot = 0x02; // Autopilot is on.
      static const cndmask_t c_lcw = 0x04; // Lost comm. waypoint is set.
      static const cndmask_t c_config = 0x08; // There is a valid configuration.
      static const cndmask_t c_sanity = c_telemetry | c_autopilot | c_lcw | c_config;
      static const cndmask_t c_trk = 0x10; // Tracker is on.
      static const cndmask_t c_trk_h = 0x20; // Tracking a handover waypoint.
      static const cndmask_t c_trk_p = 0x40; // Tracking a plan waypoint.
      static const cndmask_t c_trk_sw = 0x80; // Tracking service waypoint.
      static const cndmask_t c_trk_mask = c_trk | c_trk_h | c_trk_p | c_trk_sw;
      static const cndmask_t c_reset = 0x0100; // Tracker reset being attempted.

      // Supervision state.
      cndmask_t m_cnd;

      enum sup_state_t
      {
        c_ss_insane,
        c_ss_ready,
        c_ss_external,
        c_ss_exec,
        c_ss_reset,
        c_ss_number
      };

      sup_state_t m_sup_state;

      inline bool
      isHandoverWpt(uint8_t index)
      {
        return cnd(c_config) && index >= m_cfg.h_min && index <= m_cfg.h_max;
      }

      inline bool
      isPlanWpt(uint8_t index)
      {
        return cnd(c_config) && index >= m_cfg.p_min && index <= m_cfg.p_max;
      }

      inline void
      cnd(cndmask_t mask, bool yn)
      {
        if (yn)
          m_cnd |= mask;
        else
          m_cnd &= ~mask;
      }

      inline bool
      cnd(cndmask_t mask)
      {
        return (m_cnd & mask) != 0;
      }

      inline bool
      allcnd(cndmask_t mask)
      {
        return (m_cnd & mask) == mask;
      }

      Task(const std::string& name, Tasks::Context& ctx):
        APPacketProcessor(name, ctx),
        m_sup_state(c_ss_insane)
      {
        param("Plan Waypoints - Default Min", m_cfg.p_min)
        .defaultValue("40")
        .minimumValue("0")
        .maximumValue("99");

        param("Plan Waypoints - Default Max", m_cfg.p_max)
        .defaultValue("69")
        .minimumValue("0")
        .maximumValue("99");

        param("Handover Waypoints - Default Min", m_cfg.h_min)
        .defaultValue("30")
        .minimumValue("0")
        .maximumValue("99");

        param("Handover Waypoints - Default Max", m_cfg.h_max)
        .defaultValue("39")
        .minimumValue("0")
        .maximumValue("99");

        param("Service Waypoint - Default Loiter Radius", m_cfg.sw_radius)
        .units(Units::Meter)
        .defaultValue("200")
        .minimumValue("100");

        param("Service Waypoint - Default Altitude", m_cfg.sw_alt)
        .units(Units::Meter)
        .defaultValue("200")
        .minimumValue("30");

        param("Service Waypoint - Default Speed", m_cfg.sw_speed)
        .units(Units::MeterPerSecond)
        .defaultValue("20")
        .minimumValue("10");

        hAP(RESET_REPORT, &Task::onResetReport);
        hAP(MISSION_LIMITS, &Task::onMissionLimitsPacket);

        bind<IMC::Calibration>(this);
        bind<IMC::EstimatedState>(this);
        bind<IMC::GetPiccoloControlConfiguration>(this);
        bind<IMC::GotoPiccoloWaypoint>(this);
        bind<IMC::PiccoloControlConfiguration>(this);
        bind<IMC::PiccoloTrackingState>(this);
        bind<IMC::VehicleState>(this);
      }

      void
      onUpdateParameters(void)
      {
        m_cnd = 0;

        setEntityState(IMC::EntityState::ESTA_INIT, Status::CODE_BOOT);
        m_telemetry_time = 0;
        m_try_reset_time = -1;

        if(getEntityId() != DUNE_IMC_CONST_UNK_EID)
        {
          validateConfig();
          reportState();
          dispatch(m_cfg);
        }
      }

      ~Task()
      { }

      void
      validateConfig(void)
      {
        bool ok = true;

        const int c_min_p_waypoints = 20;

        if (m_cfg.p_max - m_cfg.p_min < c_min_p_waypoints)
        {
          err(DTR("invalid configuration for plan waypoints: %d -- %d"),
              (int)m_cfg.p_min, (int)m_cfg.p_max);
          ok = false;
        }

        const int c_min_h_waypoints = 5;

        if (m_cfg.h_max - m_cfg.h_min < c_min_h_waypoints)
        {
          err(DTR("invalid configuration for handover waypoints: %d -- %d"),
              (int)m_cfg.h_min, (int)m_cfg.h_max);
          ok = false;
        }

        if (m_cfg.h_max >= m_cfg.p_min && m_cfg.h_min <= m_cfg.p_max)
        {
          err(DTR("clash between handover and plan waypoints"));
          ok = false;
        }

        cnd(c_trk_mask, false);
        cnd(c_config, ok);
      }

      void
      reportState(void)
      {
        int prev_state = m_sup_state;

        if (!allcnd(c_sanity))
        {
          std::string msg;
          if (!cnd(c_telemetry))
            msg = "telemetry timeout";
          else if (!cnd(c_autopilot))
            msg = "autopilot is off";
          else if (!cnd(c_lcw))
            msg = "no lost communications waypoint";
          else if (!cnd(c_config))
            msg = "invalid configuration";

          if (m_sup_state == c_ss_exec)
            abort("insane state");

          m_sup_state = c_ss_insane;
          setEntityState(IMC::EntityState::ESTA_ERROR, msg.c_str());
          err(DTR("state now: %s"), msg.c_str());
          return;
        }
        else if (m_sup_state != c_ss_exec)
        {
          if (!cnd(c_trk))
          {
            if (cnd(c_reset))
            {
              m_sup_state = c_ss_reset;
              setEntityState(IMC::EntityState::ESTA_NORMAL, c_state_desc[m_sup_state].c_str());
            }
            else
            {
              m_sup_state = c_ss_external;
              setEntityState(IMC::EntityState::ESTA_ERROR, c_state_desc[m_sup_state].c_str());
            }
          }
          else if (cnd(c_trk_h | c_trk_sw))
          {
            setEntityState(IMC::EntityState::ESTA_NORMAL, c_state_desc[m_sup_state].c_str());
          }
          else
          {
            m_sup_state = c_ss_external;
            setEntityState(IMC::EntityState::ESTA_ERROR, c_state_desc[m_sup_state].c_str());
          }
        }
        else if (m_sup_state == c_ss_exec)
        {
          if (cnd(c_trk) && !cnd(c_trk_h | c_trk_p))
          {
            abort("tracker is following external waypoints");
            m_sup_state = c_ss_external;
            setEntityState(IMC::EntityState::ESTA_ERROR, c_state_desc[m_sup_state].c_str());
          }
        }

        if ((prev_state != m_sup_state) && (m_sup_state != c_ss_insane))
          inf(DTR("state now: %s"), c_state_desc[m_sup_state]);
      }

      void
      consume(const IMC::EstimatedState* estate)
      {
        m_estate = *estate;
      }

      void
      onReportEntityState(void)
      {
        if (!cnd(c_lcw))
          requestMissionLimits();

        if (Clock::get() - m_telemetry_time > c_telemetry_timeout)
          cnd(c_telemetry, false);

        reportState();
      }

      void
      consume(const IMC::Calibration* cal)
      {
        (void)cal;

        if (m_sup_state == c_ss_insane || m_sup_state == c_ss_external)
        {
          abort("not ready for calibration requests");
          reportState();
        }
        else
        {
          m_sup_state = c_ss_exec;
          loiterAtCurrentPosition();
        }
      }

      void
      consume(const IMC::GetPiccoloControlConfiguration* msg)
      {
        (void)msg;
        dispatch(m_cfg);
      }

      void
      consume(const IMC::GotoPiccoloWaypoint* msg)
      {
        if (m_sup_state != c_ss_ready)
        {
          err(DTR("not ready for tracking commands"));
          return;
        }

        if (!isHandoverWpt(msg->index))
        {
          err(DTR("waypoint %d is not a handover waypoint"), (int)msg->index);
          return;
        }

        trackWpt(msg->index);
      }

      void
      consume(const IMC::PiccoloControlConfiguration* msg)
      {
        m_cfg = *msg;
        m_cfg.setSource(getSystemId());
        m_cfg.setDestination(IMC::AddressResolver::invalid());

        inf(DTR("configuration has been set"));

        IMC::CacheControl cc;
        cc.message.set(*msg);
        cc.op = IMC::CacheControl::COP_STORE;
        dispatch(cc);
        dispatch(m_cfg);

        validateConfig();
        reportState();
      }

      void
      requestMissionLimits(void)
      {
        MakeAutopilotPacket(&m_pkt, MISSION_LIMITS, 0);
        sendToAP(&m_pkt);
      }

      void
      consume(const IMC::PiccoloTrackingState* ts)
      {
        cndmask_t prev = m_cnd;

        m_telemetry_time = Clock::get();

        cnd(c_telemetry, true);
        cnd(c_autopilot, (ts->status & ts->STA_AUTOPILOT) != 0);
        cnd(c_trk, (ts->status & ts->STA_TRACKER) != 0);
        cnd(c_trk_h, cnd(c_trk) && isHandoverWpt(ts->to));
        cnd(c_trk_p, cnd(c_trk) && isPlanWpt(ts->to));
        cnd(c_trk_sw, cnd(c_trk_p) && ts->to == m_cfg.p_max);

        if (allcnd(c_sanity) && m_sup_state != c_ss_exec && cnd(c_autopilot) && !cnd(c_trk))
        {
          // Try to set tracker on
          double now = Clock::get();
          if (now - m_try_reset_time >= 2)
          {
            loiterAtCurrentPosition();
            if (m_try_reset_time < 0)
              cnd(c_reset, true); // sane to see recovery as normal for 2s
            else
              cnd(c_reset, false); // not sane after that, even if task keeps trying
            m_try_reset_time = now;
          }
        }
        else
        {
          m_try_reset_time = -1;
          cnd(c_reset, false);
        }

        if (m_cnd != prev)
          reportState();
      }

      void
      consume(const IMC::VehicleState* vs)
      {
        bool vs_exec = (vs->op_mode == IMC::VehicleState::VS_CALIBRATION ||
                        vs->op_mode == IMC::VehicleState::VS_MANEUVER);

        if (m_sup_state == c_ss_exec && !vs_exec)
        {
          // Vehicle stopped executing a plan.
          if (!vs_exec)
          {
            if (!cnd(c_trk))
              cnd(c_reset, true);
            loiterAtCurrentPosition();
            m_sup_state = c_ss_ready;
            reportState();
          }
          return;
        }

        if (vs_exec)
        {
          if (m_sup_state == c_ss_ready || m_sup_state == c_ss_reset)
          {
            // Vehicle about to start executing a plan.
            m_sup_state = c_ss_exec;
            reportState();
          }
          else if (m_sup_state != c_ss_exec)
          {
            abort("not ready for maneuver execution");
            reportState();
          }
        }
      }

      void
      onMissionLimitsPacket(const APPacket* pkt)
      {
        if (!DecodeMissionLimitsPacket(pkt, &m_ml))
        {
          err(DTR("error decoding mission limits packet"));
          return;
        }

        cnd(c_lcw, true);
        reportState();
      }

      void
      onResetReport(const APPacket* pkt)
      {
        UInt16 RSR, Vec;
        UInt32 PC, MSR;
        UInt32 Link;

        if (!DecodeResetReportPacket(pkt, &RSR, &Vec, &PC, &MSR, &Link))
          return;

        err(DTR("PICCOLO SYSTEM RESET ! Info: %u %u %u %u"), RSR, Vec, (unsigned)PC, (unsigned)MSR);

        if (RSR & 0x01)
          err(DTR(" ... due to internal exception"));
        if (RSR & 0x10)
          err(DTR("... due to rest pin"));
        if (RSR & 0x20)
          err(DTR("... due to power on"));
        if (RSR & 0x1000)
          err(DTR("... due to watchdog"));

        if (m_sup_state == c_ss_exec)
          abort("Piccolo reset");

        m_sup_state = c_ss_insane;
        cnd(c_autopilot, false);
        cnd(c_telemetry, false);
        cnd(c_trk, false);
        reportState();
      }

      void
      onMain(void)
      {
        while (!stopping())
        {
          waitForMessages(1.0);
        }
      }

      void
      loiterAtCurrentPosition(void)
      {
        APWaypoint w;

        std::memset(&w, 0, sizeof(w));

        double lat = m_estate.lat;
        double lon = m_estate.lon;

        Coordinates::toWGS84(m_estate, lat, lon);

        w.Point.Lat = lat;
        w.Point.Lon = lon;
        w.Point.Alt = m_cfg.sw_alt;
        w.PreTurn = false;
        w.Slope = false;
        w.OrbitRadius = m_cfg.sw_radius;
        w.Direction = 1;
        w.Next = m_cfg.p_max;

        FormWaypointPacket(&m_pkt, &w, m_cfg.p_max);

        sendToAP(&m_pkt);
        trackWpt(m_cfg.p_max);
      }

      void
      trackWpt(uint8_t index)
      {
        m_pkt.Data[0] = index;
        m_pkt.Data[1] = 0;
        MakeAutopilotPacket(&m_pkt, TRACK, 2);
        sendToAP(&m_pkt);

        trace("tracking waypoint: %u", index);
      }

      void
      abort(const char* msg)
      {
        err("%s", msg);
        dispatch(m_abort);
      }
    };
  }
}

DUNE_TASK
