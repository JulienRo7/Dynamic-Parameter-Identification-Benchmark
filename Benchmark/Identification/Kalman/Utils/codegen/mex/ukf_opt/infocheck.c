/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * infocheck.c
 *
 * Code generation for function 'infocheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "infocheck.h"
#include "error.h"
#include "ukf_opt_data.h"
#include "lapacke.h"

/* Function Definitions */
boolean_T infocheck(const emlrtStack *sp, int32_T info)
{
  boolean_T p;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (info < 0) {
    if (info == -1010) {
      st.site = &kb_emlrtRSI;
      c_error(&st);
    } else {
      st.site = &lb_emlrtRSI;
      f_error(&st, info);
    }
  } else {
    p = false;
  }

  return p;
}

/* End of code generation (infocheck.c) */
