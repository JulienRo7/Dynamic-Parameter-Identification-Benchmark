/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qr.c
 *
 * Code generation for function 'qr'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "qr.h"
#include "error.h"
#include "xgeqrf.h"
#include "srukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo tc_emlrtRSI = { 20, /* lineNo */
  "qr",                                /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/qr.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 36, /* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 158,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 165,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 166,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 169,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 173,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 178,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 179,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 182,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 186,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 187,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 191,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 193,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 194,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 38, /* lineNo */
  "xorgqr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xorgqr.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 46, /* lineNo */
  "xorgqr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xorgqr.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 51, /* lineNo */
  "xorgqr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xorgqr.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 59, /* lineNo */
  "xorgqr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xorgqr.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 207,/* lineNo */
  "eml_qr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/private/eml_qr.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 14, /* lineNo */
  "xorgqr",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xorgqr.m"/* pathName */
};

/* Function Definitions */
void qr(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
        real_T Q_data[], int32_T Q_size[2], real_T R_data[], int32_T R_size[2])
{
  int32_T b_A_size[2];
  int32_T n;
  real_T b_A_data[2277];
  real_T tau_data[23];
  int32_T tau_size[1];
  int32_T m;
  int32_T j;
  int32_T A_size_idx_0;
  int32_T i;
  real_T c_A_data[2277];
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_st.site = &uc_emlrtRSI;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  n = A_size[0] * A_size[1];
  if (0 <= n - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(n * (int32_T)sizeof(real_T)));
  }

  c_st.site = &vc_emlrtRSI;
  xgeqrf(&c_st, b_A_data, b_A_size, tau_data, tau_size);
  m = b_A_size[0];
  n = b_A_size[1];
  if (b_A_size[0] > b_A_size[1]) {
    R_size[0] = (int8_T)b_A_size[1];
    R_size[1] = (int8_T)b_A_size[1];
    c_st.site = &wc_emlrtRSI;
    for (j = 0; j < n; j++) {
      c_st.site = &xc_emlrtRSI;
      for (i = 0; i < j + 1; i++) {
        R_data[i + R_size[0] * j] = b_A_data[i + b_A_size[0] * j];
      }

      c_st.site = &yc_emlrtRSI;
      for (i = j + 1; i < n; i++) {
        R_data[i + R_size[0] * j] = 0.0;
      }
    }

    c_st.site = &ad_emlrtRSI;
    A_size_idx_0 = b_A_size[0];
    n = b_A_size[0] * b_A_size[1];
    if (0 <= n - 1) {
      memcpy(&c_A_data[0], &b_A_data[0], (uint32_T)(n * (int32_T)sizeof(real_T)));
    }

    d_st.site = &ae_emlrtRSI;
    e_st.site = &be_emlrtRSI;
    if (!((b_A_size[0] == 0) || (b_A_size[1] == 0))) {
      f_st.site = &vd_emlrtRSI;
      f_st.site = &wd_emlrtRSI;
      f_st.site = &xd_emlrtRSI;
      info_t = LAPACKE_dorgqr(102, (ptrdiff_t)b_A_size[0], (ptrdiff_t)b_A_size[1],
        (ptrdiff_t)b_A_size[1], &c_A_data[0], (ptrdiff_t)b_A_size[0], &tau_data
        [0]);
      n = (int32_T)info_t;
      f_st.site = &yd_emlrtRSI;
      if (n != 0) {
        p = true;
        b_p = false;
        if (n == -7) {
          b_p = true;
        } else {
          if (n == -5) {
            b_p = true;
          }
        }

        if (!b_p) {
          if (n == -1010) {
            g_st.site = &sd_emlrtRSI;
            c_error(&g_st);
          } else {
            g_st.site = &td_emlrtRSI;
            e_error(&g_st, n);
          }
        }
      } else {
        p = false;
      }

      if (p) {
        n = b_A_size[1];
        for (j = 0; j < n; j++) {
          for (i = 0; i < A_size_idx_0; i++) {
            c_A_data[i + A_size_idx_0 * j] = rtNaN;
          }
        }
      }
    }

    Q_size[0] = b_A_size[0];
    Q_size[1] = b_A_size[1];
    n = b_A_size[0] * b_A_size[1];
    if (0 <= n - 1) {
      memcpy(&Q_data[0], &c_A_data[0], (uint32_T)(n * (int32_T)sizeof(real_T)));
    }
  } else {
    R_size[0] = b_A_size[0];
    R_size[1] = b_A_size[1];
    c_st.site = &bd_emlrtRSI;
    for (j = 0; j < m; j++) {
      c_st.site = &cd_emlrtRSI;
      for (i = 0; i < j + 1; i++) {
        R_data[i + R_size[0] * j] = b_A_data[i + b_A_size[0] * j];
      }

      c_st.site = &dd_emlrtRSI;
      for (i = j + 1; i < m; i++) {
        R_data[i + R_size[0] * j] = 0.0;
      }
    }

    c_st.site = &ed_emlrtRSI;
    for (j = b_A_size[0]; j < n; j++) {
      c_st.site = &fd_emlrtRSI;
      for (i = 0; i < m; i++) {
        R_data[i + R_size[0] * j] = b_A_data[i + b_A_size[0] * j];
      }
    }

    c_st.site = &gd_emlrtRSI;
    A_size_idx_0 = b_A_size[0];
    n = b_A_size[0] * b_A_size[1];
    if (0 <= n - 1) {
      memcpy(&c_A_data[0], &b_A_data[0], (uint32_T)(n * (int32_T)sizeof(real_T)));
    }

    d_st.site = &ae_emlrtRSI;
    e_st.site = &be_emlrtRSI;
    if (!((b_A_size[0] == 0) || (b_A_size[1] == 0))) {
      f_st.site = &vd_emlrtRSI;
      f_st.site = &wd_emlrtRSI;
      f_st.site = &xd_emlrtRSI;
      info_t = LAPACKE_dorgqr(102, (ptrdiff_t)b_A_size[0], (ptrdiff_t)b_A_size[0],
        (ptrdiff_t)b_A_size[0], &c_A_data[0], (ptrdiff_t)b_A_size[0], &tau_data
        [0]);
      n = (int32_T)info_t;
      f_st.site = &yd_emlrtRSI;
      if (n != 0) {
        p = true;
        b_p = false;
        if (n == -7) {
          b_p = true;
        } else {
          if (n == -5) {
            b_p = true;
          }
        }

        if (!b_p) {
          if (n == -1010) {
            g_st.site = &sd_emlrtRSI;
            c_error(&g_st);
          } else {
            g_st.site = &td_emlrtRSI;
            e_error(&g_st, n);
          }
        }
      } else {
        p = false;
      }

      if (p) {
        n = b_A_size[1];
        for (j = 0; j < n; j++) {
          for (i = 0; i < A_size_idx_0; i++) {
            c_A_data[i + A_size_idx_0 * j] = rtNaN;
          }
        }
      }
    }

    Q_size[0] = (int8_T)b_A_size[0];
    Q_size[1] = (int8_T)b_A_size[0];
    c_st.site = &hd_emlrtRSI;
    for (j = 0; j < m; j++) {
      c_st.site = &id_emlrtRSI;
      for (i = 0; i < m; i++) {
        Q_data[i + Q_size[0] * j] = c_A_data[i + A_size_idx_0 * j];
      }
    }
  }
}

/* End of code generation (qr.c) */
