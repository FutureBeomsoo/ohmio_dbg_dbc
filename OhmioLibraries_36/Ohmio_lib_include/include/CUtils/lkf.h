/**
 * @file lkf.h
 * @brief   Linear Kalman filter
 * @author    Carlos Aydos
 * @date      23 Jan 2019
 **/

#pragma once

#include "algebra.h"
#include "stdbool.h"
#include <assert.h>

/**
 * @brief Structure containing all the memory members required by the filter. The memory these members point to is allocated by the client
 */
typedef struct
{
   double * estimated_state;
   double * estimated_covariance;
   double * innovation;
   double * innovation_covariance;
   double * nis;
   double * process_noise; // this is not automatically scaled by the elapsed time, if elapsed varies, this matrix would typically vary too
   double * process_model;
   int n_x;
   int n_x_bytes;
   int n_cov_bytes;
   double * predicted_state;
   double * predicted_covariance;
   double * _aux_buf_inv;
   double * _inverted;
   double * _tranposed_observation_model;
   double * _gain;
   double * _gain_t;
   double * _temp1;
   double * _temp2;
} lkf_t;

void linear_process_update(lkf_t * lkf);

/**
 *  @brief    Provides the linear observation update framework.
 *  @author   Carlos Aydos
 *  @date     24 Jan 2019
 **/
bool linear_observation_update(
      lkf_t * const lkf,                                //!< INPUT/OUTPUT - lkf_t structure with the current filter state
      int n_z,                               //!< INPUT - Size of the observation vector
      int outlier_nis_threshold,                       //!< INPUT - The distance criteria to ignore outliers, 0 never ignores.
      const double * const observations,         //!< INPUT - The observation vector
      const double * const linear_observation_model, //!< INPUT - The observation model (e.g. H)
      const double * const additive_observation_noise          //!< INPUT - The observation noise model (n_z x n_z)
      );

void kalman_gain(lkf_t * const lkf, int n_z);

/**
 *  @brief    Macro for allocating memory for LKF. Memory is allocated on the stack so it cannot be used outside the scope in which it was declared. This is a single memory block that can be shared by multiple filter instances. Choose the largest MAX_N_X, MAX_N_AUG and MAX_N_Z of all filter instances
 *  @author   Carlos Aydos
 *  @date     1 May 2020
 **/
#define ALLOCATE_LKF(MAX_N_X,MAX_N_Z) \
   const int max_n_x = MAX_N_X;  \
   double temp2[MAX_N_X * MAX_N_X]; \
   double aux_buf_inv[SAFE_INVERSE_BUFFER_SIZE(MAX_N_Z)]; \
   double inverted[MAX_N_Z * MAX_N_Z]; \
   double tranposed_observation_model[MAX_N_X * MAX_N_Z]; \
   double gain[MAX_N_X * MAX_N_Z]; \
   double gain_t[MAX_N_Z * MAX_N_X]; \
   double temp1[MAX_N_X * MAX_N_Z];

#define EXTERN_LKF \
   extern const int max_n_x;  \
   extern double temp2[]; \
   extern double aux_buf_inv[]; \
   extern double inverted[]; \
   extern double tranposed_observation_model[]; \
   extern double gain[]; \
   extern double gain_t[]; \
   extern double temp1[];

/**
 *  @brief    Allocates memory specific to an instance of a LKF. Memory is allocated on the stack so it cannot be used outside the scope in which it was declared. This is a single memory block that can be shared by multiple filter instances. N_X, N_AUG and N_Z must no be larger than the ones used for ALLOCATE_LKF. LKF must be a unique name associated with this this instance
 *  @author   Carlos Aydos
 *  @date     1 May 2020
 **/
#define ALLOCATE_LKF_INSTANCE(LKF,N_X,N_Z) \
   double LKF##_estimated_state[N_X]; \
   double LKF##_estimated_covariance[N_X * N_X]; \
   double LKF##_predicted_state[N_X]; \
   double LKF##_predicted_covariance[N_X * N_X]; \
   double LKF##_innovation[N_Z]; \
   double LKF##_innovation_covariance[N_Z * N_Z]; \
   double LKF##_nis; \
   double LKF##_process_noise[N_X * N_X]; \
   double LKF##_process_model[N_X * N_X];

/**
 *  @brief    Assigns previously allocated memory to a specific LKF instance
 *  @author   Carlos Aydos
 *  @date     1 May 2020
 **/

#define ASSIGN_LKF(LKF,N_X) \
   assert(N_X <= max_n_x);  \
   LKF.n_x = N_X; \
   LKF.n_x_bytes = N_X * sizeof(double); \
   LKF.n_cov_bytes = N_X * N_X * sizeof(double); \
   LKF._aux_buf_inv = aux_buf_inv; \
   LKF._inverted = inverted; \
   LKF._tranposed_observation_model = tranposed_observation_model; \
   LKF._gain = gain; \
   LKF._gain_t = gain_t; \
   LKF._temp1 = temp1; \
   LKF._temp2 = temp2; \
   LKF.estimated_state = LKF##_estimated_state; \
   LKF.estimated_covariance = LKF##_estimated_covariance; \
   LKF.predicted_state = LKF##_predicted_state; \
   LKF.predicted_covariance = LKF##_predicted_covariance; \
   LKF.innovation = LKF##_innovation; \
   LKF.innovation_covariance = LKF##_innovation_covariance; \
   LKF.nis = &LKF##_nis; \
   LKF.process_noise = LKF##_process_noise; \
   LKF.process_model = LKF##_process_model;


