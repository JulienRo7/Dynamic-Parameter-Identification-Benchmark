/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.h
 *
 * Code generation for function 'svd'
 *
 */

#ifndef SVD_H
#define SVD_H

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
extern void svd(const emlrtStack *sp, const real_T A_data[], const int32_T
                A_size[2], real_T U_data[], int32_T U_size[2], real_T S_data[],
                int32_T S_size[2], real_T V_data[], int32_T V_size[2]);

#endif

/* End of code generation (svd.h) */
