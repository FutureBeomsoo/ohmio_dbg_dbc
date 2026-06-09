#pragma once

#include <stdbool.h>

typedef enum
{
   FRONT = 0,
   REFERENCE = 1,
   REAR = 2
} speed_souce_n;

typedef struct
{
   double speed;
   double gamma;
   double rho;
   speed_souce_n type;
} odometry_nav_t;

/**
 *  @brief    Calculates the movement of a all steering vehicle model as per https://hmitechnologies.atlassian.net/wiki/spaces/AI/pages/505315695/All+wheel+steering+model
 *  The outputs are the incremental change of a specified vehicle reference (x,y) point and the vehicle heading change.
 *  @author   Carlos Aydos
 *  @date     17 April 2020
 **/
void all_wheel_steering_model(
      double L,                //!< INPUT - wheel base
      double l,                //!< INPUT - reference
      double dt,               //!< INPUT - time step size
      const odometry_nav_t * const inputs,                //!< INPUT - Input parameters
      double * const x_incr,                          //!< OUTPUT - x direction increment
      double * const y_incr,                          //!< OUTPUT - y direction increment
      double * const theta_incr                       //!< OUTPUT - heading increment (right-hand rule)
      );

/**
 * Same as all_wheel_steering_model_centre(), but splits calculations in 10 subdivisions resulting in more accurate output
 */
void all_wheel_steering_model_split10(
      double L,                //!< INPUT - wheel base
      double l,                //!< INPUT - reference
      double dt,               //!< INPUT - time step size
      const odometry_nav_t * const inputs,                //!< INPUT - Input parameters
      double * const x_incr,                          //!< OUTPUT - x direction increment
      double * const y_incr,                          //!< OUTPUT - y direction increment
      double * const theta_incr                       //!< OUTPUT - heading increment (right-hand rule)
      );

/**
 * Same as all_wheel_steering_model_split10(), but splits calculations in 2 subdivisions
 */
void all_wheel_steering_model_split2(
      double L,
      double l,
      double dt,
      const odometry_nav_t * const i,
      double * const x_incr,
      double * const y_incr,
      double * const heading_incr);

/**
 * Same as all_wheel_steering_model(), but assumes l  = L/2;
 */
void all_wheel_steering_model_centre (
      double L,
      double dt,
      const odometry_nav_t * const i,
      double * const x_incr,
      double * const y_incr,
      double * const heading_incr
);


/**
 * Same as all_wheel_steering_model_centre(), but splits calculations in 10 subdivisions resulting in more accurate output
 */
void all_wheel_steering_model_centre_split10 (
      double L,
      double dt,
      const odometry_nav_t * const i,
      double * const x_incr,
      double * const y_incr,
      double * const heading_incr
);

/**
 * Same as all_wheel_steering_model_centre_split10(), but splits calculations in 2 subdivisions
 */
void all_wheel_steering_model_centre_split2(
      double L,
      double dt,
      const odometry_nav_t * const i,
      double * const x_incr,
      double * const y_incr,
      double * const heading_incr
);


/**
 *  @brief     Calculates the longitudianl acceleration of a point over time
 *  @return    The acceleration, units will be a result of the input units
 *  @author    Carlos Aydos
 *  @date      19 April 2021
 **/
double longitudinal_acceleration(
      double x,                     //!< INPUT - x position
      double y,                     //!< INPUT - y position
      double z,                     //!< INPUT - z position
      double dt,                     //!< INPUT - time since last position
      double filter,                 //!< INPUT - filtering factor. 0 never changes the signal, 1 is the raw acceleration
      bool init                     //!< INPUT - true for the first call, false for subsequent calls
);

/**
 *  @brief     Calculates the lateral acceleration of a vehicle
 *  @return    The acceleration, units will be a result of the input units
 *  @author    Carlos Aydos
 *  @date      19 April 2021
 **/
double lateral_acceleration_from_steering(
      double speed,                 //!< INPUT - vehicle speed
      double steer_angle_front,     //!< INPUT - front steering angle (radians)
      double steer_angle_rear,      //!< INPUT - rear steering angle (radians)
      double L                       //!< INPUT - wheel base (same distance units used in vehicle speed)
);

/**
 *  @brief     Calculates the lateral acceleration of a vehicle
 *  @return    The acceleration, units will be a result of the input units
 *  @author    Carlos Aydos
 *  @date      19 April 2021
 **/
double lateral_acceleration_from_heading(
      double speed,                         //!< INPUT - vehicle speed
      double heading_change,                //!< INPUT - heading change (radians)
      double dt                             //!< INPUT - time step size (same distance units used in vehicle speed)
);

