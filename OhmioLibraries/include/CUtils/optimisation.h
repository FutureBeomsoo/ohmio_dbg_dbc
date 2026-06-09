#pragma once

#include "dims.h" // project specific files that needs to define MAX_DIM (maximum number of vertices a simplex can have)

#define BEST_I idx[0]
#define WORST_I idx[pdim]
#define BEST_P p[BEST_I]
#define WORST_P p[WORST_I]

/**
 * Nelder-Mead optimiser.
 * @return The number of iterations performed
 */
int simplex_optimiser(
      const double p0[],                  //!< INPUT - Initial point
      const int pdim,                     //!< INPUT - Number of dimensions of initial point
      const double p0_width,              //!< INPUT - % width of the initial simplex
      const double ytol,                  //!< INPUT - convergence absolute tolerance for height of the simplex
      const double xtol,                  //!< INPUT - convergence absolute tolerance for diameter of the simplex
      const int nmax,                     //!< INPUT - maximum number of iterations allowed
      double (*cost)(double [MAX_DIM]),   //!< INPUT - the cost function
      double out[MAX_DIM],                //!< OUTPUT - the optimised point
      double * const yval);               //!< OUTPUT - the cost at the optimised point

