/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qrsolve.c
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "qrsolve.h"
#include "srukf_opt_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "ode45.h"
#include "warning.h"
#include "xgeqp3.h"
#include "srukf_opt_mexutil.h"
#include "srukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 21, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 29, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 33, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 40, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 122,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 121,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 73, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 79, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 80, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 90, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 31, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 59, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 79, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 80, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 93, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 102,/* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRTEInfo o_emlrtRTEI = { 29,/* lineNo */
  2,                                   /* colNo */
  "qrsolve",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 1, /* lineNo */
  24,                                  /* colNo */
  "qrsolve",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pName */
};

/* Function Declarations */
static void LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
                      real_T tau_data[], const int32_T jpvt_data[], real_T
                      B_data[], int32_T B_size[2], int32_T rankA, real_T Y_data[],
                      int32_T Y_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static int32_T rankFromQR(const emlrtStack *sp, const emxArray_real_T *A);

/* Function Definitions */
static void LSQFromQR(const emlrtStack *sp, const emxArray_real_T *A, const
                      real_T tau_data[], const int32_T jpvt_data[], real_T
                      B_data[], int32_T B_size[2], int32_T rankA, real_T Y_data[],
                      int32_T Y_size[2])
{
  int8_T unnamed_idx_0;
  int32_T mn;
  ptrdiff_t nrc_t;
  int32_T i;
  int32_T loop_ub;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  int32_T i7;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  unnamed_idx_0 = (int8_T)A->size[1];
  Y_size[0] = unnamed_idx_0;
  Y_size[1] = (int8_T)B_size[1];
  mn = unnamed_idx_0 * (int8_T)B_size[1];
  if (0 <= mn - 1) {
    memset(&Y_data[0], 0, (uint32_T)(mn * (int32_T)sizeof(real_T)));
  }

  st.site = &vf_emlrtRSI;
  b_st.site = &ag_emlrtRSI;
  mn = muIntScalarMin_sint32(A->size[0], A->size[1]);
  c_st.site = &bg_emlrtRSI;
  if ((!((A->size[0] == 0) || (A->size[1] == 0))) && (!((B_size[0] == 0) ||
        (B_size[1] == 0)))) {
    c_st.site = &cg_emlrtRSI;
    c_st.site = &dg_emlrtRSI;
    nrc_t = (ptrdiff_t)B_size[0];
    c_st.site = &eg_emlrtRSI;
    info_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)B_size[1],
      (ptrdiff_t)mn, &A->data[0], (ptrdiff_t)A->size[0], &tau_data[0], &B_data[0],
      nrc_t);
    mn = (int32_T)info_t;
    c_st.site = &fg_emlrtRSI;
    if (mn != 0) {
      p = true;
      b_p = false;
      if (mn == -7) {
        b_p = true;
      } else if (mn == -9) {
        b_p = true;
      } else {
        if (mn == -10) {
          b_p = true;
        }
      }

      if (!b_p) {
        if (mn == -1010) {
          d_st.site = &sd_emlrtRSI;
          c_error(&d_st);
        } else {
          d_st.site = &td_emlrtRSI;
          h_error(&d_st, mn);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      mn = B_size[1];
      for (i = 0; i < mn; i++) {
        loop_ub = B_size[0];
        for (i7 = 0; i7 < loop_ub; i7++) {
          B_data[i7 + B_size[0] * i] = rtNaN;
        }
      }
    }
  }

  st.site = &wf_emlrtRSI;
  for (mn = 0; mn < B_size[1]; mn++) {
    st.site = &xf_emlrtRSI;
    if ((!(1 > rankA)) && (rankA > 2147483646)) {
      b_st.site = &fb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i < rankA; i++) {
      Y_data[(jpvt_data[i] + unnamed_idx_0 * mn) - 1] = B_data[i + B_size[0] *
        mn];
    }

    for (loop_ub = rankA - 1; loop_ub + 1 > 0; loop_ub--) {
      Y_data[(jpvt_data[loop_ub] + unnamed_idx_0 * mn) - 1] /= A->data[loop_ub +
        A->size[0] * loop_ub];
      st.site = &yf_emlrtRSI;
      for (i = 0; i < loop_ub; i++) {
        Y_data[(jpvt_data[i] + unnamed_idx_0 * mn) - 1] -= Y_data
          [(jpvt_data[loop_ub] + unnamed_idx_0 * mn) - 1] * A->data[i + A->size
          [0] * loop_ub];
      }
    }
  }
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static int32_T rankFromQR(const emlrtStack *sp, const emxArray_real_T *A)
{
  int32_T r;
  real_T tol;
  int32_T minmn;
  int32_T maxmn;
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv12[2] = { 1, 6 };

  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *b_y;
  char_T cv3[14];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = 0;
  tol = 0.0;
  if (A->size[0] < A->size[1]) {
    minmn = A->size[0];
    maxmn = A->size[1];
  } else {
    minmn = A->size[1];
    maxmn = A->size[0];
  }

  if (minmn > 0) {
    tol = (real_T)maxmn * muDoubleScalarAbs(A->data[0]) * 2.2204460492503131E-16;
    while ((r < minmn) && (!(muDoubleScalarAbs(A->data[r + A->size[0] * r]) <=
             tol))) {
      r++;
    }
  }

  if ((r < minmn) && (!emlrtSetWarningFlag(sp))) {
    st.site = &tf_emlrtRSI;
    y = NULL;
    m4 = emlrtCreateCharArray(2, iv12);
    emlrtInitCharArrayR2013a(&st, 6, m4, &rfmt[0]);
    emlrtAssign(&y, m4);
    b_y = NULL;
    m4 = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m4);
    b_st.site = &gg_emlrtRSI;
    c_emlrt_marshallIn(&b_st, b_sprintf(&b_st, y, b_y, &d_emlrtMCI), "sprintf",
                       cv3);
    st.site = &uf_emlrtRSI;
    c_warning(&st, r, cv3);
  }

  return r;
}

void qrsolve(const emlrtStack *sp, const emxArray_real_T *A, const real_T
             B_data[], const int32_T B_size[2], real_T Y_data[], int32_T Y_size
             [2])
{
  emxArray_real_T *b_A;
  int32_T rankR;
  int32_T loop_ub;
  real_T tau_data[3];
  int32_T tau_size[1];
  int32_T jpvt_data[99];
  int32_T jpvt_size[2];
  int32_T b_B_size[2];
  real_T b_B_data[2277];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &b_A, 2, &p_emlrtRTEI, true);
  rankR = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(sp, b_A, rankR, &o_emlrtRTEI);
  loop_ub = A->size[0] * A->size[1];
  for (rankR = 0; rankR < loop_ub; rankR++) {
    b_A->data[rankR] = A->data[rankR];
  }

  st.site = &jf_emlrtRSI;
  xgeqp3(&st, b_A, tau_data, tau_size, jpvt_data, jpvt_size);
  st.site = &kf_emlrtRSI;
  rankR = rankFromQR(&st, b_A);
  b_B_size[0] = B_size[0];
  b_B_size[1] = B_size[1];
  loop_ub = B_size[0] * B_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_B_data[0], &B_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &lf_emlrtRSI;
  LSQFromQR(&st, b_A, tau_data, jpvt_data, b_B_data, b_B_size, rankR, Y_data,
            Y_size);
  emxFree_real_T(sp, &b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (qrsolve.c) */
