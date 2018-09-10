/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stateJacobian.h
 *
 * Code generation for function 'stateJacobian'
 *
 */

#ifndef STATEJACOBIAN_H
#define STATEJACOBIAN_H

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
extern void stateJacobian(const emlrtStack *sp, real_T dt, const real_T x_data[],
  const int32_T x_size[1], const real_T u_data[], const int32_T u_size[1], const
  int32_T r_size[1], real_T A[529]);

#endif

/* End of code generation (stateJacobian.h) */
