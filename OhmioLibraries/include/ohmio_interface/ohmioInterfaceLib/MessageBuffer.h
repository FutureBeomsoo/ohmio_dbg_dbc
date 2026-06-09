#pragma once
#include "CommonInclude.h"
#include <mutex>
#include <condition_variable>
#include <deque>

//! we need to make the test friend so that it can control the lock for testing
namespace OhmioTests
{
	class MessageBufferTests;
}

namespace Ohmio
{

	//! A message buffer. Holding a FIFO of messages to be exported to destinations (files and or TCP servers)
	//
	//! All public methods (PushMessage, PopMessage and WaitForNewMessage) lock a mutex to make the system if
	// thread safe.
	//! The design assumes that on average pop is called at least at the same rate as push so that
	//! the buffer doesn't grow beyond maximum size. If the buffer exceeds the maximum size
	//! the oldest messages are removed 
	class MessageBuffer
	{
	public:
		//! Constructor
		//
		//! @param[in] maxBufferSize - limit the number of messes in the buffer to this.
		//! if maxBufferSize <= 0 no limit
		MessageBuffer(int maxBufferSize);
		~MessageBuffer();


		//! Add a message to the buffer
		//
		//! Lock the buffer and add a message at the end
		//! @param[in] message - The message to add
		void PushMessage(const std::shared_ptr<CAN_MSG>& message);


		//! Get the oldest message from the buffer and remove it
		//
		//! Lock, get the message and remove it from the buffer.
		//! Should be called when the buffer is not empty but will return
		//! an empty message with no destination if empty
		//! @return the oldest message in the buffer or an empty message
		std::shared_ptr<CAN_MSG> PopMessage();

		//! Wait for a new message
		//
		//! sleep until a new message arrives or timeout
		//! @param[in] timeout - maximum time to wait (mSec)
		//! @return true if buffer is not empty
		bool WaitForNewMessage(int timeout);

		//! How many messages are in the buffer now? This is public to help in testing
		int GetBufferSize();


	private:
		//! allow the unit test access to the private members for testing of threading
		friend class OhmioTests::MessageBufferTests;


		std::deque<std::shared_ptr<CAN_MSG>> m_buffer;		//!< The actual buffer
		std::mutex m_mutex;						//!< for locking the new message event and the buffer  
		std::condition_variable m_newMessage;	//!< new message event
		int m_maxSize;							//!< max size of the buffer
	
	};
}

