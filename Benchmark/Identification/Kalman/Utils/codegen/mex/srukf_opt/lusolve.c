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
#include "srukf_opt.h"
#include "lusolve.h"
#include "xtrsm.h"
#include "srukf_opt_emxutil.h"
#include "warning.h"
#include "xgetrf.h"
#include "srukf_opt_data.h"

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = { 42, /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 103,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 101,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = { 101,/* lineNo */
  2,                                   /* colNo */
  "lusolve",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 1, /* lineNo */
  19,                                  /* colNo */
  "lusolve",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pName */
};

/* Function Declarations */
static void warn_singular(const emlrtStack *sp);

/* Function Definitions */
static void warn_singular(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!emlrtSetWarningFlag(sp)) {
    st.site = &kc_emlrtRSI;
    warning(&st);
  }
}

void lusolve(const emlrtStack *sp, const emxArray_real_T *A, const real_T
             B_data[], const int32_T B_size[2], real_T X_data[], int32_T X_size
             [2])
{
  emxArray_real_T *b_A;
  int32_T info;
  int32_T jp;
  int32_T ipiv_data[99];
  int32_T ipiv_size[2];
  int32_T xi;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &b_A, 2, &n_emlrtRTEI, true);
  st.site = &ve_emlrtRSI;
  info = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(&st, b_A, info, &m_emlrtRTEI);
  jp = A->size[0] * A->size[1];
  for (info = 0; info < jp; info++) {
    b_A->data[info] = A->data[info];
  }

  b_st.site = &xe_emlrtRSI;
  xgetrf(&b_st, A->size[1], A->size[1], b_A, A->size[1], ipiv_data, ipiv_size,
         &info);
  if (info > 0) {
    b_st.site = &we_emlrtRSI;
    warn_singular(&b_st);
  }

  X_size[0] = B_size[0];
  X_size[1] = B_size[1];
  jp = B_size[0] * B_size[1];
  if (0 <= jp - 1) {
    memcpy(&X_data[0], &B_data[0], (uint32_T)(jp * (int32_T)sizeof(real_T)));
  }

  xtrsm(B_size[0], A->size[1], b_A, A->size[1], X_data, B_size[0]);
  b_xtrsm(B_size[0], A->size[1], b_A, A->size[1], X_data, B_size[0]);
  info = A->size[1] - 2;
  emxFree_real_T(&st, &b_A);
  while (info + 1 > 0) {
    if (ipiv_data[info] != info + 1) {
      jp = ipiv_data[info] - 1;
      for (xi = 0; xi < B_size[0]; xi++) {
        temp = X_data[xi + X_size[0] * info];
        X_data[xi + X_size[0] * info] = X_data[xi + X_size[0] * jp];
        X_data[xi + X_size[0] * jp] = temp;
      }
    }

    info--;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (lusolve.c) */
