#pragma once

#include "CommonInclude.h"
#include <vector>


namespace Ohmio
{
	//! Interface class for an observer interested in a message
	//
	//! To implement an observer:
	//! - override MessageCallback to handle the requested messages
	//! - call RegisterToMessage in the constructor for all the message IDs to be called
	class IMessageObserver
	{
	public:
		IMessageObserver(std::shared_ptr<MessageReceiver> receiver);
		virtual ~IMessageObserver();

		//! Call back function that gets called when our message is received
		virtual void MessageCallback(const CAN_MSG& message) = 0;

	protected:
		//! Register a call back
		void RegisterToMessage(IMessageObserver* observer, uint64_t id);

		//! Stop listening to messages
		void DeregisterAll();

	private:
		std::vector<size_t> m_registeredCallbacks;			//! the unique IDs of all our callback functions so that we can deregister
		std::shared_ptr<MessageReceiver> m_receiver;		//! the receiver we registered with (so that we can deregister)

	};
}

