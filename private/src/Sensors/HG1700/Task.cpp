//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************

// ISO C++ 98 headers.
#include <stdexcept>
#include <cerrno>

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Linux headers.
#include <sys/select.h>

// SAB 82532 Receive Status Register: Valid Frame.
#define SAB82532_RSTA_VFR    (1 << 7)
// SAB 82532 Receive Status Register: CRC Check OK.
#define SAB82532_RSTA_CRC    (1 << 5)

namespace Sensors
{
  namespace HG1700
  {
    using DUNE_NAMESPACES;

    // IMU address.
    static const uint8_t c_imu_addr = 0x0a;
    // Angular Velocity conversion factor (2^-20 * 600).
    static const double c_agvel_factor = 0.0005722045898437500000000;
    // Acceleration conversion factor (2^-14 * 600 * (12/39.37)).
    static const double c_accel_factor = 0.0111621316992634;
    // Delta Angle conversion factor (2^-33).
    static const double c_edelt_factor = 0.0000000001164153218269348;
    // Delta Velocity conversion factor (2^-27 * (12/39.37)).
    static const double c_vdelt_factor = 0.00000000227094150782540;
    // Flight Control Data Frame Size.
    static const int c_fcd_size = 18 + 1;
    // Flight Control Data and Inertial Data Frame Size.
    static const int c_fcdid_size = c_fcd_size + 24;
    // Amount of time, in seconds, between messages.
    static const double c_message_delta = 1 / 600.0;

    struct Arguments
    {
      // ESCC - Device.
      std::string escc_dev;
      // Input timeout.
      float input_tout;
      // Power channel name.
      std::string power_channel;
      // IMU rotation matrix values.
      std::vector<double> rotation_mx;
    };

    // Convenience function to throw the last system error.
    inline void
    throwLastError(const std::string& msg)
    {
      throw std::runtime_error(msg + System::Error::getLastMessage());
    }

    struct Task: public DUNE::Tasks::Task
    {
      // ESCC descriptor.
      int m_fd;
      // Rotation Matrix to correct IMU mounting position.
      Matrix m_rotation;
      // Sensor data matrix.
      Matrix m_data;
      // Angular velocity.
      IMC::AngularVelocity m_agvel;
      // Acceleration
      IMC::Acceleration m_accel;
      // Euler Angles Delta.
      IMC::EulerAnglesDelta m_edelt;
      // Velocity Delta.
      IMC::VelocityDelta m_vdelt;
      // Task arguments.
      Arguments m_args;
      // Input Watchdog.
      Counter<float> m_wdog;
      // Power channel state.
      IMC::PowerChannelState m_power_channel_state;
      // Power channel control.
      IMC::PowerChannelControl m_power_channel_control;
      // True if task is active.
      bool m_active;
      // IMU timestamp.
      double m_imu_time;

      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        m_fd(-1),
        m_active(false),
        m_imu_time(0)
      {
        param("ESCC - Device", m_args.escc_dev)
        .defaultValue("")
        .description("HG1700 ESCC Device parameter");

        param("Input Timeout", m_args.input_tout)
        .units(Units::Second)
        .defaultValue("2")
        .description("Number of seconds for the watchdog");

        param("IMU Rotation Matrix", m_args.rotation_mx)
        .defaultValue("")
        .size(9)
        .description("IMU rotation matrix which is dependent of the mounting position");

        param("Power Channel", m_args.power_channel)
        .defaultValue("IMU")
        .description("Power channel that controls the power of the device");

        // Resize sensor data matrix.
        m_data.resize(3, 1);

        // Register consumers.
        bind<IMC::EntityControl>(this);
        bind<IMC::PowerChannelState>(this);
      }

      void
      onUpdateParameters(void)
      {
        m_rotation.fill(3, 3, &m_args.rotation_mx[0]);
      }

      ~Task(void)
      {
        onResourceRelease();
      }

      void
      onResourceAcquisition(void)
      {
        m_fd = open(m_args.escc_dev.c_str(), O_RDWR);
        if (m_fd == -1)
          throwLastError(DTR("failed to open ESCC device"));
      }

      void
      onResourceRelease(void)
      {
        if (m_fd != -1)
        {
          close(m_fd);
          m_fd = -1;
        }
      }

      void
      onResourceInitialization(void)
      {
        setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
        m_wdog.setTop(m_args.input_tout);
      }

