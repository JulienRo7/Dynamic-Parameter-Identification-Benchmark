/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.h
 *
 * Code generation for function 'xgemv'
 *
 */

#ifndef XGEMV_H
#define XGEMV_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "integrate_RRR_dyn_CL_types.h"

/* Function Declarations */
extern void b_xgemv(real_T alpha1, const real_T A_data[], int32_T ix0, real_T
                    y_data[]);
extern void xgemv(int32_T n, real_T alpha1, const real_T A_data[], int32_T ix0,
                  real_T y_data[]);

#endif

/* End of code generation (xgemv.h) */
