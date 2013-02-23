//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

#include "Piccolo.hpp"
#include "Translator.hpp"

namespace Piccolo
{
  using DUNE_NAMESPACES;

  struct Arguments
  {
    std::string conn_type;
    std::string uart_path;
    uint16_t uart_baud;
    Address tcp_server;
    uint16_t tcp_port;
    bool payload_stream;
    std::vector<std::string> modules;
    uint16_t port; // Server port
    bool enable_tracker;
    uint8_t plan_wpts;  // Startind index for plan waypoints.
    uint8_t hdvr_wpts;  // Startind index for handover waypoints.
    uint8_t max_clients;  // Maximum number of clients.
    bool gimbal_direct; // Route directly to gimbal.
  };

  struct Task: public DUNE::Tasks::Task
  {
    //! Arguments
    Arguments m_args;
    //! Translator
    Translator* m_transl;
    //! Parser
    PiccoloParser m_parser;
    //! Comms Buffer
    uint8_t m_buf[255];
    //! Link
    PiccoloLink* m_link;
    //! Bitfield of enabled control loops.
    uint32_t m_cloops;
    //! Piccolo Address resolver
    PiccoloAddresses m_addr;
    //! Last Latitude
    int32_t m_lat;
    //! Last Longitude
    int32_t m_lon;
    //! Last height
    int16_t m_height;
    //! Current Piccolo Waypoint
    uint8_t m_wp;
    //! Servos PWM
    uint16_t m_pwm[4];


    Task(const std::string& name, Tasks::Context& ctx):
      Tasks::Task(name, ctx),
      m_link(0),
      m_addr(ctx),
      m_lat(0),
      m_lon(0),
      m_height(0)
    {
      bind<IMC::ControlLoops>(this);
      bind<IMC::DesiredSpeed>(this);
      bind<IMC::DesiredZ>(this);
      bind<IMC::DesiredRoll>(this);
      bind<IMC::DesiredHeading>(this);
      bind<IMC::DesiredVerticalRate>(this);
      bind<IMC::DesiredPath>(this);
      bind<IMC::GpsFix>(this);
      bind<IMC::Parameter>(this);
      bind<IMC::SetServoPosition>(this);
      m_transl = new Translator(this);
      std::fill_n(m_pwm, 4, 0);

      // Retrieve configuration values.
      param("Enable Modules", m_args.modules)
      .defaultValue("")
      .description("AutoPilot, GroundStation, TASE and PayloadStream");

      param("Connection", m_args.conn_type)
      .defaultValue("Serial")
      .values("Serial, TCP")
      .description("Connection type");

      param("Serial Port - Path", m_args.uart_path)
      .defaultValue("/dev/ttyS1")
      .description("Serial Port device path");

      param("Serial Port - Baud Rate", m_args.uart_baud)
      .defaultValue("57600")
      .description("Serial Port baud rate");

      param("TCP Server - Host", m_args.tcp_server)
      .defaultValue("127.0.0.1")
      .description("Server address for TCP connections");

      param("TCP Server - Port", m_args.tcp_port)
      .defaultValue("2001")
      .description("Server address for TCP connections");

      param("Piccolo Tracker", m_args.enable_tracker)
      .defaultValue("false")
      .description("Enable Piccolo waypoint tracker");

      param("Plan Waypoints", m_args.plan_wpts)
      .description("Plan Waypoints starting index")
      .defaultValue("130");

      param("Handover Waypoints", m_args.hdvr_wpts)
      .description("Handover Waypoints starting index")
      .defaultValue("100");
    }

    ~Task(void)
    {
      Task::onResourceRelease();
    }

    void
    onResourceAcquisition(void)
    {
      connect();
    }

    void
    onResourceRelease(void)
    {
      Memory::clear(m_link);
    }

    void
    connect(void)
    {
      try
      {
        if (m_args.conn_type == "Serial")
        {
          inf(DTR("creating a serial connection | %s %u"), m_args.uart_path.c_str(), m_args.uart_baud);
          m_link = new PiccoloLink(m_args.uart_path, m_args.uart_baud);
        }
        else
        {
          inf(DTR("creating a TCP connection | %s %u"), m_args.tcp_server.c_str(), m_args.tcp_port);
          m_link = new PiccoloLink(m_args.tcp_server, m_args.tcp_port);
        }
        inf(DTR("Piccolo interface initialized"));

        //! Setup BW mode to maximum (25Hz)
        BandwidthMode* bw = new BandwidthMode;
        bw->setDestination(1);
        m_link->send(bw);
        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
      }
      catch(std::exception& e)
      {
        war("Connection failed, will try again");
        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_COM_ERROR);
      }
    }

    void
    info(uint32_t was, uint32_t is, uint32_t loop, const char* desc)
    {
      was &= loop;
      is &= loop;

      if (was && !is)
        war(DTR("%s - deactivating"), desc);
      else if (!was && is)
        war(DTR("%s - activating"), desc);
    }

