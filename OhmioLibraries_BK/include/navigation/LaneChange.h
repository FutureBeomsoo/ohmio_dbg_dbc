#pragma once



//! Location in 2D (in m units)
typedef struct
{
	double x;			//!< X component of location (eastward) 
	double y;			//!< Y component of location (northward)
} location_2D;

#define LaneChangeOffsetForHeading 5	//!< calculate heading by using this muck look ahead 
#define DefaultWpDistance 0.2128		//!< distance between adjacent way point


//! Calculate the requirements for lane change
//
//! Call this function once, then call MoveWayPoint() or ReturnWayPoint() repeatedly
//! to get the modified track.
//! All parameters are in m and sec.
//! @param[in] offset - How much to move the vehicle sideways to the new lane. Left 
//! is negative. 
//! @param[in] velocity - the speed of the vehicle when we start the transition maneuver. 
//! @param[in] maxAcceleration - maximum acceleration for comfortable driving. 
//! use LaneChangeMaxAcceleration
//! @param[in] distBetweenWP - the distance between 2 adjacent way point (use DefaultWpDistance). 
//! Used for converting between WP index and distance
//! @return number of way points needed for the transition to the new lane
int OffsetTrack(double offset, double velocity, double maxAcceleration, double distBetweenWP);

//! Get the new location for a way point
//
//! Call OffsetTrack() first to set up the parameters of the transition
//! @param[in] wpIndex - how many way points from the start of the transition are we.
//! This tells us how much to move the point by
//! @param[in] pointToMove - calculate the new location of this point (point 
//! is on the original track)  
//! @param[in] nextPoint - a point that is a few WP ahead of pointToMove on the 
//! original track. Used to calculate the heading so that we can offset in the 
//! correct direction. Use LaneChangeOffsetForHeading
//! @param[out] movedPoint - pointToMove after moving to the new track.   
void MoveWayPoint(int wpIndex, const location_2D* pointToMove, 
	const location_2D* nextPoint, location_2D* movedPoint);

//! Get the new location for a way point in returning to the original track
//
//! Call OffsetTrack() first to set up the parameters of the transition.
//! @param[in] wpIndex - how many way points from the start of the transition are we.
//! This tells us how much to move the point by
//! @param[in] pointToMove - calculate the new location of this point (point 
//! is on the original track)  
//! @param[in] nextPoint - a point that is a few WP ahead of pointToMove on the 
//! original track. Used to calculate the heading so that we can offset in the 
//! correct direction. Use LaneChangeOffsetForHeading
//! @param[out] movedPoint - pointToMove after moving to the new track.   
void ReturnWayPoint(int wpIndex, const location_2D* pointToMove, 
	const location_2D* nextPoint, location_2D* movedPoint);

//! Get the new location for a way point close to track end
//
//! Call OffsetTrack() first to set up the parameters of the transition
//! @param[in] wpIndex - how many way points from the start of the transition are we.
//! This tells us how much to move the point by
//! @param[in] pointToMove - calcualte the new location of this point (point 
//! is on the original track)  
//! @param[in] prevPoint - a point that is a few WP BEFORE pointToMove on the 
//! original track. Used to calculate the heading so that we can offset in the 
//! correct direction. Use LaneChangeOffsetForHeading
//! @param[out] movedPoint - pointToMove after moving to the new track.   
void MoveWayPointNearEnd(int wpIndex, const location_2D* pointToMove,
	const location_2D* prevPoint, location_2D* movedPoint);

//! Get the new location for a way point in returning to the original track close to track end
//
//! Call OffsetTrack() first to set up the parameters of the transition.
//! @param[in] wpIndex - how many way points from the start of the transition are we.
//! This tells us how much to move the point by
//! @param[in] pointToMove - calcualte the new location of this point (point 
//! is on the original track)  
//! @param[in] prevPoint - a point that is a few WP BEFORE pointToMove on the 
//! original track. Used to calculate the heading so that we can offset in the 
//! correct direction. Use LaneChangeOffsetForHeading
//! @param[out] movedPoint - pointToMove after moving to the new track.   
void ReturnWayPointNearEnd(int wpIndex, const location_2D* pointToMove,
	const location_2D* prevPoint, location_2D* movedPoint);