/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ode2345.c
 *
 * Code generation for function 'ode2345'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "ode2345.h"

/* Function Definitions */
boolean_T ismonotonic(const real_T x[2])
{
  boolean_T p;
  p = true;
  if ((!(x[1] > x[0])) && (!(x[0] > x[1]))) {
    p = false;
  }

  return p;
}

void maxAbsThresh(const real_T a[6], const real_T b[6], real_T y[6])
{
  int32_T k;
  real_T b_a;
  real_T b_b;
  for (k = 0; k < 6; k++) {
    b_a = muDoubleScalarAbs(a[k]);
    b_b = muDoubleScalarAbs(b[k]);
    if ((b_a > b_b) || muDoubleScalarIsNaN(b_b)) {
      b_a = muDoubleScalarMax(b_a, 0.01);
    } else {
      b_a = muDoubleScalarMax(b_b, 0.01);
    }

    y[k] = b_a;
  }
}

/* End of code generation (ode2345.c) */
