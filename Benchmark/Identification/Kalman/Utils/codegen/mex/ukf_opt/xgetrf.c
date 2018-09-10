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
#include "ukf_opt.h"
#include "xgetrf.h"
#include "error.h"
#include "ukf_opt_mexutil.h"
#include "ukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 7,  /* lineNo */
  "int",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 8,  /* lineNo */
  "majority",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 31, /* lineNo */
  "infocheck",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 27, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 90, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 82, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 78, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo se_emlrtRSI = { 58, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 57, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

static emlrtRSInfo ue_emlrtRSI = { 50, /* lineNo */
  "xgetrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgetrf.m"/* pathName */
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, real_T A_data[], int32_T
            A_size[2], int32_T lda, int32_T ipiv_data[], int32_T ipiv_size[2],
            int32_T *info)
{
  int32_T i17;
  int32_T varargin_1;
  const mxArray *y;
  const mxArray *m17;
  static const int32_T iv30[2] = { 1, 15 };

  ptrdiff_t info_t;
  ptrdiff_t ipiv_t_data[3];
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ue_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    ipiv_size[0] = 1;
    ipiv_size[1] = 0;
    *info = 0;
  } else {
    b_st.site = &te_emlrtRSI;
    c_st.site = &hb_emlrtRSI;
    i17 = muIntScalarMin_sint32(m, n);
    varargin_1 = muIntScalarMax_sint32(i17, 1);
    b_st.site = &te_emlrtRSI;
    c_st.site = &rc_emlrtRSI;
    if ((int8_T)varargin_1 != varargin_1) {
      y = NULL;
      m17 = emlrtCreateCharArray(2, iv30);
      emlrtInitCharArrayR2013a(&b_st, 15, m17, &cv0[0]);
      emlrtAssign(&y, m17);
      c_st.site = &vf_emlrtRSI;
      l_error(&c_st, y, &b_emlrtMCI);
    }

    b_st.site = &se_emlrtRSI;
    c_st.site = &hb_emlrtRSI;
    b_st.site = &re_emlrtRSI;
    c_st.site = &hb_emlrtRSI;
    b_st.site = &qe_emlrtRSI;
    c_st.site = &ib_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A_data[0],
      (ptrdiff_t)lda, &ipiv_t_data[0]);
    *info = (int32_T)info_t;
    ipiv_size[0] = 1;
    ipiv_size[1] = (int8_T)varargin_1;
    b_st.site = &pe_emlrtRSI;
    c_st.site = &jb_emlrtRSI;
    if (*info < 0) {
      if (*info == -1010) {
        c_st.site = &kb_emlrtRSI;
        c_error(&c_st);
      } else {
        c_st.site = &lb_emlrtRSI;
        i_error(&c_st, *info);
      }
    }

    for (k = 0; k < (int8_T)varargin_1; k++) {
      ipiv_data[k] = (int32_T)ipiv_t_data[k];
    }
  }
}

/* End of code generation (xgetrf.c) */
