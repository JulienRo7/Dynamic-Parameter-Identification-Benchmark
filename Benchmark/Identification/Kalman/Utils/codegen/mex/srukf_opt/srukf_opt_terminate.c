/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * srukf_opt_terminate.c
 *
 * Code generation for function 'srukf_opt_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "srukf_opt_terminate.h"
#include "srukf_opt_mexutil.h"
#include "_coder_srukf_opt_mex.h"
#include "srukf_opt_data.h"

/* Function Definitions */
void srukf_opt_atexit(void)
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

void srukf_opt_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtFreeThreadStackData(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (srukf_opt_terminate.c) */
