#pragma once

#include "InterfaceManager.h"
#include "ohmioModelLib/DriveSystemStatus.h"

namespace OhmioInterfacePy
{
	//! The drive system API see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/1112211506/API+Functions?focusedCommentId=1121419265
	class DriveSystemStatusInterface
	{
	public:
		DriveSystemStatusInterface(InterfaceManager& manager);
		~DriveSystemStatusInterface();

		//! Get the current status of the motor
		void GetMotorData(OhmioModel::TractionMotor& data);

		//! Get the current status of the steering
		void GetSteeringData(OhmioModel::Steering& front, OhmioModel::Steering& rear);

		//! Get the current status of the Hydraulic Brake unit
		void GetHydraulicBrakData(OhmioModel::HydraulicBrake& data);

		//! Get the current status of the parking Brakes
		void GetParkingBrakData(OhmioModel::BreakSystem& data);

		//! Set the wheel radius of the vehicle. For converting rad/sec to m/sec
		void SetWheelRadius(double radius);

		//! Set the gearing ratio of the motor. For converting rad/sec to RPM
		void SetGearRatio(double gear);


	private:

	};
}
