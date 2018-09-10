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
#include "ukf_opt.h"
#include "mrdivide.h"
#include "lusolve.h"
#include "qrsolve.h"

/* Variable Definitions */
static emlrtRSInfo he_emlrtRSI = { 1,  /* lineNo */
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
              [2], const real_T B_data[], const int32_T B_size[2], real_T
              y_data[], int32_T y_size[2])
{
  int32_T b_B_size[2];
  real_T b_A_data[69];
  int32_T tmp_size[2];
  int32_T loop_ub;
  int32_T i10;
  int32_T b_A_size[2];
  int32_T b_loop_ub;
  int32_T i11;
  real_T b_B_data[9];
  real_T tmp_data[1127];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (B_size[1] != A_size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI, "Coder:MATLAB:dimagree",
      "Coder:MATLAB:dimagree", 0);
  }

  if ((A_size[0] == 0) || (A_size[1] == 0) || ((B_size[0] == 0) || (B_size[1] ==
        0))) {
    y_size[0] = (int8_T)A_size[0];
    y_size[1] = (int8_T)B_size[0];
    loop_ub = (int8_T)A_size[0] * (int8_T)B_size[0];
    if (0 <= loop_ub - 1) {
      memset(&y_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }
  } else if (B_size[0] == B_size[1]) {
    st.site = &he_emlrtRSI;
    lusolve(&st, B_data, B_size, A_data, A_size, b_A_data, tmp_size);
    y_size[0] = tmp_size[0];
    y_size[1] = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&y_data[0], &b_A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof
              (real_T)));
    }
  } else {
    b_B_size[0] = B_size[1];
    b_B_size[1] = B_size[0];
    loop_ub = B_size[0];
    for (i10 = 0; i10 < loop_ub; i10++) {
      b_loop_ub = B_size[1];
      for (i11 = 0; i11 < b_loop_ub; i11++) {
        b_B_data[i11 + b_B_size[0] * i10] = B_data[i10 + B_size[0] * i11];
      }
    }

    b_A_size[0] = A_size[1];
    b_A_size[1] = A_size[0];
    loop_ub = A_size[0];
    for (i10 = 0; i10 < loop_ub; i10++) {
      b_loop_ub = A_size[1];
      for (i11 = 0; i11 < b_loop_ub; i11++) {
        b_A_data[i11 + b_A_size[0] * i10] = A_data[i10 + A_size[0] * i11];
      }
    }

    st.site = &he_emlrtRSI;
    qrsolve(&st, b_B_data, b_B_size, b_A_data, b_A_size, tmp_data, tmp_size);
    y_size[0] = tmp_size[1];
    y_size[1] = tmp_size[0];
    loop_ub = tmp_size[0];
    for (i10 = 0; i10 < loop_ub; i10++) {
      b_loop_ub = tmp_size[1];
      for (i11 = 0; i11 < b_loop_ub; i11++) {
        y_data[i11 + y_size[0] * i10] = tmp_data[i10 + tmp_size[0] * i11];
      }
    }
  }
}

/* End of code generation (mrdivide.c) */
