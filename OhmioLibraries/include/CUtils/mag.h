#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "GeomagnetismHeader.h"

/**
 *  @brief      Calculates the world magnetic vector
 *  \image html vector.png
 *  @returns    0 - Ok
 *              1 - Magnetic horizontal component weak, compass readings have large errors
 *              2 - Magnetic horizontal component very weak, compass readings have VERY LARGE errors
 *              3 - Memory allocation error
 *  @author   Carlos Aydos
 *  @date     27 Jun 2018
 **/
int world_magnetic_model(
   double latitude,                                //!< INPUT - Latitude in decimal degrees.
   double longitude,                               //!< INPUT - Longitude in decimal degrees.
   double height,                                  //!< INPUT - Height above ellipsoid
   double decimal_year,                            //!< INPUT - Decimal year. For example, 27 Jun 2018 is 2018.4849315068493
   MAGtype_GeoMagneticElements * magnetic_vector,  //!< OUTPUT - Magnetic vector [nanoteslas] and its variation [nanoteslas/year]. Client allocated.
   void (*mag_error)(int control)
);

