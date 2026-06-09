#pragma once


namespace OhmioTcp
{
	//! helper for traffic light related TCP communication
	namespace TrafficLightMessageDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,			//!< Leave 0 unused for converting strings to number 
			GoCommand,				//!< Sets the current light status (red, green, etc) and ID
			StatusRequest,			//!< Get current state
			AddLightCommand,		//!< crtae a traffic light

			// always add above this line
			last
		};
	};
}

