#pragma once
#include <stdbool.h>

#include "PointDefinitions.h"
// Create a track section on the fly. Can be used for skipping a bus stop bay 
// or for generating a connector section between 2 tracks.
// caller needs to create the track (call CreateStraightTrack() or CreateCurvedTrack()) first
// after this they can call GetWP() to get the way points in the new track one at a time.
// the create functions have 2 versions 1 for a fixed number of way points 
// and one for a fixed distance between adjacent way points.
// use thenumber of points for replacing short sections (bus stop bays)
// use the distance for connecting two tracks.

// ############## limitation #########################
// the track information is stored in a static variables.
// you can only have one track at a time.
 
//! Calculate a straight track between two points
//
//! Call this function once to set up the track. Then call GetWP() repeatedly to get the WP.
//! Create a track with the required number of way points between start and end.
//! @param[in] fromPoint - starting point of the track
//! @param[in] toPoint - end point of the track
//! @param[in] numPoint - How many WP to use between the start and end.
//! @return true if the track can be created 
bool CreateStraightTrack(const location_2D* fromPoint, const location_2D* toPoint, int numPoint);


//! Calculate a straight track between two points
//
//! Call this function once to set up the track. Then call GetWP() repeatedly to get the WP.
//! Create a track with the required distance between adjacent way points and calculates the number of WP.
//! @param[in] fromPoint - starting point of the track
//! @param[in] toPoint - end point of the track
//! @param[in] wpDistance - distance between adjacent way points
//! @return number of way points created. Returnes 0 if invalid
int CreateStraightTrackAtWpDistance(const location_2D* fromPoint, const location_2D* toPoint, double wpDistance);


//! Calculate a curved track between two points
//
//! Call this function once to set up the track. Then call GetWP() repeatedly to get the WP.
//! Create a track with the required number of way points between start and end.
//! @param[in] fromPoint - starting point of the track
//! @param[in] toPoint - end point of the track
//! @param[in] beforeFrom - a point a few WP before the start (about 1m) to define the direction at the start
//! @param[in] afterTo - a point a few WP after the start (about 1m) to define the direction at the end
//! @param[in] numPoint - How many WP to use between the start and end.
//! @return true if the track can be created 
bool CreateCurvedTrack(const location_2D* fromPoint, const location_2D* toPoint,
    const location_2D* beforeFrom, const location_2D* afterTo, int numPoint);

//! Calculate a curved track between two points
//
//! Create a track with the required distance between adjacent way points and calculates the number of WP.
//! @param[in] fromPoint - starting point of the track
//! @param[in] toPoint - end point of the track
//! @param[in] beforeFrom - a point a few WP before the start (about 1m) to define the direction at the start
//! @param[in] afterTo - a point a few WP after the start (about 1m) to define the direction at the end
//! @param[in] wpDistance - distance between adjacent way points
//! @return number of way points created. Returnes 0 if invalid
int CreateCurvedTrackAtWpDistance(const location_2D* fromPoint, const location_2D* toPoint,
    const location_2D* beforeFrom, const location_2D* afterTo, double wpDistance);

//! Do we have a valid track?
bool IsWpConnectorValid();

//! Get a WP on the new track
//
//! Call CreateStraightTrack() or CreateCurvedTrack first to set up the new track
//! Call this function repeatedly to get the WP.
//! @param[in] wpIndex - how many way points from the start of the track.
//! @param[out] wp - the WP in the new track.   
void GetWP(int wpIndex, location_2D* wp);
