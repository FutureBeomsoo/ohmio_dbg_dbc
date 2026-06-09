#pragma once
#include "ohmioInterfaceLib/IMessageObserver.h"

namespace OhmioControl
{
	//! Answer to version requests
	class VersionResponder : public Ohmio::IMessageObserver
	{
	public:
		VersionResponder(std::shared_ptr<Ohmio::MessageReceiver> receiver, std::shared_ptr<Ohmio::MessageBuffer> writeBuffer);
		~VersionResponder();

		// Inherited via IMessageObserver
		virtual void MessageCallback(const Ohmio::CAN_MSG & message) override;

		//! Create a version message and send
		void AswerVersionRequest(const Ohmio::CAN_MSG & message);

	private:

		std::shared_ptr<Ohmio::MessageBuffer> m_writeBuffer;	//!< for sending to vehicle
	};

}