    void
    consume(const IMC::ControlLoops* cloops)
    {
      if(!strcmp(getEntityLabel(),"Simulator"))
        return;

      uint32_t prev = m_cloops;

      if (cloops->enable)
      {
        m_cloops |= cloops->mask;
        if((!m_args.enable_tracker) && (cloops->mask & IMC::CL_PATH))
        {
          debug(DTR("tracker is NOT enabled"));
          m_cloops &= ~IMC::CL_PATH;
        }
      }
      else
        m_cloops &= ~cloops->mask;

      info(prev, m_cloops, IMC::CL_SPEED, DTR("speed control"));
      info(prev, m_cloops, IMC::CL_ALTITUDE, DTR("altitude control"));
      info(prev, m_cloops, IMC::CL_ROLL, DTR("bank control"));
      info(prev, m_cloops, IMC::CL_YAW, DTR("heading control"));
      info(prev, m_cloops, IMC::CL_VERTICAL_RATE, DTR("vertical rate control"));
      info(prev, m_cloops, IMC::CL_PATH, DTR("path control"));
    }

    void
    consume(const IMC::DesiredSpeed* ds)
    {
      if (!(m_cloops & IMC::CL_SPEED))
      {
        err(DTR("speed control is NOT active"));
        return;
      }

      trace("speed: %0.2f m/s", ds->value);

      AutopilotLoop* ap_loop = new AutopilotLoop;

      ap_loop->id = AutopilotLoop::LOOP_IAS;
      ap_loop->control = AutopilotLoop::LOOP_CTRL_ON;
      ap_loop->value = (float)ds->value;
      ap_loop->setDestination(m_addr.self());

      m_link->send(ap_loop);
    }

    void
    consume(const IMC::DesiredZ* da)
    {
      if (!(m_cloops & IMC::CL_ALTITUDE))
      {
        err(DTR("altitude control is NOT active"));
        return;
      }

      if (da->z_units != IMC::Z_ALTITUDE)
      {
        err(DTR("Not a valid altitude reference"));
        return;
      }

      trace("altitude: %0.2f m", da->value);

      AutopilotLoop* ap_loop = new AutopilotLoop;

      ap_loop->id = AutopilotLoop::LOOP_ALT;
      ap_loop->control = AutopilotLoop::LOOP_CTRL_ON;
      ap_loop->value = (float)da->value;
      ap_loop->setDestination(m_addr.self());

      m_link->send(ap_loop);
    }

    void
    consume(const IMC::DesiredRoll* dr)
    {
      if (!(m_cloops & IMC::CL_ROLL))
      {
        err(DTR("bank control is NOT active"));
        return;
      }

      trace("bank: %0.2f degrees", Angles::degrees(dr->value));

      AutopilotLoop* ap_loop = new AutopilotLoop;

      ap_loop->id = AutopilotLoop::LOOP_BANK;
      ap_loop->control = AutopilotLoop::LOOP_CTRL_ON;
      ap_loop->value = (float)dr->value;
      ap_loop->setDestination(m_addr.self());

      m_link->send(ap_loop);
    }

    void
    consume(const IMC::DesiredHeading* dh)
    {
      if (!(m_cloops & IMC::CL_YAW))
      {
        err(DTR("heading control is NOT active"));
        return;
      }

      double value = dh->value;

      if (value < 0)
        value += c_two_pi;

      trace("heading: %0.2f degrees", Angles::degrees(value));

      AutopilotLoop* ap_loop = new AutopilotLoop;

      ap_loop->id = AutopilotLoop::LOOP_HEAD;
      ap_loop->control = AutopilotLoop::LOOP_CTRL_ON;
      ap_loop->value = (float)value;
      ap_loop->setDestination(m_addr.self());

      m_link->send(ap_loop);
    }

    void
    consume(const IMC::DesiredVerticalRate* dvr)
    {
      if (!(m_cloops & IMC::CL_VERTICAL_RATE))
      {
        err(DTR("vertical rate control is NOT active"));
        return;
      }

      trace("vertical rate: %0.2f m/s", dvr->value);

      AutopilotLoop* ap_loop = new AutopilotLoop;

      ap_loop->id = AutopilotLoop::LOOP_VRATE;
      ap_loop->control = AutopilotLoop::LOOP_CTRL_ON;
      ap_loop->value = (float)dvr->value;
      ap_loop->setDestination(m_addr.self());

      m_link->send(ap_loop);
    }

