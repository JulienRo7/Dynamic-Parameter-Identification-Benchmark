/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.h
 *
 * Code generation for function 'bsxfun'
 *
 */

#ifndef BSXFUN_H
#define BSXFUN_H

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
extern void bsxfun(const emlrtStack *sp, const real_T a_data[], const int32_T
                   a_size[2], const real_T b_data[], const int32_T b_size[1],
                   real_T c_data[], int32_T c_size[2]);

#endif

/* End of code generation (bsxfun.h) */
