/**
 * @file rotations.h
 * @brief  Implementation of a series of 3D rotation functions. Several conventions exist and we adopted the one on section 8.11 of this <a href="https://www.astro.rug.nl/software/kapteyn-beta/_downloads/attitude.pdf">reference</a>.
 *  @author    Carlos Aydos
 *  @date      21 Feb 2019
 **/

#pragma once

#include <stdbool.h>

typedef enum
{
   I2B = 2, //!< inertial to body frame
   B2I = 8, //!< body to inertial frame
} RotationType;

/**
 *  @brief  Rotates a 2D convariance matrix angle psi anticlockwise
 *  @author Carlos Aydos
 *  @date   28 Feb 2024
 **/
void rotate_cov2d(
      const double cov[4],
      const double psi,
      double r[4]);

/**
 *  @brief  Performs a passive 2D rotation transformation of a point (x,y) of a right-handed Cartesian coordinate system given the angle psi (z-axis).
 *  @author Carlos Aydos
 *  @date   8 April 2019
 **/
void rotate_2d(
      const double p[2],
      const double psi,
      const RotationType type,
      double r[2]);

/**
 *  @brief  Performs a passive 3D intrinsic rotation transformation of a point (x,y,z) of a right-handed Cartesian coordinate system given the Euler angles phi (x-axis), theta (y-axis) and psi (z-axis). The rotation sequence adopted is psi-theta-phi. For example, the code below perform a passive rotation from the inertial frame to the body frame (I2B). The point at (1,1,1) rotates by 45 degrees around the z-axis, than rotates 20 degrees around the previous y-axis and finally rotates 10 degrees around the previous x-axis. The resulting point coordinates are stored in r.
 \code
 double point[3] = { 1, 1, 1 };
 double attitude[3] = { 10 * D2R, 20 * D2R, 45 * D2R };
 double result[3];
 intrinsic_rotate(point, attitude, I2B, result);
 \endcode
 *  @author    Carlos Aydos
 *  @date      19 Feb 2019
 **/
void intrinsic_rotate(
      const double p[3],            //!< INPUT - an (x,y,z) point with respect to the origin frame
      const double attitute[3],     //!< INPUT - Intrinsic angles (phi, theta, psi).
      const RotationType type,      //!< INPUT - the rotation type
      double r[3]                   //!< OUTPUT - an (x,y,z) point with respect to the destination frame
      );

/**
 *  @brief  Performs a passive 3D extrinsic rotation transformation of a point at (x,y,z) of a right-handed Cartesian coordinate system given the Euler angles phi (x-axis), theta (y-axis) and psi (z-axis). The rotation sequence adopted is phi-theta-psi. For example, the code below perform a passive rotation from the body frame to the inertial frame (I2B). The point at (1,1,1) rotates by 45 degrees around the x-axis, than rotates 20 degrees around the original y-axis and finally rotates 10 degrees around the original z-axis. The resulting point coordinates are stored in r.
 \code
 double point[3] = { 1, 1, 1 };
 double attitude[3] = { 10 * D2R, 20 * D2R, 45 * D2R };
 double result[3];
 extrinsic_rotate(point, attitude, I2B, result);
 \endcode
 *  @author   Carlos Aydos
 *  @date     19 Feb 2019
 **/
void extrinsic_rotate(
      const double * const p,          //!< INPUT - an (x,y,z) point with respect to the origin frame
      const double * const attitude,   //!< INPUT - Extrinsic angles (phi, theta, psi).
      const RotationType type,         //!< INPUT - the rotation type
      double * const r                 //!< OUTPUT - an (x,y,z) point with respect to the destination frame
      );