    void
    consume(const IMC::DesiredPath* dpath)
    {
      if(!m_args.enable_tracker)
        return;

      if(!(m_cloops & IMC::CL_PATH))
      {
        err(DTR("path control is NOT active"));
        return;
      }

      Track* track = new Track;
      //! Start
      Waypoint* wp1 = new Waypoint;
      //! End
      Waypoint* wp2 = new Waypoint;
      //! Safety
      Waypoint* wp3 = new Waypoint;

      double bearing, range;
      double lat, lon, n, e;

      if(dpath->flags & DesiredPath::FL_START)
      {
        wp1->lat = (int32_t)(dpath->start_lat / marcs2rad);
        wp1->lon = (int32_t)(dpath->start_lon / marcs2rad);
        wp1->altitude = (int16_t)dpath->start_z;
        if(dpath->start_z_units == IMC::Z_ALTITUDE)
          wp1->flags2 |= Waypoint::WP2_AGL;
        WGS84::getNEBearingAndRange(dpath->start_lat, dpath->start_lon, dpath->end_lat, dpath->end_lon, &bearing, &range);
      }
      else
      {
        wp1->lat = m_lat;
        wp1->lon = m_lon;
        wp1->altitude = m_height;
        WGS84::getNEBearingAndRange((fp64_t)m_lat * marcs2rad, (fp64_t)m_lon * marcs2rad, dpath->end_lat, dpath->end_lon, &bearing, &range);
      }
      wp1->index = m_args.plan_wpts;
      wp1->next = m_args.plan_wpts + 1;
      wp1->setDestination(m_addr.self());
      m_link->send(wp1);

      wp2->lat = (int32_t)(dpath->end_lat / marcs2rad);
      wp2->lon = (int32_t)(dpath->end_lon / marcs2rad);
      wp2->altitude = (int16_t)dpath->end_z;
      if(dpath->end_z_units == IMC::Z_ALTITUDE)
        wp2->flags2 |= Waypoint::WP2_AGL;
      if(dpath->lradius < 0)
        wp2->radius = 0;
      else
        wp2->radius = (uint8_t)(dpath->lradius / 10);
      wp2->index = m_args.plan_wpts + 1;
      wp2->next = m_args.plan_wpts + 2;
      wp2->setDestination(m_addr.self());
      m_link->send(wp2);


      n = std::cos(bearing) * 200.0;
      e = std::sin(bearing) * 200.0;

      lat = dpath->end_lat;
      lon = dpath->end_lon;

      WGS84::displace(n, e, &lat, &lon);

      wp3->lat = (int32_t)(lat / marcs2rad);
      wp3->lon = (int32_t)(lon / marcs2rad);
      wp3->altitude = (int16_t)dpath->end_z;
      if(dpath->end_z_units == IMC::Z_ALTITUDE)
        wp3->flags2 |= Waypoint::WP2_AGL;
      wp3->radius = 15;
      wp3->index = m_args.plan_wpts + 2;
      wp3->next = m_args.plan_wpts + 2;
      wp3->setDestination(m_addr.self());
      m_link->send(wp3);

      track->target = m_args.plan_wpts + 1;
      track->track_goto = 0;
      track->setDestination(m_addr.self());
      m_link->send(track);
    }

    void
    consume(const IMC::GpsFix* gps_fix)
    {
      m_lat = (int32_t)(gps_fix->lat / marcs2rad);
      m_lon = (int32_t)(gps_fix->lon / marcs2rad);
      m_height = (int16_t)(gps_fix->height);
    }

    void
    consume(const IMC::Parameter* par)
    {
      if(!par->param.compare("curr_waypoint"))
      {
        m_wp = par->getDestinationEntity();

        if(m_wp < m_args.hdvr_wpts)
          setEntityState(IMC::EntityState::ESTA_ERROR, "External Control");
      }
    }

    void
    consume(const IMC::SetServoPosition* servo)
    {
      switch(servo->id)
      {
        case 1:
          m_pwm[0] = (uint16_t)servo->value;
          break;
        case 2:
          m_pwm[1] = (uint16_t)servo->value;
          break;
        case 3:
          m_pwm[2] = (uint16_t)servo->value;
          break;
        case 4:
          m_pwm[3] = (uint16_t)servo->value;
          break;
      }

      PilotCommandPulse* pcp = new PilotCommandPulse;

      pcp->aileron = m_pwm[0];
      pcp->elevator = m_pwm[1];
      pcp->throttle = m_pwm[2];
      pcp->rudder = m_pwm[3];
      pcp->ignition = 1;
      pcp->manual = 1;

      pcp->setDestination(m_addr.self());
      m_link->send(pcp);
    }


    void
    handlePiccoloData(void)
    {
      if(!m_link->poll(1.0))
        return;

      int n = m_link->receive(m_buf);

      for(int i = 0; i < n; ++i)
      {
        if(m_parser.parse(m_buf[i]))
        {
          PiccoloMessage* m = m_parser.getPacket().deserializeData();
          if(m)
          {
            if(m->getId() == 837)
            {
              TelemetryHighRes* tlm;
              tlm = (TelemetryHighRes*) m;
              m_transl->translate(tlm, (bool)!strcmp(getEntityLabel(),"Simulator"));
            }
            if(m->getId() == 1031)
            {
              GroundStationTelemetry* gtlm;
              gtlm = (GroundStationTelemetry*) m;
              m_transl->translate(gtlm);
            }
            if(m->getId() == 839)
            {
              SystemStatusHighRes* systatus;
              systatus = (SystemStatusHighRes*) m;
              m_transl->translate(systatus);
            }
          }
        }
      }
    }

    void
    onMain(void)
    {
      while(!stopping())
      {
        // Handle IMC messages from bus
        consumeMessages();

        // Handle Piccolo messages
        if(m_link)
        {
          handlePiccoloData();
        }
        else
        {
          Time::Delay::wait(1.0);
          connect();
        }
      }
    }
  };
}

DUNE_TASK
