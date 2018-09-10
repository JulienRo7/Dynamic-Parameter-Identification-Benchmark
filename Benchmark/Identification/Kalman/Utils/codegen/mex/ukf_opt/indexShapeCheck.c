/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "indexShapeCheck.h"
#include "ukf_opt_data.h"

/* Function Definitions */
void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yc_emlrtRSI;
  if (matrixSize == 1) {
    emlrtErrorWithMessageIdR2018a(&st, &p_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
