/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lusolve.h
 *
 * Code generation for function 'lusolve'
 *
 */

#ifndef LUSOLVE_H
#define LUSOLVE_H

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
extern void lusolve(const emlrtStack *sp, const real_T A_data[], const int32_T
                    A_size[2], const real_T B_data[], const int32_T B_size[2],
                    real_T X_data[], int32_T X_size[2]);

#endif

/* End of code generation (lusolve.h) */
