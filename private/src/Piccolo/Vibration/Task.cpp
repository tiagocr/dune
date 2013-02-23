//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************
// $Id:: Task.cpp 12695 2013-01-23 22:54:41Z rasm                         $:*
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Sensors
{
  namespace Piccolo
  {
    namespace Vibration
    {
      using DUNE_NAMESPACES;
      using namespace DUNE::Piccolo;

      // Handler task for vibration data from Piccolo.
      //
      // On request Piccolo yields data from a 1Khz sample from
      // sensors & gyros regarding vibration.
      //
      // The data is reported with the RAW_VIBRATION_DATA packet
      // as follows:
      // - Per each sensor in the order given by the enumeration below.
      //   16 packets each with 64 ADC samples are sent.
      //
      // Since the outer loop is per sensor rather than per sample,
      // buffering is required first for all angular velocities and
      // then accelaration measures to report properly in IMC terms.

      static const int c_samples_per_pkt = 64;
      static const int c_pkt_per_cycle = 16;
      static const int c_samples_per_cycle = 1024;
      static const double c_sensor_freq = 0.0009765625; //  = 1 / 1024

      enum
      {
        c_roll_rate,
        c_pitch_rate,
        c_yaw_rate,
        c_accel_x,
        c_accel_y,
        c_accel_z,
        c_num_readings
      };

      struct SensorReading
      {
        uint16_t data[c_samples_per_pkt];
        uint16_t zero;
        fp32_t gain;
      };

      struct Arguments
      {
        double cycle_delay; // Cycle delay.
      };

      struct Task: public APPacketProcessor
      {
        Arguments m_args;      // Task arguments.
        bool m_start_cycle;    // Cycle start flag.
        bool m_error_recovery; // Error recovery flag.
        uint8_t m_next_sensor; // Expected sensor for next reading.
        uint16_t m_next_index; // Expected index for next reading.

        double m_start_time;   // Processing start time.
        double m_ref_time;     // Reference time for cycle start.

        SensorReading m_data[c_pkt_per_cycle][2]; // Data buffer (aprox. 4 Kb)
        SensorReading m_stage2_reading; // Work variable for 3rd variable in order.

        IMC::AngularVelocity m_vel; // Work var. to report angular velocities.
        IMC::Acceleration m_acc; // Work var. to report acceleration
        APPacket m_req_pkt; // Cycle request packet.

        Task(const std::string& name, Tasks::Context& ctx):
          APPacketProcessor(name, ctx)
        {
          param("Cycle Delay", m_args.cycle_delay)
          .units(Units::Second)
          .minimumValue("0.0")
          .defaultValue("0.0");

          m_start_time = m_ref_time = Clock::get();
          m_next_index = 0;
          m_next_sensor = 0;
          m_start_cycle = true;
          m_error_recovery = false;

          hAP(RAW_VIBRATION_DATA, &Task::onVibrationPacket);

          MakeAutopilotPacket(&m_req_pkt, RAW_VIBRATION_DATA, 0);
        }

        void
        onEntityReservation(void)
        {
          int eid = reserveEntity("Vibration Data", true);
          m_acc.setSourceEntity(eid);
          m_vel.setSourceEntity(eid);
        }

        double
        value(SensorReading* sr, int sample)
        {
          double v = (double)sr->data[sample];
          v -= (double)sr->zero;
          v *= sr->gain;
          return v;
        }

        void
        onVibrationPacket(const APPacket* pkt)
        {
          // Decode sensor reading
          uint8_t sensor;
          uint16_t index;

          SensorReading* sr;

          if ((m_next_sensor % 3) == 2)
            sr = &m_stage2_reading;
          else
            sr = &m_data[m_next_index][m_next_sensor % 3];

          sensor = DecodeRawVibrationPacket(pkt, &index, sr->data, &sr->zero, &sr->gain);
          index = index >> 6; // multiples of 64

          if (sensor >= 5)
            sensor -= 2;  // Accel indexes start at 5, our own numeration starts at 3

          //printf("VD got %d:%d exp %d:%d - %d\n", (int) sensor, (int) index, (int) m_next_sensor, (int) m_next_index, m_error_recovery);

          if (sensor != m_next_sensor || index != m_next_index)
          {
            err(DTR("protocol error - sample %d:%d != %d:%d"),
                (int)m_next_sensor, m_next_index, (int)sensor, index);
            m_error_recovery = true;
            m_next_sensor = sensor;
            m_next_index = index;
          }

          if (m_error_recovery)
          {
            m_next_index = (index + 1) % c_pkt_per_cycle;
            if (m_next_index == 0)
              m_next_sensor = (m_next_sensor + 1) % c_num_readings;
            m_error_recovery = (m_next_sensor != c_roll_rate || m_next_index != 0);
            if (!m_error_recovery)
              m_start_cycle = true;
            return;
          }

          if (m_next_sensor == c_yaw_rate)
            sendAngularVelocity(index);
          else if (m_next_sensor == c_accel_z)
            sendAcceleration(index);

          m_next_index = (m_next_index + 1) % c_pkt_per_cycle;

          if (m_next_index != 0)
            return;

          m_next_sensor = (m_next_sensor + 1) % c_num_readings;

          if (m_next_sensor != c_roll_rate)
            return;

          // End of cycle
          m_ref_time = Clock::get();
          m_start_cycle = true;
        }

        void
        sendAngularVelocity(int index)
        {
          m_vel.time = (m_ref_time - m_start_time) + (index << 6) * c_sensor_freq;

          for (int i = 0; i != c_samples_per_pkt; i++)
          {
            m_vel.x = value(&m_data[index][0], i);
            m_vel.y = value(&m_data[index][1], i);
            m_vel.z = value(&m_stage2_reading, i);
            dispatch(m_vel);
            m_vel.time += c_sensor_freq;
          }
        }

        void
        sendAcceleration(int index)
        {
          m_acc.time = (m_ref_time - m_start_time) + (index << 6) * c_sensor_freq;

          for (int i = 0; i != c_samples_per_pkt; i++)
          {
            m_acc.x = value(&m_data[index][0], i);
            m_acc.y = value(&m_data[index][1], i);
            m_acc.z = value(&m_stage2_reading, i);
            dispatch(m_acc);
            m_acc.time += c_sensor_freq;
          }
        }

        void
        onMain(void)
        {
          while (!stopping())
          {
            if (m_start_cycle)
            {
              if (m_args.cycle_delay > 0)
                Delay::wait(m_args.cycle_delay);

              sendToAP(&m_req_pkt);
            }
            waitForMessages(0.1);
          }
        }
      };
    }
  }
}

DUNE_TASK
