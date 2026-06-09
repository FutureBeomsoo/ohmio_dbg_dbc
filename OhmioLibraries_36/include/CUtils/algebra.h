#pragma once

#include "math.h"

#define DETERMINANT_BUFFER_SIZE(n) ((2 * n * n * n + 3 * n * n + n) / 6)
#define INVERSE_BUFFER_SIZE(n) (DETERMINANT_BUFFER_SIZE(n) + 2 * n * n)
#define SAFE_INVERSE_BUFFER_SIZE(n) (INVERSE_BUFFER_SIZE(n) + n * n)


/**
 *  @brief     Matrix inverse for positive definite matrices
 *  @return    false if matrix not positive definite, true ok
 *  @author    Carlos Aydos
 *  @date      07 Dec 2018
 **/
int inverse_positive_definite(
      const double * const a,    //!< INPUT - The input matrix of size n x n
      const int n,               //!< INPUT - The size of the matrix
      double * const buff,       //!< INPUT - A temporary buffer of size INVERSE_BUFFER_SIZE, client allocated, use convenient macro INVERSE_BUFFER_SIZE
      double * const out         //!< INPUT - The inverted matrix
      );

/**
 *  @brief     Safe matrix inverse for positive definite matrices, it matrix is numerically unstable, this will always work as it uses the safe version of the cholesky decomposition
 *  @return    false if matrix not positive definite, true ok
 *  @author    Carlos Aydos
 *  @date      07 Dec 2018
 **/
int inverse_positive_definite_safe (
      const double * const a,    //!< INPUT - The input matrix of size n x n
      const int n,               //!< INPUT - The size of the matrix
      int * const indices,       //!< INPUT - a temporary buffer of size n for internal use (client allocated)
      double * const buff,       //!< INPUT - A temporary buffer of size SAFE_INVERSE_BUFFER_SIZE, client allocated, use convenient macro SAFE_INVERSE_BUFFER_SIZE
      double * const out         //!< INPUT - The inverted matrix
      );

/**
 *  @brief     Upper triangular matrix inverse
 *  @return    false if not invertible, true ok
 *  @author    Carlos Aydos
 *  @date      07 Dec 2018
 **/
int inverse_upper_triangular(
      double * const a,          //!< INPUT - The input matrix occupying the first n * n places of a buffer of total size DETERMINANT_BUFFER_SIZE. The excess memory can remain uninitialised and will be overwritten by the function. This peculiar size is the square pyramidal number and ensures there is enough memory for the recursive algorithm to calculate the determinant. Failure to allocate enough space will result in undefined behaviour or segmentation fault.
      const int n,            //!< INPUT - The size of the matrix
      double * const out         //!< OUTPUT - The n x n inverted matrix
      );

/**
 *  @brief    N-Dimensional vector length
 *  @return   vector length
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
double vector_length(
      double const * const in,    //!< INPUT - Vector
      int size                    //!< INPUT - Dimensions
      );

/**
 *  @brief    Element-wise sums of two vectors
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void vector_plus_vector(
      double const * const a,     //!< INPUT - First vector
      double const * const b,     //!< INPUT - Second vector
      int size,                   //!< INPUT - Vectors sizes
      double * const sum          //!< OUTPUT - The result
      );

/**
 *  @brief    Element-wise subtraction of two vectors
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void vector_minus_vector(
      double const * const a,     //!< INPUT - First vector
      double const * const b,     //!< INPUT - Second vector
      int size,                   //!< INPUT - Vectors sizes
      double * const subs       //!< OUTPUT - The result
      );

/**
 *  @brief    Element-wise multiplication of two vectors
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void vector_times_vector(
      double const * const a,     //!< INPUT - First vector
      double const * const b,     //!< INPUT - Second vector
      int size,                   //!< INPUT - Vectors sizes
      double * const mult       //!< OUTPUT - The result
      );

/**
 *  @brief    Element-wise multiplication of a vector and a scalar
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void scalar_times_vector(
      const double a,             //!< INPUT - The scalar
      double const * const b,     //!< INPUT - The vector
      int size,                   //!< INPUT - Vector length
      double * const r          //!< OUTPUT - The result
      );

/**
 *  @brief    Element-wise division of a scalar by a vector
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void scalar_divides_vector(
      const double a,         //!< INPUT - The scalar
      double const * const b, //!< INPUT - The vector
      int size,               //!< INPUT - Vector length
      double * const r        //!< OUTPUT - The result
      );

/**
 *  @brief      Element-wise division of a vector by a scalar
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void vector_divides_scalar(
      double const * const a,     //!< INPUT - The scalar
      const double b,             //!< INPUT - The vector
      int size,                   //!< INPUT - Vector length
      double * const r          //!< OUTPUT - The result
      );

/**
 *  @brief      Element-wise sum of a vector and a scalar
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
#ifdef __NVCC__
__device__ __host__
#endif
void vector_plus_scalar(
      double const * const a,     //!< INPUT - The scalar
      const double b,             //!< INPUT - The vector
      int size,                   //!< INPUT - Vector length
      double * const r          //!< OUTPUT - The result
      );

/**
 *  @brief      Inner product of two vectors
 *  @return     The resulting value
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
double inner_product(
      const double * const a, //!< INPUT - First vector
      const double * const b, //!< INPUT - Second vector
      const int size        //!< INPUT - Vectors length
      );

/**
 *  @brief    matrix product of self and transpose, a * a^T
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void matrix_transponse_product(
      const double * const a,  //!< INPUT - matrix
      const int rows,       //!< INPUT - number of rows of "a"
      const int cols,       //!< INPUT - number of columns of "a"
      double * const out       //!< OUTPUT - Client allocated result of size rows x rows
      );

/**
 *  @brief    Generalised matrix product of two matrices
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
#ifdef __NVCC__
__host__ __device__
#endif
void matrix_product(
      const double * const a, //!< INPUT - First matrix
      const double * const b, //!< INPUT - Second matrix
      const int a_rows,       //!< INPUT - number of rows of "a"
      const int a_cols,       //!< INPUT - number of columns of "a"
      const int b_cols,       //!< INPUT - number of columns of "b"
      double * const out      //!< OUTPUT - Client allocated result of size a_row x b_cols
      );

#ifdef __NVCC__
__device__
void matrix_product_cuda(
      const double * const a, //!< INPUT - First matrix
      const double * const b,//!< INPUT - Second matrix
      const int a_rows,//!< INPUT - number of rows of "a"
      const int a_cols,//!< INPUT - number of columns of "a"
      const int b_cols,//!< INPUT - number of columns of "b"
      double * const out//!< OUTPUT - Client allocated result of size a_row x b_cols
);
#endif

/**
 *  @brief    Pad rows and cols to a square matrix
 *  @author   Carlos Aydos
 *  @date     29 Nov 2018
 **/
