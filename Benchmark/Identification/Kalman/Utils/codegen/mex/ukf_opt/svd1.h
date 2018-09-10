/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd1.h
 *
 * Code generation for function 'svd1'
 *
 */

#ifndef SVD1_H
#define SVD1_H

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
extern void b_svd(const emlrtStack *sp, const real_T A_data[], const int32_T
                  A_size[2], real_T U_data[], int32_T U_size[2], real_T s_data[],
                  int32_T s_size[1], real_T V_data[], int32_T V_size[2]);

#endif

/* End of code generation (svd1.h) */
