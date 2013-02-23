//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Joao Fortuna                                                     *
//***************************************************************************
// Automatically generated do not edit.                                     *
//***************************************************************************

#include "PiccoloDefinitions.hpp"
namespace Piccolo
{
    MovingBase::MovingBase(void)
    {
      m_id = 256;
      clear();
    }

    void
    MovingBase::clear(void)
    {
      gps_tow = 0;
      north = 0;
      east = 0;
      down = 0;
      head = 0;
      vnorth = 0;
      veast = 0;
      vdown = 0;
      rhand = 0;
    }

    PilotCommandAngle::PilotCommandAngle(void)
    {
      m_id = 512;
      clear();
    }

    void
    PilotCommandAngle::clear(void)
    {
      aileron = 0;
      elevator = 0;
      throttle = 0;
      rudder = 0;
      flap = 0;
      manual = 0;
      counter = 0;
      brakes = 0;
      parachute = 0;
      ignition = 0;
    }

    PilotCommandPulse::PilotCommandPulse(void)
    {
      m_id = 513;
      clear();
    }

    void
    PilotCommandPulse::clear(void)
    {
      aileron = 0;
      elevator = 0;
      throttle = 0;
      rudder = 0;
      flap = 0;
      manual = 0;
      counter = 0;
      brakes = 0;
      parachute = 0;
      ignition = 0;
    }

    UserWarning::UserWarning(void)
    {
      m_id = 768;
      clear();
    }

    void
    UserWarning::clear(void)
    {
      type = 0;
      code = 0;
    }

    BandwidthMode::BandwidthMode(void)
    {
      m_id = 770;
      clear();
    }

    void
    BandwidthMode::clear(void)
    {
    }

    FeatureCode::FeatureCode(void)
    {
      m_id = 771;
      clear();
    }

    void
    FeatureCode::clear(void)
    {
      code = 0;
    }

    PayloadMass::PayloadMass(void)
    {
      m_id = 774;
      clear();
    }

    void
    PayloadMass::clear(void)
    {
      mass = 0;
    }

    ElevationData::ElevationData(void)
    {
      m_id = 775;
      clear();
    }

    void
    ElevationData::clear(void)
    {
      mass = 0;
      elev = 0;
      elev_a = 0;
      elev_b = 0;
      elev_c = 0;
      elev_d = 0;
      elev_e = 0;
    }

    Waypoint::Waypoint(void)
    {
      m_id = 776;
      clear();
    }

    void
    Waypoint::clear(void)
    {
      lat = 0;
      lon = 0;
      flags = 0;
      radius = 0;
      altitude = 0;
      windfind = 0;
      time = 0;
      index = 0;
      next = 0;
      user = 0;
      flags2 = 0;
    }

    WaypointList::WaypointList(void)
    {
      m_id = 777;
      clear();
    }

    void
    WaypointList::clear(void)
    {
    }

    Track::Track(void)
    {
      m_id = 778;
      clear();
    }

    void
    Track::clear(void)
    {
      target = 0;
      track_goto = 0;
    }

    MinThrottle::MinThrottle(void)
    {
      m_id = 779;
      clear();
    }

    void
    MinThrottle::clear(void)
    {
      throttle = 0;
    }

    MissionSettings::MissionSettings(void)
    {
      m_id = 780;
      clear();
    }

    void
    MissionSettings::clear(void)
    {
      min_altitude = 0;
      max_altitude = 0;
      fl_timeout = 0;
    }

    SensorOrientation::SensorOrientation(void)
    {
      m_id = 782;
      clear();
    }

    void
    SensorOrientation::clear(void)
    {
      roll = 0;
      pitch = 0;
      yaw = 0;
      x_ant = 0;
      y_ant = 0;
      z_ant = 0;
    }

    AltimeterSetting::AltimeterSetting(void)
    {
      m_id = 783;
      clear();
    }

    void
    AltimeterSetting::clear(void)
    {
      base_press = 0;
      flags = 0;
    }

    SystemReset::SystemReset(void)
    {
      m_id = 784;
      clear();
    }

    void
    SystemReset::clear(void)
    {
    }

    SystemVersion::SystemVersion(void)
    {
      m_id = 785;
      clear();
    }

