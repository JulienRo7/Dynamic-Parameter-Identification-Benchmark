/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgesvd.h
 *
 * Code generation for function 'xgesvd'
 *
 */

#ifndef XGESVD_H
#define XGESVD_H

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
extern void ceval_xgesvd(const emlrtStack *sp, real_T A_data[], int32_T A_size[2],
  real_T U_data[], int32_T U_size[2], real_T S_data[], int32_T S_size[1], real_T
  V_data[], int32_T V_size[2], int32_T *info);

#endif

/* End of code generation (xgesvd.h) */
