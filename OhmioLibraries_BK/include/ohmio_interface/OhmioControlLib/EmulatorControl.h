#pragma once
#include "UtilityLib/RunInThreadForever.h"
#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioModelLib/DriveStatus.h"

namespace OhmioControl
{
	//! Fake joystick for emulator
	class stu_Joystick
	{
	public:
		double steering;
		int speed;
		bool start;
		bool reverse;
		bool breaking;

		void init()
		{
			steering = 0.0;
			speed = 0;
			start = false;
			reverse = false;
			breaking = false;
		}

		void reset()
		{
			init();
		}

		stu_Joystick()
		{
			init();
		}

		stu_Joystick& operator = (const stu_Joystick& others)
		{
			this->steering = others.steering;
			this->speed = others.speed;
			this->start = others.start;
			this->reverse = others.reverse;
			this->breaking = others.breaking;
			return *this;
		}
	};


	//! handle special features that only the emulator supports
	class EmulatorControl : public Threading::RunInThreadForever
	{
	public:
		//! Constructor
		//
		//! @param[in] vehicle - how to get access to messages
		//! @param[in] wpSourse - needed for converting WP index to location
		EmulatorControl(std::shared_ptr<Ohmio::CommunicationManager> vehicle, std::shared_ptr<OhmioModel::IWpFlagsSource> wpSource);
		~EmulatorControl();

		//! Start / stop emulating a joystick
		void EmulateJoystick(bool emulate);

		//! Set the joystick command to send 
		void SetJoystickState(const stu_Joystick& joystick);

		//! Reset the current location to the default position or to a specific WP
		//
		//! @param[in] wpIdx - the WP to jump to. usualy called with 0. 
		//! if < 0 use the hardcoded default value
		void ResetLocation(int wpIdx = 0);

	protected:
		// RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;

	private:
		//! Send the fake joystick message
		void SendJoystickMessage();

        //! convert linear angle to curve
		int16_t convertToExpCurve(int16_t value, uint8_t power);

	private:
		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;		//!< for writing to the vehicle
		std::shared_ptr<OhmioModel::DriveStatus> m_driveStatus;		//!< to monitor the status
		std::shared_ptr<OhmioModel::IWpFlagsSource> m_wpSource;		//!< For getting location from WP
		stu_Joystick m_joyStick;		//!< to save the fake joystick status 
		bool m_emulateJoytick;										//!< should we emulate the joystick
	};
}

