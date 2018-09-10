/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "sqrt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 12,  /* lineNo */
  "sqrt",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, real_T *x)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (*x < 0.0) {
    st.site = &x_emlrtRSI;
    b_error(&st);
  }

  *x = muDoubleScalarSqrt(*x);
}

void c_sqrt(const emlrtStack *sp, real_T x_data[], int32_T x_size[2])
{
  boolean_T p;
  int32_T nx;
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  p = false;
  nx = x_size[0] * x_size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x_data[k] < 0.0)) {
      p = true;
    } else {
      p = false;
    }
  }

  if (p) {
    st.site = &x_emlrtRSI;
    b_error(&st);
  }

  nx = x_size[0] * x_size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] = muDoubleScalarSqrt(x_data[k]);
  }
}

/* End of code generation (sqrt.c) */
