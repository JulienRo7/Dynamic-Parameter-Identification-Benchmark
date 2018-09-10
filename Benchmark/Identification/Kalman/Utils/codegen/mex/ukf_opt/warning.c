/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 14,  /* lineNo */
  15,                                  /* colNo */
  "warning",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 14,  /* lineNo */
  25,                                  /* colNo */
  "warning",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtMCInfo d_emlrtMCI = { 14,  /* lineNo */
  9,                                   /* colNo */
  "warning",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtRSInfo xf_emlrtRSI = { 14, /* lineNo */
  "warning",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m16;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m16, 4, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m14;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m14, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp, const char_T varargin_1[23], const char_T
               varargin_2[23])
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv9[2] = { 1, 7 };

  static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *b_y;
  static const int32_T iv10[2] = { 1, 7 };

  static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c_y;
  static const int32_T iv11[2] = { 1, 33 };

  static const char_T msgID[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 'd',
    'e', '4', '5', ':', 'I', 'n', 't', 'e', 'g', 'r', 'a', 't', 'i', 'o', 'n',
    'T', 'o', 'l', 'N', 'o', 't', 'M', 'e', 't' };

  const mxArray *d_y;
  static const int32_T iv12[2] = { 1, 23 };

  const mxArray *e_y;
  static const int32_T iv13[2] = { 1, 23 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtAssertMATLABThread(sp, &emlrtRTEI);
  y = NULL;
  m5 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 7, m5, &u[0]);
  emlrtAssign(&y, m5);
  b_y = NULL;
  m5 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 7, m5, &b_u[0]);
  emlrtAssign(&b_y, m5);
  c_y = NULL;
  m5 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 33, m5, &msgID[0]);
  emlrtAssign(&c_y, m5);
  d_y = NULL;
  m5 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 23, m5, &varargin_1[0]);
  emlrtAssign(&d_y, m5);
  e_y = NULL;
  m5 = emlrtCreateCharArray(2, iv13);
  emlrtInitCharArrayR2013a(sp, 23, m5, &varargin_2[0]);
  emlrtAssign(&e_y, m5);
  st.site = &xf_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &c_emlrtMCI), &d_emlrtMCI);
}

void c_warning(const emlrtStack *sp, int32_T varargin_1, const char_T
               varargin_2[14])
{
  const mxArray *y;
  const mxArray *m7;
  static const int32_T iv15[2] = { 1, 7 };

  static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *b_y;
  static const int32_T iv16[2] = { 1, 7 };

  static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c_y;
  static const int32_T iv17[2] = { 1, 32 };

  static const char_T msgID[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *d_y;
  const mxArray *e_y;
  static const int32_T iv18[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m7 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(sp, 7, m7, &u[0]);
  emlrtAssign(&y, m7);
  b_y = NULL;
  m7 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(sp, 7, m7, &b_u[0]);
  emlrtAssign(&b_y, m7);
  c_y = NULL;
  m7 = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(sp, 32, m7, &msgID[0]);
  emlrtAssign(&c_y, m7);
  d_y = NULL;
  m7 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m7) = varargin_1;
  emlrtAssign(&d_y, m7);
  e_y = NULL;
  m7 = emlrtCreateCharArray(2, iv18);
  emlrtInitCharArrayR2013a(sp, 14, m7, &varargin_2[0]);
  emlrtAssign(&e_y, m7);
  st.site = &xf_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &c_emlrtMCI), &d_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv6[2] = { 1, 7 };

  static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 7 };

  static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c_y;
  static const int32_T iv8[2] = { 1, 27 };

  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtAssertMATLABThread(sp, &emlrtRTEI);
  y = NULL;
  m4 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  b_y = NULL;
  m4 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 7, m4, &b_u[0]);
  emlrtAssign(&b_y, m4);
  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 27, m4, &msgID[0]);
  emlrtAssign(&c_y, m4);
  st.site = &xf_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &c_emlrtMCI), &d_emlrtMCI);
}

/* End of code generation (warning.c) */
