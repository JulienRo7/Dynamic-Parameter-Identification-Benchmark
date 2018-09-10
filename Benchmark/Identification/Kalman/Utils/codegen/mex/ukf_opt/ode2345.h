/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ode2345.h
 *
 * Code generation for function 'ode2345'
 *
 */

#ifndef ODE2345_H
#define ODE2345_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "ukf_opt_types.h"

/* Function Declarations */
extern boolean_T ismonotonic(const real_T x[2]);
extern void maxAbsThresh(const real_T a[6], const real_T b[6], real_T y[6]);

#endif

/* End of code generation (ode2345.h) */
