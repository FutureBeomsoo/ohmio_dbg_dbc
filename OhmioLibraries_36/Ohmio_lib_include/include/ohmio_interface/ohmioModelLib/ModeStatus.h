#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"

namespace OhmioModel
{
	//! State of the vehicle
	class ModeStatus : public Ohmio::IMessageObserver
	{
	public:
		ModeStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~ModeStatus();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;


		//! Register an observer to get notified when status changed
		void Register(const std::shared_ptr<IChangeObserver>& notify);

		//! what is the state of the vehicle
		int GetCurrentState();

		//! Was a shutdown request sent
		bool IsShutdown();

		//! Was a reset request sent to any unit
		bool IsReset();


	private:
		//! Update the current status for a new message
		bool UpdateStatus(int mode);

		//! Tell all the observers that the status has changed 
		void NotifyChange();

		//! get the driving mode
		int GetModeFromDriveMessage(const Ohmio::CAN_MSG & message);

		//! We got a sutdown / reset message
		void HandleRestMessage(const Ohmio::CAN_MSG& message);

	private:
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
		int m_currentMode;		//!< current state (from SYS_STATES enum)
		bool m_reset;			//!< we are in reset mode
		bool m_shutdown;		//!< we are in shutdown mode
	};

}


