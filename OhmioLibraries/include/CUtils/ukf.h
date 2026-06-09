/**
 * @file ukf.h
 *  @brief     Implementation of an Unscented Kalman Filter. A description of the UKF can be found at "Chapter 7 - The Unscented Kalman Filter, Eri A. Wan and Rudolph van der Merwe". This is the last known working <a href=http://citeseerx.ist.psu.edu/viewdoc/download;jsessionid=07C9BCA6A280D9BE4EC08246C041FE2C?doi=10.1.1.28.6470&rep=rep1&type=pdf>link</a>. The ordinary UKF uses an augmented state and covariance to include the noise terms. This implementation allows for an optional additive observation model. Another option is to use sequential sensor updates by redrawing the sigma-points. The target of this implementation at the time was an MCU with no dynamic allocation. For that reason, all memory is allocated with global variables. A few of the use cases are described with examples below.
 *
 *  First thing to do is to allocate memory for the the filter.
 *
 *  \snippet unit_tests/test_ukf.cpp Memory allocation
 *
 *  \section ex1 Example 1
 *  Example 1 tracks an object in 1 dimension by tracking position and speed and observing position and speed. There are 4 noise terms: position noise, speed noise, position observation noise and speed observation noise.
 *
 *  We need define the movement and observation models for each ukf.
 *
 *  \snippet unit_tests/test_ukf.cpp Models ex1
 *
 *  Now we are ready to run
 *
 *  \snippet unit_tests/test_ukf.cpp Assignment ex1
 *
 *  Next, we need to do a first time initialisation of the state and state covariance.
 *
 *  \snippet unit_tests/test_ukf.cpp Init ex1
 *
 *  The first time step is processed like this:
 *
 *  \snippet unit_tests/test_ukf.cpp Move1 ex1
 *  \snippet unit_tests/test_ukf.cpp Observe1 ex1
 *
 *  The second and subsequent time step are processed like this:
 *
 *  \snippet unit_tests/test_ukf.cpp Move2 ex1
 *  \snippet unit_tests/test_ukf.cpp Observe2 ex1
 *
 *  \section ex2 Example 2
 *  Example 2 tracks the same object, but with 2 differences:
 * - The observation noise is additive and the terms are added during the observation update. As a result, the state is only augmented by 2 instead of 4.
 * - The updates are treated as separate sensors updated in sequence.
 * .
 * We can reuse the movement model from the first example, but we need 2 new observation models:
 *
 *  \snippet unit_tests/test_ukf.cpp Models ex2
 *
 *   *  Now we are ready to run
 *
 *  \snippet unit_tests/test_ukf.cpp Assignment ex2
 *
 *  Now the first time initialisation of the state and state covariance.
 *
 *  \snippet unit_tests/test_ukf.cpp Init ex2
 *
 *  The first time step can be now processed. Note the 2 differences from example 1:
 *  - The observation noises are added here.
 *  - The observations are added in sequence. That requires the sigma-points to be redrawn between observations.
 *  .
 *
 *  \snippet unit_tests/test_ukf.cpp Move1 ex2
 *  \snippet unit_tests/test_ukf.cpp Observe1 ex2
 *
 * The second and subsequent time step are processed like this:
 *
 *  \snippet unit_tests/test_ukf.cpp Move2 ex2
 *  \snippet unit_tests/test_ukf.cpp Observe2 ex2
 *
 *  Additional notes:
 *  - The above examples show 2 filters running in complete time isolation for a better flow of the examples. But it is possible to run both instances, one time step at a time, but it required to call ASSIGN_UKF before a call to movement_update to point the memory to the right instance.
 *
 *  @author    Carlos Aydos
 *  @date      23 Jan 2019
 **/

#pragma once
#include <stdint.h>
#include "stdbool.h"
#include "lkf.h"

typedef union
{
   uint32_t word;
   struct
   {
      uint32_t cholesky_failed :1;
      uint32_t innovation_covariance_not_psd :1;
      uint32_t nonpositive_variance :1;
      uint32_t nan_or_inf :1;
      uint32_t outlier_detected :1;
   };
} ukf_flags;
/**
 * @brief Structure containing all the memory members required by the filter. The memory these members point to is allocated by the client
 */
