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
#include "integrate_RRR_dyn_CL.h"
#include "abs.h"

/* Function Definitions */
void b_abs(const real_T x_data[], const int32_T x_size[1], real_T y_data[],
           int32_T y_size[1])
{
  int32_T k;
  y_size[0] = (int8_T)x_size[0];
  for (k = 0; k < x_size[0]; k++) {
    y_data[k] = muDoubleScalarAbs(x_data[k]);
  }
}

/* End of code generation (abs.c) */
