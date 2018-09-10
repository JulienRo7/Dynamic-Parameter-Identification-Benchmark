/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qrsolve.h
 *
 * Code generation for function 'qrsolve'
 *
 */

#ifndef QRSOLVE_H
#define QRSOLVE_H

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
extern void qrsolve(const emlrtStack *sp, const emxArray_real_T *A, const real_T
                    B_data[], const int32_T B_size[2], real_T Y_data[], int32_T
                    Y_size[2]);

#endif

/* End of code generation (qrsolve.h) */
