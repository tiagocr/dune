//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************

#include "PiccoloDefinitions.hpp"
#include "PiccoloSerialization.hpp"

namespace Piccolo
{
    uint8_t*
    MovingBase::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    MovingBase::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(gps_tow, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(north, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(east, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(down, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(head, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(vnorth, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(veast, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(vdown, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(rhand, bfr__, 1);
    }

    uint8_t*
    PilotCommandAngle::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    PilotCommandAngle::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(aileron, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elevator, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(throttle, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(rudder, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(flap, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(manual, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(counter, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(brakes, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(parachute, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(ignition, bfr__, 1);
    }

    uint8_t*
    PilotCommandPulse::serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      *(bfr__++) = 0xA0;
      *(bfr__++) = 0x05;
      *(bfr__++) = (uint8_t)(getId() % 256);
      *(bfr__++) = 17;
      bfr__ += Piccolo::reverseSerialize(aileron, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(elevator, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(throttle, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(rudder, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(flap, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(manual, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(counter, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(brakes, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(parachute, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(ignition, bfr__, 1);
      uint16_t crc = DUNE::Algorithms::CRC16::compute(ptr__ , 21); //! 4 from header, 17 from data
      *(bfr__++) = (uint8_t) ((crc >> 8) & 0x00FF);
      *(bfr__++) = (uint8_t) (crc & 0x00FF);
      return bfr__;
    }

    void
    PilotCommandPulse::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(aileron, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elevator, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(throttle, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(rudder, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(flap, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(manual, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(counter, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(brakes, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(parachute, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(ignition, bfr__, 1);
    }

    uint8_t*
    UserWarning::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    UserWarning::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(type, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(code, bfr__, 1);
    }

    uint8_t*
    BandwidthMode::serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      *(bfr__++) = 0xA0;
      *(bfr__++) = 0x05;
      *(bfr__++) = (uint8_t)(getId() % 256);
      *(bfr__++) = 4;
      *(bfr__++) = 0xFF;
      *(bfr__++) = 0x00;
      *(bfr__++) = 0x00;
      *(bfr__++) = 0x00;
      uint16_t crc = DUNE::Algorithms::CRC16::compute(ptr__ , 8);
      *(bfr__++) = (uint8_t) ((crc >> 8) & 0x00FF);
      *(bfr__++) = (uint8_t) (crc & 0x00FF);
      return bfr__;
    }

    void
    BandwidthMode::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    FeatureCode::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    FeatureCode::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(code, bfr__, 8);
    }

    uint8_t*
    PayloadMass::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    PayloadMass::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(mass, bfr__, 4);
    }

    uint8_t*
    ElevationData::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ElevationData::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(mass, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(elev, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elev_a, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elev_b, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elev_c, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elev_d, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(elev_e, bfr__, 2);
    }

    uint8_t*
    Waypoint::serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      *(bfr__++) = 0xA0;
      *(bfr__++) = 0x05;
      *(bfr__++) = (uint8_t)(getId() % 256);
      *(bfr__++) = 18; //! Data size
      bfr__ += Piccolo::reverseSerialize(lat, bfr__, 4);
      bfr__ += Piccolo::reverseSerialize(lon, bfr__, 4);
      bfr__ += Piccolo::reverseSerialize(flags, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(radius, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(altitude, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(windfind, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(time, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(index, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(next, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(user, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(flags2, bfr__, 1);
      uint16_t crc = DUNE::Algorithms::CRC16::compute(ptr__ , 22); //! 4 from header, 18 from data
      *(bfr__++) = (uint8_t) ((crc >> 8) & 0x00FF);
      *(bfr__++) = (uint8_t) (crc & 0x00FF);
      return bfr__;
    }

    void
    Waypoint::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(lat, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(lon, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(flags, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(radius, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(altitude, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(windfind, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(time, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(index, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(next, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(user, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(flags2, bfr__, 1);
    }

    uint8_t*
    WaypointList::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    WaypointList::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    Track::serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      *(bfr__++) = 0xA0;
      *(bfr__++) = 0x05;
      *(bfr__++) = (uint8_t)(getId() % 256);
      *(bfr__++) = 2; //! Data size
      bfr__ += Piccolo::reverseSerialize(target, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(track_goto, bfr__, 1);
      uint16_t crc = DUNE::Algorithms::CRC16::compute(ptr__ , 6); //! 4 from header, 3 from data
      *(bfr__++) = (uint8_t) ((crc >> 8) & 0x00FF);
      *(bfr__++) = (uint8_t) (crc & 0x00FF);
      return bfr__;
    }

    void
    Track::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(target, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(track_goto, bfr__, 1);
    }

    uint8_t*
    MinThrottle::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    MinThrottle::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(throttle, bfr__, 2);
    }

    uint8_t*
    MissionSettings::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    MissionSettings::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(min_altitude, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(max_altitude, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(fl_timeout, bfr__, 4);
    }

    uint8_t*
    SensorOrientation::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SensorOrientation::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(roll, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(pitch, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(yaw, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(x_ant, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(y_ant, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(z_ant, bfr__, 4);
    }

    uint8_t*
    AltimeterSetting::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    AltimeterSetting::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(base_press, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(flags, bfr__, 1);
    }

    uint8_t*
    SystemReset::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SystemReset::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    SystemVersion::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SystemVersion::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(major, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(minor, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(sub, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(test, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(year, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(month, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(day, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(bserial, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(features, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(brevision, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(bconfig, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(ctrl, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(ctrlversion, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(byear, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(bmonth, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(bday, bfr__, 1);
    }

    uint8_t*
    ResetReport::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ResetReport::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    SurfaceTest::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SurfaceTest::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(angle, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(width, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(surface, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(frequency, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(deviation, bfr__, 2);
    }

    uint8_t*
    MissionLimits::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    MissionLimits::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(comm_timeout, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(pilot_timeout, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(lost_comm_wpt, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(failure, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(autoland, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_timeout, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(min_altitude, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(max_altitude, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(flight_timeout, bfr__, 4);
    }

    uint8_t*
    UserAction::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    UserAction::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(action, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(do_action, bfr__, 1);
    }

    uint8_t*
    AutopilotLoop::serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      *(bfr__++) = 0xA0;
      *(bfr__++) = 0x05;
      *(bfr__++) = (uint8_t)(getId() % 256);
      *(bfr__++) = 9;
      bfr__ += Piccolo::reverseSerialize(id, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(control, bfr__, 1);
      bfr__ += Piccolo::reverseSerialize(reserved, bfr__, 2);
      bfr__ += Piccolo::reverseSerialize(value, bfr__, 4);
      bfr__ += Piccolo::reverseSerialize(UpdateEEPROM, bfr__, 1);
      uint16_t crc = DUNE::Algorithms::CRC16::compute(ptr__ , 13);
      *(bfr__++) = (uint8_t) ((crc >> 8) & 0x00FF);
      *(bfr__++) = (uint8_t) (crc & 0x00FF);
      return bfr__;
    }

    void
    AutopilotLoop::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(id, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(control, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(reserved, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(value, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(UpdateEEPROM, bfr__, 1);
    }

    uint8_t*
    AutoFlareDisable::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    AutoFlareDisable::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(Disable, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(SupressWarning, bfr__, 1);
    }

    uint8_t*
    Description::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    Description::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    UserSpace::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    UserSpace::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    ManualFlare::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ManualFlare::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    MagneticCalibration::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    MagneticCalibration::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    EngineKill::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    EngineKill::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(kill, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(reserved, bfr__, 1);
    }

    uint8_t*
    RadioTransmitDisable::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    RadioTransmitDisable::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(radio, bfr__, 2);
    }

    uint8_t*
    RadioSettings::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    RadioSettings::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(channel, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(power, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(speed, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(radio, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(frequency, bfr__, 4);
    }

    uint8_t*
    ExternalSerialSetup::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ExternalSerialSetup::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    ExternalIOSetup::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ExternalIOSetup::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    ExternalIOSample::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ExternalIOSample::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(sample_0, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_1, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_2, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_3, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_4, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_5, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_6, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_7, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_8, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_9, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_10, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_11, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_12, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_13, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_14, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_15, bfr__, 4);
    }

    uint8_t*
    ExternalADCSample::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ExternalADCSample::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(sample_0, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_1, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_2, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(sample_3, bfr__, 4);
    }

    uint8_t*
    LandNow::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    LandNow::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    CreateSimpleLanding::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    CreateSimpleLanding::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(lat, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(lon, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(alt, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(head, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(ccw_direction, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(start, bfr__, 1);
    }

    uint8_t*
    AirDataZero::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    AirDataZero::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(alt, bfr__, 4);
    }

    uint8_t*
    PreLaunchMode::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    PreLaunchMode::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    ManualAssistMode::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ManualAssistMode::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(mode, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(reserved, bfr__, 1);
    }

    uint8_t*
    Lights::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    Lights::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(enable, bfr__, 1);
    }

    uint8_t*
    Brake::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    Brake::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(value, bfr__, 2);
    }

    uint8_t*
    Parachute::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    Parachute::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(enable, bfr__, 1);
    }

    uint8_t*
    Drop::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    Drop::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(enable, bfr__, 1);
    }

    uint8_t*
    ThrottleTrim::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ThrottleTrim::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    TransponderControl::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    TransponderControl::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(code, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(flags, bfr__, 1);
    }

    uint8_t*
    RawVibrationData::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    RawVibrationData::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    VibrationData::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    VibrationData::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    LinkBridge::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    LinkBridge::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    DoubletCommand::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    DoubletCommand::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(flags, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(Duration, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(Pulse, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Center, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Delta, bfr__, 2);
    }

    uint8_t*
    DoubletAPData::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    DoubletAPData::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(SampleIndex, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(SampleRate, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(SampleTotal, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(LeftRPM, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(RightRPM, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Roll, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Pitch, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Yaw, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Aileron, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Elevator, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Throttle, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Rudder, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(Flaps, bfr__, 2);
    }

    uint8_t*
    DoubletSensorData::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    DoubletSensorData::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(SampleIndex, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(SampleRate, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(SampleTotal, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(RollRate, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(PitchRate, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(YawRate, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(DynP, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(StatP, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(XAccel, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(YAccel, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(ZAccel, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(AnalogA, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(AnalogB, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(AnalogC, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(AnalogD, bfr__, 2);
    }

    uint8_t*
    ControllerDataRequest::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ControllerDataRequest::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(CtrlId, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(CtrlVers, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(Category, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(DataId, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(NumData, bfr__, 1);
    }

    uint8_t*
    ControllerData::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ControllerData::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(CtrlId, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(CtrlVers, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(Category, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(DataId, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(CtrlData, bfr__, 4);
    }

    uint8_t*
    TelemetryHighRes::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    TelemetryHighRes::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(data_flags, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(limits, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(time, bfr__, 4);
      if(data_flags & TelemetryHighRes::DATA_GPS)
      {
        bfr__ += Piccolo::reverseDeserialize(lat, bfr__, 4);
        bfr__ += Piccolo::reverseDeserialize(lon, bfr__, 4);
        bfr__ += Piccolo::reverseDeserialize(height, bfr__, 3);
        bfr__ += Piccolo::reverseDeserialize(reserved, bfr__, 1);
        bfr__ += Piccolo::reverseDeserialize(sat_status, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(vnorth, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(veast, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(vdown, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(gps_status, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(gps_week, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(gps_tow, bfr__, 4);
      }
      if(data_flags & TelemetryHighRes::DATA_SENSOR)
      {
        bfr__ += Piccolo::reverseDeserialize(roll, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(pitch, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(yaw, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(altitude_old, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(wind_south, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(wind_west, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(left_rpm, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(right_rpm, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(density_ratio, bfr__, 1);
      }
      if(data_flags & TelemetryHighRes::DATA_RAW_SENSOR)
      {
        bfr__ += Piccolo::reverseDeserialize(oat, bfr__, 1);
        bfr__ += Piccolo::reverseDeserialize(ias, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(static_pressure, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(p, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(q, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(r, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(x_accel, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(y_accel, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(z_accel, bfr__, 2);
      }
      if(data_flags & TelemetryHighRes::DATA_MAGNETOMER)
      {
        bfr__ += Piccolo::reverseDeserialize(mag_x, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(mag_y, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(mag_z, bfr__, 2);
        bfr__ += Piccolo::reverseDeserialize(compass, bfr__, 2);
      }
      if(data_flags & TelemetryHighRes::DATA_AGL)
        bfr__ += Piccolo::reverseDeserialize(agl, bfr__, 2);
      int num_act = (int)(data_flags & TelemetryHighRes::DATA_NUM_ACT);
      if(num_act > 0)
        bfr__ += Piccolo::reverseDeserialize(act0, bfr__, 2);
      if(num_act > 1)
        bfr__ += Piccolo::reverseDeserialize(act1, bfr__, 2);
      if(num_act > 2)
        bfr__ += Piccolo::reverseDeserialize(act2, bfr__, 2);
      if(num_act > 3)
        bfr__ += Piccolo::reverseDeserialize(act3, bfr__, 2);
      if(num_act > 4)
        bfr__ += Piccolo::reverseDeserialize(act4, bfr__, 2);
      if(num_act > 5)
        bfr__ += Piccolo::reverseDeserialize(act5, bfr__, 2);
      if(num_act > 6)
        bfr__ += Piccolo::reverseDeserialize(act6, bfr__, 2);
      if(num_act > 7)
        bfr__ += Piccolo::reverseDeserialize(act7, bfr__, 2);
      if(num_act > 8)
        bfr__ += Piccolo::reverseDeserialize(act8, bfr__, 2);
      if(num_act > 9)
        bfr__ += Piccolo::reverseDeserialize(act9, bfr__, 2);
      if(num_act > 10)
        bfr__ += Piccolo::reverseDeserialize(act10, bfr__, 2);
      if(num_act > 11)
        bfr__ += Piccolo::reverseDeserialize(act11, bfr__, 2);
      if(num_act > 12)
        bfr__ += Piccolo::reverseDeserialize(act12, bfr__, 2);
      if(num_act > 13)
        bfr__ += Piccolo::reverseDeserialize(act13, bfr__, 2);
      if(num_act > 14)
        bfr__ += Piccolo::reverseDeserialize(act14, bfr__, 2);
      if(num_act > 15)
        bfr__ += Piccolo::reverseDeserialize(act15, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(fuel_flow, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(fuel, bfr__, 2);
      if(data_flags & TelemetryHighRes::DATA_SENSOR)
      {
        bfr__ += Piccolo::reverseDeserialize(wow_gc, bfr__, 1);
        bfr__ += Piccolo::reverseDeserialize(altitude, bfr__, 3);
      }
    }

    uint8_t*
    TelemetryLowRes::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    TelemetryLowRes::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(data_flags, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(limits, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(time, bfr__, 3);
      bfr__ += Piccolo::reverseDeserialize(lat, bfr__, 3);
      bfr__ += Piccolo::reverseDeserialize(lon, bfr__, 3);
      bfr__ += Piccolo::reverseDeserialize(height, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(sat_status, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(vnorth, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(veast, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(vdown, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_status, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(gps_week, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(gps_tow, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(roll, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(pitch, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(yaw, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(altitude_old, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(wind_south, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(wind_west, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(left_rpm, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(right_rpm, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(density_ratio, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(oat, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(ias, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(static_pressure, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(p, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(q, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(r, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(x_accel, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(y_accel, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(z_accel, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(mag_x, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(mag_y, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(mag_z, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(compass, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(agl, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act0, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act1, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act2, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act3, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act4, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act5, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act6, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act7, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act8, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act9, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act10, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act11, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act12, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act13, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act14, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(act15, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(fuel_flow, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(fuel, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(altitude, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(wow_gc, bfr__, 1);
    }

    uint8_t*
    SystemStatusHighRes::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SystemStatusHighRes::deserializeFields(const uint8_t* bfr__)
    {
      int size = (int)(*(bfr__-1));
      const uint8_t* start__ = bfr__;

      bfr__ += Piccolo::reverseDeserialize(power_main, bfr__, 3);
      bfr__ += Piccolo::reverseDeserialize(power_servo, bfr__, 3);
      bfr__ += Piccolo::reverseDeserialize(voltage_bad, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(temp_board, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(track_status, (bfr__ + 20), 2); // Skip 20 bytes of fields I don't care about
      bfr__ += Piccolo::reverseDeserialize(waypoint_to, (start__ + size -1), 1); // Skip all the rest except the last byte
    }

    uint8_t*
    SystemStatusLowRes::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SystemStatusLowRes::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    LaunchNow::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    LaunchNow::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    ControllerDataDefault::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    ControllerDataDefault::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    SetFuelLevel::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SetFuelLevel::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(electric, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(reserved1, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(reserved2, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(reserved3, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(fuel, bfr__, 4);
    }

    uint8_t*
    SensorError::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SensorError::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    Abort::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    Abort::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    MovingBaselineStatus::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    MovingBaselineStatus::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    SetFuelIfLocked::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    SetFuelIfLocked::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    AddAddress::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    AddAddress::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(address, bfr__, 2);
    }

    uint8_t*
    DelAddress::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    DelAddress::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(address, bfr__, 2);
    }

    uint8_t*
    PilotAddress::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    PilotAddress::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(address, bfr__, 2);
    }

    uint8_t*
    DGPSCorrection::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    DGPSCorrection::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(lat, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(lon, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(height, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(enable, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(moving, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(north, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(east, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(down, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(head, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(rhand, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(abs_head, bfr__, 1);
    }

    uint8_t*
    GSSystemVersion::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    GSSystemVersion::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(major, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(minor, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(sub, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(released, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(year, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(month, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(day, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(bserial, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(brevision, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(bconfig, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(byear, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(bmonth, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(bday, bfr__, 1);
    }

    uint8_t*
    RequestConfig::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    RequestConfig::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

    uint8_t*
    GroundStationTelemetry::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    GroundStationTelemetry::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(lat, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(lon, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(height, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(vnorth, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(veast, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(gps_tracked_sat, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_visible_sat, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_dop, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(gps_status, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(gps_year, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(gps_month, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_day, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_hour, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_min, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_sec, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(gps_frac_sec, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(rssi, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(input_voltage, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(input_current, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(fs_voltage, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(dr_voltage, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(ar_voltage, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(cpu_voltage, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(gps_voltage, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(board_temp, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(vswr, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(reserved, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(pressure, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(pilot_sample, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(pilot_uplink, bfr__, 1);
    }

    uint8_t*
    GSRadioSettings::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    GSRadioSettings::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(channel, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(power, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(speed, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(radio, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(frequency, bfr__, 4);
    }

    uint8_t*
    DynamicEnumeration::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    DynamicEnumeration::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(enable, bfr__, 1);
    }

    uint8_t*
    GSUserWarning::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    GSUserWarning::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(type, bfr__, 1);
      bfr__ += Piccolo::reverseDeserialize(code, bfr__, 1);
    }

    uint8_t*
    GSResetReport::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    GSResetReport::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += Piccolo::reverseDeserialize(rsr, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(except, bfr__, 2);
      bfr__ += Piccolo::reverseDeserialize(pcounter, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(msreg, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(linkreg, bfr__, 4);
      bfr__ += Piccolo::reverseDeserialize(fpreg, bfr__, 4);
    }

    uint8_t*
    GPSHotStart::serializeFields(uint8_t* bfr__) const
    {
      return bfr__;
    }

    void
    GPSHotStart::deserializeFields(const uint8_t* bfr__)
    {
      bfr__ += 0;
    }

}