void pad_square_matrix(
      const double * const mat,         //!< INPUT - input square matrix of size n x n
      const int n,                   //!< INPUT - square matrix size
      int const new_n,               //!< INPUT - new square matrix size
      const int * const pad_at,        //!< INPUT - size new_n array indicating which rows/cols to pad
      double const value,               //!< INPUT - padding value, e.g. 0
      double * const new_mat            //!< OUTPUT - output square matrix of size new_n x new_n, client allocated, it cannot be mat
      );

/**
 *  @brief    Remove rows and cols of a square matrix where diagonal is zero
 *  @return   true for success, false if row or col are greater or equal than n
 *  @author   Carlos Aydos
 *  @date     28 Nov 2018
 **/
int remove_dimensions(
      const double * const mat,  //!< INPUT - input square matrix of size n x n
      const int n,            //!< INPUT - square matrix size
      int row,                //!< INPUT - row index to remove
      int col,                //!< INPUT - column index to remove
      double * const new_mat     //!< OUTPUT - output square matrix of size new_n x new_n, client allocated, but it can be mat
      );

/**
 *  @brief    Remove rows and cols of a square matrix where diagonal is zero
 *  @author   Carlos Aydos
 *  @date     28 Nov 2018
 **/
void remove_dimensions_with_zero_diagonal(
      const double * const mat,  //!< INPUT - input square matrix of size n x n
      const int n,            //!< INPUT - square matrix size
      double epsilon,            //!< INPUT - a very small double, i.e. definition of zero (sugestion "4 * machine_epsilon()" found in util.h)
      int * const removed,      //!< INPUT - size n array indicating which rows/cols to remove
      int * const new_n,      //!< OUTPUT - new square matrix size (client allocated)
      double * const new_mat     //!< OUTPUT - output square matrix of size new_n x new_n, client allocated, but it can be mat
      );

/**
 *  @brief    Cholesky decomposition
 *  @return   true for success or false if orig is not positive definite, in which case chol is undefined
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
int cholesky(
      const double * const orig,    //!< INPUT - n x n matrix
      const int n,               //!< INPUT - matrix size
      double * const chol                  //!< OUTPUT - lower triangular Cholesky decomposition
      );

/**
 *  @brief    numerically safe Cholesky decomposition. Cholesky decomposition only applies to positive definite matrices. However, covariance matrix can be positive semi-definite. This function recognises non-PDness and applies backup strategies.
 *  @return   true - result is upper cholesky decomposition if m is PD.
 *            false - result is square root of diagonal.
 *  @author   Carlos Aydos
 *  @date     29 Nov 2018
 **/
int cholesky_safe(
      const double * const m,       //!< INPUT - n x n matrix
      const int n,                  //!< INPUT - matrix size
      double epsilon,               //!< INPUT - a very small double, i.e. definition of zero (suggestion "4 * machine_epsilon()" found in util.h)
      int * aux_indices,            //!< INPUT - a temporary buffer of size n for internal use (client allocated)
      double * aux_mat,             //!< INPUT - a temporary buffer of size n x n for internal use (client allocated)
      double *chol                  //!< OUTPUT - lower triangular Cholesky decomposition (see return value for details)
      );

