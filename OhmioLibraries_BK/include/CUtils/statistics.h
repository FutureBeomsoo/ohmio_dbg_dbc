#pragma once
#include <stdbool.h>


/**
 *  @brief     Estimates the maximum a posteriori of a multivariate sample.
 *  @author    Carlos Aydos
 *  @date      16 Jul 2018
 **/
void maximum_a_posteriori(
   const double * const samples, //!< INPUT - Input array
   int n_samples,                //!< INPUT - Number of samples
   int n_vars,                   //!< INPUT - Number of variables
   int * votes,                  //!< INPUT - Utility buffer for internal use of size n_samples. Client allocated.
   int * membership,             //!< INPUT - Utility buffer for internal use of size n_samples. Client allocated.
   double * map_estimate         //!< OUTPUT - maximum a posteriori estimate of size n_vars
   );

/**
 *  @brief     Estimates the maximum a posteriori of a multivariate sample. No dynamic memory allocation
 *  @author    Carlos Aydos
 *  @date      21 Nov 2018
 **/
void maximum_a_posteriori_noalloc(
   const double * const samples, //!< INPUT - Input array
   int n_samples,                //!< INPUT - Number of samples
   int n_vars,                   //!< INPUT - Number of variables
   int * votes,                  //!< INPUT - Utility buffer for internal use of size n_samples. Client allocated.
   int * membership,             //!< INPUT - Utility buffer for internal use of size n_samples. Client allocated.
   int * max_n_bins,             //!< INPUT/OUTPUT - The maximum number of bins the histogram algorithm can use. Determines the size of the two following inputs, if the size was not large enough, it will use the input value. The value required replaces the input value for future programmer consideration.
   int * counts,                 //!< INPUT - Utility buffer for internal use of size max_n_bins. Client allocated.
   double * edges,               //!< INPUT - Utility buffer for internal use of size max_n_bins + 1. Client allocated.
   double * map_estimate         //!< OUTPUT - maximum a posteriori estimate of size n_vars
   );

/**
 *  @brief     Allocates samples into bins. Bin widths are automatic estimated using Scott's rule.
 *  @return    The number of bins
 *  @author    Carlos Aydos
 *  @date      13 Jul 2018
 **/
int histogram(
   const double * const samples, //!< INPUT - Input array
   int size,                     //!< INPUT - Number of elements
   int * membership,             //!< OUTPUT - An array of size "size" with the membership of each sample, client allocated.
   int ** counts,                //!< OUTPUT - An array of size "number of bins" containing the counts of each bin. This is allocated internally and must be freed by the client.
   double ** edges               //!< OUTPUT - An array of size "number of bins" + 1 containing the edges of each bin. This is allocated internally and must be freed by the client.
   );

/**
 *  @brief     Identical functionality to histogram(), but no dynamic memory allocation
 *  @return    The number of bins
 *  @author    Carlos Aydos
 *  @date      21 Nov 2018
 **/
int histogram_noalloc(
   const double * const samples, //!< INPUT - Input array
   int size,                     //!< INPUT - Number of elements
   int * membership,             //!< OUTPUT - An array of size "size" with the membership of each sample, client allocated.
   int * max_n_bins,             //!< INPUT/OUTPUT - Maximum number of bins which determines the size of the the two following inputs, if the size was not large enough, it will use the input value. The value required replace the input value for future programmer consideration.
   int * counts,                 //!< OUTPUT - An array of size max_n_bins containing the counts of each bin. client allocated.
   double * edges                //!< OUTPUT - An array of size max_n_bins + 1 containing the edges of each bin. client allocated.
   );


/**
 *  @brief     Single uniform random number generator
 *  @return    Returns a sample between 0 and 1
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double random_uniform(void);

/**
 *  @brief     Multiple random number generator
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void random_uniform_buffer(
   const int size,            //!< INPUT - Buffer size
   double * const out         //!< OUTPUT - Client allocated pointer to the resulting buffer
   );
/**
 *  @brief     Single gaussian random number generator
 *  @return    Returns a sample from a mean of 0 and std deviation of 1
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double random_gaussian(void);

/**
 *  @brief     Multi-variate gaussian random number generator. The distribution covariance is diagonal.
 *  @return    Returns a sample from a mean of mu and covariance diagonal sigma
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double multi_gaussian_pdf_simple(
   const double * const x,       //!< INPUT - the value to evaluate the probability
   const double * const mu,      //!< INPUT - a vector of size "size" containing the means
   const double * const sigma,   //!< INPUT - a vector of size "size" containing the covariance diagonal
   const int size                //!< INPUT - number of variables
   );

/**
 *  @brief     Same as multi_gaussian_pdf_simple, but no dynamic allocation
 *  @return    Returns a sample from a mean of mu and covariance diagonal sigma
 *  @author    Carlos Aydos
 *  @date      15 Jun 2018
 **/
