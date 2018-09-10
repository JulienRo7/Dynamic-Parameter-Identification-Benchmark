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
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
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

void maxAbsThresh(const real_T a_data[], const int32_T a_size[1], const real_T
                  b_data[], real_T y_data[], int32_T y_size[1])
{
  int32_T loop_ub;
  real_T a;
  real_T b;
  y_size[0] = (int8_T)a_size[0];
  loop_ub = (int8_T)a_size[0];
  if (0 <= loop_ub - 1) {
    memset(&y_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  for (loop_ub = 0; loop_ub < a_size[0]; loop_ub++) {
    a = muDoubleScalarAbs(a_data[loop_ub]);
    b = muDoubleScalarAbs(b_data[loop_ub]);
    if ((a > b) || muDoubleScalarIsNaN(b)) {
      a = muDoubleScalarMax(a, 0.001);
    } else {
      a = muDoubleScalarMax(b, 0.001);
    }

    y_data[loop_ub] = a;
  }
}

/* End of code generation (ode2345.c) */
