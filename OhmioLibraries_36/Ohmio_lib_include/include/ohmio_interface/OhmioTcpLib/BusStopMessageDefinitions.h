#pragma once

namespace OhmioTcp
{
	//! helper for buss stop related TCP communication
	namespace BusStopMessageDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,			//!< Leave 0 unused for converting strings to number 
			SetStopLocation,		//!< set a bus stop
			ActivateBusStop,		//!< enable / disable a stop
			Go,						//!< drive again after stopping
			GetAllStops,			//!< get all the stop locations
			GetTrackId,				//!< what track are we driving
			GetCurrentWp,			//!< where are we now
			IsStopped,				//!< are we stopped
			Hold,					//!< hold the vehicle (no drive no door close)
			Release,				//!< release from hold
			IsHold,					//!< are we waiting for 'release' before we can go

			// always add above this line
			last
		};
	};
}