    void
    SystemVersion::clear(void)
    {
      major = 0;
      minor = 0;
      sub = 0;
      test = 0;
      year = 0;
      month = 0;
      day = 0;
      bserial = 0;
      features = 0;
      brevision = 0;
      bconfig = 0;
      ctrl = 0;
      ctrlversion = 0;
      byear = 0;
      bmonth = 0;
      bday = 0;
    }

    ResetReport::ResetReport(void)
    {
      m_id = 786;
      clear();
    }

    void
    ResetReport::clear(void)
    {
    }

    SurfaceTest::SurfaceTest(void)
    {
      m_id = 787;
      clear();
    }

    void
    SurfaceTest::clear(void)
    {
      angle = 0;
      width = 0;
      surface = 0;
      frequency = 0;
      deviation = 0;
    }

    MissionLimits::MissionLimits(void)
    {
      m_id = 788;
      clear();
    }

    void
    MissionLimits::clear(void)
    {
      comm_timeout = 0;
      pilot_timeout = 0;
      lost_comm_wpt = 0;
      failure = 0;
      autoland = 0;
      gps_timeout = 0;
      min_altitude = 0;
      max_altitude = 0;
      flight_timeout = 0;
    }

    UserAction::UserAction(void)
    {
      m_id = 790;
      clear();
    }

    void
    UserAction::clear(void)
    {
      action = 0;
      do_action = 0;
    }

    AutopilotLoop::AutopilotLoop(void)
    {
      m_id = 792;
      clear();
    }

    void
    AutopilotLoop::clear(void)
    {
      id = 0;
      control = 0;
      reserved = 0;
      value = 0;
      UpdateEEPROM = 0;
    }

    AutoFlareDisable::AutoFlareDisable(void)
    {
      m_id = 793;
      clear();
    }

    void
    AutoFlareDisable::clear(void)
    {
      Disable = 0;
      SupressWarning = 0;
    }

    Description::Description(void)
    {
      m_id = 794;
      clear();
    }

    void
    Description::clear(void)
    {
    }

    UserSpace::UserSpace(void)
    {
      m_id = 795;
      clear();
    }

    void
    UserSpace::clear(void)
    {
    }

    ManualFlare::ManualFlare(void)
    {
      m_id = 796;
      clear();
    }

    void
    ManualFlare::clear(void)
    {
    }

    MagneticCalibration::MagneticCalibration(void)
    {
      m_id = 798;
      clear();
    }

    void
    MagneticCalibration::clear(void)
    {
    }

    EngineKill::EngineKill(void)
    {
      m_id = 799;
      clear();
    }

    void
    EngineKill::clear(void)
    {
      kill = 0;
      reserved = 0;
    }

    RadioTransmitDisable::RadioTransmitDisable(void)
    {
      m_id = 800;
      clear();
    }

    void
    RadioTransmitDisable::clear(void)
    {
      radio = 0;
    }

    RadioSettings::RadioSettings(void)
    {
      m_id = 801;
      clear();
    }

    void
    RadioSettings::clear(void)
    {
      channel = 0;
      power = 0;
      speed = 0;
      radio = 0;
      frequency = 0;
    }

    ExternalSerialSetup::ExternalSerialSetup(void)
    {
      m_id = 802;
      clear();
    }

    void
    ExternalSerialSetup::clear(void)
    {
    }

    ExternalIOSetup::ExternalIOSetup(void)
    {
      m_id = 803;
      clear();
    }

    void
    ExternalIOSetup::clear(void)
    {
    }

    ExternalIOSample::ExternalIOSample(void)
    {
      m_id = 804;
      clear();
    }

    void
    ExternalIOSample::clear(void)
    {
      sample_0 = 0;
      sample_1 = 0;
      sample_2 = 0;
      sample_3 = 0;
      sample_4 = 0;
      sample_5 = 0;
      sample_6 = 0;
      sample_7 = 0;
      sample_8 = 0;
      sample_9 = 0;
      sample_10 = 0;
      sample_11 = 0;
      sample_12 = 0;
      sample_13 = 0;
      sample_14 = 0;
      sample_15 = 0;
    }

    ExternalADCSample::ExternalADCSample(void)
    {
      m_id = 806;
      clear();
    }

    void
    ExternalADCSample::clear(void)
    {
      sample_0 = 0;
      sample_1 = 0;
      sample_2 = 0;
      sample_3 = 0;
    }

