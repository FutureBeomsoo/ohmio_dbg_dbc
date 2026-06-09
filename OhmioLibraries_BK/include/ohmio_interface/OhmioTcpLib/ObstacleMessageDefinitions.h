#pragma once
namespace OhmioTcp
{
	//! helper for traffic light related TCP communication
	namespace ObstacleMessageDefinitions
	{
		// The messages we can send
		enum class Commands
		{
			Invalid = 0,				//!< Leave 0 unused for converting strings to number 
			ObstacleLocationCommand,	//!< Sets an obstacle at a location
			RemoveObstacleCommand,		//!< remove a static obstacle
			GetDistancesCommand,		//!< Get the current state (distance, envelop, etc)
			GetStaicObsCommand,			//!< Get external obstacles (that are set by  ObstacleLocationCommand)

			// always add above this line
			last
		};
	};
}

