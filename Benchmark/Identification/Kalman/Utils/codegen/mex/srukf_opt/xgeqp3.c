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
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "xgeqp3.h"
#include "srukf_opt_emxutil.h"
#include "colon.h"
#include "error.h"
#include "srukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo mf_emlrtRSI = { 14, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 37, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 38, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 45, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 64, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 67, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 76, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pathName */
};

static emlrtRTEInfo x_emlrtRTEI = { 77,/* lineNo */
  9,                                   /* colNo */
  "xgeqp3",                            /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgeqp3.m"/* pName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, real_T tau_data[], int32_T
            tau_size[1], int32_T jpvt_data[], int32_T jpvt_size[2])
{
  int32_T m;
  int32_T n;
  int32_T jpvt_t_size_idx_0;
  int32_T loop_ub;
  int32_T i14;
  ptrdiff_t jpvt_t_data[99];
  ptrdiff_t m_t;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  m = A->size[0];
  n = A->size[1];
  b_st.site = &nf_emlrtRSI;
  b_st.site = &of_emlrtRSI;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    tau_size[0] = 0;
    eml_signed_integer_colon(A->size[1], jpvt_data, jpvt_size);
  } else {
    tau_size[0] = muIntScalarMin_sint32(m, n);
    b_st.site = &pf_emlrtRSI;
    jpvt_t_size_idx_0 = A->size[1];
    loop_ub = A->size[1];
    for (i14 = 0; i14 < loop_ub; i14++) {
      jpvt_t_data[i14] = (ptrdiff_t)0;
    }

    b_st.site = &qf_emlrtRSI;
    m_t = (ptrdiff_t)A->size[0];
    b_st.site = &rf_emlrtRSI;
    info_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A->size[1], &A->data[0], m_t,
      &jpvt_t_data[0], &tau_data[0]);
    m = (int32_T)info_t;
    b_st.site = &sf_emlrtRSI;
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
          g_error(&c_st, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      i14 = A->size[0] * A->size[1];
      emxEnsureCapacity_real_T(&st, A, i14, &x_emlrtRTEI);
      loop_ub = A->size[1];
      for (i14 = 0; i14 < loop_ub; i14++) {
        m = A->size[0];
        for (jpvt_t_size_idx_0 = 0; jpvt_t_size_idx_0 < m; jpvt_t_size_idx_0++)
        {
          A->data[jpvt_t_size_idx_0 + A->size[0] * i14] = rtNaN;
        }
      }

      loop_ub = tau_size[0];
      for (i14 = 0; i14 < loop_ub; i14++) {
        tau_data[i14] = rtNaN;
      }

      eml_signed_integer_colon(n, jpvt_data, jpvt_size);
    } else {
      jpvt_size[0] = 1;
      jpvt_size[1] = jpvt_t_size_idx_0;
      for (i14 = 0; i14 < jpvt_t_size_idx_0; i14++) {
        jpvt_data[i14] = (int32_T)jpvt_t_data[i14];
      }
    }
  }
}

/* End of code generation (xgeqp3.c) */
