/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * num2str.c
 *
 * Code generation for function 'num2str'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "num2str.h"

/* Variable Definitions */
static emlrtRSInfo vb_emlrtRSI = { 15, /* lineNo */
  "num2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/num2str.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 53,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pName */
};

static emlrtRSInfo gc_emlrtRSI = { 53, /* lineNo */
  "flt2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[23]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[23]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[23]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[23])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 2, pArrays, "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2] = { 1, 23 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

void num2str(const emlrtStack *sp, real_T x, char_T str[23])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv4[2] = { 1, 7 };

  static const char_T rfmt[7] = { '%', '2', '3', '.', '1', '5', 'e' };

  const mxArray *b_y;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y = NULL;
  m1 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(&st, 7, m1, &rfmt[0]);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = emlrtCreateDoubleScalar(x);
  emlrtAssign(&b_y, m1);
  b_st.site = &gc_emlrtRSI;
  emlrt_marshallIn(&b_st, b_sprintf(&b_st, y, b_y, &c_emlrtMCI), "sprintf", str);
}

/* End of code generation (num2str.c) */
