/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "svd.h"
#include "anyNonFinite.h"
#include "svd1.h"

/* Variable Definitions */
static emlrtRSInfo qb_emlrtRSI = { 25, /* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 33, /* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
         real_T U_data[], int32_T U_size[2], real_T S_data[], int32_T S_size[2],
         real_T V_data[], int32_T V_size[2])
{
  boolean_T allFiniteA;
  int32_T k;
  real_T s_data[49];
  int32_T s_size[1];
  int32_T tmp_size[2];
  int8_T iv0[2];
  int32_T loop_ub;
  real_T tmp_data[2401];
  real_T U1_data[2401];
  int32_T U1_size[2];
  real_T V1_data[2401];
  int32_T V1_size[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  allFiniteA = !anyNonFinite(A_data, A_size);
  if (allFiniteA) {
    st.site = &qb_emlrtRSI;
    b_svd(&st, A_data, A_size, U_data, U_size, s_data, s_size, V_data, V_size);
  } else {
    for (k = 0; k < 2; k++) {
      iv0[k] = (int8_T)A_size[k];
    }

    tmp_size[0] = iv0[0];
    tmp_size[1] = iv0[1];
    loop_ub = iv0[0] * iv0[1];
    if (0 <= loop_ub - 1) {
      memset(&tmp_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    st.site = &rb_emlrtRSI;
    b_svd(&st, tmp_data, tmp_size, U1_data, U1_size, s_data, s_size, V1_data,
          V1_size);
    U_size[0] = U1_size[0];
    U_size[1] = U1_size[1];
    loop_ub = U1_size[0] * U1_size[1];
    for (k = 0; k < loop_ub; k++) {
      U_data[k] = rtNaN;
    }

    loop_ub = s_size[0];
    for (k = 0; k < loop_ub; k++) {
      s_data[k] = rtNaN;
    }

    V_size[0] = V1_size[0];
    V_size[1] = V1_size[1];
    loop_ub = V1_size[0] * V1_size[1];
    for (k = 0; k < loop_ub; k++) {
      V_data[k] = rtNaN;
    }
  }

  S_size[0] = U_size[1];
  S_size[1] = V_size[1];
  loop_ub = U_size[1] * V_size[1];
  if (0 <= loop_ub - 1) {
    memset(&S_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  for (k = 0; k < s_size[0]; k++) {
    S_data[k + S_size[0] * k] = s_data[k];
  }
}

/* End of code generation (svd.c) */
