#pragma once

#include <stddef.h>
#include <math.h>

#define APBIT(pos) ( 1<<(pos) )
#define SET_BIT(x, pos) ( (x) |= (APBIT(pos)) )
#define RESET_BIT(x, pos) ( (x) &= ~(APBIT(pos)) )
#define FLIP_BIT(x, pos) ( (x) ^= (APBIT(pos)) )
#define CHECK_BIT(y, pos) ( ( 0u == ( (y)&(APBIT(pos)) ) ) ? 0u : 1u )

#ifndef INFINITY
#define INFINITY HUGE_VAL
#endif

#define D2R 0.01745329251994329547437168      // PI / 180
#define R2D 57.29577951308232286464772187     // 180 / PI

#ifndef M_PI
# define M_PI     3.14159265358979323846
# define M_PI_2   1.57079632679489661923
#endif
#define M2_PI 6.28318530717958623199

#define SIGNUM(x) (((x) > 0) - ((x) < 0))

#define RANGE_CHECK(v,a,b) ((v) < (a) ? (a) : (v) > (b) ? (b) : (v))

#define ROUND(x) ((int) ((x) + (((x) > 0) - ((x) < 0)) * 0.5))

/**
 *  @brief    Calculates the average of 2 angles
 *  @returns  the average
 *  @author   Carlos Aydos
 *  @date     8 Mar 2022
 **/
double angle_average_2(double a, double b);

/**
 *  @brief    Calculates the average value of a set of angles
 *  @returns  the average
 *  @author   Carlos Aydos
 *  @date     30 Mar 2021
 **/
double angle_average(
      const double * const a,
      size_t n);


/**
 *  @brief    Prints a matrix to stdout fixed engineering format, nice for a table-like appearance
 *  @author   Carlos Aydos
 *  @date     22 Jan 2019
 **/
void print_matrix(const double * const m, size_t n_rows, size_t n_cols);

/**
 *  @brief    Prints a matrix to stdout 17 decimal points
 *  @author   Carlos Aydos
 *  @date     7 Jul 2020
 **/
void print_matrix_full_res(const double * const m, size_t n_rows, size_t n_cols);

/**
 *  @brief    Set all array elements to value
 *  @author   Carlos Aydos
 *  @date     10 Jan 2019
 **/
void set_value(
      double * a,     //!< INPUT/OUTPUT - array of size n
      size_t n,       //!< INPUT - array size
      double value    //!< INPUT - value to set elements to
);

/**
 *  @brief     Finds the minimum double value a machine can distinguish (epsilon)
 *  @return    epsilon
 *  @author    Carlos Aydos
 *  @date      28 nov 2018
 **/
double machine_epsilon(void);

/**
 *  @brief     Finds the minimum value in integer array
 *  @return    The minimum value
 *  @author    Carlos Aydos
 *  @date      13 Jul 2018
 **/
int find_min_i(
   const int * const v,    //!< INPUT - input vector
   const int size,         //!< INPUT - number of elements
   int * const index       //!< OUTPUT - the index of the minimum or the first if more than one exist
   );

/**
 *  @brief     Finds the maximum value in integer array
 *  @return    The maximum value
 *  @author    Carlos Aydos
 *  @date      13 Jul 2018
 **/
int find_max_i(
   const int * const v, //!< INPUT - input vector
   const int size,         //!< INPUT - number of elements
   int * const index      //!< OUTPUT - the index of the maximum or the first if more than one exist
   );

/**
 *  @brief     Finds the minimum value in double array
 *  @return    The minimum value
 *  @author    Carlos Aydos
 *  @date      13 Jul 2018
 **/
double find_min_d(
   const double * const v, //!< INPUT - input vector
   const int size,         //!< INPUT - number of elements
   int * const index      //!< OUTPUT - the index of the minimum or the first if more than one exist
   );

/**
 *  @brief     Finds the maximum value in double array
 *  @return    The maximum value
 *  @author    Carlos Aydos
 *  @date      13 Jul 2018
 **/
double find_max_d(
   const double * const v, //!< INPUT - input vector
   const int size,         //!< INPUT - number of elements
   int * const index      //!< OUTPUT - the index of the maximum or the first if more than one exist
   );

/**
 *  @brief     Calculates the difference between two angles.
 *  @returns   The result is in a range of -pi to pi. A positive result means a is an angle further anti-clockwise
 *  @author    Carlos Aydos
 *  @date      12 Jul 2018
 **/
#ifdef __NVCC__
__device__ __host__
#endif
double angle_diff(double a, double b);

/**
 *  @brief     Calculates the distance between an angle and an angle interval.
 *  @returns   The result is in a range of -pi to pi. A positive result means a is an angle further anti-clockwise than the interval, a result of zero means the value is inside the interval
 *  @author    Carlos Aydos
 *  @date      02 Jan 2019
 **/
double angle_distance(double x, double a, double b);

/**
 *  @brief     element wise power of 2
 *  @returns   result vector
 *  @author    Carlos Aydos
 *  @date      11 Jul 2018
 **/
double const * pow2i(
   const double * const in,   //!< INPUT - input vector
   const int size,            //!< INPUT - number of elements
   double * const out         //!< INPUT - result vector (client allocated)
   );

/**
 *  @brief     calculates the radius of a circle given 3 points
 *  @returns   radius
 *  @author    Carlos Aydos
 *  @date      22 Nov 2022
 **/
double circle_radius(double x[3], double y[3]);

/**
 *  @brief     Compares 2 doubles.
 *  @returns   -1 if a < b, 0 if a==b, 1 if a > b
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
int compare_double(
   const void *a,
   const void *b
   );


#ifdef __XC32__
///**
// *  @brief     Finds the smallest double
// *  @returns   The result
// *  @author    Carlos Aydos
// *  @date      06 Jun 2018
// **/
double fmin(
   double a,
   double b
   );
//
///**
// *  @brief     Finds the largest double
// *  @returns   The result
// *  @author    Carlos Aydos
// *  @date      06 Jun 2018
// **/
double fmax(
   double a,
   double b
   );
#endif


/**
 *  @brief     Transforms cartesian heading to a geodetic heading
 *  @returns   The result
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
#ifdef __NVCC__
__device__ __host__
#endif
double cartesian2geodetic_heading(
   double angle
   );

/**
 *  @brief     Reverse the elements of a vector
 *  @returns   The result
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void flip(
   const double * const in,
   const int size,
   double * const out
   );

