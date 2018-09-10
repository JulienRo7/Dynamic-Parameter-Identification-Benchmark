/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgesvd.c
 *
 * Code generation for function 'xgesvd'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "xgesvd.h"
#include "infocheck.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 193,/* lineNo */
  "xgesvd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

/* Function Definitions */
void ceval_xgesvd(const emlrtStack *sp, real_T A_data[], int32_T A_size[2],
                  real_T U_data[], int32_T U_size[2], real_T S_data[], int32_T
                  S_size[1], real_T V_data[], int32_T V_size[2], int32_T *info)
{
  int32_T minnm;
  int32_T i6;
  int32_T loop_ub;
  int32_T i7;
  real_T Vt_data[2401];
  ptrdiff_t info_t;
  real_T superb_data[48];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  minnm = muIntScalarMin_sint32(A_size[1], A_size[0]);
  U_size[0] = A_size[0];
  U_size[1] = A_size[0];
  S_size[0] = minnm;
  if (!((A_size[0] == 0) || (A_size[1] == 0))) {
    info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)A_size[0], (ptrdiff_t)
      A_size[1], &A_data[0], (ptrdiff_t)A_size[0], &S_data[0], &U_data[0],
      (ptrdiff_t)A_size[0], &Vt_data[0], (ptrdiff_t)A_size[1], &superb_data[0]);
    *info = (int32_T)info_t;
  } else {
    *info = 0;
  }

  V_size[0] = A_size[1];
  V_size[1] = A_size[1];
  minnm = A_size[1];
  for (i6 = 0; i6 < minnm; i6++) {
    loop_ub = A_size[1];
    for (i7 = 0; i7 < loop_ub; i7++) {
      V_data[i7 + V_size[0] * i6] = Vt_data[i6 + A_size[1] * i7];
    }
  }

  st.site = &gc_emlrtRSI;
  infocheck(&st, *info);
}

/* End of code generation (xgesvd.c) */
