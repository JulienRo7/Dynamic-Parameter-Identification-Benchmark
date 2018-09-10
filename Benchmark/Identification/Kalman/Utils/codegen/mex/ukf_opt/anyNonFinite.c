/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * anyNonFinite.c
 *
 * Code generation for function 'anyNonFinite'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "anyNonFinite.h"

/* Function Definitions */
boolean_T anyNonFinite(const real_T x_data[], const int32_T x_size[2])
{
  boolean_T p;
  int32_T nx;
  int32_T k;
  nx = x_size[0] * x_size[1];
  p = true;
  for (k = 0; k < nx; k++) {
    if (p && ((!muDoubleScalarIsInf(x_data[k])) && (!muDoubleScalarIsNaN
          (x_data[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/* End of code generation (anyNonFinite.c) */