typedef struct
{
   lkf_t l;
   double *predicted_cross_covariance;
   int n_aug;
   int n_sp;
   int n_xa;
   double _kappa;
   double *_augmented_state;
   double *_augmented_covariance;
   int *_aux_indices;
   double *_aux_buf;
   double *_sp;
   double *_delta1;
   double *_weights;
   double *_delta2;
   double *_inverted_observation_model;
   double *_sp_trans;
   double *_predicted_observations;
   double *_predicted_observations_variances;
} ukf_t;

/**
 *  @brief    Produces a set of sigma-points and weights
 *  @returns  False if Cholesky failed, else true;
 *  @author   Carlos Aydos
 *  @date     30 Nov 2018
 **/
bool sigma_points(
      const int n,                        //!< INPUT - The number of variables
      const double kappa,                 //!< INPUT - Sigma point scaling factor
      const double * const state,         //!< INPUT - State buffer of size n
      const double * const covariance,    //!< INPUT - Covariance matrix of size n x n
      int * const aux_indices,            //!< INPUT - Temporary storage of size n for internal purposes, client allocated
      double * const aux_buf,             //!< INPUT - Temporary storage of size 2 x n x n for internal purposes, client allocated
      double * const sigma_points,        //!< OUTPUT - Sigma points in a (n) x (1 + 2 * n) matrix, client allocated
      double * const weights              //!< OUTPUT - Sigma point weights in a buffer of size 1 + 2 * n, client allocated
      );

/**
 *  @brief    Calculated state and covariance from a set of sigma-points and weights
 *  @author   Carlos Aydos
 *  @date     30 Nov 2018
 **/
void unscented_transform(
      const double * const sp,            //!< INPUT - Sigma point matrix of size n_a, n_sp
      const double * const weights,       //!< INPUT - Sigma point weights in a buffer of size n_sp
      const int n_a,                      //!< INPUT - The size of fist dimension of sp
      const int n_sp,                     //!< INPUT - The size of the second dimension of sp, typically the number of Sigma points
      const int n,                        //!< INPUT - The number of variables to be calcualted
      double * const delta,               //!< OUTPUT - Temporary variable of size (n) x (n_sp), client allocated
      double * const state,               //!< OUTPUT - State buffer of size n
      double * const covariance           //!< OUTPUT - Covariance matrix of size n x n
      );

/**
 *  @brief    Provides the movement update framework. The client needs to provide the movement_model() for the the transformation of the sigma-points
 *  @author   Carlos Aydos
 *  @date     30 Nov 2018
 **/
ukf_flags movement_update(
      ukf_t * const ukf,                  //!< INPUT/OUTPUT - ukf_t structure with the current filter state
      const void * const inputs, //!<// Now create an instance named "ukf" INPUT - Generic pointer to user data to be passed to movement_model()
      const double elapsed,               //!< INPUT - the time elapsed since last time movement_model() was called
      bool additive_process_noise,        //!< INPUT - use the additive process noise matrix
      void (*movement_model)(
            ukf_t * const ukf,
            const void * const inputs,
            const double elapsed)       //!< INPUT - Function for the transformation of the sigma-points with the given parameter signature.
            );

/**
 *  @brief    Provides the observation update framework. The client needs to provide the observation_model() for the mapping of the state to the observations
 *  @author   Carlos Aydos
 *  @date     10 Jan 2019
 *  @return   Returns true if an outlier was detected
 **/
ukf_flags observation_update(
      ukf_t * const ukf,                                 //!< INPUT/OUTPUT - ukf_t structure with the current filter state
      int n_z,                                           //!< INPUT - Size of the observation vector
      int n_sp,                                          //!< INPUT - Number of sigma-points.
      int outlier_nis_threshold,                         //!< INPUT - The distance criteria to ignore outliers, 0 never ignores.
      const void * const inputs,                         //!< INPUT - Generic pointer to user data to be passed to observation_model()
      const double * const observations,                 //!< INPUT - The observation vector
      const double * const additive_observation_noise,   //!< INPUT - The observation noise model (n_z x n_z)
      void (innovation_callback)(), //!< INPUT - Handled called after innovation was calculated. Useful to make custom transformations to the innovation such as overflow management. Pass NULL if unused.
      void (*observation_model)(
            ukf_t * const ukf,
            const void * const inputs)  //!< INPUT - Function for the transformation of the sigma-points with the given parameter signature.
            );

