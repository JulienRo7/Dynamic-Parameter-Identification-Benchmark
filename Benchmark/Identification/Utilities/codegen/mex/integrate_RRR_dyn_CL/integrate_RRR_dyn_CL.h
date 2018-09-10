/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * integrate_RRR_dyn_CL.h
 *
 * Code generation for function 'integrate_RRR_dyn_CL'
 *
 */

#ifndef INTEGRATE_RRR_DYN_CL_H
#define INTEGRATE_RRR_DYN_CL_H

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
extern void integrate_RRR_dyn_CL(const emlrtStack *sp, const real_T X_0_data[],
  const int32_T X_0_size[1], const real_T Theta_data[], const int32_T
  Theta_size[1], real_T t_0, real_T t_f, real_T N, emxArray_real_T *t,
  emxArray_real_T *X, emxArray_real_T *Qpp);

#endif

/* End of code generation (integrate_RRR_dyn_CL.h) */
