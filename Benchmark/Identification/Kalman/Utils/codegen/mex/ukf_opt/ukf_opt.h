/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ukf_opt.h
 *
 * Code generation for function 'ukf_opt'
 *
 */

#ifndef UKF_OPT_H
#define UKF_OPT_H

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
extern void ukf_opt(const emlrtStack *sp, real_T t_km1, real_T t_k, const real_T
                    x_km1_data[], const int32_T x_km1_size[1], const real_T
                    u_km1_data[], const int32_T u_km1_size[1], real_T P_data[],
                    int32_T P_size[2], const real_T y_k_data[], const int32_T
                    y_k_size[1], const real_T Rv_data[], const int32_T Rv_size[2],
                    const real_T Rn_data[], const int32_T Rn_size[2], real_T
                    alpha, real_T beta, real_T kappa, boolean_T
                    sigmaComputeMethod, real_T x_data[], int32_T x_size[1],
                    real_T K_data[], int32_T K_size[2], real_T inov_data[],
                    int32_T inov_size[1], real_T x_kkm1_data[], int32_T
                    x_kkm1_size[1], real_T P_kkm1_data[], int32_T P_kkm1_size[2],
                    real_T P_xy_data[], int32_T P_xy_size[2], real_T P_yy_data[],
                    int32_T P_yy_size[2]);

#endif

/* End of code generation (ukf_opt.h) */
