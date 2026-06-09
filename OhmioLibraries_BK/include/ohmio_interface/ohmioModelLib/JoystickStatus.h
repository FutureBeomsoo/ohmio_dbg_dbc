#pragma once
//#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"

namespace OhmioModel
{
	//! State of all the buttons in the joystick
	class JoystickState
	{

	public:
		JoystickState()
			: x(0), y(0), rotation(0), throttle(0), hatswitch(0)
		{
			for (auto& b : buttons)
			{
				b = false;
			}
		}

		~JoystickState() {}
		enum consts 
		{ 
			NumButtons = 12 //! number of buttons
		};

		std::array<bool, NumButtons> buttons;		//!< the individual buttons
		double x;			//!< X position of the stick in [-1, 1] range
		double y;			//!< Y position of the stick in [-1, 1] range
		double rotation;	//!< rotation of the stick in [-1, 1] range
		double throttle;	//!< speed lever in [0, 1] range
		int hatswitch;		//!< no idea what it is (4 bits)
	};

	class JoystickStatus : public Ohmio::IMessageObserver
	{
	public:
		JoystickStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~JoystickStatus();

		//! Call back function that gets called when our message is received
		virtual void MessageCallback(const Ohmio::CAN_MSG& message) override;

		//!< Get the current value
		void GetState(JoystickState& state);

		//! Register an observer to get notified when status changed
		void Register(const std::shared_ptr<IChangeObserver>& notify);

	private:
		void HandleJoystickMessage(const Ohmio::CAN_MSG& message);
		void HandleManualMessage(const Ohmio::CAN_MSG& message);

	private:
		JoystickState m_CurrentState;		//!< current state of the joystick
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change

	};

}
