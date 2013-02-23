//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************
// $Id:: Task.cpp 12667 2013-01-22 02:44:42Z rasm                         $:*
//***************************************************************************

// ISO C++ 98 headers.
#include <cmath>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Control
{
  namespace UAV
  {
    namespace Piccolo
    {
      namespace Tracker
      {
        using DUNE_NAMESPACES;
        using namespace DUNE::Piccolo;

        const double c_wahead_offset = 500;
        const double c_wahead_radius = 250;

        struct Task: public DUNE::Control::PathController
        {
          APPacket m_pkt;
          IMC::PiccoloPacket m_imc_pkt;
          uint8_t m_wmin, m_wmax;

          Task(const std::string& name, Tasks::Context& ctx):
            DUNE::Control::PathController(name, ctx)
          {
            bind<IMC::PiccoloControlConfiguration>(this);
          }

          ~Task(void)
          { }

          bool hasSpecificZControl(void) const
          {
            // Task will override base class handling of altitude and depth
            // meaning altitude control will be waypoint-based strictly
            // (but still allowing PCC operator interference in that regard)
            return true;
          }

          void
          consume(const IMC::PiccoloControlConfiguration* cfg)
          {
            m_wmin = cfg->p_min;
            m_wmax = cfg->p_max - 1;
          }

          void
          onUpdateParameters(void)
          {
            PathController::onUpdateParameters();
          }

          void
          onActivation(void)
          { }

          void
          onDeactivation(void)
          { }

          void
          onPathStartup(const IMC::EstimatedState& state, const TrackingState& ts)
          {
            // >> Define waypoint indexes. <<
            uint8_t w1 = m_wmin, w2 = w1 + 1, w3 = w1 + 2;

            // >> Initiate block waypoint transfer. <<
            APWaypointMask mask;
            std::memset(mask, 0, sizeof(mask));
            SetFPMaskBit(mask, w1);
            SetFPMaskBit(mask, w2);
            SetFPMaskBit(mask, w3);
            // Note: 3 below refers to the operation, not the number of waypoints.
            FormWaypointListPacket(&m_pkt, mask, 3);
            sendPacket();

            // >> Define and send the waypoints. <<
            double alt = ts.end.z;
            sendWpt(w1, w2, state, ts.start, alt);
            sendWpt(w2, w3, state, ts.end, alt);

            TrackingState::Coord w3c;
            double r;
            bool c;

            if (ts.loiter.radius > 0)
            {
              w3c = ts.loiter.center;
              r = ts.loiter.radius;
              c = ts.loiter.clockwise;
            }
            else
            {
              setBearingAndRange(ts.start, ts.track_bearing, ts.track_length + c_wahead_offset, w3c);
              w3c.z = ts.end.z;
              r = c_wahead_radius;
              c = true;
            }

            sendWpt(w3, w3, state, w3c, alt, r, c);

            // >> Send track comand. <<
            track(w2);
          }

          void
          sendWpt(uint8_t index, uint8_t next, const IMC::EstimatedState& ref,
                  const TrackingState::Coord& coord, double alt,double radius = -1,
                  bool clockwise = false)
          {
            double lat = ref.lat;
            double lon = ref.lon;

            WGS84::displace(coord.x, coord.y, &lat, &lon);

            APWaypoint w;
            std::memset(&w, 0, sizeof(w));
            w.Point.Lat = lat;
            w.Point.Lon = lon;
            w.Point.Alt = alt;
            w.PreTurn = false;
            w.Slope = false;
            w.OrbitRadius = radius > 0 ? radius : 0;
            w.OrbitTime = 0;
            w.Direction = clockwise ? 1 : 0;
            w.Next = next;

            FormWaypointPacket(&m_pkt, &w, index);

            trace("sending waypoint --"
                      " index: %d"
                      " next: %d"
                      " lat: %0.6f"
                      " lon: %0.6f"
                      " (x,y): %0.2f %0.2f"
                      " alt: %0.2f"
                      " orb. radius: %0.2f"
                      " orb. clockwise: %d",
                  index, w.Next,
                  Angles::degrees(w.Point.Lat),
                  Angles::degrees(w.Point.Lon),
                  coord.x, coord.y,
                  w.Point.Alt,
                  w.OrbitRadius,
                  w.Direction);

            sendPacket();
          }

          void
          track(uint8_t index)
          {
            m_pkt.Data[0] = index;
            m_pkt.Data[1] = 0;
            MakeAutopilotPacket(&m_pkt, TRACK, 2);

            trace("track request: %u", index);
            sendPacket();
          }

          void
          sendPacket(void)
          {
            trace("AP packet out: %s", name(&m_pkt, false));

            m_imc_pkt.id = qAP(m_pkt.PktType);
            m_imc_pkt.setTimeStamp();
            copy(&m_pkt, &m_imc_pkt);
#if BROKEN
            bus().dispatch(&m_imc_pkt, this, c_q_connection);
#endif
          }

          void
          step(const IMC::EstimatedState& state, const TrackingState& ts)
          {
            // Do nothing.
            // All necessary Piccolo commands are sent by onPathStartup() method above.
            (void)state;
            (void)ts;
          }

          void
          loiter(const IMC::EstimatedState& state, const TrackingState& ts)
          {
            // Do nothing.
            // All necessary Piccolo commands are sent by onPathStartup() method above.
            // This function is defined so that default loitering strategy
            // as defined by PathController::loiter() is not executed.
            (void)state;
            (void)ts;
          }
        };
      }
    }
  }
}

DUNE_TASK