// must be called before augmented_state_update
void unscented_cross_covariance(
      const ukf_t * const ukf,
      double * const delta3,
      double * const cross_covariance);

void backwards_recursion(
      int n_x,
      const double * const estimated_state_0,
      const double * const estimated_covariance_0,
      const double * const predicted_state_1,
      const double * const predicted_covariance_1,
      const double * const smoothed_state_1,
      const double * const smoothed_covariance_1,
      const double * const predicted_cross_covariance_1,
      double * const aux_buf_inv_smo,
      double * const inverted_predicted_covariance,
      double * const smoother_gain,
      double * const smoothed_state_0,
      double * const smoothed_covariance_0
      );

void backwards_pass(
      int t_steps,
      int n_x,
      const double * const estimated_state,
      const double * const estimated_covariance,
      const double * const predicted_state,
      const double * const predicted_covariance,
      const double * const predicted_cross_covariance,
      double * const aux_buf_inv_smo,
      double * const inverted_predicted_covariance,
      double * const smoother_gain,
      double * const smoothed_state,
      double * const smoothed_covariance
      );

bool redraw(ukf_t * const ukf);

/**
 *  @brief    Macro for allocating memory for UKF. Memory is allocated on the stack so it cannot be used outside the scope in which it was declared. This is a single memory block that can be shared by multiple filter instances. Choose the largest MAX_N_X, MAX_N_AUG and MAX_N_Z of all filter instances
 *  @author   Carlos Aydos
 *  @date     1 May 2020
 **/
#define ALLOCATE_UKF(MAX_N_X,MAX_N_AUG,MAX_N_Z) \
   ALLOCATE_LKF(MAX_N_X,MAX_N_Z) \
   const int max_n_aug = MAX_N_AUG; \
   const int maxn_xa = MAX_N_X + MAX_N_AUG;  \
   const int max_n_sp = 1 + 2 * (MAX_N_X + MAX_N_AUG); \
   int aux_indices[(MAX_N_X + MAX_N_AUG + MAX_N_Z)]; \
   double aux_buf[2 * (MAX_N_X + MAX_N_AUG) * (MAX_N_X + MAX_N_AUG)]; \
   double sp[(MAX_N_X + MAX_N_AUG) * (1 + 2 * (MAX_N_X + MAX_N_AUG))]; \
   double delta1[MAX_N_X * (1 + 2 * (MAX_N_X + MAX_N_AUG))]; \
   double weights[1 + 2 * (MAX_N_X + MAX_N_AUG)]; \
   double delta2[MAX_N_Z * (1 + 2 * (MAX_N_X + MAX_N_AUG))]; \
   double inverted_observation_model[MAX_N_X * MAX_N_Z]; \
   double sp_trans[MAX_N_Z * (1 + 2 * (MAX_N_X + MAX_N_AUG))]; \
   double transformed_state[MAX_N_Z];  \
   double transformed_variances[MAX_N_X * MAX_N_Z];  \
   double state_augmented[(MAX_N_X + MAX_N_AUG)]; \
   double covariance_augmented[(MAX_N_X + MAX_N_AUG) * (MAX_N_X + MAX_N_AUG)];

#define EXTERN_UKF \
   EXTERN_LKF \
   extern const int max_n_aug; \
   extern const int maxn_xa;  \
   extern const int max_n_sp; \
   extern int aux_indices[]; \
   extern double aux_buf[]; \
   extern double sp[]; \
   extern double delta1[]; \
   extern double weights[]; \
   extern double delta2[]; \
   extern double inverted_observation_model[]; \
   extern double sp_trans[]; \
   extern double transformed_state[];  \
   extern double transformed_variances[];  \
   extern double state_augmented[]; \
   extern double covariance_augmented[];

/**
 *  @brief    Allocates memory specific to an instance of a UKF. Memory is allocated on the stack so it cannot be used outside the scope in which it was declared. This is a single memory block that can be shared by multiple filter instances. N_X, N_AUG and N_Z must no be larger than the ones used for ALLOCATE_UKF. UKF must be a unique name associated with this this instance
 *  @author   Carlos Aydos
 *  @date     1 May 2020
 **/