double multi_gaussian_pdf_simple_noalloc(
   const double * const x,          //!< INPUT - the value to evaluate the probability
   const double * const mu,         //!< INPUT - a vector of size "size" containing the means
   const double * const sigma,      //!< INPUT - a vector of size "size" containing the covariance diagonal
   const int size,                  //!< INPUT - number of variables
   double * const delta,      //!< INPUT - Utility buffer for internal use of size size. Client allocated.
   double * const mahalanobis //!< INPUT - Utility buffer for internal use of size size. Client allocated.
   );

/**
 *  @brief     Single Epaneshnikov random number generator
 *  @return    Returns a sample between -1 and 1
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double random_epaneshnikov(void);

/**
 *  @brief     Multiple random number generator of numbers between -1 and 1
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void random_epaneshnikov_buffer(
   const int size,                //!< INPUT - Buffer size
   double * const out             //!< OUTPUT - Client allocated pointer to the resulting buffer
   );

/**
 *  @brief     Unbiased variance estimation
 *  @return    Returns the sample variance
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
double variance(
   const double * const x,   //!< INPUT - Samples
   const int size      //!< INPUT - Buffer size
   );

/**
 *  @brief     Estimation of the mean
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void mean(
   const double * const x,   //!< INPUT - Samples (n_s x n_var)
   const int n_var,          //!< INPUT - number of variables (columns)
   const int n_s,            //!< INPUT - number of samples (rows)
   double * const mu         //!< OUTPUT - Client allocated output of n_var length
   );

/**
 *  @brief     Estimation of the mean of weighted samples
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void weighted_mean(
   const double * const x,   //!< INPUT - Samples (n_s x n_var)
   const double * const w,   //!< INPUT - Weights (n_s)
   const int n_var,          //!< INPUT - number of variables (columns)
   const int n_s,            //!< INPUT - number of samples (rows)
   double * const mu,        //!< OUTPUT - Client allocated output of n_var length
   double * const sum_w_o    //!< OUTPUT (OPTIONAL) - Client allocated output. Sum of the weights if !NULL.
   );

/**
 *  @brief     Bernoully trial
 *  @return    trial outcome
 *  @author    Carlos Aydos
 *  @date      07 Nov 2018
 **/
bool bernoulli(double p);

/**
 *  @brief     Estimation of the covariance
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
void covariance(
   const double * const x, //!< INPUT - Samples (n_s x n_var)
   const int n_var,        //!< INPUT - Number of variables (columns)
   const int n_s,          //!< INPUT - Number of samples (rows)
   double * const cov      //!< OUTPUT - Client allocated covariance (n_var x n_var)
   );

/**
 *  @brief     Estimation of the covariance without internal memory alloaction
 *  @author    Carlos Aydos
 *  @date      20 Nov 2018
 **/
void covariance_noalloc(
   const double * const x, //!< INPUT - Samples (n_s x n_var)
   const int n_var,        //!< INPUT - Number of variables (columns)
   const int n_s,          //!< INPUT - Number of samples (rows)
   double * aux_mu,        //!< INPUT - A temporary buffer if size n_s (client allocated)
   double * const cov      //!< OUTPUT - Client allocated covariance (n_var x n_var)
   );

/**
 *  @brief     Estimation of the covariance of weighted samples
 *  @return    0 for success, -1 is weights are ill-formed
 *  @author    Carlos Aydos
 *  @date      06 Jun 2018
 **/
int weighted_covariance(
   const double * const x, //!< INPUT - Samples (n_s x n_var)
   const double * const w, //!< INPUT - Weights (n_s)
   const int n_var,        //!< INPUT - Number of variables (columns)
   const int n_s,          //!< INPUT - Number of samples (rows)
   double * const cov      //!< OUTPUT - Client allocated covariance (n_var x n_var)
   );

/**
 *  @brief     Same as weighted_covariance, but with no dynamic memory allocation
 *  @return    0 for success, -1 is weights are ill-formed
 *  @author    Carlos Aydos
 *  @date      15 May 2019
 **/
int weighted_covariance_noalloc(
   const double * const x, //!< INPUT - Samples (n_s x n_var)
   const double * const w, //!< INPUT - Weights (n_s)
   const int n_var,        //!< INPUT - Number of variables (columns)
   const int n_s,          //!< INPUT - Number of samples (rows)
   double * const aux_mu,       //!< INPUT - A temporary buffer if size n_var (client allocated)
   double * const cov      //!< OUTPUT - Client allocated covariance (n_var x n_var)
   );