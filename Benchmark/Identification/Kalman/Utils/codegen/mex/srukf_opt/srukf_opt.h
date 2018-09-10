/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * srukf_opt.h
 *
 * Code generation for function 'srukf_opt'
 *
 */

#ifndef SRUKF_OPT_H
#define SRUKF_OPT_H

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
extern void srukf_opt(const emlrtStack *sp, real_T t_km1, real_T t_k, const
                      real_T x_km1_data[], const int32_T x_km1_size[1], const
                      real_T u_km1_data[], const int32_T u_km1_size[1], real_T
                      S_data[], int32_T S_size[2], const real_T y_k_data[],
                      const int32_T y_k_size[1], const real_T Sv_data[], const
                      int32_T Sv_size[2], const real_T Sn_data[], const int32_T
                      Sn_size[2], real_T alpha, real_T beta, real_T kappa,
                      real_T x_data[], int32_T x_size[1], real_T K_data[],
                      int32_T K_size[2], real_T inov_data[], int32_T inov_size[1],
                      real_T x_kkm1_data[], int32_T x_kkm1_size[1], real_T
                      S_kkm1_data[], int32_T S_kkm1_size[2], real_T P_xy_data[],
                      int32_T P_xy_size[2], emxArray_real_T *S_yy);

#endif

/* End of code generation (srukf_opt.h) */
