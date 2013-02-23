//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joel Cardoso                                                     *
// Author: Eduardo Marques                                                  *
//***************************************************************************
// $Id:: Task.cpp 12695 2013-01-23 22:54:41Z rasm                         $:*
//***************************************************************************

// ISO C++ 98 headers.
#include <map>

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Actuators
{
  namespace TASE
  {
    using DUNE_NAMESPACES;
    using namespace DUNE::Piccolo;

    struct Arguments
    {
      bool direct_access;
      std::string uart_device;
      uint16_t uart_brate;
      bool gateway;
    };

    struct Task: public DUNE::Tasks::Task
    {
      //! Configuration parameters.
      Arguments m_args;
      //! Serial port handle (if access is direct).
      SerialPort* m_uart;
      //! IMC datum (if access is not direct).
      IMC::PiccoloPacket m_imc_pkt;
      IMC::EulerAngles m_euler;
      GimbalPacket m_gpkt_in, m_gpkt_out;
      Piccolo::Addresses m_addrs;

      typedef void (Task::* PacketHandler)(const GimbalPacket*);
      typedef std::map<uint16_t, PacketHandler> PHMap;
      PHMap m_ph;

      enum State
      {
        c_state_timeout,
        c_state_ok,
        c_num_states
      };

      enum Zoom
      {
        ZOOM_IN = 1,
        ZOOM_OUT = -1,
        ZOOM_STOP = 0
      };

      enum Focus
      {
        FOCUS_IN = 1,
        FOCUS_OUT = -1,
        FOCUS_STOP = 0
      };

      static const int c_data_timeout = 5;

      double m_rxtime;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx),
        m_uart(NULL),
        m_addrs(ctx)
      {
        param("Direct Gimbal Access", m_args.direct_access)
        .defaultValue("true")
        .description("Access TASE gimbal hardware directly");

        param("Serial Port - Device", m_args.uart_device)
        .defaultValue("/tty/S0")
        .description("Serial port device (if direct gimbal access is enabled");

        param("Serial Port - Baud Rate", m_args.uart_brate)
        .defaultValue("9600")
        .description("Serial port baud rate (if direct gimbal access is enabled");

        param("Gateway Mode", m_args.gateway)
        .defaultValue("false")
        .description("Enable gateway mode (direct access must be enabled)");

        bind<IMC::CameraZoom>(this);
        bind<IMC::RemoteActions>(this);

        // Setup handlers for Gimbal packets
        setHandler(GIMBAL_POSITION_INFORMATION_GROUP,
                   GEOREFERENCE_DATA_GIMBAL_PKTTYPE,
                   &Task::onGeoReferencePacket);

        setHandler(GIMBAL_SETUP_GROUP,
                   SYSTEM_VERSION_GIMBAL_PKTTYPE,
                   &Task::onVersionPacket);
      }

      inline void
      setHandler(uint8_t group, uint8_t type, PacketHandler h)
      {
        m_ph[(group << 8) | type] = h;
      }

      void
      onResourceAcquisition(void)
      {
        if (!m_args.direct_access)
          m_args.gateway = false;  // override to false in case it's mistakingly true

        if (m_args.direct_access)
          m_uart = new SerialPort(m_args.uart_device, m_args.uart_brate);

#if BROKEN
        if (!m_args.direct_access || m_args.gateway)
          bind<Task, IMC::PiccoloPacket>(*this, c_q_gimbal_processor);
#endif

        std::memset(&m_gpkt_in, 0, sizeof(m_gpkt_in));
        m_rxtime = 0;
      }

      void
      onResourceRelease(void)
      {
        if (m_args.direct_access && m_uart != NULL)
        {
          delete m_uart;
          m_uart = NULL;
        }
      }

      void
      handleIncomingData(const uint8_t* p, int n)
      {
        for (const uint8_t* e = p + n; e != p; ++p)
        {
          if (LookForGimbalPacketInByte(&m_gpkt_in, *p))
          {
            trace("IN | %s", name(&m_gpkt_in));

            PHMap::iterator itr = m_ph.find((m_gpkt_in.Group << 8) | m_gpkt_in.PktType);
            m_rxtime = Clock::get();

            if (itr != m_ph.end())
              (this->*(itr->second))(&m_gpkt_in);

            if (m_args.gateway)
            {
              sendToBus(&m_gpkt_in, c_q_gateway);
            }
          }
        }
      }

      void
      sendPacket(void)
      {
        trace("OUT | %s", name(&m_gpkt_out));

        const char* data = (const char*)&m_gpkt_out;
        int len = Piccolo::size(&m_gpkt_out);

        if (m_args.direct_access)
        {
          m_uart->write((const char*)data, len);
        }
        else
        {
          sendToBus(&m_gpkt_out, c_q_connection);
        }
      }

      void
      sendToBus(const GimbalPacket* gpkt, int qualification)
      {
        const uint8_t* p = gpkt->Data;
        const uint8_t* e = p + gpkt->Size;

        m_imc_pkt.id = c_q_gimbal_processor;
        m_imc_pkt.setTimeStamp();

        do
        {
          int n = std::min(e - p, MAX_STREAM_DATA_SIZE);
          makeStreamPacket(p, n, m_addrs.self(), GIMBAL_STREAM, &m_imc_pkt);
          p += n;
#if BROKEN
          bus().dispatch(&m_imc_pkt, this, qualification);
#endif
        }
        while (p != e);
      }

      void
      onMain(void)
      {
        uint8_t buf[1024];

        if (!m_args.direct_access)
        {
          m_imc_pkt.id = Piccolo::c_q_gimbal_processor_active;
          m_imc_pkt.setTimeStamp();
#if BROKEN
          bus().dispatch(&m_imc_pkt, this, Piccolo::c_q_connection);
#endif
        }

        // Request version info
        MakeGimbalPacket(&m_gpkt_out, GIMBAL_SETUP_GROUP, SYSTEM_VERSION_GIMBAL_PKTTYPE, 0, 0);
        sendPacket();

        while (!stopping())
        {
          if (!m_args.direct_access)
          {
            waitForMessages(1.0);
          }
          else
          {
            consumeMessages();

            if (m_uart->hasNewData(0.005) == IOMultiplexing::PRES_OK)
            {
              int n = m_uart->read(buf, sizeof(buf));

              if (n > 0)
                handleIncomingData(buf, n);
            }
          }
        }
      }

      void
      onReportEntityState(void)
      {
        if (Clock::get() - m_rxtime > c_data_timeout)
          setEntityState(IMC::EntityState::ESTA_ERROR, DTR("no gimbal data"));
        else
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
      }

      void
      consume(const IMC::CameraZoom* cz)
      {
        switch (cz->action)
        {
          case IMC::CameraZoom::ACTION_ZOOM_IN:
            inf(DTR("zoom_in"));
            cameraZoom(ZOOM_IN, 1);
            break;
          case IMC::CameraZoom::ACTION_ZOOM_OUT:
            inf(DTR("zoom_out"));
            cameraZoom(ZOOM_OUT, 1);
            break;
          case IMC::CameraZoom::ACTION_ZOOM_STOP:
            inf(DTR("zoom_stop"));
            cameraZoom(ZOOM_STOP, 1);
            break;
        }
      }

      void
      consume(const IMC::RemoteActions* ra)
      {
        TupleList tuples(ra->actions);
        // For Gimbal Command Packet (0x80)
        float pan = tuples.get("Pan", 0.00f);
        float tilt = tuples.get("Tilt", 0.00f);
        int8_t zoom = tuples.get("Zoom", 0);
        float zoom_tout = tuples.get("Zoom_tout", 0.00f);
        int8_t gimbal_flags = tuples.get("Gimbal_flag", 0);
        float impulse_tout = tuples.get("Impulse_tout", 0.00f);
        // For Camera Command Packet (0x41)
        uint8_t camera = tuples.get("Camera", 0);
        float hfov = tuples.get("HFOV", 0.00f);
        uint16_t focus = tuples.get("Focus", 0);
        uint8_t exposure = tuples.get("Exposure", 0);
        uint8_t shutter_speed = tuples.get("Shutter_speed", 0);
        uint8_t bright = tuples.get("Bright", 0);
        uint8_t camera_flags = tuples.get("Camera_flag", 0);

        // For Gimbal Command Packet (0x80)
        trace("Pan %0.2f", pan);
        trace("Tilt %0.2f", tilt);
        trace("Zoom %d", zoom);
        trace("Zoom Timeout %0.2f", zoom_tout);
        trace("Focus %d", focus);
        trace("Gimbal Flags %d", gimbal_flags);
        trace("Impulse Timeout %0.2f", impulse_tout);
        // For Camera Command Packet (0x41)
        trace("Camera %d", camera);
        trace("HFOV %0.2f", hfov);
        trace("Focus %d", focus);
        trace("Exposure %d", exposure);
        trace("Shutter Speed %d", shutter_speed);
        trace("Bright %d", bright);
        trace("Camera Flags %d", camera_flags);

        gimbalCmd(pan, tilt, zoom, zoom_tout, gimbal_flags, impulse_tout);
        cameraCmd(camera, hfov, focus, exposure, shutter_speed, bright, camera_flags);
      }

      void
      consume(const IMC::PiccoloPacket* pkt)
      {
        const StreamPacket* spkt = Piccolo::streamPkt(pkt);

        if (m_args.gateway)
        {
          // Stream format
          m_uart->write(spkt->Data, spkt->Size);
          trace("OUT (GW) | %s", name((const GimbalPacket*)spkt->Data));
        }
        else
        {
          // Data was read from Piccolo link
          handleIncomingData(spkt->Data, spkt->Size);
        }
      }

      // Gimbal command packet
      void
      gimbalCmd(float pan, float tilt, int8_t zoom, float zoom_tout, uint8_t gimbal_flags, float impulse_tout)
      {
        FormGimbalCmdPacket(&m_gpkt_out, pan, tilt, zoom, zoom_tout, gimbal_flags, impulse_tout, 0);
        sendPacket();
      }

      // Camera command packet
      void
      cameraCmd(uint8_t camera, float hfov, uint16_t focus, uint8_t exposure, uint8_t shutter_speed, uint8_t bright, uint8_t camera_flags)
      {
        FormGimbalCameraCmdPacket(&m_gpkt_out, camera, hfov, focus, exposure, shutter_speed, bright, camera_flags);
        sendPacket();
      }

      // Continuous rate focus command with timeout
      void
      cameraFocus(Focus focus, uint8_t cmr_id)
      {
        int focus_rate = 0;
        float focus_tout = 1;
        switch (focus)
        {
          case 1:
            inf(DTR("focus_in"));
            focus_rate = 8;
            break;
          case -1:
            inf(DTR("focus_out"));
            focus_rate = -8;
            break;
          case 0:
            inf(DTR("focus_stop"));
            focus_rate = 0;
            break;
        }
        FormGimbalCameraFocusPacket(&m_gpkt_out, cmr_id, focus_rate, focus_tout);
        sendPacket();
      }

      // Continuous rate zoom command with timeout
      void
      cameraZoom(Zoom zoom, uint8_t cmr_id)
      {
        int8_t zoom_rate = 0;
        float zoom_tout = 0.5;
        switch (zoom)
        {
          case 1:
            inf(DTR("zoom_in"));
            zoom_rate = 8;
            break;
          case -1:
            inf(DTR("zoom_out"));
            zoom_rate = -8;
            break;
          case 0:
            inf(DTR("zoom_stop"));
            zoom_rate = 0;
            break;
        }
        FormGimbalCameraZoomPacket(&m_gpkt_out, cmr_id, zoom_rate, zoom_tout);
        sendPacket();
      }

      // Given a camera type print out its name.
      // param cmr_type is the type of camera to print.
      /*void
        cameraType(UInt8 cmr_type)
        {
        switch(cmr_type)
        {
        case CAMERA_TYPE_NO_CAMERA:     inf(DTR("No camera")); break;
        case CAMERA_TYPE_DUMB_CAMERA:   inf(DTR("Dumb camera")); break;
        case CAMERA_TYPE_SONY:          inf(DTR("Sony block camera")); break;
        case CAMERA_TYPE_PHOTON:        inf(DTR("FLIR Photon LWIR camera")); break;
        case CAMERA_TYPE_TAU:           inf(DTR("FLIR Tau LWIR camera")); break;
        case CAMERA_TYPE_HRC:           inf(DTR("FLIR HRC MWIR camera")); break;
        case CAMERA_TYPE_THERMO:        inf(DTR("Thermoteknix LWIR camera")); break;
        case CAMERA_TYPE_PROSILICA:     inf(DTR("Prosilica camera")); break;
        case CAMERA_TYPE_320_KTX:       inf(DTR("Sensors unlimited SWIR 320 camera")); break;
        case CAMERA_TYPE_640_KTX:       inf(DTR("Sensors unlimited SWIR 640 camera")); break;
        default:                        inf(DTR("Unknown type or no camera")); break;
        }
        }*/

      void
      onGeoReferencePacket(const GimbalPkt_t* pkt)
      {
        GimbalTelemetryData_t data;

        if (!DecodeGimbalGeoreferencePacketNew(pkt, &data))
        {
          err(DTR("error decoding gimbal georeference packet"));
          return;
        }
        // report in IMC
        m_euler.phi = data.CameraAttitude[ROLL_AXIS];
        m_euler.theta = data.CameraAttitude[PITCH_AXIS];
        m_euler.psi = data.CameraAttitude[YAW_AXIS];
        inf("%0.2f %0.2f %0.2f", Angles::degrees(m_euler.phi),
            Angles::degrees(m_euler.theta), Angles::degrees(m_euler.psi));

        dispatch(m_euler);
      }

      void
      onVersionPacket(const GimbalPkt_t* pkt)
      {
        Version_t v;
        Board_t b;
        uint8_t cameras[3];
        float maxHFOV[3];
        float minHFOV[3];

        if (!DecodeGimbalVersionPacket(pkt, &v, &b, cameras, maxHFOV, minHFOV))
        {
          err(DTR("error decoding gimbal version packet"));
          return;
        }

        inf(DTR("software version %d.%d.%d patch %d %4d-%02d-%02d"),
            (int)v.MajorVersion,
            (int)v.MinorVersion,
            (int)v.SubVersion,
            (int)v.PatchNum,
            (int)v.Date.year,
            (int)v.Date.month,
            (int)v.Date.day);

        inf(DTR("hardware board - SN %0u FN %u rev %u config %u %u-%02u-%02u"),
            b.SerialNumber,
            b.FeatureCode,
            b.Rev,
            (unsigned)b.Config,
            b.Date.year,
            b.Date.month,
            b.Date.day);

        for (int i = 0; i != 3; ++i)
        {
          inf(DTR("camera %d -- id: %u HFOV: [%0.2f, %0.2f]"),
              i, cameras[i], minHFOV[i], maxHFOV[i]);
          //cameraType(cameras[i]);
        }
      }
    };
  }
}

DUNE_TASK
