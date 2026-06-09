#pragma once

/**
 * @file    odometry calibration.h
 * @brief   A library to facoliate the calibration of the Ohmio odometry. It uses the both GPS data when the vehicle drives a figure 8 to calculate the calibration parameters.
 * @author  Carlos Aydos
 * @date    31 Mar 2021
 **/

// 2 minutes worth of data
#define OC_N 2*60*10

typedef union
{
   struct
   {
      unsigned short front_gps_data_has_irregular_timestamps :1;
      unsigned short rear_gps_data_has_irregular_timestamps :1;
      unsigned short cannot_synchronize_gps_timestamps :1;
      unsigned short not_enough_straight_driving :1;
      unsigned short not_enough_left_steer_driving :1;
      unsigned short not_enough_right_steer_driving :1;
      unsigned short not_enough_data_points : 1;
      unsigned short timeout :1;
   };
   unsigned short word;
} calibration_error_t;

typedef struct
{
   double p[5];
   union
   {
      struct
      {
         unsigned short front_steering_scale_not_reliable :1;
         unsigned short rear_steering_scale_not_reliable :1;
         unsigned short low_accuracy :1;
      } flags;
      unsigned short word;
   };
} calibration_results_t;

void start_data_collection(void);
calibration_error_t add_front_gps_data_point(int gps_timestamp, double latitude, double longitude, double height, char quality, double rear_motor_speed, double front_steering_angle, double rear_steering_angle);
calibration_error_t add_rear_gps_data_point(int gps_timestamp, double latitude, double longitude, double height, char quality, double rear_motor_speed, double front_steering_angle, double rear_steering_angle);
calibration_error_t end_data_collection(void);
calibration_error_t do_calibration(calibration_results_t * res);
