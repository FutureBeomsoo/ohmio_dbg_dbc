#pragma once

#include <iostream>
#include <vector>
#include "CommonInclude.h"

namespace Ohmio
{
	//! Interface for a can bus writer / reader. To allow unit tests
	class ICanBus
	{
	public:
		virtual bool initCanbus() = 0;
		virtual void quitCanbus() = 0;
		virtual bool GetPortStatus() = 0;


		//! Read current messages from the bus
		//
		//! @param[out] can - the messages we got
		//! @param[in] CANInd - the buss ID to read from (0 or 1)
		//! @return true if write success. false otherwise
		virtual bool ReadCanbus(std::vector<CAN_MSG>& msg, CanBuses CANInd) = 0;

		//! Write a single message to the bus
		//
		//! @param[in] can - the message to send (bus to write to is contained in the message)
		//! @return true if write success. false otherwise
		virtual bool WriteCanbus(const CAN_MSG& msg) = 0;

		//! Write a multiple messages to the bus
		//
		//! @param[in] can - the messages to send
		//! @param[in] CANInd - the buss ID to write too (0 or 1).
		//! Caller is responsible to make sure all the messages are for the 
		//! correct bus
		//! @return true if write success. false otherwise
		virtual bool WriteCanbusMulti(std::vector<CAN_MSG>& messages, CanBuses CANInd) = 0 ;

		//! Is this a mock bus for testing?
		virtual bool IsMock() = 0;

		//! Have we established communication with the physical bus?
		virtual bool IsConnected() = 0;
	};

}

