#pragma once
//#include "ohmioInterfaceLib/CommonInclude.h"
#include "ohmioInterfaceLib/IMessageObserver.h"
#include "commonInclude.h"

namespace OhmioModel
{
	class RemoteStatus : public Ohmio::IMessageObserver
	{
	public:
		RemoteStatus(std::shared_ptr<Ohmio::MessageReceiver> receiver);
		~RemoteStatus();

		//! Call back function that gets called when our message is received
		virtual void MessageCallback(const Ohmio::CAN_MSG& message) override;

		//!< Get the current value
		//@{
		bool GetEmergency();
		bool GetGo();
		bool Gethorn();
		//@}

		//! Register an observer to get notified when status changed
		void Register(const std::shared_ptr<IChangeObserver>& notify);

	private:

		void HandleRemotekMessage(const Ohmio::CAN_MSG& message);

	private:
		std::vector<std::shared_ptr<IChangeObserver>> m_changeNotify;	//!< tell these when status change
		bool m_emergency;		//!< current state of the emergency button
		bool m_go;				//!< current state of the 'go' button
		bool m_horn;			//!< current state of the horn button

	};

}
