#pragma once


namespace OhmioTcp
{
	//! helper for buss stop related TCP communication
	namespace DriveControlMessageDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,			//!< Leave 0 unused for converting strings to number 
			Go,						//!< 'Go' button pressed
			Stop,					//!< 'Stop' button pressed
			Start,					//!< 'start' button pressed
			StopAtLocation,			//!< Stop at location defined by tat, long
			StopAtWp,				//!< Stop at location defined WP
			Speed,					//!< set max speed
			Track,					//!< select track
			GetMode,				//!< Get driving mode
			GetTrack,				//!< Get track (1F/ 2R, ...)
			GetSpeed,				//!< Get max speed
			Overtake,				//!< perform over take manouver or return from overtake


			// always add above this line
			last
		};
	};




}


