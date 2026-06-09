#pragma once
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "ohmioModelLib/PeripheralStatus.h"

namespace OhmioControl
{

	//! What we want the air condition to do
	class AirConRequest
	{
	public:
		double temp;		//!< desired temperature (def)
		OhmioModel::AirConMode mode;	//!< what we want it todo
		uint8_t level;		//!< David what is it?

	};
	
	//! Control peripheral devices (door, step, etc). 
	class IPeripheralControl
	{
	public:
		//! Get device state
		//
		//! @param[in] device - the device to ask
		//! @return - the state of the device
		virtual OhmioModel::deviceState GetDeviceState(OhmioModel::peripheralDevices device) = 0;

		//! Is device in error?
		//
		//! @param[in] device - the device to ask
		//! @param[out] errorCode - the error codes from the device
		//! @return - true if error
		virtual bool IsDeviceError(OhmioModel::peripheralDevices device, int& errorCode) = 0;

		///@{
		//! Operate a device
		//
		//! @param[in] on - if true turn the device on (open door, extend step etc)
		//!					if false turn the device off (close door, retract step etc)
		virtual void SetDoor(bool on) = 0;
		virtual void SetStep(bool on) = 0;
		///@}


		//! Are devices controlled by the system (false) or by operator (true)
		virtual bool IsManualOverride() const = 0;

		//! Set devices control by the system (false) or by operator (true)
		virtual void ManualOverride(bool manual) = 0;

		//! Deactivate all the devices so that we can start driving 
		//
		//! close door, retract step, etc
		//! Prepare To Drive 
		virtual void PrepareToDrive() = 0;

	};

	//! Control peripheral devices, door, foot step, lift, air condition etc
	//
	//! Note that this class deviated from the model - controller paradigm it is both model and control
	//! see https://hmitechnologies.atlassian.net/wiki/spaces/EN/pages/2474541057/Peripherals+control
	class PeripheralControl : public IPeripheralControl, public Threading::RunInThreadForever, public Ohmio::IMessageObserver
	{
	public:
		//! Constructor
		//
		//! @param[in] receiver - how we get messages from the vehicle
		//! @param[in] writeBuffer - how we send messages to the vehicle
		//! @param[in] safety - to know when we may operate peripherals
		//! @param[in] heartBitMSec - send door heart bit every X mSec. Should be 1000 on the vehicle
		//! but for testing we can use much faster rate to make the test faster
		PeripheralControl(std::shared_ptr<Ohmio::MessageReceiver> receiver,
			std::shared_ptr<Ohmio::MessageBuffer> writeBuffer,
			std::shared_ptr<Ohmio::SafetyRegulator> safety,
			int heartBitMSec);

		~PeripheralControl();


		//! Set a source for getting flags information. 
		//
		//! Should be injected in contractor but I get a conflict with creating the drive control 
		void SetFlagsSource(std::shared_ptr<OhmioModel::IWpFlagsSource> wpFlagsSourse);


		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		// IPeripheralControl interface
		virtual OhmioModel::deviceState GetDeviceState(OhmioModel::peripheralDevices device) override;
		virtual bool IsDeviceError(OhmioModel::peripheralDevices device, int& errorCode) override;
		virtual void SetDoor(bool on) override;
		virtual void SetStep(bool on) override;
		virtual bool IsManualOverride() const override;
		virtual void ManualOverride(bool manual) override;
		virtual void PrepareToDrive() override;

		//! Operate the lift and footing
		//
		//! @param[in] lift_on - if true turn the lift on
		//! @param[in] foot_command - 0-idle, 1-down, 2-up
		void SetFoot(int footCommand, bool liftOn);

		//! Is the horn beeping
		bool IsHornOn();

		//! Turn horn on / off. 
		//
		//! Call with true to set the horn on
		//! Call with false to set the horn to be controlled by jotstick commands
		void BeepHorn(bool on);

		//! Get the air condition information
		//
		//! @param[out] roomTemp - room temperature (deg)
		//! @param[out] airConTemp - air condition temperature (deg)
		void GetAirConState(double& roomTemp, double& airConTemp);

