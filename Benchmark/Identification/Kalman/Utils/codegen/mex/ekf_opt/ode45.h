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
#include "ekf_opt_types.h"

/* Function Declarations */
extern void ode45(const emlrtStack *sp, const cell_wrap_1
                  ode_tunableEnvironment[2], const real_T tspan[2], const real_T
                  b_y0[6], emxArray_real_T *varargout_1, emxArray_real_T
                  *varargout_2);

#endif

/* End of code generation (ode45.h) */
