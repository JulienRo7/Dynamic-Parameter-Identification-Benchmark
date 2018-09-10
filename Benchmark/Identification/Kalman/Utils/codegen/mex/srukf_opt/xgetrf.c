/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "xgetrf.h"
#include "error.h"
#include "srukf_opt_mexutil.h"
#include "srukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo pd_emlrtRSI = { 7,  /* lineNo */
  "int",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 8,  /* lineNo */
  "majority",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 31, /* lineNo */
  "infocheck",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 27, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 90, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 82, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 78, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 58, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 57, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 50, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, emxArray_real_T *A,
            int32_T lda, int32_T ipiv_data[], int32_T ipiv_size[2], int32_T
            *info)
{
  int32_T i13;
  int32_T varargin_1;
  const mxArray *y;
  const mxArray *m15;
  static const int32_T iv28[2] = { 1, 15 };

  ptrdiff_t info_t;
  ptrdiff_t ipiv_t_data[99];
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &if_emlrtRSI;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    ipiv_size[0] = 1;
    ipiv_size[1] = 0;
    *info = 0;
  } else {
    b_st.site = &hf_emlrtRSI;
    c_st.site = &pd_emlrtRSI;
    i13 = muIntScalarMin_sint32(m, n);
    varargin_1 = muIntScalarMax_sint32(i13, 1);
    b_st.site = &hf_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    if ((int8_T)varargin_1 != varargin_1) {
      y = NULL;
      m15 = emlrtCreateCharArray(2, iv28);
      emlrtInitCharArrayR2013a(&b_st, 15, m15, &cv0[0]);
      emlrtAssign(&y, m15);
      c_st.site = &hg_emlrtRSI;
      i_error(&c_st, y, &emlrtMCI);
    }

    b_st.site = &gf_emlrtRSI;
    c_st.site = &pd_emlrtRSI;
    b_st.site = &ff_emlrtRSI;
    c_st.site = &pd_emlrtRSI;
    b_st.site = &ef_emlrtRSI;
    c_st.site = &qd_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A->data[0],
      (ptrdiff_t)lda, &ipiv_t_data[0]);
    *info = (int32_T)info_t;
    ipiv_size[0] = 1;
    ipiv_size[1] = (int8_T)varargin_1;
    b_st.site = &df_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    if (*info < 0) {
      if (*info == -1010) {
        c_st.site = &sd_emlrtRSI;
        c_error(&c_st);
      } else {
        c_st.site = &td_emlrtRSI;
        f_error(&c_st, *info);
      }
    }

    for (k = 0; k < (int8_T)varargin_1; k++) {
      ipiv_data[k] = (int32_T)ipiv_t_data[k];
    }
  }
}

/* End of code generation (xgetrf.c) */