    LandNow::LandNow(void)
    {
      m_id = 807;
      clear();
    }

    void
    LandNow::clear(void)
    {
    }

    CreateSimpleLanding::CreateSimpleLanding(void)
    {
      m_id = 811;
      clear();
    }

    void
    CreateSimpleLanding::clear(void)
    {
      lat = 0;
      lon = 0;
      alt = 0;
      head = 0;
      ccw_direction = 0;
      start = 0;
    }

    AirDataZero::AirDataZero(void)
    {
      m_id = 813;
      clear();
    }

    void
    AirDataZero::clear(void)
    {
      alt = 0;
    }

    PreLaunchMode::PreLaunchMode(void)
    {
      m_id = 814;
      clear();
    }

    void
    PreLaunchMode::clear(void)
    {
    }

    ManualAssistMode::ManualAssistMode(void)
    {
      m_id = 815;
      clear();
    }

    void
    ManualAssistMode::clear(void)
    {
      mode = 0;
      reserved = 0;
    }

    Lights::Lights(void)
    {
      m_id = 816;
      clear();
    }

    void
    Lights::clear(void)
    {
      enable = 0;
    }

    Brake::Brake(void)
    {
      m_id = 817;
      clear();
    }

    void
    Brake::clear(void)
    {
      value = 0;
    }

    Parachute::Parachute(void)
    {
      m_id = 818;
      clear();
    }

    void
    Parachute::clear(void)
    {
      enable = 0;
    }

    Drop::Drop(void)
    {
      m_id = 819;
      clear();
    }

    void
    Drop::clear(void)
    {
      enable = 0;
    }

    ThrottleTrim::ThrottleTrim(void)
    {
      m_id = 820;
      clear();
    }

    void
    ThrottleTrim::clear(void)
    {
    }

    TransponderControl::TransponderControl(void)
    {
      m_id = 827;
      clear();
    }

    void
    TransponderControl::clear(void)
    {
      code = 0;
      flags = 0;
    }

    RawVibrationData::RawVibrationData(void)
    {
      m_id = 829;
      clear();
    }

    void
    RawVibrationData::clear(void)
    {
    }

    VibrationData::VibrationData(void)
    {
      m_id = 830;
      clear();
    }

    void
    VibrationData::clear(void)
    {
    }

    LinkBridge::LinkBridge(void)
    {
      m_id = 831;
      clear();
    }

    void
    LinkBridge::clear(void)
    {
    }

    DoubletCommand::DoubletCommand(void)
    {
      m_id = 832;
      clear();
    }

    void
    DoubletCommand::clear(void)
    {
      flags = 0;
      Duration = 0;
      Pulse = 0;
      Center = 0;
      Delta = 0;
    }

    DoubletAPData::DoubletAPData(void)
    {
      m_id = 833;
      clear();
    }

    void
    DoubletAPData::clear(void)
    {
      SampleIndex = 0;
      SampleRate = 0;
      SampleTotal = 0;
      LeftRPM = 0;
      RightRPM = 0;
      Roll = 0;
      Pitch = 0;
      Yaw = 0;
      Aileron = 0;
      Elevator = 0;
      Throttle = 0;
      Rudder = 0;
      Flaps = 0;
    }

    DoubletSensorData::DoubletSensorData(void)
    {
      m_id = 834;
      clear();
    }

    void
    DoubletSensorData::clear(void)
    {
      SampleIndex = 0;
      SampleRate = 0;
      SampleTotal = 0;
      RollRate = 0;
      PitchRate = 0;
      YawRate = 0;
      DynP = 0;
      StatP = 0;
      XAccel = 0;
      YAccel = 0;
      ZAccel = 0;
      AnalogA = 0;
      AnalogB = 0;
      AnalogC = 0;
      AnalogD = 0;
    }

    ControllerDataRequest::ControllerDataRequest(void)
    {
      m_id = 835;
      clear();
    }

    void
    ControllerDataRequest::clear(void)
    {
      CtrlId = 0;
      CtrlVers = 0;
      Category = 0;
      DataId = 0;
      NumData = 0;
    }

    ControllerData::ControllerData(void)
    {
      m_id = 836;
      clear();
    }

    void
    ControllerData::clear(void)
    {
      CtrlId = 0;
      CtrlVers = 0;
      Category = 0;
      DataId = 0;
      CtrlData = 0;
    }

