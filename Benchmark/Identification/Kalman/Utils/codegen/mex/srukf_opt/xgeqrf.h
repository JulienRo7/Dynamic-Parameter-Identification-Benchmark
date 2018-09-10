/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqrf.h
 *
 * Code generation for function 'xgeqrf'
 *
 */

#ifndef XGEQRF_H
#define XGEQRF_H

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
extern void xgeqrf(const emlrtStack *sp, real_T A_data[], int32_T A_size[2],
                   real_T tau_data[], int32_T tau_size[1]);

#endif

/* End of code generation (xgeqrf.h) */
