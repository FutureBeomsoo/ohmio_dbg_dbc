#pragma once

#include "ohmioInterfaceLib/IMessageObserver.h"
#include "canbus/dbc_MsgID_peripheral.h"
#include "canbus/dbc_CAN_peripheral.h"
#include "commonInclude.h"

namespace OhmioModel
{
	//! information about steering
	class Steering
	{
	public:
		Steering() : requested(0), actual(0), current(0), rpm(0), manufactureNo(0){}
		double requested;	//!< requested angle (degrees)
		double actual;		//!< actual angle (degrees)
		double current;		//!< motor current (amperes)
		double rpm;			//!< motor rotation speed
		int manufactureNo;	//!< type of steering	
	};

	//! information about the main motor
	class TractionMotor
	{
	public:
		TractionMotor() : requestedSpeed(0),
		actualSpeed(0), rpm(0), motorTemperature(0), controllerTemperature(0),
			torque(0), current(0), voltage(0), requestedTorque(0), 
			throttleOpenDegree(0), mode(0) {}
		double requestedSpeed;	//!< requested Speed (meters / sec)
		double actualSpeed;		//!< actual Speed (meters / sec)
		double rpm;				//!< motor rotation speed
		double motorTemperature;	//!< degrees
		double controllerTemperature;	//!< degrees
		double torque;			//!< in Nm
		double requestedTorque; //!< requested torque (Nm)
		double current;			//!< amp
		double voltage;			//!< volt
		double throttleOpenDegree; //!< request throttle (%)
		uint64_t mode;            //!< motor3 mode
	};

	//! information about break
	class HydraulicBrake
	{
	public:
		HydraulicBrake() : requestedPressure(0),
			actualPressure(0), current(0), voltage(0), timeAlarm(false),
			ehbError(0), active(0), parkReq(0), activeCount(0), activeWarning(false) {}
		double requestedPressure;	//!< requested pressure (bar)
		double actualPressure;	//!< actual pressure (bar)
		double current;			//!< break current (amperes)
		double voltage;			//!< break voltage (volts)
		bool timeAlarm;			//!< alarm on / off
		uint8_t ehbError;       //!< EHB error
		uint8_t active;         //!< Brake HEB status active or not
		uint8_t parkReq;        //!< Parking Brake request
		int activeCount;		//!< counter for brake operating time
		bool activeWarning;		//!< warning when the brake is on too long
	};

	//! What a break can do
	enum class BreakStaus
	{
		unknown = 0,
		engaged = 1,
		disengaged = 2,
		idle = 3,

		// always add above
		last
	};

	//! information about a parking break
	class ParkingBreak
	{
	public:
		ParkingBreak() : status(BreakStaus::idle), operationsMode(BreakStaus::idle), current(0) {}
		BreakStaus status;			//!< current status
		BreakStaus operationsMode;	//!< change requested
		double current;				//!< current (amperes)
	};


	//! information about all parking breaks
	class BreakSystem
	{
	public:
		BreakSystem() : requested(BreakStaus::idle) {}
		BreakStaus requested;	//!< requested status
		std::array<ParkingBreak, 2> parkBreaks; // the 2 EPB
	};

	//! monitor the drive system (steering, speed, etc) status
	//
	//! Note that the data is not exactly real time.
	//! The system keeps track of the latest values of localization.
	//! Whenever new message is received the data is updated. When
	//! asking for data user may receive a combination of old and new data
	class DriveSystemStatus : public Ohmio::IMessageObserver
	{
	public:
		DriveSystemStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~DriveSystemStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Get the current status of the motor
		void GetMotorData(TractionMotor& data);

		//! Get the current status of the steering
		void GetSteeringData(Steering& front, Steering& rear);

		//! Get the current status of the Hydraulic Brake unit
		void GetHydraulicBrakData(HydraulicBrake& data);

		//! Is the hydraulic brake on too long?
		bool IsHydraulicBrakeAlarm();

		//! Get the current status of the parking Brakes
		void GetParkingBrakData(BreakSystem& data);

		//! are 
		bool IsEpbEngaged();

		//! Set the wheel radius of the vehicle. For converting rad/sec to m/sec
		void SetWheelRadius(double radius);

		//! Set the gearing ratio of the motor. For converting rad/sec to RPM
		void SetGearRatio(double gear);

		double GetOdometerValue();

		//! Get the final status from both the epb status and mode
		P_EPB_STATUS Get_EPB_Status(uint8_t status, uint8_t mode);

		//! Is there an error in the braking system?
		//
		//!@param[out] epb - true if EPB (park brake) error
		//!@param[out] ehb - true if EHB (hydraulic brake) error
		//!@param[out] motor - true if motor error
		void GetBrakingErrors(bool& epb, bool& ehb, bool& motor);



	private:
		///@{
		//! Receive a specific message and update status
		void ReceiveSteeringMessage(const Ohmio::CAN_MSG & message);
		void ReceiveSteeringRequestMessage(const Ohmio::CAN_MSG & message);
		void ReceiveSteeringRequestCombinedMessage(const Ohmio::CAN_MSG & message);
		void ReceiveSteeringErrorMessage(const Ohmio::CAN_MSG & message);
		void ReceiveSpeedRequest(const Ohmio::CAN_MSG & message);
		void ReceiveSpeedResponseMessage(const Ohmio::CAN_MSG & message);
		void ReceiveHydraulicBreakMessage(const Ohmio::CAN_MSG & message);
		void ReceiveHydraulicBreakStausMessage(const Ohmio::CAN_MSG & message);


		void ReceiveHydraulicBreakStausPowerMessage(const Ohmio::CAN_MSG & message);
		void ReceiveHydraulicBreaksT060PowerMessage(const Ohmio::CAN_MSG & message);
		void ReceiveHydraulicBreakErrorMessage(const Ohmio::CAN_MSG & message);
		void ReceiveParkBreakRequestMessage(const Ohmio::CAN_MSG & message);
		void ReceiveParkBreakResponseMessage(const Ohmio::CAN_MSG & message);
		void ReceiveNewMotorMessage(const Ohmio::CAN_MSG & message);
		void ReceiveNewMotorMessageAdditional(const Ohmio::CAN_MSG & message);
		void ReceiveNewMotorRequestMessage(const Ohmio::CAN_MSG & message);
		void ReceiveOdometertMessage(const Ohmio::CAN_MSG & message);
		void RecieveParameterMessage(const Ohmio::CAN_MSG & message);
		void RecieveSteeringId(const Ohmio::CAN_MSG & message);
		///@}

		//! Is any of the units in the list in error currently  
		bool AreUnitsInError(const std::vector<int>& units);

		//! is the hydraulic brake held too long?
		void CheckHydraulicBrakeOvertime();

	private:
		BreakSystem m_parkingBreaks;	//!< the parking break system
		Steering m_frontSteering;		//!< front steering
		Steering m_rearSteering;		//!< rear steering
		TractionMotor m_motor;			//!< the motor
		HydraulicBrake m_hydraulicBreak;			//!< the break 
		double m_wheelRadius;			//!< radius of wheel (meters) for converting rad/sec to m/sec
		double m_gearRatio;				//!< gearing for converting rad/sec to RPM
		double m_odomer;				//!< total drive distance (m)
		std::shared_ptr< ErrorStatus> m_errors;	//!< monitor error state 
	};
}

