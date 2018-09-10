/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qr.h
 *
 * Code generation for function 'qr'
 *
 */

#ifndef QR_H
#define QR_H

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
extern void qr(const emlrtStack *sp, const real_T A_data[], const int32_T
               A_size[2], real_T Q_data[], int32_T Q_size[2], real_T R_data[],
               int32_T R_size[2]);

#endif

/* End of code generation (qr.h) */
