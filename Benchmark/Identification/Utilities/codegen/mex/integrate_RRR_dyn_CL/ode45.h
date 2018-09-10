/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ode45.h
 *
 * Code generation for function 'ode45'
 *
 */

#ifndef ODE45_H
#define ODE45_H

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
extern void ode45(const emlrtStack *sp, const real_T ode_tunableEnvironment_f1[3],
                  const real_T ode_tunableEnvironment_f2_data[], const int32_T
                  ode_tunableEnvironment_f2_size[1], const real_T tspan[2],
                  const real_T y0_data[], const int32_T y0_size[1],
                  emxArray_real_T *varargout_1, emxArray_real_T *varargout_2);

#endif

/* End of code generation (ode45.h) */
