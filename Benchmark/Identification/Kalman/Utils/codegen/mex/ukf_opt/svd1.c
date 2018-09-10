/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd1.c
 *
 * Code generation for function 'svd1'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "svd1.h"
#include "error.h"
#include "xgesvd.h"
#include "ukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo vb_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 75, /* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 83, /* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 105,/* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 205,/* lineNo */
  "xgesdd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 175,/* lineNo */
  "xgesdd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 64, /* lineNo */
  "xgesdd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 57, /* lineNo */
  "xgesdd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 54, /* lineNo */
  "xgesdd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 28, /* lineNo */
  "xgesvd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

/* Function Definitions */
void b_svd(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
           real_T U_data[], int32_T U_size[2], real_T s_data[], int32_T s_size[1],
           real_T V_data[], int32_T V_size[2])
{
  int32_T loop_ub;
  real_T b_A_data[2401];
  int32_T info;
  int32_T b_A_size[2];
  int32_T i4;
  int32_T b_loop_ub;
  int32_T i5;
  real_T Vt_data[2401];
  ptrdiff_t info_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &wb_emlrtRSI;
  loop_ub = A_size[0] * A_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  U_size[0] = A_size[0];
  U_size[1] = A_size[0];
  s_size[0] = muIntScalarMin_sint32(A_size[1], A_size[0]);
  c_st.site = &ec_emlrtRSI;
  if (!((A_size[0] == 0) || (A_size[1] == 0))) {
    c_st.site = &dc_emlrtRSI;
    c_st.site = &cc_emlrtRSI;
    c_st.site = &bc_emlrtRSI;
    info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)A_size[0], (ptrdiff_t)A_size[1],
      &b_A_data[0], (ptrdiff_t)A_size[0], &s_data[0], &U_data[0], (ptrdiff_t)
      A_size[0], &Vt_data[0], (ptrdiff_t)A_size[1]);
    info = (int32_T)info_t;
    c_st.site = &ac_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        d_st.site = &kb_emlrtRSI;
        c_error(&d_st);
      } else {
        d_st.site = &lb_emlrtRSI;
        e_error(&d_st, info);
      }
    }
  } else {
    info = 0;
  }

  if (info > 0) {
    b_st.site = &xb_emlrtRSI;
    b_A_size[0] = A_size[0];
    b_A_size[1] = A_size[1];
    loop_ub = A_size[0] * A_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof
              (real_T)));
    }

    c_st.site = &fc_emlrtRSI;
    ceval_xgesvd(&c_st, b_A_data, b_A_size, U_data, U_size, s_data, s_size,
                 V_data, V_size, &info);
  } else {
    V_size[0] = A_size[1];
    V_size[1] = A_size[1];
    loop_ub = A_size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_loop_ub = A_size[1];
      for (i5 = 0; i5 < b_loop_ub; i5++) {
        V_data[i5 + V_size[0] * i4] = Vt_data[i4 + A_size[1] * i5];
      }
    }
  }

  if (info > 0) {
    b_st.site = &yb_emlrtRSI;
    g_error(&b_st);
  }
}

/* End of code generation (svd1.c) */
