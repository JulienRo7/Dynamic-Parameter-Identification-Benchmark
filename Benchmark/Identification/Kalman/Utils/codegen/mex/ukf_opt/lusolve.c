/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lusolve.c
 *
 * Code generation for function 'lusolve'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "lusolve.h"
#include "warning.h"
#include "xgetrf.h"
#include "ukf_opt_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo ie_emlrtRSI = { 42, /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 103,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 101,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 113,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 115,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 120,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

/* Function Definitions */
void lusolve(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
             const real_T B_data[], const int32_T B_size[2], real_T X_data[],
             int32_T X_size[2])
{
  int32_T b_A_size[2];
  int32_T loop_ub;
  real_T b_A_data[9];
  int32_T ipiv_data[3];
  int32_T ipiv_size[2];
  real_T temp;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  int32_T jp;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  int32_T xi;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ie_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  loop_ub = A_size[0] * A_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  b_st.site = &ke_emlrtRSI;
  xgetrf(&b_st, A_size[1], A_size[1], b_A_data, b_A_size, A_size[1], ipiv_data,
         ipiv_size, &loop_ub);
  if (loop_ub > 0) {
    b_st.site = &je_emlrtRSI;
    if (!emlrtSetWarningFlag(&b_st)) {
      c_st.site = &yd_emlrtRSI;
      warning(&c_st);
    }
  }

  b_st.site = &le_emlrtRSI;
  X_size[0] = B_size[0];
  X_size[1] = B_size[1];
  loop_ub = B_size[0] * B_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&X_data[0], &B_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  if ((B_size[0] < 1) || (A_size[1] < 1)) {
  } else {
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'R';
    m_t = (ptrdiff_t)B_size[0];
    n_t = (ptrdiff_t)A_size[1];
    lda_t = (ptrdiff_t)A_size[1];
    ldb_t = (ptrdiff_t)B_size[0];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A_data[0], &lda_t,
          &X_data[0], &ldb_t);
  }

  b_st.site = &me_emlrtRSI;
  if ((B_size[0] < 1) || (A_size[1] < 1)) {
  } else {
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'R';
    m_t = (ptrdiff_t)B_size[0];
    n_t = (ptrdiff_t)A_size[1];
    lda_t = (ptrdiff_t)A_size[1];
    ldb_t = (ptrdiff_t)B_size[0];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A_data[0], &lda_t,
          &X_data[0], &ldb_t);
  }

  for (loop_ub = A_size[1] - 2; loop_ub + 1 > 0; loop_ub--) {
    if (ipiv_data[loop_ub] != loop_ub + 1) {
      jp = ipiv_data[loop_ub] - 1;
      b_st.site = &ne_emlrtRSI;
      for (xi = 0; xi < B_size[0]; xi++) {
        temp = X_data[xi + X_size[0] * loop_ub];
        X_data[xi + X_size[0] * loop_ub] = X_data[xi + X_size[0] * jp];
        X_data[xi + X_size[0] * jp] = temp;
      }
    }
  }
}

/* End of code generation (lusolve.c) */
