/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsm.h
 *
 * Code generation for function 'xtrsm'
 *
 */

#ifndef XTRSM_H
#define XTRSM_H

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
extern void b_xtrsm(int32_T m, int32_T n, const emxArray_real_T *A, int32_T lda,
                    real_T B_data[], int32_T ldb);
extern void xtrsm(int32_T m, int32_T n, const emxArray_real_T *A, int32_T lda,
                  real_T B_data[], int32_T ldb);

#endif

/* End of code generation (xtrsm.h) */
