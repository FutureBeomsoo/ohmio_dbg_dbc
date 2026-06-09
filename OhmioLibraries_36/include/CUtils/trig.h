/**
 * @file trig.h
 *  @brief     Implementation hyperbolic trigonometry functions sinh(x), cosh(x) and tanh(x) and their inverses. These are a re-implementation to avoid a XC32 compiler bug. These are exposed via the following macros:
 *  - SINH(X)
 *  - COSH(X)
 *  - TANH(X)
 *  - ASINH(X)
 *  - ACOSH(X)
 *  - ATANH(X)
 *
 *  You must compile the code with the compiler option -DHYP_TRIG=HMI for this to make effect, otherwise the macros substitute the stdlib <math.h> functions.
 *  @author    Carlos Aydos
 *  @date      26 Feb 2019
 **/
#pragma once

#include <math.h>

#define HMI 1

#if HYP_TRIG == HMI
#define SINH(x) ((exp(x)-exp(-(x)))/2)
#define COSH(x) ((exp(x)+exp(-(x)))/2)
#define TANH(x) (SINH(x)/COSH(x))
#define ASINH(x) log((x)+sqrt((x)*(x)+1))
#define ACOSH(x) log((x)+sqrt((x)*(x)-1))
#define ATANH(x) (0.5*log((1+(x))/(1-(x))))
#else
#define SINH(x) sinh(x)
#define COSH(x) cosh(x)
#define TANH(x) tanh(x)
#define ASINH(x) asinh(x)
#define ACOSH(x) acosh(x)
#define ATANH(x) atanh(x)
#endif

