/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "norm.h"

/* Function Definitions */
real_T b_norm(const real_T x_data[])
{
  real_T y;
  int32_T k;
  real_T absx;
  y = 0.0;
  for (k = 0; k < 6; k++) {
    absx = muDoubleScalarAbs(x_data[k]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }

  return y;
}

real_T norm(const real_T x[6])
{
  real_T y;
  int32_T k;
  real_T absx;
  y = 0.0;
  for (k = 0; k < 6; k++) {
    absx = muDoubleScalarAbs(x[k]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }

  return y;
}

/* End of code generation (norm.c) */