    TelemetryHighRes::TelemetryHighRes(void)
    {
      m_id = 837;
      clear();
    }

    void
    TelemetryHighRes::clear(void)
    {
      data_flags = 0;
      limits = 0;
      time = 0;
      lat = 0;
      lon = 0;
      height = 0;
      reserved = 0;
      sat_status = 0;
      vnorth = 0;
      veast = 0;
      vdown = 0;
      gps_status = 0;
      gps_week = 0;
      gps_tow = 0;
      roll = 0;
      pitch = 0;
      yaw = 0;
      altitude_old = 0;
      wind_south = 0;
      wind_west = 0;
      left_rpm = 0;
      right_rpm = 0;
      density_ratio = 0;
      oat = 0;
      ias = 0;
      static_pressure = 0;
      p = 0;
      q = 0;
      r = 0;
      x_accel = 0;
      y_accel = 0;
      z_accel = 0;
      mag_x = 0;
      mag_y = 0;
      mag_z = 0;
      compass = 0;
      agl = 0;
      act0 = 0;
      act1 = 0;
      act2 = 0;
      act3 = 0;
      act4 = 0;
      act5 = 0;
      act6 = 0;
      act7 = 0;
      act8 = 0;
      act9 = 0;
      act10 = 0;
      act11 = 0;
      act12 = 0;
      act13 = 0;
      act14 = 0;
      act15 = 0;
      fuel_flow = 0;
      fuel = 0;
      wow_gc = 0;
      altitude = 0;
    }

    TelemetryLowRes::TelemetryLowRes(void)
    {
      m_id = 838;
      clear();
    }

    void
    TelemetryLowRes::clear(void)
    {
      data_flags = 0;
      limits = 0;
      time = 0;
      lat = 0;
      lon = 0;
      height = 0;
      sat_status = 0;
      vnorth = 0;
      veast = 0;
      vdown = 0;
      gps_status = 0;
      gps_week = 0;
      gps_tow = 0;
      roll = 0;
      pitch = 0;
      yaw = 0;
      altitude_old = 0;
      wind_south = 0;
      wind_west = 0;
      left_rpm = 0;
      right_rpm = 0;
      density_ratio = 0;
      oat = 0;
      ias = 0;
      static_pressure = 0;
      p = 0;
      q = 0;
      r = 0;
      x_accel = 0;
      y_accel = 0;
      z_accel = 0;
      mag_x = 0;
      mag_y = 0;
      mag_z = 0;
      compass = 0;
      agl = 0;
      act0 = 0;
      act1 = 0;
      act2 = 0;
      act3 = 0;
      act4 = 0;
      act5 = 0;
      act6 = 0;
      act7 = 0;
      act8 = 0;
      act9 = 0;
      act10 = 0;
      act11 = 0;
      act12 = 0;
      act13 = 0;
      act14 = 0;
      act15 = 0;
      fuel_flow = 0;
      fuel = 0;
      altitude = 0;
      wow_gc = 0;
    }

    SystemStatusHighRes::SystemStatusHighRes(void)
    {
      m_id = 839;
      clear();
    }

    void
    SystemStatusHighRes::clear(void)
    {
      power_main = 0;
      power_servo = 0;
      voltage_bad = 0;
      temp_board = 0;
      reserved1 = 0;
      reserved2 = 0;
      reserved3 = 0;
      track_status = 0;
      reserved4 = 0;
      reserved5 = 0;
      waypoint_to = 0;
    }

    SystemStatusLowRes::SystemStatusLowRes(void)
    {
      m_id = 840;
      clear();
    }

    void
    SystemStatusLowRes::clear(void)
    {
    }

    LaunchNow::LaunchNow(void)
    {
      m_id = 841;
      clear();
    }

    void
    LaunchNow::clear(void)
    {
    }

    ControllerDataDefault::ControllerDataDefault(void)
    {
      m_id = 842;
      clear();
    }

    void
    ControllerDataDefault::clear(void)
    {
    }

    SetFuelLevel::SetFuelLevel(void)
    {
      m_id = 843;
      clear();
    }

    void
    SetFuelLevel::clear(void)
    {
      electric = 0;
      reserved1 = 0;
      reserved2 = 0;
      reserved3 = 0;
      fuel = 0;
    }

