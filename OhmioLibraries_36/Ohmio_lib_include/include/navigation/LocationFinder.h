#pragma once

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES // needed for the definition of M_PI
#endif
#include <math.h>
#include <vector>

//! Parameters for finding the current way point
//
//! All units are meters and radians.
class LocationFinderParams
{
public:
	LocationFinderParams(double outOfTrackTolerance = 0.8,
		double maxRollBack = 3.0,
		double maxHeadingError = M_PI / 4,
		double maxAltitudeDiff = 1.0)
		: m_outOfTrackTolerance(outOfTrackTolerance)
		, m_maxRollBack(maxRollBack)
		, m_maxHeadingError(maxHeadingError)
		, m_maxAltitudeDiff(maxAltitudeDiff)
	{}
	~LocationFinderParams() {}
	double m_outOfTrackTolerance;		//!< vehicle is out of track if distance to nearest way point larger then this (m)
	double m_maxRollBack;				//!< when searching from known location the vehicle may move back but this amount (m)
	double m_maxHeadingError;			//!< when comparing heading this is the max difference (radians)
	double m_maxAltitudeDiff;			//!< when comparing altitudes this is the max difference (m)
};

//! A way point in the track
class WayPoint
{
public:
	double x;				//!< in X coordinates, meters. Can be local or global coordinates.
	double y;				//!< in Y coordinates, meters. Can be local or global coordinates.
	double heading;			//!< direction of travel. In radians 0 is north, pi/2 east, in [0, 2pi) range
	double altitude;		//!< in meters above whatever reference height is used. 
};


//! Find the current way point from the vehicle location
//
//! see https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/938672138/Locating+the+vehicle+on+the+track
//! Search is always done internally in XY coordinates.
class LocationFinder
{
public:
	//! contractor
	//
	//!@param[in] m_params - the parameters to use (how far off track we can be etc)
	LocationFinder(LocationFinderParams m_params);
	~LocationFinder();

	///@{ 
	//! Set the track we are driving on from way points in lat long coordinates
	//
	//! @param[in] trackXY - the track in x,y coordinates 
	void SetTrackXY(const std::vector<WayPoint>& trackXY);
	///@}		


	///@{ 
	//! Find the current way point index
	//
	//! @param[in] locationXY - current location (lat, long, altitude, heading)
	//! @param[in] searchFrom - last point index. 
	//! If searchFrom >= 0 we are driving on a track and this is the last known point index. 
	//! If searchFrom < 0 we are starting on a new track and do not know where we are
	//! @return the index of the nearest point to our location. Will be -1 if not on track
	int FindWayPointIndexXY(const WayPoint& locationXY, int searchFrom);
	///@}		


	//! Calculate heading to get from 'from' to 'to'. Public to help with testing
	double CalculateHeading(const WayPoint& from, const WayPoint& to);

private:
	//! Go backward along the track so that we can start the search in case we rolled backward
	int RollBack(int searchFrom);

	//! Helper function calculating distance between points. For speed with use distance squared (avoiding sqrt)
	double DistanceSqr(const WayPoint& from, const WayPoint& to);
		

	//! Are 2 points in similar altitude and heading. To prevent matching the vehicle to wrong
	//! arm of the track when the track crosses itself
	bool IsMatchingHeadingAndAltitude(const WayPoint& from, const WayPoint& to);


	//! This is the heavy search. We don't know where we are and we search
	//! the entire track to find what region of the track is closest to us
	int FindStartLocation(const WayPoint& location);

	//! This is the fast search. We already know where on the track we are we just
	//! refine to nearest point
	int FindNearest(int searchFrom, const WayPoint& location);

	//! Set the heading for each point on the track
	void CalculateHeadings();


private:
	std::vector<WayPoint> m_track;		//!< the track we are on. Way points are in XY (not lat long)
	LocationFinderParams m_params;			//!< parameters for searching
};

