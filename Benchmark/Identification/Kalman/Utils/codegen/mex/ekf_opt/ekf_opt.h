/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ekf_opt.h
 *
 * Code generation for function 'ekf_opt'
 *
 */

#ifndef EKF_OPT_H
#define EKF_OPT_H

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
extern void ekf_opt(const emlrtStack *sp, real_T t_km1, real_T t_k, const real_T
                    x_km1_data[], const int32_T x_km1_size[1], const real_T
                    u_km1_data[], const int32_T u_km1_size[1], const real_T
                    P_km1_data[], const int32_T P_km1_size[2], const real_T
                    y_k_data[], const int32_T y_k_size[1], const real_T Rv_data[],
                    const int32_T Rv_size[2], const real_T Rn_data[], const
                    int32_T Rn_size[2], real_T x[23], real_T P[529], real_T K[69],
                    real_T inov[3], real_T x_kkm1_data[], int32_T x_kkm1_size[1],
                    real_T P_kkm1[529], real_T P_xy[69], real_T P_yy[9]);

#endif

/* End of code generation (ekf_opt.h) */
