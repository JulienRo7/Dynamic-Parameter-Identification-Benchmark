/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide.c
 *
 * Code generation for function 'mrdivide'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "mrdivide.h"
#include "srukf_opt_emxutil.h"
#include "lusolve.h"
#include "qrsolve.h"

/* Variable Definitions */
static emlrtRSInfo ue_emlrtRSI = { 1,  /* lineNo */
  "mrdivide",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mrdivide.p"/* pathName */
};

static emlrtRTEInfo l_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "mrdivide",                          /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mrdivide.p"/* pName */
};

/* Function Definitions */
void mrdivide(const emlrtStack *sp, const real_T A_data[], const int32_T A_size
              [2], const emxArray_real_T *B, real_T y_data[], int32_T y_size[2])
{
  emxArray_real_T *b_B;
  int8_T unnamed_idx_1;
  int32_T i5;
  int32_T loop_ub;
  int32_T b_A_size[2];
  int32_T b_loop_ub;
  int32_T i6;
  real_T b_A_data[2277];
  real_T tmp_data[2277];
  int32_T tmp_size[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (B->size[1] != A_size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI, "Coder:MATLAB:dimagree",
      "Coder:MATLAB:dimagree", 0);
  }

  emxInit_real_T1(sp, &b_B, 2, &l_emlrtRTEI, true);
  if ((A_size[0] == 0) || (A_size[1] == 0) || ((B->size[0] == 0) || (B->size[1] ==
        0))) {
    unnamed_idx_1 = (int8_T)B->size[0];
    y_size[0] = (int8_T)A_size[0];
    y_size[1] = unnamed_idx_1;
    loop_ub = (int8_T)A_size[0] * unnamed_idx_1;
    if (0 <= loop_ub - 1) {
      memset(&y_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }
  } else if (B->size[0] == B->size[1]) {
    st.site = &ue_emlrtRSI;
    lusolve(&st, B, A_data, A_size, y_data, y_size);
  } else {
    i5 = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[1];
    b_B->size[1] = B->size[0];
    emxEnsureCapacity_real_T(sp, b_B, i5, &l_emlrtRTEI);
    loop_ub = B->size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_loop_ub = B->size[1];
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        b_B->data[i6 + b_B->size[0] * i5] = B->data[i5 + B->size[0] * i6];
      }
    }

    b_A_size[0] = A_size[1];
    b_A_size[1] = A_size[0];
    loop_ub = A_size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_loop_ub = A_size[1];
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        b_A_data[i6 + b_A_size[0] * i5] = A_data[i5 + A_size[0] * i6];
      }
    }

    st.site = &ue_emlrtRSI;
    qrsolve(&st, b_B, b_A_data, b_A_size, tmp_data, tmp_size);
    y_size[0] = tmp_size[1];
    y_size[1] = tmp_size[0];
    loop_ub = tmp_size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_loop_ub = tmp_size[1];
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        y_data[i6 + y_size[0] * i5] = tmp_data[i5 + tmp_size[0] * i6];
      }
    }
  }

  emxFree_real_T(sp, &b_B);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mrdivide.c) */
