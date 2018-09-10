/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqrf.c
 *
 * Code generation for function 'xgeqrf'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "xgeqrf.h"
#include "error.h"
#include "srukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = { 16, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 38, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 39, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 62, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 65, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 73, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqrf.m"/* pathName */
};

/* Function Definitions */
void xgeqrf(const emlrtStack *sp, real_T A_data[], int32_T A_size[2], real_T
            tau_data[], int32_T tau_size[1])
{
  int32_T m;
  int32_T n;
  ptrdiff_t m_t;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  int32_T loop_ub;
  int32_T i12;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  m = A_size[0];
  n = A_size[1];
  b_st.site = &kd_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    tau_size[0] = 0;
  } else {
    tau_size[0] = muIntScalarMin_sint32(m, n);
    b_st.site = &md_emlrtRSI;
    m_t = (ptrdiff_t)A_size[0];
    b_st.site = &nd_emlrtRSI;
    info_t = LAPACKE_dgeqrf(102, m_t, (ptrdiff_t)A_size[1], &A_data[0], m_t,
      &tau_data[0]);
    m = (int32_T)info_t;
    b_st.site = &od_emlrtRSI;
    if (m != 0) {
      p = true;
      b_p = false;
      if (m == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (m == -1010) {
          c_st.site = &sd_emlrtRSI;
          c_error(&c_st);
        } else {
          c_st.site = &td_emlrtRSI;
          d_error(&c_st, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      m = A_size[1];
      for (n = 0; n < m; n++) {
        loop_ub = A_size[0];
        for (i12 = 0; i12 < loop_ub; i12++) {
          A_data[i12 + A_size[0] * n] = rtNaN;
        }
      }

      m = tau_size[0];
      for (n = 0; n < m; n++) {
        tau_data[n] = rtNaN;
      }
    }
  }
}

/* End of code generation (xgeqrf.c) */
