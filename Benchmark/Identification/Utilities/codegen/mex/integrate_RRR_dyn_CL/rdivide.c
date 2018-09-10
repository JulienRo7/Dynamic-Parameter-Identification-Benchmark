/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "rdivide.h"
#include "integrate_RRR_dyn_CL_data.h"

/* Function Definitions */
void rdivide(const emlrtStack *sp, const real_T x_data[], const real_T y_data[],
             const int32_T y_size[1], real_T z_data[], int32_T z_size[1])
{
  int8_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  varargin_2[0] = (int8_T)y_size[0];
  varargin_2[1] = 1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(6 + -5 * k == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(sp, &s_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  z_size[0] = 6;
  for (k = 0; k < 6; k++) {
    z_data[k] = x_data[k] / y_data[k];
  }
}

/* End of code generation (rdivide.c) */
