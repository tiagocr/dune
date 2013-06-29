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
// Automatically generated.                                                 *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

using DUNE_NAMESPACES;

#include "Test.hpp"

int
main(void)
{
  Test test("IMC Serialization/Deserialization");

  {
    IMC::EntityState msg;
    msg.setTimeStamp(0.795019068955);
    msg.setSource(12531U);
    msg.setSourceEntity(162U);
    msg.setDestination(39537U);
    msg.setDestinationEntity(78U);
    msg.state = 246U;
    msg.flags = 120U;
    msg.description.assign("IYMSPIMXRXTQKIHANSSNCCEHEFUQKTSHZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityState msg;
    msg.setTimeStamp(0.631791659418);
    msg.setSource(31936U);
    msg.setSourceEntity(235U);
    msg.setDestination(47326U);
    msg.setDestinationEntity(250U);
    msg.state = 158U;
    msg.flags = 73U;
    msg.description.assign("XMKSQDPRJKMXVTSNGQQMEUZLRWIBPYAUMBIKIENMIQXYOSCXXNEPGSCXJPFJYUQSSLHZDRVSABKEAANOFMTSIVPXCHWJWOJQJKFANCRZQABIEYGJRVGIAZITHZEKFHRMRHOOKVWUKOVEHSVRGSGLNRTZKMPLWLDXFYWWNJBANWBGCOUBWUTJUDCACLTHHBPLLTFYQEYTHDYDU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityState msg;
    msg.setTimeStamp(0.115841588079);
    msg.setSource(32342U);
    msg.setSourceEntity(36U);
    msg.setDestination(12724U);
    msg.setDestinationEntity(129U);
    msg.state = 112U;
    msg.flags = 131U;
    msg.description.assign("SFXRSYRLZWRKJFLNVGCFKSESVYBTQWTUGGVSDIYCQLRXDNJVTVHZRASIUIEBNIUMAZYJARAOKZENKEWHOPTOGCFWUCBUHVIWPSZNAJXPMSKQQQFLTKIOJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityState msg;
    msg.setTimeStamp(0.55337299959);
    msg.setSource(62704U);
    msg.setSourceEntity(54U);
    msg.setDestination(15460U);
    msg.setDestinationEntity(31U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityState msg;
    msg.setTimeStamp(0.0834796397491);
    msg.setSource(47431U);
    msg.setSourceEntity(173U);
    msg.setDestination(4098U);
    msg.setDestinationEntity(200U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityState msg;
    msg.setTimeStamp(0.573845411518);
    msg.setSource(30135U);
    msg.setSourceEntity(27U);
    msg.setDestination(23341U);
    msg.setDestinationEntity(26U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityInfo msg;
    msg.setTimeStamp(0.241053641853);
    msg.setSource(20214U);
    msg.setSourceEntity(213U);
    msg.setDestination(43705U);
    msg.setDestinationEntity(39U);
    msg.id = 98U;
    msg.label.assign("JOGKYVDGWFKKZLOSTLLTIQRVTHGIHYNZNPFQSURQQGMHTCUWNRYDINXSLWVUZZSBQPBBASLNFMVAUMFKSPHVRCFEFGYNIKKTPAORBLNBPAQIBJEATHEBMWHCGUDMALPWAA");
    msg.component.assign("YNMYOFFOHPSTPUIJQKEIUAGGVBHATHDREDZBQOTZUGNRCTLRGLFZBBHJMWNITCLBXVIXCXF");
    msg.act_time = 22158U;
    msg.deact_time = 37276U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityInfo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityInfo msg;
    msg.setTimeStamp(0.830367512254);
    msg.setSource(57049U);
    msg.setSourceEntity(142U);
    msg.setDestination(9367U);
    msg.setDestinationEntity(228U);
    msg.id = 82U;
    msg.label.assign("UDXDYRKEZEAUSNOECIEVZBNCAOPPQWJAPBQLHRZLUXWSTRAKRNUVHLCPFGIRFWZVBJYCGYQDBXNXZEAQCJCVKWMBMPYPTJQKSXABMSGHPPXMOHAMHMZLFHRIDOSYKQNLFVIWQWSHUJKTWNYJJOQKSMD");
    msg.component.assign("RENIMWHCXXKAGGKNOQQYCWLUYLTFFNUWPUNIXHYTYSGMDUIJISJKTDGEODBMCFDJOPTOONDCARUURGMPBFMEPRAXIJDYNXZRJJCZFMLZKTKNLFVNHSTBPBAQZOSDCIVZIVEWWPQGHGVPJCSNXNFJKLVLKTJXQEKMOZBPHTQLLUQCJHUOWCVEZZERHSTMLRGHXLSSQASDKKDQWDRAIUFGFYPHOORBWBABRWXUHPSAMEZVVQYAICTA");
    msg.act_time = 35233U;
    msg.deact_time = 28593U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityInfo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityInfo msg;
    msg.setTimeStamp(0.183861155869);
    msg.setSource(14155U);
    msg.setSourceEntity(198U);
    msg.setDestination(12592U);
    msg.setDestinationEntity(74U);
    msg.id = 12U;
    msg.label.assign("CZIJOKGDIBUZWPABMCMGEMPVAHMAYVWNNZKFMQLXOZZSVOSFFFHMAXVKZJSTTKFEPFHMTCJUIJBSROEVLJLMUMBGVUQPPJRDBKPLUQGATVDTSRKHWCGSYNOFCPUMTRCEJYUUXICLRSLXJHIEAKHITBPLNARDHGVCOBNXSQGIUYSPEKXIWNAEXZRL");
    msg.component.assign("LWAFGGRFOKUPTRBSYQGZCUOZLWPTXVDVMROXJNAUFFXQWXVQIOTIFVKYNTBDKUCLWPYTPWTJUKEFCHKTMWMMZINEMNYVOIIPEWMHEHGGQBJXTSAYAYAPRRVZBPWWUPLZKDHZDQGHNPBBXOSJ");
    msg.act_time = 56821U;
    msg.deact_time = 59980U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityInfo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityInfo msg;
    msg.setTimeStamp(0.78699196715);
    msg.setSource(40092U);
    msg.setSourceEntity(221U);
    msg.setDestination(41150U);
    msg.setDestinationEntity(19U);
    msg.id = 32U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityInfo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityInfo msg;
    msg.setTimeStamp(0.106337590482);
    msg.setSource(14106U);
    msg.setSourceEntity(181U);
    msg.setDestination(61608U);
    msg.setDestinationEntity(5U);
    msg.id = 20U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityInfo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityInfo msg;
    msg.setTimeStamp(0.889196206431);
    msg.setSource(49551U);
    msg.setSourceEntity(30U);
    msg.setDestination(63131U);
    msg.setDestinationEntity(239U);
    msg.id = 182U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityInfo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityList msg;
    msg.setTimeStamp(0.824057927481);
    msg.setSource(52830U);
    msg.setSourceEntity(252U);
    msg.setDestination(11393U);
    msg.setDestinationEntity(158U);
    msg.op = 145U;
    msg.list.assign("QQUOYQYPNVKHMRNQIQEMITAJCEUJLZRKOZFNACAGMYRCKQISZSJVXKEUZVXTGBJBNGSXDULIOMBVBXODTFQFIWDKXLCMAHPPPZAVGFSGNEEANWYCVSCPUKLWWMDRIBCYYUWNSRFOWJGHNAXDPRCPKYEJEQEJHBQBFIVWFHXZOBHZTHRMLEH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityList #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityList msg;
    msg.setTimeStamp(0.214014411312);
    msg.setSource(44064U);
    msg.setSourceEntity(43U);
    msg.setDestination(20337U);
    msg.setDestinationEntity(215U);
    msg.op = 141U;
    msg.list.assign("HUNUCRYKSNEZRZXSXBAUCGYPZKBVNJYRDFOCRYIYKCQRMSKBWNTUIZC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityList #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityList msg;
    msg.setTimeStamp(0.291280617756);
    msg.setSource(55912U);
    msg.setSourceEntity(87U);
    msg.setDestination(2187U);
    msg.setDestinationEntity(110U);
    msg.op = 147U;
    msg.list.assign("IVALOYAVQUPCURQS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityList #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityControl msg;
    msg.setTimeStamp(0.796408943571);
    msg.setSource(10942U);
    msg.setSourceEntity(43U);
    msg.setDestination(61768U);
    msg.setDestinationEntity(58U);
    msg.op = 125U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityControl msg;
    msg.setTimeStamp(0.310245511705);
    msg.setSource(1629U);
    msg.setSourceEntity(180U);
    msg.setDestination(26815U);
    msg.setDestinationEntity(132U);
    msg.op = 216U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityControl msg;
    msg.setTimeStamp(0.835083143749);
    msg.setSource(13725U);
    msg.setSourceEntity(213U);
    msg.setDestination(43672U);
    msg.setDestinationEntity(13U);
    msg.op = 28U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CpuUsage msg;
    msg.setTimeStamp(0.49901453186);
    msg.setSource(52542U);
    msg.setSourceEntity(161U);
    msg.setDestination(4336U);
    msg.setDestinationEntity(27U);
    msg.value = 135U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CpuUsage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CpuUsage msg;
    msg.setTimeStamp(0.896364687504);
    msg.setSource(43253U);
    msg.setSourceEntity(37U);
    msg.setDestination(62069U);
    msg.setDestinationEntity(7U);
    msg.value = 21U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CpuUsage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CpuUsage msg;
    msg.setTimeStamp(0.989503650494);
    msg.setSource(5142U);
    msg.setSourceEntity(102U);
    msg.setDestination(11462U);
    msg.setDestinationEntity(187U);
    msg.value = 162U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CpuUsage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransportBindings msg;
    msg.setTimeStamp(0.212332949668);
    msg.setSource(21519U);
    msg.setSourceEntity(87U);
    msg.setDestination(63738U);
    msg.setDestinationEntity(29U);
    msg.consumer.assign("NAYOZQCNPWAKTSKTTIZXRKFSBXCRILSUDQSNPBCXZYOSQCSEDCIRUOOFKYWFIFUKCEOXJIXFENEYAFWYZIGMDHIJGJBAWAVBLMPJDPGULXZVEBUFQQHEBAJMHHZHUZNXKNHDBYKGGDLEDRLTVVUWSRSUKRJBIVMBRMEHVDGNSSJPHTROXTKORIYVGLICJNMUFVERMDDAGNWUVPPCZMV");
    msg.message_id = 29378U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransportBindings #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransportBindings msg;
    msg.setTimeStamp(0.161996314514);
    msg.setSource(5893U);
    msg.setSourceEntity(212U);
    msg.setDestination(6408U);
    msg.setDestinationEntity(116U);
    msg.consumer.assign("UKYVRNXENRNHAEXUDBAKKRDXUUCREEMTJQFPQWNYSAPFXPFZIRBDMHLSHNDRAWJTDBGXTGYMJGUZTSTEKQUZVHOTFEPHBQIZYFORLVTATHTMQEFVMBSKVWWIBWDLZNEMSOXPCGGWJYJRYPZZEONOLNBQDVRLGGOVXKULWFOEZBXHSZJXQXMIGVAFBJAKSOIIPPYLQJDBGHPOALFLMVQCMIN");
    msg.message_id = 5208U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransportBindings #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TransportBindings msg;
    msg.setTimeStamp(0.0159294400718);
    msg.setSource(46496U);
    msg.setSourceEntity(31U);
    msg.setDestination(31858U);
    msg.setDestinationEntity(120U);
    msg.consumer.assign("ZYZCVMUSZIZTSTPPDEEAJQFLMMMJTLRSXOCUKCWJLANCXUOMJTOVNTRUOEUDXIQUDSDMOTIIFKCJALRQBUIVVKPVSACGDJRFRYHWDLGZREIKFFFEERGHPWBL");
    msg.message_id = 50754U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TransportBindings #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RestartSystem msg;
    msg.setTimeStamp(0.625275680403);
    msg.setSource(25696U);
    msg.setSourceEntity(13U);
    msg.setDestination(2873U);
    msg.setDestinationEntity(31U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RestartSystem #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RestartSystem msg;
    msg.setTimeStamp(0.867602076267);
    msg.setSource(24466U);
    msg.setSourceEntity(6U);
    msg.setDestination(64212U);
    msg.setDestinationEntity(238U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RestartSystem #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RestartSystem msg;
    msg.setTimeStamp(0.520715246496);
    msg.setSource(11159U);
    msg.setSourceEntity(97U);
    msg.setDestination(20042U);
    msg.setDestinationEntity(230U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RestartSystem #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Parameter msg;
    msg.setTimeStamp(0.738764099837);
    msg.setSource(48934U);
    msg.setSourceEntity(227U);
    msg.setDestination(30935U);
    msg.setDestinationEntity(124U);
    msg.section.assign("ERWZFDMMOFHHOBFWWJFFHDDAJEHNTWXENMUDXAPNXWHPZHSEUKHUWXDTVALPOGARPRQWRYSRRYSJUSZMVDVVSKDLTPOKOLFBEPPJJETZYJBHLHKNGMZRNLSYWXOLCRQGICSPEWFCYWDCEGCSCFVXNIMCAGNQDQKFUJGTLCXBZKVJDMFTZCGTRTAQSQ");
    msg.param.assign("OCGUYCIMDTYSHEVHVPIUWIJDYQNEEDGCAJDCONWIYDVBYUDKFQLKVMEZWBMCEZHRXRTPLNSXZAOKFTBZXEJYIZJYWMBGFVCHSPQZJVIQGNRJASENZUIANHAPLTKQUWRMTMXWXLDTOMOPAMSHRNWBGPAOQIPPQAHLBKZBJFGBJQVONCSPYDMUHRHUXYZEPH");
    msg.value.assign("IVIVRXUIWJPGQWEREAQSIUEXENBMMWTSYJNIXRVPKTUAVNKNPXYQKDIBCJOITUKSECLRBMREZMLFPOMSALGONCZYJBTYQABOVPSCLHYOYYHAEGKFQYUTLAGHXIAFHTDJPYXJSOVCAVMQFOZNMTUKZDHWQHCDFZLZSUJZCXGKCGIOWHRSKGXQPG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Parameter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Parameter msg;
    msg.setTimeStamp(0.82225541203);
    msg.setSource(52485U);
    msg.setSourceEntity(178U);
    msg.setDestination(19604U);
    msg.setDestinationEntity(206U);
    msg.section.assign("ADCFKGLMKHDHILVWZDUOOSSGGQSKXAKBMZJJSYBYSTREEKLLRXTRRFZVHWZJDAXFWJMWMFAJYEDEMDENROASGIXQPIWDMCAEQVAJ");
    msg.param.assign("OEMVGFTOWFHCSPVLQMWUVDTNLLGSJJXHYLZYBWEMGUSKPPXCRIQAPYUWXKTESNKGZBRHUNKXJXQCAIMXXVLIWDLESYTPJKCVLLSOEJKSMRYBELOKUZRBCZGICQWJEACLHDJBTMHHZHEDFSUDPJWASENRPYCSNOWGAZMVBRQMIAXFATFPKBVTBQJIYYHFNYOUMIBPKFCMUHABDTEPQZVAGJAFIRTDINOROGOUNZNVXRRQCGTQYKVNHFFUDWQ");
    msg.value.assign("IDOSYFBGQPSJRESLLJAZWKFLHUTNHRILCVQTUVHYTBKOEPEHEYFLJNSUZREFOQRAHNSAYHCGHRXOBDZFXINLOSJXKPWCOAORQGMJSGRBPTQW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Parameter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Parameter msg;
    msg.setTimeStamp(0.132814457766);
    msg.setSource(61770U);
    msg.setSourceEntity(159U);
    msg.setDestination(16337U);
    msg.setDestinationEntity(120U);
    msg.section.assign("DBQHLXZQWPXMTQTYKBFYKARESLSWTJCZNJSZNGNBNRWWLYJLUINQSOIMIZBNSGQODQYPURVDYBMVCERLHTIUFFHPTUAPXTWHQAHQJAGYNELFIZIWGCPUEXDENSGCWEAJCTHYKVRTVXKZPAWNCTZDSPUAHIEPV");
    msg.param.assign("FSGDYPSZLFPSQAJOSUDVREQOAKHLCGGWDEMRXJJLJDNKPQKZLYYBVWASLOFPBXPCBQOYTX");
    msg.value.assign("FZOWALBSGDYFDRFBPSH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Parameter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ParameterControl msg;
    msg.setTimeStamp(0.0970563966432);
    msg.setSource(47360U);
    msg.setSourceEntity(41U);
    msg.setDestination(34149U);
    msg.setDestinationEntity(85U);
    msg.op = 11U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ParameterControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ParameterControl msg;
    msg.setTimeStamp(0.0244500484491);
    msg.setSource(61063U);
    msg.setSourceEntity(246U);
    msg.setDestination(12317U);
    msg.setDestinationEntity(103U);
    msg.op = 34U;
    IMC::Parameter tmp_msg_0;
    tmp_msg_0.section.assign("PNNJYNDWWOROSEERIJJEASHYTBALBICXIUZVDRSRATRQBMURPDNONIMCBNZWSAZGVWFIKCAVQWMMPFEHWVTQQEGWTPTFJXFXSHTODKFGQBPUTMVYKZBZYMUQMOPDVCHYLJYMZTXLHFELULDEULYNYVZOGCONHFOIASSQPPRMTFABVAHFXCQXMWNGUBBOQPRRXJIESPZNJHEGHUSDIKDDQCCCBJJGXVKLLIKYVTWUGSZURXKAGXKFZ");
    tmp_msg_0.param.assign("TJAAIKBQFSVSKCVMOJGSRHSDAKJBXUFGQMOELALYCIZTZMBQSVQXOQRGILNDMKBXUFISONDDZNZFHUDCJHAJMJIYUHXXPPRPUXLOWCYNYBFZYNTBKMZCBSRCQITPOLDIYHPEETOYWTRXNZFQWLBKIEIVVRURMECFSNAWEBUTTQWGWJJKJSTGUBSWDLJUEVWKZGGLXGZG");
    tmp_msg_0.value.assign("PDPBTXFFEIHQLLXCBNICUYLN");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ParameterControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ParameterControl msg;
    msg.setTimeStamp(0.828080772426);
    msg.setSource(2453U);
    msg.setSourceEntity(48U);
    msg.setDestination(29469U);
    msg.setDestinationEntity(35U);
    msg.op = 60U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ParameterControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationControl msg;
    msg.setTimeStamp(0.400894890989);
    msg.setSource(59144U);
    msg.setSourceEntity(214U);
    msg.setDestination(54538U);
    msg.setDestinationEntity(77U);
    msg.op = 23U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationControl msg;
    msg.setTimeStamp(0.459376717026);
    msg.setSource(1594U);
    msg.setSourceEntity(125U);
    msg.setDestination(63912U);
    msg.setDestinationEntity(231U);
    msg.op = 38U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationControl msg;
    msg.setTimeStamp(0.0209858291839);
    msg.setSource(25347U);
    msg.setSourceEntity(24U);
    msg.setDestination(12231U);
    msg.setDestinationEntity(50U);
    msg.op = 121U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationState msg;
    msg.setTimeStamp(0.162803393045);
    msg.setSource(62256U);
    msg.setSourceEntity(60U);
    msg.setDestination(19252U);
    msg.setDestinationEntity(69U);
    msg.total_steps = 243U;
    msg.step_number = 90U;
    msg.step.assign("FJUTHSGJTAIPFVXLHNCWKVGZMPSJHGBNYQFMTRNKMDRBQCJSLQKFOBBHNQDKDSDVRYRPOOKALUEOKEPLSIZRYWTIXKU");
    msg.flags = 202U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationState msg;
    msg.setTimeStamp(0.0710329651369);
    msg.setSource(48641U);
    msg.setSourceEntity(231U);
    msg.setDestination(39198U);
    msg.setDestinationEntity(194U);
    msg.total_steps = 81U;
    msg.step_number = 213U;
    msg.step.assign("TNOXCUUERFZMHJRMXBNLPTJVPAJZOKUOLSLAVUDTVTXQBESLMZYDJJHCBSXQYLPWFXCIHRPENQYJGDISSBWYRGSQHIAGDWMPPGGGTOARAKQBOKPVFNEIFONQKVNGIVANMFUSNKJDKZZQZKXAIGHRIUTUDZCLFEOEJHWGSPYRZWYCCUMPYDNLOTWESHIWJLKUKALXXFQTULAVQYOERDEHPBCCBRXQMWVRZJYTHIKNS");
    msg.flags = 103U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevCalibrationState msg;
    msg.setTimeStamp(0.0938142630222);
    msg.setSource(24661U);
    msg.setSourceEntity(241U);
    msg.setDestination(54020U);
    msg.setDestinationEntity(89U);
    msg.total_steps = 156U;
    msg.step_number = 251U;
    msg.step.assign("SCLMFYFPCXEQHXXSHEBIBWKKPYBISNTGVARQOJVKIMZUVBHPNPVNHDTTBVMZKQSZOJJLDKTGASOQGQDTJGEWMUIWFYNZECZPLNWJFUNMMHSUMARBXCOJZTYYRUZMDLOGIQHQBEARTAALKYOOPTQSFPWGVINMIIBHVOOROVUWBADMURCQHJINUEEDPCKJCGYSRYYGTFEDSXXVFRZXLGELJAERXFUBA");
    msg.flags = 80U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevCalibrationState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityActivationState msg;
    msg.setTimeStamp(0.584975069524);
    msg.setSource(11064U);
    msg.setSourceEntity(163U);
    msg.setDestination(49505U);
    msg.setDestinationEntity(158U);
    msg.state = 58U;
    msg.error.assign("DFCCCODSSQZYTTZKYXDWNNPRLFMRHYEHVAKLUEVXDRSGLBUITUBMOIROSKZICLHLJQPCECDTVQYAOGPVRZKXNPYEKOMJHHJZWFKWDV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityActivationState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityActivationState msg;
    msg.setTimeStamp(0.960512865573);
    msg.setSource(39408U);
    msg.setSourceEntity(179U);
    msg.setDestination(50532U);
    msg.setDestinationEntity(39U);
    msg.state = 147U;
    msg.error.assign("YTDHGGKZMAZZOVEEYMEHPXPILQHMCUTFIFFJKCSBJXAYIAMONDXOVXNSJRWQUFCTEUDWICVVRKUUAMGLYLLHCLEFKGWZTXYEYOQYWLOWDPOFZBDVPZNKOHNTURPGUJHJAWNIMZLGTRBMDJLELBDRGEPYZNKVSLWCFNAANKETAUBBCKVTXFOQIYFZGWXXUHIRPMCQMHRNBRPGERFHAWQXYVQSPIRSIVKQSCVJABH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityActivationState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityActivationState msg;
    msg.setTimeStamp(0.311708633103);
    msg.setSource(63443U);
    msg.setSourceEntity(59U);
    msg.setDestination(44501U);
    msg.setDestinationEntity(79U);
    msg.state = 7U;
    msg.error.assign("IOEGLMQUXDIEUSIWJDOLZTUCIFZULQOCAOCKSXNILBOLQKHMCFWNQPYEAUKHVGMEDPCBWNKWMIJSZZRWWRAYSRFXGFILOGPPJDLASEQBRKJVHTUNREGHTJAPXVXRQAUFKNWYZRSXFPVFTMEYZJCTYSLLVAGBNGDETNAVTGXV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityActivationState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimulatedState msg;
    msg.setTimeStamp(0.498123830052);
    msg.setSource(32805U);
    msg.setSourceEntity(47U);
    msg.setDestination(45716U);
    msg.setDestinationEntity(236U);
    msg.lat = 0.911088962283;
    msg.lon = 0.250642793547;
    msg.height = 0.352933689427;
    msg.x = 0.199477355624;
    msg.y = 0.52020520431;
    msg.z = 0.523487827463;
    msg.phi = 0.584636020029;
    msg.theta = 0.759360843175;
    msg.psi = 0.13508376834;
    msg.u = 0.667195010378;
    msg.v = 0.559782214469;
    msg.w = 0.761254252691;
    msg.p = 0.363952609191;
    msg.q = 0.186627390561;
    msg.r = 0.633018929251;
    msg.svx = 0.155432728861;
    msg.svy = 0.980607846205;
    msg.svz = 0.545723837278;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimulatedState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimulatedState msg;
    msg.setTimeStamp(0.878007829883);
    msg.setSource(42823U);
    msg.setSourceEntity(136U);
    msg.setDestination(22173U);
    msg.setDestinationEntity(118U);
    msg.lat = 0.527586448808;
    msg.lon = 0.73688257669;
    msg.height = 0.199802630305;
    msg.x = 0.845081935073;
    msg.y = 0.862384266061;
    msg.z = 0.578093798552;
    msg.phi = 0.626521661451;
    msg.theta = 0.293058556624;
    msg.psi = 0.456719271246;
    msg.u = 0.115023705651;
    msg.v = 0.593195478121;
    msg.w = 0.263950763966;
    msg.p = 0.00896317794905;
    msg.q = 0.649940810564;
    msg.r = 0.780845252842;
    msg.svx = 0.728245530688;
    msg.svy = 0.812546968421;
    msg.svz = 0.769642898391;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimulatedState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SimulatedState msg;
    msg.setTimeStamp(0.608195960904);
    msg.setSource(2726U);
    msg.setSourceEntity(91U);
    msg.setDestination(39322U);
    msg.setDestinationEntity(61U);
    msg.lat = 0.352947118838;
    msg.lon = 0.837949343951;
    msg.height = 0.306423362529;
    msg.x = 0.833185839203;
    msg.y = 0.313134200634;
    msg.z = 0.170117177233;
    msg.phi = 0.300902000771;
    msg.theta = 0.690729160582;
    msg.psi = 0.833670805453;
    msg.u = 0.101741367102;
    msg.v = 0.0883726838966;
    msg.w = 0.0588328132;
    msg.p = 0.705349440081;
    msg.q = 0.733555900498;
    msg.r = 0.591597560941;
    msg.svx = 0.729408282362;
    msg.svy = 0.424888170848;
    msg.svz = 0.780483807401;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SimulatedState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeakSimulation msg;
    msg.setTimeStamp(0.196662034187);
    msg.setSource(28395U);
    msg.setSourceEntity(227U);
    msg.setDestination(2136U);
    msg.setDestinationEntity(223U);
    msg.op = 167U;
    msg.entities.assign("MGRKSYVPPNDRSGOFPWQNHZLRSZEIRCDRSNRRBMOSDQATLZXGUVSJPUXQUKQCISYWDPZHGCMOLTYGONFKEVRUNBXROHCFFBBXHPWLEFHFEJYUTTQGYQYFDJNWVUMDXGMTKBS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeakSimulation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeakSimulation msg;
    msg.setTimeStamp(0.431300965439);
    msg.setSource(14117U);
    msg.setSourceEntity(114U);
    msg.setDestination(40452U);
    msg.setDestinationEntity(170U);
    msg.op = 230U;
    msg.entities.assign("JLRNLYWTJLZBYFMXX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeakSimulation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LeakSimulation msg;
    msg.setTimeStamp(0.960168961308);
    msg.setSource(63640U);
    msg.setSourceEntity(50U);
    msg.setDestination(15249U);
    msg.setDestinationEntity(21U);
    msg.op = 200U;
    msg.entities.assign("ZUZIHECTYUKGSPNURJDWNRJAIZKWJXLENBDLFJPEOGUZKSQYDTAVNXMVBVILMPCLLYLQLZLVQBDMDKOMMRAYZQCGXWTPQJQIQVIGHFOJRXIOERRAODFCJFQRYEUPASNJZVYCPXGZOMZSTPCVSVHEEFJIIWWPEBGBKMCBLHEBYAUQXTHDFXUXATQVWDGKYGKNHNDKMNUFT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LeakSimulation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UASimulation msg;
    msg.setTimeStamp(0.489246680851);
    msg.setSource(59405U);
    msg.setSourceEntity(149U);
    msg.setDestination(62846U);
    msg.setDestinationEntity(243U);
    msg.type = 212U;
    msg.speed = 47812U;
    const char tmp_msg_0[] = {94, 37, -15, 103, -46, -17, -100, -54, -69, -91, -97, 7, -104, -25, 126, 37, 39, -63, 36, -114, -128, -10, -106, 59, 59, 93, -104, 113, -25, -22, 95, 120, -12, 63, -53, -17, 89, 114, 126, -29, 119, -111, 63, -85, -88, -4, 22, -37, 71, 62, 56, 8, 16, 68, -60, 1, 70, 5, -67, -17, 76, 12, -7, 23, -26, 32, -97, -82, -18, -4, -32, -87, -108, 19, -47, 86, 115, 115, -29, -80, -9, 63, 15, 86, -72, 53, 104, -125, 5, 19, -104, -119, -59, -6, -73, -15, 49, 93, -104, -41, 68, -22, 50, 70, -101, 36, 74, -89, -96, -84, -86, 81, 41, 41, 102, -89, 63, 10, -92, 34, 58, 63, -76, 43, -81, 109, 9, -12, -40, 100, -31, -37, -119, -99, -79, -23, 73, -43, 58, -10, -57, 107, -71, 53, -93, -36, 19, 33, -102, 89, 82, -1, -61, -66, -42, 124, 90, 96, 82, 30, 15, 36, 4, -126, -31, 59, -106, 32, -79, 61, -16, -94, 86, -95, -102, -72, 107, -94, 114, -57, 19, 55, 65, -72, -28, -107, -80, -123, -61, -7, -74, 18, 26, -11, -120, 116, -78, -46, -1, 10, 96, -25, -103, 17, 35, -42, -87, -7, 108, 74, 29, 56, -59, 12, -106, -81, -8, 13, -119, -86, -31, 77, 21, -53, 22, 35, 119, 119, 64, 120, -24, 56};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UASimulation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UASimulation msg;
    msg.setTimeStamp(0.353760241239);
    msg.setSource(32490U);
    msg.setSourceEntity(135U);
    msg.setDestination(21426U);
    msg.setDestinationEntity(34U);
    msg.type = 130U;
    msg.speed = 29758U;
    const char tmp_msg_0[] = {95, 68, -63, 70, -97, -30, -97, 1, -126, 20, -35, 21, -121, -21, 35, 100, -99, 120, 38, 86, -67, 5, 0, -33, 77, 126, -99, 77, 79, -32, -107, -44, -74, -84, 61, -2, 18, 105, 41, 100, 82, -120, -79, -54, -61, -76, 67, 20, -102, -22, 109, -101, -67, -16, -61, -94, -84, 10, -16, 30, 6, -74, -70, -40, 118, 119, 33, 42, -6, 21, -112, 58, -50, 15, -39, 50, -114, 77, -48, -48, -86, 68, 100, 126, -36, 109, -70, -67, 10, 27, 6, 52, 68, 74, -62, -35, 37, 84, -46, 23, -60, -31, -104, 120, -125, 89, -79, -57, 25, -77, -112, -110, -94, 5, 67, -68, -112, -102, -36, 60, -115, -48, 18, -8, -22, 87, 95, 104, 100, -10, 36, -108, 11, 40, -51, 6, 13, -80, -19, 119, 20, 37, -87, 43, -86, 85, -70, 68, -20, 107, -90, -20, 17, -48, -46, 87, -69, -29, -44, 67, -121, -19, -68, -121, 3, 126, -63, -10, 104, -119, -37, -39, 15, -89, -72, 108, -106, -53, -67, -50, 25, 26, 94, -77, -4, 63, 115, 126, -104, 77, -99, -98, 7, -111, -64, 125, 104, -98, -30, -110, -22, 33, 101, 51, 48, 67, 32, -49, 6, 125, -89, 113, 10, 42, 84, 124, 41, 14, -12, 51, -110, 13, 62, -18, 43, 111, -16, -112, 17, -31, -49, -91, 6, -30, 35, 9, 23, -118, 10, 17, 24, -70, 56, 37, 87, -49, 47, -31, -67, -28};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UASimulation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::UASimulation msg;
    msg.setTimeStamp(0.260006609813);
    msg.setSource(45865U);
    msg.setSourceEntity(91U);
    msg.setDestination(46171U);
    msg.setDestinationEntity(208U);
    msg.type = 44U;
    msg.speed = 55496U;
    const char tmp_msg_0[] = {64, -47, -6, 64, 109, -43, -81, -14, 66, 123, 30, 121, 126, -93, 119, 78, 18, -37, 114};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("UASimulation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StorageUsage msg;
    msg.setTimeStamp(0.440292365875);
    msg.setSource(34271U);
    msg.setSourceEntity(190U);
    msg.setDestination(4385U);
    msg.setDestinationEntity(235U);
    msg.available = 3544089752U;
    msg.value = 148U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StorageUsage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StorageUsage msg;
    msg.setTimeStamp(0.148514107811);
    msg.setSource(49531U);
    msg.setSourceEntity(184U);
    msg.setDestination(27532U);
    msg.setDestinationEntity(213U);
    msg.available = 737225952U;
    msg.value = 45U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StorageUsage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StorageUsage msg;
    msg.setTimeStamp(0.286240593361);
    msg.setSource(15775U);
    msg.setSourceEntity(189U);
    msg.setDestination(51648U);
    msg.setDestinationEntity(173U);
    msg.available = 1753754264U;
    msg.value = 73U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StorageUsage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CacheControl msg;
    msg.setTimeStamp(0.30151748966);
    msg.setSource(49271U);
    msg.setSourceEntity(102U);
    msg.setDestination(60974U);
    msg.setDestinationEntity(225U);
    msg.op = 34U;
    msg.snapshot.assign("QSCJOFJMOYOULOCFICEGUFOFHNACVXRIQSHQOQLCJTTZVUFBMWXXHHLLZRJGPJWRWWXHYFEHMPZGSKGBUZFIIVIMUDVHZNKESKKMBZDSATKJYFNBVWVLAHAZKWOEGOPYUQGYXMYGTZEATJKTUBRXDRIILRENE");
    IMC::FollowPath tmp_msg_0;
    tmp_msg_0.timeout = 51971U;
    tmp_msg_0.lat = 0.040562226036;
    tmp_msg_0.lon = 0.805636108674;
    tmp_msg_0.z = 0.496646428404;
    tmp_msg_0.z_units = 104U;
    tmp_msg_0.speed = 0.0601896700482;
    tmp_msg_0.speed_units = 46U;
    IMC::PathPoint tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.x = 0.0885477379277;
    tmp_tmp_msg_0_0.y = 0.802724925687;
    tmp_tmp_msg_0_0.z = 0.947771769887;
    tmp_msg_0.points.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.custom.assign("ORTVFPIRKFCBFHZQZSVWOWPYAHIQPJYOVXAUGIAPXDEXQAIYAWYGXYOIESTIFYMPCMJMWFDJRXBVESBORZNJRWQRLDZEHVJSNQCLDUJIGBMNOFSITKDMUYDUKSCBEXPHTARJMSFWVENFTGLUTELUKTQPRLZFHHETEZ");
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CacheControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CacheControl msg;
    msg.setTimeStamp(0.0870676853486);
    msg.setSource(44037U);
    msg.setSourceEntity(106U);
    msg.setDestination(39349U);
    msg.setDestinationEntity(171U);
    msg.op = 200U;
    msg.snapshot.assign("ZMOTGUFSLEEOTPQURNZPWKL");
    IMC::Pressure tmp_msg_0;
    tmp_msg_0.value = 0.959570848316;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CacheControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CacheControl msg;
    msg.setTimeStamp(0.504952732044);
    msg.setSource(25941U);
    msg.setSourceEntity(4U);
    msg.setDestination(6529U);
    msg.setDestinationEntity(200U);
    msg.op = 80U;
    msg.snapshot.assign("SEGOANZIRGPCPRIQWSRTBJBEJVDBBUCQFPFPOHXUZSSQPEGXQKDZRTKOIMWZJNKZBLNXXRZEDDJJYWYFGGXMHGPYHYCVNBBTTEQVLCCRUYHINWXDFFLTAHNCLUOXHMUANOPQLFBANRAQFYEZKLIVHMKSFQRWAKLQKWCEFYDUTXLTPJKUOPDJTVZGBKOJYUPDSMMQYHZBWEDCSVWRO");
    IMC::GpsFix tmp_msg_0;
    tmp_msg_0.validity = 22709U;
    tmp_msg_0.type = 31U;
    tmp_msg_0.utc_year = 30214U;
    tmp_msg_0.utc_month = 110U;
    tmp_msg_0.utc_day = 23U;
    tmp_msg_0.utc_time = 0.589366811221;
    tmp_msg_0.lat = 0.0167201340841;
    tmp_msg_0.lon = 0.269809421492;
    tmp_msg_0.height = 0.0150673408286;
    tmp_msg_0.satellites = 154U;
    tmp_msg_0.cog = 0.832178335723;
    tmp_msg_0.sog = 0.388570540989;
    tmp_msg_0.hdop = 0.26800570983;
    tmp_msg_0.vdop = 0.824250075771;
    tmp_msg_0.hacc = 0.620837165983;
    tmp_msg_0.vacc = 0.263662897997;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CacheControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LoggingControl msg;
    msg.setTimeStamp(0.632261176291);
    msg.setSource(46169U);
    msg.setSourceEntity(125U);
    msg.setDestination(45036U);
    msg.setDestinationEntity(44U);
    msg.op = 253U;
    msg.name.assign("PRPWHSSGKNDANHTJZZPDXZCIYBMZPYOKMVGPKASBBPXMUIVODXDEFUGMLQQMNINYJGCEPLCOTY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LoggingControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LoggingControl msg;
    msg.setTimeStamp(0.152895057559);
    msg.setSource(51273U);
    msg.setSourceEntity(80U);
    msg.setDestination(63040U);
    msg.setDestinationEntity(198U);
    msg.op = 16U;
    msg.name.assign("JFDUOBDPKJXNAYLGGTXFDCLGFMNGVEMLCSDOBIYIDYJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LoggingControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LoggingControl msg;
    msg.setTimeStamp(0.201139198511);
    msg.setSource(24197U);
    msg.setSourceEntity(164U);
    msg.setDestination(40412U);
    msg.setDestinationEntity(146U);
    msg.op = 52U;
    msg.name.assign("LPGZOXCUIHWUUHEYYTXFWVTXBTZCKUIDQLPRLYNAMRTKXFJGBJEGPMOKYHDRQXQIYMAJQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LoggingControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookEntry msg;
    msg.setTimeStamp(0.282269732191);
    msg.setSource(62458U);
    msg.setSourceEntity(252U);
    msg.setDestination(35677U);
    msg.setDestinationEntity(83U);
    msg.type = 22U;
    msg.htime = 0.729825990901;
    msg.context.assign("OSNBTDXGLXHRUSGJFBNMFYWVFQSXXBTCWEMVJLAQLGORXBNPDHOFCZCUDRUQHGGQOVGNKEJUSAEUFGX");
    msg.text.assign("NFBZQVNFGYLRTMURBSTWUFCVTJEDQAVENIIUPAJXOMMKALTZCFDRTKEGJNBXMYGKAMGWLDXXPYSJDUISQIII");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookEntry #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookEntry msg;
    msg.setTimeStamp(0.814148179015);
    msg.setSource(54281U);
    msg.setSourceEntity(27U);
    msg.setDestination(35928U);
    msg.setDestinationEntity(58U);
    msg.type = 240U;
    msg.htime = 0.170449507555;
    msg.context.assign("TUDVMMSIPXRBGIEKOTYEYRNADZASFJPBKUQGOLKEXKZQUGMCJHSYTDNTKGZIEXEODHWLEKIKUCOOAMLSVRHVFQTWJCFRSOQUPHIPXPWYYTMLQZGOONMNKFXSZZFZEWBVMPUGAHMDNVKQNWPYSBCCEXFWBIBACBPUNXMDBIWLJLASCEDQNBIJLIRTEYDAXMDVPNYRCQHSGJZVHZVKJWHANXV");
    msg.text.assign("IRFWUPGHELEQFLADYPGIASXLBLRUERQUACKNUHJHMFPFPISIUZKI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookEntry #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookEntry msg;
    msg.setTimeStamp(0.740916230346);
    msg.setSource(47422U);
    msg.setSourceEntity(35U);
    msg.setDestination(30471U);
    msg.setDestinationEntity(121U);
    msg.type = 32U;
    msg.htime = 0.0530531849782;
    msg.context.assign("IZPGZDMKFKWJUFWMRELYDAUXRADCAQNLTOQWXRENIPQAOYZDYCUPOYBTUCMJOJNLWVBQWIXGJHPVVHVLDXWPEKGSUUUBVSAESPWIKQYAFIKVDDBHCTSQQJGLCAZBYMGMRFTSUEPGRTGZBNNOHJQRSYWZLTTFOVWOBXNJUNHXLTRMIZECGLFASHBOPZODWCGEMGAHVFKAVKHERTLSEPTDXBQZRLIUBJY");
    msg.text.assign("NPVXNMIMMEFGEZAMSFH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookEntry #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookControl msg;
    msg.setTimeStamp(0.29770679855);
    msg.setSource(45601U);
    msg.setSourceEntity(192U);
    msg.setDestination(36220U);
    msg.setDestinationEntity(106U);
    msg.command = 65U;
    msg.htime = 0.534956059415;
    IMC::LogBookEntry tmp_msg_0;
    tmp_msg_0.type = 246U;
    tmp_msg_0.htime = 0.395903507379;
    tmp_msg_0.context.assign("IBAFEQBTLKOFLMYPEUHZHDZQPZMMROBUSJJXMWNXFZUWZCXJAMRLIQEOGSETYIGCTQHCMURBZLUGDDITDCDYMNGUQCEWPBSQAWAFNFBRKGGPVESOXSOWKAAYHTPFKPAJTJDEWKR");
    tmp_msg_0.text.assign("PUQAAOAFSIRTPGBLAZTXRYBOTPWVCZXIEHLLWFJZDOGRJUTMJLYCNYHQJZVVYFPUXXGXZKGYQWLDYUHFQHPFLZVISPIMCIOERNXEHNSQKCFNQTVDBKRAPRSHMQDLHKICQGLTCPIEBHNSZGQRACONUUWFNKATMSADSDEDBVYRFXKSKOBJWFZMVPUWMTBCDXWMKBKOEMLEBDMWLCNVFYRIVIGESJPWORJBSXD");
    msg.msg.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookControl msg;
    msg.setTimeStamp(0.846397150578);
    msg.setSource(27631U);
    msg.setSourceEntity(51U);
    msg.setDestination(33950U);
    msg.setDestinationEntity(178U);
    msg.command = 145U;
    msg.htime = 0.93890845685;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LogBookControl msg;
    msg.setTimeStamp(0.0475811171679);
    msg.setSource(11288U);
    msg.setSourceEntity(55U);
    msg.setDestination(64965U);
    msg.setDestinationEntity(206U);
    msg.command = 142U;
    msg.htime = 0.656419174304;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LogBookControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReplayControl msg;
    msg.setTimeStamp(0.950229903859);
    msg.setSource(24797U);
    msg.setSourceEntity(229U);
    msg.setDestination(4117U);
    msg.setDestinationEntity(249U);
    msg.op = 195U;
    msg.file.assign("FXFJOONBBMAQYPNIZPPOZWBXCCTZXXKAOMUQVGRPGBJTQNLBKNUZNIJJSSHLFCZRIZLJYUSGEQWYXKPWUYTZDXTUBAVKRPGUCHNPAGTCJLFQZKJMAADXAMKOBUSWZSNURXWWRQVMYQFINHVIEWRYBBIAFVWIVDEPLRWDHTVFHS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReplayControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReplayControl msg;
    msg.setTimeStamp(0.0886289923144);
    msg.setSource(19711U);
    msg.setSourceEntity(9U);
    msg.setDestination(60340U);
    msg.setDestinationEntity(175U);
    msg.op = 164U;
    msg.file.assign("GZEUSPIYCIIGLSVLYYGFDVTHHSCJASLA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReplayControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReplayControl msg;
    msg.setTimeStamp(0.635255131414);
    msg.setSource(18038U);
    msg.setSourceEntity(222U);
    msg.setDestination(36248U);
    msg.setDestinationEntity(53U);
    msg.op = 21U;
    msg.file.assign("NBZPKEHOTOZRPLHGWVZCXTPIRPRGBRFDJHWDTKSGRTVIJKJMNHLAFJLLWSAZZINQYUIFBCMCOXATXUEJYFEZDUGMSOOLOXCGFBEZWYHJDXXKDAPYVKITQSBZNEOIBTACSVSHNLICGTCRDYAPEUWDZKKPNEVYUMGLFBSKJTAKUBWNUNYHKEVITODNYBVXQINEGQLOWVSOYSAXRFJAVCMZGHJQBRQUWQLRMAIMGDHMCPWRXLFMXSFMPYFWUDVQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReplayControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ClockControl msg;
    msg.setTimeStamp(0.854772040785);
    msg.setSource(50229U);
    msg.setSourceEntity(139U);
    msg.setDestination(23494U);
    msg.setDestinationEntity(25U);
    msg.op = 228U;
    msg.clock = 0.800986828527;
    msg.tz = -101;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ClockControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ClockControl msg;
    msg.setTimeStamp(0.702712822887);
    msg.setSource(16941U);
    msg.setSourceEntity(139U);
    msg.setDestination(64047U);
    msg.setDestinationEntity(65U);
    msg.op = 44U;
    msg.clock = 0.9673535537;
    msg.tz = 86;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ClockControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ClockControl msg;
    msg.setTimeStamp(0.694649577038);
    msg.setSource(41700U);
    msg.setSourceEntity(132U);
    msg.setDestination(13826U);
    msg.setDestinationEntity(246U);
    msg.op = 105U;
    msg.clock = 0.223503145878;
    msg.tz = 36;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ClockControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Heartbeat msg;
    msg.setTimeStamp(0.267564722827);
    msg.setSource(30575U);
    msg.setSourceEntity(126U);
    msg.setDestination(16705U);
    msg.setDestinationEntity(143U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Heartbeat #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Heartbeat msg;
    msg.setTimeStamp(0.614969290237);
    msg.setSource(29458U);
    msg.setSourceEntity(77U);
    msg.setDestination(24199U);
    msg.setDestinationEntity(68U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Heartbeat #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Heartbeat msg;
    msg.setTimeStamp(0.692430790176);
    msg.setSource(18774U);
    msg.setSourceEntity(215U);
    msg.setDestination(39443U);
    msg.setDestinationEntity(5U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Heartbeat #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Announce msg;
    msg.setTimeStamp(0.725991602471);
    msg.setSource(58018U);
    msg.setSourceEntity(81U);
    msg.setDestination(49805U);
    msg.setDestinationEntity(228U);
    msg.sys_name.assign("HPYNJESZSBXYDDVRNHMYPEFCUKZLPMHNLBOKAXQUDTYREGUVVJAPOIX");
    msg.sys_type = 199U;
    msg.owner = 32124U;
    msg.lat = 0.880666885665;
    msg.lon = 0.840628559413;
    msg.height = 0.973824058956;
    msg.services.assign("LMSDDYBZBDXAVGKDWMFUXIEACBPJOKVHGIJQORCRSWGYPNUELDNWGSNMJKFYW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Announce #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Announce msg;
    msg.setTimeStamp(0.189436671119);
    msg.setSource(10768U);
    msg.setSourceEntity(136U);
    msg.setDestination(65181U);
    msg.setDestinationEntity(117U);
    msg.sys_name.assign("OQDXWPSOVQCWVTVJSXDEYADADOPHAJGBLAHIBMOZXMKJFIJOSGOVGIPENYYVCWOEBMLXHNUTRCZWGULXLNVMLYXGJFIUTXCFHHNZDFPRBISPAPAURMBPTNJETPJIVEKGUVFRJMHSLQSGADQMQUYRXDFLCMKQLWIHEFKHIWFANUBKLWSZADEKC");
    msg.sys_type = 12U;
    msg.owner = 12525U;
    msg.lat = 0.263308682324;
    msg.lon = 0.324308544842;
    msg.height = 0.568739047948;
    msg.services.assign("WGXHHQIKSSODMLKDLZINHGMHHWBROYKFUISFXUHOXZVCQERMLXVVVXOYYILSPAKWZFINQQTSCGICJUZEZJPBBXJEFEWOLFFSHLHJPLKMUOCVZQJGWIABAYQVGRPFRNQPSDDKEMCTYTBRNIJHTDOKNDNPUONPWPRV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Announce #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Announce msg;
    msg.setTimeStamp(0.985691406688);
    msg.setSource(59322U);
    msg.setSourceEntity(125U);
    msg.setDestination(40611U);
    msg.setDestinationEntity(173U);
    msg.sys_name.assign("CCLHZPUOBGNTDXZLZFNEUBWEUKQCDAJXRIKKMYFFABERIEBGNWIVTUQMWVNTYYLGLCFNVDSOHQKFVIDYTDPOYNFODPRTWNBBOWJWRQZQDXLEYAYNUIGPGSEPDVLPUXVZJUJWMRUNOZA");
    msg.sys_type = 192U;
    msg.owner = 1169U;
    msg.lat = 0.434613508935;
    msg.lon = 0.727700210849;
    msg.height = 0.528123382918;
    msg.services.assign("NVGBVAVHSZFXFPPAPRDONEHSJAYYADPIGFMOSPYIKBBRIJTGIECUUHQCMJWBWQOEAVWRJJXTFDAKKUJHFXDIINVLWAMCTGIROXPQHLLSWUKMGCVQNEEZDWWYBWJTKQZLQUOSDVYVUXUGIWFAFIYCTAFMHCMXPERHQJLMZSYBHZZHBJCPJOFKDGMFTXXORGEATLYMHPSLRNUNYEEREUNKLLNYGOZZBSQCSVRKTIPXDNKSDLBUDOTQB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Announce #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AnnounceService msg;
    msg.setTimeStamp(0.916340365284);
    msg.setSource(13823U);
    msg.setSourceEntity(229U);
    msg.setDestination(35567U);
    msg.setDestinationEntity(209U);
    msg.service.assign("LZRENFGIJTGFJIDOJOZSEJNLMNDBNLXSMSTGVJVYSFMXODVSHHPTWGZHNONBDIWGCTVYPZYXXCVXMACTVPORBEZC");
    msg.service_type = 110U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AnnounceService #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AnnounceService msg;
    msg.setTimeStamp(0.337514398933);
    msg.setSource(27966U);
    msg.setSourceEntity(158U);
    msg.setDestination(31991U);
    msg.setDestinationEntity(7U);
    msg.service.assign("KLURKQGMQRRJEULVROZSAAYTKLJDKPZOQFIQWBORHVNAJNDSZIBPZWXAIBHICLXCNKCQRYHCAPYOBBMQBWVHUXNEEACCHJQPPERCLHLIEDTUYQSJMAGYZSKUSXVTUYIADOTSYY");
    msg.service_type = 16U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AnnounceService #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AnnounceService msg;
    msg.setTimeStamp(0.00186292418864);
    msg.setSource(2799U);
    msg.setSourceEntity(241U);
    msg.setDestination(10295U);
    msg.setDestinationEntity(197U);
    msg.service.assign("OBFYDXEDMSUBOCTELUCVBSXAUGOPIPWRJGVZBIDNALDZIKVOECMJRRQOJNOJNTNZHLBEEITWCCWXDZVTJLKYQHIWTKVALCTCMAMRQSXPSYUYFTWFHIOIMOXBLUKXPGRMHYHOWDEMIYLSDYTMZJQSYGUDSBNGC");
    msg.service_type = 185U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AnnounceService #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RSSI msg;
    msg.setTimeStamp(0.830543716625);
    msg.setSource(17034U);
    msg.setSourceEntity(223U);
    msg.setDestination(7134U);
    msg.setDestinationEntity(137U);
    msg.value = 0.512327265836;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RSSI #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RSSI msg;
    msg.setTimeStamp(0.200505523484);
    msg.setSource(29099U);
    msg.setSourceEntity(18U);
    msg.setDestination(7971U);
    msg.setDestinationEntity(250U);
    msg.value = 0.609975719024;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RSSI #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RSSI msg;
    msg.setTimeStamp(0.620189084268);
    msg.setSource(63991U);
    msg.setSourceEntity(62U);
    msg.setDestination(44480U);
    msg.setDestinationEntity(95U);
    msg.value = 0.964000153546;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RSSI #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VSWR msg;
    msg.setTimeStamp(0.0667199006864);
    msg.setSource(28077U);
    msg.setSourceEntity(26U);
    msg.setDestination(53997U);
    msg.setDestinationEntity(245U);
    msg.value = 0.0144991315974;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VSWR #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VSWR msg;
    msg.setTimeStamp(0.0877107656652);
    msg.setSource(7756U);
    msg.setSourceEntity(216U);
    msg.setDestination(31608U);
    msg.setDestinationEntity(163U);
    msg.value = 0.421501817573;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VSWR #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VSWR msg;
    msg.setTimeStamp(0.119432647276);
    msg.setSource(8828U);
    msg.setSourceEntity(53U);
    msg.setDestination(63838U);
    msg.setDestinationEntity(49U);
    msg.value = 0.241033821937;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VSWR #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLevel msg;
    msg.setTimeStamp(0.830742211323);
    msg.setSource(28045U);
    msg.setSourceEntity(63U);
    msg.setDestination(24841U);
    msg.setDestinationEntity(162U);
    msg.value = 0.983378628243;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLevel #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLevel msg;
    msg.setTimeStamp(0.468792681574);
    msg.setSource(23096U);
    msg.setSourceEntity(229U);
    msg.setDestination(65288U);
    msg.setDestinationEntity(148U);
    msg.value = 0.51235141995;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLevel #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LinkLevel msg;
    msg.setTimeStamp(0.800480794444);
    msg.setSource(58931U);
    msg.setSourceEntity(142U);
    msg.setDestination(22692U);
    msg.setDestinationEntity(209U);
    msg.value = 0.854978039814;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LinkLevel #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sms msg;
    msg.setTimeStamp(0.0847896720109);
    msg.setSource(55350U);
    msg.setSourceEntity(92U);
    msg.setDestination(10870U);
    msg.setDestinationEntity(136U);
    msg.number.assign("OSJCJSSXWAXRVDYGYOMPNEHEBDXAWZULEVMGXNYNQCBAKFLNMTFIMBY");
    msg.timeout = 20036U;
    msg.contents.assign("ICPNVEFIHTSWYHKOEJWPVDUKDXQSBZNTLADHRGIWWEWZZATNYBNSVGMAAKQVYTXQNZXUKCCBUGCJLIXJWOQZEFOGEGUPFQCCK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sms #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sms msg;
    msg.setTimeStamp(0.232159758554);
    msg.setSource(8667U);
    msg.setSourceEntity(209U);
    msg.setDestination(566U);
    msg.setDestinationEntity(93U);
    msg.number.assign("QTGEIFAZELYDSLLYPXISAJBSFNFVJDRIFDKCTYJZYPWAAMUFWVTMNRGTDPOXKYNMOOGCQTRLVOHUNPLEMWFHWUVUTSERVRQOLHEFBNBQHGKHOPELYWHKMTCQZXOLVWMCNRSYYDFUJCWGVUAZAOVXESNQHNXDFUQRTEPYBGIIPHAEZMMBKGCRDCBTDALVABZJBOEYJUWIPGMIZFKCCCKLBWVXDUJOKZXIMJNPNXR");
    msg.timeout = 12473U;
    msg.contents.assign("ACXBIROPELABBSQFDEJYGBSWEHZVWEMINRJMDOWZJDQJKQFCVVEPSLEPEOEGPKADHHSSLATUKYDRLRUWJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sms #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Sms msg;
    msg.setTimeStamp(0.121601021914);
    msg.setSource(26171U);
    msg.setSourceEntity(184U);
    msg.setDestination(61674U);
    msg.setDestinationEntity(136U);
    msg.number.assign("RAVKUMVBYVPKQMSCNXGEOKQTZVUHTEIYFNUXCEVJBUQLESBVHJTJJSGIQJLWRAIOHOWYGMRAPSALKLOJYDROFLWBZQRECTHYHTXUXJMXZUBUZWVOXUKDFSMHBDMYBCDGTIBPHLKTBYVLTJSEACEKFJVYDPGQCWZDPFDNSFPNAXZWMGVNAIQPGIQFWZOTJDHINQNORZAXIFKSGARXLRPQCPBWZKNG");
    msg.timeout = 14717U;
    msg.contents.assign("QGYFAXFUGCZUIYDINSQJEXFGNEWDBRDJOBETMNMXMHKA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Sms #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsTx msg;
    msg.setTimeStamp(0.46588760236);
    msg.setSource(61411U);
    msg.setSourceEntity(174U);
    msg.setDestination(24120U);
    msg.setDestinationEntity(89U);
    msg.seq = 1196558526U;
    msg.destination.assign("ADLCSCENQZEJJDLCDOOJFBVKOUQVXTNQJQVVGQTJYTHPWRXDIMVWLOJMAKANFKIRCLFTOXRXKIZYHNSNUWMPORGLYIYIHZHGZGDSODDTQKYFBETYZBWMDARUHTERXIZVUIHMSSJYCSYGMSIGZPPABWHUQXWEPZXRKGFPXMFFBPFIUEVGLEJNHHWMFOYBNBTLPLVSSEWQKBUENRKGEBKDFMCVASBHAIOLDRTZKCQAO");
    msg.timeout = 34476U;
    const char tmp_msg_0[] = {87, 17, -76, -43, 73, 98, 108, -46, -97, 26, -119, -54, 112, 106, -53, -49, 109, 68, -50, -72, -127, 68, -71, 90, 17, 26, -57, 50, -98, -78, 28, 52, 104, 41, -77, -122, 32, 55, -34, 33, 87, -111, 39, -38, -36, 121, -107, -98, 27, -114, 97, 34, -36, -104, 92, 26, 115, 77, -3, -3, -72, -42, 112, 8, -71, -110, 27, 85, 86, 79, -66, 126, 95, -122, -103, -9, -71, 122, -121, -104, -103, 32, -106, -29, -60, -127, 55, 84, 46, -59, -110, 42, -77, -11, -94, 85, -52, -87, 18, 87, 14, 124, 69, 119, -24, -51, -85, -66, -105, -67, 102, -114, -111, 122, -46, 0, 68, -123, -124, 33, -2, -93, -112, -71, -122, -46, -38, -126, -47, 58, -112, 93, 120, -5, -80, 57, 30, 55, -70, -57, -104, -35, 90, 53, -39, -28, -103, 4, 109, -60, -30, 126, 59, 67, 86, -58, 82, 25, -52, 102, -113, 8, -45, 102, 65, -121, -43, -118, -81, -100, -58, -89, 112, 29, 118, -27, -22, -18, 13, -79, -71, -107, 0, -55, -57, -68, 81, -85, -104, 54, -33, 13, 59, -12, 49, 53, 100, 29, -111, 93, -58, 36, -67, 9, 24, 39, -63, -41, 48, 101, -127, -119, 88, 62, 31, 96, 56, 0, -34, -81, 5, -10, 21, 46, -100, 72, 125, -126, 107, 16, -54, -63, -37, -128, 3, -38, 106, 4, -28, 51, 58, -44, -119, 3, -98, 89};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsTx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsTx msg;
    msg.setTimeStamp(0.192438168874);
    msg.setSource(18075U);
    msg.setSourceEntity(142U);
    msg.setDestination(56662U);
    msg.setDestinationEntity(57U);
    msg.seq = 3814145117U;
    msg.destination.assign("PCFKPTASHDMBSVSXJFHUJFBYNCMYZCOCZFIELHSUKPKNDUTFAGVLXRVOTXRNPKLUIGMHOBKRCZHTWGGYUARRUKHNNLWVCYEDRPMWZTEQKLLXFSNWEDJVAPWUNVCOAWGBIQILTRSLKMSGXSMANOHBQHONZMJUAPIOTBKFIXZBBVYDZBWQJNJYZAVHQQKFGQMFEWUBC");
    msg.timeout = 52137U;
    const char tmp_msg_0[] = {43, -40, 69, -61, -23, 1, -43, -62, -12, -32, 80, -90, -4, -6, 126, -77, 11, 88, -34, 28, -5, -23, -8, 63, -85, -78, 29, 63, 39, 59, -117, 59, 76, 32, -92, 114, 73, -114, -104, 55, -1, 31, 117, -108, -37, 41, -22, -114, 49, 121};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsTx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsTx msg;
    msg.setTimeStamp(0.773588733736);
    msg.setSource(52435U);
    msg.setSourceEntity(185U);
    msg.setDestination(39488U);
    msg.setDestinationEntity(180U);
    msg.seq = 3728332048U;
    msg.destination.assign("VHMNEWVZHKFFHYKIPUNGWQZQOEWASNTDLCFDZQNRYDCCRTMXOGVKESFLRFO");
    msg.timeout = 7773U;
    const char tmp_msg_0[] = {118, -38, -79, 3, -16, 50, 87, -105, -114, 81, -93, -18, -110, -20, 74, 8, 31, -69, 66, -127, -8, 70, -75, -5, 1, -56, -6, 96, -49, 126};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsTx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRx msg;
    msg.setTimeStamp(0.630346171744);
    msg.setSource(23915U);
    msg.setSourceEntity(19U);
    msg.setDestination(27192U);
    msg.setDestinationEntity(164U);
    msg.source.assign("IDXKJGLYVTBIUXOLNZXDPAGOWBOGWZFGZHAYZKERKEHRGCRCCAYSYQQLAXEMAUHSIPLAMLTDNMUYUTVQNSLEPHWSUTIIEENWBGBFRIPJHKJFTPVGTOMZWSFJCDQKDMOLXQFUUQAXMMJABXOHCHGRKEDUKVJYZKFOWPCXOTVRMBSWXBFQHSQBTMNYZIWNEQJTWZSQJPVSIKGUPLSZJCXOLCDNIDBYPLRWAKFBJVDNNEZOYHRECF");
    const char tmp_msg_0[] = {-115, 118, -19, -77, 37, -114, -38, 76, 4, 77, -39, -50, -90, 113, 55, 1, 38, -123, 105, -43, -54, -38, 96, 55, 91, -40, -70, 15, -1, -87, -49, -98, -108, 20, -101, 85, -119, 20, 65, 78, 120, 100, 29, -107, -61, 59, -27, -12, 23, 23, 4, 87, 59, 13, -17, -85, -5, -11, 48, 14, 23, 30, -109, 94, -32, 91, 95, 118, -3, 20, -56, -53, -112, 14, 29, 45, 10, 105, -64, -19, -119, 81, -75, 126, -92, -37, 29, 25, 55, -93, -122, 45, -61, 102, -47, 33, 84, -40, 3, -71, -8, -125, -106, -79, -48, -98, 58, -17, 11, 113, -99, -7, 20, 72, 36, 79, 42, -127, -77, 37, 19, -15, -49, -57, 64, -94, 21, 23, -10, -78, 38, 92, 3, 103, -46, 50, -49, 63, 47, -46, -15, 116, -74, 49, 114, 37, 15, 7, 61, 120, -93, 34, 30, 118, -99, 11, -65, 29, 16, 101, 51, 116, -47, -111, 75, -63, 108, 23, -4, 82, -90, 32, -98, -62, 13, -12, 72, 106, 0, 98, 112, -97, -86, 113, 0, 104, -113, -16, -88, 58, -13, 52, -120, -51, 79, -85, -25, 116, -116, -83, -69, 19, -4, -19, 13, -23, -58, -47, -40, 34, 6, 4, 75, -71, -70, 51, -89, 1, 14, -56, -12, -120, -64, -11, -68, 28, -105, 37, -1, -72, -52, -10, -27, 84, 10, -50, -33, -113, 31, -54, -43, 7, 12, 99};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRx msg;
    msg.setTimeStamp(0.415919213138);
    msg.setSource(27259U);
    msg.setSourceEntity(209U);
    msg.setDestination(63075U);
    msg.setDestinationEntity(247U);
    msg.source.assign("YSYKQQPSFNWGTLIJIVACFZFHWYFGTQXEAUDOCDUDWVLPGQVTOHIUDWOINWRLXNJRBIAEBKUVIETVYNMJZJCFHFRSXMBRZIWBJA");
    const char tmp_msg_0[] = {25, -85, 99, -90, 122, 66, -58, 112, 101, 2, 92, 122, -42, -66, 105, 44, 114, -44, 122, 96, 123, 37, 82, -13, 90, -56, -21, -89, -83, 99, -3, -46, -59, -29, 50, -91, -100, -6, -95, 0, -58, -111, 79, -86, -77, -120, -54, -101, 94, -79, -96, -109, -27, 74, 23, 85, -49, 27, 54, 76, 95, -65, 38, 70, -68, 4, -35, -73, -55, -14, -6, 91, -70, 30, -23, 9, -126, -72, 98, -80, 21, 86, -112, 25, -120, 74, -95, -49, -40, -110, 23, -123, 59, -98, 14, 115, 51, 39, 80, -93, 39, 69, 72, -114, 80, 92, 4, -113, 113, -69, -80, 72, 49, 52, -106, 64, -10, -87, 63, -127, 93, 17, 81, -34, -6, 53, 108, -68, 38, 87, -77, -4, -24, -15, 92, -102, -32, 24, 105, -107, 68, 0, -2, -5, -73, 36, -27, -14, -127, 96, -128, 75, -44, -74, -120, 120, -103, 46, -108, -98, -41, 16, 21, -8, 53, 29, 100, -92, 104, 83, 13, 100, -126, 122, -41, -122, -21, 64, 90, 49, 110, 19, 88, 67, -75, -62, -98, -4, 29, -103, 105, 84, 75, 24, 83, 82, -40, -91, -32, 27, 95, -54, 102, -75, -52, -60, 0, -99, 75, 26, -59, 50, 113, 65, 126, -14, -51, 70, 29, -13, -8, -39, -122, -106, 76, 15, 95, 39, 1, -33, -49, 122, -83, 123, -33};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsRx msg;
    msg.setTimeStamp(0.141656665906);
    msg.setSource(64789U);
    msg.setSourceEntity(96U);
    msg.setDestination(40961U);
    msg.setDestinationEntity(222U);
    msg.source.assign("TSIXLDTWCRQOHSAFUGXZADMCHKELOPOWJASSUKUDVYIUIBFQBVFLEYXIPZVEWTZPYPKCPJJPRJHDCEMLZBQTEBXRMZLYVRQCXKNRROFNSFHVXCGTYULFIZVQDQDFYZMZLGCOKDQBCBFPBVCPINWHUVXSOWNLONODWYHPUQNHUER");
    const char tmp_msg_0[] = {32, 120, 41, -12, 32, -83, 70, 87, -48, 3, -115, -74, -111, -32, -66, 27, 79, 121, 15, 67, -110, -91, -90, 120, 25, -60, 82, 36, -81, 38, -5, 98, -101, 116, -108, 90, 95, -54, 67, -110, -76, 93, 52, -121, -120, 101, -53, -29, 29, -48, -97, 32, 79, 91, 51, 39, 116, -101, -97, 27, 84, 109, -14, 79, 10, -45, -2, 40, -62, -89, -98, 60, -106, 21, 43, 0, 9, 19, 43, 69, -89, 47, -103, -13, 61, -103, 38, -57, -109, 60, 84, 101, -34, -52, -14, -27, -118, 112, 39, 126, 118, 3, -38, -9, 19, 110, -52, -103, -44, 72, 34, 82, 53, -110, -85, 28, 66, -30, -112, -21, 26, 124, -43, 53, -39, 33, 6, -66, 121, -116, -20, -95, 10, 83, -31, -35, 107, -41, 83, -99, 54, 83, 110, -49, -6, -19, 1, -86, -120, -101, -29, -7, -10, -37, 36, -3, 88, 57, 32, -3, -97, -43, 113, -40, 107, -6, -21, 19, 88, -15, -90, 19, 105, -123, -52, -88, 70, -14, 14, 6, 88, 97, 73, 111, -79, 7, 3, -41, -100, -27, -123, -22, -15, -21, -71, 2, -76, 87, -44, 118, 38, 54};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsRx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsState msg;
    msg.setTimeStamp(0.784087064563);
    msg.setSource(35162U);
    msg.setSourceEntity(145U);
    msg.setDestination(48404U);
    msg.setDestinationEntity(222U);
    msg.seq = 3829685175U;
    msg.state = 226U;
    msg.error.assign("ECEVAQLBTLZZWYVZADWIWRASJYKGXORGFEFNEPCBZLJYKTUXYKQM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsState msg;
    msg.setTimeStamp(0.147498098217);
    msg.setSource(22615U);
    msg.setSourceEntity(194U);
    msg.setDestination(50285U);
    msg.setDestinationEntity(234U);
    msg.seq = 2283625489U;
    msg.state = 142U;
    msg.error.assign("RUMUUSEZLWIBOCHTPOLNPPDRZQXMBGFAKFTJQKQORSLDJIAPYUPZPEVEMQCMASNBSWBNLTSXXSHN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SmsState msg;
    msg.setTimeStamp(0.0861681004336);
    msg.setSource(6835U);
    msg.setSourceEntity(164U);
    msg.setDestination(11961U);
    msg.setDestinationEntity(184U);
    msg.seq = 296948428U;
    msg.state = 96U;
    msg.error.assign("BKHHIWVGWHBFFTNUAAYTPVPYINVSCKAAOIJL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SmsState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgRx msg;
    msg.setTimeStamp(0.601827036829);
    msg.setSource(10191U);
    msg.setSourceEntity(142U);
    msg.setDestination(51081U);
    msg.setDestinationEntity(102U);
    msg.origin.assign("ZOSJVTBANSPIEHCWWWFUVAPOMKVIQWICALGXBVFUPG");
    msg.htime = 0.630153492731;
    msg.lat = 0.802112057722;
    msg.lon = 0.0773785019143;
    const char tmp_msg_0[] = {-101, -28, 62, 28, 5, 34, -119, -47, 5, 87, 77, -98, -97, -4, 55, -61, 28, -79, 70, 39, 65, 87, -59, 54, -107, 88, -2, 82, -8, -125, 107, 57, -116, -102, 98, -45, 84, -74, -59, 10, -41, -44, -36, 24, -43, -24, 50, 109, 76, 109, -85, 64, 68, -16, -99, 69, 62, 124, 80, 110, 124, 88, 105, 107, 57, 92, 1, 37, -46, -46, 15, -16, 34, 23, 106, -111, -28, 89, -1, 75, 61, -121, 123, -100, 115, 126, -122, -78, -103, 95, 24, 71, -64, -115, -3, -113, -46, 52, -15, 6, 68, 112, 32, -21, -103, -35, 95, 58, -49, -67, 125, 1, -17, -56, 73, -24, -85, -16, -73, -45, 47, 74, -54, -67, 2, -66, 84, -77, 64, -82, 125, 38, -89, -11, 74, 13, 74, -84, -115, -128, 113, -29, -105, -18, -90, 95, -111, -93, 119, 124, -53, 30, -102, 29, -102, 2, 22, 28, -90, -39, -18};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgRx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgRx msg;
    msg.setTimeStamp(0.28218890809);
    msg.setSource(42198U);
    msg.setSourceEntity(194U);
    msg.setDestination(47592U);
    msg.setDestinationEntity(71U);
    msg.origin.assign("DWZYQDGWCMHREHROOUTIEALRATVCCXYCGCOLWXWEUVPGEJZSJOSIBY");
    msg.htime = 0.63757282207;
    msg.lat = 0.718048924227;
    msg.lon = 0.0904144414919;
    const char tmp_msg_0[] = {-9, -46, 74, 123, 34, -115, -119, 32, -81, -38, 105, 112, 44, 92, -86, -28, -82, -31, -13, -41, -34, 70, -127, 52, 100, -8, -16, 3, -23, 2, 5, -59, 60, -102, 32, -35, 80, 81, 110, 41, -33, 101, -26, 31, 26, -98, -120, -27, -71, -69, -128, 50, 17, -90, -78, 22, 45, -117, -49, -25, 117, -77, 53, 29, -13, 50, -37, -42, -118, -126, 96, -31, -104, -77, -116, 3, 72, -118, -58, -78, 30, -53, 25, 78, -32, -73, 100, 99, -59, -80, 45, -89, 32, 93, 49, 78, -107, 45, 66, -86, -79, 81, 38, 62, 116, 117, 31, 10, -81, -93, 20, 106, -114, -123, 3, 111, -85, -59, -39, -40, -108, 78, 73, 14, 98, -107, 33, 29, 106, -67, 55, 69, -67, 0, -71, 57, -80, 37, 73, 75, -68, -40, -111, -7, 57, -41, -8, -111, 49, 112, 111, 105};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgRx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgRx msg;
    msg.setTimeStamp(0.70936985191);
    msg.setSource(3173U);
    msg.setSourceEntity(67U);
    msg.setDestination(29707U);
    msg.setDestinationEntity(173U);
    msg.origin.assign("AQQZMWIULVVHLQDYIZUHOCAJKEDTKAINFKQFOFKVXPBNFORTGGKQSXEKBDFPUTTCULHWNYSFHYIGBVCIEHTUQCGTAPTIFGSMNMIRRXVVSEOBNQ");
    msg.htime = 0.792704336839;
    msg.lat = 0.0840114789344;
    msg.lon = 0.4128478273;
    const char tmp_msg_0[] = {40, -110, -17, 8, -3, -123, 90, -24, -27, -54, 109, 121, -99, 10, 14, 23, 61, 72, -36, -95, 20, 42, -50, 82, -30, -29, -107, -108, 124, -18, -17, -31, -11, 88, -107, -101, -63, 93, 94, -102, 67, 35, 86, -39, -87, -120, -23, -104, 56, 49, -20, -79, -20, 67, 59, 101, 100, -122, 22, -2, -111, -32, 72, -54, 116, -114, -126, -79, 41, 102, 69, 37, -30, -70, -112, 123, 40, -34, 122, -28, -98, -78, 24, 66, 7, -44, -58, 75, -12, 52, -96, -1, 21, -80, -94, 84, 36, 7, 18, 20, 87, -127, -60, 41, -39, -55, 61, -29, -28};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgRx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgTx msg;
    msg.setTimeStamp(0.525513917077);
    msg.setSource(25300U);
    msg.setSourceEntity(136U);
    msg.setDestination(16990U);
    msg.setDestinationEntity(153U);
    msg.req_id = 29496U;
    msg.destination.assign("NGWNVJGXICVPUQQUXCOZEVATZTNEKDKPPOCVBNGSRTFM");
    const char tmp_msg_0[] = {112, 96, -27, 80, -90, -125, 5, 66, -109, 113, 18, 28, 112, 15, 68, 53, 31, 13, 70, -36, 80, -109, 87, 101, -34, -61, 88, 55, 52, -63, 114, -84, -92, -53, -12, -89, -107, 80, 2, 12, 122, 84, -78, 26, 83, 115, 15, -108, -112, -28, 87, -31, -57, -102, -65, 75, -12, -16, 28, -84, -89, 74, -45, -37, 54, -60, 33, 71, -80, -36, -53, -56, -102, 42, 25, -64, 7, 26, 120, 113, -38, 14, 124, -118, 62, -77, 91, 54, -21, -78, -36, -83, -60, 110, 71, 125, 84, 52, -99, 117, -47, -1, 22, 91, -95, 103, 72, -12, 0, -80, 83, 16, 113, -29, 72, 52, -18, 51, 79, -84, 112, -107, -50, -119, -90, 100, -85, -77, -101, -55, -58, 72, -34, 104, 80, 39, -33, 65, -113, 9, -80, -125, -75, 34, -58, -9, 2, -68, -116, -60, -57, -13, -73, -47, -95, -60, 51, -77, -57, -51, -117, -100, -16, 73, -63, 46, 82, -63, -108, -95, 16, 96, 4, -65, 21, -110, 14, 20, 16, -42, -119, 45, -43, -84, 21, -86, 77, 12, 71, -45, -69, -63, 27, 24, 54, -63, 32, 56, 14, -79, 111, 61, 122, -88, 70, -48};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgTx #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgTx msg;
    msg.setTimeStamp(0.140136513872);
    msg.setSource(62074U);
    msg.setSourceEntity(93U);
    msg.setDestination(47203U);
    msg.setDestinationEntity(164U);
    msg.req_id = 54284U;
    msg.destination.assign("MZDCTKSJJGQPWWQLSIMMYXXGYASAJHAJRCZHEWRDVTYKQCBHONIHUOQRYVHOFKIKYXTPIBUWQCVOQUZVUXAZACVNKLVZTHJBZI");
    const char tmp_msg_0[] = {91, -85, -13, 75, -9, -63, -43, 4, -74, 60, 57, -74, 36, -26, -25, -42, 123, -12, -18, 105, 35, -102, 122, -1, 99, 40, 36, -81, -126, 114, -16, -125, 8, 62, -82, 5, 11, -74, 21, -111, 96, 92, -55, 95, 30, 100, -110, 90, -98, 25, -13, 29, 112, -73, -125, 118, 94, -64, -67, -81, -103, 64, 68, 74, 9, -13, -65, -63, 97, 86, 37, 69, -4, -23, -35, -126, 83, 13, 7, -17, -119, -19, -108, -10, 117, -14, 55, 118, 64, 53, -72, 83, -20, -45, -95, -47, -94};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgTx #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumMsgTx msg;
    msg.setTimeStamp(0.776953281819);
    msg.setSource(42495U);
    msg.setSourceEntity(90U);
    msg.setDestination(39600U);
    msg.setDestinationEntity(120U);
    msg.req_id = 26896U;
    msg.destination.assign("IEZWNMKXSHCPGRXGZTAOAFKACLADNNVHCQFZRSGLETWPCMFDZBNUACGO");
    const char tmp_msg_0[] = {83, -67, 56, 85, -81, 95, -115, 101, -58, -113, 2, -49, 42, 112, 48, 120, -9, -40, 115, 92, 16, 69, -53, -100, 33, -113, -76, -90, -125, -88, 15, 101, 34, -40, -116, 102, -8, 101, 21, -23, 64, 106, 82, -32, 43, 11, 97, 13, -82, 85, -90, -32, 79, -69, 75, -55, 87, 78, -7, 23, 44, -89, -15, 103, -1, 9, -77, 50, 108, -45, 126, -76, 85, 26, 27, -64, -11, -4, 94, 39, -124, -124, -41, -44, -121, -72, 66, -92, 104, 1, 5, -69, 113, 107, -95, 22, 99, 71, -99, 122, 42, 111, 33, 90, -17, -81, -122, 88, 16, -69, -3, 26, 40, -111, 64, -23, -50, -93, 15, -10, 44, -50, -102, 33, 17, 63, 18, 43, -50, 5, 112, 61, -102, -13, -36, -77, 73, 58, -2, 75, 108, -60, 41, -84, -46, -71, 70, 69, -33, 72, 111, 51, -102, -52, -5, 52, -93, 0, -76, 8, 50, -99, 77, -10, 43, 69, -83, 57, 78, 16, -106, -121, 3, -113, -91, -124, 29, -99, 99, -35, 119, -125, -4, -18, 106, 95, -95, 64, -110, -74, 102, 31, 84, -8, -4, 41, 11, 67, -87, 39, 107, 4, -26, -87, -101, 108, 6, 80, -9, -126, -56, -42, 120, -122, -66, -44, -8, -124, 106, -78, 13, 30, 95, 104};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumMsgTx #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumTxStatus msg;
    msg.setTimeStamp(0.338970146624);
    msg.setSource(62911U);
    msg.setSourceEntity(84U);
    msg.setDestination(36904U);
    msg.setDestinationEntity(243U);
    msg.req_id = 29541U;
    msg.status = 32U;
    msg.text.assign("URKZDPMSXRLENYGBOXTMYHBSAFIJHQWENIQBEBUGZLYSCIXJURGQIFTPAUFKTYDRHNSTSOLWWTHXKHZXDEMVPCBNLKIJVVPJBDVUCMAMEXLPURWPCJQVEN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumTxStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumTxStatus msg;
    msg.setTimeStamp(0.435224581903);
    msg.setSource(22874U);
    msg.setSourceEntity(31U);
    msg.setDestination(2029U);
    msg.setDestinationEntity(168U);
    msg.req_id = 8902U;
    msg.status = 98U;
    msg.text.assign("CXGEDBATQXQJDGRHITYTJQLIIMNHQLBGPTLQAEGLRYYKXFARDWBMMIQMZOCYDZPOKSHFLWISMUFANAHUSTYPNFZKRPFHEXENVVHYZOJGIVWJRCHVLDGSSKGOTKJVZZBEOCWUEIJEIBWVOGFAXEOHCMDGCGMPLFYAUDMCAVLWBNSKF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumTxStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IridiumTxStatus msg;
    msg.setTimeStamp(0.101577080847);
    msg.setSource(1903U);
    msg.setSourceEntity(21U);
    msg.setDestination(43965U);
    msg.setDestinationEntity(22U);
    msg.req_id = 57274U;
    msg.status = 72U;
    msg.text.assign("OFOFBQRLRPWGKSTTCITRFHJPZHQFXLEBLOQULFSEYABEKMCEPVDXOUXXZJMKHHJJZXWASIQSYSIDGQDUJENQDJFGTUIKNDBEXVNFCDPHJCDOKYYOOUCVMGLZTZBWHMFLPLBPACWUVENYIJSVGUSAWPNGMVBCHLZWLXTSFXJOQZUIABGJCKUWVRIPZHBTCSGZDEVMAAQCIYSMDWWAKMKXFMP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IridiumTxStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRange msg;
    msg.setTimeStamp(0.967986848763);
    msg.setSource(39060U);
    msg.setSourceEntity(174U);
    msg.setDestination(33840U);
    msg.setDestinationEntity(188U);
    msg.id = 173U;
    msg.range = 0.382953105745;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRange #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRange msg;
    msg.setTimeStamp(0.0814245161308);
    msg.setSource(38200U);
    msg.setSourceEntity(136U);
    msg.setDestination(59014U);
    msg.setDestinationEntity(134U);
    msg.id = 190U;
    msg.range = 0.668110835142;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRange #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRange msg;
    msg.setTimeStamp(0.668692486892);
    msg.setSource(3370U);
    msg.setSourceEntity(22U);
    msg.setDestination(36283U);
    msg.setDestinationEntity(173U);
    msg.id = 32U;
    msg.range = 0.85871044744;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRange #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblDetection msg;
    msg.setTimeStamp(0.97539308305);
    msg.setSource(55061U);
    msg.setSourceEntity(98U);
    msg.setDestination(5176U);
    msg.setDestinationEntity(61U);
    msg.tx = 95U;
    msg.channel = 19U;
    msg.timer = 21461U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblDetection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblDetection msg;
    msg.setTimeStamp(0.518914952439);
    msg.setSource(26607U);
    msg.setSourceEntity(31U);
    msg.setDestination(32235U);
    msg.setDestinationEntity(248U);
    msg.tx = 64U;
    msg.channel = 189U;
    msg.timer = 26560U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblDetection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblDetection msg;
    msg.setTimeStamp(0.487243276245);
    msg.setSource(29534U);
    msg.setSourceEntity(190U);
    msg.setDestination(5623U);
    msg.setDestinationEntity(168U);
    msg.tx = 195U;
    msg.channel = 78U;
    msg.timer = 40375U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblDetection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblBeacon msg;
    msg.setTimeStamp(0.915009273797);
    msg.setSource(54262U);
    msg.setSourceEntity(25U);
    msg.setDestination(54739U);
    msg.setDestinationEntity(123U);
    msg.beacon.assign("ZWVKPRPTZBPRZGSXSZILSQKDQJCSGTPNQHUPLLUCXDMIQOADTNFWTXXULWCBSNVFWAQCLOVECKXTIPUPJEAQUBHBJIKVNMNBNGVZRODYQIAJFMODHJMGAWGGWC");
    msg.lat = 0.693222198236;
    msg.lon = 0.0860358553354;
    msg.depth = 0.425391578337;
    msg.query_channel = 55U;
    msg.reply_channel = 164U;
    msg.transponder_delay = 243U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblBeacon #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblBeacon msg;
    msg.setTimeStamp(0.429103649205);
    msg.setSource(14752U);
    msg.setSourceEntity(58U);
    msg.setDestination(9199U);
    msg.setDestinationEntity(188U);
    msg.beacon.assign("UXNEPHJUFBNUVOTVMJTDZCVCUGFGXUARWHILPOZBVNPYFMPWDMOXIMQZWRWHHLTXTVJHEJZPZSAGEDBPQUMIDBFHPVDSJEAGOKXKRTDORVFGICNL");
    msg.lat = 0.783370343472;
    msg.lon = 0.42158313172;
    msg.depth = 0.302514468469;
    msg.query_channel = 117U;
    msg.reply_channel = 72U;
    msg.transponder_delay = 110U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblBeacon #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblBeacon msg;
    msg.setTimeStamp(0.404135364578);
    msg.setSource(10075U);
    msg.setSourceEntity(131U);
    msg.setDestination(53815U);
    msg.setDestinationEntity(202U);
    msg.beacon.assign("CHVCBYDINWOZFNDYUEZDPIIXGCEZJAHDXVEUOSRABYURUVMYINGOGVMFMPWRKUQRBVWSDNTCUCDAZHIQMHNJUXJZOVXSOLWJWKZBULXHYAPZJNSAOQLVLFQGEALCQXSKPRHYKPFJTVWFTTDBBZFJXGCKMMDRROBYYHCGJSFGTOMDLQQINJLLTPPHEXSFZCVFNGKTFEIASEQ");
    msg.lat = 0.0759076062049;
    msg.lon = 0.384564572209;
    msg.depth = 0.0410135245441;
    msg.query_channel = 14U;
    msg.reply_channel = 85U;
    msg.transponder_delay = 31U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblBeacon #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblConfig msg;
    msg.setTimeStamp(0.935670876427);
    msg.setSource(42354U);
    msg.setSourceEntity(251U);
    msg.setDestination(42294U);
    msg.setDestinationEntity(118U);
    msg.op = 170U;
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("VWCHSPAFYKVTHKUNJYTMCHFRGDMGUDOAVNDVUKOCQDMQNWQATQUJRKHJNTABFPXCQWKELXMIKFNIMYWGPVPFJZXBRSBCOVDURJPJMHDLTZKBAAOWYSMLABMBPOECGLYELYQVNJFSRCIXNSHZKBLONUGWDZYGKFWKYGVZHIXJIBAPOGOOEAZYIRCCOSTSXNRSRCLSFWDXQZXFRBVEPXTHPGGIUHDIDLVUSZIUEBXTZRJTFHZILLAUW");
    tmp_msg_0.lat = 0.441067964393;
    tmp_msg_0.lon = 0.329844136848;
    tmp_msg_0.depth = 0.925313522362;
    tmp_msg_0.query_channel = 170U;
    tmp_msg_0.reply_channel = 77U;
    tmp_msg_0.transponder_delay = 89U;
    msg.beacons.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblConfig #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblConfig msg;
    msg.setTimeStamp(0.706849811873);
    msg.setSource(64817U);
    msg.setSourceEntity(72U);
    msg.setDestination(16467U);
    msg.setDestinationEntity(39U);
    msg.op = 233U;
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("MTEPAZRVTGRBMDAVPPRZFYJXDZIHLVOVQPEFSBEMKUREFLDNIZDWMFAHHMJICCWEWGCYSRUCQOXEUANYIKAGSLQFLOQNPPJGXOSDOSHWUNVXYZUERDRNJFSWBBXBKQWWYCLUIBMUZNMZJPYDNHGXIKIFJBQVMVAZOCCOPKQHNYVKGBACQLEFGZIUSHRXALWKJPWYEWSLEAVS");
    tmp_msg_0.lat = 0.807289439531;
    tmp_msg_0.lon = 0.429914610536;
    tmp_msg_0.depth = 0.198549133419;
    tmp_msg_0.query_channel = 169U;
    tmp_msg_0.reply_channel = 202U;
    tmp_msg_0.transponder_delay = 127U;
    msg.beacons.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblConfig #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblConfig msg;
    msg.setTimeStamp(0.388396034723);
    msg.setSource(8813U);
    msg.setSourceEntity(208U);
    msg.setDestination(58599U);
    msg.setDestinationEntity(217U);
    msg.op = 109U;
    IMC::LblBeacon tmp_msg_0;
    tmp_msg_0.beacon.assign("JWESDHQVFOZFSCQDFPXQTQETMZESWIPNFRMFULMRCKJANTSHSXJZMSFFOOKPQRVLSQAEMKLVGAQJLRQJMKZCGOZKYXHBIEZLMHRHNBCUYNWJGOVCIOKWUDIL");
    tmp_msg_0.lat = 0.591634264447;
    tmp_msg_0.lon = 0.96482013518;
    tmp_msg_0.depth = 0.485925193665;
    tmp_msg_0.query_channel = 152U;
    tmp_msg_0.reply_channel = 238U;
    tmp_msg_0.transponder_delay = 244U;
    msg.beacons.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblConfig #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRange msg;
    msg.setTimeStamp(0.267014520788);
    msg.setSource(653U);
    msg.setSourceEntity(45U);
    msg.setDestination(42253U);
    msg.setDestinationEntity(40U);
    msg.address = 175U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRange #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRange msg;
    msg.setTimeStamp(0.408235893016);
    msg.setSource(59383U);
    msg.setSourceEntity(158U);
    msg.setDestination(26474U);
    msg.setDestinationEntity(155U);
    msg.address = 227U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRange #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRange msg;
    msg.setTimeStamp(0.931905837075);
    msg.setSource(44972U);
    msg.setSourceEntity(65U);
    msg.setDestination(43451U);
    msg.setDestinationEntity(238U);
    msg.address = 104U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRange #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRangeReply msg;
    msg.setTimeStamp(0.480442642533);
    msg.setSource(4495U);
    msg.setSourceEntity(197U);
    msg.setDestination(24228U);
    msg.setDestinationEntity(43U);
    msg.address = 202U;
    msg.status = 1U;
    msg.range = 0.490276189667;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRangeReply #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRangeReply msg;
    msg.setTimeStamp(0.582613966064);
    msg.setSource(21788U);
    msg.setSourceEntity(2U);
    msg.setDestination(49726U);
    msg.setDestinationEntity(38U);
    msg.address = 112U;
    msg.status = 200U;
    msg.range = 0.54921011234;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRangeReply #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticRangeReply msg;
    msg.setTimeStamp(0.588000601892);
    msg.setSource(20561U);
    msg.setSourceEntity(232U);
    msg.setDestination(53245U);
    msg.setDestinationEntity(136U);
    msg.address = 96U;
    msg.status = 95U;
    msg.range = 0.582300761357;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticRangeReply #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticMessage msg;
    msg.setTimeStamp(0.934642510455);
    msg.setSource(15098U);
    msg.setSourceEntity(121U);
    msg.setDestination(50345U);
    msg.setDestinationEntity(107U);
    IMC::MonitorEntityState tmp_msg_0;
    tmp_msg_0.command = 15U;
    tmp_msg_0.entities.assign("DTSPIIODCGKIMFNJWJICRLBNUSZCGRVGLKADEREVBPYATWREWTLEHN");
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticMessage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticMessage msg;
    msg.setTimeStamp(0.268078405852);
    msg.setSource(52209U);
    msg.setSourceEntity(247U);
    msg.setDestination(8786U);
    msg.setDestinationEntity(242U);
    IMC::LblRange tmp_msg_0;
    tmp_msg_0.id = 38U;
    tmp_msg_0.range = 0.317411060588;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticMessage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticMessage msg;
    msg.setTimeStamp(0.948891162176);
    msg.setSource(8581U);
    msg.setSourceEntity(239U);
    msg.setDestination(24580U);
    msg.setDestinationEntity(73U);
    IMC::CloseSession tmp_msg_0;
    tmp_msg_0.sessid = 3900443256U;
    msg.message.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticMessage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticDiagnostic msg;
    msg.setTimeStamp(0.0369467122386);
    msg.setSource(37071U);
    msg.setSourceEntity(128U);
    msg.setDestination(21706U);
    msg.setDestinationEntity(83U);
    msg.enable = 140U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticDiagnostic #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticDiagnostic msg;
    msg.setTimeStamp(0.0249497695147);
    msg.setSource(22590U);
    msg.setSourceEntity(117U);
    msg.setDestination(26399U);
    msg.setDestinationEntity(118U);
    msg.enable = 107U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticDiagnostic #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticDiagnostic msg;
    msg.setTimeStamp(0.518492195931);
    msg.setSource(55928U);
    msg.setSourceEntity(153U);
    msg.setDestination(25411U);
    msg.setDestinationEntity(166U);
    msg.enable = 120U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticDiagnostic #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticNoise msg;
    msg.setTimeStamp(0.604090373614);
    msg.setSource(62356U);
    msg.setSourceEntity(201U);
    msg.setDestination(15874U);
    msg.setDestinationEntity(62U);
    msg.summary = 124U;
    msg.level = 101U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticNoise #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticNoise msg;
    msg.setTimeStamp(0.296401519646);
    msg.setSource(28929U);
    msg.setSourceEntity(167U);
    msg.setDestination(12311U);
    msg.setDestinationEntity(47U);
    msg.summary = 46U;
    msg.level = 110U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticNoise #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticNoise msg;
    msg.setTimeStamp(0.498662107139);
    msg.setSource(53722U);
    msg.setSourceEntity(148U);
    msg.setDestination(11650U);
    msg.setDestinationEntity(198U);
    msg.summary = 186U;
    msg.level = 250U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticNoise #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticPing msg;
    msg.setTimeStamp(0.0710605307857);
    msg.setSource(8986U);
    msg.setSourceEntity(211U);
    msg.setDestination(3551U);
    msg.setDestinationEntity(23U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticPing #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticPing msg;
    msg.setTimeStamp(0.284239414049);
    msg.setSource(12220U);
    msg.setSourceEntity(1U);
    msg.setDestination(49917U);
    msg.setDestinationEntity(167U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticPing #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticPing msg;
    msg.setTimeStamp(0.569613286862);
    msg.setSource(63067U);
    msg.setSourceEntity(67U);
    msg.setDestination(55050U);
    msg.setDestinationEntity(17U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticPing #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticPingReply msg;
    msg.setTimeStamp(0.599142614802);
    msg.setSource(7429U);
    msg.setSourceEntity(34U);
    msg.setDestination(123U);
    msg.setDestinationEntity(76U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticPingReply #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticPingReply msg;
    msg.setTimeStamp(0.865563105572);
    msg.setSource(49018U);
    msg.setSourceEntity(225U);
    msg.setDestination(3374U);
    msg.setDestinationEntity(4U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticPingReply #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticPingReply msg;
    msg.setTimeStamp(0.0961445129532);
    msg.setSource(19155U);
    msg.setSourceEntity(90U);
    msg.setDestination(56438U);
    msg.setDestinationEntity(64U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticPingReply #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticOperation msg;
    msg.setTimeStamp(0.635039417783);
    msg.setSource(39846U);
    msg.setSourceEntity(87U);
    msg.setDestination(24767U);
    msg.setDestinationEntity(181U);
    msg.op = 96U;
    msg.system.assign("THOKXZFVFFIRSPPMIVOFBFVEHLSIGTKVABAAFSSUXOTCKNTEAICIOAAR");
    msg.range = 0.817898823266;
    IMC::DesiredPath tmp_msg_0;
    tmp_msg_0.start_lat = 0.458166208358;
    tmp_msg_0.start_lon = 0.710136643424;
    tmp_msg_0.start_z = 0.0541367538347;
    tmp_msg_0.start_z_units = 198U;
    tmp_msg_0.end_lat = 0.0592186024563;
    tmp_msg_0.end_lon = 0.20276356999;
    tmp_msg_0.end_z = 0.132448857423;
    tmp_msg_0.end_z_units = 118U;
    tmp_msg_0.speed = 0.80553539927;
    tmp_msg_0.speed_units = 82U;
    tmp_msg_0.lradius = 0.789601363261;
    tmp_msg_0.flags = 74U;
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticOperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticOperation msg;
    msg.setTimeStamp(0.95131966309);
    msg.setSource(63265U);
    msg.setSourceEntity(98U);
    msg.setDestination(8167U);
    msg.setDestinationEntity(105U);
    msg.op = 75U;
    msg.system.assign("AIWORIFDYTNYQYEMJDWEDKLWUOBCDKUKPIPXWSTYJBZMWSOUQFLMAXEWFPQJTPUHLNGSCHXYANEVVNSHRDCIOMEOMLDYCDBXMINQTMKUULVFXGEBBUIZLVZ");
    msg.range = 0.71216565664;
    IMC::DesiredHeading tmp_msg_0;
    tmp_msg_0.value = 0.974177008398;
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticOperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticOperation msg;
    msg.setTimeStamp(0.935351635574);
    msg.setSource(36036U);
    msg.setSourceEntity(188U);
    msg.setDestination(24604U);
    msg.setDestinationEntity(33U);
    msg.op = 226U;
    msg.system.assign("LJTKOKQMIFIYWJKQQIIRRSXQLIOCSDHPALDOCXLRBATTODEVEMFKQCGZOMXEZPTNKAGLOPIGBVCFJXOMAFVTFOMZZSTWYDZTWWGWYGZHSKACRJHQVDMCZIRNVEEAJPMFDIJNXNNCRGVPSDYBUACYIMFGWZXVUBBXNQLJPTCHQBY");
    msg.range = 0.907906885301;
    IMC::Map tmp_msg_0;
    tmp_msg_0.id.assign("CVVUGPFEMBPRPKLPRUCYFGRWDZZSAWTQTKADKFMQCJXPXUUIJHBIWBNVBHJVMHLEDNSHOQOZXHJPLFQMGTABQYHYOQJBIYJXAASFDWUXJXKOLYOANBMUTCGKMVIPSWGGOHQWRXNCGKTLMTITOINVFISSRESRARRNZUAIVLJCCAEOPAMBHVRXEKZCWCDWGOKGBMXNFTNEHSOTEHZDWLEZFBTULQKIPZD");
    IMC::MapFeature tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.id.assign("IZMHZETFLHQLDPBJGJICPLVDTYXQGNRVFLJMXJZYUSKSDQGXRNVUXMUHUDMPSUOTDVSNSNKYWQGVWAKFAMYWOCRPDYFWJPNELSHQPQWTYGOEEMDOBIBCZTYZASFZNZVBIHCNFGMDHQLUMRAMMCJUXYBCXKEDPHZHOETUWRYGBVJIO");
    tmp_tmp_msg_0_0.feature_type = 160U;
    tmp_tmp_msg_0_0.rgb_red = 45U;
    tmp_tmp_msg_0_0.rgb_green = 228U;
    tmp_tmp_msg_0_0.rgb_blue = 121U;
    tmp_msg_0.features.push_back(tmp_tmp_msg_0_0);
    msg.msg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticOperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystemsQuery msg;
    msg.setTimeStamp(0.829385351913);
    msg.setSource(31672U);
    msg.setSourceEntity(183U);
    msg.setDestination(17935U);
    msg.setDestinationEntity(95U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystemsQuery #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystemsQuery msg;
    msg.setTimeStamp(0.49845980394);
    msg.setSource(9958U);
    msg.setSourceEntity(20U);
    msg.setDestination(5769U);
    msg.setDestinationEntity(89U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystemsQuery #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystemsQuery msg;
    msg.setTimeStamp(0.643695508376);
    msg.setSource(19096U);
    msg.setSourceEntity(41U);
    msg.setDestination(16978U);
    msg.setDestinationEntity(132U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystemsQuery #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystems msg;
    msg.setTimeStamp(0.688330570891);
    msg.setSource(46323U);
    msg.setSourceEntity(158U);
    msg.setDestination(7217U);
    msg.setDestinationEntity(228U);
    msg.list.assign("JVIDDAABWHTKUPMQCPNBVSCIQTNZMYFSZYQMFIHKOWZHSYQQJFUIBARUBVMDWSLATMSWTOWNVJEENXSHIVWPWRZNAZQNKAQLZERL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystems #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystems msg;
    msg.setTimeStamp(0.721132325071);
    msg.setSource(43854U);
    msg.setSourceEntity(50U);
    msg.setDestination(62539U);
    msg.setDestinationEntity(121U);
    msg.list.assign("CYAHVGRNGHMNTSUYMGRAQBHIIBCJZOAVSCFFLEWOAIFYSWSKUOLOJXSXHUNMDIENHMPTGETJLHQNKZNTLM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystems #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AcousticSystems msg;
    msg.setTimeStamp(0.94580844664);
    msg.setSource(27336U);
    msg.setSourceEntity(112U);
    msg.setDestination(26555U);
    msg.setDestinationEntity(170U);
    msg.list.assign("OLRTNRDLIJVWAFXRQPIZTCDGRGSGNSEAHXWPKXWSVZZITDVENBGBSOCTJDKNJVYLIAECUDSHYYINOYZEEDLFDBVQJQWYGDHLZARLHRXQLERJUXYDQWXPWAICCTSHMVJBQNFYAICAHPYOCUAFOSDAXJSZZNTWKPFOCPMPGQKWPQEOMTR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AcousticSystems #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rpm msg;
    msg.setTimeStamp(0.259601151841);
    msg.setSource(65510U);
    msg.setSourceEntity(19U);
    msg.setDestination(52745U);
    msg.setDestinationEntity(73U);
    msg.value = -29335;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rpm #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rpm msg;
    msg.setTimeStamp(0.930046673375);
    msg.setSource(38921U);
    msg.setSourceEntity(198U);
    msg.setDestination(51911U);
    msg.setDestinationEntity(200U);
    msg.value = 2167;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rpm #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rpm msg;
    msg.setTimeStamp(0.642659821708);
    msg.setSource(57253U);
    msg.setSourceEntity(247U);
    msg.setDestination(5862U);
    msg.setDestinationEntity(239U);
    msg.value = 28593;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rpm #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Voltage msg;
    msg.setTimeStamp(0.639020483539);
    msg.setSource(40696U);
    msg.setSourceEntity(164U);
    msg.setDestination(19947U);
    msg.setDestinationEntity(53U);
    msg.value = 0.112248897468;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Voltage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Voltage msg;
    msg.setTimeStamp(0.542033801631);
    msg.setSource(55287U);
    msg.setSourceEntity(12U);
    msg.setDestination(12401U);
    msg.setDestinationEntity(126U);
    msg.value = 0.266587281508;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Voltage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Voltage msg;
    msg.setTimeStamp(0.919309122018);
    msg.setSource(39915U);
    msg.setSourceEntity(117U);
    msg.setDestination(64808U);
    msg.setDestinationEntity(73U);
    msg.value = 0.849442272275;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Voltage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Current msg;
    msg.setTimeStamp(0.94497714299);
    msg.setSource(12420U);
    msg.setSourceEntity(74U);
    msg.setDestination(25567U);
    msg.setDestinationEntity(177U);
    msg.value = 0.376978125355;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Current #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Current msg;
    msg.setTimeStamp(0.934222649378);
    msg.setSource(45137U);
    msg.setSourceEntity(167U);
    msg.setDestination(57234U);
    msg.setDestinationEntity(13U);
    msg.value = 0.535592111565;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Current #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Current msg;
    msg.setTimeStamp(0.981195519677);
    msg.setSource(49449U);
    msg.setSourceEntity(170U);
    msg.setDestination(26817U);
    msg.setDestinationEntity(2U);
    msg.value = 0.668257578585;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Current #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFix msg;
    msg.setTimeStamp(0.262131297647);
    msg.setSource(51427U);
    msg.setSourceEntity(60U);
    msg.setDestination(44669U);
    msg.setDestinationEntity(206U);
    msg.validity = 52315U;
    msg.type = 70U;
    msg.utc_year = 10749U;
    msg.utc_month = 142U;
    msg.utc_day = 166U;
    msg.utc_time = 0.926186065326;
    msg.lat = 0.517873529516;
    msg.lon = 0.710452133856;
    msg.height = 0.359924042189;
    msg.satellites = 100U;
    msg.cog = 0.828546640957;
    msg.sog = 0.675232007142;
    msg.hdop = 0.844500022392;
    msg.vdop = 0.410479352325;
    msg.hacc = 0.241836932541;
    msg.vacc = 0.225622154487;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFix #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFix msg;
    msg.setTimeStamp(0.308146152748);
    msg.setSource(26118U);
    msg.setSourceEntity(254U);
    msg.setDestination(30659U);
    msg.setDestinationEntity(70U);
    msg.validity = 16903U;
    msg.type = 144U;
    msg.utc_year = 55025U;
    msg.utc_month = 41U;
    msg.utc_day = 134U;
    msg.utc_time = 0.745162873091;
    msg.lat = 0.328690276839;
    msg.lon = 0.0485541015376;
    msg.height = 0.522295897944;
    msg.satellites = 235U;
    msg.cog = 0.553701602663;
    msg.sog = 0.114928457223;
    msg.hdop = 0.771678040228;
    msg.vdop = 0.0231405169515;
    msg.hacc = 0.932786289614;
    msg.vacc = 0.0378155773179;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFix #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFix msg;
    msg.setTimeStamp(0.753427985687);
    msg.setSource(61857U);
    msg.setSourceEntity(63U);
    msg.setDestination(40384U);
    msg.setDestinationEntity(254U);
    msg.validity = 30967U;
    msg.type = 126U;
    msg.utc_year = 58886U;
    msg.utc_month = 91U;
    msg.utc_day = 7U;
    msg.utc_time = 0.380369303191;
    msg.lat = 0.0860202382787;
    msg.lon = 0.710927085038;
    msg.height = 0.695569241222;
    msg.satellites = 82U;
    msg.cog = 0.704616597798;
    msg.sog = 0.339552650786;
    msg.hdop = 0.0609100296896;
    msg.vdop = 0.402518143326;
    msg.hacc = 0.430708149414;
    msg.vacc = 0.478828169799;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFix #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAngles msg;
    msg.setTimeStamp(0.0363999564257);
    msg.setSource(20244U);
    msg.setSourceEntity(36U);
    msg.setDestination(61065U);
    msg.setDestinationEntity(216U);
    msg.time = 0.31686786495;
    msg.phi = 0.54071077139;
    msg.theta = 0.049035353764;
    msg.psi = 0.611898821603;
    msg.psi_magnetic = 0.258646925775;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAngles #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAngles msg;
    msg.setTimeStamp(0.823380266976);
    msg.setSource(40707U);
    msg.setSourceEntity(201U);
    msg.setDestination(37528U);
    msg.setDestinationEntity(18U);
    msg.time = 0.692278814294;
    msg.phi = 0.440645611339;
    msg.theta = 0.560088602784;
    msg.psi = 0.944844220033;
    msg.psi_magnetic = 0.640040935397;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAngles #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAngles msg;
    msg.setTimeStamp(0.595117471907);
    msg.setSource(65108U);
    msg.setSourceEntity(32U);
    msg.setDestination(32659U);
    msg.setDestinationEntity(95U);
    msg.time = 0.104822451678;
    msg.phi = 0.895772341796;
    msg.theta = 0.241700721326;
    msg.psi = 0.586369717371;
    msg.psi_magnetic = 0.737597728029;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAngles #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAnglesDelta msg;
    msg.setTimeStamp(0.880108662906);
    msg.setSource(27445U);
    msg.setSourceEntity(243U);
    msg.setDestination(49393U);
    msg.setDestinationEntity(144U);
    msg.time = 0.0552685655146;
    msg.x = 0.938523485967;
    msg.y = 0.888882400775;
    msg.z = 0.560119238352;
    msg.timestep = 0.612229185383;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAnglesDelta #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAnglesDelta msg;
    msg.setTimeStamp(0.74287150204);
    msg.setSource(32461U);
    msg.setSourceEntity(11U);
    msg.setDestination(24567U);
    msg.setDestinationEntity(15U);
    msg.time = 0.917533084551;
    msg.x = 0.136223064921;
    msg.y = 0.205761681972;
    msg.z = 0.741999784993;
    msg.timestep = 0.417104592034;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAnglesDelta #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EulerAnglesDelta msg;
    msg.setTimeStamp(0.330166080526);
    msg.setSource(28560U);
    msg.setSourceEntity(159U);
    msg.setDestination(48229U);
    msg.setDestinationEntity(98U);
    msg.time = 0.571513631776;
    msg.x = 0.862747679329;
    msg.y = 0.643167191558;
    msg.z = 0.708160226235;
    msg.timestep = 0.87974268744;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EulerAnglesDelta #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AngularVelocity msg;
    msg.setTimeStamp(0.134227214544);
    msg.setSource(43384U);
    msg.setSourceEntity(166U);
    msg.setDestination(14952U);
    msg.setDestinationEntity(206U);
    msg.time = 0.753605668894;
    msg.x = 0.0103379346605;
    msg.y = 0.326434275905;
    msg.z = 0.89235399712;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AngularVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AngularVelocity msg;
    msg.setTimeStamp(0.629646388489);
    msg.setSource(37790U);
    msg.setSourceEntity(118U);
    msg.setDestination(3193U);
    msg.setDestinationEntity(192U);
    msg.time = 0.6523002839;
    msg.x = 0.768762244045;
    msg.y = 0.156703440871;
    msg.z = 0.228357541929;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AngularVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AngularVelocity msg;
    msg.setTimeStamp(0.0961413661114);
    msg.setSource(8495U);
    msg.setSourceEntity(104U);
    msg.setDestination(27883U);
    msg.setDestinationEntity(59U);
    msg.time = 0.502330856964;
    msg.x = 0.550918428294;
    msg.y = 0.504212361108;
    msg.z = 0.773901210314;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AngularVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Acceleration msg;
    msg.setTimeStamp(0.698879337091);
    msg.setSource(40046U);
    msg.setSourceEntity(154U);
    msg.setDestination(53212U);
    msg.setDestinationEntity(26U);
    msg.time = 0.149115121611;
    msg.x = 0.239872237833;
    msg.y = 0.136429758454;
    msg.z = 0.679348243879;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Acceleration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Acceleration msg;
    msg.setTimeStamp(0.296309535979);
    msg.setSource(40845U);
    msg.setSourceEntity(117U);
    msg.setDestination(5533U);
    msg.setDestinationEntity(173U);
    msg.time = 0.406303756401;
    msg.x = 0.701396064505;
    msg.y = 0.664270575971;
    msg.z = 0.223403383904;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Acceleration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Acceleration msg;
    msg.setTimeStamp(0.362230197463);
    msg.setSource(45917U);
    msg.setSourceEntity(186U);
    msg.setDestination(4446U);
    msg.setDestinationEntity(83U);
    msg.time = 0.809084127641;
    msg.x = 0.714030657168;
    msg.y = 0.802423377264;
    msg.z = 0.83497363914;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Acceleration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MagneticField msg;
    msg.setTimeStamp(0.678257229215);
    msg.setSource(3569U);
    msg.setSourceEntity(96U);
    msg.setDestination(18812U);
    msg.setDestinationEntity(162U);
    msg.time = 0.553304407051;
    msg.x = 0.417763090049;
    msg.y = 0.356108239157;
    msg.z = 0.255308962417;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MagneticField #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MagneticField msg;
    msg.setTimeStamp(0.482642434179);
    msg.setSource(5452U);
    msg.setSourceEntity(132U);
    msg.setDestination(23743U);
    msg.setDestinationEntity(146U);
    msg.time = 0.725349886812;
    msg.x = 0.662375388663;
    msg.y = 0.0621764445758;
    msg.z = 0.790351519367;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MagneticField #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MagneticField msg;
    msg.setTimeStamp(0.628810548321);
    msg.setSource(9960U);
    msg.setSourceEntity(103U);
    msg.setDestination(58697U);
    msg.setDestinationEntity(48U);
    msg.time = 0.142802596208;
    msg.x = 0.000121563605152;
    msg.y = 0.648960072025;
    msg.z = 0.658858725762;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MagneticField #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroundVelocity msg;
    msg.setTimeStamp(0.178461293488);
    msg.setSource(4035U);
    msg.setSourceEntity(131U);
    msg.setDestination(33393U);
    msg.setDestinationEntity(7U);
    msg.validity = 126U;
    msg.x = 0.207369768742;
    msg.y = 0.109294899488;
    msg.z = 0.999418111598;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroundVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroundVelocity msg;
    msg.setTimeStamp(0.94665523719);
    msg.setSource(26632U);
    msg.setSourceEntity(209U);
    msg.setDestination(16151U);
    msg.setDestinationEntity(187U);
    msg.validity = 189U;
    msg.x = 0.533751891037;
    msg.y = 0.13257029327;
    msg.z = 0.782837525801;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroundVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GroundVelocity msg;
    msg.setTimeStamp(0.831162243798);
    msg.setSource(25525U);
    msg.setSourceEntity(253U);
    msg.setDestination(41773U);
    msg.setDestinationEntity(110U);
    msg.validity = 232U;
    msg.x = 0.730863161433;
    msg.y = 0.740626033909;
    msg.z = 0.731839347662;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GroundVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterVelocity msg;
    msg.setTimeStamp(0.596892359525);
    msg.setSource(37653U);
    msg.setSourceEntity(63U);
    msg.setDestination(15113U);
    msg.setDestinationEntity(72U);
    msg.validity = 191U;
    msg.x = 0.531700477617;
    msg.y = 0.780555136156;
    msg.z = 0.577720264573;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterVelocity msg;
    msg.setTimeStamp(0.0381294452636);
    msg.setSource(63663U);
    msg.setSourceEntity(142U);
    msg.setDestination(49373U);
    msg.setDestinationEntity(197U);
    msg.validity = 4U;
    msg.x = 0.576117634076;
    msg.y = 0.398338872877;
    msg.z = 0.613408829553;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterVelocity msg;
    msg.setTimeStamp(0.75954598081);
    msg.setSource(21769U);
    msg.setSourceEntity(135U);
    msg.setDestination(63196U);
    msg.setDestinationEntity(72U);
    msg.validity = 0U;
    msg.x = 0.354527050555;
    msg.y = 0.902049405693;
    msg.z = 0.281971609885;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VelocityDelta msg;
    msg.setTimeStamp(0.193307718495);
    msg.setSource(40978U);
    msg.setSourceEntity(253U);
    msg.setDestination(61409U);
    msg.setDestinationEntity(42U);
    msg.time = 0.7348768022;
    msg.x = 0.395615367172;
    msg.y = 0.658596445064;
    msg.z = 0.443299744156;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VelocityDelta #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VelocityDelta msg;
    msg.setTimeStamp(0.491349805013);
    msg.setSource(58780U);
    msg.setSourceEntity(170U);
    msg.setDestination(8624U);
    msg.setDestinationEntity(241U);
    msg.time = 0.39273839033;
    msg.x = 0.505953224517;
    msg.y = 0.698426588661;
    msg.z = 0.803728512136;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VelocityDelta #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VelocityDelta msg;
    msg.setTimeStamp(0.453249016196);
    msg.setSource(37967U);
    msg.setSourceEntity(228U);
    msg.setDestination(30693U);
    msg.setDestinationEntity(113U);
    msg.time = 0.126316451383;
    msg.x = 0.526093043496;
    msg.y = 0.892754564004;
    msg.z = 0.341890410372;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VelocityDelta #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Distance msg;
    msg.setTimeStamp(0.269543187548);
    msg.setSource(6324U);
    msg.setSourceEntity(109U);
    msg.setDestination(45884U);
    msg.setDestinationEntity(133U);
    msg.validity = 237U;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.325985938389;
    tmp_msg_0.beam_height = 0.662215269562;
    msg.beam_config.push_back(tmp_msg_0);
    msg.value = 0.220157207717;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Distance #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Distance msg;
    msg.setTimeStamp(0.437410902068);
    msg.setSource(12744U);
    msg.setSourceEntity(45U);
    msg.setDestination(33363U);
    msg.setDestinationEntity(42U);
    msg.validity = 251U;
    IMC::DeviceState tmp_msg_0;
    tmp_msg_0.x = 0.878878072554;
    tmp_msg_0.y = 0.826275168225;
    tmp_msg_0.z = 0.630926272982;
    tmp_msg_0.phi = 0.498316719779;
    tmp_msg_0.theta = 0.620409254549;
    tmp_msg_0.psi = 0.807246472504;
    msg.location.push_back(tmp_msg_0);
    IMC::BeamConfig tmp_msg_1;
    tmp_msg_1.beam_width = 0.491726377217;
    tmp_msg_1.beam_height = 0.0625550275716;
    msg.beam_config.push_back(tmp_msg_1);
    msg.value = 0.744510663264;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Distance #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Distance msg;
    msg.setTimeStamp(0.976930905019);
    msg.setSource(40050U);
    msg.setSourceEntity(102U);
    msg.setDestination(10174U);
    msg.setDestinationEntity(145U);
    msg.validity = 121U;
    IMC::DeviceState tmp_msg_0;
    tmp_msg_0.x = 0.784130132911;
    tmp_msg_0.y = 0.347023705816;
    tmp_msg_0.z = 0.892111472556;
    tmp_msg_0.phi = 0.549530177411;
    tmp_msg_0.theta = 0.127897422094;
    tmp_msg_0.psi = 0.990162604793;
    msg.location.push_back(tmp_msg_0);
    msg.value = 0.765269697554;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Distance #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Temperature msg;
    msg.setTimeStamp(0.956205196147);
    msg.setSource(64537U);
    msg.setSourceEntity(102U);
    msg.setDestination(4008U);
    msg.setDestinationEntity(92U);
    msg.value = 0.909280700453;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Temperature #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Temperature msg;
    msg.setTimeStamp(0.974323860329);
    msg.setSource(14218U);
    msg.setSourceEntity(235U);
    msg.setDestination(11948U);
    msg.setDestinationEntity(124U);
    msg.value = 0.399471075761;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Temperature #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Temperature msg;
    msg.setTimeStamp(0.289412528199);
    msg.setSource(25856U);
    msg.setSourceEntity(59U);
    msg.setDestination(13783U);
    msg.setDestinationEntity(62U);
    msg.value = 0.530385063277;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Temperature #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pressure msg;
    msg.setTimeStamp(0.591548432633);
    msg.setSource(46119U);
    msg.setSourceEntity(191U);
    msg.setDestination(48167U);
    msg.setDestinationEntity(13U);
    msg.value = 0.825891749876;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pressure #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pressure msg;
    msg.setTimeStamp(0.698602466469);
    msg.setSource(29031U);
    msg.setSourceEntity(19U);
    msg.setDestination(53617U);
    msg.setDestinationEntity(0U);
    msg.value = 0.660856713093;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pressure #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pressure msg;
    msg.setTimeStamp(0.905063983439);
    msg.setSource(26815U);
    msg.setSourceEntity(253U);
    msg.setDestination(32898U);
    msg.setDestinationEntity(139U);
    msg.value = 0.308043975945;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pressure #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Depth msg;
    msg.setTimeStamp(0.467174706563);
    msg.setSource(8681U);
    msg.setSourceEntity(246U);
    msg.setDestination(24660U);
    msg.setDestinationEntity(224U);
    msg.value = 0.193537002558;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Depth #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Depth msg;
    msg.setTimeStamp(0.657083211141);
    msg.setSource(36705U);
    msg.setSourceEntity(240U);
    msg.setDestination(52450U);
    msg.setDestinationEntity(154U);
    msg.value = 0.642437638032;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Depth #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Depth msg;
    msg.setTimeStamp(0.0128732927782);
    msg.setSource(33228U);
    msg.setSourceEntity(75U);
    msg.setDestination(63203U);
    msg.setDestinationEntity(81U);
    msg.value = 0.651469915832;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Depth #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DepthOffset msg;
    msg.setTimeStamp(0.464960843466);
    msg.setSource(16396U);
    msg.setSourceEntity(221U);
    msg.setDestination(40693U);
    msg.setDestinationEntity(24U);
    msg.value = 0.150020654887;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DepthOffset #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DepthOffset msg;
    msg.setTimeStamp(0.885997669633);
    msg.setSource(63931U);
    msg.setSourceEntity(208U);
    msg.setDestination(41435U);
    msg.setDestinationEntity(42U);
    msg.value = 0.500739112378;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DepthOffset #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DepthOffset msg;
    msg.setTimeStamp(0.501106340483);
    msg.setSource(47584U);
    msg.setSourceEntity(218U);
    msg.setDestination(6205U);
    msg.setDestinationEntity(63U);
    msg.value = 0.827078878593;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DepthOffset #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoundSpeed msg;
    msg.setTimeStamp(0.269657494345);
    msg.setSource(36467U);
    msg.setSourceEntity(60U);
    msg.setDestination(39613U);
    msg.setDestinationEntity(198U);
    msg.value = 0.0549674341026;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoundSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoundSpeed msg;
    msg.setTimeStamp(0.408331455032);
    msg.setSource(45307U);
    msg.setSourceEntity(100U);
    msg.setDestination(4324U);
    msg.setDestinationEntity(127U);
    msg.value = 0.956904333153;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoundSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SoundSpeed msg;
    msg.setTimeStamp(0.204748230791);
    msg.setSource(18796U);
    msg.setSourceEntity(11U);
    msg.setDestination(64740U);
    msg.setDestinationEntity(161U);
    msg.value = 0.0164657315472;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SoundSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterDensity msg;
    msg.setTimeStamp(0.942061641506);
    msg.setSource(33898U);
    msg.setSourceEntity(2U);
    msg.setDestination(37384U);
    msg.setDestinationEntity(161U);
    msg.value = 0.144951031859;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterDensity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterDensity msg;
    msg.setTimeStamp(0.223505249109);
    msg.setSource(32789U);
    msg.setSourceEntity(93U);
    msg.setDestination(35411U);
    msg.setDestinationEntity(105U);
    msg.value = 0.586975681166;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterDensity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WaterDensity msg;
    msg.setTimeStamp(0.983502727172);
    msg.setSource(37615U);
    msg.setSourceEntity(182U);
    msg.setDestination(27875U);
    msg.setDestinationEntity(106U);
    msg.value = 0.43543327717;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WaterDensity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Conductivity msg;
    msg.setTimeStamp(0.675304920437);
    msg.setSource(17536U);
    msg.setSourceEntity(143U);
    msg.setDestination(46307U);
    msg.setDestinationEntity(194U);
    msg.value = 0.210685632649;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Conductivity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Conductivity msg;
    msg.setTimeStamp(0.117750522618);
    msg.setSource(48781U);
    msg.setSourceEntity(157U);
    msg.setDestination(55825U);
    msg.setDestinationEntity(142U);
    msg.value = 0.585353956215;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Conductivity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Conductivity msg;
    msg.setTimeStamp(0.361340671566);
    msg.setSource(28364U);
    msg.setSourceEntity(37U);
    msg.setDestination(6703U);
    msg.setDestinationEntity(116U);
    msg.value = 0.915893333263;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Conductivity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Salinity msg;
    msg.setTimeStamp(0.854903990727);
    msg.setSource(18587U);
    msg.setSourceEntity(95U);
    msg.setDestination(18334U);
    msg.setDestinationEntity(113U);
    msg.value = 0.672260417312;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Salinity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Salinity msg;
    msg.setTimeStamp(0.00386370246617);
    msg.setSource(23816U);
    msg.setSourceEntity(253U);
    msg.setDestination(19288U);
    msg.setDestinationEntity(90U);
    msg.value = 0.990121094302;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Salinity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Salinity msg;
    msg.setTimeStamp(0.325957788993);
    msg.setSource(8504U);
    msg.setSourceEntity(233U);
    msg.setDestination(35312U);
    msg.setDestinationEntity(207U);
    msg.value = 0.353918402867;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Salinity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WindSpeed msg;
    msg.setTimeStamp(0.656835339888);
    msg.setSource(39009U);
    msg.setSourceEntity(250U);
    msg.setDestination(43649U);
    msg.setDestinationEntity(68U);
    msg.direction = 0.32183186056;
    msg.speed = 0.0382287276584;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WindSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WindSpeed msg;
    msg.setTimeStamp(0.374907074562);
    msg.setSource(58946U);
    msg.setSourceEntity(124U);
    msg.setDestination(24799U);
    msg.setDestinationEntity(180U);
    msg.direction = 0.366566977193;
    msg.speed = 0.970757734022;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WindSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::WindSpeed msg;
    msg.setTimeStamp(0.128166498259);
    msg.setSource(11864U);
    msg.setSourceEntity(84U);
    msg.setDestination(63327U);
    msg.setDestinationEntity(9U);
    msg.direction = 0.139712342873;
    msg.speed = 0.48679559788;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("WindSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeHumidity msg;
    msg.setTimeStamp(0.915848455332);
    msg.setSource(13937U);
    msg.setSourceEntity(65U);
    msg.setDestination(48059U);
    msg.setDestinationEntity(99U);
    msg.value = 0.548116227902;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeHumidity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeHumidity msg;
    msg.setTimeStamp(0.0297372587793);
    msg.setSource(5884U);
    msg.setSourceEntity(134U);
    msg.setDestination(17192U);
    msg.setDestinationEntity(88U);
    msg.value = 0.896188562465;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeHumidity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RelativeHumidity msg;
    msg.setTimeStamp(0.107370479017);
    msg.setSource(52529U);
    msg.setSourceEntity(36U);
    msg.setDestination(14124U);
    msg.setDestinationEntity(220U);
    msg.value = 0.453042864794;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RelativeHumidity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataText msg;
    msg.setTimeStamp(0.0298623462737);
    msg.setSource(42850U);
    msg.setSourceEntity(32U);
    msg.setDestination(12286U);
    msg.setDestinationEntity(160U);
    msg.value.assign("GZMPTKOEDZBXPOBIWKSW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataText #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataText msg;
    msg.setTimeStamp(0.595845302852);
    msg.setSource(6113U);
    msg.setSourceEntity(54U);
    msg.setDestination(49821U);
    msg.setDestinationEntity(42U);
    msg.value.assign("NCREQUFJWVDVFHQUAGHLSJNTJBGWQCVYTMRSJMIKSXLTEDVBAMHUWRLURPQBAABTYKDOHYHBRTNXSYFYJQWKGZKWIA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataText #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataText msg;
    msg.setTimeStamp(0.0395133117869);
    msg.setSource(21754U);
    msg.setSourceEntity(182U);
    msg.setDestination(16228U);
    msg.setDestinationEntity(166U);
    msg.value.assign("QNZYGEHHARSPDKPDNHWPNVTETBLZAJMXBCUFTEWAUINVIJJZAXSIVXFKSWYUNJPBVYHMNMISYNCTGJOQNASPELCTLECRCAVZQVWRSKZRUTHCRPXDPYCFMANCOBOUPXFBDRLTFLDGDUMAPWJQWSQUHJEGRFBOSLLEXLZZEMMNQOFQSDFDRSKLGTBEVYEOTGQXKHUXJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataText #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataBinary msg;
    msg.setTimeStamp(0.193678582435);
    msg.setSource(19286U);
    msg.setSourceEntity(210U);
    msg.setDestination(6015U);
    msg.setDestinationEntity(147U);
    const char tmp_msg_0[] = {81, 34, -78, 74, 38, -127, 70, 60, 11, 57, 78, -107, 14, 1, -128, 13, 119, -68, 39, -90, 8, -107, 111, -12, 85, -38, 25, 27, 120, -50, -26, 74, -99};
    msg.value.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataBinary #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataBinary msg;
    msg.setTimeStamp(0.390065637448);
    msg.setSource(13185U);
    msg.setSourceEntity(194U);
    msg.setDestination(64574U);
    msg.setDestinationEntity(33U);
    const char tmp_msg_0[] = {-54, 16, 73, 0, 90, -96, -13, 17, -70, -24, -10, 8, 16, 109, 71, -29, -33, 72, -93, 115, 51, 3, 31, -79, -18, 54, 49, -51, -67, -42, -121, 95, -10, -26, 44, -82, 121, 15, -32, -28, 123, -40, -67, 78};
    msg.value.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataBinary #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DevDataBinary msg;
    msg.setTimeStamp(0.377618217004);
    msg.setSource(15815U);
    msg.setSourceEntity(65U);
    msg.setDestination(16865U);
    msg.setDestinationEntity(16U);
    const char tmp_msg_0[] = {111, -58, -117, 114, 116, -126, 74, 96, 124, -1, 89, -114, -47, -28, 0, 115, 37, 7, -67, 8, -58, -28, 5, 115, 126, 95, -60, 117, 69, -87, -26, 0, 6, -50, 60, -22, -62, -93, 105, 27, 113, 50, -75, 57, 77, -103, -77, 116, -99, -14, -46, 106, 49, -46, 25, 52, 15, 114, -16, 20, 6, -52, -89, 74, 3, 11, -83, -70, 21, -3, 62, 61, 2, 112, -10, 57, 112, -120, -111, 121, -60, -15, 64, 38, -4, -77, 91, -88, 48, -60, -34, -76, 12, 20, 2, -83, -29, -68, -95, 11, -92, -14, 78, 117, -51, -84, 97, 64, -12, -126, 122, 104, 124, -93, -76, -105, -41, -114, -77, -79, -17, 64, 88, -68, -13, -101, 93, -61, -8, 93, -75, -95, -119, -15, -39, 16, 73, 29, 88, 7};
    msg.value.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DevDataBinary #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarConfig msg;
    msg.setTimeStamp(0.503583219816);
    msg.setSource(44045U);
    msg.setSourceEntity(209U);
    msg.setDestination(55399U);
    msg.setDestinationEntity(105U);
    msg.frequency = 1814376224U;
    msg.min_range = 44227U;
    msg.max_range = 51133U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarConfig #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarConfig msg;
    msg.setTimeStamp(0.575684696612);
    msg.setSource(46080U);
    msg.setSourceEntity(11U);
    msg.setDestination(43869U);
    msg.setDestinationEntity(133U);
    msg.frequency = 2002201139U;
    msg.min_range = 34787U;
    msg.max_range = 9549U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarConfig #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarConfig msg;
    msg.setTimeStamp(0.208939107332);
    msg.setSource(16870U);
    msg.setSourceEntity(228U);
    msg.setDestination(64057U);
    msg.setDestinationEntity(40U);
    msg.frequency = 518235375U;
    msg.min_range = 61806U;
    msg.max_range = 16177U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarConfig #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarData msg;
    msg.setTimeStamp(0.727285570299);
    msg.setSource(21605U);
    msg.setSourceEntity(237U);
    msg.setDestination(60784U);
    msg.setDestinationEntity(179U);
    msg.type = 174U;
    msg.frequency = 117765632U;
    msg.min_range = 43090U;
    msg.max_range = 48553U;
    msg.bits_per_point = 110U;
    msg.scale_factor = 0.0268534461797;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.22843651406;
    tmp_msg_0.beam_height = 0.33005832239;
    msg.beam_config.push_back(tmp_msg_0);
    const char tmp_msg_1[] = {66, -69, 13, 110, -81, -105, 23, 111, 76, -5, 46, -94, -7, 59, 125, -47, 61, 66, 53, 29, 17, -67, -34, -68, 70, -37, 10, 65, 113, 106, -62, -11, 42, 113, -2, -64, -108, 37, 90, -77, -4, 93, -24, -67, -94, -30, 84, -61, -118, -78, -107, 99, -52, -125, -6, 105, -115, -39, -126, -113, 26, -22, -108, -19, 99, -35, 95, -80, 1, -104, -95, -74, -78, -104, -64, 3, -46, 67, 52, 27, 124, 101, 39, 31, 23, -87, -63, 124, -82, -57, -114, 9, -37, 88, 39, 26, 78, 22, -124, 1, 59, 29, -122, -1, 113, -20, 84, -27, 14, -58, 117, -104, -14};
    msg.data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarData msg;
    msg.setTimeStamp(0.606199291765);
    msg.setSource(46219U);
    msg.setSourceEntity(57U);
    msg.setDestination(11966U);
    msg.setDestinationEntity(213U);
    msg.type = 148U;
    msg.frequency = 1403689360U;
    msg.min_range = 17354U;
    msg.max_range = 43472U;
    msg.bits_per_point = 158U;
    msg.scale_factor = 0.497055857041;
    IMC::BeamConfig tmp_msg_0;
    tmp_msg_0.beam_width = 0.0274092621631;
    tmp_msg_0.beam_height = 0.137134026275;
    msg.beam_config.push_back(tmp_msg_0);
    const char tmp_msg_1[] = {-22, -93, -12, 71, 79, -35, 111, -83, 81, 0, -21, 64, 58, -67, -61, 108, -25, -96, 11, -28, -5, -107, 76, 58, 79, -113, -97, -25, 28, 119, -78, -67, 123, -122, 40, -26, -124, -25, -49, 80, 118, 65, 11, -98, 122, 80, -91, -76, -47, 8, 53, 5, -91, 54, 111, 78, -106, -53, -73, 88, -85, -72, -72, -102, 18, 38, 27, -10, 23, -76, 76, -62, 96, 8, 91, -44, -58, -23, -87, 103, 26, 26, 110, 121, 67, 62, -116, -65, 83, 117, -3, -119};
    msg.data.assign(tmp_msg_1, tmp_msg_1 + sizeof(tmp_msg_1));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SonarData msg;
    msg.setTimeStamp(0.154697186472);
    msg.setSource(7614U);
    msg.setSourceEntity(179U);
    msg.setDestination(48374U);
    msg.setDestinationEntity(178U);
    msg.type = 196U;
    msg.frequency = 4155408704U;
    msg.min_range = 19321U;
    msg.max_range = 35613U;
    msg.bits_per_point = 42U;
    msg.scale_factor = 0.767726130604;
    const char tmp_msg_0[] = {88, -110, 126, -90, 35, -117, 118, -71, 9, 80, -60, 6, 60, -127, 121, -44, 32, -40, -71, -74, 62, -104, 24, 49, -88, -24, 25, 3, 77, 45, -86, -38, 2, -60, 37, 66, -52, 84, 73, -89, 103, -64, 15, 70, -125, -43, -4, 92, -54, 68, -39, -119, -51, -63, -46, 60, 95, 104, -18, 89, 99, -75, 96, 56, 56, -111, 46, -69, -49, -11, 78, 70, 77, -60, 45, -61, 119, -37, 92, 109, 112, 98, -56, 43, 90, 6, 16, -80, 19, -65, 8, -76, 70, 36, 110, -75, 13, -56, -116, -114, 112, 85, -8, 96, -115, -24, -28, -110, -9, 29, 40, 34, -89, -112, -115, 12, -12, -8, 4, 22, 37, -41, 106, 116, -72, -17, 72, -86, 125, -17, 42, -12, -88, -14, 9, 88, -43, 108};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SonarData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pulse msg;
    msg.setTimeStamp(0.800157648885);
    msg.setSource(14522U);
    msg.setSourceEntity(126U);
    msg.setDestination(50015U);
    msg.setDestinationEntity(92U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pulse #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pulse msg;
    msg.setTimeStamp(0.574419899288);
    msg.setSource(20275U);
    msg.setSourceEntity(5U);
    msg.setDestination(8197U);
    msg.setDestinationEntity(207U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pulse #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Pulse msg;
    msg.setTimeStamp(0.767532474026);
    msg.setSource(49084U);
    msg.setSourceEntity(139U);
    msg.setDestination(53852U);
    msg.setDestinationEntity(134U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Pulse #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PulseDetectionControl msg;
    msg.setTimeStamp(0.864254364065);
    msg.setSource(30098U);
    msg.setSourceEntity(146U);
    msg.setDestination(3329U);
    msg.setDestinationEntity(86U);
    msg.op = 183U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PulseDetectionControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PulseDetectionControl msg;
    msg.setTimeStamp(0.076785787156);
    msg.setSource(40332U);
    msg.setSourceEntity(245U);
    msg.setDestination(60022U);
    msg.setDestinationEntity(182U);
    msg.op = 67U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PulseDetectionControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PulseDetectionControl msg;
    msg.setTimeStamp(0.673440461545);
    msg.setSource(3785U);
    msg.setSourceEntity(38U);
    msg.setDestination(4567U);
    msg.setDestinationEntity(92U);
    msg.op = 186U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PulseDetectionControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FuelLevel msg;
    msg.setTimeStamp(0.797576245626);
    msg.setSource(21777U);
    msg.setSourceEntity(182U);
    msg.setDestination(48488U);
    msg.setDestinationEntity(90U);
    msg.value = 0.291060388941;
    msg.confidence = 0.500000002031;
    msg.opmodes.assign("BKAKTQUZYKZBXJLKMCEQJNPNCKMNSHBCHHVLAPLBZNHTGRIQOSNYRPWD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FuelLevel #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FuelLevel msg;
    msg.setTimeStamp(0.606857949587);
    msg.setSource(61686U);
    msg.setSourceEntity(71U);
    msg.setDestination(3879U);
    msg.setDestinationEntity(102U);
    msg.value = 0.606546962387;
    msg.confidence = 0.00624824348866;
    msg.opmodes.assign("HMVXBBQFYRAIRWPWDVHYGSHHNIKOQRPNNVPQZRIUKIJTTAUFOVYPQADAHMCQISLJRKAYXDLBOUKNWTCTOJPWHZPKFLYZCCJBLURKXJWPAJENF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FuelLevel #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FuelLevel msg;
    msg.setTimeStamp(0.345207613292);
    msg.setSource(53204U);
    msg.setSourceEntity(179U);
    msg.setDestination(43265U);
    msg.setDestinationEntity(126U);
    msg.value = 0.469882716793;
    msg.confidence = 0.402803273163;
    msg.opmodes.assign("IHJRBZRNONNQKMDBIDNMSEHMMCPBNPYTMLPMOFMGVFVUAKHNGQAPOXSRERCYYWWTLLFROCSQWOINVBWYDIWBEXTGQMHIPFHAUKADUHEVWZBQZEJGSXIAWCXWCUJGYLMJFXVGVTLCAEVKSRCNFGSRWBKGUFXJCMNKKUSCTVB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FuelLevel #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsNavData msg;
    msg.setTimeStamp(0.357565797186);
    msg.setSource(4696U);
    msg.setSourceEntity(66U);
    msg.setDestination(64643U);
    msg.setDestinationEntity(206U);
    msg.itow = 4006928737U;
    msg.lat = 0.718162486609;
    msg.lon = 0.693605479419;
    msg.height_ell = 0.567021488324;
    msg.height_sea = 0.125336897437;
    msg.hacc = 0.774110239547;
    msg.vacc = 0.932211634442;
    msg.vel_n = 0.415511748396;
    msg.vel_e = 0.359804063834;
    msg.vel_d = 0.807885318882;
    msg.speed = 0.165218623388;
    msg.gspeed = 0.414144569363;
    msg.heading = 0.0823771458497;
    msg.sacc = 0.928415551908;
    msg.cacc = 0.928158570715;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsNavData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsNavData msg;
    msg.setTimeStamp(0.853778355656);
    msg.setSource(23598U);
    msg.setSourceEntity(13U);
    msg.setDestination(26605U);
    msg.setDestinationEntity(144U);
    msg.itow = 1354166883U;
    msg.lat = 0.654636605615;
    msg.lon = 0.223607670483;
    msg.height_ell = 0.96060020423;
    msg.height_sea = 0.748914659222;
    msg.hacc = 0.342212403304;
    msg.vacc = 0.538217566934;
    msg.vel_n = 0.58077942915;
    msg.vel_e = 0.608971286967;
    msg.vel_d = 0.145337028324;
    msg.speed = 0.24919979218;
    msg.gspeed = 0.293164433079;
    msg.heading = 0.986225291304;
    msg.sacc = 0.822099642371;
    msg.cacc = 0.468025330732;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsNavData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsNavData msg;
    msg.setTimeStamp(0.125698511703);
    msg.setSource(19121U);
    msg.setSourceEntity(50U);
    msg.setDestination(7427U);
    msg.setDestinationEntity(228U);
    msg.itow = 1356538304U;
    msg.lat = 0.869970498859;
    msg.lon = 0.087885839158;
    msg.height_ell = 0.713443427009;
    msg.height_sea = 0.896298527199;
    msg.hacc = 0.243409993994;
    msg.vacc = 0.422421423898;
    msg.vel_n = 0.468765527883;
    msg.vel_e = 0.883683504287;
    msg.vel_d = 0.539703376964;
    msg.speed = 0.624705941109;
    msg.gspeed = 0.138371302073;
    msg.heading = 0.988341345278;
    msg.sacc = 0.475981211332;
    msg.cacc = 0.225538775493;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsNavData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ServoPosition msg;
    msg.setTimeStamp(0.0726711258973);
    msg.setSource(47881U);
    msg.setSourceEntity(92U);
    msg.setDestination(40448U);
    msg.setDestinationEntity(189U);
    msg.id = 86U;
    msg.value = 0.796327575345;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ServoPosition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ServoPosition msg;
    msg.setTimeStamp(0.0967027616188);
    msg.setSource(7097U);
    msg.setSourceEntity(75U);
    msg.setDestination(42488U);
    msg.setDestinationEntity(215U);
    msg.id = 125U;
    msg.value = 0.292792630782;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ServoPosition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ServoPosition msg;
    msg.setTimeStamp(0.516977420066);
    msg.setSource(61582U);
    msg.setSourceEntity(93U);
    msg.setDestination(3815U);
    msg.setDestinationEntity(155U);
    msg.id = 233U;
    msg.value = 0.0437619103512;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ServoPosition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DeviceState msg;
    msg.setTimeStamp(0.842060271103);
    msg.setSource(59295U);
    msg.setSourceEntity(70U);
    msg.setDestination(21716U);
    msg.setDestinationEntity(241U);
    msg.x = 0.636245217028;
    msg.y = 0.314160495309;
    msg.z = 0.136213554756;
    msg.phi = 0.0106216749657;
    msg.theta = 0.368200238082;
    msg.psi = 0.518040000635;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DeviceState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DeviceState msg;
    msg.setTimeStamp(0.98996061683);
    msg.setSource(33192U);
    msg.setSourceEntity(173U);
    msg.setDestination(15400U);
    msg.setDestinationEntity(19U);
    msg.x = 0.00745273896697;
    msg.y = 0.539089652691;
    msg.z = 0.845765318275;
    msg.phi = 0.783207893556;
    msg.theta = 0.432105829354;
    msg.psi = 0.718738313395;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DeviceState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DeviceState msg;
    msg.setTimeStamp(0.443770970738);
    msg.setSource(33416U);
    msg.setSourceEntity(9U);
    msg.setDestination(40055U);
    msg.setDestinationEntity(10U);
    msg.x = 0.976997933296;
    msg.y = 0.334980042844;
    msg.z = 0.744642666092;
    msg.phi = 0.899152586808;
    msg.theta = 0.847395868517;
    msg.psi = 0.58877339334;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DeviceState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::BeamConfig msg;
    msg.setTimeStamp(0.595438605208);
    msg.setSource(57754U);
    msg.setSourceEntity(7U);
    msg.setDestination(55272U);
    msg.setDestinationEntity(85U);
    msg.beam_width = 0.448715382431;
    msg.beam_height = 0.549821177432;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("BeamConfig #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::BeamConfig msg;
    msg.setTimeStamp(0.60167291802);
    msg.setSource(27200U);
    msg.setSourceEntity(222U);
    msg.setDestination(3829U);
    msg.setDestinationEntity(199U);
    msg.beam_width = 0.536100835377;
    msg.beam_height = 0.463420138834;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("BeamConfig #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::BeamConfig msg;
    msg.setTimeStamp(0.16133403321);
    msg.setSource(25334U);
    msg.setSourceEntity(224U);
    msg.setDestination(65504U);
    msg.setDestinationEntity(178U);
    msg.beam_width = 0.330458563286;
    msg.beam_height = 0.170733574261;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("BeamConfig #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CameraZoom msg;
    msg.setTimeStamp(0.329612346496);
    msg.setSource(64921U);
    msg.setSourceEntity(2U);
    msg.setDestination(11796U);
    msg.setDestinationEntity(136U);
    msg.id = 17U;
    msg.zoom = 23U;
    msg.action = 70U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CameraZoom #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CameraZoom msg;
    msg.setTimeStamp(0.90197277636);
    msg.setSource(47862U);
    msg.setSourceEntity(219U);
    msg.setDestination(4092U);
    msg.setDestinationEntity(70U);
    msg.id = 85U;
    msg.zoom = 244U;
    msg.action = 9U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CameraZoom #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CameraZoom msg;
    msg.setTimeStamp(0.661431310454);
    msg.setSource(17031U);
    msg.setSourceEntity(209U);
    msg.setDestination(64231U);
    msg.setDestinationEntity(207U);
    msg.id = 214U;
    msg.zoom = 37U;
    msg.action = 9U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CameraZoom #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetThrusterActuation msg;
    msg.setTimeStamp(0.441580666011);
    msg.setSource(26633U);
    msg.setSourceEntity(204U);
    msg.setDestination(33301U);
    msg.setDestinationEntity(249U);
    msg.id = 46U;
    msg.value = 0.967813841518;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetThrusterActuation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetThrusterActuation msg;
    msg.setTimeStamp(0.0808789535696);
    msg.setSource(24806U);
    msg.setSourceEntity(5U);
    msg.setDestination(61692U);
    msg.setDestinationEntity(152U);
    msg.id = 201U;
    msg.value = 0.800254227731;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetThrusterActuation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetThrusterActuation msg;
    msg.setTimeStamp(0.177292006125);
    msg.setSource(55915U);
    msg.setSourceEntity(223U);
    msg.setDestination(11608U);
    msg.setDestinationEntity(50U);
    msg.id = 144U;
    msg.value = 0.18477890812;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetThrusterActuation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetServoPosition msg;
    msg.setTimeStamp(0.381001241015);
    msg.setSource(58497U);
    msg.setSourceEntity(46U);
    msg.setDestination(11480U);
    msg.setDestinationEntity(30U);
    msg.id = 189U;
    msg.value = 0.451022986378;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetServoPosition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetServoPosition msg;
    msg.setTimeStamp(0.923566703352);
    msg.setSource(53189U);
    msg.setSourceEntity(17U);
    msg.setDestination(30017U);
    msg.setDestinationEntity(96U);
    msg.id = 89U;
    msg.value = 0.976373550763;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetServoPosition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetServoPosition msg;
    msg.setTimeStamp(0.766947535605);
    msg.setSource(45041U);
    msg.setSourceEntity(200U);
    msg.setDestination(29274U);
    msg.setDestinationEntity(212U);
    msg.id = 235U;
    msg.value = 0.965386964049;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetServoPosition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetControlSurfaceDeflection msg;
    msg.setTimeStamp(0.68029482019);
    msg.setSource(38769U);
    msg.setSourceEntity(229U);
    msg.setDestination(17867U);
    msg.setDestinationEntity(174U);
    msg.id = 24U;
    msg.angle = 0.203361945564;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetControlSurfaceDeflection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetControlSurfaceDeflection msg;
    msg.setTimeStamp(0.503864582989);
    msg.setSource(18852U);
    msg.setSourceEntity(63U);
    msg.setDestination(53847U);
    msg.setDestinationEntity(178U);
    msg.id = 235U;
    msg.angle = 0.00278648727198;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetControlSurfaceDeflection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetControlSurfaceDeflection msg;
    msg.setTimeStamp(0.125670756265);
    msg.setSource(39643U);
    msg.setSourceEntity(75U);
    msg.setDestination(12061U);
    msg.setDestinationEntity(238U);
    msg.id = 234U;
    msg.angle = 0.854567660111;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetControlSurfaceDeflection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActionsRequest msg;
    msg.setTimeStamp(0.833746941252);
    msg.setSource(39846U);
    msg.setSourceEntity(163U);
    msg.setDestination(48935U);
    msg.setDestinationEntity(35U);
    msg.op = 67U;
    msg.actions.assign("JSMKURDLLXIJFMBUK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActionsRequest #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActionsRequest msg;
    msg.setTimeStamp(0.538892764423);
    msg.setSource(50831U);
    msg.setSourceEntity(226U);
    msg.setDestination(17159U);
    msg.setDestinationEntity(41U);
    msg.op = 93U;
    msg.actions.assign("RHINORLETBMQSQOGNAUHCTFIUZZMLFTXJNPCEOYEFPHTJYOUEWBNWHJHIPHKPTKNVGEXSOCOYOSFPFMAKKGAEFPOUNAAZLGBJVMGHCBI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActionsRequest #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActionsRequest msg;
    msg.setTimeStamp(0.000598394018617);
    msg.setSource(44747U);
    msg.setSourceEntity(242U);
    msg.setDestination(20784U);
    msg.setDestinationEntity(50U);
    msg.op = 206U;
    msg.actions.assign("YQYIPKZWNTCQEVNMIRABDIKFMUYFXKNAWHJYTRXLDGEGXKVBVVQDUCWGMTULHYNBTWNWYQPBFZTXVUTAVPGHITPQBIRPUROJYVHZGEFPJLONSPNSOCJAGLZOYNXUJGKKVAMJALOQRSDGKSHCNIKODMRLMFFLLWMZHHCDRAEWDIHBELMWLVBMRWSECGRPVHYBNRXGCSZOSQACUXSJDEQOTDOAXFSJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActionsRequest #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActions msg;
    msg.setTimeStamp(0.747525759396);
    msg.setSource(62540U);
    msg.setSourceEntity(146U);
    msg.setDestination(6515U);
    msg.setDestinationEntity(154U);
    msg.actions.assign("GZHPPSLIYVWZPAWTERGFAYKMROTYIWHJPUHSBXQNREXGOEBDJOSGXHBXI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActions #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActions msg;
    msg.setTimeStamp(0.393915900479);
    msg.setSource(62234U);
    msg.setSourceEntity(132U);
    msg.setDestination(55351U);
    msg.setDestinationEntity(26U);
    msg.actions.assign("ABGYSDGFTNBEZAGQSTUSAVMUTONZFOWUESOLLEBHHKCNMCQSFTIGVRBHJDXFPFKIFDQWEBHZZUNEQWFRIZRLNHVPOKSAUWAODGMRLDNYQYJMRNBGCQHVVCWEJBPGYUVGTJHWYYCDAMCKBTDMPVDDNICSFTRYQKZZZL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActions #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteActions msg;
    msg.setTimeStamp(0.988454743174);
    msg.setSource(39986U);
    msg.setSourceEntity(117U);
    msg.setDestination(12934U);
    msg.setDestinationEntity(180U);
    msg.actions.assign("QGELHCTMETXPIGQZGIRINLHDXXIMPUCLHPYMABIYCBCJNVOOUJLS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteActions #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ButtonEvent msg;
    msg.setTimeStamp(0.913963564883);
    msg.setSource(56939U);
    msg.setSourceEntity(122U);
    msg.setDestination(44480U);
    msg.setDestinationEntity(122U);
    msg.button = 215U;
    msg.value = 74U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ButtonEvent #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ButtonEvent msg;
    msg.setTimeStamp(0.869229531279);
    msg.setSource(55588U);
    msg.setSourceEntity(183U);
    msg.setDestination(60572U);
    msg.setDestinationEntity(50U);
    msg.button = 56U;
    msg.value = 214U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ButtonEvent #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ButtonEvent msg;
    msg.setTimeStamp(0.992518026055);
    msg.setSource(27703U);
    msg.setSourceEntity(62U);
    msg.setDestination(44818U);
    msg.setDestinationEntity(73U);
    msg.button = 69U;
    msg.value = 164U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ButtonEvent #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LcdControl msg;
    msg.setTimeStamp(0.386610333028);
    msg.setSource(47091U);
    msg.setSourceEntity(136U);
    msg.setDestination(41298U);
    msg.setDestinationEntity(178U);
    msg.op = 65U;
    msg.text.assign("AJSPVWFPICCVNECZJSOHDQXXMCAHIMOWBZSFIELNVRPMTEPKHTYSYLXVFQTWJWRORXDZUEGHIRQYMCMDPBYTTRCPIUOLAIUZDTOASHGQKFMALWZUYNGYRVYGZYMBXUSTPRJHOJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LcdControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LcdControl msg;
    msg.setTimeStamp(0.952568212545);
    msg.setSource(12584U);
    msg.setSourceEntity(213U);
    msg.setDestination(64377U);
    msg.setDestinationEntity(221U);
    msg.op = 115U;
    msg.text.assign("YCEEZETWWMEYPNMCNGVRORYCOFNJNSRYMJCPJLPSQSXSLXQAQJTFUKCJVLDOAWNWEXLCSFICKWOWUHMHGUHBARHPGCZQYBDTILHAWJGLBJJKIFUABLVWZWXMVVDBUZIVDCUEOESMBQHXPSDNZBXEPGIYRINBFNMINUOKUTKYOPQCBFTZOPMHDKLHTRGFPT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LcdControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LcdControl msg;
    msg.setTimeStamp(0.997159549632);
    msg.setSource(30649U);
    msg.setSourceEntity(197U);
    msg.setDestination(3979U);
    msg.setDestinationEntity(172U);
    msg.op = 97U;
    msg.text.assign("MBNFZTPTWQMMXCDYTIBJUIVUDTEZLSLXZZQNYMUGWUOOEGBWTAXKTHOJKUARLWZRRIRSBXPFHNAYSXFELHYVHAXPDFBAZBKGLNPPEWSNJXEICMWLIYMVRIE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LcdControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerOperation msg;
    msg.setTimeStamp(0.797947071692);
    msg.setSource(53515U);
    msg.setSourceEntity(46U);
    msg.setDestination(61369U);
    msg.setDestinationEntity(0U);
    msg.op = 112U;
    msg.time_remain = 0.886898737327;
    msg.sched_time = 0.70638976221;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerOperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerOperation msg;
    msg.setTimeStamp(0.656349369139);
    msg.setSource(273U);
    msg.setSourceEntity(206U);
    msg.setDestination(63777U);
    msg.setDestinationEntity(111U);
    msg.op = 80U;
    msg.time_remain = 0.0430294619341;
    msg.sched_time = 0.529529193155;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerOperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerOperation msg;
    msg.setTimeStamp(0.693302435921);
    msg.setSource(12362U);
    msg.setSourceEntity(220U);
    msg.setDestination(39392U);
    msg.setDestinationEntity(67U);
    msg.op = 144U;
    msg.time_remain = 0.972027627983;
    msg.sched_time = 0.288068902584;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerOperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelControl msg;
    msg.setTimeStamp(0.736864890179);
    msg.setSource(1771U);
    msg.setSourceEntity(138U);
    msg.setDestination(63244U);
    msg.setDestinationEntity(0U);
    msg.name.assign("SDPQCCECSEZPBYAHHARQVDFLBWFORVRIHGJFIPBPEUFZRLUUCPMNIDOHLSIIVXXCQFXWDRKDEROHYYLOXCWJ");
    msg.op = 153U;
    msg.sched_time = 0.292447890265;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelControl msg;
    msg.setTimeStamp(0.177587141043);
    msg.setSource(14767U);
    msg.setSourceEntity(28U);
    msg.setDestination(39803U);
    msg.setDestinationEntity(215U);
    msg.name.assign("WEISUDBNLYTUXFYIUGOIXPPEPYZZYXJCXEBDJCSESTVYEHKFUKRRXARMHGJUCVSADSRUWERCSOQWGZAHBHJOLJMAGINGZMLQNWVAPWZODLEJUILFBEKAMLRVLHCKDUZOQFFHJMIBMSKLRVPD");
    msg.op = 244U;
    msg.sched_time = 0.27848508007;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelControl msg;
    msg.setTimeStamp(0.876321092095);
    msg.setSource(14073U);
    msg.setSourceEntity(101U);
    msg.setDestination(38214U);
    msg.setDestinationEntity(33U);
    msg.name.assign("DYUUVJDYEURSHGSWMHXXSQTWOFRELGVXCUYESIQQKPYBXIBDNVTATNTGZHIAFJVASGGHYMBOWHMHNUCCZCNWCMAPBMPNBEOPSRWPPLFARZZLGICEHTANFVVNZRXJSLFBBJKDQKHQFSYQAMRBTVPWFQPAJGFXLNYKKWFVDHMOZILCSRVTMZCLUWKXKRKRTWJZURDDBEOENVJSUMTXCHNEOYUCGIJMOU");
    msg.op = 252U;
    msg.sched_time = 0.843257110576;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryPowerChannelState msg;
    msg.setTimeStamp(0.954837321953);
    msg.setSource(4962U);
    msg.setSourceEntity(242U);
    msg.setDestination(60877U);
    msg.setDestinationEntity(187U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryPowerChannelState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryPowerChannelState msg;
    msg.setTimeStamp(0.133885096953);
    msg.setSource(52448U);
    msg.setSourceEntity(190U);
    msg.setDestination(30437U);
    msg.setDestinationEntity(89U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryPowerChannelState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryPowerChannelState msg;
    msg.setTimeStamp(0.70422322423);
    msg.setSource(31644U);
    msg.setSourceEntity(125U);
    msg.setDestination(41563U);
    msg.setDestinationEntity(200U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryPowerChannelState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelState msg;
    msg.setTimeStamp(0.475097428023);
    msg.setSource(31302U);
    msg.setSourceEntity(18U);
    msg.setDestination(10965U);
    msg.setDestinationEntity(159U);
    msg.name.assign("SERUOJCHFXZBRWNPHQDOTFRLSTXTFKOXUSCBIKISQDAOAHTBZUKTRPYFXPWEXNDIZLYABRGZMAGDGEHJDCZOXFBKDKZWIVJWLUCQWWDMMQOLOOIFQWWAYMZAUVTNNQVADZLBVMBLHALJMETDNMXGUXSCFYSEFXQZFRIRIMVTFYCCLPGGJRYVQGICNNSPSVANHTJPGKNOVEBPARYGPHKJWSJVZGQJMLKPPYOKWSEUKUETNECBRYVUBHCMIHXHIQ");
    msg.state = 235U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelState msg;
    msg.setTimeStamp(0.683192151145);
    msg.setSource(36741U);
    msg.setSourceEntity(46U);
    msg.setDestination(57276U);
    msg.setDestinationEntity(177U);
    msg.name.assign("KCNXROLNLQQRTSMDYEDACAQDXRSUNGOMHRHBZEWPSITCIUCMNXWQJSIFDYSKALLUPMJHQOFIBBZXVFONJCQRGRXZPBGKWHTECIKTFPZKQPCMSNWIJGYUEBTLEXGVSWYNYDNAFKVPQFQEMQKTMAVFFJVPYOXTSIDBXDGJHVLURKUVYZHAIYHBKZAARYFTDZBSHSVCPEWOWWUTGHARDGLFUXDNEYKBZPJRMMOIG");
    msg.state = 28U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PowerChannelState msg;
    msg.setTimeStamp(0.0530432470249);
    msg.setSource(2607U);
    msg.setSourceEntity(103U);
    msg.setDestination(62499U);
    msg.setDestinationEntity(48U);
    msg.name.assign("POVHHDFFBGMEDKEXOSLVHNPSQILMLWYIZYRLTXCYCSTUGMNWWBZTBQQSDMCPDZLEYTNBMLFNOJMUKDUORXKQYCZHJNSXKICT");
    msg.state = 103U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PowerChannelState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LedBrightness msg;
    msg.setTimeStamp(0.616608395237);
    msg.setSource(39674U);
    msg.setSourceEntity(41U);
    msg.setDestination(48396U);
    msg.setDestinationEntity(82U);
    msg.name.assign("WVVSNXAHJOAZLJEJMDLIYJNFPNZZUSNABKQZCBLBFYDHWPUWAPM");
    msg.value = 45U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LedBrightness #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LedBrightness msg;
    msg.setTimeStamp(0.778653018471);
    msg.setSource(40707U);
    msg.setSourceEntity(193U);
    msg.setDestination(58831U);
    msg.setDestinationEntity(45U);
    msg.name.assign("PJNPPTMQKHJBCAYZYNDXVZTORIEDWVEFOLSVZCIMRPXVVKSXFYAUWDNMXPTFQYUWGVFHSHBGTMMUAQPBDLCZSKVECWLDALDUIXYJNZHJHCMODKVETKCGYCBMUOIIBUOHMVFTSTJZTRAXAIOBSRHILSSPTEXGPZUBVDGWNAMYRJBFUGZEBQXLZRWWIFDLOLQRQQQIJCBGKESPSNE");
    msg.value = 62U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LedBrightness #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LedBrightness msg;
    msg.setTimeStamp(0.0982312159275);
    msg.setSource(8547U);
    msg.setSourceEntity(189U);
    msg.setDestination(64581U);
    msg.setDestinationEntity(42U);
    msg.name.assign("EPXCPCJNBEPZCEQKJIFRGBCFGFNMLSBJEVDRAWTMPAUERSVYXWYAWLKCOJFQOATMSDIPCUUSNLRBKLTAESIXOICOMILUDBDZLPW");
    msg.value = 248U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LedBrightness #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryLedBrightness msg;
    msg.setTimeStamp(0.4794982524);
    msg.setSource(21798U);
    msg.setSourceEntity(233U);
    msg.setDestination(48900U);
    msg.setDestinationEntity(132U);
    msg.name.assign("KGRTEQGLVWQFTZNLCFHWYCXDOYSILWUN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryLedBrightness #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryLedBrightness msg;
    msg.setTimeStamp(0.253869034278);
    msg.setSource(2193U);
    msg.setSourceEntity(113U);
    msg.setDestination(19214U);
    msg.setDestinationEntity(207U);
    msg.name.assign("ZOOKYTRMKJBWPAQUTGMIHHGZDENVMTKSXQBEQMISHZLCDCUCPISJAVTSZKHEFNJUIJNGOQIXILKFGMTENNZALRYFNXETPEORLQALPACBCQVHWVFUHMVRKTMCVXUUOODWOYKPKBXDXJEZJWLZFGEDPJUHOS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryLedBrightness #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryLedBrightness msg;
    msg.setTimeStamp(0.593871078454);
    msg.setSource(40113U);
    msg.setSourceEntity(203U);
    msg.setDestination(32096U);
    msg.setDestinationEntity(39U);
    msg.name.assign("OECEPKKOULAKYFHTQZUHXWTAUBMGNBVPMQLAYMWBEGYLMOSCDRRZVDTNTWRPZBGMOIVCRJCFZSDYZWTTCQIIHEXFJWKDZUGQEFOYSFHFAIISPIUDXUCQPRYHDHJWXYGXNALQRCVAJOWYVJGSKSNKJAOYLYIMXXRGDFTPMTDJUZKVUBWKEEDLOMGXXATIVTUKNQCHPHMLRPWVCBJJJSAPWFQBOBVGHNEUXDNIRE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryLedBrightness #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetLedBrightness msg;
    msg.setTimeStamp(0.271709054842);
    msg.setSource(23958U);
    msg.setSourceEntity(156U);
    msg.setDestination(36771U);
    msg.setDestinationEntity(105U);
    msg.name.assign("VJRCLRLSMXTXUNBSUBCCNIBPOJYWQSMAGWHKNERXXHMHOXVFHMNMTQOEIABJGKZJSEZAG");
    msg.value = 200U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetLedBrightness #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetLedBrightness msg;
    msg.setTimeStamp(0.496092298177);
    msg.setSource(62392U);
    msg.setSourceEntity(94U);
    msg.setDestination(7454U);
    msg.setDestinationEntity(73U);
    msg.name.assign("WQLGXWYFBFTCOXWTVWLEDHHRPUTTSVCKEOPOXPTZGBSIRUTICVUKYGHTJRWGGQEHNVBLNUBOCP");
    msg.value = 134U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetLedBrightness #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetLedBrightness msg;
    msg.setTimeStamp(0.149970382359);
    msg.setSource(49331U);
    msg.setSourceEntity(161U);
    msg.setDestination(36935U);
    msg.setDestinationEntity(138U);
    msg.name.assign("WIRRCZGUQFWVITJJLIA");
    msg.value = 191U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetLedBrightness #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedState msg;
    msg.setTimeStamp(0.80468755646);
    msg.setSource(11472U);
    msg.setSourceEntity(73U);
    msg.setDestination(7842U);
    msg.setDestinationEntity(118U);
    msg.lat = 0.0611727725921;
    msg.lon = 0.739444295627;
    msg.height = 0.931583868707;
    msg.x = 0.544470686173;
    msg.y = 0.134769135628;
    msg.z = 0.414827292467;
    msg.phi = 0.865832347006;
    msg.theta = 0.394283629037;
    msg.psi = 0.084935258985;
    msg.u = 0.319707656195;
    msg.v = 0.145702468897;
    msg.w = 0.828166896766;
    msg.vx = 0.980997183037;
    msg.vy = 0.817621994061;
    msg.vz = 0.324403653654;
    msg.p = 0.616990136784;
    msg.q = 0.309842535244;
    msg.r = 0.575108520319;
    msg.depth = 0.892282556833;
    msg.alt = 0.669803419651;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedState msg;
    msg.setTimeStamp(0.929629641221);
    msg.setSource(41105U);
    msg.setSourceEntity(132U);
    msg.setDestination(47333U);
    msg.setDestinationEntity(221U);
    msg.lat = 0.198757004156;
    msg.lon = 0.158308010692;
    msg.height = 0.960081159615;
    msg.x = 0.13813326591;
    msg.y = 0.393172988933;
    msg.z = 0.170454546743;
    msg.phi = 0.854759156641;
    msg.theta = 0.801149412893;
    msg.psi = 0.555727617515;
    msg.u = 0.473369534735;
    msg.v = 0.343608379861;
    msg.w = 0.919316879583;
    msg.vx = 0.643071323573;
    msg.vy = 0.268608414614;
    msg.vz = 0.0138677396147;
    msg.p = 0.654823807311;
    msg.q = 0.747486020912;
    msg.r = 0.530119949583;
    msg.depth = 0.677446764681;
    msg.alt = 0.753125785445;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedState msg;
    msg.setTimeStamp(0.299706816256);
    msg.setSource(34582U);
    msg.setSourceEntity(222U);
    msg.setDestination(17952U);
    msg.setDestinationEntity(163U);
    msg.lat = 0.978732275907;
    msg.lon = 0.758419090355;
    msg.height = 0.649524206065;
    msg.x = 0.994070954378;
    msg.y = 0.990217759086;
    msg.z = 0.327240969925;
    msg.phi = 0.465369551754;
    msg.theta = 0.531671126811;
    msg.psi = 0.593258565449;
    msg.u = 0.953076103528;
    msg.v = 0.583361801324;
    msg.w = 0.636691438058;
    msg.vx = 0.35608608146;
    msg.vy = 0.769483168314;
    msg.vz = 0.37709077719;
    msg.p = 0.676197865637;
    msg.q = 0.0757419738847;
    msg.r = 0.23420402664;
    msg.depth = 0.261528927864;
    msg.alt = 0.899578885995;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedStreamVelocity msg;
    msg.setTimeStamp(0.750396752023);
    msg.setSource(46676U);
    msg.setSourceEntity(222U);
    msg.setDestination(3612U);
    msg.setDestinationEntity(160U);
    msg.x = 0.751743163759;
    msg.y = 0.797268427264;
    msg.z = 0.894684251277;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedStreamVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedStreamVelocity msg;
    msg.setTimeStamp(0.886686149421);
    msg.setSource(35519U);
    msg.setSourceEntity(224U);
    msg.setDestination(21770U);
    msg.setDestinationEntity(157U);
    msg.x = 0.0777484539529;
    msg.y = 0.829372983665;
    msg.z = 0.34954280605;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedStreamVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EstimatedStreamVelocity msg;
    msg.setTimeStamp(0.270717371109);
    msg.setSource(16833U);
    msg.setSourceEntity(171U);
    msg.setDestination(23124U);
    msg.setDestinationEntity(85U);
    msg.x = 0.622367011636;
    msg.y = 0.0452120894704;
    msg.z = 0.342428644911;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EstimatedStreamVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IndicatedSpeed msg;
    msg.setTimeStamp(0.890903581284);
    msg.setSource(26291U);
    msg.setSourceEntity(149U);
    msg.setDestination(2111U);
    msg.setDestinationEntity(247U);
    msg.value = 0.539046551525;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IndicatedSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IndicatedSpeed msg;
    msg.setTimeStamp(0.141400232289);
    msg.setSource(19889U);
    msg.setSourceEntity(35U);
    msg.setDestination(48516U);
    msg.setDestinationEntity(53U);
    msg.value = 0.67726290105;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IndicatedSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IndicatedSpeed msg;
    msg.setTimeStamp(0.704802350713);
    msg.setSource(33338U);
    msg.setSourceEntity(121U);
    msg.setDestination(16347U);
    msg.setDestinationEntity(219U);
    msg.value = 0.88257010521;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IndicatedSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrueSpeed msg;
    msg.setTimeStamp(0.84295631925);
    msg.setSource(32877U);
    msg.setSourceEntity(81U);
    msg.setDestination(32145U);
    msg.setDestinationEntity(14U);
    msg.value = 0.0748655860581;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrueSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrueSpeed msg;
    msg.setTimeStamp(0.614472499635);
    msg.setSource(11807U);
    msg.setSourceEntity(109U);
    msg.setDestination(401U);
    msg.setDestinationEntity(196U);
    msg.value = 0.980582807681;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrueSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrueSpeed msg;
    msg.setTimeStamp(0.252763066743);
    msg.setSource(49199U);
    msg.setSourceEntity(214U);
    msg.setDestination(21380U);
    msg.setDestinationEntity(163U);
    msg.value = 0.621663698634;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrueSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationUncertainty msg;
    msg.setTimeStamp(0.565708476935);
    msg.setSource(10340U);
    msg.setSourceEntity(128U);
    msg.setDestination(32288U);
    msg.setDestinationEntity(103U);
    msg.x = 0.602927215411;
    msg.y = 0.827994189123;
    msg.z = 0.431664560676;
    msg.phi = 0.614744803338;
    msg.theta = 0.474032085519;
    msg.psi = 0.995889391602;
    msg.p = 0.287374304892;
    msg.q = 0.817524303423;
    msg.r = 0.894369394423;
    msg.u = 0.274168996416;
    msg.v = 0.0257287639996;
    msg.w = 0.731479142418;
    msg.bias_psi = 0.999314626731;
    msg.bias_r = 0.040055944754;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationUncertainty #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationUncertainty msg;
    msg.setTimeStamp(0.893212475937);
    msg.setSource(11463U);
    msg.setSourceEntity(139U);
    msg.setDestination(65302U);
    msg.setDestinationEntity(73U);
    msg.x = 0.0565935984547;
    msg.y = 0.631381698589;
    msg.z = 0.022128947688;
    msg.phi = 0.727654411351;
    msg.theta = 0.321232143769;
    msg.psi = 0.77587867604;
    msg.p = 0.648393677477;
    msg.q = 0.578020979035;
    msg.r = 0.521667097307;
    msg.u = 0.41029699117;
    msg.v = 0.0859506205985;
    msg.w = 0.0423600438202;
    msg.bias_psi = 0.504638942232;
    msg.bias_r = 0.0948629280688;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationUncertainty #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationUncertainty msg;
    msg.setTimeStamp(0.0418544201572);
    msg.setSource(10682U);
    msg.setSourceEntity(21U);
    msg.setDestination(31632U);
    msg.setDestinationEntity(246U);
    msg.x = 0.553524155613;
    msg.y = 0.21665452812;
    msg.z = 0.990928480178;
    msg.phi = 0.0959043713788;
    msg.theta = 0.4081785682;
    msg.psi = 0.0528332783283;
    msg.p = 0.501346017029;
    msg.q = 0.480295272314;
    msg.r = 0.731377245884;
    msg.u = 0.799117456386;
    msg.v = 0.292393583062;
    msg.w = 0.816272503471;
    msg.bias_psi = 0.478588651602;
    msg.bias_r = 0.092730386698;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationUncertainty #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationData msg;
    msg.setTimeStamp(0.396028261286);
    msg.setSource(792U);
    msg.setSourceEntity(55U);
    msg.setDestination(60504U);
    msg.setDestinationEntity(83U);
    msg.bias_psi = 0.494357796303;
    msg.bias_r = 0.121939042891;
    msg.cog = 0.188839101291;
    msg.cyaw = 0.989857242439;
    msg.lbl_rej_level = 0.961085256892;
    msg.gps_rej_level = 0.165110884667;
    msg.custom_x = 0.0602691826657;
    msg.custom_y = 0.659166955907;
    msg.custom_z = 0.84641390642;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationData msg;
    msg.setTimeStamp(0.471300760081);
    msg.setSource(41513U);
    msg.setSourceEntity(95U);
    msg.setDestination(23653U);
    msg.setDestinationEntity(42U);
    msg.bias_psi = 0.997518011607;
    msg.bias_r = 0.386360291504;
    msg.cog = 0.786270701009;
    msg.cyaw = 0.372011302853;
    msg.lbl_rej_level = 0.789041980546;
    msg.gps_rej_level = 0.883476719107;
    msg.custom_x = 0.232137052375;
    msg.custom_y = 0.0631495790119;
    msg.custom_z = 0.735393628576;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationData msg;
    msg.setTimeStamp(0.550036091651);
    msg.setSource(59931U);
    msg.setSourceEntity(127U);
    msg.setDestination(1298U);
    msg.setDestinationEntity(185U);
    msg.bias_psi = 0.584015214568;
    msg.bias_r = 0.163487680336;
    msg.cog = 0.401283763658;
    msg.cyaw = 0.00889566282875;
    msg.lbl_rej_level = 0.427804155102;
    msg.gps_rej_level = 0.647740104673;
    msg.custom_x = 0.853846614706;
    msg.custom_y = 0.435950558106;
    msg.custom_z = 0.469210762612;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRejection msg;
    msg.setTimeStamp(0.241763182183);
    msg.setSource(33320U);
    msg.setSourceEntity(121U);
    msg.setDestination(34860U);
    msg.setDestinationEntity(233U);
    msg.utc_time = 0.626595730342;
    msg.reason = 153U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRejection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRejection msg;
    msg.setTimeStamp(0.617772560897);
    msg.setSource(44523U);
    msg.setSourceEntity(237U);
    msg.setDestination(64777U);
    msg.setDestinationEntity(24U);
    msg.utc_time = 0.30496019902;
    msg.reason = 85U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRejection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GpsFixRejection msg;
    msg.setTimeStamp(0.886011648829);
    msg.setSource(19517U);
    msg.setSourceEntity(139U);
    msg.setDestination(3410U);
    msg.setDestinationEntity(39U);
    msg.utc_time = 0.613856959732;
    msg.reason = 30U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GpsFixRejection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRangeAcceptance msg;
    msg.setTimeStamp(0.697589888754);
    msg.setSource(37577U);
    msg.setSourceEntity(35U);
    msg.setDestination(23747U);
    msg.setDestinationEntity(12U);
    msg.id = 88U;
    msg.range = 0.220252792454;
    msg.acceptance = 157U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRangeAcceptance #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRangeAcceptance msg;
    msg.setTimeStamp(0.430613365345);
    msg.setSource(14415U);
    msg.setSourceEntity(169U);
    msg.setDestination(46546U);
    msg.setDestinationEntity(207U);
    msg.id = 22U;
    msg.range = 0.283650622347;
    msg.acceptance = 235U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRangeAcceptance #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblRangeAcceptance msg;
    msg.setTimeStamp(0.599648903448);
    msg.setSource(9768U);
    msg.setSourceEntity(84U);
    msg.setDestination(27759U);
    msg.setDestinationEntity(173U);
    msg.id = 209U;
    msg.range = 0.700094403554;
    msg.acceptance = 68U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblRangeAcceptance #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DvlRejection msg;
    msg.setTimeStamp(0.482400787064);
    msg.setSource(27722U);
    msg.setSourceEntity(64U);
    msg.setDestination(7605U);
    msg.setDestinationEntity(241U);
    msg.type = 127U;
    msg.reason = 167U;
    msg.value = 0.141228363626;
    msg.timestep = 0.621295631023;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DvlRejection #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DvlRejection msg;
    msg.setTimeStamp(0.450058841914);
    msg.setSource(56171U);
    msg.setSourceEntity(91U);
    msg.setDestination(49188U);
    msg.setDestinationEntity(243U);
    msg.type = 98U;
    msg.reason = 178U;
    msg.value = 0.470653111483;
    msg.timestep = 0.0120846603983;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DvlRejection #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DvlRejection msg;
    msg.setTimeStamp(0.614270231701);
    msg.setSource(47463U);
    msg.setSourceEntity(243U);
    msg.setDestination(10943U);
    msg.setDestinationEntity(217U);
    msg.type = 192U;
    msg.reason = 37U;
    msg.value = 0.162954067034;
    msg.timestep = 0.189780129896;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DvlRejection #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationReset msg;
    msg.setTimeStamp(0.25079918372);
    msg.setSource(16660U);
    msg.setSourceEntity(46U);
    msg.setDestination(60374U);
    msg.setDestinationEntity(29U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationReset #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationReset msg;
    msg.setTimeStamp(0.034764547883);
    msg.setSource(21011U);
    msg.setSourceEntity(93U);
    msg.setDestination(5389U);
    msg.setDestinationEntity(138U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationReset #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::NavigationReset msg;
    msg.setTimeStamp(0.12594259285);
    msg.setSource(47594U);
    msg.setSourceEntity(165U);
    msg.setDestination(54568U);
    msg.setDestinationEntity(220U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("NavigationReset #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblEstimate msg;
    msg.setTimeStamp(0.684555300567);
    msg.setSource(9542U);
    msg.setSourceEntity(75U);
    msg.setDestination(9194U);
    msg.setDestinationEntity(154U);
    msg.beacon.assign("BLXZPRCNWSZZKABHOQDDNBWIYWWAPUBJJMVLOPEECZWETXBTJLYEAIPGOWDEJXKJGFKTVRZFLRDGHDQTMWMJIYHTUTCYCPLVHRUMGOFGDDPFLAIMKXKLCNFNCEVMCQXPCONKDLVMQBKVDSTSJHMJQZCZAUQUVWHCIGHONGVJUEMBOFSAUZLHBYNRKIKISQVXHRBRRAFXNHBIYYASEVNRSXEAYLTQEJWOSISOPTRIFGXPUUQPFOYNYQGZ");
    msg.x = 0.392653516487;
    msg.y = 0.256585712408;
    msg.depth = 0.34243661925;
    msg.var_x = 0.429872166955;
    msg.var_y = 0.474821513851;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblEstimate #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblEstimate msg;
    msg.setTimeStamp(0.19012301861);
    msg.setSource(6858U);
    msg.setSourceEntity(183U);
    msg.setDestination(40575U);
    msg.setDestinationEntity(166U);
    msg.beacon.assign("BAQOUPXTLDYBIXJGOTOPUHBNEHZTEOXSHKDEMQFKOE");
    msg.x = 0.581696505964;
    msg.y = 0.825912265541;
    msg.depth = 0.620992860561;
    msg.var_x = 0.671891846261;
    msg.var_y = 0.575915002399;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblEstimate #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LblEstimate msg;
    msg.setTimeStamp(0.964259612073);
    msg.setSource(41082U);
    msg.setSourceEntity(15U);
    msg.setDestination(37072U);
    msg.setDestinationEntity(148U);
    msg.beacon.assign("UXDVSRIXHRVJJLYPPPTJOWIBIXCKCRVKLMKYZHGKBYUQJJTQBZJZOZPNEYKWXNVXFMFLGQMISUNNWCFQSIWGULIWTOQEGCUE");
    msg.x = 0.695732760278;
    msg.y = 0.647944296568;
    msg.depth = 0.621124996028;
    msg.var_x = 0.658457777197;
    msg.var_y = 0.10453883137;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LblEstimate #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeading msg;
    msg.setTimeStamp(0.826873993761);
    msg.setSource(45109U);
    msg.setSourceEntity(134U);
    msg.setDestination(3364U);
    msg.setDestinationEntity(11U);
    msg.value = 0.294806340822;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeading #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeading msg;
    msg.setTimeStamp(0.0138373126727);
    msg.setSource(62085U);
    msg.setSourceEntity(109U);
    msg.setDestination(57546U);
    msg.setDestinationEntity(126U);
    msg.value = 0.00719796693931;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeading #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeading msg;
    msg.setTimeStamp(0.234734144467);
    msg.setSource(41112U);
    msg.setSourceEntity(26U);
    msg.setDestination(16230U);
    msg.setDestinationEntity(161U);
    msg.value = 0.398273612224;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeading #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredZ msg;
    msg.setTimeStamp(0.561511425042);
    msg.setSource(6161U);
    msg.setSourceEntity(216U);
    msg.setDestination(9305U);
    msg.setDestinationEntity(173U);
    msg.value = 0.464211170558;
    msg.z_units = 70U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredZ #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredZ msg;
    msg.setTimeStamp(0.860478381171);
    msg.setSource(60630U);
    msg.setSourceEntity(82U);
    msg.setDestination(21808U);
    msg.setDestinationEntity(97U);
    msg.value = 0.365944528909;
    msg.z_units = 157U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredZ #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredZ msg;
    msg.setTimeStamp(0.32871827785);
    msg.setSource(9253U);
    msg.setSourceEntity(180U);
    msg.setDestination(11554U);
    msg.setDestinationEntity(106U);
    msg.value = 0.115185196294;
    msg.z_units = 235U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredZ #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredSpeed msg;
    msg.setTimeStamp(0.102646282999);
    msg.setSource(33614U);
    msg.setSourceEntity(31U);
    msg.setDestination(50397U);
    msg.setDestinationEntity(54U);
    msg.value = 0.814271594959;
    msg.speed_units = 153U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredSpeed #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredSpeed msg;
    msg.setTimeStamp(0.59395734656);
    msg.setSource(2647U);
    msg.setSourceEntity(79U);
    msg.setDestination(47529U);
    msg.setDestinationEntity(55U);
    msg.value = 0.21598006025;
    msg.speed_units = 99U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredSpeed #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredSpeed msg;
    msg.setTimeStamp(0.532410060642);
    msg.setSource(57419U);
    msg.setSourceEntity(170U);
    msg.setDestination(42734U);
    msg.setDestinationEntity(109U);
    msg.value = 0.852375267286;
    msg.speed_units = 48U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredSpeed #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredRoll msg;
    msg.setTimeStamp(0.766884177036);
    msg.setSource(46780U);
    msg.setSourceEntity(209U);
    msg.setDestination(46519U);
    msg.setDestinationEntity(153U);
    msg.value = 0.0036517722826;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredRoll #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredRoll msg;
    msg.setTimeStamp(0.046442489431);
    msg.setSource(58764U);
    msg.setSourceEntity(32U);
    msg.setDestination(16948U);
    msg.setDestinationEntity(190U);
    msg.value = 0.738555007514;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredRoll #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredRoll msg;
    msg.setTimeStamp(0.701806323306);
    msg.setSource(62662U);
    msg.setSourceEntity(182U);
    msg.setDestination(23563U);
    msg.setDestinationEntity(58U);
    msg.value = 0.975482567149;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredRoll #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPitch msg;
    msg.setTimeStamp(0.016167110195);
    msg.setSource(64757U);
    msg.setSourceEntity(117U);
    msg.setDestination(7995U);
    msg.setDestinationEntity(179U);
    msg.value = 0.177263495949;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPitch #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPitch msg;
    msg.setTimeStamp(0.435754410034);
    msg.setSource(5856U);
    msg.setSourceEntity(213U);
    msg.setDestination(8936U);
    msg.setDestinationEntity(245U);
    msg.value = 0.669756474501;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPitch #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPitch msg;
    msg.setTimeStamp(0.342357827786);
    msg.setSource(4746U);
    msg.setSourceEntity(143U);
    msg.setDestination(40083U);
    msg.setDestinationEntity(156U);
    msg.value = 0.618105688449;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPitch #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVerticalRate msg;
    msg.setTimeStamp(0.208203462715);
    msg.setSource(36822U);
    msg.setSourceEntity(135U);
    msg.setDestination(15268U);
    msg.setDestinationEntity(206U);
    msg.value = 0.166132943492;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVerticalRate #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVerticalRate msg;
    msg.setTimeStamp(0.260480427919);
    msg.setSource(40447U);
    msg.setSourceEntity(117U);
    msg.setDestination(13137U);
    msg.setDestinationEntity(48U);
    msg.value = 0.448223323673;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVerticalRate #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVerticalRate msg;
    msg.setTimeStamp(0.697908912038);
    msg.setSource(53707U);
    msg.setSourceEntity(186U);
    msg.setDestination(61980U);
    msg.setDestinationEntity(67U);
    msg.value = 0.834994420873;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVerticalRate #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPath msg;
    msg.setTimeStamp(0.302062800077);
    msg.setSource(2218U);
    msg.setSourceEntity(143U);
    msg.setDestination(29589U);
    msg.setDestinationEntity(198U);
    msg.start_lat = 0.537308921555;
    msg.start_lon = 0.814916820148;
    msg.start_z = 0.00407265596335;
    msg.start_z_units = 39U;
    msg.end_lat = 0.34215215859;
    msg.end_lon = 0.842381138893;
    msg.end_z = 0.13032589483;
    msg.end_z_units = 180U;
    msg.speed = 0.525984236022;
    msg.speed_units = 119U;
    msg.lradius = 0.0846240233224;
    msg.flags = 101U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPath #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPath msg;
    msg.setTimeStamp(0.569982861805);
    msg.setSource(38935U);
    msg.setSourceEntity(234U);
    msg.setDestination(8575U);
    msg.setDestinationEntity(224U);
    msg.start_lat = 0.147204644028;
    msg.start_lon = 0.903967357432;
    msg.start_z = 0.0772577029038;
    msg.start_z_units = 34U;
    msg.end_lat = 0.617077534803;
    msg.end_lon = 0.563806988754;
    msg.end_z = 0.563186121094;
    msg.end_z_units = 29U;
    msg.speed = 0.159862521166;
    msg.speed_units = 16U;
    msg.lradius = 0.763356150635;
    msg.flags = 137U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPath #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredPath msg;
    msg.setTimeStamp(0.175566187295);
    msg.setSource(13542U);
    msg.setSourceEntity(250U);
    msg.setDestination(8626U);
    msg.setDestinationEntity(85U);
    msg.start_lat = 0.186005360126;
    msg.start_lon = 0.0648589541727;
    msg.start_z = 0.0113942523265;
    msg.start_z_units = 83U;
    msg.end_lat = 0.469249813989;
    msg.end_lon = 0.268228903929;
    msg.end_z = 0.661844430737;
    msg.end_z_units = 86U;
    msg.speed = 0.87647753845;
    msg.speed_units = 60U;
    msg.lradius = 0.402239408267;
    msg.flags = 27U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredPath #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredControl msg;
    msg.setTimeStamp(0.675917107304);
    msg.setSource(2374U);
    msg.setSourceEntity(78U);
    msg.setDestination(22375U);
    msg.setDestinationEntity(8U);
    msg.x = 0.0449575970843;
    msg.y = 0.632594222432;
    msg.z = 0.315331350327;
    msg.k = 0.496514328748;
    msg.m = 0.988097605023;
    msg.n = 0.95913048126;
    msg.flags = 231U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredControl msg;
    msg.setTimeStamp(0.690392719101);
    msg.setSource(39962U);
    msg.setSourceEntity(22U);
    msg.setDestination(25699U);
    msg.setDestinationEntity(76U);
    msg.x = 0.266399153007;
    msg.y = 0.315576450834;
    msg.z = 0.48177114784;
    msg.k = 0.0349347000768;
    msg.m = 0.0714468721601;
    msg.n = 0.650750213066;
    msg.flags = 162U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredControl msg;
    msg.setTimeStamp(0.330887723288);
    msg.setSource(26533U);
    msg.setSourceEntity(99U);
    msg.setDestination(35592U);
    msg.setDestinationEntity(246U);
    msg.x = 0.608679496734;
    msg.y = 0.735012417627;
    msg.z = 0.292696930908;
    msg.k = 0.663455212372;
    msg.m = 0.309941407361;
    msg.n = 0.31313947492;
    msg.flags = 154U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeadingRate msg;
    msg.setTimeStamp(0.824392701642);
    msg.setSource(29701U);
    msg.setSourceEntity(214U);
    msg.setDestination(17933U);
    msg.setDestinationEntity(1U);
    msg.value = 0.269980037227;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeadingRate #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeadingRate msg;
    msg.setTimeStamp(0.159990964055);
    msg.setSource(63762U);
    msg.setSourceEntity(86U);
    msg.setDestination(53003U);
    msg.setDestinationEntity(171U);
    msg.value = 0.65423326757;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeadingRate #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredHeadingRate msg;
    msg.setTimeStamp(0.079081612687);
    msg.setSource(52379U);
    msg.setSourceEntity(193U);
    msg.setDestination(8789U);
    msg.setDestinationEntity(41U);
    msg.value = 0.146421238312;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredHeadingRate #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVelocity msg;
    msg.setTimeStamp(0.357295540491);
    msg.setSource(54487U);
    msg.setSourceEntity(106U);
    msg.setDestination(52172U);
    msg.setDestinationEntity(242U);
    msg.u = 0.664186765056;
    msg.v = 0.522359229181;
    msg.w = 0.17215850173;
    msg.p = 0.613375401742;
    msg.q = 0.735737941938;
    msg.r = 0.723314104495;
    msg.flags = 212U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVelocity #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVelocity msg;
    msg.setTimeStamp(0.306655874865);
    msg.setSource(15299U);
    msg.setSourceEntity(84U);
    msg.setDestination(50267U);
    msg.setDestinationEntity(184U);
    msg.u = 0.123032938135;
    msg.v = 0.656694248913;
    msg.w = 0.383401093263;
    msg.p = 0.0848256659221;
    msg.q = 0.0517661091922;
    msg.r = 0.758799255387;
    msg.flags = 191U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVelocity #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::DesiredVelocity msg;
    msg.setTimeStamp(0.459605697868);
    msg.setSource(17633U);
    msg.setSourceEntity(163U);
    msg.setDestination(51217U);
    msg.setDestinationEntity(23U);
    msg.u = 0.321584821803;
    msg.v = 0.810289375577;
    msg.w = 0.118943907641;
    msg.p = 0.868106001442;
    msg.q = 0.909273723137;
    msg.r = 0.470527446069;
    msg.flags = 136U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("DesiredVelocity #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathControlState msg;
    msg.setTimeStamp(0.812268668341);
    msg.setSource(37636U);
    msg.setSourceEntity(125U);
    msg.setDestination(27143U);
    msg.setDestinationEntity(25U);
    msg.start_lat = 0.872361323872;
    msg.start_lon = 0.267607921088;
    msg.start_z = 0.93124899647;
    msg.start_z_units = 214U;
    msg.end_lat = 0.777586649626;
    msg.end_lon = 0.637787092583;
    msg.end_z = 0.305844153419;
    msg.end_z_units = 29U;
    msg.lradius = 0.756486124544;
    msg.flags = 23U;
    msg.x = 0.584366238161;
    msg.y = 0.311469149447;
    msg.z = 0.304694145503;
    msg.vx = 0.500122339485;
    msg.vy = 0.0127760485306;
    msg.vz = 0.606259320101;
    msg.course_error = 0.081396004337;
    msg.eta = 34318U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathControlState msg;
    msg.setTimeStamp(0.461626341337);
    msg.setSource(35025U);
    msg.setSourceEntity(130U);
    msg.setDestination(43053U);
    msg.setDestinationEntity(129U);
    msg.start_lat = 0.824109544224;
    msg.start_lon = 0.524348855846;
    msg.start_z = 0.979750340827;
    msg.start_z_units = 62U;
    msg.end_lat = 0.323092574084;
    msg.end_lon = 0.507647034471;
    msg.end_z = 0.470375219009;
    msg.end_z_units = 208U;
    msg.lradius = 0.151968176819;
    msg.flags = 49U;
    msg.x = 0.518884530206;
    msg.y = 0.505005921886;
    msg.z = 0.475000580504;
    msg.vx = 0.674628450365;
    msg.vy = 0.675248391924;
    msg.vz = 0.381328650741;
    msg.course_error = 0.848152771351;
    msg.eta = 45573U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathControlState msg;
    msg.setTimeStamp(0.0313039203231);
    msg.setSource(54093U);
    msg.setSourceEntity(217U);
    msg.setDestination(8619U);
    msg.setDestinationEntity(62U);
    msg.start_lat = 0.110550389198;
    msg.start_lon = 0.0849057950344;
    msg.start_z = 0.427016623314;
    msg.start_z_units = 157U;
    msg.end_lat = 0.886156987652;
    msg.end_lon = 0.240957211515;
    msg.end_z = 0.217387156997;
    msg.end_z_units = 72U;
    msg.lradius = 0.987738390617;
    msg.flags = 149U;
    msg.x = 0.276033119621;
    msg.y = 0.734096346502;
    msg.z = 0.517124329841;
    msg.vx = 0.526042285197;
    msg.vy = 0.12058469672;
    msg.vz = 0.604494962005;
    msg.course_error = 0.938822215652;
    msg.eta = 24811U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AllocatedControlTorques msg;
    msg.setTimeStamp(0.815017605555);
    msg.setSource(28573U);
    msg.setSourceEntity(131U);
    msg.setDestination(37421U);
    msg.setDestinationEntity(134U);
    msg.k = 0.805520782783;
    msg.m = 0.513893358433;
    msg.n = 0.0779877411458;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AllocatedControlTorques #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AllocatedControlTorques msg;
    msg.setTimeStamp(0.715744261924);
    msg.setSource(16774U);
    msg.setSourceEntity(177U);
    msg.setDestination(588U);
    msg.setDestinationEntity(232U);
    msg.k = 0.411762083044;
    msg.m = 0.232430665059;
    msg.n = 0.800269479324;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AllocatedControlTorques #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::AllocatedControlTorques msg;
    msg.setTimeStamp(0.794597427197);
    msg.setSource(49321U);
    msg.setSourceEntity(52U);
    msg.setDestination(36770U);
    msg.setDestinationEntity(180U);
    msg.k = 0.542551272821;
    msg.m = 0.713189361699;
    msg.n = 0.494590748218;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("AllocatedControlTorques #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlParcel msg;
    msg.setTimeStamp(0.117365449755);
    msg.setSource(35574U);
    msg.setSourceEntity(99U);
    msg.setDestination(43940U);
    msg.setDestinationEntity(170U);
    msg.p = 0.141361824854;
    msg.i = 0.0904633056673;
    msg.d = 0.835624970726;
    msg.a = 0.755659910181;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlParcel #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlParcel msg;
    msg.setTimeStamp(0.292386436141);
    msg.setSource(56693U);
    msg.setSourceEntity(215U);
    msg.setDestination(27070U);
    msg.setDestinationEntity(187U);
    msg.p = 0.878078703561;
    msg.i = 0.55629907858;
    msg.d = 0.485072869128;
    msg.a = 0.18029574107;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlParcel #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlParcel msg;
    msg.setTimeStamp(0.796671071934);
    msg.setSource(34044U);
    msg.setSourceEntity(139U);
    msg.setDestination(7823U);
    msg.setDestinationEntity(254U);
    msg.p = 0.305320938026;
    msg.i = 0.603948514968;
    msg.d = 0.452041077423;
    msg.a = 0.973263909791;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlParcel #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Brake msg;
    msg.setTimeStamp(0.849268658647);
    msg.setSource(47294U);
    msg.setSourceEntity(169U);
    msg.setDestination(46539U);
    msg.setDestinationEntity(186U);
    msg.op = 153U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Brake #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Brake msg;
    msg.setTimeStamp(0.995797167488);
    msg.setSource(39944U);
    msg.setSourceEntity(129U);
    msg.setDestination(58317U);
    msg.setDestinationEntity(19U);
    msg.op = 163U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Brake #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Brake msg;
    msg.setTimeStamp(0.341959461077);
    msg.setSource(28247U);
    msg.setSourceEntity(45U);
    msg.setDestination(46161U);
    msg.setDestinationEntity(10U);
    msg.op = 18U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Brake #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Goto msg;
    msg.setTimeStamp(0.109689722282);
    msg.setSource(21324U);
    msg.setSourceEntity(68U);
    msg.setDestination(55799U);
    msg.setDestinationEntity(145U);
    msg.timeout = 47090U;
    msg.lat = 0.759251821247;
    msg.lon = 0.0615609517757;
    msg.z = 0.21642151942;
    msg.z_units = 180U;
    msg.speed = 0.945304659531;
    msg.speed_units = 33U;
    msg.roll = 0.0360230414312;
    msg.pitch = 0.43101110365;
    msg.yaw = 0.909201173202;
    msg.custom.assign("LAYRJYRMXSKEFONJLIMRVVGOOTSBXMXRZJOYEPTFIWORYMZAWTQCXHVELRAQQWJAUQHWWDODUHXIUROHSLOLCPNPAIEZGNDNGYCCSLBAGIV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Goto #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Goto msg;
    msg.setTimeStamp(0.937492714188);
    msg.setSource(4099U);
    msg.setSourceEntity(224U);
    msg.setDestination(4258U);
    msg.setDestinationEntity(134U);
    msg.timeout = 26219U;
    msg.lat = 0.547058385233;
    msg.lon = 0.774544318295;
    msg.z = 0.0915885569573;
    msg.z_units = 218U;
    msg.speed = 0.114955222609;
    msg.speed_units = 187U;
    msg.roll = 0.0169681685944;
    msg.pitch = 0.0726724814786;
    msg.yaw = 0.991324023917;
    msg.custom.assign("OFQWIKRGSAARWBJMWJUGUYJJELOHTOLCHFBBWMKEZLTLNFECUEANBQXLXNXUMJHYYXZRXJDOAVHJIQNDKVPVDKWKVDOQISWN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Goto #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Goto msg;
    msg.setTimeStamp(0.118952381133);
    msg.setSource(17742U);
    msg.setSourceEntity(235U);
    msg.setDestination(20665U);
    msg.setDestinationEntity(29U);
    msg.timeout = 51166U;
    msg.lat = 0.253221614119;
    msg.lon = 0.651709463374;
    msg.z = 0.710959360245;
    msg.z_units = 20U;
    msg.speed = 0.0367060347095;
    msg.speed_units = 10U;
    msg.roll = 0.205818013355;
    msg.pitch = 0.797801659004;
    msg.yaw = 0.339187732297;
    msg.custom.assign("DIKYLIARXFOAEREMQOSEIFLPXXRYXBRPHCSSFKNPBAIVHQYZMKGIAQRAMLZCSITEAZYIVUEQFFTGWISZTQDHDABLPYVXAOQOTMVPJGDKUNNOOEGHGUHCQZRUWCNDZQPFVDGKYBSPJBJIUZLENXVPRDKNSZPEHYDGJDVKXUOJKRFGLHYPASOWIFLVUBNLQDZFCOXWMVWJTOAMYWLWBJTCBJGHWUKNTMK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Goto #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopUp msg;
    msg.setTimeStamp(0.377748695536);
    msg.setSource(64109U);
    msg.setSourceEntity(32U);
    msg.setDestination(6266U);
    msg.setDestinationEntity(45U);
    msg.timeout = 47484U;
    msg.lat = 0.161141069997;
    msg.lon = 0.56972937102;
    msg.z = 0.668062754189;
    msg.z_units = 106U;
    msg.speed = 0.00582430515584;
    msg.speed_units = 81U;
    msg.duration = 2391U;
    msg.radius = 0.0783759010293;
    msg.flags = 88U;
    msg.custom.assign("CDJFWRLOSOQDDGSOXJFYZGECWGDKTBGBHVIUSDBXSMXEORHBQASNBKOHIJKMLXJWLIAEBILVY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopUp #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopUp msg;
    msg.setTimeStamp(0.366696774642);
    msg.setSource(34719U);
    msg.setSourceEntity(183U);
    msg.setDestination(33588U);
    msg.setDestinationEntity(118U);
    msg.timeout = 46523U;
    msg.lat = 0.180287646332;
    msg.lon = 0.794710841596;
    msg.z = 0.331577437306;
    msg.z_units = 196U;
    msg.speed = 0.241534410407;
    msg.speed_units = 220U;
    msg.duration = 4582U;
    msg.radius = 0.728311313167;
    msg.flags = 184U;
    msg.custom.assign("KKIEZLPDWABHSXFOLPZQHJEVBOGXPFQNDEEMRBTCHWVODJTRBGKUER");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopUp #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopUp msg;
    msg.setTimeStamp(0.00118776384209);
    msg.setSource(20558U);
    msg.setSourceEntity(229U);
    msg.setDestination(36117U);
    msg.setDestinationEntity(54U);
    msg.timeout = 40826U;
    msg.lat = 0.705503418014;
    msg.lon = 0.743326901154;
    msg.z = 0.97918956098;
    msg.z_units = 246U;
    msg.speed = 0.868189044427;
    msg.speed_units = 243U;
    msg.duration = 29601U;
    msg.radius = 0.202942169437;
    msg.flags = 157U;
    msg.custom.assign("KOTFDGAJJFYMBMIVNBHUAEZANWCJWXLNYCRZHHKRJFIIXAHCMVCVRLXLGQDZGEAGYEUUQWBWOPQVZJUNIKBDREFYRLPIBUEFTCZUDYWZOPOWVSVDIMZFXACZSSROLGBXNPYWENJUXWQDLVISRKNMDQXJHOONGPGWUSHMQBKNPQYMLPLEJJMQXRCDCRTITTKJETBBQYPYXSKTOZLTFHLSGFBUXDDKSCICFPMEV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopUp #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Teleoperation msg;
    msg.setTimeStamp(0.296346952633);
    msg.setSource(56630U);
    msg.setSourceEntity(119U);
    msg.setDestination(56404U);
    msg.setDestinationEntity(108U);
    msg.custom.assign("VZYCYHHRIHW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Teleoperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Teleoperation msg;
    msg.setTimeStamp(0.943166999167);
    msg.setSource(65326U);
    msg.setSourceEntity(53U);
    msg.setDestination(13113U);
    msg.setDestinationEntity(160U);
    msg.custom.assign("DQLANVFFEYCZJCNDWPTRQOCZNXRZXVNOOLWWZLKYEQGFSASCJYEKMIPWJHCWDPXUOVSUTZPIJBEIMWDDHQTXTEUQYMGPXIXDNDINUMRBCWZBERVYGXBTAFOQKIOGSMTHKKUUTOXYIJAURKSBTSPCZGLUNHQWBBRCN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Teleoperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Teleoperation msg;
    msg.setTimeStamp(0.208178972125);
    msg.setSource(45168U);
    msg.setSourceEntity(45U);
    msg.setDestination(3879U);
    msg.setDestinationEntity(51U);
    msg.custom.assign("BVAPFPCEMTAPBJYUILDPTWCWDMTOANLQOYBMDGYTSAYGEMUCFGKTVATVJXONNDGJVMKKWETIWEDWSYIUFMNSYKGLPIQSMQFKCSQUFIPCGNCDNJDYRWNHNORAXFXJRWQPOROJXTDZMQHBYSNUSVLVJRVLCAVQEOCMZSUUHUALRQIZWOFOEAAQZUZHEQRSRGKXFGZHJIMBFPHWGTVRICEPZWXRTBPBILDXCLYZHKX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Teleoperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Loiter msg;
    msg.setTimeStamp(0.336142429928);
    msg.setSource(39248U);
    msg.setSourceEntity(224U);
    msg.setDestination(51132U);
    msg.setDestinationEntity(176U);
    msg.timeout = 14585U;
    msg.lat = 0.349153580526;
    msg.lon = 0.190435183073;
    msg.z = 0.125053735137;
    msg.z_units = 113U;
    msg.duration = 50069U;
    msg.speed = 0.313963701734;
    msg.speed_units = 240U;
    msg.type = 74U;
    msg.radius = 0.402578988802;
    msg.length = 0.857022490425;
    msg.bearing = 0.631695851923;
    msg.direction = 10U;
    msg.custom.assign("EDXHUEPUEKFTMTFOYQVMPZKOWRLWGTPNNOHNLSQCGRNUIFBOYLGOCGTMTCXSXJJWRCUNORDHVPLYXUHZZULZMXEKEUYFASILXCPQDBGCFSPJASYZQVBQSBCHYQOGVENPYLCGJKQZIAKHUPTJHLORLQFXDDWKMDZDTBVPSKKVSIZVVONNAXXWLWSQKXFNUTBAJFWIMIIAAJB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Loiter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Loiter msg;
    msg.setTimeStamp(0.0329387755972);
    msg.setSource(32227U);
    msg.setSourceEntity(44U);
    msg.setDestination(20769U);
    msg.setDestinationEntity(190U);
    msg.timeout = 12055U;
    msg.lat = 0.0893791827056;
    msg.lon = 0.996952453313;
    msg.z = 0.690607858502;
    msg.z_units = 122U;
    msg.duration = 38430U;
    msg.speed = 0.214473541966;
    msg.speed_units = 17U;
    msg.type = 230U;
    msg.radius = 0.271870931663;
    msg.length = 0.998690281324;
    msg.bearing = 0.916463030956;
    msg.direction = 240U;
    msg.custom.assign("VONAUOQQUVYYOWPGECFOSLCXAAEUEKXROILEDPXMLWNBEXPCXVYHEUFUDUCITTFVZHDRSBIYXHRPVYLTUENBPKAYMQROIRSJTETVMSMJBRHDQNFHRJWVTOTAOFCFGSBYWJQWGNWJLIGN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Loiter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Loiter msg;
    msg.setTimeStamp(0.25269483207);
    msg.setSource(19539U);
    msg.setSourceEntity(28U);
    msg.setDestination(25425U);
    msg.setDestinationEntity(90U);
    msg.timeout = 34630U;
    msg.lat = 0.584937811972;
    msg.lon = 0.334713393848;
    msg.z = 0.368775996089;
    msg.z_units = 243U;
    msg.duration = 53351U;
    msg.speed = 0.920935117306;
    msg.speed_units = 242U;
    msg.type = 41U;
    msg.radius = 0.449674910102;
    msg.length = 0.80683594886;
    msg.bearing = 0.880274467269;
    msg.direction = 248U;
    msg.custom.assign("QTNVOHVQPQVCLEUDUXJLQIPMSGUSJUWJEFLFWVSLTSKZSNNVRPRMDBLZKCXJRKRYMZAWLFLYMXEDGNGIA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Loiter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IdleManeuver msg;
    msg.setTimeStamp(0.898657318824);
    msg.setSource(4185U);
    msg.setSourceEntity(244U);
    msg.setDestination(28416U);
    msg.setDestinationEntity(83U);
    msg.duration = 7785U;
    msg.custom.assign("PVCACPXQURRQTAHTCEELLWNSWKZGZYWSJJTOCNSQEDHRNUUTVIYFGUBEHMSVICDJAVHBQOOVNJOMLBCULZAQYLEVAACHPOZLDBDDAUFOVYPJPWFRUKKSMXGLSGSAJQBMFHMZKNYVJMRPXIIHTLOGRUMEFSMEYUZLQXWTGWZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IdleManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IdleManeuver msg;
    msg.setTimeStamp(0.635545828132);
    msg.setSource(35079U);
    msg.setSourceEntity(93U);
    msg.setDestination(51308U);
    msg.setDestinationEntity(169U);
    msg.duration = 63521U;
    msg.custom.assign("DSVIKEKKNCUFIQANBGLRZBYEFWUIUGCKMVHRRMFTHKIXCPMMGBURIYITLKXABHXHOJOYNJMOEHYEQFZQGJWFZVIZXWNQXSZYYZCZDTSCTHJDNDAEJABVGHVDOWJBFPBOSLOUOPBTMUQOEWFUKDCNQKSGXAJJTHNLKBUWRRAFEBEHGWHV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IdleManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::IdleManeuver msg;
    msg.setTimeStamp(0.0574137419454);
    msg.setSource(29583U);
    msg.setSourceEntity(33U);
    msg.setDestination(34719U);
    msg.setDestinationEntity(191U);
    msg.duration = 2697U;
    msg.custom.assign("WBONLFVOPXKMQJEQAZXBDVBVWXRRPGYAEQMUFMWBQAIQSIFOVJFLNAEPCNMZQAKLJTKHGZCDMSKVARLXSBIJYGIAZCZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("IdleManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LowLevelControl msg;
    msg.setTimeStamp(0.120760622152);
    msg.setSource(11786U);
    msg.setSourceEntity(24U);
    msg.setDestination(63825U);
    msg.setDestinationEntity(47U);
    IMC::DesiredRoll tmp_msg_0;
    tmp_msg_0.value = 0.824093815823;
    msg.control.set(tmp_msg_0);
    msg.duration = 32219U;
    msg.custom.assign("BWBMBOPJKKHDVYUFLORINBTEXFPNDCLXRZXDCMHMQYERTOJHNOFABISGAEJFNZWLWVZKDWSDKMEIVTVLLCOCUHPTRKRNGVDLEIVUXYGEUCUPXTCVYLXSHOGFUSTPIPQLFGWFCIJZUGVNYAKMSSVIBSLAFWIHPUHNMMFADRWYTAGYRBRZCNDPWSQXWSQZTPORVQASBXCWOEBUDEIAJGETAPJXCZNAJKIKQKQJHLMFHOZURQYJYZDQXBMQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LowLevelControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LowLevelControl msg;
    msg.setTimeStamp(0.501174991817);
    msg.setSource(24909U);
    msg.setSourceEntity(133U);
    msg.setDestination(41345U);
    msg.setDestinationEntity(84U);
    IMC::DesiredHeading tmp_msg_0;
    tmp_msg_0.value = 0.0679756565169;
    msg.control.set(tmp_msg_0);
    msg.duration = 19915U;
    msg.custom.assign("GJEKFHWHXTQZQIMWYNFWTYKNVRFPKIXYBYULGXYPQTGFGE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LowLevelControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::LowLevelControl msg;
    msg.setTimeStamp(0.034613382268);
    msg.setSource(30055U);
    msg.setSourceEntity(49U);
    msg.setDestination(32314U);
    msg.setDestinationEntity(139U);
    IMC::DesiredHeading tmp_msg_0;
    tmp_msg_0.value = 0.822247212353;
    msg.control.set(tmp_msg_0);
    msg.duration = 30934U;
    msg.custom.assign("TITDGUVPCRYYYMDHFCMJQZOPFSEXSGGTIFDFAFNNSORBBPNQTZSLXTJQWGKROLFYETOLAFMODSAPLCCMTOBSZOPLFVPQOZCMCHKQQUXAQBJRLWXGNHUJYWEOILJHAWSIWNAUJJXYVZVQCUEWSMHPAGKNLVHZKVGZLVEJEPUJBRFXUIKUIMIAGYEBDKZSYWATEHSFRYEDWZKIBORNXDVB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("LowLevelControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rows msg;
    msg.setTimeStamp(0.181715574521);
    msg.setSource(45148U);
    msg.setSourceEntity(166U);
    msg.setDestination(17847U);
    msg.setDestinationEntity(98U);
    msg.timeout = 45358U;
    msg.lat = 0.392810747489;
    msg.lon = 0.195320999293;
    msg.z = 0.656676272641;
    msg.z_units = 38U;
    msg.speed = 0.306149332544;
    msg.speed_units = 119U;
    msg.bearing = 0.58915685459;
    msg.cross_angle = 0.200854587098;
    msg.width = 0.274333302499;
    msg.length = 0.134970032819;
    msg.hstep = 0.87026563569;
    msg.coff = 179U;
    msg.alternation = 17U;
    msg.flags = 181U;
    msg.custom.assign("APVCQFVBCWKDIGIO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rows #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rows msg;
    msg.setTimeStamp(0.343244210115);
    msg.setSource(21135U);
    msg.setSourceEntity(26U);
    msg.setDestination(58888U);
    msg.setDestinationEntity(247U);
    msg.timeout = 26897U;
    msg.lat = 0.609283336705;
    msg.lon = 0.7090514972;
    msg.z = 0.83281211766;
    msg.z_units = 33U;
    msg.speed = 0.947589183002;
    msg.speed_units = 236U;
    msg.bearing = 0.535297439056;
    msg.cross_angle = 0.543458092223;
    msg.width = 0.0744578484045;
    msg.length = 0.772761142771;
    msg.hstep = 0.108342448946;
    msg.coff = 232U;
    msg.alternation = 186U;
    msg.flags = 205U;
    msg.custom.assign("NJTFNLDIOKGZIQNPYGLQCJUTHOKCNWILCFUODYFRXNHHDKVKVQBHHYWEEYJBCWAQFOZCVXTTXXBQWTUAFISSRFBZMJBPNUELWPZR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rows #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Rows msg;
    msg.setTimeStamp(0.602095557902);
    msg.setSource(23469U);
    msg.setSourceEntity(103U);
    msg.setDestination(18316U);
    msg.setDestinationEntity(213U);
    msg.timeout = 41982U;
    msg.lat = 0.405697662744;
    msg.lon = 0.878194626261;
    msg.z = 0.072278861796;
    msg.z_units = 102U;
    msg.speed = 0.440332822187;
    msg.speed_units = 154U;
    msg.bearing = 0.829648070691;
    msg.cross_angle = 0.594010876702;
    msg.width = 0.866368711837;
    msg.length = 0.118855128022;
    msg.hstep = 0.931622121409;
    msg.coff = 45U;
    msg.alternation = 18U;
    msg.flags = 194U;
    msg.custom.assign("CEGAIYOZGCPECMMIDEPNHHVZULVCACWWCMFHFNIXFQYEDGYIRMPPTVQXNUHDXSSKNJEHTPNJTVMSQRFMRXXYOVNKLJGDUJBOWPHEXYRRUYFPSBNULZILBCBOBQGFMLLZEBSTCTBRRQAJSZZOEDSKMULNWPLGWOOQUVPFBFHZAFHSKRAIUDNQKJMPLBJCWIFYRMDTWHAXGJRIJYIDXLAG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Rows #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPath msg;
    msg.setTimeStamp(0.0808065955849);
    msg.setSource(23506U);
    msg.setSourceEntity(196U);
    msg.setDestination(13742U);
    msg.setDestinationEntity(169U);
    msg.timeout = 13212U;
    msg.lat = 0.144417762129;
    msg.lon = 0.471994475775;
    msg.z = 0.397856496797;
    msg.z_units = 128U;
    msg.speed = 0.377317671743;
    msg.speed_units = 42U;
    IMC::PathPoint tmp_msg_0;
    tmp_msg_0.x = 0.638881010841;
    tmp_msg_0.y = 0.672053551581;
    tmp_msg_0.z = 0.404210446998;
    msg.points.push_back(tmp_msg_0);
    msg.custom.assign("QZAQJIAWUCDFAEYCZTQUFMGYHBDHEBZADGPYSSJRBQNQFNHGNUZILRPFZIOZDFDDIMQUDVCKDJAXOPYVRVNTPVROAQUS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPath #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPath msg;
    msg.setTimeStamp(0.456562894542);
    msg.setSource(35574U);
    msg.setSourceEntity(112U);
    msg.setDestination(9513U);
    msg.setDestinationEntity(48U);
    msg.timeout = 10610U;
    msg.lat = 0.834166946319;
    msg.lon = 0.646072116745;
    msg.z = 0.0310329076504;
    msg.z_units = 121U;
    msg.speed = 0.57993618032;
    msg.speed_units = 56U;
    msg.custom.assign("PZQOYYGMCSUXGSWSVEZUKCGMCFWCSUZVHUKOIXDAZXPHLTMJXCFEGVQMGVPHFAFHSORQXXZVNHRTWJRUPYFZOLBNTIT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPath #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowPath msg;
    msg.setTimeStamp(0.866297316399);
    msg.setSource(56396U);
    msg.setSourceEntity(220U);
    msg.setDestination(59250U);
    msg.setDestinationEntity(105U);
    msg.timeout = 41749U;
    msg.lat = 0.054811692359;
    msg.lon = 0.191949266064;
    msg.z = 0.784728895268;
    msg.z_units = 39U;
    msg.speed = 0.186325332008;
    msg.speed_units = 131U;
    IMC::PathPoint tmp_msg_0;
    tmp_msg_0.x = 0.379058350072;
    tmp_msg_0.y = 0.71423722759;
    tmp_msg_0.z = 0.142138201473;
    msg.points.push_back(tmp_msg_0);
    msg.custom.assign("EVYHKNEOCNJJHICQBTAEXMTBGKLWKSWGCFMAAUMPBBZZSFHCJWCKQDDZBFNNUGMGOFFUYJYJSYWVFGTDPKEEVIJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowPath #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathPoint msg;
    msg.setTimeStamp(0.880476270493);
    msg.setSource(11007U);
    msg.setSourceEntity(38U);
    msg.setDestination(41723U);
    msg.setDestinationEntity(220U);
    msg.x = 0.793606968377;
    msg.y = 0.700838813627;
    msg.z = 0.931582295175;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathPoint msg;
    msg.setTimeStamp(0.510782031733);
    msg.setSource(40083U);
    msg.setSourceEntity(194U);
    msg.setDestination(41537U);
    msg.setDestinationEntity(236U);
    msg.x = 0.116870017514;
    msg.y = 0.136004778578;
    msg.z = 0.115075386671;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PathPoint msg;
    msg.setTimeStamp(0.909977737019);
    msg.setSource(39538U);
    msg.setSourceEntity(33U);
    msg.setDestination(41443U);
    msg.setDestinationEntity(178U);
    msg.x = 0.651259493191;
    msg.y = 0.320205045435;
    msg.z = 0.464169144783;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PathPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::YoYo msg;
    msg.setTimeStamp(0.551238227171);
    msg.setSource(30768U);
    msg.setSourceEntity(253U);
    msg.setDestination(6875U);
    msg.setDestinationEntity(38U);
    msg.timeout = 31319U;
    msg.lat = 0.127216548042;
    msg.lon = 0.608594016146;
    msg.z = 0.526041729854;
    msg.z_units = 79U;
    msg.amplitude = 0.903891717708;
    msg.pitch = 0.00167927257436;
    msg.speed = 0.265564386178;
    msg.speed_units = 78U;
    msg.custom.assign("XENJHIWZMVXCPNPMNJCMFVOFKYOEJBIQEGUDFXMTYUTFYQLOVZHPJATABFMFGSKHOHLMXCZZAIJBBYKPUKYSNULFUERZRMTORPPXLGCJNCRLICNWXZXZDQIAZWYVHMLWVOJOGGBGYVKJWKNWQAQSLKEDITOIRWCPBPYGGDBREFSKHYLWDTDHMTDEMAFUXTIAUBSNPEPXVZQBDNQRSEXZNSVKULQSAQROUGRWYAUGTEDHVQTSJRCIH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("YoYo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::YoYo msg;
    msg.setTimeStamp(0.867139408022);
    msg.setSource(3523U);
    msg.setSourceEntity(162U);
    msg.setDestination(35679U);
    msg.setDestinationEntity(168U);
    msg.timeout = 39704U;
    msg.lat = 0.20174157397;
    msg.lon = 0.55433144831;
    msg.z = 0.440124875605;
    msg.z_units = 180U;
    msg.amplitude = 0.543729283821;
    msg.pitch = 0.268789288794;
    msg.speed = 0.529835280603;
    msg.speed_units = 76U;
    msg.custom.assign("BMPRZJRPXSVUQDCHMVTKPEIAKLQAAQTXVWLGNCZXDRMLLDQZXFJAKKAOGZOTYQYJTFFAABCGDTIVZB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("YoYo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::YoYo msg;
    msg.setTimeStamp(0.0278493387232);
    msg.setSource(26641U);
    msg.setSourceEntity(185U);
    msg.setDestination(5589U);
    msg.setDestinationEntity(64U);
    msg.timeout = 8119U;
    msg.lat = 0.379685417386;
    msg.lon = 0.0576222072354;
    msg.z = 0.358335238506;
    msg.z_units = 200U;
    msg.amplitude = 0.551200787667;
    msg.pitch = 0.200078629887;
    msg.speed = 0.591068646287;
    msg.speed_units = 16U;
    msg.custom.assign("OBLYMDCGAPGRBWVSVYIRYGTUFUMSBCZYQRZTPZSNDWZHPHXSDIBCRAMXPNLWQZLTJFUZLRSFWFJBSFMOQKQZNUVMPYELDKWYEIXWKAYTKVKHLAOHREQHYA");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("YoYo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TeleoperationDone msg;
    msg.setTimeStamp(0.079468507651);
    msg.setSource(2438U);
    msg.setSourceEntity(232U);
    msg.setDestination(51915U);
    msg.setDestinationEntity(181U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TeleoperationDone #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TeleoperationDone msg;
    msg.setTimeStamp(0.124831590676);
    msg.setSource(56403U);
    msg.setSourceEntity(54U);
    msg.setDestination(45853U);
    msg.setDestinationEntity(89U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TeleoperationDone #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TeleoperationDone msg;
    msg.setTimeStamp(0.814423123635);
    msg.setSource(62168U);
    msg.setSourceEntity(28U);
    msg.setDestination(40613U);
    msg.setDestinationEntity(212U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TeleoperationDone #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeeping msg;
    msg.setTimeStamp(0.126072747422);
    msg.setSource(37208U);
    msg.setSourceEntity(152U);
    msg.setDestination(49685U);
    msg.setDestinationEntity(138U);
    msg.lat = 0.0418688643817;
    msg.lon = 0.326598615326;
    msg.z = 0.947528764915;
    msg.z_units = 171U;
    msg.radius = 0.849691767428;
    msg.duration = 61070U;
    msg.speed = 0.00873020009839;
    msg.speed_units = 26U;
    msg.custom.assign("HSTEYBONBKRXPKWNTPQB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeeping #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeeping msg;
    msg.setTimeStamp(0.0524518004794);
    msg.setSource(44120U);
    msg.setSourceEntity(147U);
    msg.setDestination(23432U);
    msg.setDestinationEntity(123U);
    msg.lat = 0.989852369411;
    msg.lon = 0.883263978299;
    msg.z = 0.942913206897;
    msg.z_units = 37U;
    msg.radius = 0.60876448891;
    msg.duration = 41403U;
    msg.speed = 0.0423246254637;
    msg.speed_units = 139U;
    msg.custom.assign("TWIKKIGNUCCDVEZSYLSVKAPUAYQHL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeeping #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StationKeeping msg;
    msg.setTimeStamp(0.880430457497);
    msg.setSource(16955U);
    msg.setSourceEntity(115U);
    msg.setDestination(30153U);
    msg.setDestinationEntity(231U);
    msg.lat = 0.147278663247;
    msg.lon = 0.297215311328;
    msg.z = 0.585859060726;
    msg.z_units = 69U;
    msg.radius = 0.0647134293403;
    msg.duration = 46714U;
    msg.speed = 0.694068747914;
    msg.speed_units = 35U;
    msg.custom.assign("YLUXPSPSINDQFGMZMOZTJKRRZZHGBHOAVJMVITYIYOHVLXIPQZCWCIRZJSOAEQTUUVPEETKOMBGPNGJIVJLJBXXYRYXHRAGOUVEFNLHDXZFCPLZASYTKFBWBCLBUBPAKSDXUKEWQWUHWNMXEKDQCDATDQLMRFIENFTFENXVBDSTCWSDJFSLXOBOM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StationKeeping #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Elevator msg;
    msg.setTimeStamp(0.688548141342);
    msg.setSource(6357U);
    msg.setSourceEntity(215U);
    msg.setDestination(16524U);
    msg.setDestinationEntity(72U);
    msg.timeout = 62464U;
    msg.flags = 203U;
    msg.lat = 0.728531216242;
    msg.lon = 0.342996194246;
    msg.start_z = 0.361367059628;
    msg.start_z_units = 159U;
    msg.end_z = 0.242307750031;
    msg.end_z_units = 241U;
    msg.radius = 0.695143604803;
    msg.speed = 0.157188932036;
    msg.speed_units = 21U;
    msg.custom.assign("AFQSBXCSJGFYMCP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Elevator #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Elevator msg;
    msg.setTimeStamp(0.273223164388);
    msg.setSource(22041U);
    msg.setSourceEntity(159U);
    msg.setDestination(54600U);
    msg.setDestinationEntity(173U);
    msg.timeout = 43U;
    msg.flags = 22U;
    msg.lat = 0.484555896508;
    msg.lon = 0.230531980401;
    msg.start_z = 0.865667241587;
    msg.start_z_units = 245U;
    msg.end_z = 0.0523115613992;
    msg.end_z_units = 110U;
    msg.radius = 0.925411147912;
    msg.speed = 0.915948702195;
    msg.speed_units = 5U;
    msg.custom.assign("BWZCPKRYTEGASUYPPVQULOUHWIGEZSGHFZGKRBVCQJCGYRCAEIVPWVUFXQXUSDTQCMZSX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Elevator #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Elevator msg;
    msg.setTimeStamp(0.277544586314);
    msg.setSource(37358U);
    msg.setSourceEntity(238U);
    msg.setDestination(27901U);
    msg.setDestinationEntity(46U);
    msg.timeout = 65277U;
    msg.flags = 66U;
    msg.lat = 0.421001705293;
    msg.lon = 0.392316653608;
    msg.start_z = 0.799068935873;
    msg.start_z_units = 163U;
    msg.end_z = 0.171449004477;
    msg.end_z_units = 52U;
    msg.radius = 0.574477859005;
    msg.speed = 0.136931282639;
    msg.speed_units = 241U;
    msg.custom.assign("IFJOYOLWEJJALLUUWUDQFIUIAXTEIZBNFGTNMKQSPHYMWLMDEQVIYUTCERMBKXPAMKUFZPQSBKTZTBJWNYDONVHRFDXQHTG");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Elevator #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowTrajectory msg;
    msg.setTimeStamp(0.24547128648);
    msg.setSource(45927U);
    msg.setSourceEntity(80U);
    msg.setDestination(43299U);
    msg.setDestinationEntity(155U);
    msg.timeout = 25904U;
    msg.lat = 0.609200347196;
    msg.lon = 0.488178326868;
    msg.z = 0.330315489472;
    msg.z_units = 199U;
    msg.speed = 0.456343387174;
    msg.speed_units = 129U;
    msg.custom.assign("VLVWIXPZOAKWDXGENNWLGTEQMTFLOAANYQJTTQOKIFJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowTrajectory #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowTrajectory msg;
    msg.setTimeStamp(0.0828093658953);
    msg.setSource(6266U);
    msg.setSourceEntity(139U);
    msg.setDestination(58066U);
    msg.setDestinationEntity(102U);
    msg.timeout = 44528U;
    msg.lat = 0.178520421089;
    msg.lon = 0.589886382215;
    msg.z = 0.957435680576;
    msg.z_units = 246U;
    msg.speed = 0.904299535412;
    msg.speed_units = 24U;
    msg.custom.assign("IVZKNDWAIWCUHCYZGDFTIGTQUWGFFELERLXCHSLXHBRLRTC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowTrajectory #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowTrajectory msg;
    msg.setTimeStamp(0.707969899093);
    msg.setSource(34708U);
    msg.setSourceEntity(96U);
    msg.setDestination(47188U);
    msg.setDestinationEntity(76U);
    msg.timeout = 57269U;
    msg.lat = 0.460297596588;
    msg.lon = 0.662703137206;
    msg.z = 0.0656168830764;
    msg.z_units = 87U;
    msg.speed = 0.563635255075;
    msg.speed_units = 215U;
    msg.custom.assign("FNZVYOSOTNWSDJIKTPHFHDOAMFTVBLQCTRMILXXVGYMJDNSBIMTPLEAFHJVGGVCRPLDCAFQIYRVZAVMCBARAUOWERFMQOMJIKXLCQWRCNLRWWXDBOUGMUWENFRZPMPMWYKPOZIIBXAKQYHPBZEIKZXGUWHCKZBWNFSVTPBZJSNJXWYAFKBYSGRLDSNUDLKHYE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowTrajectory #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrajectoryPoint msg;
    msg.setTimeStamp(0.451269208438);
    msg.setSource(47271U);
    msg.setSourceEntity(104U);
    msg.setDestination(612U);
    msg.setDestinationEntity(252U);
    msg.x = 0.108684644036;
    msg.y = 0.97718441333;
    msg.z = 0.168261300366;
    msg.t = 0.523087095281;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrajectoryPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrajectoryPoint msg;
    msg.setTimeStamp(0.798883480954);
    msg.setSource(60955U);
    msg.setSourceEntity(10U);
    msg.setDestination(23287U);
    msg.setDestinationEntity(168U);
    msg.x = 0.607664338005;
    msg.y = 0.161788543128;
    msg.z = 0.0610598089785;
    msg.t = 0.249426630907;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrajectoryPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrajectoryPoint msg;
    msg.setTimeStamp(0.183310700254);
    msg.setSource(21662U);
    msg.setSourceEntity(78U);
    msg.setDestination(9635U);
    msg.setDestinationEntity(51U);
    msg.x = 0.136092815645;
    msg.y = 0.356960576257;
    msg.z = 0.395220375362;
    msg.t = 0.59194787612;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrajectoryPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CustomManeuver msg;
    msg.setTimeStamp(0.919395864016);
    msg.setSource(33172U);
    msg.setSourceEntity(155U);
    msg.setDestination(28617U);
    msg.setDestinationEntity(35U);
    msg.timeout = 11853U;
    msg.name.assign("ZJYUIRTLCOWUYKOPRMRJAQMXBJNCYFQMZZPOTQCEZIQOLZBFDKRSGGTCTAIGMCKQXREPBFLWECILBZMYBYALPJIZEFOTZTBWBPMPSKZQAOKJCSEUDCVDFFXT");
    msg.custom.assign("KMGEYUPBCCIZVLDDCVFCBTMBLEQXWTNCSVUYMSHGWKVDIHJWGBHIVONFGPAYONHSGURTIIWIDQATTPNZJARSEDOMFNUUGTJVAKALJOHKMUYFERNVXZRXDVJAPZRGDKELZJZYRHXQPUECMNSJSPTMKFIOBQSROEEPIVUWYZQD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CustomManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CustomManeuver msg;
    msg.setTimeStamp(0.395520877722);
    msg.setSource(24755U);
    msg.setSourceEntity(37U);
    msg.setDestination(64145U);
    msg.setDestinationEntity(125U);
    msg.timeout = 49963U;
    msg.name.assign("ARLEIZJRXAYWOPJSHHNIHBAUMXYRUYMCNKCIWAUXFQDGLCYMPZFVDGVDTHBWNTHIVNSLOCHK");
    msg.custom.assign("ETGPYFXNHJJUDLBWXOQJIGZUXYIQHKANEBAPDCLQHGQFWNJRVDSFDOCVGVKFGVGJHMBOAPIKAFKZTSERBEHTKWYDVLTSAPNBQITINPVWPAEPNMCYXFWESSMXQTCHEUYNMJFAGOFTLCYZVXRZAFUYNKTVULINKSCMDGIWZBKZUUAOIEILULFAPEOXNHMRUXQQGKXWBR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CustomManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CustomManeuver msg;
    msg.setTimeStamp(0.575508289243);
    msg.setSource(48408U);
    msg.setSourceEntity(73U);
    msg.setDestination(17974U);
    msg.setDestinationEntity(109U);
    msg.timeout = 64403U;
    msg.name.assign("PWIAHKGEDENTFJ");
    msg.custom.assign("ATKMWMNIQVLAHACZMDBGJOKGPJSTCRKGTLHGL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CustomManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormation msg;
    msg.setTimeStamp(0.0028806252407);
    msg.setSource(15689U);
    msg.setSourceEntity(104U);
    msg.setDestination(34476U);
    msg.setDestinationEntity(51U);
    msg.lat = 0.57243988813;
    msg.lon = 0.621035187007;
    msg.z = 0.991439655681;
    msg.z_units = 107U;
    msg.speed = 0.627058550796;
    msg.speed_units = 250U;
    IMC::VehicleFormationParticipant tmp_msg_0;
    tmp_msg_0.vid = 737U;
    tmp_msg_0.off_x = 0.794554435503;
    tmp_msg_0.off_y = 0.897714236529;
    tmp_msg_0.off_z = 0.764959022405;
    msg.participants.push_back(tmp_msg_0);
    msg.start_time = 0.932473872603;
    msg.custom.assign("VPYAKWERYZJBKUBRUNRNYMPSSOINROGWGOCKEVBD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormation msg;
    msg.setTimeStamp(0.683759553345);
    msg.setSource(27670U);
    msg.setSourceEntity(179U);
    msg.setDestination(52785U);
    msg.setDestinationEntity(96U);
    msg.lat = 0.256426353161;
    msg.lon = 0.205646890782;
    msg.z = 0.824754443882;
    msg.z_units = 152U;
    msg.speed = 0.960892776286;
    msg.speed_units = 185U;
    IMC::TrajectoryPoint tmp_msg_0;
    tmp_msg_0.x = 0.516584434108;
    tmp_msg_0.y = 0.466264977744;
    tmp_msg_0.z = 0.836096796387;
    tmp_msg_0.t = 0.220608534527;
    msg.points.push_back(tmp_msg_0);
    IMC::VehicleFormationParticipant tmp_msg_1;
    tmp_msg_1.vid = 61755U;
    tmp_msg_1.off_x = 0.550017790182;
    tmp_msg_1.off_y = 0.0487732608652;
    tmp_msg_1.off_z = 0.544213204121;
    msg.participants.push_back(tmp_msg_1);
    msg.start_time = 0.67288888273;
    msg.custom.assign("YRZHBLOGHLRGBJUBCECYRGVVCRWMAFELTQHBAZPUOSHWECYWGDSQBJJKQLUJDFFUTMMPLQKEFTJYIDCCVAHWRWAVOUIJVJNUPMNSTHECUBJFYBQDNWKEXERIZMZWDECVFOYZIKMKUYHAQJNGSSIGTWNOGYJCRQDEXGMVIAZONTTXPRYXLFUWIVOTLMBXKVDSKILZFDSFPRKAPDLXTANCLGQIQQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormation msg;
    msg.setTimeStamp(0.0581843892326);
    msg.setSource(33957U);
    msg.setSourceEntity(161U);
    msg.setDestination(9244U);
    msg.setDestinationEntity(219U);
    msg.lat = 0.251959598972;
    msg.lon = 0.736912776062;
    msg.z = 0.37727294556;
    msg.z_units = 217U;
    msg.speed = 0.947168117557;
    msg.speed_units = 38U;
    IMC::TrajectoryPoint tmp_msg_0;
    tmp_msg_0.x = 0.935914156347;
    tmp_msg_0.y = 0.289921349241;
    tmp_msg_0.z = 0.218783907453;
    tmp_msg_0.t = 0.207973925257;
    msg.points.push_back(tmp_msg_0);
    msg.start_time = 0.913012865377;
    msg.custom.assign("QDWKVJKLOANUTSEHSDVEPIJPRZCHBMZLVUBGYKINAGLNFFTBVSZPROOLZQLIRGXBROCXJQY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormationParticipant msg;
    msg.setTimeStamp(0.959518840221);
    msg.setSource(37776U);
    msg.setSourceEntity(90U);
    msg.setDestination(46165U);
    msg.setDestinationEntity(195U);
    msg.vid = 37971U;
    msg.off_x = 0.793287354128;
    msg.off_y = 0.395173405584;
    msg.off_z = 0.469796051148;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormationParticipant #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormationParticipant msg;
    msg.setTimeStamp(0.15169814007);
    msg.setSource(26357U);
    msg.setSourceEntity(169U);
    msg.setDestination(20092U);
    msg.setDestinationEntity(102U);
    msg.vid = 51785U;
    msg.off_x = 0.263429755;
    msg.off_y = 0.159373339766;
    msg.off_z = 0.0916693562625;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormationParticipant #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleFormationParticipant msg;
    msg.setTimeStamp(0.369715447712);
    msg.setSource(54463U);
    msg.setSourceEntity(225U);
    msg.setDestination(60784U);
    msg.setDestinationEntity(229U);
    msg.vid = 39031U;
    msg.off_x = 0.928790281425;
    msg.off_y = 0.673313644863;
    msg.off_z = 0.404123207245;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleFormationParticipant #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StopManeuver msg;
    msg.setTimeStamp(0.923209850685);
    msg.setSource(43241U);
    msg.setSourceEntity(37U);
    msg.setDestination(21318U);
    msg.setDestinationEntity(82U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StopManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StopManeuver msg;
    msg.setTimeStamp(0.199146673454);
    msg.setSource(1547U);
    msg.setSourceEntity(65U);
    msg.setDestination(7964U);
    msg.setDestinationEntity(214U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StopManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::StopManeuver msg;
    msg.setTimeStamp(0.248326333821);
    msg.setSource(63014U);
    msg.setSourceEntity(206U);
    msg.setDestination(62275U);
    msg.setDestinationEntity(47U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("StopManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RegisterManeuver msg;
    msg.setTimeStamp(0.0690611159141);
    msg.setSource(33521U);
    msg.setSourceEntity(213U);
    msg.setDestination(20002U);
    msg.setDestinationEntity(44U);
    msg.mid = 28233U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RegisterManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RegisterManeuver msg;
    msg.setTimeStamp(0.919677487335);
    msg.setSource(28322U);
    msg.setSourceEntity(189U);
    msg.setDestination(42922U);
    msg.setDestinationEntity(155U);
    msg.mid = 7773U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RegisterManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RegisterManeuver msg;
    msg.setTimeStamp(0.174800197352);
    msg.setSource(35923U);
    msg.setSourceEntity(71U);
    msg.setDestination(56746U);
    msg.setDestinationEntity(143U);
    msg.mid = 60995U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RegisterManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverControlState msg;
    msg.setTimeStamp(0.684427794208);
    msg.setSource(54177U);
    msg.setSourceEntity(139U);
    msg.setDestination(16426U);
    msg.setDestinationEntity(125U);
    msg.state = 230U;
    msg.eta = 39739U;
    msg.info.assign("BODBGPRHXVCRSVJGIWRMZCHDJFYFUXKAJGLQPMIIQDBDYTABSDXUJYGLNPFZEQHWYHZXELXZEMQARMJOWAHWVPQUTYAVOHNAOZSHUBVDJFGCQOSWCQYILQAENCTCINMBJOVISMJFYKHWRFNAVOKABPXZKZUBSASZKXZJDLRBNYFPVQUHEKRTUVKPXCOLWT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverControlState msg;
    msg.setTimeStamp(0.400606675466);
    msg.setSource(25900U);
    msg.setSourceEntity(141U);
    msg.setDestination(30969U);
    msg.setDestinationEntity(218U);
    msg.state = 117U;
    msg.eta = 19045U;
    msg.info.assign("ESTDQAHUUGBUBZGVVTFOHJTVTKAGXZQDWYYESCVAWKDIQOXUUOABQWHRPGFNMSREQIEKPZAEXPMFNNBVFQMVLFKM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ManeuverControlState msg;
    msg.setTimeStamp(0.690825020578);
    msg.setSource(35487U);
    msg.setSourceEntity(193U);
    msg.setDestination(61742U);
    msg.setDestinationEntity(7U);
    msg.state = 161U;
    msg.eta = 53955U;
    msg.info.assign("WHQBKTJASGOXQIKMPFRVGOAKPXRQDYBOJFCZRITZINDKHTWLWARPAXWIHOMJYADNXRZUOHJCRRIPRVONRNPUMESCZNILBYUULJGHTCHZMBNHVWEVLUGEHCIPCFBXIUFDMJZVVYSYCBPDETKKSSQWBFINEKGSFLVHVCEEYNSCXDYZQWU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ManeuverControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowSystem msg;
    msg.setTimeStamp(0.640467077488);
    msg.setSource(47013U);
    msg.setSourceEntity(190U);
    msg.setDestination(39301U);
    msg.setDestinationEntity(33U);
    msg.system = 5549U;
    msg.duration = 49976U;
    msg.speed = 0.0555866605267;
    msg.speed_units = 24U;
    msg.x = 0.451341988134;
    msg.y = 0.549461610302;
    msg.z = 0.0129642411091;
    msg.z_units = 26U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowSystem #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowSystem msg;
    msg.setTimeStamp(0.750880226141);
    msg.setSource(6364U);
    msg.setSourceEntity(54U);
    msg.setDestination(39459U);
    msg.setDestinationEntity(107U);
    msg.system = 40436U;
    msg.duration = 58610U;
    msg.speed = 0.596725799034;
    msg.speed_units = 246U;
    msg.x = 0.456661660425;
    msg.y = 0.506586558968;
    msg.z = 0.971725452961;
    msg.z_units = 58U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowSystem #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowSystem msg;
    msg.setTimeStamp(0.975775425676);
    msg.setSource(44903U);
    msg.setSourceEntity(92U);
    msg.setDestination(36889U);
    msg.setDestinationEntity(188U);
    msg.system = 38313U;
    msg.duration = 40287U;
    msg.speed = 0.98018698784;
    msg.speed_units = 92U;
    msg.x = 0.804851945296;
    msg.y = 0.229749097447;
    msg.z = 0.762764813967;
    msg.z_units = 164U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowSystem #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommsRelay msg;
    msg.setTimeStamp(0.503712111407);
    msg.setSource(46596U);
    msg.setSourceEntity(139U);
    msg.setDestination(43535U);
    msg.setDestinationEntity(194U);
    msg.lat = 0.631061379901;
    msg.lon = 0.896502055846;
    msg.speed = 0.992877692358;
    msg.speed_units = 47U;
    msg.duration = 9229U;
    msg.sys_a = 7245U;
    msg.sys_b = 42775U;
    msg.move_threshold = 0.233886592632;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommsRelay #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommsRelay msg;
    msg.setTimeStamp(0.587675934913);
    msg.setSource(6821U);
    msg.setSourceEntity(163U);
    msg.setDestination(20445U);
    msg.setDestinationEntity(152U);
    msg.lat = 0.195667573138;
    msg.lon = 0.0295352385619;
    msg.speed = 0.205915810593;
    msg.speed_units = 46U;
    msg.duration = 62154U;
    msg.sys_a = 39929U;
    msg.sys_b = 18835U;
    msg.move_threshold = 0.974503800084;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommsRelay #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CommsRelay msg;
    msg.setTimeStamp(0.123540375401);
    msg.setSource(59499U);
    msg.setSourceEntity(204U);
    msg.setDestination(59685U);
    msg.setDestinationEntity(249U);
    msg.lat = 0.329571749414;
    msg.lon = 0.572356817271;
    msg.speed = 0.45337837987;
    msg.speed_units = 116U;
    msg.duration = 43125U;
    msg.sys_a = 38074U;
    msg.sys_b = 11345U;
    msg.move_threshold = 0.769875124833;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CommsRelay #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CoverArea msg;
    msg.setTimeStamp(0.15237427466);
    msg.setSource(1010U);
    msg.setSourceEntity(171U);
    msg.setDestination(45775U);
    msg.setDestinationEntity(151U);
    msg.lat = 0.383832677731;
    msg.lon = 0.463075643617;
    msg.z = 0.147430846469;
    msg.z_units = 13U;
    msg.speed = 0.832138939123;
    msg.speed_units = 20U;
    IMC::PolygonVertex tmp_msg_0;
    tmp_msg_0.lat = 0.239196115244;
    tmp_msg_0.lon = 0.775292503739;
    msg.polygon.push_back(tmp_msg_0);
    msg.custom.assign("NEJTKIDAGRQELKHUEEWSLLXJLSRDKPVQVHKHLQYJAPFOXYMNAUMGNNLYJYSPTCCNCXPDPKOSHQWPJQQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CoverArea #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CoverArea msg;
    msg.setTimeStamp(0.0340862780692);
    msg.setSource(19369U);
    msg.setSourceEntity(180U);
    msg.setDestination(26798U);
    msg.setDestinationEntity(42U);
    msg.lat = 0.604579273931;
    msg.lon = 0.0531823142733;
    msg.z = 0.868383146904;
    msg.z_units = 51U;
    msg.speed = 0.631577227245;
    msg.speed_units = 214U;
    msg.custom.assign("SUULLREYKQFWOAJBAPZFJAZROELSFXWTUZZKRXQGXPBVDMJYGKNDAYRKTLWWZMBSAKQYCRZYGCKEFHPGFPDFUUKOICVYNNERNMWEWSUQLVHFXMGOPSVBVCOMIHCLSNGJFYDZZEIAATGDNVBKKWMODHX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CoverArea #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CoverArea msg;
    msg.setTimeStamp(0.438910758022);
    msg.setSource(12184U);
    msg.setSourceEntity(231U);
    msg.setDestination(63881U);
    msg.setDestinationEntity(161U);
    msg.lat = 0.517720947071;
    msg.lon = 0.682307167989;
    msg.z = 0.176335772908;
    msg.z_units = 233U;
    msg.speed = 0.491989508911;
    msg.speed_units = 114U;
    IMC::PolygonVertex tmp_msg_0;
    tmp_msg_0.lat = 0.679671734225;
    tmp_msg_0.lon = 0.676570319383;
    msg.polygon.push_back(tmp_msg_0);
    msg.custom.assign("VVRSILEARYWPYIEFCIBLMLWSYDPMQJSCRSTNOFTSBHAZROIMYJHEBHNGFJXNSJSSCEXYLAJEWIAOMQKQCAFDGXYDLKRFOITJIBDNXIWGHXQDZHRXIUGDMKUTMOLBCCFWJKXWMMNNGOCETELZVKNYTVYFUZJCQGGNBIHLJBEDPZWFDHDHTTWOHCUBXSKEYFURZPCVLAKPGKXUPDVRQZLVZUNSRUBQOVGPVQKUQPQWFOAP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CoverArea #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PolygonVertex msg;
    msg.setTimeStamp(0.661092743665);
    msg.setSource(37546U);
    msg.setSourceEntity(198U);
    msg.setDestination(28657U);
    msg.setDestinationEntity(237U);
    msg.lat = 0.0524811971433;
    msg.lon = 0.750395606649;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PolygonVertex #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PolygonVertex msg;
    msg.setTimeStamp(0.113387648711);
    msg.setSource(55506U);
    msg.setSourceEntity(76U);
    msg.setDestination(9891U);
    msg.setDestinationEntity(56U);
    msg.lat = 0.00582961238411;
    msg.lon = 0.408503396639;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PolygonVertex #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PolygonVertex msg;
    msg.setTimeStamp(0.195128853786);
    msg.setSource(33085U);
    msg.setSourceEntity(140U);
    msg.setDestination(26635U);
    msg.setDestinationEntity(229U);
    msg.lat = 0.256251168903;
    msg.lon = 0.66972471768;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PolygonVertex #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompassCalibration msg;
    msg.setTimeStamp(0.470725214574);
    msg.setSource(29016U);
    msg.setSourceEntity(97U);
    msg.setDestination(52365U);
    msg.setDestinationEntity(226U);
    msg.timeout = 54124U;
    msg.lat = 0.837003145603;
    msg.lon = 0.887607506949;
    msg.z = 0.168429696186;
    msg.z_units = 226U;
    msg.pitch = 0.810749678935;
    msg.amplitude = 0.86578196811;
    msg.duration = 56242U;
    msg.speed = 0.760370174957;
    msg.speed_units = 99U;
    msg.radius = 0.961706834984;
    msg.direction = 48U;
    msg.custom.assign("QSKGZQJECFCZUATNBJXLSWGKOLIIVJZEGBKRHUOGDMALFUXLVWWMYBCTJAOHNMNRSJMMQNCBSEAUWVEGDOEQJSJXTZPHAAKXRRDZSFXRMEOIITPBORZIUDMKYIPSIAFONFC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompassCalibration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompassCalibration msg;
    msg.setTimeStamp(0.871793147586);
    msg.setSource(54242U);
    msg.setSourceEntity(234U);
    msg.setDestination(30732U);
    msg.setDestinationEntity(147U);
    msg.timeout = 56065U;
    msg.lat = 0.499828054489;
    msg.lon = 0.342087427293;
    msg.z = 0.550892645265;
    msg.z_units = 13U;
    msg.pitch = 0.527489687671;
    msg.amplitude = 0.223928075895;
    msg.duration = 23075U;
    msg.speed = 0.396785545424;
    msg.speed_units = 198U;
    msg.radius = 0.355007292801;
    msg.direction = 66U;
    msg.custom.assign("BXBSUHPSAYUUUXLIKOWJOAIXAXURELLJSJOMVEZKELXDQMVFTHILCURRWCAWIVOGK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompassCalibration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompassCalibration msg;
    msg.setTimeStamp(0.646159108746);
    msg.setSource(20017U);
    msg.setSourceEntity(75U);
    msg.setDestination(64645U);
    msg.setDestinationEntity(234U);
    msg.timeout = 47441U;
    msg.lat = 0.306278269059;
    msg.lon = 0.676912765307;
    msg.z = 0.516991048751;
    msg.z_units = 1U;
    msg.pitch = 0.999616852474;
    msg.amplitude = 0.667517917476;
    msg.duration = 17459U;
    msg.speed = 0.237885525149;
    msg.speed_units = 148U;
    msg.radius = 0.0779976905643;
    msg.direction = 16U;
    msg.custom.assign("YAMZRFOJWHTEYUBSIHABDAWDUTBOUIFMUKXTBRRNXYDVDPXNRZUMKXLJSZELKTJYLPGEJRMHZTYFCDHPGOQSKUXKMJWSREUYIPHIUTUTYNDVDJOHGGZQNNRSFNLEGRENIOPOMAYCIWVEQCRLXOBSTOFLVFAWQZLSQAZGIDVCHLDTABKHSNLJGAQWBYSQQIFIOSCOHPKVN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompassCalibration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowReference msg;
    msg.setTimeStamp(0.968117568842);
    msg.setSource(5904U);
    msg.setSourceEntity(9U);
    msg.setDestination(18585U);
    msg.setDestinationEntity(233U);
    msg.control_src = 56140U;
    msg.control_ent = 202U;
    msg.timeout = 0.500374250407;
    msg.loiter_radius = 0.0519603499678;
    msg.altitude_interval = 0.489188576988;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowReference #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowReference msg;
    msg.setTimeStamp(0.474482205588);
    msg.setSource(54358U);
    msg.setSourceEntity(233U);
    msg.setDestination(32785U);
    msg.setDestinationEntity(183U);
    msg.control_src = 39026U;
    msg.control_ent = 172U;
    msg.timeout = 0.457611342737;
    msg.loiter_radius = 0.640004550087;
    msg.altitude_interval = 0.393082999149;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowReference #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowReference msg;
    msg.setTimeStamp(0.914283335393);
    msg.setSource(38508U);
    msg.setSourceEntity(163U);
    msg.setDestination(42534U);
    msg.setDestinationEntity(102U);
    msg.control_src = 59311U;
    msg.control_ent = 217U;
    msg.timeout = 0.0484017858455;
    msg.loiter_radius = 0.288579842826;
    msg.altitude_interval = 0.50928764502;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowReference #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Reference msg;
    msg.setTimeStamp(0.931443121721);
    msg.setSource(20863U);
    msg.setSourceEntity(92U);
    msg.setDestination(59968U);
    msg.setDestinationEntity(145U);
    msg.flags = 161U;
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.439536533896;
    tmp_msg_0.speed_units = 231U;
    msg.speed.set(tmp_msg_0);
    IMC::DesiredZ tmp_msg_1;
    tmp_msg_1.value = 0.455618753295;
    tmp_msg_1.z_units = 101U;
    msg.z.set(tmp_msg_1);
    msg.lat = 0.599747094253;
    msg.lon = 0.437481911896;
    msg.radius = 0.0929558864059;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Reference #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Reference msg;
    msg.setTimeStamp(0.59136664904);
    msg.setSource(7836U);
    msg.setSourceEntity(229U);
    msg.setDestination(58494U);
    msg.setDestinationEntity(143U);
    msg.flags = 44U;
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.561738755739;
    tmp_msg_0.speed_units = 6U;
    msg.speed.set(tmp_msg_0);
    IMC::DesiredZ tmp_msg_1;
    tmp_msg_1.value = 0.36682222707;
    tmp_msg_1.z_units = 238U;
    msg.z.set(tmp_msg_1);
    msg.lat = 0.611893199177;
    msg.lon = 0.686711150799;
    msg.radius = 0.72379845912;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Reference #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Reference msg;
    msg.setTimeStamp(0.17148236639);
    msg.setSource(2197U);
    msg.setSourceEntity(104U);
    msg.setDestination(26021U);
    msg.setDestinationEntity(19U);
    msg.flags = 58U;
    IMC::DesiredSpeed tmp_msg_0;
    tmp_msg_0.value = 0.781531859801;
    tmp_msg_0.speed_units = 99U;
    msg.speed.set(tmp_msg_0);
    IMC::DesiredZ tmp_msg_1;
    tmp_msg_1.value = 0.159601333615;
    tmp_msg_1.z_units = 151U;
    msg.z.set(tmp_msg_1);
    msg.lat = 0.252273712332;
    msg.lon = 0.736768287507;
    msg.radius = 0.0362695142786;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Reference #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowRefState msg;
    msg.setTimeStamp(0.723354760199);
    msg.setSource(15854U);
    msg.setSourceEntity(61U);
    msg.setDestination(32052U);
    msg.setDestinationEntity(35U);
    msg.control_src = 47164U;
    msg.control_ent = 71U;
    IMC::Reference tmp_msg_0;
    tmp_msg_0.flags = 125U;
    IMC::DesiredSpeed tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.value = 0.618927540689;
    tmp_tmp_msg_0_0.speed_units = 231U;
    tmp_msg_0.speed.set(tmp_tmp_msg_0_0);
    IMC::DesiredZ tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.value = 0.256225129389;
    tmp_tmp_msg_0_1.z_units = 79U;
    tmp_msg_0.z.set(tmp_tmp_msg_0_1);
    tmp_msg_0.lat = 0.447252675661;
    tmp_msg_0.lon = 0.623915258429;
    tmp_msg_0.radius = 0.910395805337;
    msg.reference.set(tmp_msg_0);
    msg.state = 63U;
    msg.proximity = 30U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowRefState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowRefState msg;
    msg.setTimeStamp(0.192042617219);
    msg.setSource(28342U);
    msg.setSourceEntity(138U);
    msg.setDestination(14U);
    msg.setDestinationEntity(66U);
    msg.control_src = 21913U;
    msg.control_ent = 174U;
    IMC::Reference tmp_msg_0;
    tmp_msg_0.flags = 65U;
    IMC::DesiredSpeed tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.value = 0.953036113626;
    tmp_tmp_msg_0_0.speed_units = 139U;
    tmp_msg_0.speed.set(tmp_tmp_msg_0_0);
    IMC::DesiredZ tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.value = 0.697334505881;
    tmp_tmp_msg_0_1.z_units = 12U;
    tmp_msg_0.z.set(tmp_tmp_msg_0_1);
    tmp_msg_0.lat = 0.219986451446;
    tmp_msg_0.lon = 0.229241799846;
    tmp_msg_0.radius = 0.113534579576;
    msg.reference.set(tmp_msg_0);
    msg.state = 126U;
    msg.proximity = 104U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowRefState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::FollowRefState msg;
    msg.setTimeStamp(0.355936192108);
    msg.setSource(1680U);
    msg.setSourceEntity(245U);
    msg.setDestination(43193U);
    msg.setDestinationEntity(83U);
    msg.control_src = 35140U;
    msg.control_ent = 33U;
    IMC::Reference tmp_msg_0;
    tmp_msg_0.flags = 82U;
    IMC::DesiredSpeed tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.value = 0.589062789676;
    tmp_tmp_msg_0_0.speed_units = 12U;
    tmp_msg_0.speed.set(tmp_tmp_msg_0_0);
    IMC::DesiredZ tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.value = 0.20743548321;
    tmp_tmp_msg_0_1.z_units = 179U;
    tmp_msg_0.z.set(tmp_tmp_msg_0_1);
    tmp_msg_0.lat = 0.842683121055;
    tmp_msg_0.lon = 0.638412211004;
    tmp_msg_0.radius = 0.458350212828;
    msg.reference.set(tmp_msg_0);
    msg.state = 30U;
    msg.proximity = 21U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("FollowRefState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleState msg;
    msg.setTimeStamp(0.886037097815);
    msg.setSource(3703U);
    msg.setSourceEntity(210U);
    msg.setDestination(45362U);
    msg.setDestinationEntity(208U);
    msg.op_mode = 87U;
    msg.error_count = 154U;
    msg.error_ents.assign("SHSXQFTYOAXBANHMANDCRFBYVCLQSTBELMFZLWQMNUUXRTMJYJP");
    msg.maneuver_type = 7723U;
    msg.maneuver_stime = 0.9789528136;
    msg.maneuver_eta = 14187U;
    msg.control_loops = 1833724068U;
    msg.flags = 150U;
    msg.last_error.assign("JWJVBQBFQVHYNSORXJCRFFVQCPCZBRKWRMUECSYUHTIKESGKPZSEBKYMKBPZMGIIWACSPYDMHZLXAUULGXATJKRBCUZNWNIVPUAKAQGMDTSYXKVTYRZRYNMCXHOLLAZEDXCRMPOIPOHO");
    msg.last_error_time = 0.502656438592;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleState msg;
    msg.setTimeStamp(0.358823339511);
    msg.setSource(38480U);
    msg.setSourceEntity(89U);
    msg.setDestination(46315U);
    msg.setDestinationEntity(99U);
    msg.op_mode = 182U;
    msg.error_count = 37U;
    msg.error_ents.assign("DUIYPKHLKHFCFLWNPDVSFJKHCBBMNCCOZNGMIVVIZRCOUXKMXELPLUZWADTFAUMVH");
    msg.maneuver_type = 34772U;
    msg.maneuver_stime = 0.445769985701;
    msg.maneuver_eta = 37050U;
    msg.control_loops = 1522950390U;
    msg.flags = 157U;
    msg.last_error.assign("CBDTGSJXCHRFBRVSRAVGTLUDKGJWHMOCNBTWFVKRBMECAACZKFVPHTKGHNLORQSJCWGIQDZSIXMJPBWJOEREDYNYCXAKEPDZMSGLUQEELUUPCBFAUZDEPCP");
    msg.last_error_time = 0.558327727107;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleState msg;
    msg.setTimeStamp(0.183877364192);
    msg.setSource(6204U);
    msg.setSourceEntity(149U);
    msg.setDestination(6464U);
    msg.setDestinationEntity(205U);
    msg.op_mode = 174U;
    msg.error_count = 206U;
    msg.error_ents.assign("PTYVRBAULALNIMSRRCNJBQXYHOUGJCLLIAPMPSYJEWKHKOCLZMJRTGIPCYRQSOTDKOFOVKFGTJNIEJVZKQGNJHCGHQVYBFWNZBZNJRISXUQMVDYCQMROHSFVAPYGEBIFQPWEAACETFUWWDAZOKNNHJMSXDRNABZGMTGGCPPLZXQLFVRUJOBPASYSFDIGDVXYQNXHKBUIXK");
    msg.maneuver_type = 18211U;
    msg.maneuver_stime = 0.881884172911;
    msg.maneuver_eta = 61924U;
    msg.control_loops = 2752396614U;
    msg.flags = 157U;
    msg.last_error.assign("RIBJMOQHCISSKCDFJVLUWXVRQWYHQJMCOEQHZNGPASIZQFAPTMOVPGERBBAXLKUTDPFASEGTNLGHLJRNFIHSWLYXRRZDSCIIVKBUKUDXZMMDSMDXGKPH");
    msg.last_error_time = 0.590065042425;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleCommand msg;
    msg.setTimeStamp(0.914084222626);
    msg.setSource(4167U);
    msg.setSourceEntity(83U);
    msg.setDestination(62044U);
    msg.setDestinationEntity(65U);
    msg.type = 8U;
    msg.request_id = 36494U;
    msg.command = 112U;
    IMC::CoverArea tmp_msg_0;
    tmp_msg_0.lat = 0.394599040232;
    tmp_msg_0.lon = 0.320028704617;
    tmp_msg_0.z = 0.473210468254;
    tmp_msg_0.z_units = 3U;
    tmp_msg_0.speed = 0.703411736608;
    tmp_msg_0.speed_units = 41U;
    IMC::PolygonVertex tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.lat = 0.463420882686;
    tmp_tmp_msg_0_0.lon = 0.0651416881679;
    tmp_msg_0.polygon.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.custom.assign("GCYBLNVBYNCFTEEHAQKBFASFRDZBIWHKNIXCXVEVQFMYQIOCNSVCGFDRWYLXEAAKJOMHJBJHJGHWUZCNNEPGAMCJAZE");
    msg.maneuver.set(tmp_msg_0);
    msg.calib_time = 2122U;
    msg.info.assign("CBTEGPCBSETSNAWVYRWADGVYSDYRBPUZPKQIAUCIMYHFAJKXGDWKVVSJBHSZSLWOQUMCYUIESFOIFXKGBOQNDQSEGTTAJLOPNMWJTHRTFRNWAFXAEPEZEWKILILCCVXFRHMQGJRHGXKOXYTYZUVNZJUDDCHFNL");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleCommand #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleCommand msg;
    msg.setTimeStamp(0.185523311052);
    msg.setSource(20536U);
    msg.setSourceEntity(157U);
    msg.setDestination(38617U);
    msg.setDestinationEntity(70U);
    msg.type = 194U;
    msg.request_id = 55302U;
    msg.command = 175U;
    IMC::IdleManeuver tmp_msg_0;
    tmp_msg_0.duration = 31402U;
    tmp_msg_0.custom.assign("VLFXFHNETUPVASEFJNRVJOITPMBBWFWCTUIDCVDBTJAGYMHGWHVZUJUJQHWLMRA");
    msg.maneuver.set(tmp_msg_0);
    msg.calib_time = 17262U;
    msg.info.assign("ELAKMAWUYPQOUPVXRTPOZAGJJGGTQHXJDHKNPDZQFETSLZKNCBSPAMODTXSCSYDWOVLWDRYRIRDFDVDNNGFVQASEZHYQRVBVJBSGCERKPSYKUNHMNGIHZLJTEFCBYYFUMPRJLQIVIOUPNQWZURIMYONAUHIAIWTDWUXBJNLMOHISJWJEPRGEJVXXOLGVSK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleCommand #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleCommand msg;
    msg.setTimeStamp(0.263525810489);
    msg.setSource(9265U);
    msg.setSourceEntity(219U);
    msg.setDestination(7781U);
    msg.setDestinationEntity(242U);
    msg.type = 180U;
    msg.request_id = 4553U;
    msg.command = 122U;
    IMC::YoYo tmp_msg_0;
    tmp_msg_0.timeout = 35407U;
    tmp_msg_0.lat = 0.655201141123;
    tmp_msg_0.lon = 0.137392018739;
    tmp_msg_0.z = 0.648402757318;
    tmp_msg_0.z_units = 25U;
    tmp_msg_0.amplitude = 0.0704443483101;
    tmp_msg_0.pitch = 0.290059910547;
    tmp_msg_0.speed = 0.469337938741;
    tmp_msg_0.speed_units = 67U;
    tmp_msg_0.custom.assign("OTGXMBSXXCIWBODIHQORKAXCHKLGFELVGMZSVORJSVCXPDWDKUSPGAEYWIAVQKIFWFUDTVNENMREFTRBLOABQPFXOCJTHPDMRLWZSZRTGRJIIJHCIYZZNPQIZBGRKBSGQLWCTEKZTHOMWQTUACKSMZZNAHOFXBPNLHESYEKLWHPS");
    msg.maneuver.set(tmp_msg_0);
    msg.calib_time = 18277U;
    msg.info.assign("CRMDHXWPUOSNJWKTQTHCHSARPPFPKPVYAEBURNCDICDLORJISBFVGRKSCMMJTKQHFEYNUCEXIYFSDVQEGGZIKYWYQXWDPAEDJCIOSRHBSVMJYKZMZIIOGNXBTASYUJBMWLYAEPXLXVDHLXNGLJCJTZVGLBQBATBMDGVWKOPTUWNIMKZFAUUZO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleCommand #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MonitorEntityState msg;
    msg.setTimeStamp(0.776328569412);
    msg.setSource(8246U);
    msg.setSourceEntity(53U);
    msg.setDestination(20010U);
    msg.setDestinationEntity(148U);
    msg.command = 15U;
    msg.entities.assign("TDBMUCZWWZUQZBHSKZKRDHGPVQRRRXBACZAJCSDWNLVUSNRZVCUGAEJWKKGDZRGPDPWRVBPIKPBFDJWGCQZENYFYYKYBFUSNMTSQKXBUVYMFLOQCJAZLGEXVYPNIUDTTWFJJAIGNIBOEBSMKLGHQUSKLALBXQKHIEOGODTHCMRUJMHXEEXSPJAMHFHNTODLOMACWCOOYQFYQNEWINTXIE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MonitorEntityState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MonitorEntityState msg;
    msg.setTimeStamp(0.104954862453);
    msg.setSource(49744U);
    msg.setSourceEntity(57U);
    msg.setDestination(41408U);
    msg.setDestinationEntity(55U);
    msg.command = 70U;
    msg.entities.assign("WGMKXDBKZKITLRFNLVBZEJXASCSTMVKGIZRKXUNMUPZADQRCOHSOWOTWLSSPMOKYTZQENSJVFVOYRFEEDZCDHAVHUXUPTMNGJ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MonitorEntityState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MonitorEntityState msg;
    msg.setTimeStamp(0.710917441933);
    msg.setSource(22935U);
    msg.setSourceEntity(250U);
    msg.setDestination(14306U);
    msg.setDestinationEntity(84U);
    msg.command = 224U;
    msg.entities.assign("ODQNZRMQJSZBHZPOVBIVFUOFSMEFSTAPNZRSJQBNAAJIWCKWGXJBJREDOHGNFKZLBPRQNGXETOHYFDUXTPVBVYWFJQBEKCCIZEOZPYTHPNMICY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MonitorEntityState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityMonitoringState msg;
    msg.setTimeStamp(0.673957117645);
    msg.setSource(41608U);
    msg.setSourceEntity(123U);
    msg.setDestination(16932U);
    msg.setDestinationEntity(130U);
    msg.mcount = 134U;
    msg.mnames.assign("TWIQIXRWJNBLPFUXNUABDIFFGMCVBFDBISIYAMLGOLYPQQWSCJEGBOLJABKPGTNEORZMHNKDWLIYOJOKRDZVZHTTYDHBYIKCYBTIHGQCWTAJTQKNNJXFXUOQOTGEHVZSGORQJXLMOVPUNYRVUGWQNUJHSKDPEMYTSXKSEDCCRQELDPNWCVFLUVZAVRYFWMSBMWESPFRFFTVPAR");
    msg.ecount = 124U;
    msg.enames.assign("QCYDDSVQZBXDEKCAMWICUBOTHCGTKAFDQTVFZLPIHODMFWZZFRFYALVVKCOVPJNPGUBBOWLHBNPJGXGINFTAJDZMSIKFRJHIGSTVFASEOCSFZWSWYDWUBTAPJKIYEOJQIJUQEQOCKIHE");
    msg.ccount = 82U;
    msg.cnames.assign("GDBSKXWKPLELRUYPXUHHAERJTQWHILYLCWPDKFQVNUJYRINLUECBZDSCWFDWLXMIMMHOGKTFOSTXOECBAGBDVZJKFBRIVGKNWCJIQ");
    msg.last_error.assign("CVFVSUQYPQOBLDVBKNSBAOSIRKJPUUAZXWEPFEWGLFRYZGDUNWEISFUMOHIXSNORSZPMFRGBZGLIFZPWLUVAH");
    msg.last_error_time = 0.948764992251;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityMonitoringState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityMonitoringState msg;
    msg.setTimeStamp(0.0279944635438);
    msg.setSource(9556U);
    msg.setSourceEntity(233U);
    msg.setDestination(16756U);
    msg.setDestinationEntity(132U);
    msg.mcount = 142U;
    msg.mnames.assign("ZZXEZQFYMVXMCUBDPRTTCBIBSBHLZIKNGFQYVMMWVYVEWNWQEELATYFQCAVCYKJWMRHLDLAVGGAMHQHXCRYQPNLCPDORNHPDBTZXDMDXFRNGXFUQFYGKO");
    msg.ecount = 235U;
    msg.enames.assign("HYBBRSDYNBWZYOONTEEMTGKQESTEBCQRDNHFPIKJAPXEQBTJHDHWLDWESCBWHJEGAMOFRDFIKUNFSAHAWIVHZUMHXBMGPISKBQZCNJILOACENUOXNQ");
    msg.ccount = 51U;
    msg.cnames.assign("PSEJIEFUNTRKPYPGUELPEMNRJWFVLXUDSZOQVEDPMKDGAVKTHBSXCWRHNBGQSKXPXHJP");
    msg.last_error.assign("KPLJUTOHRIKNBMQXXCKUSVHEQYPBPEWKKENWWZYAVQQZIMDCJPYKATDEMBZPCDX");
    msg.last_error_time = 0.70339021224;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityMonitoringState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityMonitoringState msg;
    msg.setTimeStamp(0.0164572802397);
    msg.setSource(4180U);
    msg.setSourceEntity(112U);
    msg.setDestination(2334U);
    msg.setDestinationEntity(15U);
    msg.mcount = 56U;
    msg.mnames.assign("YNIPELXIDZVTRRDTJNCTLRFVHWKWVHBAMSOJCQXSBJMMSMCNTDUAZMIGUQPPUIIKCIKKEWORDTAOSRBRPOTFBFHSHGCZQVOUMYHMBAGDKHLEXNIPTUKJWPSAPAGSKLUAAFHYUDGFWEFORXZA");
    msg.ecount = 130U;
    msg.enames.assign("EUOLNMZZKBRJKLKGPWEIFIHAXKFLRDDKAKMMTRZQOBIJLMSSXUWBSABYZQLSWODNYQTNDIULBAXVZHPNSFWVHGMFTOGYCJGXCTGPWPURNSDJIRDNQTMCCXFMJEFOVUHVCNLEEYADQCZFEHBJCQLSUZTPYXWRTYQZOZYHEPQSQXIGVOJNMHDNAXAUTJWUXHXEJYINGQKVKZAYPHMWCGHAURVFBIGYVEGCSFJIPFOKRWBTR");
    msg.ccount = 182U;
    msg.cnames.assign("DCGJMKMLCMYNONFLLFQEDXVIWQUHIZZMWBLPVGFPDAQTDPGBEJPSALMJZECYVTRBSBIBRYJZLKYQXPZFNVKNZNOJDKYWATEJXJCMKHXUJWGLOLQFFWMAWBMXRVNUQKFSKTVJCTUIHTASWGYEWRAHLHAOHXXRTPEHROOHGSZSKSQKZDYYAFEXWMUNJXNOGEZBFCUPZPIQCRMGWUIGQS");
    msg.last_error.assign("ZTHQRGKNXJRNKMQOJKTICUUSZAWZNXKRGOJSMMLFZXYDXDEJYPZBTASTHDFCPBQVTX");
    msg.last_error_time = 0.70009176786;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityMonitoringState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OperationalLimits msg;
    msg.setTimeStamp(0.756957106264);
    msg.setSource(65093U);
    msg.setSourceEntity(99U);
    msg.setDestination(9252U);
    msg.setDestinationEntity(238U);
    msg.mask = 21U;
    msg.max_depth = 0.944656300441;
    msg.min_altitude = 0.889061270027;
    msg.max_altitude = 0.962006928003;
    msg.min_speed = 0.0307929541411;
    msg.max_speed = 0.771868824914;
    msg.max_vrate = 0.470789998299;
    msg.lat = 0.251500963028;
    msg.lon = 0.102761703075;
    msg.orientation = 0.0281251511063;
    msg.width = 0.946498694015;
    msg.length = 0.55424973654;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OperationalLimits #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OperationalLimits msg;
    msg.setTimeStamp(0.544948878072);
    msg.setSource(61407U);
    msg.setSourceEntity(53U);
    msg.setDestination(24688U);
    msg.setDestinationEntity(191U);
    msg.mask = 176U;
    msg.max_depth = 0.772228413644;
    msg.min_altitude = 0.637321690237;
    msg.max_altitude = 0.0986535303127;
    msg.min_speed = 0.886136456554;
    msg.max_speed = 0.413587399248;
    msg.max_vrate = 0.972390338608;
    msg.lat = 0.412613668336;
    msg.lon = 0.119243267074;
    msg.orientation = 0.386175931947;
    msg.width = 0.759052184087;
    msg.length = 0.97237288338;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OperationalLimits #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::OperationalLimits msg;
    msg.setTimeStamp(0.874848506845);
    msg.setSource(5765U);
    msg.setSourceEntity(225U);
    msg.setDestination(8948U);
    msg.setDestinationEntity(89U);
    msg.mask = 254U;
    msg.max_depth = 0.270952154902;
    msg.min_altitude = 0.859702230144;
    msg.max_altitude = 0.746909666558;
    msg.min_speed = 0.0192658221173;
    msg.max_speed = 0.477239172878;
    msg.max_vrate = 0.81863158752;
    msg.lat = 0.861058027332;
    msg.lon = 0.753891407482;
    msg.orientation = 0.463826069791;
    msg.width = 0.561474839395;
    msg.length = 0.146449190164;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("OperationalLimits #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetOperationalLimits msg;
    msg.setTimeStamp(0.295541539472);
    msg.setSource(45833U);
    msg.setSourceEntity(250U);
    msg.setDestination(51811U);
    msg.setDestinationEntity(157U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetOperationalLimits #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetOperationalLimits msg;
    msg.setTimeStamp(0.629845239285);
    msg.setSource(58411U);
    msg.setSourceEntity(100U);
    msg.setDestination(12972U);
    msg.setDestinationEntity(241U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetOperationalLimits #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::GetOperationalLimits msg;
    msg.setTimeStamp(0.707498009392);
    msg.setSource(17147U);
    msg.setSourceEntity(240U);
    msg.setDestination(1534U);
    msg.setDestinationEntity(185U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("GetOperationalLimits #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Calibration msg;
    msg.setTimeStamp(0.0683458612325);
    msg.setSource(3889U);
    msg.setSourceEntity(6U);
    msg.setDestination(6498U);
    msg.setDestinationEntity(13U);
    msg.duration = 6625U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Calibration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Calibration msg;
    msg.setTimeStamp(0.364812132046);
    msg.setSource(39548U);
    msg.setSourceEntity(123U);
    msg.setDestination(27072U);
    msg.setDestinationEntity(99U);
    msg.duration = 32281U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Calibration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Calibration msg;
    msg.setTimeStamp(0.987543619561);
    msg.setSource(58973U);
    msg.setSourceEntity(207U);
    msg.setDestination(26378U);
    msg.setDestinationEntity(228U);
    msg.duration = 39230U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Calibration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlLoops msg;
    msg.setTimeStamp(0.503237086026);
    msg.setSource(37646U);
    msg.setSourceEntity(119U);
    msg.setDestination(56818U);
    msg.setDestinationEntity(205U);
    msg.enable = 106U;
    msg.mask = 4013842547U;
    msg.scope_ref = 0.0969470917983;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlLoops #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlLoops msg;
    msg.setTimeStamp(0.0703016819332);
    msg.setSource(53684U);
    msg.setSourceEntity(191U);
    msg.setDestination(26478U);
    msg.setDestinationEntity(180U);
    msg.enable = 17U;
    msg.mask = 1422052977U;
    msg.scope_ref = 0.938183184068;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlLoops #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ControlLoops msg;
    msg.setTimeStamp(0.445008113392);
    msg.setSource(51575U);
    msg.setSourceEntity(25U);
    msg.setDestination(36682U);
    msg.setDestinationEntity(159U);
    msg.enable = 2U;
    msg.mask = 1360362207U;
    msg.scope_ref = 0.716659767479;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ControlLoops #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleMedium msg;
    msg.setTimeStamp(0.907924440413);
    msg.setSource(57553U);
    msg.setSourceEntity(143U);
    msg.setDestination(12813U);
    msg.setDestinationEntity(58U);
    msg.medium = 37U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleMedium #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleMedium msg;
    msg.setTimeStamp(0.711681791432);
    msg.setSource(65123U);
    msg.setSourceEntity(68U);
    msg.setDestination(22263U);
    msg.setDestinationEntity(61U);
    msg.medium = 96U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleMedium #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleMedium msg;
    msg.setTimeStamp(0.299074104152);
    msg.setSource(542U);
    msg.setSourceEntity(104U);
    msg.setDestination(18573U);
    msg.setDestinationEntity(170U);
    msg.medium = 167U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleMedium #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Collision msg;
    msg.setTimeStamp(0.41007871705);
    msg.setSource(22086U);
    msg.setSourceEntity(38U);
    msg.setDestination(32585U);
    msg.setDestinationEntity(247U);
    msg.value = 0.0247801177214;
    msg.type = 81U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Collision #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Collision msg;
    msg.setTimeStamp(0.50065579711);
    msg.setSource(64196U);
    msg.setSourceEntity(171U);
    msg.setDestination(61086U);
    msg.setDestinationEntity(246U);
    msg.value = 0.355068277149;
    msg.type = 204U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Collision #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Collision msg;
    msg.setTimeStamp(0.299933869848);
    msg.setSource(52574U);
    msg.setSourceEntity(117U);
    msg.setDestination(18851U);
    msg.setDestinationEntity(76U);
    msg.value = 0.868390161042;
    msg.type = 234U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Collision #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Abort msg;
    msg.setTimeStamp(0.727254462471);
    msg.setSource(1549U);
    msg.setSourceEntity(73U);
    msg.setDestination(6591U);
    msg.setDestinationEntity(240U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Abort #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Abort msg;
    msg.setTimeStamp(0.462992905591);
    msg.setSource(61372U);
    msg.setSourceEntity(88U);
    msg.setDestination(61341U);
    msg.setDestinationEntity(244U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Abort #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Abort msg;
    msg.setTimeStamp(0.847571993358);
    msg.setSource(39804U);
    msg.setSourceEntity(49U);
    msg.setDestination(29235U);
    msg.setDestinationEntity(45U);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Abort #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanSpecification msg;
    msg.setTimeStamp(0.741590450286);
    msg.setSource(6315U);
    msg.setSourceEntity(133U);
    msg.setDestination(48674U);
    msg.setDestinationEntity(66U);
    msg.plan_id.assign("AHKUPSQKNVLDROXEZFLKJSLOCZHSUHFDFYDIVQGFTNDGJ");
    msg.description.assign("IRUXSEPWCWECOMJPTGZLCZXADETMLRYPEPUTGPVSQOEBKWAYVBIGRMXSJHFUCUDFJUEQHQFFRKLAODJOXMMYPGANTPNHRICEVDVWNUATJLHAAONGUEVRRZQWXTAIEQKXSHIVJMHLVEXKGFCMZFQJYCKTWGBSQDBXOBOYHQKNUGYGNGLMXJSNVYOHOYDFLIINFXTRMCKFJNBZR");
    msg.vnamespace.assign("SMFEGBEXJCGVDWGJOHYEWUAMFSTRFVYKJAKQZUEUZEJZPMBDRYBOWNRDSYSPSENTBCHLCEGAOLJMRJFXYTQDGBEOBWVQUYVCNNTXZXOHRHFSQABKXCWFELFCWJQJDETTALMJTKILBKGMPFXIPVAPUYZZSGPOHXKSOCWNTQIRMLIUDZNFRPYKGPIJG");
    msg.start_man_id.assign("ZYWODHIDUVROZGWCLAIDVSYRLNQYSUKJBRBPHHCKTEWRJUKFSPIUFNPKPLXBIANODBKZETGPHZTNTSVZDGYNYUNAATMI");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanSpecification #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanSpecification msg;
    msg.setTimeStamp(0.846624464331);
    msg.setSource(42849U);
    msg.setSourceEntity(226U);
    msg.setDestination(5420U);
    msg.setDestinationEntity(205U);
    msg.plan_id.assign("BVJUDBPOLHPJFYTMQYMFJKIXDSEVNCUVQXTQDKWYZWOYWRANEYVUIDINGCGK");
    msg.description.assign("TKZEGKIMSAPAZJHAZWLQGXYYRJZZBTEDDQBIDVROGEYOEDXLQESANORAZNWCRMAMCEFJUXHFCFNEWPVCTSYHHRSQXRBGFPLPVOPGJKDXBEKTBFFLDOTUMWKNBFNIWCDMPNOXCHCYYQQILQZRQXJGSERNDYJLXLTWIIUT");
    msg.vnamespace.assign("LFMXQDDKGMWLZSSCDSNIWBYPUOWRPWHD");
    msg.start_man_id.assign("KILDGNHWGCHBFSQZRRMLLGFDBIYUMKVNOYDKHATRXRZAEUYTUJGDUTEFRVOSQTAXMSFBWWAJNDSZJTGOQGVKKZPKXZVIXURRIXMQYSPXCQIFJTWPTYWMUEHNWPTGIOYYIVJXEAOPCNGXUBNMYRAFNJSBQBGIKHCOZZOOZWHILRYMZUFLCSWAMWQUBRBTQQLADJPKUWFAVKSXDIFMHEPTHGBAHCOKPBPJNLOEECVLHEJPMNEZCVDJD");
    IMC::PlanTransition tmp_msg_0;
    tmp_msg_0.source_man.assign("YJTSPKQBDMEVDBCZWWPEPXANCIJKDAQOVUZMRHXAXXYERMOHKLCDEQJZDUVGEHTSTGRVHYBCTDOKTXWJSDOVPRDXQRRWIGZFRJIYKHNFRYTPRVFMJSNHVWSSIFZFEJFZKQUVZIXLIVPPZQLEQFATXZUH");
    tmp_msg_0.dest_man.assign("LGSWXANKIHJHGKZHXTMKFEGXSTHQHRASGMPYSLRJZBKWPDYVURYSFTKXKYMWIIBTQVNWNZJOIEORNLUOBGNXVNHFKQFLQZJDBIIFJYDUQOATEPMAVDJVDPMIBXUTZXFVFYFEPQGKETDAEAMAXEAPUQSROLSJAUJCCRLIRUGUYVCLWYMZMNYDSBQOFPDGXHEZPBRMNHSULCMRTBOXCI");
    tmp_msg_0.conditions.assign("XIIJUZXJBGRVHTVXYVLCJJIEFXGVVGKSUMLGSQZDSBPQYYMUQA");
    msg.transitions.push_back(tmp_msg_0);
    IMC::CacheControl tmp_msg_1;
    tmp_msg_1.op = 43U;
    tmp_msg_1.snapshot.assign("BHLUFJIQOQUADPRTFHQJMEUKGXAECROTSDGIASNZJUMRBMTABFJGZVHVWUWEKBLDQIFTNGNTOHVHYXGOLXKJLDYFWDWPUKFNAMNPYVHDTYYPIEPPPBZCWTZFXASGWPOBYJSACRCBGBKGZCOQROUKOFIAOCFHVEYNALUBXEZWIGECNWUNMRCRRLXVLEPBIFCVLKEVXQWPTRLQMHSDMZTVZDYSXSCNKDJQAU");
    IMC::TrexObservation tmp_tmp_msg_1_0;
    tmp_tmp_msg_1_0.timeline.assign("SZYYLMHHUNHSFCFEGYBGZNCZKOXWIWYLJVRHLXQADQFKMTGNURVTWXTBHIFPHZNASQRLSQVOLJCZSJBKPJIWIWHXGXKSIZDOPLXWPOTNUWYDBWAQQDNUVWUTUCMPADEKXOZVDRFOZDPGJSNGBZMNFYTQRITOPHKLKOESECKMYYXCOEMCDURTDQPBNGPJIDQFMCTYSIAIUHB");
    tmp_tmp_msg_1_0.predicate.assign("FZEFPCFHNSXLRZYWTGQGLBJUYGQQJIQMSEQSROURKYV");
    tmp_tmp_msg_1_0.attributes.assign("AOCINVYOSTKTNGDVBAWUSUFEUMUVWDCEEKYWTKIHGMKMSPHRXUPNKLJGSHAGEJZXLAJFJBGRIKCVJZOCPRTCBQQECLBDHEHANZHFQOXXRNNWULRGDZTQKBSSFDAWUFIORLMCVHXLIZFMPFILYWSHCUWJLPZYTCJZGNYCDEASMJVEDOAZBATYQWOZIOBSJBYIKQT");
    tmp_msg_1.message.set(tmp_tmp_msg_1_0);
    msg.start_actions.push_back(tmp_msg_1);
    IMC::Sms tmp_msg_2;
    tmp_msg_2.number.assign("CYMWBTPLHALGBRUE");
    tmp_msg_2.timeout = 23470U;
    tmp_msg_2.contents.assign("DBUPMTFWHTIBDFWZWOHVCTVIFOKKWKIYCIAVHBVJYKJEQFYGMIGBNLODDLPSCDTUAPWCLPCPSTRRTKKAYEGLUESPZQNVWBFHRSAXXQEVCBFOYAJAYXZXQZALLKMYNWWHVRZIUPSTJBNTHOOHMMGUSCJKQMNPYO");
    msg.end_actions.push_back(tmp_msg_2);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanSpecification #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanSpecification msg;
    msg.setTimeStamp(0.745794280617);
    msg.setSource(64479U);
    msg.setSourceEntity(183U);
    msg.setDestination(5573U);
    msg.setDestinationEntity(84U);
    msg.plan_id.assign("NKDZKEAPEEGNYBRJXERUIFBULTECUA");
    msg.description.assign("WBTJXSECHWTLJDLNBXWNSZRHWLMRLRRODGTMNSLQZCIKASOJVQZJDRNAIKAABGVVUBJJLKDTCBUXQZGUTYQIFZHSGDRADOIEUGTGSKEDZPMTUTLGQIXNNXDPBHBYZJNFBCYZLAIEKMNURWUOMCYESUVYEMWYHOYQBYNMXSOVRGPEEMACQCRAKLHSFJXHCSMKYPTBJ");
    msg.vnamespace.assign("RJSBJYYVTCYXSBBVFJEDQCGIRYUPNRSADDMXZRWUBKSZUM");
    msg.start_man_id.assign("TSETEITMESVGSLCWIZKUOVOPGLNVHGTJZHIABELHSKOVJXZCHFLCUXSWPMWDLBEAQWSVONFZXEQTNAFNJTADCLXRZHMMHIBDUKHPZUSZYNMCLWAUSPRXOGFDOCZBJOUTPMPX");
    IMC::PlanManeuver tmp_msg_0;
    tmp_msg_0.maneuver_id.assign("CGPUYHLIOGNWOXMRLHNUFMQFNIWZFFECFYSXSWRYKIWYAGMHZICTFJOKVIVLNJENHVFZGKOLERVBWMXZQHQDDCTTQFBGTBVFHBCOGYPUWHUPCDGECNTRSHIJKEBWZGQOBOBMKTIHTLSKTODUITRKANEBEDMYR");
    IMC::Goto tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.timeout = 30462U;
    tmp_tmp_msg_0_0.lat = 0.231810785621;
    tmp_tmp_msg_0_0.lon = 0.221801386524;
    tmp_tmp_msg_0_0.z = 0.208806870403;
    tmp_tmp_msg_0_0.z_units = 185U;
    tmp_tmp_msg_0_0.speed = 0.618629627862;
    tmp_tmp_msg_0_0.speed_units = 138U;
    tmp_tmp_msg_0_0.roll = 0.998070854068;
    tmp_tmp_msg_0_0.pitch = 0.13929493156;
    tmp_tmp_msg_0_0.yaw = 0.0363713904903;
    tmp_tmp_msg_0_0.custom.assign("GASDMWFLAXCUPUZVEZWLEALDNAYIKQDGVZAVEHVSRAZQZUUHKJCSLRAGHJJXXCZIOXVTZTNXONDNHDJZBRPWDRWIKXXVYEIKBHBYUOPIUSPWTMGEJYLCIPSMFLBYDNCCETMSOIDGCFDLSBRPKNAOHKHWFIUJCTYBFXOMLMGEMMQSCTJKGQQQZKIQWPBULRCHWEFYMFONAVDBGTKXVEOTPIJHZQHGJYYSBQRPUOFQVTORGJNELRFKFN");
    tmp_msg_0.data.set(tmp_tmp_msg_0_0);
    IMC::AcousticOperation tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.op = 167U;
    tmp_tmp_msg_0_1.system.assign("GYMFXIYZEGIIWXPMIDBENKKQLFGWHESNEVOXUXHZTHATZLKDJCSAKORSYUNBAQLZYUVQJXIQSHUKDZZEOKFTVRRFJUVUCVNGSOYGNOXOFQXK");
    tmp_tmp_msg_0_1.range = 0.703741277427;
    IMC::Acceleration tmp_tmp_tmp_msg_0_1_0;
    tmp_tmp_tmp_msg_0_1_0.time = 0.422305641209;
    tmp_tmp_tmp_msg_0_1_0.x = 0.371980870052;
    tmp_tmp_tmp_msg_0_1_0.y = 0.303566365056;
    tmp_tmp_tmp_msg_0_1_0.z = 0.475004421559;
    tmp_tmp_msg_0_1.msg.set(tmp_tmp_tmp_msg_0_1_0);
    tmp_msg_0.end_actions.push_back(tmp_tmp_msg_0_1);
    msg.maneuvers.push_back(tmp_msg_0);
    IMC::PlanTransition tmp_msg_1;
    tmp_msg_1.source_man.assign("XWZKWZNGWJGVFSTACEICFOZ");
    tmp_msg_1.dest_man.assign("IUMOXZIICOSJXGATQIVXKATBCBTQSXTTMBYCDSPPKGYCGYQBWHOXRIGGLAFEFPLPERIDKNNANNEDUOVTWLBDLWOZHUSXAMXLIZHQUWYHKFRXQCEIVOMBLCZDDKQVHUHJJVEMYASKHHIWFVYWMKAZLBJREQYMLBJNVYFHYOPZEBTAUXWGAOKWJNONCTVSTQVZCEBJNZJSMMZRWHPMPC");
    tmp_msg_1.conditions.assign("RWHUXQWFXODPMMVOZPIPTALMCNCTIJBBJGIBRXALOMKISUFYAZCGJALNJGRSHZMBQZNJMOYKQTWEQEQYGNBXABVIKESECSYYUDWZTDFVFZPYOBGHNDBKRFTHKZNJFIVVAWLTCIPVBYJXXUNWDWULLGCGORHECENRMAHKLEECNPPYDDEYTOZZHHQSDJJVLIWKKJSTRULFGRTGDPHZRFPQWURVFX");
    msg.transitions.push_back(tmp_msg_1);
    IMC::EntityInfo tmp_msg_2;
    tmp_msg_2.id = 179U;
    tmp_msg_2.label.assign("IGOAUEEXDX");
    tmp_msg_2.component.assign("JJTCMJDVMNVJALMURULFAIWKKBYZIBSTSYJCZQCYQJIRKACHMRPNLAUCMYZUXMUCBSDMOQDHFAQFIJZRXRZPVFLEBEZWXGESUYFDAGROKINIREHWZNAVQVXOWWVWXPRUFXAZECJGMILBZKDPSDYAOXBWBVNHCXOEQWTFMKPDEKHLGTIRNZJEEMTTNCOISVTKFNTITLHHYOYEWPLOUYOLGTOGGFX");
    tmp_msg_2.act_time = 30958U;
    tmp_msg_2.deact_time = 16370U;
    msg.end_actions.push_back(tmp_msg_2);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanSpecification #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanManeuver msg;
    msg.setTimeStamp(0.288198883225);
    msg.setSource(1776U);
    msg.setSourceEntity(6U);
    msg.setDestination(40222U);
    msg.setDestinationEntity(34U);
    msg.maneuver_id.assign("NHFIJJXQBDQYSNJCDRXHTWEADVCUMDIUXHLTRLGPEUY");
    IMC::FollowReference tmp_msg_0;
    tmp_msg_0.control_src = 25369U;
    tmp_msg_0.control_ent = 58U;
    tmp_msg_0.timeout = 0.3797491371;
    tmp_msg_0.loiter_radius = 0.455178699144;
    tmp_msg_0.altitude_interval = 0.500703118711;
    msg.data.set(tmp_msg_0);
    IMC::FollowReference tmp_msg_1;
    tmp_msg_1.control_src = 16885U;
    tmp_msg_1.control_ent = 100U;
    tmp_msg_1.timeout = 0.361453205762;
    tmp_msg_1.loiter_radius = 0.322295921396;
    tmp_msg_1.altitude_interval = 0.665143447992;
    msg.start_actions.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanManeuver #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanManeuver msg;
    msg.setTimeStamp(0.0739684772169);
    msg.setSource(6085U);
    msg.setSourceEntity(237U);
    msg.setDestination(41235U);
    msg.setDestinationEntity(80U);
    msg.maneuver_id.assign("PXORYYEEFGIUSDTYSOYJDGKZLPDCLAWAKEOTWEDZGHMPMFGIFZOGUPQNXHHNARBURHMJPHYTLVAPTDQIHLZXHYIVUKCZKXBPWMCAQFUIZFISTSBFV");
    IMC::PopUp tmp_msg_0;
    tmp_msg_0.timeout = 6395U;
    tmp_msg_0.lat = 0.550655128174;
    tmp_msg_0.lon = 0.834269726678;
    tmp_msg_0.z = 0.947898726605;
    tmp_msg_0.z_units = 46U;
    tmp_msg_0.speed = 0.536832763545;
    tmp_msg_0.speed_units = 12U;
    tmp_msg_0.duration = 15990U;
    tmp_msg_0.radius = 0.489746495458;
    tmp_msg_0.flags = 76U;
    tmp_msg_0.custom.assign("QAOUHIVWHDIPPGNWJAIXXGLTJWQLDOIHVNFZRQNXPWFDMKMLOJR");
    msg.data.set(tmp_msg_0);
    IMC::DesiredVerticalRate tmp_msg_1;
    tmp_msg_1.value = 0.731079531038;
    msg.start_actions.push_back(tmp_msg_1);
    IMC::EmergencyControl tmp_msg_2;
    tmp_msg_2.command = 100U;
    IMC::PlanSpecification tmp_tmp_msg_2_0;
    tmp_tmp_msg_2_0.plan_id.assign("YWCOVDLSFIPPQBFFJGJOECGQEEROPYZIURRYNUIFVTKDAJNKYOEHCAQJMVJPHRDQNFPTRTCDGIHVSMDDFAVUXGXJLIBLFENDLZCMPULDRWAXYVSQYOWYESKUHZKEBNBPNRKW");
    tmp_tmp_msg_2_0.description.assign("CMVJZSBLEXWPCFUDPETBFQODHIXXJRYJNWCILTPCTICHSBGAGUOGBDCFQJEQMPKNCUXYYNYOSYTENZOUNPRGGULPOVSEXRPHGZ");
    tmp_tmp_msg_2_0.vnamespace.assign("ODGKVYDNZAEMJOPXWXVKUBHQUKZZQWRCGQEURXEIFOKLNMMYSSLJVEZQQBBTJMLFRWXZKCMZANKHLCNFGBYJJRYDPXEDPMOFETJD");
    tmp_tmp_msg_2_0.start_man_id.assign("ARPSAAVUAXPCDWLOHAAZFDDKYXXBNTMCQHUGROFOIUYUCCQVPTLWOINJJBTXQGQLEVPAMTEJGPDPZMRQYGDVEQBZIHYSQLBLRAVLRMGUDCBJPOBYLSWEERTJISMVHKHQWZNHZEPUFFNA");
    IMC::PlanTransition tmp_tmp_tmp_msg_2_0_0;
    tmp_tmp_tmp_msg_2_0_0.source_man.assign("VZQSYQZLUZABHIQIIIUTYYUARWLAENNXAYRAXBZQUXLIPWOVFHMLGGROGXUILREJYFQUWCVBVJVTHWGFLJSSOGNBBMOIFVDKGAYXVVUILMRCEJHRZZSXGJXATWDCCLDJAEFOPEEZSHHBXKSTRKPVSEDWUMQEHZUNJFOFJPMTBNIPBBMLKKOPSOITNMCFRWNZYPWGDNNMFZQPGYXKYBGRTTDWCTDT");
    tmp_tmp_tmp_msg_2_0_0.dest_man.assign("OHINJRWMZVKGXDDJRJAUEQQIWSRTQDBOAZUKLLWYLTIFQSIYEVPMLOKMFEWJCOAIKJODLBMBAZBXMMLNKGFBEXPTFNCYUUOGCGNACNZTZLSCLTETQWOYYHSRDGCEWJCAPYHJBIHKWFQMQYZXGJMIXNZXVBSSFDHKMRXUVFYISAVZS");
    tmp_tmp_tmp_msg_2_0_0.conditions.assign("GXOGYWHIGHUEOQTHBNJJPOCIYBRAAPOTJGUBGSPIIMMQFONTVQYSXVQPUFFNAAXMYUJFCHSWSEKHLMHCGPRDNRTWKTLMHIWCZSWCQKZRIVXSNSUCUFOQMHWXYKMXBPCYBZLKDELLFHVFMZRSRYDPKDPCRWZTOFAVJJZEQTAKYLUAUJUBENLDRVMEVWLNAPQTNSCDIOKYCGGXTPDBDEELDBZZ");
    IMC::PlanSpecification tmp_tmp_tmp_tmp_msg_2_0_0_0;
    tmp_tmp_tmp_tmp_msg_2_0_0_0.plan_id.assign("KTLZUCAGRZQIVLKNWPPELLFNXFUAGFHSOUVIYWHSMWDQHPCLSBYQXMJJMAMWLZBPELAXZVQNZJRBNPIINOHMKIYPKQZTMHSUIMRIMVNUFVWERQNATLEIPOXCDNYURDXJZOEJ");
    tmp_tmp_tmp_tmp_msg_2_0_0_0.description.assign("TUJCENKWLIHRJAKMQVYGNLNCESHLAWCTWOQSLGURXARGAZWFAVVYPPHUOLJOXVQSTUCMBEAYGKFONMFJLSPHPLPYGRXWDXYYVUTQZIJOEYHSWFFREJGNOXOVMKEAXPTCDWAK");
    tmp_tmp_tmp_tmp_msg_2_0_0_0.vnamespace.assign("OUAPUWGOCRWLVAEPXBI");
    tmp_tmp_tmp_tmp_msg_2_0_0_0.start_man_id.assign("TAWTZFNKWBYCGOHBZKFPDALQZVQLHHAYQIVPPISUHDBGARNPTRERCRWULICFWQIYMMTAFJGZPUSOQQCYMPLLIVOHSTIHXTCENUZFOZFBRCDAEJTITHBJLSOYRHLKSXKZYVYXMQEUJJYOBUJFFAQRGSZJHFMOJXUNWVCYEGXNDLSUTCYKDXBEWVMSRLNARGJCQIWEODKHMPFQAMXSWPXSNDIBKWDZNKKVIVXLZKVM");
    IMC::PlanTransition tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0.source_man.assign("ANCEPOSOXTHNABBZXEHYGJOFTOVTIIXOWIBFDKZYEIWLDTYEHPBGWLJBOANYKIPWKAQJGDKMMUCQLAFYQREJZFJYFKTBETCBSRBPHSODNGEQMJVYWJHHDKLSSRUTGCUKGJFQNZMAYAZACIIFVLFOCTDZUHREPGTQMXFUCLAGUEQMVKVGSDWRWCYQCRLUDGRSZBNSHIRMFNNDVDVAPNOUZHSXXMTEPWJKUMVXPLQ");
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0.dest_man.assign("NQVJWUWDIKUJTTKDNMOXPUZNECGBMLPWTJBQYLQGONHNKBDXWCVPGRZFBMUAEXFMSCCSVQMPRBVEFDFLIQZPDZHAPBIVLGHJXBENNAAAXJYEUFEVGPTBUDATSQAXQHIJSWRVEBFCHGEEZDHWKCKCLOOAYDZRDHOZSQVDAIUTIFYMYUFOJUUKYJMOPGSMXJRIPCYMXGHWLLPOFSBYTGFLZNMYSICQX");
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0.conditions.assign("APUTJQODCPTRSFDOFKHCKGPYRGNDHVUVAOMLCGORDYKZELWWKBSXEDGYQPMNEITTMDAILEFQKEMEIVTBNNGJXUJUIRXJBJSVMRPMBOHVMITCRQFUWZLLZSAPJVKHNUOFSQWZCLMBZAKVBLXCXRZFSYHSBNYTTQAZPLIWYYWRAGHBAVFGIUTEZIPCDXFXFBJPNCNOSDRMGLOMTSCWUWVAGHLWINEGXUHXWE");
    IMC::StationKeeping tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.lat = 0.0654909257666;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.lon = 0.412955971638;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.z = 0.764809842704;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.z_units = 51U;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.radius = 0.463772761592;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.duration = 31775U;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.speed = 0.099948912421;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.speed_units = 167U;
    tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0.custom.assign("DKNHJTQYRVPLJXUFQVFGRAOBQPZQNIDUSDNFUQRSGTDLKEHHAFYRKVFDTFGLPURTOVCQHZEAULOZCOOISMABRMCPQMMUHIVQLCXZFCYINVLBFXSXJBTOEAOZZQKTKZVIVNPNYVXKYAGTCXRCYIEPZPEHXAFGMG");
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0.actions.push_back(tmp_tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0_0);
    tmp_tmp_tmp_tmp_msg_2_0_0_0.transitions.push_back(tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_0);
    IMC::PathControlState tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.start_lat = 0.0799954490394;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.start_lon = 0.517409287258;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.start_z = 0.174664712955;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.start_z_units = 124U;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.end_lat = 0.162818760791;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.end_lon = 0.296781499482;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.end_z = 0.0279131141977;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.end_z_units = 127U;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.lradius = 0.0441599538469;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.flags = 213U;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.x = 0.943506354137;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.y = 0.271604191886;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.z = 0.53107335439;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.vx = 0.784716985159;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.vy = 0.370195367215;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.vz = 0.953665820224;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.course_error = 0.269416176714;
    tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1.eta = 53084U;
    tmp_tmp_tmp_tmp_msg_2_0_0_0.end_actions.push_back(tmp_tmp_tmp_tmp_tmp_msg_2_0_0_0_1);
    tmp_tmp_tmp_msg_2_0_0.actions.push_back(tmp_tmp_tmp_tmp_msg_2_0_0_0);
    tmp_tmp_msg_2_0.transitions.push_back(tmp_tmp_tmp_msg_2_0_0);
    IMC::ButtonEvent tmp_tmp_tmp_msg_2_0_1;
    tmp_tmp_tmp_msg_2_0_1.button = 233U;
    tmp_tmp_tmp_msg_2_0_1.value = 230U;
    tmp_tmp_msg_2_0.start_actions.push_back(tmp_tmp_tmp_msg_2_0_1);
    tmp_msg_2.plan.set(tmp_tmp_msg_2_0);
    msg.end_actions.push_back(tmp_msg_2);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanManeuver #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanManeuver msg;
    msg.setTimeStamp(0.937909754937);
    msg.setSource(31576U);
    msg.setSourceEntity(47U);
    msg.setDestination(60508U);
    msg.setDestinationEntity(46U);
    msg.maneuver_id.assign("VTVGHKQYSJOLBQZGISCSJOAOABBSYJTWDNGENPBQZPYOSEIPLCEBXMIURQWLXEFRUTDVJVUILFGLOJSCTRSHWTWMWUZLANYVZSNWRFTOJ");
    IMC::CustomManeuver tmp_msg_0;
    tmp_msg_0.timeout = 16483U;
    tmp_msg_0.name.assign("JNUMIXKLSMIDVXGATIFCPQAPHIRGOKFQWZFFCCPTXILTDKCUYKCWRDYYKUUQMSBMWQHVZIBKPAATJPEXGZIIFHXVOFTMCPRRLXGFUURYSELIDNJGONGBKJOGDUYEUDFWVYRSETHOASPYNLBQVLLIZ");
    tmp_msg_0.custom.assign("EZJOFXUUKLBDDMVPHNZYOOGPHEQRHOVRTGKIQQBQMZSNRHOYGXMUISKPTVHNQWBKXCQWDPGJNEJUYPCWQWNPWPXALJSYFAIDNRWCWFFGXSYHZEZVBRODYVJIDALOFMBPSLAGFBGYPLOIZDLTNAFBZTRRTZNTV");
    msg.data.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanManeuver #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanTransition msg;
    msg.setTimeStamp(0.481335326965);
    msg.setSource(63305U);
    msg.setSourceEntity(216U);
    msg.setDestination(16119U);
    msg.setDestinationEntity(3U);
    msg.source_man.assign("LFQILNQYMGHYZWFLTSBXIABYMSWPWPKCBFWFLPYGLXNTWIVZAYVADHGYEPNXWQEYWPMKOXULVSKKEAUVAQXMUSXEEWSRZBJHGRJBIOLCAHZZZEGSRSPWDJGXOESGKVCUAUMIGNLRHJTKPFKTROBIFDVATQOPOSMDZZZDCAOHCRVIOIDNBUYPPCXXTKDFVVYCUQYFMCRJBUGSKDQWOQJBNIQERTEN");
    msg.dest_man.assign("IFXRSGFFAHOYFKFCRQCEUDKSAJWJICRIZLQDVGCOLGZWN");
    msg.conditions.assign("NCDRSICRDDEFFIKLCXKOGDMAVLRFSAXQKRFHBRVUASYCUHLEZBYIEBYTHAAHEQOUOQWYSVREAEIKNJTZEDNRWTWJGMCZTJEBQUZOMZYIMPAFZMVOIWGHDYFGOVMONDNGSJUBUGQECVOFTHYXQHXSSLIUUFMJYCZNJQMWPZBBZULBJPM");
    IMC::IridiumMsgTx tmp_msg_0;
    tmp_msg_0.req_id = 59319U;
    tmp_msg_0.destination.assign("TMLCCNXPAJJDTEMJVHPBKWZNXZEYSHVUGOHSFRCCGVFXHQMWEBDAJSYFHFUIWTKOUYOAGSNWJKZIPLMDLLDFVEKHMCEORAGIPYILSBDKPURQKCJVGWXUFQGAYXVQCRGGJDZEFGTHTBTDBHOBLNKEVRLEHBYDPXRHJQBTNQWPIYTYYPUZUOXOJCSWSZINCTOFCNZXKWSZVSGQSEAQMU");
    const char tmp_tmp_msg_0_0[] = {-12, 68, -121, -64, -95, 39, 62, -23, 14, 47, -109, 64, -36, -56, 1, -80, 11, 110, -13, -43, 81, -81, -23, 72, 59, -67, 57, -54, 17, -87, 37, 124, 35, 37, -66, 82, -95, 121, 69};
    tmp_msg_0.data.assign(tmp_tmp_msg_0_0, tmp_tmp_msg_0_0 + sizeof(tmp_tmp_msg_0_0));
    msg.actions.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanTransition #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanTransition msg;
    msg.setTimeStamp(0.85154900748);
    msg.setSource(53262U);
    msg.setSourceEntity(38U);
    msg.setDestination(50025U);
    msg.setDestinationEntity(189U);
    msg.source_man.assign("GRGPLCUCITBKXZKQSOURBCEGLALNATVRZLULGEICRXKGPLKUYVEYOEOAJVOSMVXQBAYOXSHBUMAUQCNDTUMAMFYXVWYIJZPDMPRXQBPOINARAANORJNHVKNMLWBGOCRNFZZMTGRPQ");
    msg.dest_man.assign("RIXKEGSTFFLFLVHEEQZFDNKHZGOXBQUZFFKSLRYBYHDLNAKRMMTOZULXIHWMBFQSZYNBFWGQSOTISVBCKSPGULJRIYWOOEDVTIDKHPNCNKTCWRCPBLAXXNGSYJVNPPPC");
    msg.conditions.assign("ZICAPBGLKJWFMWRYDIXQTJ");
    IMC::MagneticField tmp_msg_0;
    tmp_msg_0.time = 0.67933600897;
    tmp_msg_0.x = 0.873862833813;
    tmp_msg_0.y = 0.153311550319;
    tmp_msg_0.z = 0.300972591635;
    msg.actions.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanTransition #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanTransition msg;
    msg.setTimeStamp(0.312535036349);
    msg.setSource(24828U);
    msg.setSourceEntity(235U);
    msg.setDestination(37350U);
    msg.setDestinationEntity(30U);
    msg.source_man.assign("ZSNKAATVJCLEXVAALNIBRJTRSNFWQ");
    msg.dest_man.assign("OHLPRIPRQMKYPXNLAWWHXWGYYGTVWNNSVMPWKQTYFRIGKCRHDVOPFMQXDKLWPEETAVIISXZZUJFGYXQAEKUWKOOMBJDNFNAGJATUJAFCMYUAWSRTKZRIEINMMDXTGCFGPUFZJXHJIQUHCVFFCWXBAJOYZEBCISSWDOZZJ");
    msg.conditions.assign("HNSBEQQQXCEJZVOBPTOTOFWSCNVDDZPPCBFWKBMQQKUHUUHQXIETMDWUZMXDVIVHBCNYLUJTMF");
    IMC::VehicleCommand tmp_msg_0;
    tmp_msg_0.type = 204U;
    tmp_msg_0.request_id = 45492U;
    tmp_msg_0.command = 212U;
    IMC::Rows tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.timeout = 7427U;
    tmp_tmp_msg_0_0.lat = 0.519889088803;
    tmp_tmp_msg_0_0.lon = 0.41686844265;
    tmp_tmp_msg_0_0.z = 0.898343140477;
    tmp_tmp_msg_0_0.z_units = 234U;
    tmp_tmp_msg_0_0.speed = 0.971544996381;
    tmp_tmp_msg_0_0.speed_units = 63U;
    tmp_tmp_msg_0_0.bearing = 0.84702913793;
    tmp_tmp_msg_0_0.cross_angle = 0.45279057488;
    tmp_tmp_msg_0_0.width = 0.589896400514;
    tmp_tmp_msg_0_0.length = 0.24560823187;
    tmp_tmp_msg_0_0.hstep = 0.113807503988;
    tmp_tmp_msg_0_0.coff = 4U;
    tmp_tmp_msg_0_0.alternation = 195U;
    tmp_tmp_msg_0_0.flags = 64U;
    tmp_tmp_msg_0_0.custom.assign("BLSODRTOMCSRJVWQYAQRHWXIKRBSPXZAJDFFUOVKWWKWADBJASPFERABGDHFDLBJLSXVEUNOEPANOUYRCVXNTYAVMBGXCFQHPTMFNSXIMFDRVNETGUGMTQYDNWMKBWZFVGLHSPQXAEJMMHJSCBCEJDJDIZQKVNZLNTPUZKCVYYRRAGFIGKJWIEIQNBUO");
    tmp_msg_0.maneuver.set(tmp_tmp_msg_0_0);
    tmp_msg_0.calib_time = 35570U;
    tmp_msg_0.info.assign("SQTZIRQNHFMJSOTAIDYKMHMQBYLYRNWXSKWPAIEXKERGTUFUFMOECXAISTKHOYGKRVGUXMIGNFBEQKQDNZVOTFEKWDFSCELCJFMGUJJQPCJWVYBPUHXCXJVWVMHEPKLSLRPBOMB");
    msg.actions.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanTransition #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControl msg;
    msg.setTimeStamp(0.152441299133);
    msg.setSource(54433U);
    msg.setSourceEntity(207U);
    msg.setDestination(50185U);
    msg.setDestinationEntity(127U);
    msg.command = 222U;
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("UNDVIEZMIWFTHQCNPOQSHASJIOZZADNAWEPXZJXKNGYEGBPTERDLJIDGAWZQQEQUTRVMUYVVDXKCALHFYXTLRMFMNGCPZPEBVFTSGAFWYEPAACCYQFIFUMIXCFHSLWLNPVMHRLKDGCXIPJGXZKKWBNWTTDWRKQLZDETOSSYPEVQRQHOYGUOVBWUN");
    tmp_msg_0.description.assign("FROAUMJFXLPRJIQLFOUFVGNHELPADSCAEUFQQVBHOJVWLUZVVIBDEPCERBEGKXVKSZSPWKUGMSXGNBPIDKOGKHFCLIAAMYHETQMOYNNRYMWSRNQNHLPTBWOYTABDJUWXRFCRKBQNUVBEAEXXWYPZMCSKYIOYKICJINZYURVMXPDGFDGOQJPTZYSXBUWGLXGMTPTNZSCHSCQZOLNOFIHWAYTWZXJDDZFEDRJBIKMWAG");
    tmp_msg_0.vnamespace.assign("HGDTYFGSNGQEZESJLWZEIUEFXVPHMVQTXVBZPLDJORWJJSGTAJIIGOSELDYPVOHPEOOUKIBNJAZYZGZCDCWQXRXDNFGNBJFPTNCKGCAIGSWBBNPQMWKCVICBCXRIYULXQKWHLUEURFRFBJAATLURFIEODCUDGNPFPTYMHTLWHOXVANSQSNSTIWAMDN");
    IMC::PlanVariable tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("JRFFDVTUHOBPKOLWPXZSDPOYGVVCGVJNDGCZRTPHLFBHGHDJRHNAMUXHLHNQTWLKITAFPLWAMSFRZEHCMOJWGNIVDQNPAZEXAXBRNMTBFSAEQKJQMPIYXEXPRXWQQBUKPBZZANQLDNYUAERGBHVSDOSTIRTMFGYDWBJOKEXCCZBDYZXKYIOXMTAUZWSBILSIYUJYCSIRV");
    tmp_tmp_msg_0_0.value.assign("AOCDVXOMIIWZGTYXB");
    tmp_tmp_msg_0_0.type = 56U;
    tmp_tmp_msg_0_0.access = 59U;
    tmp_msg_0.variables.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.start_man_id.assign("LSUPNULUQPHJTCLIVFGYDRSGHAAMOIBSQQPHMMGDUY");
    IMC::PlanManeuver tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.maneuver_id.assign("ACEKJPLLBKUOELYBDUAGOUFSVBKISBJJXPMGXLPWOFOOKPJSXZGHTALTZLMIGAITPNFNWESJXNYPGAXQOEQYZTKQUJQPDXEGVIACPYJGFMQPXTOTXQMBAETXLDVNWDZGRNF");
    IMC::FollowPath tmp_tmp_tmp_msg_0_1_0;
    tmp_tmp_tmp_msg_0_1_0.timeout = 9746U;
    tmp_tmp_tmp_msg_0_1_0.lat = 0.920625882511;
    tmp_tmp_tmp_msg_0_1_0.lon = 0.984528016882;
    tmp_tmp_tmp_msg_0_1_0.z = 0.0798869910077;
    tmp_tmp_tmp_msg_0_1_0.z_units = 177U;
    tmp_tmp_tmp_msg_0_1_0.speed = 0.238673112384;
    tmp_tmp_tmp_msg_0_1_0.speed_units = 120U;
    IMC::PathPoint tmp_tmp_tmp_tmp_msg_0_1_0_0;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.x = 0.667888607577;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.y = 0.782961204329;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.z = 0.17219233664;
    tmp_tmp_tmp_msg_0_1_0.points.push_back(tmp_tmp_tmp_tmp_msg_0_1_0_0);
    tmp_tmp_tmp_msg_0_1_0.custom.assign("QBVFATIYQVCSJPUDXZJLPFLRZJY");
    tmp_tmp_msg_0_1.data.set(tmp_tmp_tmp_msg_0_1_0);
    IMC::ServoPosition tmp_tmp_tmp_msg_0_1_1;
    tmp_tmp_tmp_msg_0_1_1.id = 175U;
    tmp_tmp_tmp_msg_0_1_1.value = 0.768739586004;
    tmp_tmp_msg_0_1.start_actions.push_back(tmp_tmp_tmp_msg_0_1_1);
    tmp_msg_0.maneuvers.push_back(tmp_tmp_msg_0_1);
    msg.plan.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControl msg;
    msg.setTimeStamp(0.0206388550419);
    msg.setSource(58411U);
    msg.setSourceEntity(56U);
    msg.setDestination(48262U);
    msg.setDestinationEntity(134U);
    msg.command = 170U;
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("UQEIMPDNOUCYTBIERLMJFWDAQHTRKJDXUSHLMNZAIGYOKYPPBZRDSBHCKEGTBBEUABWLNIXDTHOEZBISHVWZLRMNFDPXLFTRYUCYZVDXWYYLVFTSGGAMSLXQXJOREUWDWWHVSJNFLNGDAZEXAOMOFIIKQWCOQTVVBQIQLZOLKNAYYFQBTGHJXGTVUPAMJKFIGJKFZKCAUISSCHERCDQMZHRPEKG");
    tmp_msg_0.description.assign("AWOWXMAMCVFFHVRSIBOCORINBIDJTXKIOCDECUAHCDOBOLBJDIRSKMHGFTPAKMOREZLDLQGJLAXVLVGOTFSOJPWKXCPMHQDENJXZJEHUCEAYGYKPLPVUUJWSKQBKVFVBYQTRYFZFSWTBKNFHJIXNHZELGEBLDFA");
    tmp_msg_0.vnamespace.assign("AYROVPCGJCNBTRBQPDFXFDARVWHOEHGQXQLSXFLWGANNVZBKBTWSCUCTJESFZDLIMGOIZXTPNKLXZLEIVERGEHEOYGMWHNZTMXACJBKJYSQAMOXWVYOJMESZZFUMQNYONRVKKGRNVCBRHPJZJBCPIFMKLAIYVLC");
    IMC::PlanVariable tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("VEJXCSKLRWSPLVOLVYUZNHRMFXJNJNEDQYPRLIQCNHVQHIWIFGSFTSMKPWPPWGLVIADNKTOZQYXOJFOLXJWKBLDJCFJOUCVZTKIGREUBU");
    tmp_tmp_msg_0_0.value.assign("MEIIAMHZZTLTFEJWXZROGTXSLZCMVFNOSUTRQJHILBXKAJRVTXLYHEAWFFUJIMPCARIQCDTFLJKNNCFURDNGDHGYJBZCMWQBQLTIXPKSYMWYYJUKVJEHSWOOWQKPCCQAKUPJNAXXVMRHYNKEVUDRLEUPNDZDQNYDWVZWFPBSJLIPGQBHXVYGDXIHRYOOPKEAXDQTMHSDSOGEWLWYGBRGFNLZTBOMCBVIUNSOBBRCSZQKAKGEAVFAEMZPHCU");
    tmp_tmp_msg_0_0.type = 214U;
    tmp_tmp_msg_0_0.access = 37U;
    tmp_msg_0.variables.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.start_man_id.assign("AEMYXQBSNUKDBLKWEINOIPOWBQJK");
    IMC::PlanTransition tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.source_man.assign("ZPOWTGUDQPLNKETCNWTGTRNIILEYSQEWAJFOSKGUZAYVDVGOKTOVFDXRDJLDLSOMJVUIEBX");
    tmp_tmp_msg_0_1.dest_man.assign("JOSGUICXCGWVLHGZBZVQKTRBTIQFCBRXBRYBYRWCRKNDMVCJFNSJYQZDH");
    tmp_tmp_msg_0_1.conditions.assign("ZJBSUPTXPDVEPOHAFYAQGMSDCDPMZFDNZXBMCEI");
    tmp_msg_0.transitions.push_back(tmp_tmp_msg_0_1);
    IMC::PushEntityParameters tmp_tmp_msg_0_2;
    tmp_tmp_msg_0_2.name.assign("HEHHRFUQQNDWBCISSEIICEXALCVKOHGVSVDZZZMGKCNBBHAMOZBILUULTXSTKYBBEXITUSFGOPUABPCLUDARRHHYMCGIMJOYQJPGRDDWDXBTGCEXZDFVYMJYZMFQLEIOJEUANEXQSUMPKELIPJQTYVWSJ");
    tmp_msg_0.start_actions.push_back(tmp_tmp_msg_0_2);
    msg.plan.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControl msg;
    msg.setTimeStamp(0.159445200134);
    msg.setSource(63344U);
    msg.setSourceEntity(204U);
    msg.setDestination(34818U);
    msg.setDestinationEntity(176U);
    msg.command = 229U;
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("HCNOWSQWFDIEAUGETDPDEPKJBOEOSHBIDMGLMLMQCNDKJWBHLNFYWWAGXIMSVSQGBGZLKFHJVLRUAOPTMCKZOPYFBZWRQHACCDIQLTHIBLFFOKGVUJAMRCPFRGDXFBZIZEURKASWKXRVNCARPVYONKQKTGNZBQZVTUUV");
    tmp_msg_0.description.assign("QRSBOZTIBJDTDAVNZNYXTYOHYHRGQVE");
    tmp_msg_0.vnamespace.assign("CJEIYHPEHAYTGSYKXODKBTZNIQDLCJYEPBJGDCLFARHQTFIEUXZJZOIUVBTAOHMWCQKNWSMFIAFMGBZSNQBAPTTFIDVPHEDXITUTUFGSEKUQOWQCHRVVPLLKNFJPYJAWWOBEGNSRFYUMAHFWIAMQJBBPCLZX");
    IMC::PlanVariable tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("BKKWVUWZOODSWMZNJPAHGKNZDUAJZDUTZAEWPAXKEWMILHMLTLQWCSDYVXBRXOEXKNZRHRGPVC");
    tmp_tmp_msg_0_0.value.assign("PEOIQRJZEUATQLXPWGWUDTKBCISOTRWBALMGKPWZCVYUAFQAZFILJIHJYPBYVPFWYEZYPZMGNRBDKMGFCXNGJXHRKQATJBCSDPRCQZWDBOGNNBQITKSBDKAYYEDHEQKAGHPWI");
    tmp_tmp_msg_0_0.type = 65U;
    tmp_tmp_msg_0_0.access = 163U;
    tmp_msg_0.variables.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.start_man_id.assign("QLDEPOPYFRLGFBTUXMOJAVFJNUBXLMXFMYNWKYCOQFQLVWHLEFNFZJMKTTCBSENTFYSDUIXIHIJECWNQOCAPGBFRNPCVBFSBYTKPDPTYWGGDLIMAKPAZYKGDQNUOCBWGWLLMVUEAIIHNZQWEXHPUGZHSHACVTOIXVDGUDXBXJVGERMCIJWARRWVBH");
    IMC::PlanTransition tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.source_man.assign("HFRZWKDPALMHFGRZJDIQGTXKEMSXFRWHYPSDTNVKIRKSQNAP");
    tmp_tmp_msg_0_1.dest_man.assign("UHTEHGAORFXZWRPSSBYPANCNURIINTNBJSKXQERVPDXPWCGZKKSNZFYJCIBEHKUFKJYLFMLJVYMOCHYPZHPRDZPVQVIMWZCAXD");
    tmp_tmp_msg_0_1.conditions.assign("FXGQVFRMMULFOAHAZCSMULMCHRXGEFUKJPGAIWRIOMEBYEQVYUDARTCNNJBDOMZFDLJHUQPRTWXKVLPQMEJLCDDLFZMTDTBHUHQUVASZIISGBRSGEGDTBWBZJFIEGXACAJIBCQPUHDNULQOCZIPGIYZS");
    tmp_msg_0.transitions.push_back(tmp_tmp_msg_0_1);
    IMC::AcousticDiagnostic tmp_tmp_msg_0_2;
    tmp_tmp_msg_0_2.enable = 63U;
    tmp_msg_0.start_actions.push_back(tmp_tmp_msg_0_2);
    IMC::Rpm tmp_tmp_msg_0_3;
    tmp_tmp_msg_0_3.value = 2608;
    tmp_msg_0.end_actions.push_back(tmp_tmp_msg_0_3);
    msg.plan.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControlState msg;
    msg.setTimeStamp(0.0215533779694);
    msg.setSource(38983U);
    msg.setSourceEntity(62U);
    msg.setDestination(9019U);
    msg.setDestinationEntity(83U);
    msg.state = 222U;
    msg.plan_id.assign("UNXSDFSGCUZPNNLKMKZUILDTIMMSUWJNTZXVPEDJMNBQKIQRPYQIRLOGQXNQBZCZFTUKFMGDGNXHZHIPEJYSRHVKOQBOQ");
    msg.comm_level = 21U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControlState msg;
    msg.setTimeStamp(0.457776972736);
    msg.setSource(52708U);
    msg.setSourceEntity(239U);
    msg.setDestination(10284U);
    msg.setDestinationEntity(218U);
    msg.state = 115U;
    msg.plan_id.assign("KNYMBFDSCSKVZFYOBQMWASYMGBSQNRDFRFXUVMKQT");
    msg.comm_level = 29U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EmergencyControlState msg;
    msg.setTimeStamp(0.153480362602);
    msg.setSource(16128U);
    msg.setSourceEntity(203U);
    msg.setDestination(34579U);
    msg.setDestinationEntity(249U);
    msg.state = 131U;
    msg.plan_id.assign("UUGNMYHDHFOAIYOQQDCIVHCNKSBAUVCYQYTFHWQSXGFHLUAYPIXGDUHYDFFMJZXJQQTIQWUBEAMXOZNVKKCEMWYSRHWEFXMPMVKMDREUOZJGRFBVKQTVWGJABSRCZSIJNBWISUOCRKVYXTAMRNHSFMZVZWTSGIJAGYHEENHJFQTGQ");
    msg.comm_level = 186U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EmergencyControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDB msg;
    msg.setTimeStamp(0.681411751227);
    msg.setSource(51215U);
    msg.setSourceEntity(92U);
    msg.setDestination(25125U);
    msg.setDestinationEntity(131U);
    msg.type = 124U;
    msg.op = 25U;
    msg.request_id = 42385U;
    msg.plan_id.assign("MTGZLBSSNIAPWGXTEHZNODWEPWWOKZBSQSZVT");
    IMC::PlanSpecification tmp_msg_0;
    tmp_msg_0.plan_id.assign("UELTAGCOMCKSXYRQVTFPPCRJHRXNGDUZRAWEQAGQSZFKKBYMQWEJILBSMRKHCLVITHWVGVBRUNYANWENCXLGGIFXGTPRUFHIVTJYSCHRWKNCBDXMTKFQPOUQKVQYPZEXOVBTJJKHMZLSXNDSAJEXZOBRHPEZJCSFOIEDWNKLQDQYLFNAMFXZKBMRUZYMZDBYFYOWGIQVU");
    tmp_msg_0.description.assign("PRSFYVVDUEKQRBDZIVKJBXMHJPSGZGNITAIOONELTYGFSWHEIDMFLUXQH");
    tmp_msg_0.vnamespace.assign("UUBLPBDJPKPMHCNRIYCRXKYW");
    IMC::PlanVariable tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("KNZZQLCOOPSDXBOZMJCQMMOPZPYMJEMPTUNBQONCKQLJVAIQAYBJPUWKDCQZXPORWINCYBTIHRRDSKN");
    tmp_tmp_msg_0_0.value.assign("FLKJCODKCDSHVUYWEIPMLSINMYSUEAMDPMLFIKBDLIJZFAIOPYAJFCRXRURUKEDGYRCIOAHWOYMVQXEDLAYTOBHTRYSTTDNDRGJXMZEMWBGSNVCGLCPQUBLPAOVDRMTPAVKXMVJXKOZFBVFNEWVRPQQRAHLCZGHQQUPEWKYBWZJYTBEOTHIFJDSGQV");
    tmp_tmp_msg_0_0.type = 93U;
    tmp_tmp_msg_0_0.access = 105U;
    tmp_msg_0.variables.push_back(tmp_tmp_msg_0_0);
    tmp_msg_0.start_man_id.assign("GIMXLZGAGCYMXAAGYVHTJIEIYAACAJZGYGNXSBMKPXGDHDNYPKPFWUWNGRKOXRUOJVFEECEPFBYQOTPTYSKXNIBJMJVOHKBPVPGJLAMUNSOE");
    IMC::PlanManeuver tmp_tmp_msg_0_1;
    tmp_tmp_msg_0_1.maneuver_id.assign("BRUKXSVEWLIXFBBCKZVFHOIDMTOFXDJCWLFEKPISHYNQUIJEBZXHITMAAKBQXBHFNYEJDKKEWSDZRMECADCQQKYKFNUGTCNHBYOYXOTOLHIQXYGZPEAZZORLXZCYYPEATLOWNAHTMYZTPDNHWGJWRACLOBUJGWZBCSEQSVWAGMLPGMQVIVUYFIDVNHKUFJSFPCNZQD");
    IMC::VehicleFormation tmp_tmp_tmp_msg_0_1_0;
    tmp_tmp_tmp_msg_0_1_0.lat = 0.17652969494;
    tmp_tmp_tmp_msg_0_1_0.lon = 0.771092044498;
    tmp_tmp_tmp_msg_0_1_0.z = 0.688411058331;
    tmp_tmp_tmp_msg_0_1_0.z_units = 170U;
    tmp_tmp_tmp_msg_0_1_0.speed = 0.355903082004;
    tmp_tmp_tmp_msg_0_1_0.speed_units = 23U;
    IMC::TrajectoryPoint tmp_tmp_tmp_tmp_msg_0_1_0_0;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.x = 0.582389086448;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.y = 0.66765206738;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.z = 0.830586041192;
    tmp_tmp_tmp_tmp_msg_0_1_0_0.t = 0.50033539488;
    tmp_tmp_tmp_msg_0_1_0.points.push_back(tmp_tmp_tmp_tmp_msg_0_1_0_0);
    IMC::VehicleFormationParticipant tmp_tmp_tmp_tmp_msg_0_1_0_1;
    tmp_tmp_tmp_tmp_msg_0_1_0_1.vid = 13547U;
    tmp_tmp_tmp_tmp_msg_0_1_0_1.off_x = 0.597348789494;
    tmp_tmp_tmp_tmp_msg_0_1_0_1.off_y = 0.0755511743803;
    tmp_tmp_tmp_tmp_msg_0_1_0_1.off_z = 0.0248721707659;
    tmp_tmp_tmp_msg_0_1_0.participants.push_back(tmp_tmp_tmp_tmp_msg_0_1_0_1);
    tmp_tmp_tmp_msg_0_1_0.start_time = 0.892155910102;
    tmp_tmp_tmp_msg_0_1_0.custom.assign("SMEGUDTKGHEAKMQDAJSRQRJFNCODGUKRRHCETAROZPXWTGFHSSVFOXHGGCVJPSEYCIYWNMZJCIIITSXBAKMPIEFLNLLOBPWIBQPNMQWQFZLYZLIOPNDFSAFTYDLBXWZDOXHDBXVJNTSVDRBWV");
    tmp_tmp_msg_0_1.data.set(tmp_tmp_tmp_msg_0_1_0);
    tmp_msg_0.maneuvers.push_back(tmp_tmp_msg_0_1);
    IMC::PlanTransition tmp_tmp_msg_0_2;
    tmp_tmp_msg_0_2.source_man.assign("KJDVGDKAQZCVJEJQWQKNKMHGWRBYJTTBTNIMCDFDZNYDFXTSDJWPCSCNHQJZCPGCKSPHOJRUAECSNILATDLPXFPIRVQATOGENQBWEQTIWRY");
    tmp_tmp_msg_0_2.dest_man.assign("HFVGUBQEEMUJUZVVIJMXQPOIBNSMHFCYEUPOEIGUIZADGQTRIPRYTGJDEDMQXBTY");
    tmp_tmp_msg_0_2.conditions.assign("UFQMSBZHUSPJZGSENQTXRIVUCPDCRHRHQAPLHWFXEKBNNGCXFYUOLWEDRBYUPCIGYQAKWZTORVMQPVTIGPAATTDAXCLXFCNMOGFKQWJDENEJLXJCJSWSKUOGQIYWYSJROPFIBMRJTMWYSZBLKAPRNEGFWANME");
    tmp_msg_0.transitions.push_back(tmp_tmp_msg_0_2);
    IMC::EmergencyControlState tmp_tmp_msg_0_3;
    tmp_tmp_msg_0_3.state = 1U;
    tmp_tmp_msg_0_3.plan_id.assign("EVUIJLYOFMDXKTNPTUXSTJDQYHIBHOZGG");
    tmp_tmp_msg_0_3.comm_level = 237U;
    tmp_msg_0.end_actions.push_back(tmp_tmp_msg_0_3);
    msg.arg.set(tmp_msg_0);
    msg.info.assign("UWNENRPBCIGXKDBMNMWJZSUODXUQFQKOQWZWTIVQNPPHIBCRCDGALMURGQKQLFJCYEXTEHDHJTXDLRICLPNAKWVSDUMRUR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDB #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDB msg;
    msg.setTimeStamp(0.370304140072);
    msg.setSource(20588U);
    msg.setSourceEntity(43U);
    msg.setDestination(2707U);
    msg.setDestinationEntity(130U);
    msg.type = 166U;
    msg.op = 224U;
    msg.request_id = 1309U;
    msg.plan_id.assign("PDGZQCUOXMLMAACQUMJIACWLYXNOBSTZQFTIRSEUEYKKVWUPZRIRDQUMPEKLTBQETWYWFGHFQRHZMQUZBVXLVZXSWXZTNVGPVCIWHJUYFVEAOIKVYYNHWHJSZPSIGFYMHLYXBGEVOBNNOSDHTJOZ");
    IMC::Goto tmp_msg_0;
    tmp_msg_0.timeout = 21632U;
    tmp_msg_0.lat = 0.46964533908;
    tmp_msg_0.lon = 0.269787866649;
    tmp_msg_0.z = 0.674478545097;
    tmp_msg_0.z_units = 211U;
    tmp_msg_0.speed = 0.843750253312;
    tmp_msg_0.speed_units = 25U;
    tmp_msg_0.roll = 0.565194713338;
    tmp_msg_0.pitch = 0.0486161893713;
    tmp_msg_0.yaw = 0.971673419138;
    tmp_msg_0.custom.assign("SXISYKAYCXIXYWKFCBWQPVLPIVJLKPUWMIQSBISDONVEZRDSMSBTBGHPCQTQEVHORAUOWXPEGRKAJFAJJMLHEALOTUWCANEKVZSXTTXFUFGYVHEMR");
    msg.arg.set(tmp_msg_0);
    msg.info.assign("OVPLOJJUDXUEOWDZPTAVXBMSHVMK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDB #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDB msg;
    msg.setTimeStamp(0.942721050169);
    msg.setSource(33458U);
    msg.setSourceEntity(132U);
    msg.setDestination(35333U);
    msg.setDestinationEntity(245U);
    msg.type = 232U;
    msg.op = 115U;
    msg.request_id = 13313U;
    msg.plan_id.assign("HEMYUAQMDYBNVXKLZSPDTFJSWIIMDFSSXZKHZGXVEEHUXSGBISMWVFRSLKBTRMERHUCDHAMZWWUISWNSJMEUULQFHCPCEDBYUHZEOZOPJCJGUQFPFDCTQAHQRPDFXPQXNDOARNZNZBXJSLECVTTTKGWYIIGXOKBHABMLCOEUKVLWFORJEWGTVZDMGBNINKOOCL");
    IMC::Sms tmp_msg_0;
    tmp_msg_0.number.assign("PWPMOXXKBGPIXZFBACOVGLWCTWSRYGHLCYGLZTRQRDLUHMVEPREWQYMYJIBLCQYAXOGRIZYUNULOSJLHNQEDCZHCIHUVSHKKPDGXWLDVSBAUPAIQNMJOTESBSHKKJUZQKNRVFSMMIDXUBCJIHNRZDWCFBVROXJFRSYIYFJQUKQMVBNQNFVTUVTEJKOFZGGYJWXXMX");
    tmp_msg_0.timeout = 16491U;
    tmp_msg_0.contents.assign("EEPBBKEAOQUOHW");
    msg.arg.set(tmp_msg_0);
    msg.info.assign("FYZEYGOVGPLIIHVHAMPBRMPRKQUBJCQDPQSKAXDSIZGQTCLMFUKYREXUMPNZGDANWBSXSCYOXUQZZYFVPCMDCTXTEWNEKRRZUEZRXGAASXLKTZTIHOPAENSBLQOTJVOKZNCDWYJQQSAOJCVXHHFMAIMBTJGUKDEQUNLLYRYUOHBDEIKENWGNWGKMODRCZWTBWIMSJFFOHJCNSJLVVHJPLSIF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDB #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBState msg;
    msg.setTimeStamp(0.650707809964);
    msg.setSource(44797U);
    msg.setSourceEntity(146U);
    msg.setDestination(36002U);
    msg.setDestinationEntity(126U);
    msg.plan_count = 56091U;
    msg.plan_size = 3677334432U;
    msg.change_time = 0.280813587282;
    msg.change_sid = 55309U;
    msg.change_sname.assign("RFGNAXFVHBMJSDOIQHLV");
    const char tmp_msg_0[] = {63, 9, -128, -45, -95, -48, -69, 97, 37, 56, 117, -72, -56, -26, 71, 106, 89, 122, -80, -73, 62, -115, -107, 36, -46, 32, 82, -24, 118, -45, 120, 123, -65, 112, -40, -66, 84, 30, -2, -106, 89, 121, 122, 85, -112, -45, -65, -21, 50, -17, 104, 35, 31, -16, 124, 80, -36, -56, -76, -103, -54, 118, -47, 57, -51, 77, 71, -98, -62, 87, 85};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));
    IMC::PlanDBInformation tmp_msg_1;
    tmp_msg_1.plan_id.assign("JCZHGYCJZZSVQYNSBWNFJQFMOOQYIRESRDMSPGDJZTPAFPNXDGALVLRXINRSTJESARSIKQGYPVMDQCRYGWOPOSQDBJTUMGKXZZXEHTHOUGYLWNBKOVPHJTZPLGGELUBBYRABWJVLUWWFOLIUXWWZYACWJTARUCPZTOTCYIVUVFBHCUADKKCMFIUJXWMCVB");
    tmp_msg_1.plan_size = 11347U;
    tmp_msg_1.change_time = 0.132382795597;
    tmp_msg_1.change_sid = 18242U;
    tmp_msg_1.change_sname.assign("UQXJEQLSOHKGDULJEDHKQTGNVCYRBEKYAQEGMKXPZCEDPGGJGKRFXHTYCREFICUTZUAZIXRUBPJWSMDBCAZYLXOPRBQHEAVFZBWMHLIBONQWSVUJNDRCAJCYQPDVLRRGPNIULMUWMBWLIMOARLPSVVKZXIBDTNWXAYMFAFFPVYVDKWIHILTHBBNNQPKQZXIJXTILSEUAOSWYOHMWMZAHQJFCEERGZVZGOMJGKYDSSTOFVNSNXTFDTTYJUOO");
    const char tmp_tmp_msg_1_0[] = {38, -43, 114, 57, 53, -17, -118, 117, -104, -69, 57, 61, -16, 73, -55, 74, -11, -22, -65, -6};
    tmp_msg_1.md5.assign(tmp_tmp_msg_1_0, tmp_tmp_msg_1_0 + sizeof(tmp_tmp_msg_1_0));
    msg.plans_info.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBState msg;
    msg.setTimeStamp(0.996173410211);
    msg.setSource(36348U);
    msg.setSourceEntity(205U);
    msg.setDestination(42048U);
    msg.setDestinationEntity(1U);
    msg.plan_count = 677U;
    msg.plan_size = 1298218808U;
    msg.change_time = 0.528954172688;
    msg.change_sid = 64587U;
    msg.change_sname.assign("VTBNUGMULTRNLJSMDYLMHPFEVMRUNVRSGJFGJTFLLDSSQMXAITGXJIXHPQPXIQUMPEEYIFYSXHNYZEYUSWOKLIHOPMUTZODMBAWXVEHMDOSLYFTAVNFWPVUJAADABBIKDZRAXKECFVGHNIYGVTXCJKKRFGJ");
    const char tmp_msg_0[] = {81, -37, -122, -39, -2, 126, -83, -55, 44, -62, 90, 120, -125, 84, 32, 40, 57, 52, -74, 25, 79, 27, 122, -71, 12, 120, 0, 60, -24, 93, -27, 24, -74, -73, -41, -2, 49, -94, 57, -46, 11, -119, 104, 125, -123, 45, 62, -43};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));
    IMC::PlanDBInformation tmp_msg_1;
    tmp_msg_1.plan_id.assign("IDMXSGFUEVOTCIHMBWMKNKNOOYTTVCDVEXPAMNQHBZEMDCPSHACYGCVLWIVHRGRUWJQHCTFLKORGFSCBEZYXYWBAWHNXZKPGZWUUAPWPLPKJQEREQBPYOQSWIUEDGOVBHRLELDAMBJMZWLDTFDZPAEKRSJVFFZQESPSXIKJGZQTAFUNTQPGKXVYYUBCFLJIYUJJHSJRMQBRDFZKTHNBNMALOCCRNXTYQIASRKJXZNFLHYOLSUNVVOD");
    tmp_msg_1.plan_size = 6006U;
    tmp_msg_1.change_time = 0.848182581252;
    tmp_msg_1.change_sid = 15910U;
    tmp_msg_1.change_sname.assign("JWWNTTANADTPFZGEHPVWKSGEMMFQPNWICCIAMSSYWXRGUEQAMUOICSDJHXQWVITFLVBKLPJHITBZTRFHOMUPTGESDOZUIFESJHVCLYEHBKQVGZRCHQCIQUZUBYNZWXETOBPMRJLFRGPSDUAOKOBXKSILKZBLBVFFSMJNKXOJFQKPARAVCHVL");
    const char tmp_tmp_msg_1_0[] = {111, -8, 5, -100, -75, -17, 11, -21, -12, -54, -9, 10, 80, -34, 27, 32, -8, -126, -48, -26, 121, -42, 8, 86, -61, -86, -40, 115, -22, 7, -116, 50, -5, -125, 118, 113, 44, 80, 46, 74, -128, -113, -87, -22, 110, -51, 80, 7, -121, -27, -21, -77, 46, 58, 55, -82, -17, -109, 96, -2, -43, 31, -120, 59, 12, -106, 86, 77, 35, 107, -58, -105, -122, 107, -58, 20, 62, 96, -97, 57, -10, 21, -30, 35, 101, 5, -10, -10, -40, -89, 107, -29, 69, -76, -11, 50, 110, -76, -31, -60, -34, -1, 6, 0, -26, -33, 88, 14, -69, -80, 85, -7, -12, -1, -43, 37, -63, 51, -101, 52, 12, -101, -64, 76, 6, -45, 40, -56, 10, 2, 29, 24, -128, 99, -27, -19, 43, 63, 46, 30, -75, -49, -113, 100, 118, 77, 72, -66, -104, -49, -54, -85, -36, 115, -56, 81, 86, 104, -45, 0, -109, -103, 101, -118, -45, 31, 96, 19, 13, -111, -100, 97, -116, -16, 114, -46, 117, 4, 117, -14, 116, 13, 79, -80, 112, 7, -115, -52, 101, -117, -54, 87, -12, 115, 112, 84, 121, 51, 17, 2, -53, 96, 29, 39, -125, 9, 86, 85, 71, -125, -97, -11, -2, 50, -37, -128, -71, 6, -62, -2, -9, 46, 111, 30, -37, -69, 87, 62, -104, -6, 105, 95, 87, 4, -93, 65, -30, 86, -79, 123, -128, -83, 85};
    tmp_msg_1.md5.assign(tmp_tmp_msg_1_0, tmp_tmp_msg_1_0 + sizeof(tmp_tmp_msg_1_0));
    msg.plans_info.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBState msg;
    msg.setTimeStamp(0.315597226666);
    msg.setSource(7690U);
    msg.setSourceEntity(108U);
    msg.setDestination(33760U);
    msg.setDestinationEntity(66U);
    msg.plan_count = 54053U;
    msg.plan_size = 552107969U;
    msg.change_time = 0.716072154913;
    msg.change_sid = 56764U;
    msg.change_sname.assign("IHRFBGYNOVUEPVIIVDBYDMNYRMVJMWONELYIBXBCSGTZFCRLYKBIQCPODURKOWNBSXISOQCJAXPDLPWVBHEOWJHGTZQXAZUCUHORJQISUHQFCQGTSDBYAWGFFKNZEWYTEUHWVJSRDAAOTLGJESRLGLCVTJJVOXTBDHXHEZDGDLAYKNEEXPMPQAXFRKVYMD");
    const char tmp_msg_0[] = {-14, -13, 30, 117, -78, -113, -105, -6, 14, -44, -6, -42, 111, -2, 90, 119, 52, 29, -54, -76, -3, 98, 95, 103, 47, 65, -34, -43};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));
    IMC::PlanDBInformation tmp_msg_1;
    tmp_msg_1.plan_id.assign("WWYFSULVLRHBSFXUJBBXBPJDNSFGLHZSVFMJYOFQTIWTSWVTOGLBGKDEVDPRTBAQPNJHRJGVHXTJDYDCTKHWBKSVNHOUKGNELIPMJOFREBZDZRUWEODZEZEQEETAWRUCGOHCTGNPGUKXYUCAEIXNUSKIRQZCFSJQYLCOEQTUPLCDCIBQCDAVNAVMBNGPWIFAZKSPFHXXRAPYIYMMIXLOLGXMQONPQJDXHKYVJHQIAWYSRAMR");
    tmp_msg_1.plan_size = 20201U;
    tmp_msg_1.change_time = 0.565614344154;
    tmp_msg_1.change_sid = 30708U;
    tmp_msg_1.change_sname.assign("KCVXFTSKWBUJLEZRFFOHPYIGFDMQAQKUFSDBAIOJBENECFLANAXYJLZAGZGLPLGPONNQEIYTYWSYVCLKRFMHHUJXMZHMEWWKQXHTUXVXWJKHIDVKPGXVCPMARURZFRVBHUPFWSKTEQDUKXWKTONYZAVNDYEHJNAPQWVFRTEYPMBIXWGBRUVNCLODQEHRSULXWQCZCOYAJYIPTQJSJBCJBOZHGISINTIDRBACGVEDUNTQLMGOMLDP");
    const char tmp_tmp_msg_1_0[] = {61, -98, -118, 110, -50, -79, 19, -98, 102, 73, 89, 7, 109, -17, 101, 3, 36, 80, 47, -42, -98, 39, -101, -7, -18, 93, -89, -120, -51, 103, -70, -33, -5, -122, 81, -11, -27, 62, -84, 110, -59, 49, -45, -65, 111, 71, 32, -4, 55, -24, -110, 114, 107, 125, 59, -3, -25, -117, 76, -14, 15, -19, 84, 108, -88, -124, 64, -58, -126, 42, -31, -41, -12, -108, -111, 52, 86, -64, -14, 54, 115, 47, 123, 108, -15, 83, 107, -34, 52, -120, 17, -8, -35, 3, 79, 109, -85, 52, 22, 101, 107, 115, 19, 58, -59, 36, 11, 37, -10, -93, 58, 76, 36, -20, 104, 45, -47, -128, -29, -2, 97, -62};
    tmp_msg_1.md5.assign(tmp_tmp_msg_1_0, tmp_tmp_msg_1_0 + sizeof(tmp_tmp_msg_1_0));
    msg.plans_info.push_back(tmp_msg_1);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBInformation msg;
    msg.setTimeStamp(0.751993440834);
    msg.setSource(25473U);
    msg.setSourceEntity(139U);
    msg.setDestination(44226U);
    msg.setDestinationEntity(226U);
    msg.plan_id.assign("ONYVHUIVNPHJHBODWKGCKTXCHMMKQCUPQUWXSPSAGIWEJMMQYCGZXBWFWODVADYNQFDTPLTLCRKVLFHMRSVXFWMJVQEZCMYDDPOXJPUVYKNNTBJTVGNMRJLCKHZ");
    msg.plan_size = 34554U;
    msg.change_time = 0.823707144617;
    msg.change_sid = 24907U;
    msg.change_sname.assign("JBWCZWJQVBSCYBXADNTCLUDMFISHLXPGZKDNIBSYYDMGGNPKBJMLGXULTIJXVIXTRFKWVZRWDRSZAJYVOQODGGFHHPXNVCXFUXBYXOTRHGZWTVWKMHBULUJKMR");
    const char tmp_msg_0[] = {54, 73, -51, 115, 115, 122, -114, 45, -84, -33, -69, 62, 41, 47, -55, -64};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBInformation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBInformation msg;
    msg.setTimeStamp(0.968135639436);
    msg.setSource(38727U);
    msg.setSourceEntity(69U);
    msg.setDestination(29835U);
    msg.setDestinationEntity(47U);
    msg.plan_id.assign("EBPFECKGFLSHPEHOVOTRTSRMIXEJIDXCRYPVSODSIXDHIWONRDZCWPLXNLYABKYQMCITWQPWYUBVBKJAJUULVNKAVSGWIGUTVMMFTATPQKLZCENKFNVQFYSBUSQHZJMDMRYFOYCHBZOLDZUJPFBGEXYMJGANGHISAAEVXXQLCFZWAWIVKRTHPUJXBHCRTEILOAGGAWDS");
    msg.plan_size = 36517U;
    msg.change_time = 0.246613543172;
    msg.change_sid = 8752U;
    msg.change_sname.assign("RYSFIFMNSBECBQDLWRMYPSRAOLUCJLLIEFFRKWHVMVLSZKDVHCLXTWKODPMRDDFHCRMDRMKKBNAGULJOUIBTXPWOYGCNITHXYIIGWALGECTPBQVPXCZGXUGHKJVXPJKGCRHYZTURDA");
    const char tmp_msg_0[] = {-46, 89, -49, 37, 3, 3, -115, 121, 20, -52, -125, 18, 48, 73, -5, 3, 10, -77, 37, 22, 119, -106, 53, -94, 89, -101, 101, 61, -114, -92, -114, 97, -79, -1, 117, 101, 15, 125, -92, 10, 35, -37, -33, 1, 49, 76, -48, 41, -76, 7, -120, 59, 109, 49, -127, 67, 104, 3, 79, -78, -126, -90, 37, -65, 22, -81, 121, -42, -65, -66, -126, 115, -123, 64, 55, -75, -39, -67, 46, -45, -70, -66, 83, 65, -24, -116, 31, -22, 74, 47, -57, 99, 46, -5, 26, 100, 120, -85, -40, 125, -5, -105, 111, 66, -9, 109, -36, 84, -61, 36, -36, -105, -66, 16, 83, 8, -48, 10, 37, -83, -9, -122, 64, -80, -32, 46, -119, 123, 116, -80, -36, 24, 8};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBInformation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanDBInformation msg;
    msg.setTimeStamp(0.398847424722);
    msg.setSource(22765U);
    msg.setSourceEntity(58U);
    msg.setDestination(60765U);
    msg.setDestinationEntity(70U);
    msg.plan_id.assign("MWQHPJYYZBMXYHLOGUDTJRSKRNSXJLZTMLHYPIBUJIFVOUYKXWIAMGTLZLAWLWCIZKFDVVHAATNEBRK");
    msg.plan_size = 38543U;
    msg.change_time = 0.173399678464;
    msg.change_sid = 64980U;
    msg.change_sname.assign("FCFZOJZKWNVYREAWKFXEDWYTFQMUOGMIAWBJHLUOXNFPOYCDNBUMHTLJRUXGYWGSARJJGURMFATYTCPPRPNKZHQGIHTXXIKZDGPQQ");
    const char tmp_msg_0[] = {-128, -42, -34, 26, -91, -44, 3, -55, -121, -61, -11, 27, 44, -72, -117, 82, -125, -22, -59, -67, 88, -57, 29, 13, 2, 20, 121, 97, -85, 16, -22, 96, 37, -85, 42, -83, 28, 10, -48, 61, -35, -105, -96, 60, 58, -30, 85, -76, -22, -90, -103, -25, -81, -81, -68, 120, -76, -66, 21, -13, -1, 1, 55, -116, 121, -108, -117, 117, -67, -15, 107, 55, 115, 58, 14, 66, -44, 102, 36, -36, -4, -51, -84, -38, 43, -15, 117, -39, 75, -48, -8, 35, -70, 37, -71, -64, 70, 96, 69, 67, -72, -17, -14, -51, -5, 83, 13, 106, 122, 54, -8, 74, -87, -88, 16, -125, -125, -126, -47, 61, 124, 60, -88, 32, -28, -29, -3, -104, 17, -34, 74, -27, 22, 120, -121, 75, -30, 123, -85, 105, 115, -92, 38, 39, -34, 105, -72, -121, -58, 93, -90, -45, 86, -84, 8, -62, -11, -58, -30, 35, 45, 78, 106, 110, 116, 87, -4, -21, 67, -125, 110, -13, -55, -61, 104, -118, -7, 103, 30, 95, -2, -50, -64, 55, 68, 47, -85, 82, -86, -128, 107, 104, -60, 36, 44};
    msg.md5.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanDBInformation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControl msg;
    msg.setTimeStamp(0.988939273435);
    msg.setSource(330U);
    msg.setSourceEntity(42U);
    msg.setDestination(31824U);
    msg.setDestinationEntity(197U);
    msg.type = 250U;
    msg.op = 158U;
    msg.request_id = 26340U;
    msg.plan_id.assign("FMIAYSCDOQYOYWNQDHQIQPCBJDTWCEEHACU");
    msg.flags = 59306U;
    IMC::QueryEntityParameters tmp_msg_0;
    tmp_msg_0.name.assign("DQCVRVZWSASVJBJRKIESMNJWVACMGWOZYIX");
    tmp_msg_0.visibility.assign("MGSLPLMAFHTADOJGUZCAH");
    tmp_msg_0.scope.assign("UIAKRFZKWZWXFMEFNXAVRHIBESKQVGUQPNBYZCRGVCSDAINHCUUWPLRAOTGCOWIFRMGQINFYYHTAMDQWVKHEASAMJMUJTTMNRJGVLJXDVOPSXEMSXCDLSLAECYKWZZFBFBOPBZGWHURJHYVWLLXPJQIFNKDNDBERPTQOSMPMTBOH");
    msg.arg.set(tmp_msg_0);
    msg.info.assign("MZNOUYRTVRLEIAQSVOQDJEPKMPTYXLMWDATHSXYZBOUNXJIGGTIHBUFIQFHGEODVQCZKMBAQEDQKNZLJFIDSCPPSKIIXXUOQNFRSNVOBJDCUCVPFTAIQOLLXRAPIHBBST");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControl #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControl msg;
    msg.setTimeStamp(0.761660470085);
    msg.setSource(16952U);
    msg.setSourceEntity(180U);
    msg.setDestination(62937U);
    msg.setDestinationEntity(145U);
    msg.type = 19U;
    msg.op = 45U;
    msg.request_id = 21841U;
    msg.plan_id.assign("CWQPBGNRHVVWOLIWSIAOQDODUKXQDCWHCBTLFWZXJTVSPKEGLXHLOJBCVNRBUEKXZZSPMEACTBMNLATFGTIYTDULHTMBTYB");
    msg.flags = 12876U;
    IMC::NavigationReset tmp_msg_0;
    msg.arg.set(tmp_msg_0);
    msg.info.assign("ATIDTRPABBDJNZQUMZHXZOJMYKJZEONGNDGMWHPDDQHBQMUMGFGWPHYBTSYNLVESLOXIYRGLQYKPYWECOCSRIN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControl #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControl msg;
    msg.setTimeStamp(0.456199767646);
    msg.setSource(43822U);
    msg.setSourceEntity(253U);
    msg.setDestination(35230U);
    msg.setDestinationEntity(198U);
    msg.type = 77U;
    msg.op = 71U;
    msg.request_id = 14983U;
    msg.plan_id.assign("OLWJVBODTHYTSKQJUQDKOKFATBYRKUQEYSCXLSMAPTVHOTERSKPFAOCHMPEBUGUFHWAXYTLYMVMQESFWIFTJFCFLUGCXUPVJMPOYNFKQEEWGOXAGWUAOIWNADEXCMXGLSJIJDRVHVCLMSQAZLIBGTNLRCWHNEUZDKZBIHR");
    msg.flags = 65142U;
    IMC::FollowTrajectory tmp_msg_0;
    tmp_msg_0.timeout = 20649U;
    tmp_msg_0.lat = 0.0536797406122;
    tmp_msg_0.lon = 0.1121298616;
    tmp_msg_0.z = 0.664406131476;
    tmp_msg_0.z_units = 212U;
    tmp_msg_0.speed = 0.360410399158;
    tmp_msg_0.speed_units = 37U;
    tmp_msg_0.custom.assign("RXQAINBGGLLQJJVTZLYVWLLBPWXFLFFXTEEQJWJWPUSDNCDUPEISGYHKEMGIDITJQDOSFCSNOTVWHCGNLMTIVHYPCDZUYMXXJCYNZVMHANRTDJMEDKKRNCGAHCOBFOYTMBSIEMLSDATX");
    msg.arg.set(tmp_msg_0);
    msg.info.assign("LIRQQLAEKPHMNIWLJITEFWVZSRGNLTXMUYJAYCDTZBTABMY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControl #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControlState msg;
    msg.setTimeStamp(0.499549465298);
    msg.setSource(2749U);
    msg.setSourceEntity(226U);
    msg.setDestination(31483U);
    msg.setDestinationEntity(159U);
    msg.state = 29U;
    msg.plan_id.assign("JXJTGTXUMORULYDCVUXVADMBBEIRPNDOSRSAGPTESPMGZDQRYBOUSONMMKCWUKEMSHSAFLCIVTHSWLJNUCDWEJHIFPFAYVOQXQWDIQGCZVYFBQVKAEXOKD");
    msg.plan_eta = 1606468438;
    msg.plan_progress = 0.612549281583;
    msg.man_id.assign("OBRACSJUIZTLNTJULUTPTIWERVNHRAZUTSRXIYIGAYKVOHDZNCHWVXKCVLMDQBZLWYZJQAKEFJNXPHDLEWGWTBSPHDMSOLHUWLAFXRPJNAFEXSRKBFGUOKMCNNHKKMNBFZIIHDOWPFCXWUYRABRICQWFAGSVJGUSQOAHGEMQROCPFTDEYKAYSZOYYDJIIJDTRUMBPTLBOCONQPVMKVJSXGDXCKMIZVLJYGELFVGQBEZEPY");
    msg.man_type = 36819U;
    msg.man_eta = 1120297521;
    msg.last_outcome = 171U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControlState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControlState msg;
    msg.setTimeStamp(0.892919668013);
    msg.setSource(37134U);
    msg.setSourceEntity(144U);
    msg.setDestination(12546U);
    msg.setDestinationEntity(225U);
    msg.state = 113U;
    msg.plan_id.assign("EQNNMGCXDCQUSARURDWCSWMSBXJJZQXBTWZPSCVSYJRTMHKPGOSQNJHJDBGIRLVIIMEOHBHVAKFCTGWAZBBRNOAUFTJZNAHKEAQYXE");
    msg.plan_eta = 1675743813;
    msg.plan_progress = 0.927410225556;
    msg.man_id.assign("BKNQQTHJDQLWIHMGFVLVRKFZCAFNVEGLXGXFKCELOVWPDEIFKDYDPSWMXOXLOUNSGYBLDXDEWDEAAQSSYDPIVGMITRUTJTLIITHBUXICJMOWWHAP");
    msg.man_type = 52085U;
    msg.man_eta = -483900622;
    msg.last_outcome = 250U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControlState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanControlState msg;
    msg.setTimeStamp(0.255379405072);
    msg.setSource(38190U);
    msg.setSourceEntity(197U);
    msg.setDestination(2704U);
    msg.setDestinationEntity(53U);
    msg.state = 130U;
    msg.plan_id.assign("BTBQVBCQPWGSXITTERZJCNXJIFVFNUEUWMDULYILNNAXHWRGWFFLJMGPJQLNUZFGHHCNJZFNKYWCKTYAKPVIUIYQSBARBYRFCTNIBSQEYLSAVCRSFIBWPZEMPHTHMNMVKGDNOSLYBMKAXZOCLTKQUVOOJAGEDJITUXWBAPZKQDYPKMZTLGZOOSVDUTOJPHVGMOXQ");
    msg.plan_eta = 1009627717;
    msg.plan_progress = 0.202776144184;
    msg.man_id.assign("MHBAWYRWKRJXXQTFIKQWBSAGFIAQEHCTBVADRYQNSVJKEFDDLMOVZVPRNRVELLGRHZGTCZTZOYDUTYVHFKOJCPJGNWPOUIHSVQFTOYBCENGDZUXCBYUMCSQSUHBFAQAPQDUOBYTFDSPLAXPMHOWFGFSNGEQLNJTYLXRNFEMXYGKDEOPASRRDJPNYSEZJJBWMUUELDCHCATWXWTUBKCMINKGZJWVHOVNXGBIMKIZPPK");
    msg.man_type = 6448U;
    msg.man_eta = -2089319055;
    msg.last_outcome = 153U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanControlState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanVariable msg;
    msg.setTimeStamp(0.365592853145);
    msg.setSource(49909U);
    msg.setSourceEntity(12U);
    msg.setDestination(34347U);
    msg.setDestinationEntity(130U);
    msg.name.assign("UMIFDRHKRAGDGHMQMJTA");
    msg.value.assign("KWNMNCWGNXJGYFFGBJRCHPLXXVBDLLORYKPQSRDAFATLTCROZJCENYXFZRIQRUHMWSYKRLVAHAETAXVRKHLUQCMHIOGZGIIVWNMMUILCGLYOAFYFQFNVEQV");
    msg.type = 66U;
    msg.access = 167U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanVariable #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanVariable msg;
    msg.setTimeStamp(0.653644987836);
    msg.setSource(43026U);
    msg.setSourceEntity(100U);
    msg.setDestination(60708U);
    msg.setDestinationEntity(233U);
    msg.name.assign("PJSSEYYLBUAFLERPUWTNQKDNRBRLHPDUKCPSZQEXBLZECWANPFDOJGIJXIWDVYTABLCCWJGCKTACIUDWFZOSNIKUYHUDNVOYXJHJCGRWKATXNXYVQHXHATIVJWPQVRKMISZUMIQZYLMFTPNGNRSBGUBMLF");
    msg.value.assign("EVTRNJGDSISASPCBSYUMDGMCMDMYBQAEZRBJEVHGHNEQALAMNULINAQWIPZMENYOYXWGLISIUQXBBHXTQYLKVVBBXRONVCABRTXQHASKLFFVNPFHSVDLOATPUXUFHDBEWNRIEJCQKVKMQCMGCJGKZULMPRZOWAYKSEUGFPYPHWWGOKFDULHTZGCESJRXD");
    msg.type = 227U;
    msg.access = 156U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanVariable #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanVariable msg;
    msg.setTimeStamp(0.336251656586);
    msg.setSource(34639U);
    msg.setSourceEntity(166U);
    msg.setDestination(5282U);
    msg.setDestinationEntity(120U);
    msg.name.assign("IXBBHXJJBDFARQODAIXSCCNUPJKDWKFFPEUIMQDWYXWSFYNGEGBKVECPXWHSV");
    msg.value.assign("DQPKOHESVDQWOMMXOZXJEYBIJJRYOFVPALLMDMYMDIBFUBIQJSTQRFGFAKRCXKPBGTEBBCULPTZLKOWAIWZGZEHQWXZ");
    msg.type = 202U;
    msg.access = 135U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanVariable #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanGeneration msg;
    msg.setTimeStamp(0.305702615815);
    msg.setSource(21296U);
    msg.setSourceEntity(124U);
    msg.setDestination(6871U);
    msg.setDestinationEntity(43U);
    msg.cmd = 198U;
    msg.op = 109U;
    msg.plan_id.assign("JGVEPBMSOROWRANJQABRGXFWFMKNVUJPLUPAMAYOBSXWKZVHCVHGCXYSAQEPIQQNJOXEGVDPKLTNKSDYPTFBMPIDGDCOFUVUWHWIGLLSMHFGLUIBTLHEJGZEFTEODCBXRGZAWOQAWVVYCLIMERJACXZNIBYHDSIBPAMAJRKTRJCYBDZPOITEXFNHVZQUEPEODJTMZQFWFLNUU");
    msg.params.assign("FAZYJGWLBGYPWRGOCOICFVORXEWKSCAFZSULCIDZRRHICHTTZBUJPXEAUTQQMPNMANHZNTLSCMMBQNBLCEAMFYDMPYNDBIYWVINEOCYVEGJYELRZLVVJWHJWGPYZMPNKTQZGNJLRNSVOUKUHQPFXODFLWJWCOTEVXOZHBVXGTNKISDAFCGWPSVEUXUBAUBYQKFOUXSXMB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanGeneration #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanGeneration msg;
    msg.setTimeStamp(0.493769312551);
    msg.setSource(22829U);
    msg.setSourceEntity(128U);
    msg.setDestination(22432U);
    msg.setDestinationEntity(191U);
    msg.cmd = 211U;
    msg.op = 81U;
    msg.plan_id.assign("XRIJCAMRKBEUIUFUPQIDPSXOQCFOZHMGBFLVFRKSYGJDTDNAFSOJTQTSVLQPRDZUDFJXAMBNHIGSMWJHVYWYLJBKNSCDZOCKQNDAGZRZFCACNQXWYUAOPYBWROUMIEFHNLPGUEAGTTIXEXWHQNIYBVLYUXXIRGHQMDPETMLNEYWKCNRUSFELLWZOOGVCVYKXQPSBQZYWZDGKTJLARDGMPKHBHVCNVTWLBUXEZMJZFVVJOJ");
    msg.params.assign("HOVKDFUGXYKHKJJIMBIZSFWVLGFCDXFBQYBXITYRTECNAAWZNUXYJEECXJUEOJVLAKUWWRKQMNVAKYPIVQPRSRBATRPFINFIFPDXJDKZMXKWZZPGV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanGeneration #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PlanGeneration msg;
    msg.setTimeStamp(0.196247942945);
    msg.setSource(42597U);
    msg.setSourceEntity(77U);
    msg.setDestination(60084U);
    msg.setDestinationEntity(178U);
    msg.cmd = 58U;
    msg.op = 200U;
    msg.plan_id.assign("HCTLPMMQTRSSAEKKQHFYKEXSSWEMJVKSAIESYDLOEUQQOWHUIZBIETLVNIPXQZGFTAYVAGZICMWYBBZDCBSHCKVGJQBHOXDRBUTAJMUKFDGVIXPHOGFGMFUTZPUOIMFVSQZINUUBXTWABSRODXYXRZCDPLDNNLPNVYOLJHIEYCGKRXZJELABPDEWTPTSJAWWPH");
    msg.params.assign("EWOBCZJKZKNTCMGMGCRHDFHEDJGIWENKMOWMBGHHVHFTODLRAVVTLSOXRNSUOINEBHCUPEMVFNWDKJAWBTJVZK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PlanGeneration #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportedState msg;
    msg.setTimeStamp(0.972482186137);
    msg.setSource(36665U);
    msg.setSourceEntity(128U);
    msg.setDestination(3449U);
    msg.setDestinationEntity(181U);
    msg.lat = 0.322717268341;
    msg.lon = 0.485754973436;
    msg.depth = 0.850372400478;
    msg.roll = 0.215685716566;
    msg.pitch = 0.561478987924;
    msg.yaw = 0.321362725988;
    msg.rcp_time = 0.223505650237;
    msg.sid.assign("WOKNWAFDCDWASBIYZZKHJBNPADPVTJAFIHBNXQIJRMEPGMDDXBQATBHPJLBEOSSKFYPODSBFKWCVNDZTRQPZUCVZUYGFUQMLTTRRRAEVHXIGUGZNGDVCMMOYVHOKCJYFYRKQINCALMTKOQHUOEWYTNCKACIGXPBQVNNFJLSWDPHSIZMYKZZMFRILOCLEJYJPTQQESWXMXBOOMGKQCVIFUGVSZHEUULGLLLTXWSVERSRX");
    msg.s_type = 197U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportedState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportedState msg;
    msg.setTimeStamp(0.780361072833);
    msg.setSource(50160U);
    msg.setSourceEntity(204U);
    msg.setDestination(41220U);
    msg.setDestinationEntity(207U);
    msg.lat = 0.478761102018;
    msg.lon = 0.720325042428;
    msg.depth = 0.370017279621;
    msg.roll = 0.650239450974;
    msg.pitch = 0.628160074783;
    msg.yaw = 0.60236543795;
    msg.rcp_time = 0.85376675831;
    msg.sid.assign("UWGYKGZWHDFTBUPTYLIHUOOSSKNDXWOTEZRJSKZQJARMFACEGFIOBFHMELIBHEGHEFISTEXVTGBHIAAMPXCCRUEWCMWNYSYLAUKUJBTACYSYXXDNPFUESKEZNWVNMKBGEJDIQAQSIKPFHKXWZLB");
    msg.s_type = 17U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportedState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ReportedState msg;
    msg.setTimeStamp(0.167935101454);
    msg.setSource(16480U);
    msg.setSourceEntity(237U);
    msg.setDestination(27745U);
    msg.setDestinationEntity(148U);
    msg.lat = 0.649830553124;
    msg.lon = 0.29402185865;
    msg.depth = 0.884558607436;
    msg.roll = 0.622774112932;
    msg.pitch = 0.303486300463;
    msg.yaw = 0.616653473489;
    msg.rcp_time = 0.164205804907;
    msg.sid.assign("YGMOWEINOPNVGOAYCNLPYKCBSOVZJJSESPRSCWKZTFNPCCANSXDLGNVFTBJTKRFAZMXIETCFEATIHQBMQUHTTUNNNSDXYKRRPWGJJHEXKZGAULYZDFBWVSRLTWUOSOQBCIZMBOLLMYZUDOYIYUAGKEVPKPPVBHALRSUHXVWBRD");
    msg.s_type = 37U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ReportedState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteSensorInfo msg;
    msg.setTimeStamp(0.999504107538);
    msg.setSource(30577U);
    msg.setSourceEntity(118U);
    msg.setDestination(54852U);
    msg.setDestinationEntity(46U);
    msg.id.assign("CTKXPXGQWAWJRBYZJQDSVVXKVAEMCZJHJODWIUWELXPOFRYTYWEMVXUFNKDCVAGSEPVDSHRRVHRIPBQAFIOLPIMHSTPFDMFHGEIUETEAXQIYNSCJBGBWZTLKMYKKYBOTOJGQVTNZGCHELWAHICZSNZRLYMARBLXOBNANWFOIOAXQMFPJUWPFQCNDRBKCTHDXULHJGROHSBUKNVLSDPFXEJENBLNKYZZQUCMDCGRZJ");
    msg.sensor_class.assign("DWSFXUDQVWMMZORAKEGHGQWMOEXJIKPENEGSPJVCOASKTUNZKGXSGAULAHELWHSFKXHVLUGTLCZDUZAHRQLNIOMOWHXMYZNUTEWIRRBUOMUQWQIYWBTZRYSPNFNJIPBMBQIPHKKVVBYVNJYYCPDMHALEFKNEXMYJRUCPEOCSROYIAOAWFDGZQYFCDLJRDXCZFRDEBATJGKBHFPNYGBRSDICJVXC");
    msg.lat = 0.902129784825;
    msg.lon = 0.454197462796;
    msg.alt = 0.178928136722;
    msg.heading = 0.964420677935;
    msg.data.assign("XXEYOEVEZZRFQFQAUXBKBZYEBWOYCSXU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteSensorInfo #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteSensorInfo msg;
    msg.setTimeStamp(0.430315956068);
    msg.setSource(54308U);
    msg.setSourceEntity(10U);
    msg.setDestination(53145U);
    msg.setDestinationEntity(76U);
    msg.id.assign("XWPMIGDVFHCF");
    msg.sensor_class.assign("YBHOGANPWID");
    msg.lat = 0.899905274059;
    msg.lon = 0.876705642442;
    msg.alt = 0.248776062072;
    msg.heading = 0.442339384751;
    msg.data.assign("OHKPQBZQQYKMXPMRACVGTKZJZNRMJDATIHKPXTDZXLTOWJCOFBQFSAZSARNUXDPWWJZVEYMANHUVGSKJTQGEFBOFSPCDNYPANSUWNBXFDJBTCEJHUHYEEHIGUPTDJTVKXQBWHBBR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteSensorInfo #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteSensorInfo msg;
    msg.setTimeStamp(0.103452518428);
    msg.setSource(51020U);
    msg.setSourceEntity(100U);
    msg.setDestination(54485U);
    msg.setDestinationEntity(171U);
    msg.id.assign("HKVIEFYIIIWMLOHPKDKZVBBZHNZMSHUDIXWGC");
    msg.sensor_class.assign("YQJDUOFJTJAQQOADRXJAGAKFRYVZBXWAETTFQNOKKVDTPZMVSNVBQIIZGCRPWIWJBJEXNVRFPHHUWDUOHZMCKILEBHWOQFXUVYAPBZFMEUGLYWOCXEZPSVBEFGRZVQHILNWSGUZLCLEJKCKKJHQCCXGTYDKRLGMUVIAXPLDPXNWIHNQSSULFGDOSRUEWSSSBKCBACGYAOEOPTSKTTHTPPIOBZNXM");
    msg.lat = 0.61474407974;
    msg.lon = 0.37013012602;
    msg.alt = 0.219313864572;
    msg.heading = 0.775390527555;
    msg.data.assign("PQIIMGVXHWCFTELGNYMOLGOQAARAHUCDKDFKLBZDTTFELNQAHLQBUXZVCKLYNRUWUVQZSISKRGNJNIBLGBUATPXWDVKOJGXUVWWYFYQHQZKLJQYDRTIJGMJYOENAEUVBPNSDHFZZVNCTTDWTPXPYWZOWHYVBHSKBEXICTHZEGALHDFUPWWOPDVFRYBOKQYHSXIBFCZTXSXRJCMIEAEPRUMQIMJMSMCEPROUAIGSJKECFPXLZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteSensorInfo #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Map msg;
    msg.setTimeStamp(0.765681496747);
    msg.setSource(28491U);
    msg.setSourceEntity(169U);
    msg.setDestination(12701U);
    msg.setDestinationEntity(180U);
    msg.id.assign("WDORVLMNCYXGIFHUXUKKUYTLZPFBCEYADEDWRM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Map #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Map msg;
    msg.setTimeStamp(0.693271035841);
    msg.setSource(9649U);
    msg.setSourceEntity(28U);
    msg.setDestination(22831U);
    msg.setDestinationEntity(25U);
    msg.id.assign("RKYTDIKAEAXNUQHHZDOQCQRPBABPXIQEGDOQGVPUCUYZJJGOVKWYICSTKBOZSKLWGXSOTCJVJFUVDXUFWPPXUAMDTNZLRREXOWXLDYEJIUVBFLESYYMFBVZXMWIBYRHGEPZCJYZOAHSAFAKEJEWSMLCHNNDTITSFHEMPDGBMVNNYPHNNVWGMIHZNPSKGOLXK");
    IMC::MapFeature tmp_msg_0;
    tmp_msg_0.id.assign("PQXJTTIBSGXPMBNCNESQOPWUVFGINTDYVQWHXKWKICZHLQOPUIXNEXVEDAEAQLKDWOJWTUEJ");
    tmp_msg_0.feature_type = 249U;
    tmp_msg_0.rgb_red = 196U;
    tmp_msg_0.rgb_green = 46U;
    tmp_msg_0.rgb_blue = 17U;
    msg.features.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Map #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Map msg;
    msg.setTimeStamp(0.595161869974);
    msg.setSource(62579U);
    msg.setSourceEntity(174U);
    msg.setDestination(12591U);
    msg.setDestinationEntity(76U);
    msg.id.assign("AIFMXUYRVSSCWXMQIARDGWDNFFFNZLFLPTQEIKOXKJBVOGYJHHLBWEEBDLJETWZDKSYRXPSDUZYILZZGADOUAPSVHBMRASHBRNOJPMBGDPQWGVSCZMCUBAOAZTDCFQYBLBFIXJWSCKLTMKZNJPEQAETRCCHBUJNRAHPCXVKSQTVIGWCHRLAQRGUXGNLKVKDMYYHVIWOPUWMGOYUFIRMYZMIEINTQ");
    IMC::MapFeature tmp_msg_0;
    tmp_msg_0.id.assign("NKFEJWTCBIERELPKZKASUNGJUZJCCSPMPPMSWTMYCCKTMPHLJTTPPSGKSXUNTJGRBRFSJNRXYLVXRFWWBALFGKYQDOCOHUSOVDWGNXRMFYBXQJOHBVPIXRTOUDHYOWLKPACYWGYCDTEE");
    tmp_msg_0.feature_type = 99U;
    tmp_msg_0.rgb_red = 208U;
    tmp_msg_0.rgb_green = 31U;
    tmp_msg_0.rgb_blue = 110U;
    IMC::MapPoint tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.lat = 0.441674611341;
    tmp_tmp_msg_0_0.lon = 0.340095232752;
    tmp_tmp_msg_0_0.alt = 0.382100438958;
    tmp_msg_0.feature.push_back(tmp_tmp_msg_0_0);
    msg.features.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Map #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapFeature msg;
    msg.setTimeStamp(0.376892595516);
    msg.setSource(53628U);
    msg.setSourceEntity(145U);
    msg.setDestination(32003U);
    msg.setDestinationEntity(133U);
    msg.id.assign("YKSVPGNTDCCBXQANONKWHAWBDFPPGLAQQHIWTHSGITMFIASCOMVQTNDELUEQMANVWSZUJMXMHJLCSBYHAQVEHYHYPVMRCYCTROWIVCXOXLZSGCUBBXIDJFPWGFJRNRUQOGZVTRBUGNYUJHJMCEEAXDVPIYDXXUSICZMZAQJLNFQVOBTWFYZRLKRKKNEZPXTITJKAYDLFRDXSHBUSVEZUKORNKMALFGDQJZSOWPUTEMKDFBGIJ");
    msg.feature_type = 156U;
    msg.rgb_red = 153U;
    msg.rgb_green = 240U;
    msg.rgb_blue = 77U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapFeature #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapFeature msg;
    msg.setTimeStamp(0.435757026468);
    msg.setSource(43062U);
    msg.setSourceEntity(164U);
    msg.setDestination(12467U);
    msg.setDestinationEntity(154U);
    msg.id.assign("TJSZIHLAOIOHULHTHLKZEOYUOXFFAWQJVPWFCMCVNJPWUEDMXAPVSLQPIDNTSOQNEVKKALGGQHXNSKMLJUYURBKMZIH");
    msg.feature_type = 147U;
    msg.rgb_red = 49U;
    msg.rgb_green = 25U;
    msg.rgb_blue = 136U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapFeature #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapFeature msg;
    msg.setTimeStamp(0.521970362854);
    msg.setSource(1721U);
    msg.setSourceEntity(95U);
    msg.setDestination(57311U);
    msg.setDestinationEntity(39U);
    msg.id.assign("WVENPXEZFTTVOQGDAQBBJUPMJYFKATWOWKXQIPHHBDSZHNFVCFVILUHAULUCRTUKGZDCBAFWMTRRF");
    msg.feature_type = 54U;
    msg.rgb_red = 122U;
    msg.rgb_green = 205U;
    msg.rgb_blue = 23U;
    IMC::MapPoint tmp_msg_0;
    tmp_msg_0.lat = 0.0798642623261;
    tmp_msg_0.lon = 0.587751485999;
    tmp_msg_0.alt = 0.956121912499;
    msg.feature.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapFeature #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapPoint msg;
    msg.setTimeStamp(0.882048975817);
    msg.setSource(42324U);
    msg.setSourceEntity(225U);
    msg.setDestination(11998U);
    msg.setDestinationEntity(102U);
    msg.lat = 0.713408146357;
    msg.lon = 0.69655303734;
    msg.alt = 0.978293042149;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapPoint #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapPoint msg;
    msg.setTimeStamp(0.434934353054);
    msg.setSource(23998U);
    msg.setSourceEntity(203U);
    msg.setDestination(53815U);
    msg.setDestinationEntity(227U);
    msg.lat = 0.801748741722;
    msg.lon = 0.279844643446;
    msg.alt = 0.162043722368;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapPoint #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::MapPoint msg;
    msg.setTimeStamp(0.721133894475);
    msg.setSource(39122U);
    msg.setSourceEntity(90U);
    msg.setDestination(22324U);
    msg.setDestinationEntity(122U);
    msg.lat = 0.718330579989;
    msg.lon = 0.759692746386;
    msg.alt = 0.558725559959;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("MapPoint #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CcuEvent msg;
    msg.setTimeStamp(0.10017503411);
    msg.setSource(46293U);
    msg.setSourceEntity(36U);
    msg.setDestination(28065U);
    msg.setDestinationEntity(13U);
    msg.type = 61U;
    msg.id.assign("DATMOPJJVVAPLZTURBFKRDQNOSEYHQCANDSOJPOVVBHWONVTUZKXHCBFDISXYRIDCYQTCMDQIGQOMGZPPKXTYIZTLKYZTHGDLKYXFBLRNZNQCBJCTEOOSRWZPGEELQFMIICSWUGILVHMNSFFNYIUUYBAWLKFHPNSWGSMAPHVABUJVLAKRXWUPIJQHCEIWBQNZ");
    IMC::CpuUsage tmp_msg_0;
    tmp_msg_0.value = 229U;
    msg.arg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CcuEvent #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CcuEvent msg;
    msg.setTimeStamp(0.140777677193);
    msg.setSource(51646U);
    msg.setSourceEntity(96U);
    msg.setDestination(7065U);
    msg.setDestinationEntity(213U);
    msg.type = 99U;
    msg.id.assign("BLFTCXCZWNKCBMZGJILZEGFCKFETGBOLSTMMIVJQCDHDYKNQXVFKLPFOQAAXPSDAMMKNHCGGVODIQOPHDUYYOBOOIYUYDAKTHNPRYWEBXUZXJIPWNEQECOPQVBYRPFXDUZFCNVSQSKJVHRKEUPXLVZZAWWTVQMNMLSTLJRIIIHHJTLAHSAJEKMXXRDNGLGDUBTBUBGYTOHWCRUJSJKVYREQWXQEVFSZFSGHYWCG");
    IMC::EulerAnglesDelta tmp_msg_0;
    tmp_msg_0.time = 0.264774513461;
    tmp_msg_0.x = 0.858848397021;
    tmp_msg_0.y = 0.00310643216331;
    tmp_msg_0.z = 0.93946420826;
    tmp_msg_0.timestep = 0.602624705088;
    msg.arg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CcuEvent #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CcuEvent msg;
    msg.setTimeStamp(0.0685762671309);
    msg.setSource(40585U);
    msg.setSourceEntity(66U);
    msg.setDestination(36350U);
    msg.setDestinationEntity(103U);
    msg.type = 221U;
    msg.id.assign("CNKNICKHYGOUDKAIJBWUHGADJPTFXKVVECBOXORQFXTVVBSFUEFWNYRBSIWDWBTICYKNRONKMEQQOHFOQAZUFRGRPDWDJCKZYERSBLZSQALQRFJPGMXIYDTM");
    IMC::DesiredHeadingRate tmp_msg_0;
    tmp_msg_0.value = 0.554367288256;
    msg.arg.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CcuEvent #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleLinks msg;
    msg.setTimeStamp(0.74161333539);
    msg.setSource(24977U);
    msg.setSourceEntity(80U);
    msg.setDestination(23094U);
    msg.setDestinationEntity(46U);
    msg.localname.assign("EPADPLOUWYQXPDCEXVIWUKGPTRMLFQQELQNVJWRHCIJGPEJPMABZUALDMQZITSNNSWXVKMAGCDBVBYBGKVHYMRFLIQYZEAGCRXKACSMEXBIZOITUJGDYWUOOCNRLEAMWNSFTYBFHEKVGPZVKDVWMQRUZGZCJXXHBFXUBWFDZZODMHHLSTTXOOOLITKBLTACENURRQVGIYKKSNTGHIZLXHMPBSHYJQJJTK");
    IMC::Announce tmp_msg_0;
    tmp_msg_0.sys_name.assign("DRHABNBVLKDZDKLSGEBWJZGVWCGNNKJSARYCPMSLVZFPZFAKMNPFWACLIALODOFLTNZZFWNRYBANODZJZTWCZOHFOITMHJKAIGUXPAQTQVQTOWEXWUPKBTURIBHEMJHVMDLVUYNFSOGCKEPXNVIBGHSKCOLOEMMAFMYTVOGURQCPLGXSXNFXPGDDSE");
    tmp_msg_0.sys_type = 11U;
    tmp_msg_0.owner = 30898U;
    tmp_msg_0.lat = 0.140582906208;
    tmp_msg_0.lon = 0.636914160025;
    tmp_msg_0.height = 0.874865842652;
    tmp_msg_0.services.assign("ABPMRWYLZNLBJPQIXLUEAPBQIWSARNKTTUYRMOAKOHTGSOZHGWXITVDOAXZMCWXUVQCKSZLAHUBYXIXHVLHUSK");
    msg.links.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleLinks #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleLinks msg;
    msg.setTimeStamp(0.490664309198);
    msg.setSource(20466U);
    msg.setSourceEntity(110U);
    msg.setDestination(29292U);
    msg.setDestinationEntity(235U);
    msg.localname.assign("KCZOWGDYMFRVOSZOQNUMQEBKESQBMLVEVOJYBRXVYYHPHGZQBZOTOFRGKQVVUIWRMXYBRWKJEPLYSPUMEAEOWPJKDBFTPDYPXXUFQLMPFNUPTWDYTHJJRMGODNLAFEEUASNGMJVPQIAACCLFXKHBJIT");
    IMC::Announce tmp_msg_0;
    tmp_msg_0.sys_name.assign("BFEQSCPHQRHHNHPWEGKDWORGBTGVWRJPAAVUIMOQFGXKLRCNBQRFIKZPIGNMATNZGJGHLHXMOJUNYJOPIYMVPYRYJYUEVPHDUVTOOIFSOPNTOBJCFIDWLNXHGDJKWRLCCKUEKLBAYXVGUAJFLTTEFXNMXSSWIQZSHWRFSLPQMBKOTUZFSMTDZIYIEZKOQXDVALJTCDZCCDYMZIMQTHWUVBRDAECUEBAEFSS");
    tmp_msg_0.sys_type = 46U;
    tmp_msg_0.owner = 62350U;
    tmp_msg_0.lat = 0.702156765617;
    tmp_msg_0.lon = 0.817445902564;
    tmp_msg_0.height = 0.92099531758;
    tmp_msg_0.services.assign("XEFQCDMLRTFKUYHKIKDFRLLTGAHCHPXHOCNODIEMFQGYGJGNBJDFBARQHGKXAYRPCEMCZEYMEZFWDJZHMRAQSSCXNXMNHGBFIVBOILKAWUTVYIAYRIBH");
    msg.links.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleLinks #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VehicleLinks msg;
    msg.setTimeStamp(0.239887510806);
    msg.setSource(34458U);
    msg.setSourceEntity(251U);
    msg.setDestination(38639U);
    msg.setDestinationEntity(150U);
    msg.localname.assign("ZRDSSDARQTTMYJNYEPFJIXINVHDBULWLULYTWUMHIVOPMTRUJGCMKIOTENKFCGKNGCSCE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VehicleLinks #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexObservation msg;
    msg.setTimeStamp(0.124505294918);
    msg.setSource(55998U);
    msg.setSourceEntity(187U);
    msg.setDestination(8006U);
    msg.setDestinationEntity(18U);
    msg.timeline.assign("BZCHBWGDNWG");
    msg.predicate.assign("GVUZZQTBWVZMCUFSOLXVKXSSZFTQHKQROJBVSJAOHIAZEHCN");
    msg.attributes.assign("ARZHZPEDIJMJNIPUOVRCLNOIJXQUWWCNOXTWWKVQSPTMYVSFTGAMCQJBTIDHWOYFNSHOPCHRFXMDLATQORCQEKRHZKLSWKUEGWTGTFRYZLDCFVHOBIHAPTCYERILURSTMAZHKYAVBLXGJGBZBUXSODDIQEEAVQGSAKEEWLYMXURCBVSUJMMXUDAIZNDLVEOLGYZCNBSCKKXBFIXRBNKJHGMNDLPUFPWSTQFWYBVMPAYKHJPVOPFNDIGJUQZ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexObservation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexObservation msg;
    msg.setTimeStamp(0.441132021337);
    msg.setSource(44481U);
    msg.setSourceEntity(8U);
    msg.setDestination(37452U);
    msg.setDestinationEntity(3U);
    msg.timeline.assign("QUQEEMFEIEIVGLFWKJETQOUZMCWXWWJQZANGFCVPVNLWAUBDRMPGNBOWFCQTBGELAGIISNQHCHXUPIUSQKTECPQNDOBAQKAPRXPLUAMKIRFDXHJHDERKVSOKGMXSDTMWRRLTZPVMAYHDDWJIWSHYCCRNJAOZVUYVHHAMSJDZOFNFUCYTG");
    msg.predicate.assign("JRKEQMTJVWOWSBFJSJHSDYMKOGPTFSNSIKJUEQFOVEDLPNDLCFBACGHMNJUHWWKMVTNLJRAWCQXWGMKZPSNUZZIATCKECIMKQLTYAUXYSLSPEOEPOXDQAKLBXAIUPNFGAYVUHRXRZLGTHZSHXAIMYUGOXUEZWOIIDBQBSTYPHGBHRDBQYJ");
    msg.attributes.assign("UPTDTISDCPGHLTJNERPCAQYNOKDXCRXWTQMKSYIBRENBOXPHSZROJAALKAZXKSYUABPBJIJHLYQTZZIEXKGWFLNEYWQGCPQACGVPWGNMRVMYCSZBFBQAVROYDVZAWSKQHEVSWQKONNGUFOEWBETXDUFJOQTRFOZFZJUIGXTHJLFDVULJDASCLPFDJVEOMM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexObservation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexObservation msg;
    msg.setTimeStamp(0.666391339647);
    msg.setSource(5867U);
    msg.setSourceEntity(92U);
    msg.setDestination(45647U);
    msg.setDestinationEntity(63U);
    msg.timeline.assign("NQKKPVERUAUZZOVQJBFFTVNWJGTHZCZFMUINOAULLTPWBHQVAONDWKPVZIVROKDPVICTIROKQGSLELUPSPDWRXWDDEEP");
    msg.predicate.assign("ZVELIIQCENTWGJUAUURYWXTRFYOAPRJNICJFANOBBLMYCTXBGXTGGJLSLYEYMKGHEIRYMVHXZECOTJXWEQAFGFOSDPDOIEAYZFCDHAGSEXMZDMOMOFAWNTDBHPSGQPVDHKIHBKMXFELJJSLAINDTKTVCQYDBIPNZAWCTPKGRUDQZWHQMABYPSJPQFUKOGINWVNMREKZZXVLUDCKVFUOSSVNVVSU");
    msg.attributes.assign("FICYWTTPBSUIHOYRCUXKZANQJSWDGHAZHJXJZPQRHFQIBXVGOCYUAFLFCZAVBRRCHUCVNLJFMWDDLWOVIZZWKMMKNDMVPMJNHRPWETOGGTJKHVBOUNWYARLJXTNXPK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexObservation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexCommand msg;
    msg.setTimeStamp(0.256708583071);
    msg.setSource(33264U);
    msg.setSourceEntity(215U);
    msg.setDestination(14416U);
    msg.setDestinationEntity(28U);
    msg.command = 216U;
    msg.goal_id.assign("SNSLWTDXICKOGFGNKTODEJQVMGXXRHOMEBOUPHCZPRRVNKXEUWDAHSVWAPFNWSDNTMVLCVGSFNHFBFTQGRTMAUKIEJTTQPLYZJKUUBSIIXBPBJYDXJWHHBPFISNFMRZUKASNOYOOZVEPBWFJVHQJESPRTEIDUOIBCEDZYFLYQLAULALSXMAZQCFROMLARNTQKAMVNOXEGDMZKCKXC");
    msg.goal_xml.assign("MPLIDGKTZIVYNLRFEOQAESXOGGSNWNOYLWMVCPDUVFXQIQBGHFFIFZCTWVEASACNHAXRKPZUPYSTODTCDKBBTQCGKWLLRWNKNLQWMUBMILSQUJFJRLJBFPIKARLXNKQEZTRSOQAWXHJUAYVEWDYHOVJBYMCKADTZDTQZGAKHRINISJHRTXJMXXPCNMVUCXDZAZGPUYFUHHLJGGF");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexCommand #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexCommand msg;
    msg.setTimeStamp(0.160943398851);
    msg.setSource(14336U);
    msg.setSourceEntity(32U);
    msg.setDestination(61603U);
    msg.setDestinationEntity(76U);
    msg.command = 159U;
    msg.goal_id.assign("PUHYGPTGMELJROPWSEMKUNDCUEIHZOCSKKMMFRDLJVSWVRRNJBDQOTDDRWCCOXXIQMGWIAMLYOQIJQDVGVGPS");
    msg.goal_xml.assign("XZAXKSWWGSEDBBIAWNLUYBAOOXWPMEDEHLLGFYBOUBUMFEEAPISDANMCKZPYVXCIZPFHVUEXLJCTFPVUUGYPKAXZQIQQGICHKKLJMGVGLPN");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexCommand #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexCommand msg;
    msg.setTimeStamp(0.167405199483);
    msg.setSource(62908U);
    msg.setSourceEntity(51U);
    msg.setDestination(20313U);
    msg.setDestinationEntity(78U);
    msg.command = 4U;
    msg.goal_id.assign("DHHPPILPRACITKUAZJOQKJTCUIUWARBVYSBLBBUOLMHKOFOJLLPLUHEZVACRNINJUFZSDIWFRMFK");
    msg.goal_xml.assign("LMQMXTLTKPPFENBJCBSJFCGOCTBZYEVBBDSPOECTYOBVWUZDWWGXYONZDSSWHGHYELOIWPKPUALKRZGMNXXSCZLFUQQJLOIHFHANWJQLAAAGDMPURYBJDSBBUIWNMUHSMDDWFZMJOGNFYKLAZRSNKVRHVXQXMZRXCGKJXOVANYECIRHOIZYZCVRHTUSIPQAQXNE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexCommand #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexOperation msg;
    msg.setTimeStamp(0.187819280137);
    msg.setSource(46938U);
    msg.setSourceEntity(210U);
    msg.setDestination(59221U);
    msg.setDestinationEntity(50U);
    msg.op = 189U;
    msg.goal_id.assign("LPKRESYDSPIIUBFPGNWZIMCXUMJKCIUJXOABFLKDEKMNJRFTETEBDSR");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("CKOQVVSURHOKIBFBNACMOWHPCCZJAVGBL");
    tmp_msg_0.predicate.assign("XUAYEUAEQEXBFTNUEZCVWRTTQNIUSOEIPWSLKVWWGHCUNKGMENOQPEVGVXNYGJYEPHPQKYLTFBCBRBPDQLWI");
    IMC::TrexAttribute tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("FGLBEVVHJUMJHXUSQTCMDGWMOFVIOKLSGEOACRHXOPCFTFATZBAWNPZSSJBZIRWJUSLKPMBXNXGRUNXKBRCWSMFCLTHFQLZJOSYAYULIHAKNAEVQQGXCZVEYKXTSFK");
    tmp_tmp_msg_0_0.attr_type = 74U;
    tmp_tmp_msg_0_0.min.assign("DWSARMTXJMTLRESHEDSWEQFLLUHZEFKVMHKCNPSXTQYYFGJVSZXJDJLEPWDGODDNNQAKLTFARDIFPMVOBICOHXYHWGXFVVCWHIGMPUICBQYGULQDIUVJWNEUOBIJCOXWMCIDRTTCNUNFHZMQLBAIVQCXO");
    tmp_tmp_msg_0_0.max.assign("SXEYDQAKTLOBVUZWZIYVBZIHPTSNBMINHHDFKNIFYLCFRBNQUEMTDVCEMUSBCRIJRFITFAPLGYMWECLWSSMJXVAFXVQVGKQWCCIYDWECIVHKLPPGKOTFYJWHMNASZFEWWKOJGSVJRPDSXXYTOOJBAGJRYHLXOEG");
    tmp_msg_0.attributes.push_back(tmp_tmp_msg_0_0);
    msg.token.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexOperation #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexOperation msg;
    msg.setTimeStamp(0.366002360814);
    msg.setSource(48879U);
    msg.setSourceEntity(224U);
    msg.setDestination(49606U);
    msg.setDestinationEntity(7U);
    msg.op = 101U;
    msg.goal_id.assign("UTTMNEBPRJFOSVIYNVIWGBENFIXBGFASLLYWNBGOQKAGZDEXKYQJUMOISAONNRLPJMCDIIDHEGZJOWHDU");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("ICJKDXEXIYHCHUUZVYFIATZFFNIHKCOPOZKINHQYPOZRCHDNISKBEWZJELHUKBYHYTJTJJLDTGGEFHPQYGLSRLKHRCGUVWARBSKXNMUQVOANVVE");
    tmp_msg_0.predicate.assign("IDRDFXGRZYPGPIUHIKPBPHASVNKVXSYJJTYIPCJTGHUBAPWEYMHQZFFJDOHGNPNJVTYCTSSMRIELZCLQRFQBKFOOGSBXLHAOGZBOSSDCRCZTFFTJKAUKDEQPWMLPVIYEQLWHWRPJKULYATOKMBTMIWOWNVRRCQIMVAECFVRLZUIHDCSTEDBALXKCWYMSKDHUZLETNJOGSHQFXZXXJNXYKQVOM");
    IMC::TrexAttribute tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("AHHNIPVMHJQLOLUFFUHKDFRCZBQMIXACTCNSBSYEYKVCUJMXPTWIIEHQPLOUQRUNUIGLKFZHGRWFQGMLSQMBBGWBZOTVHSIYNZEODVAAYRPIDFGDLHNXBZTJKZWXCRJPOXYBNWJKQUUIBSJNZVTDKOPEFECRQDVRLHWDAOPGXFMBANVRWMQECRGTTEZSPXQRYVLNWMAGGKYDSUEYOFHCJMTDCKOVWDEZXVJTEMZJBSKPAYITXIAYOJLSA");
    tmp_tmp_msg_0_0.attr_type = 30U;
    tmp_tmp_msg_0_0.min.assign("AALNLAXBVMDRTNWMHEDSH");
    tmp_tmp_msg_0_0.max.assign("RYNDJOJQMAMUYCYHSSNTXHAPORJZQJXZGBIUCMKAXZJLCBWKSSQFETYDZWBFEDATYDKPWAWTGFNKQXEFGKLBFRMVORJVROWFNGPXUXGCGLJMNNRKYPHPSKKSHSBU");
    tmp_msg_0.attributes.push_back(tmp_tmp_msg_0_0);
    msg.token.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexOperation #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexOperation msg;
    msg.setTimeStamp(0.523237803423);
    msg.setSource(9710U);
    msg.setSourceEntity(214U);
    msg.setDestination(60087U);
    msg.setDestinationEntity(219U);
    msg.op = 209U;
    msg.goal_id.assign("HIHQSVBDKGLIZLFZVXZGSQJVTXDYXLOIDQFCBHBIPNMAQPJRVERCCPZETDFUXUYANPPNCNSDXZOSSRNEUWUGENMTBWWKVHLMIQKWSTOWYDFGOVKVCWNZAYXTPOXGPYUCTLDPNAFPFBLYUIIJCLMXLBMGTJWGEQAFPSMVIQBQJCGEEZADRRMEYYKZWRHTOTDXBQQRFHLCBOKJJEYAANKABFSNVMJWLMROHUDUW");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("LWDAPQLVMECIZSRTPEUNGTGDQRERSGGUHSYTQUHPCUDC");
    tmp_msg_0.predicate.assign("MZUYPXKBBONQLDDLYDZFFYWTPCYROUYWGXAHPSMFJLLYLUZPCXEBKAEPBEHIYRJMCAIVINZAMHLJHVFSIGDTJYIDUYHUZWGTTKJMXZOHFEHQOBSIO");
    IMC::TrexAttribute tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("OSLIUZZAARNCVMYEXFRHRESXCESIOTCATJVBNROILTGWTTAFWWNDQTUHOFCXNQPQLBPMXLPCZEVKEXQM");
    tmp_tmp_msg_0_0.attr_type = 73U;
    tmp_tmp_msg_0_0.min.assign("NTYPKXPFWTWMYCQLPXGIDJWJJZLNSSVOKOUSUHGYFMNKLVITDYIKMXNDATBEQZATFDVKDFGRSZXUAGLDTSVZNLWFBNUCMAUIHYROVSZCGSORUBUQTOBFPNDNXCMRDRIICAPJRMPUBLLMJOPYNGIOPXJCUHAVGNAJHEKPXLGHIHABZJELIEQHSRSOYZMXMHWWXVWAKFCCKLSTZVWAYHEQERR");
    tmp_tmp_msg_0_0.max.assign("MJPWGXDOMOUQLYLLOLQRUNFQAZJZGVKKZWPWGXTIOFZBHANBFECPWJKXALGVNQLTFCSXBYKNUGDDGJNFMEIECJIQUTSDWQUDRAYXMIDBCHCLIKVHHTSHKLFPJVSYAOKDJKATRALZCEQUPVMJVPITZFPHRUHBEMFRSPUBIZTVYOFTZDEEXBZROHPHDBJEWCYZRCGOTVXWPSIW");
    tmp_msg_0.attributes.push_back(tmp_tmp_msg_0_0);
    msg.token.set(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexOperation #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexAttribute msg;
    msg.setTimeStamp(0.785521073983);
    msg.setSource(1029U);
    msg.setSourceEntity(182U);
    msg.setDestination(11766U);
    msg.setDestinationEntity(189U);
    msg.name.assign("XPMZZPQLTKLTNTQPILAHQEBRCRJYVQR");
    msg.attr_type = 22U;
    msg.min.assign("GCGRIJYNGPLBMZXLZNNWIHXHFSFMAQELVKYYIBZNUJDKPZDOILRCGJMBTDRSQKWXFIIAOACRYVRYDOKGFOULUJHUSECSPFWQRAOUXDDABEKSNTQFYGLFUQ");
    msg.max.assign("BJOYBGTHUJJTZSXNBOGEFYWEJVCTECKDNZPUUCEWPUIZYNHQBQAJSWGOUCPXQFVPXLIOZGMFXLDTLCYAWSDFLUQSKCSEYIGPSZLVVKDVOAXHKANTKNQYFOAYCMPFROYNTCNXKJDNRBRZKLSAXXZLM");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexAttribute #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexAttribute msg;
    msg.setTimeStamp(0.931218115648);
    msg.setSource(42244U);
    msg.setSourceEntity(20U);
    msg.setDestination(2090U);
    msg.setDestinationEntity(122U);
    msg.name.assign("DPPNELGDSCPKUKDOFEDNEBRBQKISHGADCHRZVIIPNSVWMNZC");
    msg.attr_type = 27U;
    msg.min.assign("VTWGPRJHNEUTGMEQOUMJANPSJRVDFQDSLZVLYRBEOAHEGPWPEMAJAGS");
    msg.max.assign("FGZDWODOLYKFVQMZGTKWZHGKOGJZUXAJJILTBCFYCIYPHHISTIKMQYXVZBOKTUJNAFYRTVZRYJXNIPFDNMFZYLEJBPQEZWNOACCWEUHISUHVC");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexAttribute #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexAttribute msg;
    msg.setTimeStamp(0.740194944937);
    msg.setSource(54079U);
    msg.setSourceEntity(192U);
    msg.setDestination(2146U);
    msg.setDestinationEntity(236U);
    msg.name.assign("YELDTYNQVOCXGNKJBCNQKTXXSZHOQQNLUMGTKXLLTOEZSFZWFURSAVIBNFTPLAJQVFWTUUQWZYDEYYJACLHPHOOXEFXOPSMJGVSBGDBEADKZSBAXLJEJGSRPKXKRHFZVTAPWPKVBYNFODZNOMROCISRASCWKGACUWERJFWIIMRDRCVYUYITHFTUOMQGBMHHWMVPKDBMINFUBUQHACZPLDNIRDGAJZEJJ");
    msg.attr_type = 55U;
    msg.min.assign("UKEOZTCJMXPITMLAQBFFUCWQGGUGKXHWFTCLWPIQSYKLKSJDSNDTALVNGEGXDFPVJVQWLVEYBASHTHUWLYACHCTITNUHPCZORIMLFTAXJUJJIMPUZVLHNNNRAADQSAOBFIIEQKZPUMJYTWGOCHDLYVZFGZBNMLZQIEOXRBSKDXOHCKYDXJIFJYUAHEB");
    msg.max.assign("KBXEFLYPYMOLFNMZDUSZUQDQTNLKIWSJRLNUQGTNUOKUNJKOLSEQPAPAQCNGZJXNFMUXYDSWGEHEWRVOIMREDWFXYCWQJTVQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexAttribute #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexToken msg;
    msg.setTimeStamp(0.0961506107926);
    msg.setSource(520U);
    msg.setSourceEntity(232U);
    msg.setDestination(33116U);
    msg.setDestinationEntity(96U);
    msg.timeline.assign("DYXCIQTFXPONXECANDIMZGLLHLOBFNJIUCRAATYMSOGWEXPDTSWKDYJTGGTMKKQWZDZPLWRQKKKLNITEWSEUHESUZPMVSFFGNYAXFWWVGBXVTHMBAANOFRNQAQBHHRQFVJILIVDJZGCDCZYCQXJYJYZTLLCCBLRRVBUOOQFSAVFPAUJVWUIJZGVBAXMORPPSBMHUKYNQS");
    msg.predicate.assign("JGBIUTAVKOJSGWHXDUJ");
    IMC::TrexAttribute tmp_msg_0;
    tmp_msg_0.name.assign("QCVMRYZMYFIQAADOVULTSWOGCTWRVUIBOWJIZEOSZNJNKY");
    tmp_msg_0.attr_type = 166U;
    tmp_msg_0.min.assign("ZZQHUBOFDIEYOWWKSBJHXRGKBKQJHICLOGTPVWWIEQLFRAIJEFUZGLDXYCKXJPHSINMHMMDJMEFIGBJUVNPYQWSAUPSVXGBNKQXBOLMLMTVRPTSBEFLLHNXENBQGGWEPJDTEWMRN");
    tmp_msg_0.max.assign("JDIFRDECKIMCGHQOTVDYIQBZUOISFMUNEAOPBHFLGKTXMXOURKARPRDKDGMWTXEXPWZEMUZESMAUDSTTRGGAROYG");
    msg.attributes.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexToken #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexToken msg;
    msg.setTimeStamp(0.542635383577);
    msg.setSource(38140U);
    msg.setSourceEntity(137U);
    msg.setDestination(12624U);
    msg.setDestinationEntity(51U);
    msg.timeline.assign("GSEETUEYXGLODPBYXCFRBWIGRNACKAUHOTRJOGETMXAYWLJWDZERIFGQOAVNJFGFLIRLUOAWRVIIBCZPUHQSDKRMBOVKAHUGVUHCXOQ");
    msg.predicate.assign("EHJZLAOHNIRYNSRBOYNSQVSBMNUIBOQCLPFWNBGWGVSFIDQYUMTTUKJMQJVVNCMDCIYTVDVLAFKICOKARYLGEOQGSWHARXWEAZKTXWXUZGRYERRFSHMLXXHGGWUDGJFYKZOKLXIZKYHD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexToken #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexToken msg;
    msg.setTimeStamp(0.195401658831);
    msg.setSource(18028U);
    msg.setSourceEntity(70U);
    msg.setDestination(16563U);
    msg.setDestinationEntity(171U);
    msg.timeline.assign("RZCMDWRTCAPERNSNEJZCSZXZAWAQRXCKJWOOUHNRMKEXMSJUEUTYYFECVGFQSTIFXDDTNDIUFOFYKIGKPDWMBHXRAPHSLTXCLNGAWSYWTTVHOULGGSOIVBVMVEUIOYJZLHIKVWTDFPBSLZLYGOXWNKCLRVETHKHLTFBKBUOYAPAQHMJBDNPMJQABYUMFEORGDFJLBBEZYNNQOAUJWCXCDJQHPISK");
    msg.predicate.assign("SRUQPYQMLGRPWOMKLFHHFVNGFLJQ");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexToken #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexPlan msg;
    msg.setTimeStamp(0.427906207247);
    msg.setSource(1971U);
    msg.setSourceEntity(117U);
    msg.setDestination(26U);
    msg.setDestinationEntity(7U);
    msg.reactor.assign("EODXLIHHHNJBXILWUVPSIAXXLADKOREKMJGTCDMOXBKYJHHRSQUGIFONMRZCQVVYLFAGRCUVUTWYLSWDTNQBRWFEWMUZVSQFTBFKYXGJSJOIJMBRZETPNPYJWMSFNAZOGSCKRMNAUVORDG");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("PSTJJFXLYAHUHZOQDWKEAOGGFBXFVGYXYKNOBFNZWVBRXCEGEQCADLQKAPYZUQLPXFACVTWETECEFUJMCQJYVRSGJ");
    tmp_msg_0.predicate.assign("DXXKSKNILSIPFZRIIDFYAQCESOJGKOZTRRTEIUEJUTIKEXQPHNCIJMGYSYFNKKPITBGWXGJBCWQEBZOFDPPKTNTUTMOCPDOYWRBLMADNLA");
    IMC::TrexAttribute tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("TSOPJCEYIJUOKICYYPDYIRZJBEBXW");
    tmp_tmp_msg_0_0.attr_type = 16U;
    tmp_tmp_msg_0_0.min.assign("NHGKNJZFPOCKFFGATYMZKFYMGMKMHUYRVTBJUKIVEMPWNWNXNQRXICJDGXIKNIPIXCEAEVZXBHO");
    tmp_tmp_msg_0_0.max.assign("EQKXZJRDKDPAHEPDWGIWRTWKYYKRJ");
    tmp_msg_0.attributes.push_back(tmp_tmp_msg_0_0);
    msg.tokens.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexPlan #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexPlan msg;
    msg.setTimeStamp(0.142910991216);
    msg.setSource(27676U);
    msg.setSourceEntity(113U);
    msg.setDestination(27164U);
    msg.setDestinationEntity(97U);
    msg.reactor.assign("UTCVWRFKPPVNLXOWHUYVDIVAZFJUKKZPYQFTNFQQWXBJYWKRMLV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexPlan #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::TrexPlan msg;
    msg.setTimeStamp(0.523878210708);
    msg.setSource(53101U);
    msg.setSourceEntity(18U);
    msg.setDestination(35058U);
    msg.setDestinationEntity(99U);
    msg.reactor.assign("IVOCTVNVISOJTWZQONUKSGHYZPSEUUGFRVDBVOYFWRHKNNATXMCLPSLTGXQVXJWIAHZPLQDHCEAGRBHXDQVJGOQLMFRKNBBMVTPOYRNWZBJPSFAOZEEICGLFDRALEXKMSDWJXVAKXOGIRTSDKCWPTEKTGESMCJDHPLIBOQEEJBAOHMPIJYSFFXIUKQQUCQZKQB");
    IMC::TrexToken tmp_msg_0;
    tmp_msg_0.timeline.assign("PQEXUOYKMGRWTLQSWDTBHINXUWPOUVPDVRCQGDFXFNPJMRGHSATOM");
    tmp_msg_0.predicate.assign("JNMDHDEJYOOPSEGOMKKYBUBCKJXRNVQMSXTXAECZPIURTYUQLVOCPIJLKTFDGXJZNCIWD");
    IMC::TrexAttribute tmp_tmp_msg_0_0;
    tmp_tmp_msg_0_0.name.assign("EYDKWBGIKWMZKXYEYTGYWNQTYDCYJLDCUBRRDXQXAIDQWZPAS");
    tmp_tmp_msg_0_0.attr_type = 253U;
    tmp_tmp_msg_0_0.min.assign("GSVANPXWJRTDPODDIWXRLNOPJIKUPUUCQFMNOBGHJSIYZZQMEBYKDBOYQPDIKLLMAS");
    tmp_tmp_msg_0_0.max.assign("PALAAYBNVEFFAGVXVXMKLMPFACNFROUSGMOWPVSUWIYDNQDUSCWYTSDQIOMCRPFKZRQGUKLHXNVKIANEDWXONECFTQHUZFSAHOVGKOUMAHEZBBEDEHZXLFLAQJRKIIWDZJCHYPJTADPILTSTBHDNYPDYKBUGWGJEXPCOYIWRUJLWXVKCTMSIJYCBLRTHRGSZKMLWBDTGVXTPNZGUOMQQJEFRRIZ");
    tmp_msg_0.attributes.push_back(tmp_tmp_msg_0_0);
    msg.tokens.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("TrexPlan #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VideoData msg;
    msg.setTimeStamp(0.28308366181);
    msg.setSource(24991U);
    msg.setSourceEntity(246U);
    msg.setDestination(46217U);
    msg.setDestinationEntity(17U);
    msg.id = 45U;
    msg.width = 1669U;
    msg.height = 24903U;
    msg.widthstep = 52042U;
    msg.channels = 175U;
    msg.depth = 24U;
    msg.finaldata = 91U;
    const char tmp_msg_0[] = {-11, -3, -80, 70, -115, -42, 6, 126, -61, 59, 22, 79, -113, 104, -15, -116, -113, -35, 58, -115, -125, -15, -126, -90, -52, -11, -90, 74, 20, -91, 83};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VideoData #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VideoData msg;
    msg.setTimeStamp(0.560641121436);
    msg.setSource(19708U);
    msg.setSourceEntity(28U);
    msg.setDestination(26228U);
    msg.setDestinationEntity(124U);
    msg.id = 136U;
    msg.width = 13229U;
    msg.height = 16521U;
    msg.widthstep = 41949U;
    msg.channels = 254U;
    msg.depth = 78U;
    msg.finaldata = 141U;
    const char tmp_msg_0[] = {-33, 108, 1, 84, -60, -58, -62, -52, 7, -126, 27, -51, -5, 6, 108, -123, -64, 66, -50, -6, 28, 84, -113, 14, 39, 31, 104, 71, 70, 72, 17, -54, -41, 45, -51, 41, -28, 50, -103, 32, 3, -86, 103, -22, 115, 52, -99, -111, 120, -107, 20, -75, -27, -100, 26, 19, 33, -77, 74, 54, 8, 60, -8, -102, -118, 36, -41, -99, 5, -10, -76, 24, 1, -36, 6, -88, -58, -78, -27, 55, -62, -35, -115, -115, 65, -101, -41, 97, 93, 46, -72, -112, 26, -114, 82, -59, 53, -71, 97, -65, 84, 100, 38, -7, -122, 21, -65, 109, -121, 6, -4, -108, 108, 29, -24, 118, -84, 76, -93, -22, 116, 44, 22, 68, 37, 9, 113, 104, -62, 2, 118, 7, -2, 20, 82, -85, 49, 46, -4, -19, 1, -108, 116, -28, 81, -49, 44, 11, -27, -24, -25, 5, 2, -112, 16, 125, -74, 74, 75, 30, -94, 89, 24, -15, 85, 2, 18, -126, -78, -88, -26, -83, -53, 50, -103, -71, -121, 36, 102, 84, 64, -76, 110, 121, 31, 95, 70, -54, 106, -10};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VideoData #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::VideoData msg;
    msg.setTimeStamp(0.0117417808038);
    msg.setSource(46224U);
    msg.setSourceEntity(141U);
    msg.setDestination(20505U);
    msg.setDestinationEntity(21U);
    msg.id = 198U;
    msg.width = 40482U;
    msg.height = 59299U;
    msg.widthstep = 36368U;
    msg.channels = 186U;
    msg.depth = 36U;
    msg.finaldata = 81U;
    const char tmp_msg_0[] = {-86, -62, 120, 7, 38, 107, -82, 27, -53, 87, -113, -75, 53, -33, 66, 48, -120, 44, 33, -106, 106, -73, 124, -40, -101, 8, 39, 65, -72, -82, -119, -67, -83, 11, -59, 62, -78, -42, -28, -57, 122, 21, 60, 29, 39, -127, 95, -5, 35, -127, -19, -56, 63, 103, -103, 117, 37, -68, 59, 121, -10, -91, -75, 45, 8, 23, 8, -72, 111, 120, 96, -59, 122, -63, 120, 60, -31, 22, -99, 6, -6, 49, 12, -19, 110, -50, -70, -72, 99, -73, -56, -85, -93, 69, -90, -127, 1, 59, -92, -10, 36, 88, 80, 6, -114, 124, 94, 74, 42, -17, -35, 112, -44, 59, 60, -101, 88, 23, 117, -76, -11, 90, -44, 75, 124, -92, -60, 51, -8, 83, -119, 59, -58, -1, 30, 71, 95, -55, -76};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("VideoData #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RawImage msg;
    msg.setTimeStamp(0.0461514113642);
    msg.setSource(53064U);
    msg.setSourceEntity(145U);
    msg.setDestination(5214U);
    msg.setDestinationEntity(124U);
    msg.width = 17761U;
    msg.height = 17233U;
    msg.channels = 5U;
    msg.depth = 206U;
    const char tmp_msg_0[] = {73, -59, 36, 84, 95, -111, 51, -82, -114, -100, 96, -67, 36, 61, 39, 34, 59, 57, -126, -17, -103, 58, 87, -3, -66, -72, 50, -127, -69, -19, -31, 126, -9, -119, 88, 61, -100, -5, 93, 36, -23, 2, 31, 52, 42, 20, 28, 96, -117, -70, -64, 3, 110, 114, -80, -8, 13, -39, -96, -37, 8, -23, 95, -38, 29, 22, 101, 104, -87, 21, -34, -92, -93, -118, 92, -69, -122, -88, 124, 111, 2, 55, -1, 94, 5, 5, 43, 86, -113, -54, -57, 90, 51, 120, 76, 9, -52, -72, 90, 1, -128, 41, -98, 119, 45, -106, 109, -65, 104, 41, 13, -102, -109, -25, 50, -25, 39, 12, 94, -32, -68, 109, 113, -14, 12, -128, -87, 46, 48, 2, 75, 69, -89, 17, -28, -28, -91, -5, -69, 8, 39, -12, -32, 16, -89, 109, -24, -62, 113, -34, -59, 48, -79, -23, -41, -92, -46, 57, 109, -124, 83, -115, 108, 8, 0, -11, -45, -49, -114, 13, -11, -1, 78, 105, 10, -100, -42, 102, -88, -56, 5, 111, 21, -121, -59, -116, -77, 120, 116, -65, 66, -60, -24, 35, 17, 93, -85, 25, -9, -115, -88, -11, 21, 83, -63, -47, 50, 96, -63, 54, -85, 54, -106, 126, 29, -87, -126, 112, 13, 99, -62, -38, 87, 20, -118, -116, -12, -58, -122, -85, -123, -91, 112, 59, 79, -106, 108, -56, 62, -70, 1, 39};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RawImage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RawImage msg;
    msg.setTimeStamp(0.278899848893);
    msg.setSource(23387U);
    msg.setSourceEntity(126U);
    msg.setDestination(58461U);
    msg.setDestinationEntity(57U);
    msg.width = 32332U;
    msg.height = 34189U;
    msg.channels = 190U;
    msg.depth = 15U;
    const char tmp_msg_0[] = {-84, -99, 20, 36, 121, -42, 64, 49, 94, 119, 75, -77, 62, 53, -83, -34, 81, -1, 69, -50, 120, -10, 9, -61, -49, 119, 95, -28, 106, 42, -23, 81, -39, 123, 71, 1, 43, 27, 28, -16, 109, -48, 46, 90, -62, 23, 75, 45, -54, -108, -45, -115, 73, 39, -27, -69, -47, -14, 90, -98, -18, 49, -85, 117, 47, 7, 55, -111, -114, -68, 90, 66, 4, -87, 73, 73, -27, 23, -99, 27, -86, 103, 125, 19, 119, 3, 83, -119, -16};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RawImage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RawImage msg;
    msg.setTimeStamp(0.0854582197036);
    msg.setSource(16106U);
    msg.setSourceEntity(162U);
    msg.setDestination(58181U);
    msg.setDestinationEntity(232U);
    msg.width = 16104U;
    msg.height = 48023U;
    msg.channels = 168U;
    msg.depth = 43U;
    const char tmp_msg_0[] = {101, 84, 99, 111, -120, -84, -76, 100, -113, 41, -111, -110, 26, -94, -34, 56, -41, 92, -128, 58, 101, -51, 80, -100, -17, -64, -107, -89, -76, -43, 46, -54, 20, 113, 102, -106, 45, -14, 92, -95, -72, 0, -91, 66, -23, 58, 55, -119, -67, 123, 58, -65, -40, 17, -47, -103, 93, 25, -27, 53, -113, -18, -38, 43, -15, 59, 50, 123, 68, -82, -99, 31, 60, -95, -84, 70, 67, -127, 96};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RawImage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedImage msg;
    msg.setTimeStamp(0.741475328297);
    msg.setSource(48916U);
    msg.setSourceEntity(109U);
    msg.setDestination(554U);
    msg.setDestinationEntity(36U);
    msg.frameid = 201U;
    const char tmp_msg_0[] = {49, 2, 109, -125, -102, -109, -109, 13, 89, -79, 57, 9, -16, -3, -26, 38, -68, -78};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedImage #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedImage msg;
    msg.setTimeStamp(0.950559199239);
    msg.setSource(2192U);
    msg.setSourceEntity(171U);
    msg.setDestination(57739U);
    msg.setDestinationEntity(25U);
    msg.frameid = 143U;
    const char tmp_msg_0[] = {-101, 119, -52, -18, 94, 93, 60, 80, -121, -8, 88, -64, -2, -111, -114, 123, 12, 7, -2, 79, 85, -6, 94, -91, -116, 73, 13, 33, 76, -61, -63, -65, 8, 99, 124, 54, 126, 12, -73, -33, -56, 19, 14, -66, 89, -71, 115, -24, -16, 75, 9, -81, 19, -82, -123, -35, -15, 26, 89, 2, 108, 6, 6, -106, -30, 119, -5, 112, -79, 45, -5, -12, 89, 48, 86, -95, 23, -33, 10};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedImage #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CompressedImage msg;
    msg.setTimeStamp(0.0977877976585);
    msg.setSource(27251U);
    msg.setSourceEntity(169U);
    msg.setDestination(5346U);
    msg.setDestinationEntity(63U);
    msg.frameid = 248U;
    const char tmp_msg_0[] = {46, 116, 18, -56, 118, 90, -128, -35, 27, 13, -79, 7, 21, 52, -9, 71, 32, -5, -110, -89, -95, 42, -8, 78, 118, -5, 33, 120, 70, -28, 108, -70, -66, 122, 71, 7, -29, -86, 35, -16, -62, -100, 91, 73, 51, 29, 39, -85, 87, 23, 91, -109, 114, 5, 22, -50, -99, 115, -74, 12, 82, -7, 94, 10, -122, -46, -104, 42, 14, 111, -34, -22, -38, -53, 61, -20, -13, -48, 27, -58, 100, -33, 13, 93, -78, -45, 91, -37, 88, -52, -24, 103, -57, 26, 14, -87, 84, 9, 101, 110, -13, -125, 107, 48, -115, -94, 126, 9, -52, -77, 68, 58, 9, 102, -60, -68, -125, -78, -85, 110, -110, -15, -48, -81, 102, 3, 54, 108, 104, 29, 25, 91, -45, -1, 78, -110, 95, 60, 107, -81, -41, -10, -48, -39, -78, -18, 99, -93, 36, -50, -90, -81, 123, 94, 25, 120, 5, -111, 73, -80, -65, 11, 64, -83, 104, -66, -57, -16, 30, 44, -18, 69, -40, 28, 75, 101, -20, -12, 13, 26, -89, -83, -116, 47, 54, 87, -31, -67, -50, -10, -81, 3, -15, 91, -15, -56, -12, -126, 91, -65, -49, 90, -28, 49, -74, -84};
    msg.data.assign(tmp_msg_0, tmp_msg_0 + sizeof(tmp_msg_0));

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CompressedImage #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTxSettings msg;
    msg.setTimeStamp(0.444097597763);
    msg.setSource(48616U);
    msg.setSourceEntity(39U);
    msg.setDestination(7322U);
    msg.setDestinationEntity(40U);
    msg.fps = 55U;
    msg.quality = 199U;
    msg.reps = 179U;
    msg.tsize = 169U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTxSettings #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTxSettings msg;
    msg.setTimeStamp(0.126643996498);
    msg.setSource(62176U);
    msg.setSourceEntity(234U);
    msg.setDestination(55301U);
    msg.setDestinationEntity(0U);
    msg.fps = 45U;
    msg.quality = 113U;
    msg.reps = 78U;
    msg.tsize = 225U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTxSettings #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::ImageTxSettings msg;
    msg.setTimeStamp(0.978097692248);
    msg.setSource(58553U);
    msg.setSourceEntity(9U);
    msg.setDestination(38338U);
    msg.setDestinationEntity(1U);
    msg.fps = 52U;
    msg.quality = 113U;
    msg.reps = 101U;
    msg.tsize = 189U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("ImageTxSettings #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteState msg;
    msg.setTimeStamp(0.695578681852);
    msg.setSource(29543U);
    msg.setSourceEntity(189U);
    msg.setDestination(27981U);
    msg.setDestinationEntity(245U);
    msg.lat = 0.744472794473;
    msg.lon = 0.462411800388;
    msg.depth = 105U;
    msg.speed = 0.734935284054;
    msg.psi = 0.370134448183;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteState #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteState msg;
    msg.setTimeStamp(0.0729951330131);
    msg.setSource(62055U);
    msg.setSourceEntity(173U);
    msg.setDestination(24178U);
    msg.setDestinationEntity(242U);
    msg.lat = 0.338473876428;
    msg.lon = 0.717556366474;
    msg.depth = 254U;
    msg.speed = 0.215174526113;
    msg.psi = 0.432696581573;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteState #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::RemoteState msg;
    msg.setTimeStamp(0.727399835742);
    msg.setSource(60837U);
    msg.setSourceEntity(205U);
    msg.setDestination(64304U);
    msg.setDestinationEntity(225U);
    msg.lat = 0.107739557549;
    msg.lon = 0.842544492922;
    msg.depth = 85U;
    msg.speed = 0.406230179779;
    msg.psi = 0.0955304968026;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("RemoteState #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Target msg;
    msg.setTimeStamp(0.447834443532);
    msg.setSource(4038U);
    msg.setSourceEntity(100U);
    msg.setDestination(38662U);
    msg.setDestinationEntity(83U);
    msg.label.assign("PLYMWUQBAFKBWXACVZYZOQSSREFLXRNPVHLENMKMUILIAP");
    msg.lat = 0.60930825043;
    msg.lon = 0.898971908609;
    msg.z = 0.924944916518;
    msg.z_units = 172U;
    msg.cog = 0.297989406927;
    msg.sog = 0.712663909172;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Target #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Target msg;
    msg.setTimeStamp(0.580265796158);
    msg.setSource(44418U);
    msg.setSourceEntity(207U);
    msg.setDestination(51916U);
    msg.setDestinationEntity(93U);
    msg.label.assign("WRDNEIOQTBWPSXTMPJWGVLFHKIKWSWHGSOICZYCMFMVBOSJTOXMTFTDBENIRDXJPUGXEDEOZWKNERNMC");
    msg.lat = 0.794781804882;
    msg.lon = 0.362710057949;
    msg.z = 0.866060136642;
    msg.z_units = 94U;
    msg.cog = 0.820173092208;
    msg.sog = 0.463871413664;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Target #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::Target msg;
    msg.setTimeStamp(0.470447564555);
    msg.setSource(10284U);
    msg.setSourceEntity(89U);
    msg.setDestination(58633U);
    msg.setDestinationEntity(177U);
    msg.label.assign("SRHWIHAXBBYPOOVMRUUJIEUPVKLZBLTEPDOQGFEURSCKIECDGWGQSHZLKTJIBQUYHQOJFLFQJCVQFGYKZMAJSNXUTXAMVTTYJVIKOSBYLGVYEACHRJDNSLSMMQZETJGUOXBPPJMMOFPXNEWSZDWIIRWQRVVAUWFGCHMBRJDNBFQCXGNUVDO");
    msg.lat = 0.910523563023;
    msg.lon = 0.992465135954;
    msg.z = 0.0163632607823;
    msg.z_units = 132U;
    msg.cog = 0.667569796583;
    msg.sog = 0.164034469173;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("Target #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameter msg;
    msg.setTimeStamp(0.836941672053);
    msg.setSource(27129U);
    msg.setSourceEntity(45U);
    msg.setDestination(61215U);
    msg.setDestinationEntity(88U);
    msg.name.assign("CKQQHIJMIBCUEMGDSKIYFTLYRZPXEZTVXCMFRNTDIUWQNVYUFNGWRDJKQULHRIHFOBTEDGMATVMRHYWBZBGEYPUGBMOQTNAWOXREPEQGKLIPROJSEVVZQBIYWFAFXSNOLPXPPPUHOFPWGUUKKKVLHNCRLEZYZIDCWBLJEJZBOTHVQJHULSTADGKMMMYWXAVSMHGPNACSOFKRAVKDJXXAOTCBIHJQAJNZRZWSWSVOI");
    msg.value.assign("SJLEDDMZEEUWMREVHQMMJNVSWXUJWOXSSKHYZLTGILJQXDGVFLPPTOSUYZPDT");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameter #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameter msg;
    msg.setTimeStamp(0.311433725913);
    msg.setSource(44000U);
    msg.setSourceEntity(208U);
    msg.setDestination(29072U);
    msg.setDestinationEntity(90U);
    msg.name.assign("FJBFAHHXUHTHWJRISZRKXPSMQZZAEFAVPEFLNLNDIADWRGZEUSVAIWVUOYWBN");
    msg.value.assign("GMNWAVZRCIASOFNWMDFAJEEXGDTEFXCZZTHODIQRCHJWCDWMUINZKERWNBTGVYBQQIZLKDTUPNTXWDDVFPGQVPYAKUYOTVHHBCPEBFIICAIFWAXFHPVYXZEJQAUINBUHPSYPCRDP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameter #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameter msg;
    msg.setTimeStamp(0.524427056308);
    msg.setSource(52909U);
    msg.setSourceEntity(33U);
    msg.setDestination(42562U);
    msg.setDestinationEntity(21U);
    msg.name.assign("HHDHDJXOMIZSGJIKNMQKNPSAPOWUHYXPITUJRZWCDLNBREEUAUZJYNAQLZCBECQCFCVTFJLNRGWDSQCWY");
    msg.value.assign("IYTTTTLLDZNGSFSVPBGDDYMDQATZNUBDNCWVJXRQYEQAIWHSUVRS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameter #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameters msg;
    msg.setTimeStamp(0.0628099110274);
    msg.setSource(7302U);
    msg.setSourceEntity(98U);
    msg.setDestination(17457U);
    msg.setDestinationEntity(124U);
    msg.name.assign("EEGGFHYPTKFUYACXIOIFLUCCGRIMRYOSTLBMBPSLTVEAZGWPHRNAWEUBWJOZPBOXQLTKLDEWGYKXVUJGCMCUQUPVXYAHHFZTSKKQDY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameters msg;
    msg.setTimeStamp(0.39906187698);
    msg.setSource(13591U);
    msg.setSourceEntity(92U);
    msg.setDestination(39688U);
    msg.setDestinationEntity(33U);
    msg.name.assign("VGLPDUTLSPBYGIPCGYDUODAFDCSOUDECWEWTIUMRXZAOYWUNOBEYWTRTJSGGJQQZOYRBTSNWENLNLZRKMHMMRAQQBSUUXFDBJBH");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("QKKTCIYTEGHDJAWOGTZQ");
    tmp_msg_0.value.assign("VXUBMKFDVRUPAWJQFZWDBQGGRCXOKCWOKGRSHGDSJQJHBNEYZJXCRHRKFIAOPTNNKKLMUXTJYRTUZGVMSOLTOXJIJIIKWASZCCNFGEARNIWQOBNXYHQUQRNUEBTPVYIDMBQUHAASZDMAYBWKFHILBCDLMCTLLQVPKMPYFMPGFSPKSPLBDRT");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::EntityParameters msg;
    msg.setTimeStamp(0.534427698578);
    msg.setSource(9226U);
    msg.setSourceEntity(2U);
    msg.setDestination(30893U);
    msg.setDestinationEntity(181U);
    msg.name.assign("TXOLRTCKTRDHORNTHQDTDYHKWRAOFWMXYGULWEMTKJPGCZDESZQXPDQMADAQQMJCNCIVGQHBCSCDYOZGNNFWDIQYSKPVAVJLUEQVXHZOIDIXZMRYSPVLXGKIUVKXGVHGZCUXROPRQWIEJHSFLJATUWGWBUFOSEPRQMCRSSJBEMHKNNNMVFBAIVNYWOSDNTBZLEUBYSYEXIJWZUFFBLYAZFFNAPMHGJZATPJPBXPHBKKCMEALGCBTIOYRLEJO");
    IMC::EntityParameter tmp_msg_0;
    tmp_msg_0.name.assign("DJBTVKECJBYGHJDTFFWSTLG");
    tmp_msg_0.value.assign("ZSLQUGEKUOLRTMYKTYJXQZATM");
    msg.params.push_back(tmp_msg_0);

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("EntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityParameters msg;
    msg.setTimeStamp(0.729200435531);
    msg.setSource(21205U);
    msg.setSourceEntity(226U);
    msg.setDestination(5043U);
    msg.setDestinationEntity(22U);
    msg.name.assign("DRDFQLBGUQOJVODFKTDDSPJJXGCGTTNUTIJBIXUBUSIWWHRIMOCKGRLZAQFMYTPGRXSDAMBSTTFXWKMAWEVYEPNVOBAFYLAIXBGUBUUIQOPSBVPMZNYTKEHDVMWZQVKNQMGLPLTXIHRCBY");
    msg.visibility.assign("XWACFMFGJEAHQZSIDDNUEVIEPDBZUGXYHDNJRCTZJJKSGLLNJIUXRDPNAPWOFPA");
    msg.scope.assign("AVCGRHJHWUYKFVPFFILRIXO");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityParameters msg;
    msg.setTimeStamp(0.871523182951);
    msg.setSource(48218U);
    msg.setSourceEntity(58U);
    msg.setDestination(15000U);
    msg.setDestinationEntity(164U);
    msg.name.assign("KYQXZGCNZRAZOIPUDTDUJQASVADEVVKBZGKYUXBTGHYTCMGJOEXMURWOHIOLBWIYINEMIBWYACTUJJKKOPUEHWRALFYEBSTDKLMUZSOKHDQRVRJAGNXKQKDHOLXCGRQQHKPHLBMGRVDTJEUAFXJXBF");
    msg.visibility.assign("SKLXGFVSNNDDQUINCXQRLSNPVAYDVEMTQPCRXGIZKXKJJBYASSLCOHDALFQSTSDOGRPXVUJYOFYAAKPUVELFDYPGIZKTIWXYVOVHRCLGHJMKREWOWVTWFGFR");
    msg.scope.assign("LJJCMEQYXZVIWJWQKQBBUEKOTGSRZZERFXJLBGATLYTGPVSJWEKZNITXTDVNNKUY");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::QueryEntityParameters msg;
    msg.setTimeStamp(0.480449599132);
    msg.setSource(6392U);
    msg.setSourceEntity(139U);
    msg.setDestination(60704U);
    msg.setDestinationEntity(165U);
    msg.name.assign("YDSONIUZKBPAVUCZWMNCDZTATMPDMKRPYNWNSHBGCTLRQDFAJLHGSIEAZYOWJDAXWFEPPMLSBJMUOZAJYMVXURJFVUPUTKIZZULEJDNVPQKEMKLCRJHKHFLRBMVBZWEERZOUHYLWQGGQVFXLNTYXJCJQIYFPDTGHKMSSHFWMBOPLEOJWXADXCIWNSFFVBRRTTXXCSDGRZUINHOBOUVQPBKFSCOXENKTNGXWQGVSHHI");
    msg.visibility.assign("XQXELSZDRGKMHMJHTESUKFBFCVKGE");
    msg.scope.assign("KDSCVXDMIRJWIQMZRMTZPFYVJGYIBWRQRJOSOAONHZVFMZQADAMZDCSNEWSCSEDWS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("QueryEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetEntityParameters msg;
    msg.setTimeStamp(0.752899253307);
    msg.setSource(8630U);
    msg.setSourceEntity(60U);
    msg.setDestination(13858U);
    msg.setDestinationEntity(188U);
    msg.name.assign("VOPJOANVLTROPHJEMDSKYYXNSCSCFMTFMQHYZQTWOSUISBWNMDOGKHMNDRUNHSHRDMJIKUZZK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetEntityParameters msg;
    msg.setTimeStamp(0.294880258262);
    msg.setSource(42209U);
    msg.setSourceEntity(203U);
    msg.setDestination(13843U);
    msg.setDestinationEntity(153U);
    msg.name.assign("KAUJNMCGTSAEGGLDPRWXYPIQJHISMFFGXHJTRVSJCHUNHUOZUBUBXJYJCMICAXKNLBKDZGSOEDPSMZYCLU");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SetEntityParameters msg;
    msg.setTimeStamp(0.426491942117);
    msg.setSource(25716U);
    msg.setSourceEntity(39U);
    msg.setDestination(23392U);
    msg.setDestinationEntity(247U);
    msg.name.assign("CQZIZEKNQVQJSRVZTNEFXJAPEAPGWGXTDHTFLQCBBK");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SetEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SaveEntityParameters msg;
    msg.setTimeStamp(0.105764075904);
    msg.setSource(1977U);
    msg.setSourceEntity(234U);
    msg.setDestination(44624U);
    msg.setDestinationEntity(145U);
    msg.name.assign("DLQNHOHDJYTDPEOCMZVAPKSQHNEUYMUTKIEFHKXQV");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SaveEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SaveEntityParameters msg;
    msg.setTimeStamp(0.309928213769);
    msg.setSource(64217U);
    msg.setSourceEntity(174U);
    msg.setDestination(49736U);
    msg.setDestinationEntity(152U);
    msg.name.assign("DSKDDXYIWELWQWDCIVLNYYDZLJZYDXJKQHLSHVALFVAGXOSPVOUNEGNBRUZKTBBCWWIXOVZODHNIZWGJKCKUPHTGIFWLSMSEXUXWDZQFAZTCSKYJUBQSYSXOBTFFXVKNMYFMSPJMMVGPGMPHPGPTFJPHAOELLDFRIKNIRAARGONRRBMRLTQHHQEYKBTJMUIZQLFHCAGJIPCQUQYYUZNJSNKFCMGURVEOXTPCTACX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SaveEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SaveEntityParameters msg;
    msg.setTimeStamp(0.624476465666);
    msg.setSource(354U);
    msg.setSourceEntity(219U);
    msg.setDestination(45827U);
    msg.setDestinationEntity(60U);
    msg.name.assign("ROAZBGXDUSEEMDDYMZHCTJWTENBQPVSZNXGRBRYHNEZLKQQKQKPSLXJVXLDIPBTMLNACAINIDWIDQFLGFXPQCOHAHVUKBGWHZDAZPGHCFBZFWYOBEJHKIGUBYPLHMJMQMYFUYJIAYCVXXZVOORZHCMQLIOOWUIZULCNONDFXVJGYDPTKTESIVETTUYAFRPWCVASGNSRTTEXB");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SaveEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CreateSession msg;
    msg.setTimeStamp(0.484249348517);
    msg.setSource(13678U);
    msg.setSourceEntity(144U);
    msg.setDestination(47757U);
    msg.setDestinationEntity(61U);
    msg.timeout = 3872598144U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CreateSession #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CreateSession msg;
    msg.setTimeStamp(0.3558057319);
    msg.setSource(61641U);
    msg.setSourceEntity(55U);
    msg.setDestination(59912U);
    msg.setDestinationEntity(108U);
    msg.timeout = 3073256702U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CreateSession #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CreateSession msg;
    msg.setTimeStamp(0.190298892535);
    msg.setSource(43036U);
    msg.setSourceEntity(14U);
    msg.setDestination(5258U);
    msg.setDestinationEntity(166U);
    msg.timeout = 1310229069U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CreateSession #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CloseSession msg;
    msg.setTimeStamp(0.942988719687);
    msg.setSource(23441U);
    msg.setSourceEntity(70U);
    msg.setDestination(45153U);
    msg.setDestinationEntity(134U);
    msg.sessid = 1525402335U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CloseSession #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CloseSession msg;
    msg.setTimeStamp(0.276797616952);
    msg.setSource(19315U);
    msg.setSourceEntity(206U);
    msg.setDestination(50093U);
    msg.setDestinationEntity(14U);
    msg.sessid = 1874408759U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CloseSession #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::CloseSession msg;
    msg.setTimeStamp(0.43676419002);
    msg.setSource(48767U);
    msg.setSourceEntity(141U);
    msg.setDestination(12284U);
    msg.setDestinationEntity(168U);
    msg.sessid = 2162876152U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("CloseSession #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionSubscription msg;
    msg.setTimeStamp(0.416453574862);
    msg.setSource(21397U);
    msg.setSourceEntity(199U);
    msg.setDestination(47045U);
    msg.setDestinationEntity(21U);
    msg.sessid = 5146065U;
    msg.messages.assign("EMNOXWZBDETTJWVSHYWQZREPWUAYTMDJAOLBBUNWPRGKOTDVKAXCHTDCGFOSFPHOKYPXCXHIBVQZQZGFRPWHAXMVYDESHWVPVRGMGLFR");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionSubscription #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionSubscription msg;
    msg.setTimeStamp(0.341316218966);
    msg.setSource(33238U);
    msg.setSourceEntity(197U);
    msg.setDestination(22513U);
    msg.setDestinationEntity(209U);
    msg.sessid = 1260140835U;
    msg.messages.assign("DSSSMQNHODDBNYXQAGREOCJQWXLDVENMZZPLBPQWANPAZECGCZQAXGSFIXVFHZHVGETBKHVHJGPDHRIAKYIXNHYWDBYUQPRMISORNJCMOOLVYCGRTOCBQFGIALUUFPLOTFWPFCASGHVORCDUJXZVKKEEBTOSNVKGEBFZGKSLTQXRAWDKAIYYVURMMJEOKXSYTQBXLEUKWISXLRIMZHYUITJMIPMATWCKNWDYBFRCUZNELTJMD");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionSubscription #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionSubscription msg;
    msg.setTimeStamp(0.906333827926);
    msg.setSource(46348U);
    msg.setSourceEntity(43U);
    msg.setDestination(47845U);
    msg.setDestinationEntity(29U);
    msg.sessid = 1034953424U;
    msg.messages.assign("SPMGCRVJUTMSRLIUVJWBOVRINVIOWDRYCALRHGPUXXACSWCDFWYMQFXDRHRQRVNBUXBLNYDKZTNQYJBDCKPTFZUTSWDMPFGCRTITAZSUTCFKFJQEIUVLVBKAFDQGASQHEHCELXTJSVUAVMQHXEZGLSHGBHFEIWXKOPOTEJGKYIGIMLCYKFNZBNXOEPJBQYQJNLUEYDCOHWDKWMTSIJLEYEYFNPUPOPZLMNPNKWGZOQH");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionSubscription #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionKeepAlive msg;
    msg.setTimeStamp(0.373398057728);
    msg.setSource(15467U);
    msg.setSourceEntity(30U);
    msg.setDestination(3061U);
    msg.setDestinationEntity(183U);
    msg.sessid = 4092524533U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionKeepAlive #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionKeepAlive msg;
    msg.setTimeStamp(0.841570291794);
    msg.setSource(5073U);
    msg.setSourceEntity(225U);
    msg.setDestination(43244U);
    msg.setDestinationEntity(61U);
    msg.sessid = 1465909574U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionKeepAlive #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionKeepAlive msg;
    msg.setTimeStamp(0.523234356427);
    msg.setSource(61051U);
    msg.setSourceEntity(213U);
    msg.setDestination(37183U);
    msg.setDestinationEntity(190U);
    msg.sessid = 2892384979U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionKeepAlive #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionStatus msg;
    msg.setTimeStamp(0.458032724758);
    msg.setSource(55840U);
    msg.setSourceEntity(121U);
    msg.setDestination(15811U);
    msg.setDestinationEntity(72U);
    msg.sessid = 1750180292U;
    msg.status = 253U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionStatus #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionStatus msg;
    msg.setTimeStamp(0.560646825385);
    msg.setSource(34326U);
    msg.setSourceEntity(155U);
    msg.setDestination(52924U);
    msg.setDestinationEntity(230U);
    msg.sessid = 3759677206U;
    msg.status = 25U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionStatus #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::SessionStatus msg;
    msg.setTimeStamp(0.865528402936);
    msg.setSource(45382U);
    msg.setSourceEntity(251U);
    msg.setDestination(39414U);
    msg.setDestinationEntity(186U);
    msg.sessid = 3313503526U;
    msg.status = 236U;

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("SessionStatus #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PushEntityParameters msg;
    msg.setTimeStamp(0.634903670701);
    msg.setSource(28168U);
    msg.setSourceEntity(197U);
    msg.setDestination(48555U);
    msg.setDestinationEntity(241U);
    msg.name.assign("TBDGRRKOWZTGXINGBMBFFEGXSBLYVUHLNKGSTAAYFYSQIDURUICVXZJVWQYRMXJQGSJEGWRBPCYPGTPYHZWHQXWAZMJAVNOKOGYUBMPTYJIKSX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PushEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PushEntityParameters msg;
    msg.setTimeStamp(0.269482644415);
    msg.setSource(43129U);
    msg.setSourceEntity(142U);
    msg.setDestination(25067U);
    msg.setDestinationEntity(176U);
    msg.name.assign("MAODPAOHOVWEOUNRZZVNPHRUTIRSYEHSVQGRLMNXJHFFPKNOXSKPALAAUHJBEQXRTLSDAYHALSXZVOVSJCMCPJFQTYGXWDEIZKTOSNEIWBCHTJPDYTICQQKMYNYAMGELTBMIBMOBPNVMRGGFKSCLJRLGFGRYZRENEMVBFGYPTFUFXXGBZDBICNSSWUQWXWLCX");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PushEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PushEntityParameters msg;
    msg.setTimeStamp(0.42348491446);
    msg.setSource(26586U);
    msg.setSourceEntity(128U);
    msg.setDestination(18001U);
    msg.setDestinationEntity(147U);
    msg.name.assign("XELYRBQAONGXGZUZKYNQWAGRUJDLSBTDFOQILZNLAXSMPLWZQNLTDRCWWBOKLTCGFODCPEJJPCEWJCAGYASJZESIDWSOUAUFHYKSGKZQMEMMRQFMBHNMGBQMUUYYZHKXRIJTIEREYIGRQHIDCIFKIIJBVMVQEZTBJODAMPDFTWMNPDLVSCUPGTNNXRUOXBFVNP");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PushEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopEntityParameters msg;
    msg.setTimeStamp(0.551700586588);
    msg.setSource(50845U);
    msg.setSourceEntity(113U);
    msg.setDestination(51692U);
    msg.setDestinationEntity(125U);
    msg.name.assign("UHXLJZRLAMWAYMPAQRBREEQRIBZGNBARXCOKTQYSUPMVHNGZXEDLXGQWTOQBFRYDCVROFVPRIWFVZJMYPJBGDALGITMUBLNQCOVXGUIZASSKVUZXFNDSBQGOPCEQKCQKOMCSPJNVXTOPCTXLDNMJPSRWTIMJJLKZDFJNBDNXHASSGXLYCIZFFWEHOAWKVHPFIYTIVBSHYEGQDDOIUKLAYEZUNHYGKMWEURMAUW");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopEntityParameters #0", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #0", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopEntityParameters msg;
    msg.setTimeStamp(0.689635313245);
    msg.setSource(14834U);
    msg.setSourceEntity(239U);
    msg.setDestination(12739U);
    msg.setDestinationEntity(234U);
    msg.name.assign("NAFQLNWITAZXCBIXIBUJMRYNUONATQHKRTFNSRKFKFKXZCGSLULNRTHQZJSKOPLANRQQGIYZRHQGBKFZWOVUYLEPMKOBZEPXUCDDMOCHAWAUEFFOGDVEJERNPTDGLRDXSWZS");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopEntityParameters #1", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #1", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  {
    IMC::PopEntityParameters msg;
    msg.setTimeStamp(0.651239891079);
    msg.setSource(41017U);
    msg.setSourceEntity(207U);
    msg.setDestination(3767U);
    msg.setDestinationEntity(240U);
    msg.name.assign("VPRPGTDRREJHQWOBGOJLNPUCNZXGMFCPJLCJAHIJVDZCGUMFQWXVLBIFSSFQABYSGDYIUSXDKDJSVXQEHPZVQSBSAZYWUTGQUYLWZLNYLXOEXXHFGILRZAIAOQTSOENXJNBPKIJNASDE");

    try
    {
      Utils::ByteBuffer bfr;
      IMC::Packet::serialize(&msg, bfr);
      IMC::Message* msg_d = IMC::Packet::deserialize(bfr.getBuffer(), bfr.getSize());
      test.boolean("PopEntityParameters #2", msg == *msg_d);
      delete msg_d;
    }
    catch (IMC::InvalidMessageSize& e)
    {
      (void)e;
      test.boolean("msg #2", msg.getSerializationSize() > DUNE_IMC_CONST_MAX_SIZE);
    }
  }

  return test.getReturnValue();
}
