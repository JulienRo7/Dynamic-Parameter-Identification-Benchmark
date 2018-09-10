/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "bsxfun.h"

/* Variable Definitions */
static emlrtRTEInfo gb_emlrtRTEI = { 50,/* lineNo */
  15,                                  /* colNo */
  "bsxfun",                            /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/bsxfun.m"/* pName */
};

/* Function Definitions */
void bsxfun(const emlrtStack *sp, const real_T a_data[], const int32_T a_size[2],
            const real_T b_data[], const int32_T b_size[1], real_T c_data[],
            int32_T c_size[2])
{
  int32_T sck;
  int32_T acoef;
  int32_T k;
  int32_T ia;
  int32_T b_acoef;
  int32_T bcoef;
  int32_T b_k;
  if (b_size[0] == 1) {
    sck = a_size[0];
  } else if (a_size[0] == 1) {
    sck = b_size[0];
  } else if (a_size[0] == b_size[0]) {
    sck = a_size[0];
  } else {
    sck = muIntScalarMin_sint32(b_size[0], a_size[0]);
    emlrtErrorWithMessageIdR2018a(sp, &gb_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch",
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  c_size[0] = (int8_T)sck;
  c_size[1] = (int8_T)a_size[1];
  if ((int8_T)sck != 0) {
    acoef = (a_size[1] != 1);
    for (k = 0; k < c_size[1]; k++) {
      ia = acoef * k;
      b_acoef = (a_size[0] != 1);
      bcoef = (b_size[0] != 1);
      for (b_k = 0; b_k < (int8_T)sck; b_k++) {
        c_data[b_k + (int8_T)sck * k] = a_data[b_acoef * b_k + a_size[0] * ia] -
          b_data[bcoef * b_k];
      }
    }
  }
}

/* End of code generation (bsxfun.c) */
