//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Eduardo Marques                                                  *
//***************************************************************************
// $Id:: Task.cpp 12667 2013-01-22 02:44:42Z rasm                         $:*
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>
#include <DUNE/Piccolo.hpp>

namespace Sensors
{
  namespace Piccolo
  {
    namespace GSTelemetry
    {
      using DUNE_NAMESPACES;
      using namespace DUNE::Piccolo;

      struct Task: public APPacketProcessor
      {
        static const int c_max_addresses = 80;

        struct GroupAddressData
        {
          uint16_t addresses[c_max_addresses];
          uint8_t ack_ratios[c_max_addresses];
          uint16_t pilot_address;
          GSNetworkFlags_t flags;
        };

        struct TelemetryData
        {
          GPS_t gps;
          SystemData_t system;
          float vswr;
          float static_pressure;
          double last_time;
        };

        Addresses m_addrs;
        GroupAddressData m_gad;
        TelemetryData m_telem;
        APPacket m_pkt_out;

        IMC::Current m_current;
        IMC::GpsFix m_gps;
        IMC::LinkLevel m_ll;
        IMC::RSSI m_rssi;
        IMC::Temperature m_temperature;
        IMC::Voltage m_voltage;
        IMC::VSWR m_vswr;

        Task(const std::string& name, Tasks::Context& ctx):
          APPacketProcessor(name, ctx),
          m_addrs(ctx)
        {
          hGS<Task>(GROUP_ADDRESS, &Task::onGroupAddress);
          hGS<Task>(GS_TELEMETRY, &Task::onTelemetry);
          hGS<Task>(GS_VERSION, &Task::onVersion);
          hGS<Task>(GS_RESET_REPORT, &Task::onResetReport);
        }

        void
        onGroupAddress(const APPacket* pkt)
        {
          uint8_t n = DecodeGroupAddressPacket(pkt, m_gad.addresses, m_gad.ack_ratios, c_max_addresses, &m_gad.pilot_address, &m_gad.flags);


          for (uint8_t i = 0; i < n; ++i)
          {

            std::string vname = "unknown";

            uint16_t imc_addr = m_addrs.toIMCAddress(m_gad.addresses[i]);

            if (imc_addr != Addresses::c_invalid)
            {
              vname = resolveSystemId(imc_addr);
              m_ll.setSource(imc_addr);
              m_ll.value = (fp64_t)m_gad.ack_ratios[i];
              dispatch(m_ll);
            }

            inf(DTR("vehicle: %s SN: %d link level: %d%%"), vname.c_str(), (int) m_gad.addresses[i], (int) m_gad.ack_ratios[i]);
          }
        }

        void
        onTelemetry(const APPacket* pkt)
        {
          // dirty (yet safe) cast required
          SInt8 v = DecodeGSTelemetryPacket((APPacket*)pkt, &m_telem.gps, &m_telem.system, &m_telem.vswr, &m_telem.static_pressure);

          if (!v)
          {
            err(DTR("error decoding GS telemetry packet"));
            return;
          }

          m_telem.last_time = Clock::get();

          m_rssi.value = 100.0 * (((double)v) - c_min_rssi) / (c_max_rssi - c_min_rssi);

          if (getEntityState() != IMC::EntityState::ESTA_NORMAL)
          {
            MakeGroundStationPacket(&m_pkt_out, GS_VERSION, 0);
            sendToGS(&m_pkt_out);
          }

          m_current.value = m_telem.system.InputCurrent;
          m_temperature.value = m_telem.system.AvionicsTemp;
          m_voltage.value = m_telem.system.InputVoltage;

          dispatch(m_current);
          dispatch(m_temperature);
          dispatch(m_voltage);
          dispatch(m_rssi);

          if (m_telem.vswr > 1000)
          {
            m_vswr.value = m_telem.vswr;
            dispatch(m_vswr);
          }
        }

        void
        onResetReport(const APPacket* pkt)
        {
          UInt16 RSR, Vec;
          UInt32 PC, MSR;
          UInt32 Link;

          if (!DecodeGSResetReportPacket(pkt, &RSR, &Vec, &PC, &MSR, &Link))
            return;

          err(DTR("GS SYSTEM RESET ! Info: %u %u %u %u"), RSR, Vec, (unsigned)PC, (unsigned)MSR);

          if (RSR & 0x01)
            err(DTR(" ... due to internal exception"));
          if (RSR & 0x10)
            err(DTR("... due to rest pin"));
          if (RSR & 0x20)
            err(DTR("... due to power on"));
          if (RSR & 0x1000)
            err(DTR("... due to watchdog"));

          setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_INIT);
          war("%s", DTR(Status::getString(Status::CODE_INIT)));
        }

        void
        onVersion(const APPacket* pkt)
        {
          Version_t v;
          Board_t b;
          if (!DecodeGSVersionPacket(pkt, &v, &b))
            err(DTR("error decoding GS Version packet"));

          inf(DTR("software version %d.%d.%d patch %d %4d-%02d-%02d"),
              (int)v.MajorVersion,
              (int)v.MinorVersion,
              (int)v.SubVersion,
              (int)v.PatchNum,
              (int)v.Date.year,
              (int)v.Date.month,
              (int)v.Date.day);

          inf(DTR("hardware board - SN %0d FN %d rev %d config %u %d-%02d-%02d"),
              b.SerialNumber,
              b.FeatureCode,
              b.Rev,
              (unsigned)b.Config,
              b.Date.year,
              b.Date.month,
              b.Date.day);
        }

        void
        onMain(void)
        {
          const double timeout = 6.0; // GS sends telemetry every 2.0 seconds

          setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_INIT);
          m_telem.last_time = 0;

          while (!stopping())
          {
            waitForMessages(1.0);

            if (Clock::get() - m_telem.last_time >= timeout)
            {
              if (getEntityState() != IMC::EntityState::ESTA_ERROR)
              {
                setEntityState(IMC::EntityState::ESTA_ERROR, Status::CODE_COM_ERROR);
                err("%s", DTR(Status::getString(Status::CODE_COM_ERROR)));
              }
            }
            else if (getEntityState() != IMC::EntityState::ESTA_NORMAL)
            {
              setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
              inf("%s", DTR(Status::getString(Status::CODE_ACTIVE)));
            }
          }
        }
      };
    }
  }
}

DUNE_TASK
