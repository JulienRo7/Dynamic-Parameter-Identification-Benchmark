/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "abs.h"

/* Function Definitions */
void b_abs(const real_T x[6], real_T y[6])
{
  int32_T k;
  for (k = 0; k < 6; k++) {
    y[k] = muDoubleScalarAbs(x[k]);
  }
}

/* End of code generation (abs.c) */
