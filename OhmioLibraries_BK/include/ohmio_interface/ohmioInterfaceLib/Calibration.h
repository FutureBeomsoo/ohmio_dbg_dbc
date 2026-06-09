#pragma once

#include "IMessageObserver.h"
#include "UtilityLib/RunInThreadForever.h"

namespace Ohmio
{
	//! Handle calibration. For now just steering 
	//
	//! Construct the calibration object when needed and destruct when done. 
	//! What it does
	//! on start (constructor)
	//! - start sending CAN_ID_STEER_REQUEST(0x690) every 20ms.
	//! - send CAN_ID_STEER_ID_REQUEST(0x682) to each unit to get current factor
	//! - Enable driving with door opened
	//! While in calibration send CAN_ID_CALIBRATION(0x680) multiple times according to user commands
	//! - Send CAN_ID_CALIBRATION(0x680)
	//! - send CAN_ID_STEER_ID_REQUEST(0x682) to each unit to get updated factor
	//! - send reset(0x40) to each unit
	//! Exit calibration (destructor)
	//! - send reset(0x40) to drive control – this is done by the user in the old version
	//! - Disable driving with door opened
	//! See https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/2146959363/Steering+Calibration+Software+Flowchart
	class Calibration : public IMessageObserver, public Threading::RunInThreadForever
	{
	public:
		//! Constructor 
		//
		//! @param[in] receiver - to get messages from the vehicle
		//! @param[in] outputBuffer - buffer for messages to the vehicle
		//! @param[in] safety - need to inform the regulator to allow drivinhg with door open
		//! @param[in] startThread - send calibraion message periodicaly. Shoulsd always be on
		//! but can turn off to simplify testing
		Calibration(std::shared_ptr<MessageReceiver> receiver, std::shared_ptr<MessageBuffer> outputBuffer,
			std::shared_ptr<SafetyRegulator> safety, bool startThread = true);

		~Calibration();

		//! Do we have all the data and are ready for calibration?
		bool IsReady();

		//@{
		//! Get the ACTUAL steering values
		//
		//! This returns the actual values from the rig not the requested values
		//! @param[out] calibrationSet - true if calibration values are vakid in this unit
		//! @param[out] factorsSet - true if factors values are vakid in this unit
		//! @return the steering angle in degrees (negativde is left)
		double GetFrontSteeringValues(bool& calibrationSet, bool& factorsSet);
		double GetRearSteeringValues(bool& calibrationSet, bool& factorsSet);
		//@}

		//@{
		//! Get the steering factors
		bool GetFrontSteeringFactors(double& positive, double& negative);
		bool GetRearSteeringFactors(double& positive, double& negative);
		//@}

		//@{
		//! Set the steering factors
		//
		//! @param[in] positive - positive steering factor
		//! @param[in] negative - negative steering factor
		//! @param[in] waitTime - wait this much (mSec) before sending a request.
		//! Normaly waits 1 second but for unit testing can call with shoter time to avaoid wait
		void SetFrontSteeringFactors(double positive, double negative, int waitTime = 1000);
		void SetRearSteeringFactors(double positive, double negative, int waitTime = 1000);
		//@}

		//@{
		//! Set the current steering position as the straight position
		//! @param[in] waitTime - wait this much (mSec) before sending a request.
		//! Normaly waits 1 second but for unit testing can call with shoter time to avaoid wait
		void SetFrontSteeringCentre(int waitTime = 1000);
		void SetRearSteeringCentre(int waitTime = 1000);
		//@}

		//! Set the steering angles (for calibration)
		//
		//! @param[in] front - angle in degrees (positive is to the right)
		//! @param[in] rear - angle in degrees (positive is to the right)
		void SetSteeringAngles(double front, double rear);

		//! Set the currently connected unit to font or rear
		//
		//! For installation. Connect only the right unit to the bus
		//! Call with true for front or false for rear. It will set the right
		//! Id for the unit
		void SetUnitId(bool front);
	

		// IMessageObserver interface
		void MessageCallback(const CAN_MSG& message) override;

	protected:
		//! Do the job of a single run of the endless loop
		virtual void RunLoopOnce()override;

		//! Get the name of this thread for diagnostics
		virtual std::string GetDiagnosticName() override;

		//! What is the period that this thread should report to the watchdog? 
		virtual int GetWatchdogPeriod() override;

	private:
		//@{
		//! Handle received message
		void ReceiveSteeringConfigResponce(const CAN_MSG& message);
		void ReceiveSteeringValues(const CAN_MSG& message);
		//@}


		//! Set current position as straight for the correct unit
		void SetSteeringCentre(int unitId, int waitTime);

		//! Set the steering factors for the correct unit
		void SetSteeringFactors(int unitId, double positive, double negative, int waitTime);

		//! ask the steering for its calibration values
		void RequestSteeringFactors(int unitId);

		//! send a reset request to a unit
		void SendResetRequest(int unitId);


	private:
		std::shared_ptr<MessageBuffer> m_writeBuffer;	//!< to send messages to vehicle
		std::shared_ptr<SafetyRegulator> m_safety;		//!< to set it in calibration
		std::map<int, std::pair<double, double>> m_steeringFactors; //!< the steering factors
		double m_actualFrontAngle;		//!< actual streeing angle of front unit
		double m_actualRearAngle;		//!< actual streeing angle of rear unit
		double m_requestedFrontAngle;	//!< requested streeing angle of front unit
		double m_requestedRearAngle;	//!< requested streeing angle of rear unit
		bool m_frontCalibrationSet;		//!< front unit calibration is set
		bool m_frontFactorSet;			//!< front unit factors are set
		bool m_rearCalibrationSet;		//!< rear unit calibration is set
		bool m_rearFactorSet;			//!< rear unit factors are set
		bool m_enableDoorWhenExit;		//!< should we allow driving with door open when we are done?
		std::chrono::high_resolution_clock::time_point m_lastRequest;		//!< time of last request sent
	};
}