    SensorError::SensorError(void)
    {
      m_id = 844;
      clear();
    }

    void
    SensorError::clear(void)
    {
    }

    Abort::Abort(void)
    {
      m_id = 845;
      clear();
    }

    void
    Abort::clear(void)
    {
    }

    MovingBaselineStatus::MovingBaselineStatus(void)
    {
      m_id = 846;
      clear();
    }

    void
    MovingBaselineStatus::clear(void)
    {
    }

    SetFuelIfLocked::SetFuelIfLocked(void)
    {
      m_id = 847;
      clear();
    }

    void
    SetFuelIfLocked::clear(void)
    {
    }

    AddAddress::AddAddress(void)
    {
      m_id = 1024;
      clear();
    }

    void
    AddAddress::clear(void)
    {
      address = 0;
    }

    DelAddress::DelAddress(void)
    {
      m_id = 1025;
      clear();
    }

    void
    DelAddress::clear(void)
    {
      address = 0;
    }

    PilotAddress::PilotAddress(void)
    {
      m_id = 1026;
      clear();
    }

    void
    PilotAddress::clear(void)
    {
      address = 0;
    }

    DGPSCorrection::DGPSCorrection(void)
    {
      m_id = 1027;
      clear();
    }

    void
    DGPSCorrection::clear(void)
    {
      lat = 0;
      lon = 0;
      height = 0;
      enable = 0;
      moving = 0;
      north = 0;
      east = 0;
      down = 0;
      head = 0;
      rhand = 0;
      abs_head = 0;
    }

    GSSystemVersion::GSSystemVersion(void)
    {
      m_id = 1028;
      clear();
    }

    void
    GSSystemVersion::clear(void)
    {
      major = 0;
      minor = 0;
      sub = 0;
      released = 0;
      year = 0;
      month = 0;
      day = 0;
      bserial = 0;
      brevision = 0;
      bconfig = 0;
      byear = 0;
      bmonth = 0;
      bday = 0;
    }

    RequestConfig::RequestConfig(void)
    {
      m_id = 1029;
      clear();
    }

    void
    RequestConfig::clear(void)
    {
    }

    GroundStationTelemetry::GroundStationTelemetry(void)
    {
      m_id = 1031;
      clear();
    }

    void
    GroundStationTelemetry::clear(void)
    {
      lat = 0;
      lon = 0;
      height = 0;
      vnorth = 0;
      veast = 0;
      gps_tracked_sat = 0;
      gps_visible_sat = 0;
      gps_dop = 0;
      gps_status = 0;
      gps_year = 0;
      gps_month = 0;
      gps_day = 0;
      gps_hour = 0;
      gps_min = 0;
      gps_sec = 0;
      gps_frac_sec = 0;
      rssi = 0;
      input_voltage = 0;
      input_current = 0;
      fs_voltage = 0;
      dr_voltage = 0;
      ar_voltage = 0;
      cpu_voltage = 0;
      gps_voltage = 0;
      board_temp = 0;
      vswr = 0;
      reserved = 0;
      pressure = 0;
      pilot_sample = 0;
      pilot_uplink = 0;
    }

    GSRadioSettings::GSRadioSettings(void)
    {
      m_id = 1033;
      clear();
    }

    void
    GSRadioSettings::clear(void)
    {
      channel = 0;
      power = 0;
      speed = 0;
      radio = 0;
      frequency = 0;
    }

    DynamicEnumeration::DynamicEnumeration(void)
    {
      m_id = 1035;
      clear();
    }

    void
    DynamicEnumeration::clear(void)
    {
      enable = 0;
    }

    GSUserWarning::GSUserWarning(void)
    {
      m_id = 1037;
      clear();
    }

    void
    GSUserWarning::clear(void)
    {
      type = 0;
      code = 0;
    }

    GSResetReport::GSResetReport(void)
    {
      m_id = 1038;
      clear();
    }

    void
    GSResetReport::clear(void)
    {
      rsr = 0;
      except = 0;
      pcounter = 0;
      msreg = 0;
      linkreg = 0;
      fpreg = 0;
    }

    GPSHotStart::GPSHotStart(void)
    {
      m_id = 1039;
      clear();
    }

    void
    GPSHotStart::clear(void)
    {
    }

}