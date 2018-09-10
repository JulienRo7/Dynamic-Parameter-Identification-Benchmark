/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xpotrf.c
 *
 * Code generation for function 'xpotrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "xpotrf.h"
#include "error.h"
#include "ukf_opt_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 77, /* lineNo */
  "xpotrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 73, /* lineNo */
  "xpotrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 37, /* lineNo */
  "xpotrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 36, /* lineNo */
  "xpotrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 13, /* lineNo */
  "xpotrf",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xpotrf.m"/* pathName */
};

/* Function Definitions */
int32_T xpotrf(const emlrtStack *sp, int32_T n, real_T A_data[], int32_T lda)
{
  int32_T info;
  ptrdiff_t info_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &gb_emlrtRSI;
  b_st.site = &fb_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)n, &A_data[0], (ptrdiff_t)
    lda);
  info = (int32_T)info_t;
  b_st.site = &db_emlrtRSI;
  if (info < 0) {
    if (info == -1010) {
      c_st.site = &kb_emlrtRSI;
      c_error(&c_st);
    } else {
      c_st.site = &lb_emlrtRSI;
      d_error(&c_st, info);
    }
  }

  return info;
}

/* End of code generation (xpotrf.c) */