#define ALLOCATE_UKF_INSTANCE(UKF,N_X,N_Z) \
   ALLOCATE_LKF_INSTANCE(UKF,N_X,N_Z) \
   double UKF##_predicted_cross_covariance[N_X * N_X];

/**
 *  @brief    Assigns previously allocated memory to a specific UKF instance
 *  @author   Carlos Aydos
 *  @date     1 May 2020
 **/

#define ASSIGN_UKF(UKF,N_X,N_AUG) \
   assert(N_X <= max_n_x);  \
   UKF.l.n_x = N_X; \
   UKF.l.n_x_bytes = N_X * sizeof(double); \
   UKF.l.n_cov_bytes = N_X * N_X * sizeof(double); \
   UKF.l._aux_buf_inv = aux_buf_inv; \
   UKF.l._inverted = inverted; \
   UKF.l._tranposed_observation_model = tranposed_observation_model; \
   UKF.l._gain = gain; \
   UKF.l._gain_t = gain_t; \
   UKF.l._temp1 = temp1; \
   UKF.l._temp2 = temp2; \
   UKF.l.estimated_state = UKF##_estimated_state; \
   UKF.l.estimated_covariance = UKF##_estimated_covariance; \
   UKF.l.predicted_state = UKF##_predicted_state; \
   UKF.l.predicted_covariance = UKF##_predicted_covariance; \
   UKF.l.innovation = UKF##_innovation; \
   UKF.l.innovation_covariance = UKF##_innovation_covariance; \
   UKF.l.nis = &UKF##_nis; \
   UKF.l.process_noise = UKF##_process_noise; \
   UKF.l.process_model = UKF##_process_model; \
   assert(N_X <= max_n_x);  \
   assert(N_AUG <= max_n_aug);  \
   assert(1 + 2 * (N_X + N_AUG) <= max_n_sp);  \
   assert(N_X + N_AUG <= maxn_xa);  \
   UKF._kappa = 0.1; \
   UKF.n_aug = N_AUG;  \
   UKF.n_sp = 1 + 2 * (N_X + N_AUG); \
   UKF.n_xa = N_X + N_AUG;  \
   UKF._augmented_state = state_augmented; \
   UKF._augmented_covariance = covariance_augmented; \
   UKF._aux_indices = aux_indices; \
   UKF._aux_buf = aux_buf; \
   UKF._sp = sp; \
   UKF._delta1 = delta1; \
   UKF._weights = weights; \
   UKF._delta2 = delta2; \
   UKF._inverted_observation_model = inverted_observation_model; \
   UKF._sp_trans = sp_trans; \
   UKF._predicted_observations = transformed_state; \
   UKF._predicted_observations_variances = transformed_variances; \
   UKF.predicted_cross_covariance = UKF##_predicted_cross_covariance; \
   for(int i = 0; i < (N_X + N_AUG); i++) \
      state_augmented[i] = 0; \
   for(int i = 0; i < (N_X + N_AUG) * (N_X + N_AUG); i++) \
      covariance_augmented[i] = 0; \
   for(int i = 0; i < N_X; i++) \
      UKF##_estimated_state[i] = 0; \
   for(int i = 0; i < N_X * N_X; i++) \
      UKF##_estimated_covariance[i] = 0;
//(void)UKF##_process_noise; // just to avoid unused warning

#define INSTANTIATE_UKS(UKF,N_X,N_AUG,MAX_T_STEPS) \
   double UKF##_max_t_steps = MAX_T_STEPS; \
   double UKF##_estimated_state_uks[N_X*MAX_T_STEPS]; \
   double UKF##_estimated_covariance_uks[N_X*N_X*MAX_T_STEPS]; \
   double UKF##_predicted_state_uks[N_X*MAX_T_STEPS]; \
   double UKF##_predicted_covariance_uks[N_X*N_X*MAX_T_STEPS]; \
   double UKF##_predicted_cross_covariance_uks[N_X*N_X*MAX_T_STEPS]; \
   double delta3[N_X * (1 + 2 * (N_X + N_AUG))]; \
   double aux_buf_inv_smo[INVERSE_BUFFER_SIZE(N_X)]; \
   double inverted_predicted_covariance[N_X*N_X]; \
   double smoother_gain[N_X*N_X]; \
   double smoothed_state[N_X*MAX_T_STEPS]; \
   double smoothed_covariance[N_X*N_X*MAX_T_STEPS];

