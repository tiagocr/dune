//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************

// ISO C++ 98 headers.
#include <string>

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace Sensors
{
  namespace NavQuestDVL
  {
    using DUNE_NAMESPACES;

    // Setup commands in order with corresponding error message if the
    // command fails.
    static const char* c_setup_cmds[] =
    {
      "#&!LQNQ.COMD2929 1\r\n", "1\r\n", DTR("failed to set continous mode"),
      "#&!LQNQ.COMD1010 1\r\n", "1\r\n", DTR("failed to set transducer face orientation"),
      "#&!LQNQ.COMD0101 0.00\r\n", "0.00\r\n", DTR("failed to set sampling frequency")
    };

    struct Arguments
    {
      //! Serial port device.
      std::string uart_dev;
      //! Serial port baud rate.
      unsigned uart_baud;
      //! Default Sound speed on water.
      double sound_speed_def;
      //! Entity label of sound speed provider.
      std::string sound_speed_elabel;
      //! DVL position.
      std::vector<float> position;
      //! DVL orientation.
      std::vector<float> orientation;
    };

    //! Number of altitude measurements.
    static const unsigned c_altitude_count = 5;
    //! Transducer beam angle.
    static const float c_transducer_angle = 22.0;
    //! Transducer beam offset.
    static const float c_transducer_offset = 0.035;

    struct Task: public DUNE::Tasks::Task
    {
      // Serial port handle.
      SerialPort* m_uart;
      // Ground velocity message.
      IMC::GroundVelocity m_gvel;
      // Water velocity message.
      IMC::WaterVelocity m_wvel;
      // Altitudes.
      IMC::Distance m_altitude[c_altitude_count];
      // Raw messages.
      IMC::DevDataBinary m_raw_data;
      // True if data sampling is enabled.
      bool m_active;
      // Valid ground velocity
      uint8_t m_gvel_valid_flag;
      // Valid water velocity
      uint8_t m_wvel_valid_flag;
      // Task arguments.
      Arguments m_args;
      //! Last sound speed value.
      double m_sound_speed;
      //! Sound speed entity id.
      int m_sound_speed_eid;

      Task(const std::string& name, Tasks::Context& ctx):
        Tasks::Task(name, ctx),
        m_uart(NULL),
        m_active(false),
        m_sound_speed(0),
        m_sound_speed_eid(-1)
      {
        param("Serial Port - Device", m_args.uart_dev)
        .defaultValue("")
        .description("Serial port device used to communicate with the sensor");

        param("Serial Port - Baud Rate", m_args.uart_baud)
        .defaultValue("115200")
        .description("Serial port baud rate");

        param("Sound Speed - Default Value", m_args.sound_speed_def)
        .units(Units::MeterPerSecond)
        .defaultValue("1500");

        param("Sound Speed - Entity Label", m_args.sound_speed_elabel)
        .description("Entity label of sound speed provider");

        param("Device Position", m_args.position)
        .defaultValue("0.55, 0, 0.12")
        .size(3)
        .description("Device position relative to navigation estimation (relative to GPS sensor)");

        param("Device Orientation", m_args.orientation)
        .defaultValue("0, -90, 0")
        .size(3)
        .description("Device orientation");

        m_gvel_valid_flag = (IMC::GroundVelocity::VAL_VEL_X | IMC::GroundVelocity::VAL_VEL_Y | IMC::GroundVelocity::VAL_VEL_Z);
        m_wvel_valid_flag = (IMC::WaterVelocity::VAL_VEL_X | IMC::WaterVelocity::VAL_VEL_Y | IMC::WaterVelocity::VAL_VEL_Z);

        // Register consumers.
        bind<IMC::EntityControl>(this);
        bind<IMC::SoundSpeed>(this);
      }

      ~Task(void)
      {
        Task::onResourceRelease();
      }

      void
      onUpdateParameters(void)
      {
        m_args.sound_speed_def = Math::round(m_args.sound_speed_def);
        m_sound_speed = m_args.sound_speed_def;

        IMC::BeamConfig bc;
        bc.beam_width = -1;
        bc.beam_height = -1;

        IMC::DeviceState ds;
        ds.z = m_args.position[2];
        ds.psi = Math::Angles::radians(m_args.orientation[2]);

        for (unsigned i = 0; i < 5; i++)
        {
          m_altitude[i].location.clear();
          m_altitude[i].beam_config.clear();
          m_altitude[i].beam_config.push_back(bc);
        }

        // Beam 1.
        ds.x = m_args.position[0] + c_transducer_offset;
        ds.y = m_args.position[1];
        ds.phi = Math::Angles::radians(m_args.orientation[0]);
        ds.theta = Math::Angles::radians(m_args.orientation[1]) + c_transducer_angle;
        m_altitude[0].location.push_back(ds);

        // Beam 2.
        ds.x = m_args.position[0];
        ds.y = m_args.position[1] + c_transducer_offset;
        ds.phi = Math::Angles::radians(m_args.orientation[0]) - c_transducer_angle;
        ds.theta = Math::Angles::radians(m_args.orientation[1]);
        m_altitude[1].location.push_back(ds);

        // Beam 3.
        ds.x = m_args.position[0] - c_transducer_offset;
        ds.y = m_args.position[1];
        ds.phi = Math::Angles::radians(m_args.orientation[0]);
        ds.theta = Math::Angles::radians(m_args.orientation[1]) - c_transducer_angle;
        m_altitude[2].location.push_back(ds);

        // Beam 4.
        ds.x = m_args.position[0];
        ds.y = m_args.position[1] - c_transducer_offset;
        ds.phi = Math::Angles::radians(m_args.orientation[0]) + c_transducer_angle;
        ds.theta = Math::Angles::radians(m_args.orientation[1]);
        m_altitude[3].location.push_back(ds);

        // Estimated Altitude.
        ds.x = m_args.position[0];
        ds.y = m_args.position[1];
        ds.phi = Math::Angles::radians(m_args.orientation[0]);
        ds.theta = Math::Angles::radians(m_args.orientation[1]);
        m_altitude[4].location.push_back(ds);

      }

      void
      onResourceAcquisition(void)
      {
        m_uart = new SerialPort(m_args.uart_dev, m_args.uart_baud);
      }

      void
      onResourceDeactivation(void)
      {
        stopSampling();
      }

      void
      onResourceInitialization(void)
      {
        m_uart->setCanonicalInput(true);

        char bfr[64];

        // NQ1 output format.
        std::string fmt_code = "01";

        // Request current output formats.
        if (sendReadData("#&!LQNQ.COMD0606\r\n", bfr, 64) == false)
          throw std::runtime_error(DTR("failed to request current output formats"));

        std::vector<std::string> fmts;
        String::split(bfr, " ", fmts);

        bool got_fmt = false;
        for (unsigned i = 0; i < fmts.size(); ++i)
        {
          if (fmts[i] != fmt_code)
          {
            std::string cmd = String::str("#&!LQNQ.COMD1616 %s\r\n", fmts[i].c_str());
            if (sendReadData(cmd.c_str(), bfr, 64) == false)
              throw std::runtime_error(DTR("failed to request current output formats"));
          }
          else
          {
            got_fmt = true;
          }
        }

        if (!got_fmt)
        {
          std::string cmd = String::str("#&!LQNQ.COMD0505 %s\r\n", fmt_code.c_str());
          std::string rpl = String::str("%s\r\n", fmt_code.c_str());
          if (!sendCommand(cmd.c_str(), rpl.c_str()))
            throw std::runtime_error(DTR("failed to configure output format"));
        }

        // Send setup commands.
        unsigned cmd_count = sizeof(c_setup_cmds) / sizeof(char*);

        for (unsigned i = 0; i < cmd_count; i += 3)
        {
          if (!sendCommand(c_setup_cmds[i], c_setup_cmds[i + 1]))
            throw std::runtime_error(c_setup_cmds[i + 2]);
        }

        setSoundSpeed(m_args.sound_speed_def);

        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
      }

      void
      onResourceRelease(void)
      {
        if (m_uart != NULL)
        {
          onResourceDeactivation();
          delete m_uart;
          m_uart = NULL;
        }
      }

      void
      consume(const IMC::EntityControl* msg)
      {
        if (msg->getDestinationEntity() != getEntityId())
          return;

        m_active = (msg->op == IMC::EntityControl::ECO_ACTIVATE);

        if (m_active)
          startSampling();
        else
          stopSampling();
      }

      void
      consume(const IMC::SoundSpeed* msg)
      {
        if ((int)msg->getSourceEntity() != m_sound_speed_eid)
          return;

        if (msg->value < 0)
          return;

        m_sound_speed = msg->value;
      }

      bool
      sendCommand(const char* cmd, const char* response, double timeout = 1.0)
      {
        debug("sending %s", sanitize(cmd).c_str());

        m_uart->write(cmd);

        char bfr[128] = {0};
        int retries = (int)(timeout / 0.01);

        while (retries--)
        {
          if (m_uart->hasNewData(0.01) == IOMultiplexing::PRES_OK)
          {
            m_uart->readString(bfr, 128);
            debug("reading %s", sanitize(bfr).c_str());

            if (std::strcmp(bfr, response) == 0)
              return true;
          }
        }

        return false;
      }

      bool
      sendReadData(const char* cmd, char* response, int resplen, double timeout = 1.0)
      {
        m_uart->write(cmd);

        int retries = (int)(timeout / 0.01);

        while (retries--)
        {
          if (m_uart->hasNewData(0.01) == IOMultiplexing::PRES_OK)
          {
            if (m_uart->readString(response, resplen) > 0)
              return true;
          }
        }
        return false;
      }

      void
      onEntityReservation(void)
      {
        m_altitude[0].setSourceEntity(reserveEntity("DVL Beam 0"));
        m_altitude[1].setSourceEntity(reserveEntity("DVL Beam 1"));
        m_altitude[2].setSourceEntity(reserveEntity("DVL Beam 2"));
        m_altitude[3].setSourceEntity(reserveEntity("DVL Beam 3"));
      }

      void
      onEntityResolution(void)
      {
        try
        {
          m_sound_speed_eid = resolveEntity(m_args.sound_speed_elabel);
        }
        catch (...)
        {
          inf(DTR("dynamic sound speed corrections are disabled"));
          m_sound_speed = m_args.sound_speed_def;
        }
      }

      void
      startSampling(void)
      {
        if (!sendCommand("#&!LQNQ.COMD2525\r\n", "AUTO_VEL_ON \r\n"))
          throw RestartNeeded(DTR("failed to start data sampling"), 5);
      }

      void
      stopSampling(void)
      {
        m_uart->flush();

        m_uart->write("#&!LQNQ.COMD2828\r\n");
        Delay::wait(0.25);
        m_uart->flush();

        if (!sendCommand("#&!LQNQ.COMD2828\r\n", "AUTO_VEL_OFF\r\n"))
          throw std::runtime_error(DTR("failed to stop data sampling"));
      }

      void
      setSoundSpeed(double value)
      {
        if (!sendCommand("#&!LQNQ.COMD6565 1\r\n", "1\r\n"))
          throw RestartNeeded(DTR("failed to enable user-defined sound speed"), 5);

        unsigned sound_speed = static_cast<unsigned>(value);
        std::string command = String::str("#&!LQNQ.COMD5555 %u\r\n", sound_speed);
        std::string reply = String::str("%u\r\n", sound_speed);

        if (!sendCommand(command.c_str(), reply.c_str()))
          throw RestartNeeded(DTR("failed to set initial sound speed"), 5);
      }

      template <typename T>
      void
      correctSoundSpeed(T& var)
      {
        var = (var * m_sound_speed) / m_args.sound_speed_def;
      }

      void
      readNQ1(void)
      {
        char bfr[256];
        int rv = m_uart->readString(bfr, 256);

        if (rv <= 0)
          setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_COM_ERROR);

        m_raw_data.value.assign(bfr, bfr + rv);
        dispatch(m_raw_data);
        debug("data %s\n", sanitize(bfr).c_str());

        // 0 - header
        // 1 - error code
        // 2, 3, 4, 5 - good_or_bad
        // 6, 7, 8, 9 - v_altitude
        // 10, 11, 12, 13 - velo_rad
        // 14, 15, 16, 17 - wvelo_rad
        // 18, 19, 20, 21 - wvelo_credit
        // 22, 23, 24 - velo_instrument
        // 25 - velo_instrument_flag
        // 26, 27, 28 - velo_earth
        // 29 - velo_earth_flag
        // 30, 31, 32 - water_velo_instrument
        // 33 - water_velo_instrument_flag
        // 34, 35, 36 - water_velo_earth
        // 37 - water_velo_earth_flag
        // 38, 39, 40 - rph
        // 41 - altitude_estimate
        // 42 - temperature
        // 43 - pressure
        // 44 - salinity
        // 45 - sound_speed
        // 46 - checksum
        unsigned gvel_flag = 0;
        unsigned wvel_flag = 0;
        unsigned csum = 0;
        double tstamp = Clock::getSinceEpoch();

        int srv = std::sscanf(bfr,
                              "%*[^ ] " // header
                              "%*[^ ] " // error_code
                              "%*u %*u %*u %*u" // good_or_bad
                              "%f %f %f %f" // v_altitude
                              "%*f %*f %*f %*f" // velo_rad
                              "%*f %*f %*f %*f" // wvelo_rad
                              "%*u %*u %*u %*u" // wvelo_credit
                              "%lf %lf %lf" // velo_instrument
                              "%u" // velo_instrument_flag
                              "%*f %*f %*f" // velo_earth
                              "%*u" // velo_earth_flag
                              "%lf %lf %lf" // water_velo_instrument
                              "%u" // water_velo_instrument_flag
                              "%*f %*f %*f" // water_velo_earth
                              "%*u" // water_velo_earth_flag
                              "%*f %*f %*f" // rph
                              "%f" // altitude_estimate
                              "%*f" // temperature
                              "%*f" // pressure
                              "%*f" // salinity
                              "%*u" // sound speed
                              "%u" // checksum
                              "\r\n",
                              &m_altitude[0].value, &m_altitude[1].value, &m_altitude[2].value, &m_altitude[3].value,
                              &m_gvel.x, &m_gvel.y, &m_gvel.z, &gvel_flag,
                              &m_wvel.x, &m_wvel.y, &m_wvel.z, &wvel_flag,
                              &m_altitude[4].value,
                              &csum);

        if (srv != 14)
        {
          err(DTR("invalid sample"));
          return;
        }

        const char* sptr = std::strchr(bfr, ' ');
        const char* eptr = std::strrchr(bfr, ' ');
        uint8_t ccsum = XORChecksum::compute((const uint8_t*)sptr, eptr - sptr);

        if (csum != ccsum)
        {
          war("%s", DTR(Status::getString(Status::CODE_INVALID_CHECKSUM)));
          return;
        }

        // Correct sound speed.
        if (m_sound_speed_eid > 0)
        {
          correctSoundSpeed(m_gvel.x);
          correctSoundSpeed(m_gvel.y);
          correctSoundSpeed(m_gvel.z);
          correctSoundSpeed(m_wvel.x);
          correctSoundSpeed(m_wvel.y);
          correctSoundSpeed(m_wvel.z);

          for (unsigned i = 0; i < 5; ++i)
            correctSoundSpeed(m_altitude[i].value);
        }

        // Dispatch ground velocity (signals inverted).
        if (gvel_flag == 1)
        {
          m_gvel.validity = m_gvel_valid_flag;
          m_gvel.x /= -1000.0;
          m_gvel.y /= -1000.0;
          m_gvel.z /= -1000.0;
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
        }
        else
        {
          m_gvel.clear();
          setEntityState(IMC::EntityState::ESTA_FAULT, Status::CODE_NO_BOTTOM_LOCK);
        }

        m_gvel.setTimeStamp(tstamp);
        dispatch(m_gvel, DF_KEEP_TIME);

        // Dispatch water velocity.
        if (wvel_flag == 2)
        {
          m_wvel.validity = m_wvel_valid_flag;
          m_wvel.x /= -1000.0;
          m_wvel.y /= -1000.0;
          m_wvel.z /= -1000.0;
        }
        else
        {
          m_wvel.clear();
        }

        m_wvel.setTimeStamp(tstamp);
        dispatch(m_wvel, DF_KEEP_TIME);

        // Dispatch bottom ranges.
        for (unsigned i = 0; i < c_altitude_count; ++i)
        {
          m_altitude[i].validity = IMC::Distance::DV_VALID;

          if (m_altitude[i].value <= 0.0)
          {
            m_altitude[i].value = 0.0;
            m_altitude[i].validity = IMC::Distance::DV_INVALID;
          }

          m_altitude[i].setTimeStamp(tstamp);
          dispatch(m_altitude[i], DF_KEEP_TIME);
        }
      }

      void
      onMain(void)
      {
        while (!stopping())
        {
          if (m_active)
          {
            consumeMessages();
          }
          else
          {
            waitForMessages(1.0);
            continue;
          }

          if (m_uart->hasNewData(1.0) == IOMultiplexing::PRES_OK)
            readNQ1();
        }
      }
    };
  }
}

DUNE_TASK
