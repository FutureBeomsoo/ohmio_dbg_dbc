/**
 * @file geo.h
 * @brief Useful conversions for WGS84. geo2utm and utm2geo provide the forward and inverse transforms. UTM northing and easting coordinates are local to the given zone and hemisphere. The hemisphere boundary is indicated between the boundaries of band M and N. Boundaries of all other bands are for information only. Applications close to a zone or hemisphere boundary that need to measure a UTM distance across the boundary, must elect to use the same zone to convert the two points. For that reason, utm_zone has a separate call from geo2utm to allow the client to force the use of a single zone and band. UTM projections are generally not suitable for measuring longitudinal distances greater than 9 degrees.
 * @author Carlos Aydos
 * @date 20 Jul 2018
 */

#pragma once
#include <stdbool.h>
#ifdef __GNUC__
#define DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED(func) __declspec(deprecated) func
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED(func) func
#endif

/**
 *  @brief    Finds UTM zone and latitude band.
 *  @author   Carlos Aydos
 *  @date     19 Jul 2018
 **/
DEPRECATED(
void utm_zone(
    double latitude,  //!< INPUT - Latitude in decimal degrees
    double longitude, //!< INPUT - Longitude in decimal degrees
    int *const zone,  //!< OUTPUT - UTM zone
    char *const band  //!< OUTPUT - UTM latitude band
));

/**
 *  @brief    Converts latitude and longitude into UTM easting and northing
 *  @author   Carlos Aydos
 *  @date     19 Jul 2018
 **/
DEPRECATED(void geo2utm(
    double latitude,       //!< INPUT - Latitude in decimal degrees
    double longitude,      //!< INPUT - Longitude in decimal degrees
    int const zone,        //!< INPUT - The UTM zone to use in the conversion
    char const band,       //!< INPUT - The UTM latitude band to use in the conversion
    double *const easting, //!< OUTPUT - UTM easting in metres
    double *const northing //!< OUTPUT - UTM northing in metres
));

/**
 *  @brief    Converts UTM easting and northing into latitude and longitude
 *  @author   Carlos Aydos
 *  @date     19 Jul 2018
 **/
DEPRECATED(void utm2geo(
    double easting,         //!< INPUT - UTM easting in metres
    double northing,        //!< INPUT - UTM northing in metres
    int zone,               //!< INPUT - The UTM zone to use in the conversion
    char band,              //!< INPUT - The UTM latitude band to use in the conversion
    double *const latitude, //!< OUTPUT - Latitude in decimal degrees
    double *const longitude //!< OUTPUT - Longitude in decimal degrees
));


/**
 *  @brief    Converts latitude and longitude into UTM coordinates relative to a given origin
 *  @author   Xianghui Luo
 *  @date     2 Sept 2019
 **/
bool LatLongToXYwithOrigin(
    double latitude,  //!< INPUT - UTM easting in metres
    double longitude, //!< INPUT - UTM northing in metres
    double *const X,  //!< OUTPUT - Latitude in decimal degrees
    double *const Y   //!< OUTPUT - Longitude in decimal degrees
);


/**
 *  @brief    Converts UTM coordinates relative to a given origin into latitude and longitude
 *  @author   Xianghui Luo
 *  @date     2 Sept 2019
 **/
bool XYwithOriginToLatLong(
    double X,  //!< OUTPUT - Latitude in decimal degrees
    double Y,   //!< OUTPUT - Longitude in decimal degrees
    double * const latitude,  //!< INPUT - UTM easting in metres
    double * const longitude //!< INPUT - UTM northing in metres
);

/**
 *  @brief    Check if  in the zone or neighboring zones
 *  @author   Xianghui Luo
 *  @date     2 Sept 2019
 **/
bool isNearZone(
   int zone,  //!< INPUT - zone
   char band,  //!< INPUT - band
   int origin_zone,  //!< INPUT - zone
   char origin_band //!< INPUT - band
);


/**
 *  @brief    Set origin latitude, longitude
 *  @author   Xianghui Luo
 *  @date     2 Sept 2019
 **/
void setLatLongToXYOrigin(
  double lat,  //!< INPUT - Latitude in decimal degrees
  double lon  //!< INPUT - Latitude in decimal degrees
);

/**
 *  @brief     Converts GPS position (a.k.a. curvilinear position) to ECEF (Earth-centered, earth-fixed) position. Extracted from "Principles of GNSS, Inertial and Multisensor Integrated Navigation Systems", Second Edition, page 61.
 *  @author    Carlos Aydos
 *  @date      18 Feb 2020
 */
DEPRECATED(void gps2ecef(
      double latitude,  //!< INPUT - Latitude in decimal degrees
      double longitude, //!< INPUT - Longitude in decimal degrees
      double altitude,  //!< INPUT - Altitude
      double * const x, //!< OUTPUT - x ECEF
      double * const y, //!< OUTPUT - y ECEF
      double * const z  //!< OUTPUT - z ECEF
));

/**
 *  @brief     Converts GPS position (a.k.a. curvilinear position) to ECEF (Earth-centered, earth-fixed) position. Extracted from "Principles of GNSS, Inertial and Multisensor Integrated Navigation Systems", Second Edition, page 62.
 *  This is an approximated method with precision higher than 1mm for altitudes between -100000 and 100000 meters
 *  @author    Carlos Aydos
 *  @date      18 Feb 2020
 */
DEPRECATED(void ecef2gps(
      double x,                 //!< INPUT - x ECEF
      double y,                 //!< INPUT - y ECEF
      double z,                 //!< INPUT - z ECEF
      double * const latitude,  //!< OUTPUT - Latitude in decimal degrees
      double * const longitude, //!< OUTPUT - Longitude in decimal degrees
      double * const altitude   //!< OUTPUT - Altitude
));
