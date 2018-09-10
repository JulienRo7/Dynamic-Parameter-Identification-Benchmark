/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * propagate_RRR_Additive.h
 *
 * Code generation for function 'propagate_RRR_Additive'
 *
 */

#ifndef PROPAGATE_RRR_ADDITIVE_H
#define PROPAGATE_RRR_ADDITIVE_H

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
#include "srukf_opt_types.h"

/* Function Declarations */
extern void __anon_fcn(const emlrtStack *sp, const real_T u_km1_data[], const
  int32_T u_km1_size[1], const real_T Theta_data[], const int32_T Theta_size[1],
  const real_T y[6], real_T varargout_1[6]);
extern void propagate_RRR_Additive(const emlrtStack *sp, real_T t_km1, real_T
  t_k, const real_T x_km1_data[], const int32_T x_km1_size[1], const real_T
  u_km1_data[], const int32_T u_km1_size[1], const real_T q_km1_data[], const
  int32_T q_km1_size[1], real_T x_data[], int32_T x_size[1]);

#endif

/* End of code generation (propagate_RRR_Additive.h) */
