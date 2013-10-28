//***************************************************************************
// Copyright 2007-2013 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Universidade do Porto. For licensing   *
// terms, conditions, and further information contact lsts@fe.up.pt.        *
//                                                                          *
// European Union Public Licence - EUPL v.1.1 Usage                         *
// Alternatively, this file may be used under the terms of the EUPL,        *
// Version 1.1 only (the "Licence"), appearing in the file LICENCE.md       *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://www.lsts.pt/dune/licence.                                        *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

// Local headers.
#include "Codecs.hpp"

namespace Transports
{
  namespace Noptilus
  {
    using DUNE_NAMESPACES;

    static const uint8_t c_estate_id = 0xfe;

    struct Arguments
    {
      //! Number of TDMA slots.
      unsigned slot_count;
      //! TDMA slot number.
      unsigned slot_number;
      //! TDMA slot duration.
      unsigned slot_dur;
    };

    struct Task: public DUNE::Tasks::Task
    {
      //! Last received estimated state.
      IMC::EstimatedState* m_estate;
      //! Seconds.
      std::set<unsigned> m_seconds;
      //! Task arguments.
      Arguments m_args;

      //! Constructor.
      //! @param[in] name task name.
      //! @param[in] ctx context.
      Task(const std::string& name, Tasks::Context& ctx):
        DUNE::Tasks::Task(name, ctx),
        m_estate(NULL)
      {
        param("Slot Count", m_args.slot_count)
        .description("Number of TDMA slots");

        param("Slot Number", m_args.slot_number)
        .description("TDMA slot of local node");

        param("Slot Duration", m_args.slot_dur)
        .units(Units::Second)
        .description("TDMA slot duration");

        bind<IMC::EstimatedState>(this);
        bind<IMC::UamRxFrame>(this);
        bind<IMC::GpsFix>(this);
      }

      ~Task(void)
      {
        Memory::clear(m_estate);
      }

      //! Update internal state with new parameter values.
      void
      onUpdateParameters(void)
      {
        m_seconds.clear();
        unsigned slot = 0;
        for (unsigned i = 0; i < 60; i += m_args.slot_dur)
        {
          if (slot == m_args.slot_number)
          {
            m_seconds.insert(i);
            inf("slot second %u", i);
          }

          if (++slot > m_args.slot_count)
            slot = 0;
        }
      }

      //! Reserve entity identifiers.
      void
      onEntityReservation(void)
      {
      }

      //! Resolve entity names.
      void
      onEntityResolution(void)
      {
      }

      //! Acquire resources.
      void
      onResourceAcquisition(void)
      {
      }

      //! Initialize resources.
      void
      onResourceInitialization(void)
      {
      }

      //! Release resources.
      void
      onResourceRelease(void)
      {
      }

      void
      consume(const IMC::EstimatedState* msg)
      {
        Memory::clear(m_estate);
        m_estate = new EstimatedState(*msg);
      }

      void
      consume(const IMC::UamRxFrame* msg)
      {
        if (msg->data.size() < 1)
          return;

        uint8_t id = msg->data[0];

        IMC::Message* rmsg = NULL;
        switch (id)
        {
          case c_estate_id:
            rmsg = CodedEstimatedState::decode(msg);
            break;
        }

        if (rmsg != NULL)
        {
          dispatch(*rmsg);
        }
      }

      void
      consume(const IMC::GpsFix* msg)
      {
        unsigned thour = (unsigned)(msg->utc_time / 3600);
        unsigned tmin = (unsigned)(((msg->utc_time / 3600.0) - thour) * 60);
        unsigned tsec = (unsigned)Math::round(((((msg->utc_time / 3600.0) - thour) * 60.0) - tmin) * 60.0);

        if (m_seconds.find(tsec) != m_seconds.end())
        {
          transmit();
        }
      }

      void
      transmit(void)
      {
        if (m_estate == NULL)
          return;

        IMC::UamTxFrame frame;
        frame.sys_dst = "broadcast";
        CodedEstimatedState::encode(m_estate, &frame);
        dispatch(frame);
        inf("transmitting");
      }

      //! Main loop.
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

DUNE_TASK
