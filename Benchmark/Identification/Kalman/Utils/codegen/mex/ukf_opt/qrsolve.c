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
#include "ukf_opt.h"
#include "qrsolve.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "ode45.h"
#include "warning.h"
#include "xgeqp3.h"
#include "ukf_opt_mexutil.h"
#include "ukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo xe_emlrtRSI = { 29, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 33, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 40, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 122,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 121,/* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 73, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 79, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 80, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 90, /* lineNo */
  "qrsolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/qrsolve.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 31, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 59, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 79, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 80, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 93, /* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 102,/* lineNo */
  "xunormqr",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xunormqr.m"/* pathName */
};

/* Function Declarations */
static void LSQFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
                      A_size[2], const real_T tau_data[], const int32_T
                      jpvt_data[], real_T B_data[], int32_T B_size[2], int32_T
                      rankA, real_T Y_data[], int32_T Y_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static int32_T rankFromQR(const emlrtStack *sp, const real_T A_data[], const
  int32_T A_size[2]);

/* Function Definitions */
static void LSQFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
                      A_size[2], const real_T tau_data[], const int32_T
                      jpvt_data[], real_T B_data[], int32_T B_size[2], int32_T
                      rankA, real_T Y_data[], int32_T Y_size[2])
{
  int32_T info;
  ptrdiff_t nrc_t;
  int32_T i;
  int32_T loop_ub;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  int32_T i12;
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
  Y_size[0] = (int8_T)A_size[1];
  Y_size[1] = (int8_T)B_size[1];
  info = (int8_T)A_size[1] * (int8_T)B_size[1];
  if (0 <= info - 1) {
    memset(&Y_data[0], 0, (uint32_T)(info * (int32_T)sizeof(real_T)));
  }

  st.site = &kf_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  c_st.site = &pf_emlrtRSI;
  if ((!((A_size[0] == 0) || (A_size[1] == 0))) && (!((B_size[0] == 0) ||
        (B_size[1] == 0)))) {
    c_st.site = &qf_emlrtRSI;
    c_st.site = &rf_emlrtRSI;
    nrc_t = (ptrdiff_t)B_size[0];
    c_st.site = &sf_emlrtRSI;
    info_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)B_size[1],
      (ptrdiff_t)muIntScalarMin_sint32(A_size[0], A_size[1]), &A_data[0],
      (ptrdiff_t)A_size[0], &tau_data[0], &B_data[0], nrc_t);
    info = (int32_T)info_t;
    c_st.site = &tf_emlrtRSI;
    if (info != 0) {
      p = true;
      b_p = false;
      if (info == -7) {
        b_p = true;
      } else if (info == -9) {
        b_p = true;
      } else {
        if (info == -10) {
          b_p = true;
        }
      }

      if (!b_p) {
        if (info == -1010) {
          d_st.site = &kb_emlrtRSI;
          c_error(&d_st);
        } else {
          d_st.site = &lb_emlrtRSI;
          k_error(&d_st, info);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      info = B_size[1];
      for (i = 0; i < info; i++) {
        loop_ub = B_size[0];
        for (i12 = 0; i12 < loop_ub; i12++) {
          B_data[i12 + B_size[0] * i] = rtNaN;
        }
      }
    }
  }

  st.site = &lf_emlrtRSI;
  for (info = 0; info < B_size[1]; info++) {
    st.site = &mf_emlrtRSI;
    if ((!(1 > rankA)) && (rankA > 2147483646)) {
      b_st.site = &nb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (i = 0; i < rankA; i++) {
      Y_data[(jpvt_data[i] + Y_size[0] * info) - 1] = B_data[i + B_size[0] *
        info];
    }

    for (loop_ub = rankA - 1; loop_ub + 1 > 0; loop_ub--) {
      Y_data[(jpvt_data[loop_ub] + Y_size[0] * info) - 1] /= A_data[loop_ub +
        A_size[0] * loop_ub];
      st.site = &nf_emlrtRSI;
      for (i = 0; i < loop_ub; i++) {
        Y_data[(jpvt_data[i] + Y_size[0] * info) - 1] -= Y_data
          [(jpvt_data[loop_ub] + Y_size[0] * info) - 1] * A_data[i + A_size[0] *
          loop_ub];
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
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static int32_T rankFromQR(const emlrtStack *sp, const real_T A_data[], const
  int32_T A_size[2])
{
  int32_T r;
  real_T tol;
  int32_T minmn;
  int32_T maxmn;
  const mxArray *y;
  const mxArray *m6;
  static const int32_T iv14[2] = { 1, 6 };

  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *b_y;
  char_T cv4[14];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = 0;
  tol = 0.0;
  if (A_size[0] < A_size[1]) {
    minmn = A_size[0];
    maxmn = A_size[1];
  } else {
    minmn = A_size[1];
    maxmn = A_size[0];
  }

  if (minmn > 0) {
    tol = (real_T)maxmn * muDoubleScalarAbs(A_data[0]) * 2.2204460492503131E-16;
    while ((r < minmn) && (!(muDoubleScalarAbs(A_data[r + A_size[0] * r]) <= tol)))
    {
      r++;
    }
  }

  if ((r < minmn) && (!emlrtSetWarningFlag(sp))) {
    st.site = &if_emlrtRSI;
    y = NULL;
    m6 = emlrtCreateCharArray(2, iv14);
    emlrtInitCharArrayR2013a(&st, 6, m6, &rfmt[0]);
    emlrtAssign(&y, m6);
    b_y = NULL;
    m6 = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m6);
    b_st.site = &uf_emlrtRSI;
    c_emlrt_marshallIn(&b_st, b_sprintf(&b_st, y, b_y, &e_emlrtMCI), "sprintf",
                       cv4);
    st.site = &jf_emlrtRSI;
    c_warning(&st, r, cv4);
  }

  return r;
}

void qrsolve(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
             const real_T B_data[], const int32_T B_size[2], real_T Y_data[],
             int32_T Y_size[2])
{
  int32_T b_A_size[2];
  int32_T loop_ub;
  real_T b_A_data[2401];
  real_T tau_data[3];
  int32_T tau_size[1];
  int32_T jpvt_data[3];
  int32_T jpvt_size[2];
  int32_T rankR;
  int32_T b_B_size[2];
  real_T b_B_data[69];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  loop_ub = A_size[0] * A_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &xe_emlrtRSI;
  xgeqp3(&st, b_A_data, b_A_size, tau_data, tau_size, jpvt_data, jpvt_size);
  st.site = &ye_emlrtRSI;
  rankR = rankFromQR(&st, b_A_data, b_A_size);
  b_B_size[0] = B_size[0];
  b_B_size[1] = B_size[1];
  loop_ub = B_size[0] * B_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_B_data[0], &B_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &af_emlrtRSI;
  LSQFromQR(&st, b_A_data, b_A_size, tau_data, jpvt_data, b_B_data, b_B_size,
            rankR, Y_data, Y_size);
}

/* End of code generation (qrsolve.c) */
