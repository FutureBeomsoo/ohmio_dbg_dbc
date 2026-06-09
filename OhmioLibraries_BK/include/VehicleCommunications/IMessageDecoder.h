#pragma once


#include <vector>
#include <string>
#include "MessageFrame.h"

namespace V2XComms
{
	//! Interface for message decoding
	class IMessageDecoder
	{
	public:
		virtual void Decode(std::string& result) = 0;

	};


}

