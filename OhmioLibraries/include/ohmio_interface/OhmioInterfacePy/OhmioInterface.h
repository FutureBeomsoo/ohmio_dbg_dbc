#pragma once


#include <vector>
#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "pybind11/functional.h"

#include "LightInterface.h"
#include "InterfaceManager.h"
#include "DriveInterface.h"
#include "LocalizationInterface.h"
#include "DriveSystemStatusInterface.h"
#include "BatteryInterface.h"
#include "BusStopInterface.h"
#include "ObstacleInterface.h"
#include "RecordingInterface.h"
#include "RealTimeInterface.h"
#include "SaftryRegulatorInterface.h"
#include "TrafficLightInterface.h"
#include "AnnouncementsControl.h"
#include "ohmioInterfaceLib/NameTranslator.h"
#include "OhmioControlLib/AnnouncementsControl.h"


#include "canbus/dbc_MsgID_main.h" // needed for the vehicle states. Would be nice if we could do without it


namespace py = pybind11;


//! Library for Pybind11 interface for the Ohmio vehicle
PYBIND11_MODULE(libOhmioInterfacePy, m)
{
	//! The manager - creates the communication channels
	py::class_<OhmioInterfacePy::InterfaceManager>(m, "InterfaceManager")
	.def(py::init<std::string>())
	.def("default_server_address", &OhmioInterfacePy::InterfaceManager::GetDefaultAddress)
	.def("is_active", &OhmioInterfacePy::InterfaceManager::IsActive);

// --------------------- Light interface -----------------------------------------------

	//! Light interface - control and get state of lights
	py::class_<OhmioInterfacePy::LightInterface>(m, "LightInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&, int>())
		.def("set_indicators", &OhmioInterfacePy::LightInterface::SetIndicators)
		.def("get_indicators"  , &OhmioInterfacePy::LightInterface::GetIndicators)
		.def("set_lighting_mode", &OhmioInterfacePy::LightInterface::SetLightingMode)
		.def("get_lighting_mode", &OhmioInterfacePy::LightInterface::GetLightingMode)
		.def("set_driving_light_for_test", &OhmioInterfacePy::LightInterface::SetDrivingLightForTest)
		.def("wait_for_change", &OhmioInterfacePy::LightInterface::WaitForChange);


	static_assert(4 == (int)OhmioControl::DrivingLightsControl::IndicatorStatus::last, "if this fails new status were added");
	py::enum_<OhmioControl::DrivingLightsControl::IndicatorStatus >(m, "IndicatorStatus")
		.value("OFF", OhmioControl::DrivingLightsControl::IndicatorStatus::off)
		.value("LEFT", OhmioControl::DrivingLightsControl::IndicatorStatus::left)
		.value("RIGHT", OhmioControl::DrivingLightsControl::IndicatorStatus::right)
		.value("ALL", OhmioControl::DrivingLightsControl::IndicatorStatus::hazard)
		.export_values();

	static_assert(4 == (int)OhmioControl::DrivingLightsControl::LightMode::last, "if this fails new modes were added");
	py::enum_<OhmioControl::DrivingLightsControl::LightMode >(m, "LightMode")
		.value("DAY", OhmioControl::DrivingLightsControl::LightMode::day)
		.value("NIGHT_LOW_BEAM", OhmioControl::DrivingLightsControl::LightMode::nightLowBeam)
		.value("NIGHT_HIGH_BEAM", OhmioControl::DrivingLightsControl::LightMode::nightHighBeam)
		.value("TEST", OhmioControl::DrivingLightsControl::LightMode::test)
		.export_values();

// --------------------- localization -----------------------------------------------
	//! LocalizationInterface interface - get localization related status
	py::class_<OhmioInterfacePy::LocalizationInterface>(m, "LocalizationInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("get_location_data", &OhmioInterfacePy::LocalizationInterface::GetLocationData)
		.def("get_fusion_data", &OhmioInterfacePy::LocalizationInterface::GetFusionData)
		.def("get_uwb_anchors_locations", &OhmioInterfacePy::LocalizationInterface::GetUwbAnchorsLocations)
		.def("get_uwb_anchors_distances", &OhmioInterfacePy::LocalizationInterface::GetUwbAnchorsDistances);

	//! GpsQuality  enum
	static_assert(10 == (int)OhmioModel::GpsQuality::last, "if this fails new states were added");
	py::enum_<OhmioModel::GpsQuality>(m, "GpsQuality")
		.value("INVALID", OhmioModel::GpsQuality::invalid)
		.value("SINGLE_POINT", OhmioModel::GpsQuality::singlePoint)
		.value("PSEUDO_RANGE_DIFFERENTIAL", OhmioModel::GpsQuality::pseudoRangeDifferential)
		.value("UNUSED", OhmioModel::GpsQuality::unused)
		.value("FIXED_SOLUTION", OhmioModel::GpsQuality::fixedSolution)
		.value("FLOATING_SOLUTION", OhmioModel::GpsQuality::floatingSolution)
		.value("ESTIMATING", OhmioModel::GpsQuality::estimating)
		.value("MANUAL", OhmioModel::GpsQuality::Manual)
		.value("SIMULATION", OhmioModel::GpsQuality::Simulation)
		.value("WAAS", OhmioModel::GpsQuality::WAAS)
		.export_values();


	py::class_<OhmioInterfacePy::UwbDataPoint>(m, "UwbDataPoint")
		.def(py::init<>())
		.def_readwrite("id", &OhmioInterfacePy::UwbDataPoint::id)
		.def_readwrite("first", &OhmioInterfacePy::UwbDataPoint::first)
		.def_readwrite("second", &OhmioInterfacePy::UwbDataPoint::second);

	py::class_<OhmioModel::LatLong>(m, "LatLong")
		.def(py::init<>())
		.def_readwrite("latitude", &OhmioModel::LatLong::Latitude)
		.def_readwrite("longitude", &OhmioModel::LatLong::Longitude);

	py::class_<OhmioModel::GpsData>(m, "GpsData")
		.def(py::init<>())
		.def_readwrite("altitude", &OhmioModel::GpsData::Altitude)
		.def_readwrite("gps_quality", &OhmioModel::GpsData::Gps_quality)
		.def_readwrite("num_satellites", &OhmioModel::GpsData::numSatellites)
		.def_readwrite("location", &OhmioModel::GpsData::Location);

	py::class_<OhmioModel::LocationData>(m, "LocationData")
		.def(py::init<>())
		.def_readwrite("compass_angle", &OhmioModel::LocationData::CompassAngle)
		.def_readwrite("front_gps", &OhmioModel::LocationData::frontGps)
		.def_readwrite("rear_gps", &OhmioModel::LocationData::rearGps)
		.def_readwrite("heading", &OhmioModel::LocationData::Heading);

	py::class_<OhmioModel::FusionData>(m, "FusionData")
		.def(py::init<>())
		.def_readwrite("acceleration_lateral", &OhmioModel::FusionData::AccelerationLateral)
		.def_readwrite("acceleration_longitudinal", &OhmioModel::FusionData::AccelerationLongitudinal)
		.def_readwrite("heading", &OhmioModel::FusionData::Heading)
		.def_readwrite("heading_confidence", &OhmioModel::FusionData::HeadingConfidence)
		.def_readwrite("location_front", &OhmioModel::FusionData::LocationFront)
		.def_readwrite("loncation_rear", &OhmioModel::FusionData::LoncationRear)
		.def_readwrite("easting_confidence", &OhmioModel::FusionData::LateralConfidence)	// TODO change interface
		.def_readwrite("northing_confidence", &OhmioModel::FusionData::ForwardConfidence)	// TODO change interface
		.def_readwrite("way_point_index", &OhmioModel::FusionData::WayPointIndex);




// --------------------- drive control -----------------------------------------------
	//! Drive interface - control and get current state of driving (speed, mode, etc)
	py::class_<OhmioInterfacePy::DriveInterface>(m, "DriveInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("start", &OhmioInterfacePy::DriveInterface::Start)
		.def("go", &OhmioInterfacePy::DriveInterface::Go)
		.def("stop", &OhmioInterfacePy::DriveInterface::Stop)
		.def("Recover_emergency", &OhmioInterfacePy::DriveInterface::RecoverEmergency)
		.def("select_track", &OhmioInterfacePy::DriveInterface::SelectTrack)
		.def("wait_for_change", &OhmioInterfacePy::DriveInterface::WaitForChange)
		.def("get_current_state", &OhmioInterfacePy::DriveInterface::GetCurrentState)
		.def("set_max_speed", &OhmioInterfacePy::DriveInterface::SetMaxSpeed)
		.def("stop_at_location", &OhmioInterfacePy::DriveInterface::StopAtLocation)
		.def("stop_at_wp", &OhmioInterfacePy::DriveInterface::StopAtWP)
		.def("overtake", &OhmioInterfacePy::DriveInterface::Overtake)
		.def("get_max_speed", &OhmioInterfacePy::DriveInterface::GettMaxSpeed)
		.def("get_current_path", &OhmioInterfacePy::DriveInterface::GetCurrentPath)
		.def("get_direction", &OhmioInterfacePy::DriveInterface::GetDirection);


	//! the driving state
	static_assert(21 == (int)SYS_STATES::NUMBER_OF_SYS_STATES, "if this fails new states were added");
	py::enum_<SYS_STATES>(m, "ModeState")
		.value("idle", SYS_STATES::SYS_IDLE)
		.value("manual", SYS_STATES::SYS_MANUAL)
		.value("start", SYS_STATES::SYS_START)
		.value("drive", SYS_STATES::SYS_DRIVE)
		.value("end_track", SYS_STATES::SYS_END)
		.value("towing", SYS_STATES::SYS_TOWING)
		.value("reserved1", SYS_STATES::SYS_RESERVED)
		.value("load_path", SYS_STATES::SYS_LOAD)
		.value("manual_remote", SYS_STATES::SYS_REMOTE)
		.value("reserved2", SYS_STATES::SYS_RESERVED2)
		.value("validation_failed", SYS_STATES::SYS_ERROR)
		.value("app_validate", SYS_STATES::SYS_VALIDATE)
		.value("emergency", SYS_STATES::SYS_EMERGENCY)
		.value("wait_for_start", SYS_STATES::SYS_WAIT)
		.value("reserved3", SYS_STATES::SYS_RESERVED3)
		.value("steering_calibration", SYS_STATES::SYS_CALIBRATION)
		.value("reserved4", SYS_STATES::SYS_RESERVED4)
		.value("validate_track", SYS_STATES::SYS_VALIDATE_OB)
		.value("reserved5", SYS_STATES::SYS_RESERVED5)
		.value("startup", SYS_STATES::SYS_START_UP)
		.value("loading", SYS_STATES::SYS_LOADING)
		.export_values();

// --------------------- drive system status  -----------------------------------------------
	py::class_<OhmioInterfacePy::DriveSystemStatusInterface>(m, "DriveSystemStatusInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("get_motor_data", &OhmioInterfacePy::DriveSystemStatusInterface::GetMotorData)
		.def("get_steering_data", &OhmioInterfacePy::DriveSystemStatusInterface::GetSteeringData)
		.def("get_hydraulic_brake_data", &OhmioInterfacePy::DriveSystemStatusInterface::GetHydraulicBrakData)
		.def("get_parking_brak_data", &OhmioInterfacePy::DriveSystemStatusInterface::GetParkingBrakData)
		.def("set_wheel_radius", &OhmioInterfacePy::DriveSystemStatusInterface::SetWheelRadius)
		.def("set_gear_ratio", &OhmioInterfacePy::DriveSystemStatusInterface::SetGearRatio);

	//! BreakStaus enum
	static_assert(4 == (int)OhmioModel::BreakStaus::last, "if this fails new states were added");
	py::enum_<OhmioModel::BreakStaus>(m, "BreakStaus")
		.value("UNKNOWN", OhmioModel::BreakStaus::unknown)
		.value("ENGAGED", OhmioModel::BreakStaus::engaged)
		.value("DISENGAGED", OhmioModel::BreakStaus::disengaged)
		.value("IDLE", OhmioModel::BreakStaus::idle)
		.export_values();

	//! information about steering
	py::class_<OhmioModel::Steering>(m, "Steering")
		.def(py::init<>())
		.def_readwrite("requested", &OhmioModel::Steering::requested)
		.def_readwrite("actual", &OhmioModel::Steering::actual)
		.def_readwrite("current", &OhmioModel::Steering::current);

	//! information about the main motor
	py::class_<OhmioModel::TractionMotor>(m, "TractionMotor")
		.def(py::init<>())
		.def_readwrite("requested_speed", &OhmioModel::TractionMotor::requestedSpeed)
		.def_readwrite("actual_speed", &OhmioModel::TractionMotor::actualSpeed)
		.def_readwrite("rpm", &OhmioModel::TractionMotor::rpm)
		.def_readwrite("motor_temperature", &OhmioModel::TractionMotor::motorTemperature)
		.def_readwrite("controller_temperature", &OhmioModel::TractionMotor::controllerTemperature);

	//! information about hydraulic break
	py::class_<OhmioModel::HydraulicBrake>(m, "HydraulicBrake")
		.def(py::init<>())
		.def_readwrite("requested_pressure", &OhmioModel::HydraulicBrake::requestedPressure)
		.def_readwrite("actual_pressure", &OhmioModel::HydraulicBrake::actualPressure)
		.def_readwrite("current", &OhmioModel::HydraulicBrake::current)
		.def_readwrite("voltage", &OhmioModel::HydraulicBrake::voltage)
		.def_readwrite("time_alarm", &OhmioModel::HydraulicBrake::timeAlarm);

	//! information about a parking break
	py::class_<OhmioModel::ParkingBreak>(m, "ParkingBreak")
		.def(py::init<>())
		.def_readwrite("status", &OhmioModel::ParkingBreak::status)
		.def_readwrite("operations_mode", &OhmioModel::ParkingBreak::operationsMode)
		.def_readwrite("current", &OhmioModel::ParkingBreak::current);

// --------------------- end drive system status  -----------------------------------------------

// --------------------- power system status  -----------------------------------------------
	py::class_<OhmioInterfacePy::BatteryInterface>(m, "BatteryInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("get_battery_data", &OhmioInterfacePy::BatteryInterface::GetBatteryData)
		.def("get_main_battery_data", &OhmioInterfacePy::BatteryInterface::GetMainBatteryData);

	//! list of additional batteries enum
	static_assert(5 == (int)OhmioModel::Batteries::last, "if this fails new states were added");
	py::enum_<OhmioModel::Batteries>(m, "Batteries")
		.value("CONTROLLER", OhmioModel::Batteries::controller)
		.value("BREAK_BATTERY", OhmioModel::Batteries::breakBattery)
		.value("FRONT_STEERING", OhmioModel::Batteries::frontSteering)
		.value("REAR_STEERING", OhmioModel::Batteries::rearSteering)
		.value("DOOR", OhmioModel::Batteries::door)
		.export_values();

	//! information about a battery
	py::class_<OhmioModel::GeneralBatteryState>(m, "Battery")
		.def(py::init<>())
		.def_readwrite("voltage", &OhmioModel::GeneralBatteryState::voltage)
		.def_readwrite("alarm", &OhmioModel::GeneralBatteryState::alarm);

	//! information about the main battery
	py::class_<OhmioModel::MainBatteryState>(m, "MainBattery")
		.def(py::init<>())
		.def_readwrite("heat_relay", &OhmioModel::MainBatteryState::heatRelay)
		.def_readwrite("charge", &OhmioModel::MainBatteryState::charge)
		.def_readwrite("health", &OhmioModel::MainBatteryState::health)
		.def_readwrite("error_level", &OhmioModel::MainBatteryState::errorLevel)
		.def_readwrite("status", &OhmioModel::MainBatteryState::status)
		.def_readwrite("current", &OhmioModel::MainBatteryState::current)
		.def_readwrite("voltage", &OhmioModel::MainBatteryState::voltage)
		.def_readwrite("energy", &OhmioModel::MainBatteryState::energy)
		.def_readwrite("insulation_resistance", &OhmioModel::MainBatteryState::insulationResistance)
		.def_readwrite("temperature", &OhmioModel::MainBatteryState::temperature)
		.def_readwrite("heat_current", &OhmioModel::MainBatteryState::heatCurrent)
		.def_readwrite("insulation_error", &OhmioModel::MainBatteryState::insulationError);

// --------------------- end power system status  -----------------------------------------------


// --------------------- Obstacle interface -----------------------------------------------
	py::class_<OhmioInterfacePy::ObstacleInterface>(m, "ObstacleInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("set_obstacle", &OhmioInterfacePy::ObstacleInterface::SetObstacle)
		.def("clear_obstacle", &OhmioInterfacePy::ObstacleInterface::ClearObstacle)
		.def("get_obstacles", &OhmioInterfacePy::ObstacleInterface::GetObstacles)
		.def("register_for_change", &OhmioInterfacePy::ObstacleInterface::RegisterForChange);

	//! information about lidar obstacle system
	py::class_<OhmioModel::LidarObstacleData>(m, "LidarObstacleData")
		.def(py::init<>())
		.def_readwrite("active", &OhmioModel::LidarObstacleData::active)
		.def_readwrite("envelop", &OhmioModel::LidarObstacleData::envelop)
		.def_readwrite("distance_on_track", &OhmioModel::LidarObstacleData::distanceOnTrack)
		.def_readwrite("distance_margin_a", &OhmioModel::LidarObstacleData::distanceMarginA)
		.def_readwrite("distance_margin_b", &OhmioModel::LidarObstacleData::distanceMarginB)
		.def_readwrite("back_distance", &OhmioModel::LidarObstacleData::backDistance);


// --------------------- end Obstacle interface  -----------------------------------------------

// --------------------- track recording interface  -----------------------------------------------
	py::class_<OhmioInterfacePy::RecordingInterface>(m, "RecordingInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("start_track", &OhmioInterfacePy::RecordingInterface::StartTrack)
		.def("end_track", &OhmioInterfacePy::RecordingInterface::EndTrack)
		.def("get_location", &OhmioInterfacePy::RecordingInterface::GetCurrentLocation)
		.def("upload_track", &OhmioInterfacePy::RecordingInterface::UploadTrack)
		.def("get_track_length", &OhmioInterfacePy::RecordingInterface::GetTrackLength)
        .def("get_cur_speed", &OhmioInterfacePy::RecordingInterface::GetCurSpeed)
        .def("get_maxi_speed", &OhmioInterfacePy::RecordingInterface::GetMaxiSpeed)
		.def("get_current_state", &OhmioInterfacePy::RecordingInterface::GetCurrentState)
		.def("get_current_state_name", &OhmioInterfacePy::RecordingInterface::GetCurrentStateName)
		.def("wait_for_change", &OhmioInterfacePy::RecordingInterface::WaitForChange)
		.def("is_reverse_driving", &OhmioInterfacePy::RecordingInterface::IsReverseDriving)
		.def("get_upload_progress", &OhmioInterfacePy::RecordingInterface::GetUploadProgress)
		.def("get_upload_status", &OhmioInterfacePy::RecordingInterface::GetUploadStatus);
		
		
	//! a recorded track point
	py::class_<OhmioModel::TrackPointForRecording>(m, "TrackPointForRecording")
		.def(py::init<>())
		.def_readwrite("front_longitude", &OhmioModel::TrackPointForRecording::frontLong)
		.def_readwrite("front_latitude", &OhmioModel::TrackPointForRecording::frontLat)
		.def_readwrite("front_altitude", &OhmioModel::TrackPointForRecording::frontAlt)
		.def_readwrite("rear_longitude", &OhmioModel::TrackPointForRecording::rearLong)
		.def_readwrite("rear_latitud", &OhmioModel::TrackPointForRecording::rearLat)
		.def_readwrite("rear_altitude", &OhmioModel::TrackPointForRecording::rearAlt)
		.def_readwrite("heading", &OhmioModel::TrackPointForRecording::heading)
		.def_readwrite("speed", &OhmioModel::TrackPointForRecording::speed)
		.def_readwrite("time_stamp", &OhmioModel::TrackPointForRecording::timeStamp)
		.def_readwrite("confidence", &OhmioModel::TrackPointForRecording::confidence);

	//! the error codes
	static_assert(8 == (int)Ohmio::TrackUploadState::last, "if this fails new states were added");
	py::enum_<Ohmio::TrackUploadState>(m, "TrackUploadState")
		.value("sucess", Ohmio::TrackUploadState::sucess)
		.value("inProgress", Ohmio::TrackUploadState::inProgress)
		.value("fileReadError", Ohmio::TrackUploadState::fileReadError)
		.value("trackTooLong", Ohmio::TrackUploadState::trackTooLong)
		.value("trackInvalid", Ohmio::TrackUploadState::trackInvalid)
		.value("uploadError", Ohmio::TrackUploadState::uploadError)
		.value("obstacleUpload", Ohmio::TrackUploadState::obstacleUpload)
		.value("managementBlock", Ohmio::TrackUploadState::managementBlock)
		.value("last", Ohmio::TrackUploadState::last)
		.export_values();


	//! the change events
	static_assert(9 == (int)OhmioTcp::TrackRecordingChangeEvents::LastChangeEvent, "if this fails new events were added");
	py::enum_<OhmioTcp::TrackRecordingChangeEvents>(m, "RecordChangeEvent")
		.value("NO_EVENT", OhmioTcp::TrackRecordingChangeEvents::NoEvent)
		.value("RECORDING", OhmioTcp::TrackRecordingChangeEvents::Recording)
		.value("LOCATION", OhmioTcp::TrackRecordingChangeEvents::Location)
		.value("TRACK_LENGTH", OhmioTcp::TrackRecordingChangeEvents::TrackLength)
		.value("SPEED", OhmioTcp::TrackRecordingChangeEvents::Speed)
		.value("MAX_SPEED", OhmioTcp::TrackRecordingChangeEvents::MaxSpeed)
		.value("MODE", OhmioTcp::TrackRecordingChangeEvents::Mode)
		.value("DIRECTION", OhmioTcp::TrackRecordingChangeEvents::Direction)
		.value("UPLOADING", OhmioTcp::TrackRecordingChangeEvents::Uploading)
		.export_values();


// --------------------- end track recording interface  -----------------------------------------------

// --------------------- Version and safety regulation interface  -------------------------------------
	py::class_<OhmioInterfacePy::SaftryRegulatorInterface>(m, "SaftryRegulatorInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("can_drive", &OhmioInterfacePy::SaftryRegulatorInterface::CanDrive)
		.def("can_operate_devices", &OhmioInterfacePy::SaftryRegulatorInterface::CanOperateDevices)
		.def("get_device_status", &OhmioInterfacePy::SaftryRegulatorInterface::GetDeviceStatus)
		.def("get_actual_versions", &OhmioInterfacePy::SaftryRegulatorInterface::GetActualVersions)
		.def("get_expected_versions", &OhmioInterfacePy::SaftryRegulatorInterface::GetExpectedVersions)
		.def("set_expected_versions_file", &OhmioInterfacePy::SaftryRegulatorInterface::SetExpectedVersionsFromFile)
		.def("set_expected_versions", &OhmioInterfacePy::SaftryRegulatorInterface::SetExpectedVersions);

	py::class_<Ohmio::UnitVersion>(m, "DeviceVersion")
		.def(py::init<>())
		.def_readwrite("boot_version", &Ohmio::UnitVersion::bootVersion)
		.def_readwrite("can_version", &Ohmio::UnitVersion::canVersion)
		.def_readwrite("can_p_version", &Ohmio::UnitVersion::canPVersion)
		.def_readwrite("main_version", &Ohmio::UnitVersion::mainVersion);

	py::class_<Ohmio::Version>(m, "Version")
		.def(py::init<>())
		.def_readwrite("major", &Ohmio::Version::majorNumber)
		.def_readwrite("minor", &Ohmio::Version::minorNumber)
		.def_readwrite("build", &Ohmio::Version::buildNumber);

	
	py::class_<OhmioInterfacePy::UnitVersion>(m, "UnitVersion")
		.def(py::init<>())
		.def_readwrite("id", &OhmioInterfacePy::UnitVersion::id)
		.def_readwrite("version", &OhmioInterfacePy::UnitVersion::version);

	py::class_<OhmioInterfacePy::DeviceState>(m, "DeviceState")
		.def(py::init<>())
		.def_readwrite("id", &OhmioInterfacePy::DeviceState::id)
		.def_readwrite("state", &OhmioInterfacePy::DeviceState::state);


	//! SaftyReason  enum
	static_assert(8 == (int)Ohmio::SafetyReason::last, "if this fails new reasons were added");
	py::enum_<Ohmio::SafetyReason>(m, "SaftyReason")
		.value("OK", Ohmio::SafetyReason::Ok)
		.value("BLOCKED_WHILE_DRIVING", Ohmio::SafetyReason::BlockedWhileDriving)
		.value("INCOMPATABLE_VERSIONS", Ohmio::SafetyReason::IncompatableVersions)
		.value("PERIPHERAL_DEVICEACTIVE", Ohmio::SafetyReason::PeripheralDeviceActive)
		.value("BOOTLOADER_FAILED", Ohmio::SafetyReason::BootLoaderFailed)
		.value("LIMP_MODE", Ohmio::SafetyReason::LimpMode)
		.value("UNSAFE_TRACK", Ohmio::SafetyReason::UnsafeTrack)
		.value("AUTO_DISALLOWED", Ohmio::SafetyReason::AutoDisallowed)
		.export_values();


// --------------------- end Version and safety regulation interface  ---------------------------------


// --------------------- Bus stop interface -----------------------------------------------

	//! Bus stop interface
	py::class_<OhmioInterfacePy::BusStopInterface>(m, "BusStopInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("enable_stop", &OhmioInterfacePy::BusStopInterface::ActivateBusStop)
		.def("get_all_stops", &OhmioInterfacePy::BusStopInterface::GetAllStops)
		.def("get_location", &OhmioInterfacePy::BusStopInterface::GetCurrentWp)
		.def("get_track_id", &OhmioInterfacePy::BusStopInterface::GetTrackId)
		.def("go", &OhmioInterfacePy::BusStopInterface::Go)
		.def("hold", &OhmioInterfacePy::BusStopInterface::Hold)
		.def("release", &OhmioInterfacePy::BusStopInterface::Release)
		.def("is_stopped", &OhmioInterfacePy::BusStopInterface::IsStopped)
		.def("is_hold", &OhmioInterfacePy::BusStopInterface::IsHold)
		.def("set_stop", &OhmioInterfacePy::BusStopInterface::SetStopLocation)
		.def("register_for_data_change", &OhmioInterfacePy::BusStopInterface::RegisterForDataChange)
		.def("register_for_wp_change", &OhmioInterfacePy::BusStopInterface::RegisterForWpChange)
		.def("wait_for_change", &OhmioInterfacePy::BusStopInterface::WaitForChange);


	//! change events  enum
	static_assert(6 == (int)OhmioTcp::BusStopChangeEvents::LastChangeEvent, "if this fails new events were added");
	py::enum_<OhmioTcp::BusStopChangeEvents>(m, "BusStopChangeEvents")
		.value("NUNE", OhmioTcp::BusStopChangeEvents::NoEvent)
		.value("STOP_LOCATIONS", OhmioTcp::BusStopChangeEvents::StopLocations)
		.value("Track_Id", OhmioTcp::BusStopChangeEvents::TrackId)
		.value("Wp", OhmioTcp::BusStopChangeEvents::Wp)
		.value("Stopped", OhmioTcp::BusStopChangeEvents::Stopped)
		.value("Held", OhmioTcp::BusStopChangeEvents::Held)
		.export_values();

// --------------------- end Bus stop interface  ---------------------------------


// --------------------- real time interface -----------------------------------------------

	//! real time interface
	py::class_<OhmioInterfacePy::RealTimeInterface>(m, "RealTimeInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("get_all_data", &OhmioInterfacePy::RealTimeInterface::GetAllData)
		.def("get_topic_data", &OhmioInterfacePy::RealTimeInterface::GetTopicData)
		.def("get_topic_names", &OhmioInterfacePy::RealTimeInterface::GetTopicNames)
		.def("get_error_data", &OhmioInterfacePy::RealTimeInterface::GetErrorData)
		.def("get_error_module_names", &OhmioInterfacePy::RealTimeInterface::GetErrorModuleNames)
		.def("get_module_errors", &OhmioInterfacePy::RealTimeInterface::GetModuleErrors)
		.def("get_version_data", &OhmioInterfacePy::RealTimeInterface::GetVersionData)
		.def("get_version_module_names", &OhmioInterfacePy::RealTimeInterface::GetVersionModuleNames)
		.def("register_for_data", &OhmioInterfacePy::RealTimeInterface::RegisterForDataChange)
		.def("register_for_errors", &OhmioInterfacePy::RealTimeInterface::RegisterForErrorChange)
		.def("register_for_version", &OhmioInterfacePy::RealTimeInterface::RegisterForVersionChange)
		.def("Get_Module_Version", &OhmioInterfacePy::RealTimeInterface::GetModuleVersion)
		.def("get_vehicle_vin", &OhmioInterfacePy::RealTimeInterface::GetVehicleVin);


	//! a value with units data
	py::class_<OhmioInterfacePy::ValueUnit>(m, "ValueUnit")
		.def(py::init<>())
		.def_readwrite("value", &OhmioInterfacePy::ValueUnit::value)
		.def_readwrite("unit", &OhmioInterfacePy::ValueUnit::unit);



// --------------------- end real time interface  ---------------------------------

// --------------------- traffic light interface -----------------------------------------------

	//! traffic light interface
	py::class_<OhmioInterfacePy::TrafficLightInterface>(m, "TrafficLightInterface")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("get_status", &OhmioInterfacePy::TrafficLightInterface::GetStatus)
		.def("go", &OhmioInterfacePy::TrafficLightInterface::Go)
		.def("set_traffic_light", &OhmioInterfacePy::TrafficLightInterface::SetTrafficLight)
		.def("register_for_data_change", &OhmioInterfacePy::TrafficLightInterface::RegisterForDataChange)
		.def("wait_for_change", &OhmioInterfacePy::TrafficLightInterface::WaitForChange);

	py::class_<OhmioInterfacePy::MotionDescription>(m, "MotionDescription")
		.def(py::init<>())
		.def_readwrite("region_id", &OhmioInterfacePy::MotionDescription::regionId)
		.def_readwrite("intersection_id", &OhmioInterfacePy::MotionDescription::intersectionId)
		.def_readwrite("event_descriptor", &OhmioInterfacePy::MotionDescription::eventDescriptor);

	py::class_<OhmioInterfacePy::TrafficLightStatus>(m, "TrafficLightStatus")
		.def(py::init<>())
		.def_readwrite("distance", &OhmioInterfacePy::TrafficLightStatus::distance)
		.def_readwrite("event_name", &OhmioInterfacePy::TrafficLightStatus::eventName)
		.def_readwrite("status", &OhmioInterfacePy::TrafficLightStatus::status)
		.def_readwrite("time_to_change", &OhmioInterfacePy::TrafficLightStatus::timeToChange)
		.def_readwrite("message_age", &OhmioInterfacePy::TrafficLightStatus::messageAge)
		.def_readwrite("time_to_cross", &OhmioInterfacePy::TrafficLightStatus::timeToCross);



	//! status  enum
	py::enum_<TRAFFIC_LIGHT_STATUS>(m, "TrafficLightStatusEnum")
		.value("TRAFFIC_IDLE", TRAFFIC_LIGHT_STATUS::TRAFFIC_IDLE)
		.value("TRAFFIC_STOP", TRAFFIC_LIGHT_STATUS::TRAFFIC_STOP)
		.value("TRAFFIC_GO", TRAFFIC_LIGHT_STATUS::TRAFFIC_GO)
		.value("TRAFFIC_NO_TIME", TRAFFIC_LIGHT_STATUS::TRAFFIC_NO_TIME)
		.value("TRAFFIC_ERROR_DATA", TRAFFIC_LIGHT_STATUS::TRAFFIC_ERROR_DATA)
		.value("TRAFFIC_ERROR_EVENT", TRAFFIC_LIGHT_STATUS::TRAFFIC_ERROR_EVENT)
		.value("TRAFFIC_ERROR_INPUT", TRAFFIC_LIGHT_STATUS::TRAFFIC_ERROR_INPUT)
		.value("TRAFFIC_ERROR_PRIMARY", TRAFFIC_LIGHT_STATUS::TRAFFIC_ERROR_PRIMARY)
		.value("TRAFFIC_ERROR_SECONDARY", TRAFFIC_LIGHT_STATUS::TRAFFIC_ERROR_SECONDARY)
		.export_values();
// --------------------- end traffic light interface  ---------------------------------


// --------------------- name translator -----------------------------------------------
		//! The manager - creates the communication channels
	py::class_<Ohmio::NameTranslator>(m, "NameTranslator")
		.def(py::init<>())
		.def("get_unit_name", &Ohmio::NameTranslator::GetUnitName)
		.def("get_unit_error_strings", &Ohmio::NameTranslator::GetUnitErrorStrings)
		.def("get_unitwarning_strings", &Ohmio::NameTranslator::GetUnitWarningStrings)
		.def("get_sys_mode_name", &Ohmio::NameTranslator::GetModeName)
		.def("get_sys_states", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> sysStates;
				 self.GetSysStates(sysStates);
				 return sysStates; })
		.def("get_path_names", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> pathNames;
				 self.GetPathNames(pathNames);		   
				 return pathNames; })
		.def("get_sys_keys", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> keyNames; 
				 self.GetSysKeys(keyNames);	
				 return keyNames; })
		.def("get_epb_status_names", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> epbStatusNames; 
				 self.GetEpbStatusNames(epbStatusNames);	
				 return epbStatusNames; })
		.def("get_gps_quality_names", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> gpsQualityNames; 
				 self.GetgpsQualityNames(gpsQualityNames);	 
				 return gpsQualityNames; })
		.def("get_traffic_light_status_names", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> trafficLightStatusNames;	   
				 self.GetTrafficLightStatusNames(trafficLightStatusNames); 
				 return trafficLightStatusNames; })
		.def("get_bms_status_names", [](const Ohmio::NameTranslator &self)
			 {
				 std::map<int, std::string> bmsStatusNames; 
				 self.GetBmsStatusNames(bmsStatusNames);	
				 return bmsStatusNames; });

// --------------------- end name translator -----------------------------------------------


// --------------------- announcements interface -----------------------------------------------

	//! announcements interface
	py::class_<OhmioInterfacePy::AnnouncementsControl>(m, "AnnouncementsControl")
		.def(py::init<OhmioInterfacePy::InterfaceManager&>())
		.def("sound_announcement", &OhmioInterfacePy::AnnouncementsControl::SoundAnnouncement);


	//! output  enum
	py::enum_<OhmioControl::ISoundPlayer::AnnouncementsDevices>(m, "AnnouncementsDeviceEnum")
		.value("INTERNAL", OhmioControl::ISoundPlayer::AnnouncementsDevices::internal)
		.value("EXTERNAL", OhmioControl::ISoundPlayer::AnnouncementsDevices::external)
		.export_values();
// --------------------- end traffic light interface  ---------------------------------

}


