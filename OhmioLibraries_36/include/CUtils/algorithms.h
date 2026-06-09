#pragma once
/**
 *  @brief      Calculates the Jacobian logarithm using the identity log(exp(a)+exp(b)) = max(a,b) + log(1 + exp(-|a-b|)) iteratively
 *  @returns    The result
 *  @author   Carlos Aydos
 *  @date     06 Jun 2018
 **/
double jacobian_logarithm (
    const double * const a,     //!< INPUT - The input vector
    int size                    //!< INPUT - The size of the input vector
);

#define BS_INCREASING 1
#define BS_DECREASING 0

/**
 *  @brief    Applies the bubble sort algorithm in place
 *  @author   Carlos Aydos
 *  @date     21 May 2020
 **/
void bubble_sort(
      double * const values,  //<! INPUT/OUTPUT - The array of values to be sorted
      const int n,            //<! INPUT - The array of values size
      const int increasingQ   //<! INPUT - BS_INCREASING or BS_DECREASING
      );

/**
 *  @brief    Applies a single pass of the bubble sort algorithm in place
 *  @return   0 if no change was made, 1 otherwise
 *  @author   Carlos Aydos
 *  @date     21 May 2020
 **/
int bubble_sort_pass(
      double * const values,   //<! INPUT/OUTPUT - The array of values to be sorted
      const int n,             //<! INPUT - The array of values size
      const int increasingQ    //<! INPUT - BS_INCREASING or BS_DECREASING
      );

/**
 *  @brief    Applies the bubble sort algorithm. The values array is not modified, instead an array of indices is returned
 *  @author   Carlos Aydos
 *  @date     21 May 2020
 **/
void bubble_sort_indices(
      const double * const values,    //<! INPUT - The array of values to be sorted
      int * const indices,            //<! INPUT/OUTPUT - The array of indices, client allocated
      const int n,                    //<! INPUT - The array of values size
      const int increasingQ           //<! INPUT - BS_INCREASING or BS_DECREASING
      );

/**
 *  @brief    Applies a single pass of the bubble sort algorithm. The values array is not modified, instead an array of indices is returned
 *  @return   0 if no change was made, 1 otherwise
 *  @author   Carlos Aydos
 *  @date     21 May 2020
 **/
int bubble_sort_indices_pass(
      const double * const values,    //<! INPUT - The array of values to be sorted
      int * const indices,            //<! INPUT/OUTPUT - The array of indices, client allocated
      const int n,                    //<! INPUT - The array of values size
      const int increasingQ           //<! INPUT - BS_INCREASING or BS_DECREASING
      );


