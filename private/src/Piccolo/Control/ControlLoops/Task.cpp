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

namespace Control
{
  namespace UAV
  {
    namespace Piccolo
    {
      namespace ControlLoops
      {
        using DUNE_NAMESPACES;
        using namespace DUNE::Piccolo;

        struct Task: public APPacketProcessor
        {
          //! SDK packet datum.
          APPacket m_out;
          //! Bitfield of enabled control loops.
          uint32_t m_cloops;

          Task(const std::string& name, Tasks::Context& ctx):
            APPacketProcessor(name, ctx),
            m_cloops(0)
          {
            setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);

            bind<IMC::DesiredHeading>(this);
            bind<IMC::DesiredZ>(this);
            bind<IMC::DesiredRoll>(this);
            bind<IMC::DesiredSpeed>(this);
            bind<IMC::DesiredVerticalRate>(this);
            bind<IMC::ControlLoops>(this);
          }

          ~Task()
          { }

          void
          sendAPLoopCmd(int type, double value)
          {
            AutopilotLoopCmd_t command;
            command.Control = AP_ON;
            command.Loop = type;
            command.Value = value;
            //-Para activar apenas quando a interface com mensagens 2.1.4 estiver implementado
            //command.EEPROM = 1;
            FormAutopilotLoopControlPacket(&m_out, &command);
            sendToAP(&m_out);
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
            uint32_t prev = m_cloops;

            if (cloops->enable)
              m_cloops |= cloops->mask;
            else
              m_cloops &= ~cloops->mask;

            info(prev, m_cloops, IMC::CL_ALTITUDE, DTR("altitude control"));
            info(prev, m_cloops, IMC::CL_YAW, DTR("heading control"));
            info(prev, m_cloops, IMC::CL_ROLL, DTR("bank control"));
            info(prev, m_cloops, IMC::CL_SPEED, DTR("speed control"));
            info(prev, m_cloops, IMC::CL_VERTICAL_RATE, DTR("vertical rate control"));
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

            sendAPLoopCmd(AP_LOOP_ALT, da->value);
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

            sendAPLoopCmd(AP_LOOP_HEADING, value);
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

            sendAPLoopCmd(AP_LOOP_BANK, dr->value);
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

            sendAPLoopCmd(AP_LOOP_IAS, ds->value);
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

            sendAPLoopCmd(AP_LOOP_VRATE, dvr->value);
          }

          void
          onMain(void)
          {
            while (!stopping())
            {
              waitForMessages(1.0);
            }
          }
        };
      }
    }
  }
}

DUNE_TASK