      void
      consume(const IMC::EntityControl* msg)
      {
        if (msg->getDestinationEntity() != getEntityId())
          return;

        m_active = (msg->op == IMC::EntityControl::ECO_ACTIVATE);

        if (m_active)
        {
          inf("%s", DTR(Status::getString(Status::CODE_ACTIVE)));
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
          if (m_power_channel_state.state != IMC::PowerChannelState::PCS_ON)
          {
            m_power_channel_control.id = m_power_channel_state.id;
            m_power_channel_control.op = IMC::PowerChannelControl::PCC_OP_TURN_ON;
            dispatch(m_power_channel_control);
          }
        }
        else
        {
          inf("%s", DTR(Status::getString(Status::CODE_IDLE)));
          setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_IDLE);
          if (m_power_channel_state.state != IMC::PowerChannelState::PCS_OFF)
          {
            m_power_channel_control.id = m_power_channel_state.id;
            m_power_channel_control.op = IMC::PowerChannelControl::PCC_OP_TURN_OFF;
            dispatch(m_power_channel_control);
          }
        }
      }

      void
      consume(const IMC::PowerChannelState* msg)
      {
        if (msg->label != m_args.power_channel)
          return;

        m_power_channel_state = *msg;
      }

      bool
      decodeFrame(const uint8_t* bfr, unsigned bfr_len)
      {
        if (!(bfr[bfr_len - 1] & SAB82532_RSTA_VFR))
          return false;

        if (bfr[0] != c_imu_addr && bfr[1] > 0x02)
          return false;

        // Flight control data.
        int16_t tmp16 = 0;
        m_data.fill(0.0);
        ByteCopy::fromLE(tmp16, bfr + 2);
        m_data(0) = tmp16 * c_agvel_factor;
        ByteCopy::fromLE(tmp16, bfr + 4);
        m_data(1) = tmp16 * c_agvel_factor;
        ByteCopy::fromLE(tmp16, bfr + 6);
        m_data(2) = tmp16 * c_agvel_factor;

        m_data = m_rotation * m_data;
        m_agvel.x = m_data(0);
        m_agvel.y = m_data(1);
        m_agvel.z = m_data(2);
        dispatch(m_agvel, DF_KEEP_TIME);

        m_data.fill(0.0);
        ByteCopy::fromLE(tmp16, bfr + 8);
        m_data(0) = tmp16 * c_accel_factor;
        ByteCopy::fromLE(tmp16, bfr + 10);
        m_data(1) = tmp16 * c_accel_factor;
        ByteCopy::fromLE(tmp16, bfr + 12);
        m_data(2) = tmp16 * c_accel_factor;

        m_data = m_rotation * m_data;
        m_accel.x = m_data(0);
        m_accel.y = m_data(1);
        m_accel.z = m_data(2);
        dispatch(m_accel, DF_KEEP_TIME);

        // Inertial data.
        if (bfr[1] == 0x02)
        {
          int32_t tmp32 = 0;
          ByteCopy::fromLE(tmp32, bfr + 14);
          m_edelt.x = tmp32 * c_edelt_factor;
          ByteCopy::fromLE(tmp32, bfr + 18);
          m_edelt.y = tmp32 * c_edelt_factor;
          ByteCopy::fromLE(tmp32, bfr + 22);
          m_edelt.z = tmp32 * c_edelt_factor;
          dispatch(m_edelt, DF_KEEP_TIME);

          ByteCopy::fromLE(tmp32, bfr + 26);
          m_vdelt.x = tmp32 * c_vdelt_factor;
          ByteCopy::fromLE(tmp32, bfr + 30);
          m_vdelt.y = tmp32 * c_vdelt_factor;
          ByteCopy::fromLE(tmp32, bfr + 34);
          m_vdelt.z = tmp32 * c_vdelt_factor;
          dispatch(m_vdelt, DF_KEEP_TIME);
        }

        return true;
      }

      bool
      hasData(void)
      {
        fd_set rfd;
        FD_ZERO(&rfd);
        FD_SET(m_fd, &rfd);

        timeval tv = {1, 0};
        int rv = select(m_fd + 1, &rfd, 0, 0, &tv);

        return rv > 0;
      }

      void
      onMain(void)
      {
        uint8_t bfr[128];

        while (!stopping())
        {
          if (!m_active)
          {
            waitForMessages(1.0);
            continue;
          }

          consumeMessages();
          if (!m_active)
            continue;

          if (hasData())
          {
            int rv = read(m_fd, bfr, sizeof(bfr));
            if (rv != c_fcd_size && rv != c_fcdid_size)
              continue;

            m_edelt.time = m_imu_time;
            m_vdelt.time = m_imu_time;
            m_agvel.time = m_imu_time;
            m_accel.time = m_imu_time;

            m_agvel.setTimeStamp();
            m_accel.setTimeStamp(m_agvel.getTimeStamp());
            m_vdelt.setTimeStamp(m_agvel.getTimeStamp());
            m_edelt.setTimeStamp(m_agvel.getTimeStamp());

            if (decodeFrame(bfr, rv))
            {
              setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
              m_wdog.reset();
            }

            m_imu_time += c_message_delta;
          }

          if (m_wdog.overflow())
          {
            setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_COM_ERROR);
            m_wdog.reset();
          }
        }
      }
    };
  }
}

DUNE_TASK
