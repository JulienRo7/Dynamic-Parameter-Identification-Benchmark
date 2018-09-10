/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cholupdate.h
 *
 * Code generation for function 'cholupdate'
 *
 */

#ifndef CHOLUPDATE_H
#define CHOLUPDATE_H

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
extern void b_cholupdate(const emlrtStack *sp, const real_T R_data[], const
  int32_T R_size[2], const real_T x_data[], const int32_T x_size[1], real_T
  R1_data[], int32_T R1_size[2]);
extern void cholupdate(const emlrtStack *sp, const real_T R_data[], const
  int32_T R_size[2], const real_T x_data[], const int32_T x_size[1], real_T
  R1_data[], int32_T R1_size[2]);

#endif

/* End of code generation (cholupdate.h) */
