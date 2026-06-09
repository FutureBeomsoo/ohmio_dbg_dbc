#pragma once

#include "pch.h"

//! The Ohmio vehicle model. Knows the status of the vehicle. See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/972685321/Modular+design+of+the+ohmio+interface 
namespace OhmioModel
{

	static const double WHEEL_RADIUS_LIFT = 0.3675;
	static const double GEAR_RATIO_LIFT = 17.8;
	static const double GEAR_RATIO_MOTOR3 = 19.2;

	//! A generic interface for monitoring change in any of the vehicle units
	class IChangeObserver
	{
	public:
		//! @param[in] param - a generic int parameter to indicate what changed
		virtual void OnChanged(int param) = 0;
	};


	//! What value are we getting from the model?
	enum class modelQueryType
	{
		actual,			//!< status from the vehicle
		requested,		//!< requested value to be sent

		// always add before this
		last	//!< Do not use. Used for enumerating the number of enum values 
	};


	class IWpFlagsSource;
	class DrivingLightStatus;
	class ModeStatus;
	class DriveStatus;
	class DriveSystemStatus;
	class ILocalizationStatus;
	class LocalizationStatus;
	class TrackRecording;
	class BatteryStatus;
	class ObstacleStatus;
	class PeripheralStatus;
	class TrafficLightStatus;
	class ErrorStatus;
	class JoystickStatus;
	class RemoteStatus;
	class ChangeMonitor;
}