/**
 *  @brief      Matrix transpose
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void transpose(
      const double * const orig, //!< INPUT - n_rows x n_cols matrix
      const int n_rows,          //!< INPUT - number of rows
      const int n_cols,          //!< INPUT - number of columns
      double * const trans       //!< OUTPUT - Client allocated transposed matrix
      );

/**
 *  @brief    Matrix inplace transpose for square matrices
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void transpose_inplace(
      double * const a,    //!< INPUT/OUTPUT - n x n matrix
      const int n          //!< INPUT - matrix size
      );

/**
 *  @brief      Calculates the volume of a unit hypersphere
 *  @return     hypersphere volume
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
double unit_hypersphere_volume(
      int n                     //!< INPUT - number of dimensions of hypersphere
      );
/**
 *  @brief      3D cross product
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
void cross_product(
      double const * const a,     //!< INPUT - First vector
      double const * const b,     //!< INPUT - Second vector
      double * const cross       //!< OUTPUT - The result
      );

/**
 *  @brief      n x n matrix determinant. This is a recursive implementation that uses Laplace's expansion.
 *  @return     Matrix determinant
 *  @author     Carlos Aydos
 *  @date       06 Dec 2018
 **/
double determinant(
      double * const a, //!< INPUT - The input matrix occupying the first n * n places of a buffer of total size DETERMINANT_BUFFER_SIZE. The excess memory can remain uninitialised and will be overwritten by the function. This peculiar size is the square pyramidal number and ensures there is enough memory for the recursive algorithm to calculate the determinant. Failure to allocate enough space will result in undefined behaviour or segmentation fault.
      const int n       //!< INPUT - The size of the matrix
      );

/**
 *  @brief      Extracts the diagonal of a square matrix
 *  @return
 *  @author     Carlos Aydos
 *  @date       21 May 2020
 **/
void diagonal(
      const double * const a, //!< INPUT - The input matrix
      const int n,       //!< INPUT - The size of the matrix
      double * const d //!< INPUT - The output vector containing the diagonal
      );

/**
 *  @brief        2x2 matrix determinant
 *  @return       Matrix determinant
 *  @author       Carlos Aydos
 *  @date         04 Dec 2018
 **/
double determinant_2d(
      const double * const a   //!< INPUT - 2x2 matrix
      );

/**
 *  @brief      3x3 matrix determinant
 *  @return     Matrix determinant
 *  @author     Carlos Aydos
 *  @date       06 Jun 2018
 **/
double determinant_3d(
      const double * const a  //!< INPUT - 3x3 matrix
      );

/**
 *  @brief    Extract square sub-matrix from matrix
 *  @return   true for success, false if parameters are invalid
 *  @author   Carlos Aydos
 *  @date     06 Dec 2018
 **/
int sub_matrix(
      const double * const a,    //!< INPUT - matrix n x n
      int n,                  //!< INPUT - matrix size
      int row,                //!< INPUT - row where the sub matrix starts
      int col,                //!< INPUT - col where the sub matrix starts
      int new_n,              //!< INPUT - size of submatrix
      double * const sub         //!< OUTPUT - submatrix of size new_n x new_n, client allocated
      );

/**
 *  @brief     2x2 matrix inverse
 *  @return    false if not invertible
 *  @author    Carlos Aydos
 *  @date      05 Dec 2018
 **/
int inverse_2d(
      double *m,        //!< INPUT - 2x2 matrix
      double epsilon, //!< INPUT - a very small double, i.e. definition of zero (suggestion "4 * machine_epsilon()" found in util.h)
      double *inv       //!< OUTPUT - 2x2 inverted matrix, client allocated
      );

/**
 *  @brief      3x3 matrix inverse
 *  @return     false if not invertible
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
int inverse_3d(
      double *m,        //!< INPUT - 3x3 matrix
      double epsilon, //!< INPUT - a very small double, i.e. definition of zero (suggestion "4 * machine_epsilon()" found in util.h)
      double *inv       //!< OUTPUT - 3x3 inverted matrix, client allocated
      );

/**
 *  @brief     Calculates norm of a 2D vector
 *  @returns   The square root of the sum of the squares
 *  @author    Carlos Aydos
 *  @date      17 Aug 2018
 **/
double norm_2d(double a, double b);

/**
 *  @brief     Calculates norm of a 3D vector
 *  @returns   The square root of the sum of the squares
 *  @author    Carlos Aydos
 *  @date      17 Aug 2018
 **/
double norm_3d(double a, double b, double c);

/**
 *  @brief     Summation of a vector
 *  @returns   The result
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double sum(
      const double * const in,
      const int size
      );

/**
 *  @brief     Cumulative summation of a vector
 *  @returns   The result
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void cumulative_sum(
      const double * const in,
      double * const out,
      const int size
      );

/**
 *  @brief     Product of all elements of a vector
 *  @returns   The result
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double prod(
      const double * const in,
      const int size
      );
