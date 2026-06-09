#pragma once

#include "MessageFrame.h"

namespace V2XComms
{
	//! Decode V2X message
	class MessageDecoder
	{
	public:
		MessageDecoder();
		~MessageDecoder();

		//! Decode a message 
		//
		//! @param[in] message - the ASN message
		//! @param[out] result - the decode message as JSON string
		void Decode(const std::vector<uint8_t>& message, std::string& result);

	private:

		// Decode the message
		void DecodeMessage(MessageFrame_t * msg, std::string& result);
	};

}
