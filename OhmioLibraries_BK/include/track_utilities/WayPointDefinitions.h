#pragma once

// Definition of track related information
// way points, headers, flags etc

#ifdef __cplusplus 
#include <cstdint>
#else
#include <stdint.h>
#ifndef __PC_SIM
#include "app.h"
#endif
#endif


//! Track file header
typedef struct
{
	uint64_t trackId;
	uint8_t  trackName[128];
	uint8_t  trackType;
	uint32_t noOfWp;
	uint64_t MD5Loc;
	uint64_t MD5Full;

}OHMIO_PATH_INFO_t;

typedef struct
{
	double latitude;
	double longitude;
	double heading;
	uint16_t lookAheadDistance;
	uint16_t speed;
	uint16_t eventFlag1;
	uint16_t eventFlag2;
}WAY_POINT_DRIVE_t;

//! Full track way point
typedef struct
{
	WAY_POINT_DRIVE_t wp;
	uint32_t wpNo;               //way point number
}OHMIO_WAY_POINT_DRIVE_t;

//! Just location way point way point
typedef struct {
	double latitude;
	double longitude;
	double latitude2;
	double longitude2;
	uint32_t wpNo;               //way point number

}OHMIO_WAY_POINT_LOC_t;


//! Values of way point eventFlag1
enum wayPointeventFlag
{
	indicateLeft =		0x0001,			//!< Need to indicate left in this location
	indicateRight =		0x0002,			//!< Need to indicate right in this location
	LaneChangeLeft =	0x0004,			//!< This is the point where we are already blocking the new lane and should stop for vehicles behind us
	LaneChangeRight =	0x0008,			//!< This is the point where we are already blocking the new lane and should stop for vehicles behind us
	trafficLight =		0x0010,			//!< Cannot pass this point if no green light 
	busStop =			0x0020,			//!< Fixed bus stop at this location. Should stop for passengers
	pedCrossing =		0x0040,			//!< Crossing. Should look for obstacles in mapped danger zones
	junction =			0x0080,			//!< Junction with mapped danger zones. Similar to lane change but danger zone is mapped
	junctionManual =	0x0100,			//!< Junction. Stop and wait for user command to go forward
	speedBump =			0x0200,			//!< Speed bump. Ground is raised in this location
	speedLimit =		0x0400,			//!< Slow down to requested speed at this location  
	reducedObstacleMargins = 0x0800,	//!< reduced safety margins for obstacle. Event data sets the details
	minSpeed =			0x1000,			//!< minimum speed required for this location. For speed calculation algorithm 
	noStep =			0x2000,			//!< Disable external devices (foot step, etc) in this part of the track
	ignoreObstacleMarginA =	0x4000,		//!< Ignore obstacle detected on near margins in this WP
	ignoreObstacleMarginB =	0x8000,		//!< Ignore obstacle detected on wide margins in this WP
};

//! Values of way point eventFlag2
enum wayPointeventFlag2
{
	dualSteering = 0x0001,		//!< Use symmetric dual steering in this part of the track
	overtakeAllowed = 0x0002,	//!< overtake is allowed here
	drivingDisallowed = 0x0004,	//!< driving disallowed in this section (needed for Korea school zone)
	badGPS = 0x0008,			//!<this section has bad GPS quality ignore GPS
	knownObstacle = 0x0010,		//!< This location has a known false positive of the obstacle system. Only trust obstacles with high confidence   
	teleport = 0x0020,			//!< This flag indicates an GPS off area with teleporting at the end of it
	icpHeightLimit = 0x0040,    //!< Indicates obstacles affecting ICP localisation at known heights
	reserved8 = 0x0080,			//!< reserved
	reserved9 = 0x0100,			//!< reserved
	reserved10 = 0x0200,		//!< reserved
	reserved11 = 0x0400,		//!< reserved
	reserved12 = 0x0800,		//!< reserved
	reserved13 = 0x1000,		//!< reserved
	reserved14 = 0x2000,		//!< reserved
	reserved15 = 0x4000,		//!< reserved
	reserved16 = 0x8000,		//!< reserved
};

//! event file header
typedef struct
{
	uint64_t trackId;
	uint32_t noOfEvents;
	uint64_t MD5Track;
	uint64_t MD5Full;

}OHMIO_EVENT_HEADER_INFO_t;

//! event information
typedef struct 
{
	uint32_t startPoint;			//!< way point number where the event becomes active
	uint32_t endPoint;				//!< way point number where the event is deactivated
	uint32_t actionPoint;			//!< way point number where the event action is happening (e.g. stop line).
	uint32_t data1;					//!< general data part 1
	uint32_t data2;					//!< general data part 2
	uint32_t data3;					//!< general data part 3
	uint32_t data4;					//!< general data part 4
	uint32_t eventIndex;            //!< event number (1 based)
	uint32_t eventBit;				//!< which of the 32 flags is on
}OHMIO_EVENT_INFO_t;


//! danger file header
typedef struct
{
	uint64_t trackId;
	uint32_t noOfPoints;
	uint32_t noOfZones;
	uint64_t MD5Track;
	uint64_t MD5Full;
}OHMIO_DANGER_HEADER_INFO_t;

//! danger point information
typedef struct
{
	double latitide;				//!< latitude of the point
	double logitude;				//!< logitude of the point
	uint32_t zoneId;				//!< zone index (1 based)
	uint32_t pointNumber;			//!< point index (1 based) 
}OHMIO_DANGER_POINT_INFO_t;

//! lane location file header
typedef struct
{
	uint64_t trackId;
	uint32_t noOfPoints;
	uint64_t vehicleId;		//!< the vehicle this file is valid for (in case we need to match to specific configuration)
	uint64_t MD5Track;
	uint64_t MD5Full;
}OHMIO_LANE_INFO_HEADER_INFO_t;

//! lane location information
typedef struct
{
	uint32_t wpNo;              //!< way point number
	uint32_t valid;				//!< Is this location good for detection?
	int32_t offset;			//!< expected offset from centre %
	int32_t heading;			//!< expected angle to the lane line
	uint32_t laneWidth;			//!< milli meters. to convert % to meters 
}OHMIO_LANE_INFO_POINT_INFO_t;


//!Error codes for file loading
enum FileLoadErrorCodes
{
	Success = 0,		//!< OK
	FileNotFound,		//!< Failed file open 
	FileHeaderError,	//!< couldn't read header
	PointReadError,		//!< couldn't read a way point
	PointNumberError,	//!< number of points didn't match header
	MD5Error,			//!< MD5 (full or location) didn't match header

	// always add before
	lastError
};
