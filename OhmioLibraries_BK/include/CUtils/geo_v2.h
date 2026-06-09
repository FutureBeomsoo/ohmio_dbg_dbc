/**
 * @file geo_v2.h
 * @brief Useful conversions for WGS84. Unless stated otherwise, all units are SI units
 * @author Carlos Aydos
 * @date 11 Jun 2020
 */

#pragma once

/**
 * Curvilinear coordinates with respect to the WGS84 ellipsoid used by GNSS systems
 */
typedef union
{
   struct {
      double latitude;
      double longitude;
      double height;    //!< w.r.t the WGS84 ellipsoid
   };
   double raw[3];
} pos_geodetic_t;

/**
 * 3D Cartesian coordinates, represented in metres
 */
typedef union
{
   struct {
      double x;
      double y;
      double z;
   };
   double raw[3];
} pos_cartesian_t;

/**
 *  @brief    Finds UTM zone and latitude band. geo2utm and utm2geo provide the forward and inverse transforms. UTM northing and easting coordinates are local to the given zone and hemisphere. The hemisphere boundary is indicated between the boundaries of band M and N. Boundaries of all other bands are for information only. Applications close to a zone or hemisphere boundary that need to measure a UTM distance across the boundary, must elect to use the same zone to convert the two points. For that reason, utm_zone has a separate call from geo2utm to allow the client to force the use of a single zone and band. UTM projections are generally not suitable for measuring longitudinal distances greater than 9 degrees.
 *  @author   Carlos Aydos
 *  @date     19 Jul 2018
 **/
void utm_zone(
      double latitude,  //!< INPUT - Latitude
      double longitude, //!< INPUT - Longitude
      int * const zone,  //!< OUTPUT - UTM zone
      char * const band  //!< OUTPUT - UTM latitude band
      );

/**
 *  @brief    Converts latitude and longitude into UTM easting and northing
 *  @author   Carlos Aydos
 *  @date     19 Jul 2018
 **/
void geo2utm(
      double latitude,       //!< INPUT - Latitude
      double longitude,      //!< INPUT - Longitude
      int const zone,        //!< INPUT - The UTM zone to use in the conversion
      char const band,       //!< INPUT - The UTM latitude band to use in the conversion
      double * const easting, //!< OUTPUT - UTM easting
      double * const northing //!< OUTPUT - UTM northing
      );

/**
 *  @brief    Converts UTM easting and northing into latitude and longitude
 *  @author   Carlos Aydos
 *  @date     19 Jul 2018
 **/
void utm2geo(
      double easting,         //!< INPUT - UTM easting
      double northing,        //!< INPUT - UTM northing
      int zone,               //!< INPUT - The UTM zone to use in the conversion
      char band,              //!< INPUT - The UTM latitude band to use in the conversion
      double * const latitude, //!< OUTPUT - Latitude
      double * const longitude //!< OUTPUT - Longitude
      );

/**
 *  @brief     Exact convertion geodetic position to ECEF (Earth-centered, earth-fixed) position. Extracted from "Principles of GNSS, Inertial and Multisensor Integrated Navigation Systems", Second Edition, page 61.
 *  @author    Carlos Aydos
 *  @date      18 Feb 2020
 */
void geo2ecef(
      const pos_geodetic_t * const geo_pos,  //!< INPUT
      pos_cartesian_t * const ecef_pos       //!< OUTPUT - caller allocated
      );

/**
 *  @brief     Converts ECEF (Earth-centered, earth-fixed) to geodetic position. Extracted from "Principles of GNSS, Inertial and Multisensor Integrated Navigation Systems", Second Edition, page 62.
 *  This is an approximated method with precision higher than 1mm for altitudes between -100000 and 100000 meters
 *  @author    Carlos Aydos
 *  @date      18 Feb 2020
 */
void ecef2geo(
      const pos_cartesian_t * const ecef_pos, //!< INPUT
      pos_geodetic_t * const geo_pos       //!< OUTPUT - caller allocated
      );

/**
 * @brief Converts geodetic coordinates into ENU (East, North, Up) coordinates. Accurate to 10mm for distances up to 200m. Extracted from "Principles of GNSS, Inertial and Multisensor Integrated Navigation Systems", Second Edition, page 77.
 *  @author    Carlos Aydos
 *  @date      11 Jun 2020
 */
void geo2enu(
      const pos_geodetic_t * const geo_pos, //!< INPUT - Geodetic position
      const pos_geodetic_t * const geo0,    //!< INPUT - The reference for the ENU frame
      double rotation,                      //!< INPUT - The rotation of the ENU frame around the Height axis (anti-clockwise from east)
      pos_cartesian_t * const enu           //!< OUTPUT - East, North, Up coordinates
      );

/**
 * @brief As geo2enu, but latitude, longitude and rotation expressed in degrees
 */
void geo2enu_degrees(
      const pos_geodetic_t * const geo_pos,
      const pos_geodetic_t * const geo0,
      double rotation,
      pos_cartesian_t * const enu
      );

/**
 * @brief As geo2enu, but latitude and longitude expressed in micro-radians
 *  @author    Carlos Aydos
 *  @date      7 Jul 2020
 */
void geo2enu_micro(
      const pos_geodetic_t * const geo_pos, //!< INPUT - Geodetic position
      const pos_geodetic_t * const geo0,    //!< INPUT - The reference for the ENU frame
      double rotation,                      //!< INPUT - The rotation of the ENU frame around the Height axis (anti-clockwise from east)
      pos_cartesian_t * const enu           //!< OUTPUT - East, North, Up coordinates
      );

/**
 * @brief   Converts ENU (East, Nort, Up) coordinates into geodetic coordinates. Accurate to 10mm for distances up to 200m. Extracted from "Principles of GNSS, Inertial and Multisensor Integrated Navigation Systems", Second Edition, page 77. It has a singularity at latitudes of PI and -PI
 *  @author    Carlos Aydos
 *  @date      11 Jun 2020
 */
void enu2geo(
      const pos_cartesian_t * const enu,    //!< INPUT - East, North, Up coordinates
      const pos_geodetic_t * const geo0,    //!< INPUT - The reference geodetic location for the conversion
      double rotation,                      //!< INPUT - The rotation of the local frame around the Height axis (anti-clockwise from east)
      pos_geodetic_t * const geo_pos        //!< OUTPUT - Geodetic position
      );

/**
 * @brief As enu2geo, but latitude and longitude expressed in micro-radians
 *  @author    Carlos Aydos
 *  @date      7 Jul 2020
 */
void enu2geo_micro(
      const pos_cartesian_t * const enu,    //!< INPUT - East, North, Up coordinates
      const pos_geodetic_t * const geo0,    //!< INPUT - The reference geodetic location for the conversion
      double rotation,                      //!< INPUT - The rotation of the local frame around the Height axis (anti-clockwise from east)
      pos_geodetic_t * const geo_pos        //!< OUTPUT - Geodetic position
      );

/**
 *  @brief    Provides the geodetic azimuth given two points. Extraced from https://en.wikipedia.org/wiki/Azimuth
 *  @return   Azimuth between 0 and 2*PI clockwise from the north.
 *  @author   Carlos Aydos
 *  @date     4 Jun 2020
 */
double azimuth(
      double lat0,   //!< INPUT - Latitude of the origin point
      double lon0,   //!< INPUT - Longitude of the origin point
      double lat1,   //!< INPUT - Latitude of the destination point
      double lon1    //!< INPUT - Longitude of the destination point
      );

