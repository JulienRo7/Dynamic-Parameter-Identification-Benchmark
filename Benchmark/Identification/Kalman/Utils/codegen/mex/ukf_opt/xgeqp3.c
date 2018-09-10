/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "xgeqp3.h"
#include "colon.h"
#include "error.h"
#include "ukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo bf_emlrtRSI = { 14, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 37, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 38, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 45, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 64, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 67, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 76, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, real_T A_data[], int32_T A_size[2], real_T
            tau_data[], int32_T tau_size[1], int32_T jpvt_data[], int32_T
            jpvt_size[2])
{
  int32_T A_size_idx_0;
  int32_T A_size_idx_1;
  int32_T m;
  real_T b_A_data[9];
  int32_T n;
  int32_T i18;
  ptrdiff_t jpvt_t_data[3];
  ptrdiff_t m_t;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  A_size_idx_0 = A_size[0];
  A_size_idx_1 = A_size[1];
  m = A_size[0] * A_size[1];
  if (0 <= m - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(m * (int32_T)sizeof(real_T)));
  }

  m = A_size[0];
  n = A_size[1];
  b_st.site = &cf_emlrtRSI;
  b_st.site = &df_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    tau_size[0] = 0;
    eml_signed_integer_colon(A_size[1], jpvt_data, jpvt_size);
  } else {
    tau_size[0] = muIntScalarMin_sint32(m, n);
    b_st.site = &ef_emlrtRSI;
    n = A_size[1];
    m = A_size[1];
    for (i18 = 0; i18 < m; i18++) {
      jpvt_t_data[i18] = (ptrdiff_t)0;
    }

    b_st.site = &ff_emlrtRSI;
    m_t = (ptrdiff_t)A_size[0];
    b_st.site = &gf_emlrtRSI;
    info_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A_size[1], &b_A_data[0], m_t,
      &jpvt_t_data[0], &tau_data[0]);
    m = (int32_T)info_t;
    b_st.site = &hf_emlrtRSI;
    if (m != 0) {
      p = true;
      b_p = false;
      if (m == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (m == -1010) {
          c_st.site = &kb_emlrtRSI;
          c_error(&c_st);
        } else {
          c_st.site = &lb_emlrtRSI;
          j_error(&c_st, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      for (i18 = 0; i18 < A_size_idx_1; i18++) {
        for (m = 0; m < A_size_idx_0; m++) {
          b_A_data[m + A_size_idx_0 * i18] = rtNaN;
        }
      }

      m = tau_size[0];
      for (i18 = 0; i18 < m; i18++) {
        tau_data[i18] = rtNaN;
      }

      eml_signed_integer_colon(A_size[1], jpvt_data, jpvt_size);
    } else {
      jpvt_size[0] = 1;
      jpvt_size[1] = n;
      for (i18 = 0; i18 < n; i18++) {
        jpvt_data[i18] = (int32_T)jpvt_t_data[i18];
      }
    }
  }

  A_size[0] = A_size_idx_0;
  A_size[1] = A_size_idx_1;
  for (i18 = 0; i18 < A_size_idx_1; i18++) {
    for (m = 0; m < A_size_idx_0; m++) {
      A_data[m + A_size[0] * i18] = b_A_data[m + A_size_idx_0 * i18];
    }
  }
}

/* End of code generation (xgeqp3.c) */
