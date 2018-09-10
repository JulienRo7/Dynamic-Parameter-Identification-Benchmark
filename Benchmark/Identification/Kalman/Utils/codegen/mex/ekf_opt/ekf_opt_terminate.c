/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ekf_opt_terminate.c
 *
 * Code generation for function 'ekf_opt_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ekf_opt.h"
#include "ekf_opt_terminate.h"
#include "_coder_ekf_opt_mex.h"
#include "ekf_opt_data.h"

/* Function Definitions */
void ekf_opt_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void ekf_opt_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (ekf_opt_terminate.c) */
