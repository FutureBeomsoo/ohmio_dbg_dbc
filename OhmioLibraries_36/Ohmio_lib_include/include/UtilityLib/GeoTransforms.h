#pragma once
#include "version.h"

extern "C"
{
	#include "CUtils/geo_v2.h"
}


//! Geo - lat long to XY transformation
namespace geo 
{
	//! Convert between latitude longitude (and altitude) and XY coordinates
	//
	//! The XY representation used is ENU https://en.wikipedia.org/wiki/Local_tangent_plane_coordinates
	//! Users of this class should not care which representation is used, any other 
	//! artesian representation (for example UTM) may be used instead.
	//! This is a C++ wrapper of the C library (geo.c).
	//! All latitude and longitude values are in degrees, all distances (XY and altitude) are in meters
	class GeoTransforms
	{
	public:
		//! constructor
		//
		//! Construct from an origin (in lat long coordinates).
		//! This will set the origin of the coordinate system.
		//! All subsequent calls will use the same origin. 
		//! @param[in] lat - latitude of the origin
		//! @param[in] lon - longitude of the origin
		//! @param[in] altitude - altitude of the origin
		GeoTransforms(double lat, double lon, double altitude);
		~GeoTransforms();

		//! convert lat long to XY Cartesian coordinates
		//
		//! Assumes the altitude is the same as in origin
		//! @param[in] lat - latitude 
		//! @param[in] lon - longitude
		//! @param[out] x - X coordinate (east) 
		//! @param[out] y - Y coordinate (north)
		void toXy(double lat, double lon, double& x, double& y);
		
		//! convert east north to lat long
		//
		//! Assumes the altitude is the same as in origin
		//! @param[in] x - X coordinate (east) 
		//! @param[in] y - Y coordinate (north)
		//! @param[out] lat - latitude 
		//! @param[out] lon - longitude
		void toGeo(double x, double y, double& latOut, double& lonOut);



		//! Calculate the heading to go from 'from' to 'to' in XY coordinates
		//
		//! @param[in] fromX - X coordinate of start point (east west) relative to origin
		//! @param[in] fromY - Y coordinate of start point (north south) relative to origin
		//! @param[in] toX - X coordinate of end point (east west) relative to origin
		//! @param[in] toY - Y coordinate of end point (north south) relative to origin
		//! @return compass angle in radians in [0, 2pi) range. North is 0, east is pi/2 ..
		double CalculateHeadingXY(double fromX, double fromY, double toX, double toY);

		//! Calculate the heading to go from 'from' to 'to' in lat long  coordinates
		//
		//! @param[in] fromLat - latitude of start point (east west) relative to origin
		//! @param[in] fromLong - longitude of start point (north south) relative to origin
		//! @param[in] toLat - latitude of end point (east west) relative to origin
		//! @param[in] toLong - longitude of end point (north south) relative to origin
		//! @return compass angle in radians in [0, 2pi) range. North is 0, east is pi/2 ..
		double CalculateHeadingLatLong(double fromLat, double fromLong, double toLat, double toLong);


	private:
		//! the coordinates of the origin as needed for geo.c Note that lat and long are in radians internally
		pos_geodetic_t m_origin;
	};

}

