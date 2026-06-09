#pragma once

namespace OhmioTcp
{
	//! helper for recording related TCP communication
	namespace RecordingMessageDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,			//!< Leave 0 unused for converting strings to number 
			StartTrack,				//!< start recording a track
			EndTrack,				//!< finish recording a track
			GetLocation,			//!< Get direction of driving
			GetTrackLength,			//!< how long is the track
			GetCurSpeed,			//!< Get vehicle speed
			GetMaxSpeed,			//!< Get max speed allowed
			GetCurrentState,		//!< Get current vehicle state
			IsReverse,				//!< Get direction of driving
			GetUploadState, 		//!< Get results of upload
			UploadTrack,			//!< Upload a track


			// always add above this line
			last
		};
	};
}
