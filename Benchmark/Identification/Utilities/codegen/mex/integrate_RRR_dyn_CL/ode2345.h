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
#include "integrate_RRR_dyn_CL_types.h"

/* Function Declarations */
extern boolean_T ismonotonic(const real_T x[2]);
extern void maxAbsThresh(const real_T a_data[], const int32_T a_size[1], const
  real_T b_data[], real_T y_data[], int32_T y_size[1]);

#endif

/* End of code generation (ode2345.h) */
