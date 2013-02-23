//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************
// Automatically generated do not edit.                                     *
//***************************************************************************

#ifndef PICCOLO_DEFINITIONS_HPP_INCLUDED_
#define PICCOLO_DEFINITIONS_HPP_INCLUDED_

#include "PiccoloMessage.hpp"

namespace Piccolo
{
  class MovingBase : public PiccoloMessage
  {
  public:
    //!GPS Time Of Week, unit: ms
    uint32_t gps_tow;
    //!North Offset, unit: m
    fp16_t north;
    //!East Offset, unit: m
    fp16_t east;
    //!Down Offset, unit: m
    fp16_t down;
    //!Heading, unit: 0.0001 rad
    uint16_t head;
    //!Ground Speed North, unit: cm/s
    fp16_t vnorth;
    //!Ground Speed East, unit: cm/s
    fp16_t veast;
    //!Ground Speed Down, unit: cm/s
    fp16_t vdown;
    //!Right Hand
    int8_t rhand;

    MovingBase(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 256;
    }

    const char*
    getName(void) const
    {
      return "MovingBase";
    }

    uint16_t
    getId(void) const
    {
      return MovingBase::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class PilotCommandAngle : public PiccoloMessage
  {
  public:
    //!Aileron, unit: mrad
    int16_t aileron;
    //!Elevator, unit: mrad
    int16_t elevator;
    //!Throttle
    int16_t throttle;
    //!Rudder, unit: mrad
    int16_t rudder;
    //!Flap, unit: mrad
    int16_t flap;
    //!Manual
    int8_t manual;
    //!Counter
    int8_t counter;
    //!Brakes
    int16_t brakes;
    //!Parachute
    int16_t parachute;
    //!Ignition
    int8_t ignition;

    PilotCommandAngle(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 512;
    }

    const char*
    getName(void) const
    {
      return "PilotCommandAngle";
    }

    uint16_t
    getId(void) const
    {
      return PilotCommandAngle::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class PilotCommandPulse : public PiccoloMessage
  {
  public:
    //!Aileron
    uint16_t aileron;
    //!Elevator
    uint16_t elevator;
    //!Throttle
    uint16_t throttle;
    //!Rudder
    uint16_t rudder;
    //!Flap
    uint16_t flap;
    //!Manual
    int8_t manual;
    //!Counter
    int8_t counter;
    //!Brakes
    uint16_t brakes;
    //!Parachute
    uint16_t parachute;
    //!Ignition
    int8_t ignition;

    PilotCommandPulse(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 513;
    }

    const char*
    getName(void) const
    {
      return "PilotCommandPulse";
    }

    uint16_t
    getId(void) const
    {
      return PilotCommandPulse::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class UserWarning : public PiccoloMessage
  {
  public:
    //!Packet type
    int8_t type;
    //!Warning code
    int8_t code;

    UserWarning(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 768;
    }

    const char*
    getName(void) const
    {
      return "UserWarning";
    }

    uint16_t
    getId(void) const
    {
      return UserWarning::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class BandwidthMode : public PiccoloMessage
  {
  public:

    BandwidthMode(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 770;
    }

    const char*
    getName(void) const
    {
      return "BandwidthMode";
    }

    uint16_t
    getId(void) const
    {
      return BandwidthMode::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class FeatureCode : public PiccoloMessage
  {
  public:
    //!Code
    uint64_t code;

    FeatureCode(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 771;
    }

    const char*
    getName(void) const
    {
      return "FeatureCode";
    }

    uint16_t
    getId(void) const
    {
      return FeatureCode::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class PayloadMass : public PiccoloMessage
  {
  public:
    //!Mass, unit: kg
    fp32_t mass;

    PayloadMass(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 774;
    }

    const char*
    getName(void) const
    {
      return "PayloadMass";
    }

    uint16_t
    getId(void) const
    {
      return PayloadMass::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ElevationData : public PiccoloMessage
  {
  public:
    //!Time, unit: ms
    uint32_t mass;
    //!Elevation, unit: 0.25 m
    uint16_t elev;
    //!Elevation A, unit: 0.25 m
    uint16_t elev_a;
    //!Elevation B, unit: 0.25 m
    uint16_t elev_b;
    //!Elevation C, unit: 0.25 m
    uint16_t elev_c;
    //!Elevation D, unit: 0.25 m
    uint16_t elev_d;
    //!Elevation E, unit: 0.25 m
    uint16_t elev_e;

    ElevationData(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 775;
    }

    const char*
    getName(void) const
    {
      return "ElevationData";
    }

    uint16_t
    getId(void) const
    {
      return ElevationData::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Waypoint : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Use Pre-Turn Control
      WP1_PRE_TURN = 0x01,
      //! Use Lights
      WP1_LIGHTS = 0x02,
      //! Use Slope Control
      WP1_SLOPE = 0x04,
      //! Use As Land Point
      WP1_LAND = 0x08,
      //! Use As Camera Target
      WP1_CAMERA = 0x10,
      //! Orbit Right
      WP1_ORBIT_RIGHT = 0x20,
      //! Deploy Drop
      WP1_DROP = 0x40,
      //! Deploy Parachute
      WP1_PARACHUTE = 0x80,
      //! AltLSB vel. resolution bit 1
      WP2_ALTLSB1 = 0x01,
      //! AltLSB vel. resolution bit 2
      WP2_ALTLSB2 = 0x02,
      //! AltLSB vel. resolution bit 3
      WP2_ALTLSB3 = 0x04,
      //! Orbit radius multiplier is 50 (instead of 10)
      WP2_ORBITM50 = 0x08,
      //! Altitude Above Ground Level
      WP2_AGL = 0x10,
      //! Hover (helicopters only)
      WP2_HOVER = 0x20,
      //! Orbit Below Altitude
      WP2_BELOW = 0x40,
      //! Orbit Above Altitude
      WP2_ABOVE = 0x80
    };

    //!Latitude, unit: marcs
    int32_t lat;
    //!Longitude, unit: marcs
    int32_t lon;
    //!Flags, unit: Bitmask
    uint8_t flags;
    //!Orbit Radius, unit: m
    uint8_t radius;
    //!Altitude, unit: m
    int16_t altitude;
    //!Wind Find
    uint8_t windfind;
    //!Orbit Time, unit: 10s
    uint8_t time;
    //!Waypoint Index
    uint8_t index;
    //!Next Waypoint Index
    uint8_t next;
    //!User Defined
    uint8_t user;
    //!Orbit Flags, unit: Bitmask
    uint8_t flags2;

    Waypoint(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 776;
    }

    const char*
    getName(void) const
    {
      return "Waypoint";
    }

    uint16_t
    getId(void) const
    {
      return Waypoint::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class WaypointList : public PiccoloMessage
  {
  public:

    WaypointList(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 777;
    }

    const char*
    getName(void) const
    {
      return "WaypointList";
    }

    uint16_t
    getId(void) const
    {
      return WaypointList::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Track : public PiccoloMessage
  {
  public:
    //!Target
    uint8_t target;
    //!Goto
    uint8_t track_goto;

    Track(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 778;
    }

    const char*
    getName(void) const
    {
      return "Track";
    }

    uint16_t
    getId(void) const
    {
      return Track::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class MinThrottle : public PiccoloMessage
  {
  public:
    //!Throttle, unit: 0.001
    int16_t throttle;

    MinThrottle(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 779;
    }

    const char*
    getName(void) const
    {
      return "MinThrottle";
    }

    uint16_t
    getId(void) const
    {
      return MinThrottle::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class MissionSettings : public PiccoloMessage
  {
  public:
    //!Min Altitude, unit: m
    int16_t min_altitude;
    //!Max Altitude, unit: m
    int16_t max_altitude;
    //!Flight Timeout, unit: s
    uint32_t fl_timeout;

    MissionSettings(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 780;
    }

    const char*
    getName(void) const
    {
      return "MissionSettings";
    }

    uint16_t
    getId(void) const
    {
      return MissionSettings::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SensorOrientation : public PiccoloMessage
  {
  public:
    //!Roll, unit: rad
    int32_t roll;
    //!Pitch, unit: rad
    int32_t pitch;
    //!Yaw, unit: rad
    int32_t yaw;
    //!X ant, unit: m
    int32_t x_ant;
    //!Y ant, unit: m
    int32_t y_ant;
    //!Z ant, unit: m
    int32_t z_ant;

    SensorOrientation(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 782;
    }

    const char*
    getName(void) const
    {
      return "SensorOrientation";
    }

    uint16_t
    getId(void) const
    {
      return SensorOrientation::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class AltimeterSetting : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Use GPS altitude
      FLAG_GPS = 0x01,
      //! Use GPS altitude if diff corrected
      FLAG_GPS_DIFF = 0x02
    };

    //!Base Pressure, unit: Pa
    uint32_t base_press;
    //!Flags, unit: Bitmask
    uint8_t flags;

    AltimeterSetting(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 783;
    }

    const char*
    getName(void) const
    {
      return "AltimeterSetting";
    }

    uint16_t
    getId(void) const
    {
      return AltimeterSetting::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SystemReset : public PiccoloMessage
  {
  public:

    SystemReset(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 784;
    }

    const char*
    getName(void) const
    {
      return "SystemReset";
    }

    uint16_t
    getId(void) const
    {
      return SystemReset::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SystemVersion : public PiccoloMessage
  {
  public:
    //!Major Version
    uint8_t major;
    //!Minor Version
    uint8_t minor;
    //!Sub Version
    uint8_t sub;
    //!Test Version
    uint8_t test;
    //!Year
    uint16_t year;
    //!Month
    uint8_t month;
    //!Day
    uint8_t day;
    //!Board Serial Number
    uint32_t bserial;
    //!Features
    uint16_t features;
    //!Board Revision
    uint16_t brevision;
    //!Board Configuration Code
    uint16_t bconfig;
    //!Controller
    uint8_t ctrl;
    //!Controller Version
    uint8_t ctrlversion;
    //!Board Fabrication Year
    uint16_t byear;
    //!Board Fabrication Month
    uint8_t bmonth;
    //!Board Fabrication Day
    uint8_t bday;

    SystemVersion(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 785;
    }

    const char*
    getName(void) const
    {
      return "SystemVersion";
    }

    uint16_t
    getId(void) const
    {
      return SystemVersion::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ResetReport : public PiccoloMessage
  {
  public:

    ResetReport(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 786;
    }

    const char*
    getName(void) const
    {
      return "ResetReport";
    }

    uint16_t
    getId(void) const
    {
      return ResetReport::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SurfaceTest : public PiccoloMessage
  {
  public:
    //!Angle, unit: mrad
    int16_t angle;
    //!Width, unit: us
    uint16_t width;
    //!Surface Index
    int8_t surface;
    //!Frequency, unit: 0.1 Hz
    uint8_t frequency;
    //!Deviation, unit: mrad
    uint16_t deviation;

    SurfaceTest(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 787;
    }

    const char*
    getName(void) const
    {
      return "SurfaceTest";
    }

    uint16_t
    getId(void) const
    {
      return SurfaceTest::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class MissionLimits : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Assertion of flight termination causes the engine to be killed
      FAILURE_KILL = 0x0001,
      //! Drop Deadman if Engine Killed
      FAILURE_DROP_DEADMAN = 0x0002,
      //! Flight termination is asserted when airspace boundary is violated
      FAILURE_AIRSPACE = 0x0010,
      //! Assertion of flight termination causes the deadman output to be dropped
      FAILURE_TRIGGER_DEADMAN = 0x0020,
      //! Assertion of flight termination causes aerodynamic termination
      FAILURE_AEROD_TERM = 0x0040,
      //! Flight timer causes automatic landing in lost communications
      FAILURE_LAND_TIMMER = 0x0080,
      //! Flight termination is asserted when the communications timeouts elapse
      FAILURE_COMM = 0x0100,
      //! Flight termination is asserted when the GPS timeouts elapse
      FAILURE_GPS = 0x0200,
      //! Flight termination is asserted when BOTH the GPS and the communications timeouts elapse
      FAILURE_GPS_COMM = 0x0400,
      //! Flight termination causes parachute deployment
      FAILURE_PARACHUTE = 0x0800
    };

    //!Communications Timeout, unit: ms
    uint32_t comm_timeout;
    //!Pilout Timeout, unit: ms
    uint32_t pilot_timeout;
    //!Lost Communications Waypoint
    uint8_t lost_comm_wpt;
    //!Failure Handling, unit: Bitmask
    uint16_t failure;
    //!Autoland Waypoint
    uint8_t autoland;
    //!GPS Timeout, unit: ms
    uint32_t gps_timeout;
    //!Minimum Altitude, unit: m
    uint16_t min_altitude;
    //!Maximum Altitude, unit: m
    uint16_t max_altitude;
    //!Flight Timeout, unit: s
    uint32_t flight_timeout;

    MissionLimits(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 788;
    }

    const char*
    getName(void) const
    {
      return "MissionLimits";
    }

    uint16_t
    getId(void) const
    {
      return MissionLimits::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class UserAction : public PiccoloMessage
  {
  public:
    //!Action Index
    int8_t action;
    //!Do
    int8_t do_action;

    UserAction(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 790;
    }

    const char*
    getName(void) const
    {
      return "UserAction";
    }

    uint16_t
    getId(void) const
    {
      return UserAction::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class AutopilotLoop : public PiccoloMessage
  {
  public:
    enum EnumAutopilotLoop
    {
      //! Indicated Air Speed
      LOOP_IAS = 0,
      //! Altitude
      LOOP_ALT = 1,
      //! Bank
      LOOP_BANK = 2,
      //! Flaps
      LOOP_FLAP = 3,
      //! Heading
      LOOP_HEAD = 4,
      //! Vertical rate
      LOOP_VRATE = 5,
      //! Pitch
      LOOP_PITCH = 6,
      //! Off
      LOOP_CTRL_OFF = 0,
      //! On
      LOOP_CTRL_ON = 1,
      //! Auto
      LOOP_CTRL_AUTO = 2
    };

    //!Loop Identifier, unit: Enumerated
    uint8_t id;
    //!Loop Control, unit: Enumerated
    uint8_t control;
    //!Reserved
    uint16_t reserved;
    //!Command Value
    fp32_t value;
    //!Updated EEPROM
    uint8_t UpdateEEPROM;

    AutopilotLoop(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 792;
    }

    const char*
    getName(void) const
    {
      return "AutopilotLoop";
    }

    uint16_t
    getId(void) const
    {
      return AutopilotLoop::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class AutoFlareDisable : public PiccoloMessage
  {
  public:
    //!Disable
    uint8_t Disable;
    //!Supress Warning
    uint8_t SupressWarning;

    AutoFlareDisable(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 793;
    }

    const char*
    getName(void) const
    {
      return "AutoFlareDisable";
    }

    uint16_t
    getId(void) const
    {
      return AutoFlareDisable::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Description : public PiccoloMessage
  {
  public:

    Description(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 794;
    }

    const char*
    getName(void) const
    {
      return "Description";
    }

    uint16_t
    getId(void) const
    {
      return Description::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class UserSpace : public PiccoloMessage
  {
  public:

    UserSpace(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 795;
    }

    const char*
    getName(void) const
    {
      return "UserSpace";
    }

    uint16_t
    getId(void) const
    {
      return UserSpace::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ManualFlare : public PiccoloMessage
  {
  public:

    ManualFlare(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 796;
    }

    const char*
    getName(void) const
    {
      return "ManualFlare";
    }

    uint16_t
    getId(void) const
    {
      return ManualFlare::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class MagneticCalibration : public PiccoloMessage
  {
  public:

    MagneticCalibration(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 798;
    }

    const char*
    getName(void) const
    {
      return "MagneticCalibration";
    }

    uint16_t
    getId(void) const
    {
      return MagneticCalibration::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class EngineKill : public PiccoloMessage
  {
  public:
    //!Kill
    uint8_t kill;
    //!Reserved
    uint8_t reserved;

    EngineKill(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 799;
    }

    const char*
    getName(void) const
    {
      return "EngineKill";
    }

    uint16_t
    getId(void) const
    {
      return EngineKill::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class RadioTransmitDisable : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Disable MHX Radio
      RADIO_MHX = 0x0001
    };

    //!Radio, unit: Bitmask
    uint16_t radio;

    RadioTransmitDisable(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 800;
    }

    const char*
    getName(void) const
    {
      return "RadioTransmitDisable";
    }

    uint16_t
    getId(void) const
    {
      return RadioTransmitDisable::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class RadioSettings : public PiccoloMessage
  {
  public:
    enum EnumRadioSettings
    {
      //! Default
      SPEED_DEFAULT = 0,
      //! Narrow Band
      SPEED_NARROW = 1,
      //! Reserved
      SPEED_RESERVED = 2,
      //! Wide Band
      SPEED_WIDE = 3,
      //! 900 MHz ISM
      RADIO_MHX_910 = 0,
      //! 2.4 GHz ISM
      RADIO_MHX_2400 = 1,
      //! Next Gen. 900 MHz ISM
      RADIO_MHX_920 = 2,
      //! Next Gen. 2.4 GHz ISM
      RADIO_MHX_2420 = 3,
      //! 450 MHz Coherent Frequency
      RADIO_MHX_420 = 4,
      //! 350 MHz Coherent Frequency
      RADIO_MHX_320 = 5,
      //! 1.3 GHz Coherent Frequency
      RADIO_MHX_1320 = 6,
      //! Extend 900 Mhz Maxstream radio
      RADIO_EXTEND_900 = 7
    };

    //!Channel
    uint8_t channel;
    //!Power, unit: 10 mW
    uint8_t power;
    //!Speed, unit: Enumerated
    uint8_t speed;
    //!Radio Type, unit: Enumerated
    uint8_t radio;
    //!Frequency, unit: MHz
    fp32_t frequency;

    RadioSettings(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 801;
    }

    const char*
    getName(void) const
    {
      return "RadioSettings";
    }

    uint16_t
    getId(void) const
    {
      return RadioSettings::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ExternalSerialSetup : public PiccoloMessage
  {
  public:

    ExternalSerialSetup(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 802;
    }

    const char*
    getName(void) const
    {
      return "ExternalSerialSetup";
    }

    uint16_t
    getId(void) const
    {
      return ExternalSerialSetup::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ExternalIOSetup : public PiccoloMessage
  {
  public:

    ExternalIOSetup(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 803;
    }

    const char*
    getName(void) const
    {
      return "ExternalIOSetup";
    }

    uint16_t
    getId(void) const
    {
      return ExternalIOSetup::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ExternalIOSample : public PiccoloMessage
  {
  public:
    //!Sample 0
    uint32_t sample_0;
    //!Sample 1
    uint32_t sample_1;
    //!Sample 2
    uint32_t sample_2;
    //!Sample 3
    uint32_t sample_3;
    //!Sample 4
    uint32_t sample_4;
    //!Sample 5
    uint32_t sample_5;
    //!Sample 6
    uint32_t sample_6;
    //!Sample 7
    uint32_t sample_7;
    //!Sample 8
    uint32_t sample_8;
    //!Sample 9
    uint32_t sample_9;
    //!Sample 10
    uint32_t sample_10;
    //!Sample 11
    uint32_t sample_11;
    //!Sample 12
    uint32_t sample_12;
    //!Sample 13
    uint32_t sample_13;
    //!Sample 14
    uint32_t sample_14;
    //!Sample 15
    uint32_t sample_15;

    ExternalIOSample(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 804;
    }

    const char*
    getName(void) const
    {
      return "ExternalIOSample";
    }

    uint16_t
    getId(void) const
    {
      return ExternalIOSample::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ExternalADCSample : public PiccoloMessage
  {
  public:
    //!Sample 0
    uint32_t sample_0;
    //!Sample 1
    uint32_t sample_1;
    //!Sample 2
    uint32_t sample_2;
    //!Sample 3
    uint32_t sample_3;

    ExternalADCSample(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 806;
    }

    const char*
    getName(void) const
    {
      return "ExternalADCSample";
    }

    uint16_t
    getId(void) const
    {
      return ExternalADCSample::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class LandNow : public PiccoloMessage
  {
  public:

    LandNow(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 807;
    }

    const char*
    getName(void) const
    {
      return "LandNow";
    }

    uint16_t
    getId(void) const
    {
      return LandNow::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class CreateSimpleLanding : public PiccoloMessage
  {
  public:
    //!Latitude, unit: marcs
    int32_t lat;
    //!Longitude, unit: marcs
    int32_t lon;
    //!Altitude, unit: cm
    int32_t alt;
    //!Heading, unit: 0.01 deg
    int16_t head;
    //!CCW Direction
    int8_t ccw_direction;
    //!Start Waypoint
    int8_t start;

    CreateSimpleLanding(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 811;
    }

    const char*
    getName(void) const
    {
      return "CreateSimpleLanding";
    }

    uint16_t
    getId(void) const
    {
      return CreateSimpleLanding::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class AirDataZero : public PiccoloMessage
  {
  public:
    //!Altitude, unit: cm
    int32_t alt;

    AirDataZero(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 813;
    }

    const char*
    getName(void) const
    {
      return "AirDataZero";
    }

    uint16_t
    getId(void) const
    {
      return AirDataZero::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class PreLaunchMode : public PiccoloMessage
  {
  public:

    PreLaunchMode(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 814;
    }

    const char*
    getName(void) const
    {
      return "PreLaunchMode";
    }

    uint16_t
    getId(void) const
    {
      return PreLaunchMode::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ManualAssistMode : public PiccoloMessage
  {
  public:
    enum EnumManualAssistMode
    {
      //! No assist
      MODE_MA_STANDARD = 0,
      //! Aileron stick is used for assist
      MODE_MA_LATERAL = 1,
      //! Elevator stick is used for assist
      MODE_MA_LONGITUDINAL = 2,
      //! All sticks are used for assist
      MODE_MA_ALL = 3,
      //! Flies based on TASE gimbal orientation
      MODE_GA_SENSOR_NAV = 4
    };

    //!Mode, unit: Enumerated
    uint8_t mode;
    //!Reserved
    uint8_t reserved;

    ManualAssistMode(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 815;
    }

    const char*
    getName(void) const
    {
      return "ManualAssistMode";
    }

    uint16_t
    getId(void) const
    {
      return ManualAssistMode::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Lights : public PiccoloMessage
  {
  public:
    //!Enable
    uint8_t enable;

    Lights(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 816;
    }

    const char*
    getName(void) const
    {
      return "Lights";
    }

    uint16_t
    getId(void) const
    {
      return Lights::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Brake : public PiccoloMessage
  {
  public:
    //!Brake Actuation
    uint16_t value;

    Brake(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 817;
    }

    const char*
    getName(void) const
    {
      return "Brake";
    }

    uint16_t
    getId(void) const
    {
      return Brake::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Parachute : public PiccoloMessage
  {
  public:
    //!Enable
    uint8_t enable;

    Parachute(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 818;
    }

    const char*
    getName(void) const
    {
      return "Parachute";
    }

    uint16_t
    getId(void) const
    {
      return Parachute::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Drop : public PiccoloMessage
  {
  public:
    //!Enable
    uint8_t enable;

    Drop(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 819;
    }

    const char*
    getName(void) const
    {
      return "Drop";
    }

    uint16_t
    getId(void) const
    {
      return Drop::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ThrottleTrim : public PiccoloMessage
  {
  public:

    ThrottleTrim(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 820;
    }

    const char*
    getName(void) const
    {
      return "ThrottleTrim";
    }

    uint16_t
    getId(void) const
    {
      return ThrottleTrim::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class TransponderControl : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Trigger a transponder ident
      FLAG_IDENT = 0x01,
      //! Reserved
      FLAG_RESERVED = 0x0E,
      //! Transponder mode
      FLAG_MODE = 0xF0
    };

    //!Squawk code
    uint16_t code;
    //!Mode flags, unit: Bitmask
    uint8_t flags;

    TransponderControl(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 827;
    }

    const char*
    getName(void) const
    {
      return "TransponderControl";
    }

    uint16_t
    getId(void) const
    {
      return TransponderControl::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class RawVibrationData : public PiccoloMessage
  {
  public:

    RawVibrationData(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 829;
    }

    const char*
    getName(void) const
    {
      return "RawVibrationData";
    }

    uint16_t
    getId(void) const
    {
      return RawVibrationData::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class VibrationData : public PiccoloMessage
  {
  public:

    VibrationData(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 830;
    }

    const char*
    getName(void) const
    {
      return "VibrationData";
    }

    uint16_t
    getId(void) const
    {
      return VibrationData::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class LinkBridge : public PiccoloMessage
  {
  public:

    LinkBridge(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 831;
    }

    const char*
    getName(void) const
    {
      return "LinkBridge";
    }

    uint16_t
    getId(void) const
    {
      return LinkBridge::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class DoubletCommand : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Doublet Deflection Symmetry
      DATA_SymmetricDeflection = 0x80,
      //! Disable all control loops
      DATA_DisableAllCtrl = 0x40,
      //! Axis Doublet
      DATA_Axis = 0xF0
    };

    //!Flags, unit: Bitmask
    uint8_t flags;
    //!Doublet Duration, unit: s
    uint8_t Duration;
    //!Pulse Duration, unit: ms
    uint16_t Pulse;
    //!Doublet Center
    int16_t Center;
    //!Pulse Delta
    int16_t Delta;

    DoubletCommand(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 832;
    }

    const char*
    getName(void) const
    {
      return "DoubletCommand";
    }

    uint16_t
    getId(void) const
    {
      return DoubletCommand::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class DoubletAPData : public PiccoloMessage
  {
  public:
    //!Sample Index
    uint16_t SampleIndex;
    //!Sample Rate, unit: Hz
    uint16_t SampleRate;
    //!Sample Total
    uint16_t SampleTotal;
    //!Left Motor RPM, unit: rpm
    uint16_t LeftRPM;
    //!Right Motor RPM, unit: rpm
    uint16_t RightRPM;
    //!Roll
    int16_t Roll;
    //!Pitch
    int16_t Pitch;
    //!Yaw
    int16_t Yaw;
    //!Aileron
    int16_t Aileron;
    //!Elevator
    int16_t Elevator;
    //!Throttle
    int16_t Throttle;
    //!Rudder
    int16_t Rudder;
    //!Flaps
    int16_t Flaps;

    DoubletAPData(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 833;
    }

    const char*
    getName(void) const
    {
      return "DoubletAPData";
    }

    uint16_t
    getId(void) const
    {
      return DoubletAPData::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class DoubletSensorData : public PiccoloMessage
  {
  public:
    //!Sample Index
    uint16_t SampleIndex;
    //!Sample Rate, unit: Hz
    uint16_t SampleRate;
    //!Sample Total
    uint16_t SampleTotal;
    //!Roll Rate
    int16_t RollRate;
    //!Pitch Rate
    int16_t PitchRate;
    //!Yaw Rate
    int16_t YawRate;
    //!Dynamic Pressure, unit: Pa
    int16_t DynP;
    //!Static Pressure
    uint16_t StatP;
    //!Acceleration in X axis
    int16_t XAccel;
    //!Acceleration in Y axis
    int16_t YAccel;
    //!Acceleration in Z axis
    int16_t ZAccel;
    //!Analog input A
    uint16_t AnalogA;
    //!Analog input B
    uint16_t AnalogB;
    //!Analog input C
    uint16_t AnalogC;
    //!Analog input D
    uint16_t AnalogD;

    DoubletSensorData(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 834;
    }

    const char*
    getName(void) const
    {
      return "DoubletSensorData";
    }

    uint16_t
    getId(void) const
    {
      return DoubletSensorData::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ControllerDataRequest : public PiccoloMessage
  {
  public:
    //!Controller Id Value
    uint8_t CtrlId;
    //!Controller Version
    uint8_t CtrlVers;
    //!Data Category
    uint8_t Category;
    //!Starting Data Id
    uint8_t DataId;
    //!Number of Data Elements
    uint8_t NumData;

    ControllerDataRequest(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 835;
    }

    const char*
    getName(void) const
    {
      return "ControllerDataRequest";
    }

    uint16_t
    getId(void) const
    {
      return ControllerDataRequest::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ControllerData : public PiccoloMessage
  {
  public:
    //!Controller Id Value
    uint8_t CtrlId;
    //!Controller Version
    uint8_t CtrlVers;
    //!Data Category
    uint8_t Category;
    //!Starting Data Id
    uint8_t DataId;
    //!Controller Data
    fp32_t CtrlData;

    ControllerData(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 836;
    }

    const char*
    getName(void) const
    {
      return "ControllerData";
    }

    uint16_t
    getId(void) const
    {
      return ControllerData::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class TelemetryHighRes : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! GPS Data
      DATA_GPS = 0x8000,
      //! Sensor Data
      DATA_SENSOR = 0x4000,
      //! Raw Sensor Data
      DATA_RAW_SENSOR = 0x2000,
      //! Magnetomer Data
      DATA_MAGNETOMER = 0x1000,
      //! AGL Data
      DATA_AGL = 0x0800,
      //! Fuel Data
      DATA_FUEL = 0x0400,
      //! AGL Data is Laser
      DATA_LASER = 0x0200,
      //! 0 cm, 1 dm
      DATA_BARALTUNIT = 0x0100,
      //! Number Of Actuators
      DATA_NUM_ACT = 0x003F,
      //! Altitude Too Low
      LIM_LOW_ALTITUDE = 0x8000,
      //! High Altitude Too High
      LIM_HIGH_ALTITUDE = 0x4000,
      //! Speed Too Low
      LIM_LOW_SPEED = 0x2000,
      //! Speed Too High
      LIM_HIGH_SPEED = 0x1000,
      //! Roll Angle Too Large
      LIM_LARGE_ROLL = 0x0800,
      //! Pitch Angle Too Large
      LIM_LARGE_PITCH = 0x0400,
      //! Engine RPM Too Low
      LIM_LOW_RPM = 0x0200,
      //! Engine RPM Too High
      LIM_HIGH_RPM = 0x0100,
      //! Excessive Wind
      LIM_EXC_WIND = 0x0080,
      //! AGL Too Low
      LIM_LOW_AGL = 0x0040,
      //! Dilution of precision, in units of 0.2 DOP
      GPS_DOP = 0xFC00,
      //! Number of visible satellites
      GPS_VISIBLE_SATS = 0x03E0,
      //! Number of tracked satellites
      GPS_TRACKED_SATS = 0x001F,
      //! 3D (=0xE000), 2D (=0xC000), Aquiring (=0x6000)
      GPS_FIX_TYPE = 0xE000
    };

    //!Data Flags, unit: Bitmask
    uint16_t data_flags;
    //!Limits, unit: Bitmask
    uint16_t limits;
    //!Time, unit: ms
    uint32_t time;
    //!Latitude, unit: marcs
    int32_t lat;
    //!Longitude, unit: marcs
    int32_t lon;
    //!Height, unit: cm
    uint24_t height;
    //!Reserved
    uint8_t reserved;
    //!Sattelite Status, unit: Bitmask
    uint16_t sat_status;
    //!Ground Speed North, unit: cm/s
    int16_t vnorth;
    //!Ground Speed East, unit: cm/s
    int16_t veast;
    //!Ground Speed Down, unit: cm/s
    int16_t vdown;
    //!GPS Status, unit: Bitmask
    uint16_t gps_status;
    //!GPS Week
    uint16_t gps_week;
    //!GPS Time Of Week, unit: ms
    uint32_t gps_tow;
    //!Roll, unit: 1/10000 radian
    int16_t roll;
    //!Pitch, unit: 1/10000 radian
    int16_t pitch;
    //!Yaw, unit: 1/10000 radian
    int16_t yaw;
    //!Barometric Altitude old, unit: cm
    int16_t altitude_old;
    //!Wind Speed South, unit: cm/s
    int16_t wind_south;
    //!Wind Speed West, unit: cm/s
    int16_t wind_west;
    //!Left RPM, unit: rpm
    uint16_t left_rpm;
    //!Right RPM, unit: rpm
    uint16_t right_rpm;
    //!Density Ratio, unit: 1/200 ths
    uint8_t density_ratio;
    //!Outside Air Temperature, unit: deg C
    int8_t oat;
    //!Indicated Air Speed (IAS), unit: cm/s
    uint16_t ias;
    //!Static Pressure, unit: 2 Pa
    uint16_t static_pressure;
    //!Roll Rate, unit: 1/10000 rad/s
    int16_t p;
    //!Pitch Rate, unit: 1/10000 rad/s
    int16_t q;
    //!Yaw Rate, unit: 1/10000 rad/s
    int16_t r;
    //!X-axis Accelaration, unit: cm/s^2
    int16_t x_accel;
    //!Y-axis Accelaration, unit: cm/s^2
    int16_t y_accel;
    //!Z-axis Accelaration, unit: cm/s^2
    int16_t z_accel;
    //!Magnetic Field X-axis, unit: 0.0001 Gauss
    int16_t mag_x;
    //!Magnetic Field Y-axis, unit: 0.0001 Gauss
    int16_t mag_y;
    //!Magnetic Field Z-axis, unit: 0.0001 Gauss
    int16_t mag_z;
    //!Compass, unit: 0.0001 radian
    uint16_t compass;
    //!Altitude above Ground Level (AGL), unit: 0.01 m
    uint16_t agl;
    //!Actuator 0
    int16_t act0;
    //!Actuator 1
    int16_t act1;
    //!Actuator 2
    int16_t act2;
    //!Actuator 3
    int16_t act3;
    //!Actuator 4
    int16_t act4;
    //!Actuator 5
    int16_t act5;
    //!Actuator 6
    int16_t act6;
    //!Actuator 7
    int16_t act7;
    //!Actuator 8
    int16_t act8;
    //!Actuator 9
    int16_t act9;
    //!Actuator 10
    int16_t act10;
    //!Actuator 11
    int16_t act11;
    //!Actuator 12
    int16_t act12;
    //!Actuator 13
    int16_t act13;
    //!Actuator 14
    int16_t act14;
    //!Actuator 15
    int16_t act15;
    //!Fuel Flow
    fp16_t fuel_flow;
    //!Fuel
    fp16_t fuel;
    //!Weight on Wheel, Ground Contact
    uint8_t wow_gc;
    //!Barometric Altitude, unit: cm
    uint24_t altitude;

    TelemetryHighRes(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 837;
    }

    const char*
    getName(void) const
    {
      return "TelemetryHighRes";
    }

    uint16_t
    getId(void) const
    {
      return TelemetryHighRes::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class TelemetryLowRes : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! GPS Data
      DATA_GPS = 0x8000,
      //! Sensor Data
      DATA_SENSOR = 0x4000,
      //! Raw Sensor Data
      DATA_RAW_SENSOR = 0x2000,
      //! Magnetomer Data
      DATA_MAGNETOMER = 0x1000,
      //! AGL Data
      DATA_AGL = 0x0800,
      //! Fuel Data
      DATA_FUEL = 0x0400,
      //! AGL Data is Laser
      DATA_LASER = 0x0200,
      //! 0 cm, 1 dm
      DATA_BARALTUNIT = 0x0100,
      //! Number Of Actuators
      DATA_NUM_ACT = 0x003F,
      //! Altitude Too Low
      LIM_LOW_ALTITUDE = 0x8000,
      //! High Altitude Too High
      LIM_HIGH_ALTITUDE = 0x4000,
      //! Speed Too Low
      LIM_LOW_SPEED = 0x2000,
      //! Speed Too High
      LIM_HIGH_SPEED = 0x1000,
      //! Roll Angle Too Large
      LIM_LARGE_ROLL = 0x0800,
      //! Pitch Angle Too Large
      LIM_LARGE_PITCH = 0x0400,
      //! Engine RPM Too Low
      LIM_LOW_RPM = 0x0200,
      //! Engine RPM Too High
      LIM_HIGH_RPM = 0x0100,
      //! Excessive Wind
      LIM_EXC_WIND = 0x0080,
      //! AGL Too Low
      LIM_LOW_AGL = 0x0040
    };

    //!Data Flags, unit: Bitmask
    uint16_t data_flags;
    //!Limits, unit: Bitmask
    uint16_t limits;
    //!Time, unit: ms
    uint24_t time;
    //!Latitude, unit: marcs
    uint24_t lat;
    //!Longitude, unit: marcs
    uint24_t lon;
    //!Height, unit: cm
    uint16_t height;
    //!Sattelite Status
    uint16_t sat_status;
    //!Ground Speed North, unit: m/s
    int8_t vnorth;
    //!Ground Speed East, unit: m/s
    int8_t veast;
    //!Ground Speed Down, unit: m/s
    int8_t vdown;
    //!GPS Status
    uint16_t gps_status;
    //!GPS Week
    uint32_t gps_week;
    //!GPS Time Of Week, unit: ms
    uint16_t gps_tow;
    //!Roll, unit: 360/256 degree
    int8_t roll;
    //!Pitch, unit: 360/256 degree
    int8_t pitch;
    //!Yaw, unit: 360/256 degree
    int8_t yaw;
    //!Barometric Altitude, unit: 0.5 m
    int8_t altitude_old;
    //!Wind Speed South, unit: 0.5 m
    int8_t wind_south;
    //!Wind Speed West, unit: 0.5 m
    int8_t wind_west;
    //!Left RPM, unit: 50 rpm
    uint8_t left_rpm;
    //!Right RPM, unit: 50 rpm
    uint8_t right_rpm;
    //!Density Ratio, unit: 1/200 ths
    uint8_t density_ratio;
    //!Outside Air Temperature, unit: deg C
    int8_t oat;
    //!Indicated Air Speed (IAS), unit: m/s
    uint8_t ias;
    //!Static Pressure, unit: 2 Pa
    uint16_t static_pressure;
    //!Roll Rate, unit: 2 deg/s
    int8_t p;
    //!Pitch Rate, unit: 2 deg/s
    int8_t q;
    //!Yaw Rate, unit: 2 deg/s
    int8_t r;
    //!X-axis Accelaration, unit: 0.2 m/s^2
    int8_t x_accel;
    //!Y-axis Accelaration, unit: 0.2 m/s^2
    int8_t y_accel;
    //!Z-axis Accelaration, unit: 0.2 m/s^2
    int8_t z_accel;
    //!Magnetic Field X-axis, unit: 0.01 Gauss
    int8_t mag_x;
    //!Magnetic Field Y-axis, unit: 0.01 Gauss
    int8_t mag_y;
    //!Magnetic Field Z-axis, unit: 0.01 Gauss
    int8_t mag_z;
    //!Compass
    uint8_t compass;
    //!Altitude above Ground Level (AGL), unit: 0.1 m
    uint8_t agl;
    //!Actuator 0
    int8_t act0;
    //!Actuator 1
    int8_t act1;
    //!Actuator 2
    int8_t act2;
    //!Actuator 3
    int8_t act3;
    //!Actuator 4
    int8_t act4;
    //!Actuator 5
    int8_t act5;
    //!Actuator 6
    int8_t act6;
    //!Actuator 7
    int8_t act7;
    //!Actuator 8
    int8_t act8;
    //!Actuator 9
    int8_t act9;
    //!Actuator 10
    int8_t act10;
    //!Actuator 11
    int8_t act11;
    //!Actuator 12
    int8_t act12;
    //!Actuator 13
    int8_t act13;
    //!Actuator 14
    int8_t act14;
    //!Actuator 15
    int8_t act15;
    //!Fuel Flow
    uint16_t fuel_flow;
    //!Fuel
    uint16_t fuel;
    //!Barometric Altitude, unit: 0.5 m
    uint16_t altitude;
    //!Weight on Wheel, Ground Contact
    uint8_t wow_gc;

    TelemetryLowRes(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 838;
    }

    const char*
    getName(void) const
    {
      return "TelemetryLowRes";
    }

    uint16_t
    getId(void) const
    {
      return TelemetryLowRes::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SystemStatusHighRes : public PiccoloMessage
  {
  public:
    enum FlagsBits
    {
      //! Main Current in 1/1000 Amp
      PWR_M_CURR = 0x00F0FF,
      //! Main Voltage in 1/100 Volt
      PWR_M_VOLT = 0xFF0F00,
      //! Servo Current in 1/1000 Amp
      PWR_S_CURR = 0x00F0FF,
      //! Servo Voltage in 1/100 Volt
      PWR_S_VOLT = 0xFF0F00,
      //! First stage converter voltage
      BAD_V_1ST = 0x80,
      //! 5.0 digital voltage
      BAD_V_DIG = 0x40,
      //! 5.0 analog voltage
      BAD_V_ANA = 0x20,
      //! CPU voltage
      BAD_V_CPU = 0x10,
      //! GPS voltage
      BAD_V_GPS = 0x08,
      //! System is orbiting
      TRACK_ORB = 0x0080,
      //! ETA to waypoint in seconds, if orbit is untimed this value is zero
      TRACK_ETA = 0xFF7F
    };

    //!Main Power, unit: Bitmask
    uint24_t power_main;
    //!Servo Power, unit: Bitmask
    uint24_t power_servo;
    //!Bad Voltage, unit: Bitmask
    uint8_t voltage_bad;
    //!Board Temperature, unit: deg C
    int8_t temp_board;
    //!Not implemented
    uint64_t reserved1;
    //!Not implemented
    uint64_t reserved2;
    //!Not implemented
    uint32_t reserved3;
    //!Track Status, unit: Bitmask
    uint16_t track_status;
    //!Not implemented
    uint16_t reserved4;
    //!Not implemented
    uint64_t reserved5;
    //!Target waypoint
    uint8_t waypoint_to;

    SystemStatusHighRes(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 839;
    }

    const char*
    getName(void) const
    {
      return "SystemStatusHighRes";
    }

    uint16_t
    getId(void) const
    {
      return SystemStatusHighRes::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SystemStatusLowRes : public PiccoloMessage
  {
  public:

    SystemStatusLowRes(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 840;
    }

    const char*
    getName(void) const
    {
      return "SystemStatusLowRes";
    }

    uint16_t
    getId(void) const
    {
      return SystemStatusLowRes::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class LaunchNow : public PiccoloMessage
  {
  public:

    LaunchNow(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 841;
    }

    const char*
    getName(void) const
    {
      return "LaunchNow";
    }

    uint16_t
    getId(void) const
    {
      return LaunchNow::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class ControllerDataDefault : public PiccoloMessage
  {
  public:

    ControllerDataDefault(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 842;
    }

    const char*
    getName(void) const
    {
      return "ControllerDataDefault";
    }

    uint16_t
    getId(void) const
    {
      return ControllerDataDefault::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SetFuelLevel : public PiccoloMessage
  {
  public:
    //!Is Electric
    int8_t electric;
    //!Reserved 1
    int8_t reserved1;
    //!Reserved 2
    int8_t reserved2;
    //!Reserved 3
    int8_t reserved3;
    //!Fuel Level
    fp32_t fuel;

    SetFuelLevel(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 843;
    }

    const char*
    getName(void) const
    {
      return "SetFuelLevel";
    }

    uint16_t
    getId(void) const
    {
      return SetFuelLevel::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SensorError : public PiccoloMessage
  {
  public:

    SensorError(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 844;
    }

    const char*
    getName(void) const
    {
      return "SensorError";
    }

    uint16_t
    getId(void) const
    {
      return SensorError::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class Abort : public PiccoloMessage
  {
  public:

    Abort(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 845;
    }

    const char*
    getName(void) const
    {
      return "Abort";
    }

    uint16_t
    getId(void) const
    {
      return Abort::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class MovingBaselineStatus : public PiccoloMessage
  {
  public:

    MovingBaselineStatus(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 846;
    }

    const char*
    getName(void) const
    {
      return "MovingBaselineStatus";
    }

    uint16_t
    getId(void) const
    {
      return MovingBaselineStatus::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class SetFuelIfLocked : public PiccoloMessage
  {
  public:

    SetFuelIfLocked(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 847;
    }

    const char*
    getName(void) const
    {
      return "SetFuelIfLocked";
    }

    uint16_t
    getId(void) const
    {
      return SetFuelIfLocked::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class AddAddress : public PiccoloMessage
  {
  public:
    //!Address
    uint16_t address;

    AddAddress(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1024;
    }

    const char*
    getName(void) const
    {
      return "AddAddress";
    }

    uint16_t
    getId(void) const
    {
      return AddAddress::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class DelAddress : public PiccoloMessage
  {
  public:
    //!Address
    uint16_t address;

    DelAddress(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1025;
    }

    const char*
    getName(void) const
    {
      return "DelAddress";
    }

    uint16_t
    getId(void) const
    {
      return DelAddress::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class PilotAddress : public PiccoloMessage
  {
  public:
    //!Address
    uint16_t address;

    PilotAddress(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1026;
    }

    const char*
    getName(void) const
    {
      return "PilotAddress";
    }

    uint16_t
    getId(void) const
    {
      return PilotAddress::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class DGPSCorrection : public PiccoloMessage
  {
  public:
    //!Latitude, unit: marcs
    int32_t lat;
    //!Longitude, unit: marcs
    int32_t lon;
    //!Height, unit: cm
    int32_t height;
    //!Enable
    int8_t enable;
    //!Moving
    int8_t moving;
    //!North Offset, unit: m
    fp16_t north;
    //!East Offset, unit: m
    fp16_t east;
    //!Down Offset, unit: m
    fp16_t down;
    //!Heading, unit: 0.0001 rad
    uint16_t head;
    //!Right Hand
    int8_t rhand;
    //!Absolute Heading
    int8_t abs_head;

    DGPSCorrection(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1027;
    }

    const char*
    getName(void) const
    {
      return "DGPSCorrection";
    }

    uint16_t
    getId(void) const
    {
      return DGPSCorrection::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class GSSystemVersion : public PiccoloMessage
  {
  public:
    //!Major Version
    uint8_t major;
    //!Minor Version
    uint8_t minor;
    //!Sub Version
    uint8_t sub;
    //!Released
    uint8_t released;
    //!Year
    uint16_t year;
    //!Month
    uint8_t month;
    //!Day
    uint8_t day;
    //!Board Serial Number
    uint32_t bserial;
    //!Board Revision
    uint32_t brevision;
    //!Board Configuration Code
    uint32_t bconfig;
    //!Board Fabrication Year
    uint16_t byear;
    //!Board Fabrication Month
    uint8_t bmonth;
    //!Board Fabrication Day
    uint8_t bday;

    GSSystemVersion(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1028;
    }

    const char*
    getName(void) const
    {
      return "GSSystemVersion";
    }

    uint16_t
    getId(void) const
    {
      return GSSystemVersion::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class RequestConfig : public PiccoloMessage
  {
  public:

    RequestConfig(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1029;
    }

    const char*
    getName(void) const
    {
      return "RequestConfig";
    }

    uint16_t
    getId(void) const
    {
      return RequestConfig::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class GroundStationTelemetry : public PiccoloMessage
  {
  public:
    //!Latitude, unit: marcs
    int32_t lat;
    //!Longitude, unit: marcs
    int32_t lon;
    //!Height Above WGS84, unit: cm
    int32_t height;
    //!Ground Speed North, unit: cm/s
    int16_t vnorth;
    //!Ground Speed East, unit: cm/s
    int16_t veast;
    //!GPS Tracked Satellites
    uint8_t gps_tracked_sat;
    //!GPS Visible Sattelites
    uint8_t gps_visible_sat;
    //!GPS DOP
    uint16_t gps_dop;
    //!GPS Status
    uint16_t gps_status;
    //!GPS Time - Year
    uint16_t gps_year;
    //!GPS Time - Month
    uint8_t gps_month;
    //!GPS Time - Day
    uint8_t gps_day;
    //!GPS Time - Hour
    uint8_t gps_hour;
    //!GPS Time - Minutes
    uint8_t gps_min;
    //!GPS Time - Seconds
    uint8_t gps_sec;
    //!GPS Time - Fractional Seconds, unit: 10 ms
    uint8_t gps_frac_sec;
    //!Receive Signal Strength Information
    int8_t rssi;
    //!Input Voltage, unit: mV
    uint16_t input_voltage;
    //!Input Current, unit: mA
    uint16_t input_current;
    //!First Stage Voltage, unit: mV
    uint16_t fs_voltage;
    //!Digital Rail Voltage, unit: mV
    uint16_t dr_voltage;
    //!Analog Rail Voltage, unit: mV
    uint16_t ar_voltage;
    //!CPU Voltage, unit: mV
    uint16_t cpu_voltage;
    //!GPS Voltage, unit: mV
    uint16_t gps_voltage;
    //!Board Temperature, unit: K
    uint16_t board_temp;
    //!MHX VSWR
    uint16_t vswr;
    //!Reserved
    int8_t reserved;
    //!Static Pressure, unit: Pa
    uint32_t pressure;
    //!Pilot Sample Percent
    uint8_t pilot_sample;
    //!Pilot Uplink Rate, unit: 0.2 Hz
    uint8_t pilot_uplink;

    GroundStationTelemetry(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1031;
    }

    const char*
    getName(void) const
    {
      return "GroundStationTelemetry";
    }

    uint16_t
    getId(void) const
    {
      return GroundStationTelemetry::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class GSRadioSettings : public PiccoloMessage
  {
  public:
    enum EnumGSRadioSettings
    {
      //! Default
      SPEED_DEFAULT = 0,
      //! Narrow Band
      SPEED_NARROW = 1,
      //! Reserved
      SPEED_RESERVED = 2,
      //! Wide Band
      SPEED_WIDE = 3,
      //! 900 MHz ISM
      RADIO_MHX_910 = 0,
      //! 2.4 GHz ISM
      RADIO_MHX_2400 = 1,
      //! Next Gen. 900 MHz ISM
      RADIO_MHX_920 = 2,
      //! Next Gen. 2.4 GHz ISM
      RADIO_MHX_2420 = 3,
      //! 450 MHz Coherent Frequency
      RADIO_MHX_420 = 4,
      //! 350 MHz Coherent Frequency
      RADIO_MHX_320 = 5,
      //! 1.3 GHz Coherent Frequency
      RADIO_MHX_1320 = 6,
      //! Extend 900 Mhz Maxstream radio
      RADIO_EXTEND_900 = 7
    };

    //!Channel
    uint8_t channel;
    //!Power, unit: 10 mW
    uint8_t power;
    //!Speed, unit: Enumerated
    uint8_t speed;
    //!Radio Type, unit: Enumerated
    uint8_t radio;
    //!Frequency, unit: MHz
    fp32_t frequency;

    GSRadioSettings(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1033;
    }

    const char*
    getName(void) const
    {
      return "GSRadioSettings";
    }

    uint16_t
    getId(void) const
    {
      return GSRadioSettings::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class DynamicEnumeration : public PiccoloMessage
  {
  public:
    //!Enable
    uint8_t enable;

    DynamicEnumeration(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1035;
    }

    const char*
    getName(void) const
    {
      return "DynamicEnumeration";
    }

    uint16_t
    getId(void) const
    {
      return DynamicEnumeration::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class GSUserWarning : public PiccoloMessage
  {
  public:
    //!Packet type
    int8_t type;
    //!Warning code
    int8_t code;

    GSUserWarning(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1037;
    }

    const char*
    getName(void) const
    {
      return "GSUserWarning";
    }

    uint16_t
    getId(void) const
    {
      return GSUserWarning::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class GSResetReport : public PiccoloMessage
  {
  public:
    //!Reset status report
    int16_t rsr;
    //!Exception
    uint16_t except;
    //!Program counter
    int32_t pcounter;
    //!Machine state register
    int32_t msreg;
    //!Link register
    int32_t linkreg;
    //!Floating point register
    int32_t fpreg;

    GSResetReport(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1038;
    }

    const char*
    getName(void) const
    {
      return "GSResetReport";
    }

    uint16_t
    getId(void) const
    {
      return GSResetReport::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

  class GPSHotStart : public PiccoloMessage
  {
  public:

    GPSHotStart(void);

    void
    clear(void);

    static uint16_t
    getIdStatic(void)
    {
      return 1039;
    }

    const char*
    getName(void) const
    {
      return "GPSHotStart";
    }

    uint16_t
    getId(void) const
    {
      return GPSHotStart::getIdStatic();
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const;

    void
    deserializeFields(const uint8_t* bfr__);

  };

}

#endif