		//! Set the air condition level
		void SetAirCon(const AirConRequest& request);

		//! Get the allowed range of temperature for air con
		//
		//! @param[out] minTemp - min temperature (deg) to use
		//! @param[out] maxTemp - max temperature (deg) to use
		void GetAirConTempRange(double& minTemp, double& maxTemp);

		//! turn the flash light in the air con unit on / off
		void SetFlash(bool on);

		//! Get the AVAS status
		void GetAvasState(OhmioModel::AvasStatus& status);

		//! Callback for state change
		//
		//! @param[in] deviceId - which device changed state
		void PeripheralStateChanged(int deviceId);

		//! For handling step hardware issue in Sydney
		//
		//! Should Only be called to set it to 5 on the problem vehicle untill the error is fixed
		void SetStepRetry(int retry);

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:

		///@{
		//! Update current state from incoming message
		void UpdateDriveState(const Ohmio::CAN_MSG & message);
		void UpdateDriveStateLongWp(const Ohmio::CAN_MSG & message);
		void UpdateDriveRequest(const Ohmio::CAN_MSG & message);
		///@}



		///@{
		//! The state of the vehicle has changed. We need to act on it 
		void DoorStateChanged();
		void StepStateChanged();
		void FootStateChanged();
		void LiftStateChanged();
		void DrivingModeChanged(int mode);
		///@}

		//! send the periodic air con command
		void SendAirconHeartBit();

		//! Send the door periodic message
		void SendDoorHeartbit();

		//! Check if the door is open and we need to push the step out
		void ExtendStepIfNeeded();

		void SendHornMsg();
	private:

		//! What do we want the door to do
		class DoorCommandToSend
		{
		public:
			bool change;	//!< should we send a command (true) or idle (false)
			bool open;		//!< should we send an open (true) or close (false) if change
		};

		//! Helper class to get notified when peripherals (door) state changes
		class DoorChangeObserver : public OhmioModel::IChangeObserver
		{
		public: 
			DoorChangeObserver(PeripheralControl& controller) : m_controller(controller) {}
			~DoorChangeObserver() {}

			virtual void OnChanged(int param) override
			{
				m_controller.PeripheralStateChanged(param);
			}

			PeripheralControl& m_controller;

		};

		std::shared_ptr<OhmioModel::PeripheralStatus> m_status;	//!< current status of peripherals
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_flagsInfo;	//!< source for WP information
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for sending to vehicle
		std::shared_ptr<Ohmio::SafetyRegulator> m_safety;		//!< for knowing if it is safe to operate devices
		std::shared_ptr<DoorChangeObserver> m_changeHelper;		//!< Get called when peripheral state changes
		std::shared_ptr<OhmioModel::JoystickStatus> m_joystick;		//!< state of the joystick (to beep the horn)
//		std::shared_ptr<OhmioModel::ChangeMonitor> m_joystickChange;	//!< Get notified when joystick state changes

		bool m_driving;			//!< are we driving now?
		bool m_manualOverride;	//!< devices are manually controlled by operator
		bool m_hornOn;			//!< horn is on from UI request
		int m_currenrMode;		//!< current vehicle mode
		int m_doorRetryCount;	//!< if door is in error retry sending a few times
		std::chrono::high_resolution_clock::time_point m_lastSendTime; //!< last time we sent a door heart bit
		std::chrono::high_resolution_clock::time_point m_lastStepTime; //!< last time we sent a step command
		int m_heartBitPeriod;	//!< time (mSec) for door hart bit
		int m_step_req_counter; //!< counter for the step request
		AirConRequest m_airConReq;		//!< what we want the air condition to do
		bool m_alarmOn;			//!< should turn on the flash light
		DoorCommandToSend m_doorCommand;	//!< what should the door do next time we send request
		double m_airconMinTemp;	//!< can't request lower temperature
		double m_airconMaxTemp;	//!< can't request higher temperature

		int m_stepInCount;		//!< for fixing hardware bug in step on Sydney vehicle
		int m_stepRetry;		//!< how many times to retry step command for fixing hardware bug in step on Sydney vehicle
	};
}


