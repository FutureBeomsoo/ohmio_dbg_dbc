#pragma once


/**
 *  @brief    Binomial coefficient
 *  @returns  n!/k!(n-k)!
 *  @author   Carlos Aydos
 *  @date     29 May 2020
 **/
int n_choose_k(int n, int k);

/**
 *  @brief    Combination of n items, picked k at a time
 *  @returns  the number of combinations
 *  @author   Carlos Aydos
 *  @date     29 May 2020
 **/
int combine_n_k(
      int n,
      int k,
      int * const combinations  //!< OUTPUT - A table where each combination is a row and the number of columns is k. The number of rows is n_choose_k(n,k). Client allocated.
      );
