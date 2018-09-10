/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide.h
 *
 * Code generation for function 'mrdivide'
 *
 */

#ifndef MRDIVIDE_H
#define MRDIVIDE_H

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
extern void mrdivide(const emlrtStack *sp, const real_T A_data[], const int32_T
                     A_size[2], const emxArray_real_T *B, real_T y_data[],
                     int32_T y_size[2]);

#endif

/* End of code generation (mrdivide.h) */
