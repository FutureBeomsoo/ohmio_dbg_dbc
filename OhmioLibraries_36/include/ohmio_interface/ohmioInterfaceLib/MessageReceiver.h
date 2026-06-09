#pragma once

#include "CommonInclude.h"
#include "UtilityLib/RunInThreadForever.h"
#include <functional>

namespace Ohmio
{
	//! Receive CAN messages and dispatch them to whoever cares
	//
	//! Implements observer pattern. Classes that want to be called for a message 
	//! need to register and get called. Multiple observers can register
	//! for the same message. An observer can register for multiple messages.
	//! Thread safety is ensured by using a mutex over Register, DeRegiste, and 
	//! ReceivedMessage. This prevents 2 threads accessing m_messageMap at the same time.
	//! This may be improved by using separate read and write locks. Requiring 
	//! read access for Receiving messages and write access for Register / Deregister
	class MessageReceiver : public Threading::RunInThreadForever
	{
	public:
		//! Constructor
		//
		//! Creates a thread that monitors the buffer and notify all registered
		//! observer whenever a new (and relevant) message arrives.
		//! @param[in] buffer - message buffer to monitor.
		MessageReceiver(std::shared_ptr<MessageBuffer> buffer);
		~MessageReceiver();


		//! Called by the CAN whenever a new message is received.
		//
		//! Normally this is called by the massage receiving thread.
		//! To make testing easier this function is public allowing
		//! direct call 
		//! Uses the map to notify everybody that cares about it.
		//! @param[in] theMessage - the message we got
		void ReceivedMessage(const CAN_MSG& message);

	private:
		// Only the base IMessageObserver can register and deregister messages.
		// This makes sure we deregister on destruction and avoid crashing when 
		// a message that a destructed class was registered to.
		friend class IMessageObserver;

		//! Register an a callback for a message
		//
		//! Register to tell us you want to know about a message
		//! @param[in] observer - the function to call when we receive a message
		//! @param[in] id - the message id the observer want to know about. Registering
		//! to ID 0 will register to ALL messages
		//! @return a unique id of the callback. Caller must retain this Id and use it for deregistering 
		size_t Register(std::function<void(const CAN_MSG&)> observer, uint64_t id);

		//! Unregister an a callback for a message
		//
		//! Remove this callback from the list. Must be called in the destructor of the 
		//! class that called Register
		//! @param[in] uid - the unique ID returned by Register
		void Deregister(size_t uid);

	protected:
		//RunInThreadForever interface
		void RunLoopOnce() override;
		std::string GetDiagnosticName() override;
		int GetWatchdogPeriod() override;



	private:

	private:
		//! Holds a callback and a unique ID
		class ReceiverInfo
		{
		public:
			std::function<void(const CAN_MSG&)> callback;	//!< the callback function
			size_t uid;										//!< id of the callback
		};

		//! Collection of callback functions to call for messages
		std::multimap< uint64_t, ReceiverInfo> m_messageMap;
		std::mutex m_mutex;							//!< for locking access to registration. 
		std::shared_ptr<MessageBuffer> m_buffer;	//!< message buffer to get messages from


	};

}

