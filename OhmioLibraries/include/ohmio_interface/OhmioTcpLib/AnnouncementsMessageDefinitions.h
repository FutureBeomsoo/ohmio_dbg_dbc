#pragma once

namespace OhmioTcp
{
	//! helper for buss stop related TCP communication
	namespace SoundDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,			//!< Leave 0 unused for converting strings to number 
			SoundRequest,			//!< request to play a sound file

			// always add above this line
			last
		};
	};




}