/**
 *  @brief Converts intrinsic rates to body frame rates on a right-handed Cartesian coordinate system given an active intrinsic attitude. Note: this is the body angular velocity not the reference frame velocity. For example, the code below calculates the body angular velocity with respect to the body frame, given
 - an attitude represented by intrinsic rotations of 10 degrees around the x-axis and 20 degrees around the y-axis, and
 - body angular velocity with respect to the inertial frame
 \code
 double frame_rate[3] = { 0 * D2R, 0 * D2R, 0 * D2R };
 double attitude[2] = { 10 * D2R, 20 * D2R };
 double body_rate[3];
 intrinsic2body_rate(frame_rate, attitude, body_rate);
 \endcode
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void intrinsic2body_rate(
      const double * const intrinsic,        //!< INPUT - Intrinsic rate (phi, theta, psi).
      const double * const partial_attitude, //!< INPUT - (phi, theta) intrinsic attitude (psi not required for this transform)
      double * const body                    //!< OUTPUT - Body angular rate (phi, theta, psi).
      );

/**
 *  @brief     Converts body frame rates to intrinsic rates on a right-handed Cartesian coordinate system given an active intrinsic attitude. Note: this is the body angular velocity not the reference frame velocity.
 For example, the code below calculates the body angular velocity with respect to the frame frame, given
 - an attitude represented by intrinsic rotations of 10 degrees around the x-axis and 20 degrees around the y-axis, and
 - body angular velocity with respect to the body frame
 \code
 double body_rate[3] = { 0 * D2R, 0 * D2R, 0 * D2R };
 double attitude[2] = { 10 * D2R, 20 * D2R };
 double frame_rate[3];
 body2intrinsic_rate(body_rate, attitude, frame_rate);
 \endcode
 *  @return    false if there is a gimbal lock due to extreme theta angles
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
bool body2intrinsic_rate(
      const double * const body,             //!< INPUT - Body angular rate (phi, theta, psi).
      const double * const partial_attitude, //!< INPUT - (phi, theta) intrinsic attitude (psi not required)
      double * const intrinsic               //!< OUTPUT - intrinsic rate (phi, theta, psi).
      );

/**
 *  @brief     Converts extrinsic rates to body frame rates on a right-handed Cartesian coordinate system given an active extrinsic attitude. Note: this is the body angular velocity not the reference frame velocity. For example, the code below calculates the body angular velocity with respect to the body frame, given
 - an attitude represented by extrinsic rotations of 10 degrees around the y-axis and 20 degrees around the z-axis, and
 - body angular velocity with respect to the inertial frame
 \code
 double frame_rate[3] = { 0 * D2R, 0 * D2R, 0 * D2R };
 double attitude[2] = { 10 * D2R, 20 * D2R };
 double body_rate[3];
 extrinsic2body_rate(frame_rate, attitude, body_rate);
 \endcode
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void extrinsic2body_rate(
      const double * const extrinsic,        //!< INPUT - Extrinsic rate (phi, theta, psi).
      const double * const partial_attitude, //!< INPUT - (theta, psi) intrinsic attitude (phi not required for this transform)
      double * const body                    //!< OUTPUT - Body angular rate (phi, theta, psi).
      );

/**
 *  @brief     Converts body frame rates to extrinsic rates on a right-handed Cartesian coordinate system given an active extrinsic attitude. Note: this is the body angular velocity not the reference frame velocity. For example, the code below calculates the body angular velocity with respect to the frame frame, given
 - an attitude represented by extrinsic rotations of 10 degrees around the y-axis and 20 degrees around the z-axis, and
 - body angular velocity with respect to the body frame
 \code
 double body_rate[3] = { 0 * D2R, 0 * D2R, 0 * D2R };
 double attitude[2] = { 10 * D2R, 20 * D2R };
 double frame_rate[3];
 body2extrinsic_rate(body_rate, attitude, frame_rate);
 \endcode
 *  @return    false if there is a gimbal lock due to extreme theta angles
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
bool body2extrinsic_rate(
      const double * const body,             //!< INPUT - Body angular rate (phi, theta, psi).
      const double * const partial_attitude, //!< INPUT - (theta, psi) intrinsic attitude (phi not required for this transform)
      double * const extrinsic               //!< OUTPUT - Extrinsic rate (phi, theta, psi).
      );

