/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error1.c
 *
 * Code generation for function 'error1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "error1.h"
#include "xgetrf.h"
#include "ukf_opt_mexutil.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 27,    /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/lang/error.m"/* pName */
};

static emlrtRSInfo wf_emlrtRSI = { 27, /* lineNo */
  "error",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/lang/error.m"/* pathName */
};

/* Function Definitions */
void h_error(const emlrtStack *sp)
{
  int32_T i8;
  const mxArray *y;
  char_T varargin_1_Value[61];
  static const char_T cv1[61] = { 'U', 'K', 'F', ':', ' ', 'P', 'l', 'e', 'a',
    's', 'e', ' ', 's', 'e', 'l', 'e', 'c', 't', ' ', 'a', ' ', 'c', 'o', 'r',
    'r', 'e', 'c', 't', ' ', 's', 'i', 'g', 'm', 'a', ' ', 'p', 'o', 'i', 'n',
    't', ' ', 'c', 'o', 'm', 'p', 'u', 't', 'a', 't', 'i', 'o', 'n', ' ', 'm',
    'e', 't', 'h', 'o', 'd', ' ', '!' };

  const mxArray *m0;
  const mxArray *b_y;
  char_T u[61];
  const mxArray *m1;
  static const int32_T iv1[2] = { 1, 61 };

  const mxArray *propValues[1];
  const char * propNames[1] = { "Value" };

  const char * propClasses[1] = { "coder.internal.string" };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i8 = 0; i8 < 61; i8++) {
    varargin_1_Value[i8] = cv1[i8];
  }

  y = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance("coder.internal.string"));
  m0 = NULL;
  for (i8 = 0; i8 < 61; i8++) {
    u[i8] = varargin_1_Value[i8];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 61, m1, &u[0]);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m0, b_y);
  propValues[0] = m0;
  emlrtSetAllProperties(sp, &y, 0, 1, propNames, propClasses, propValues);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(sp, y, 0,
    "coder.internal.string"));
  st.site = &wf_emlrtRSI;
  l_error(&st, y, &emlrtMCI);
}

/* End of code generation (error1.c) */
