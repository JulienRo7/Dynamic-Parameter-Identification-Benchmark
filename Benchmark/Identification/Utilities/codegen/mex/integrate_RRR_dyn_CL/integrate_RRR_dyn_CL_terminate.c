/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * integrate_RRR_dyn_CL_terminate.c
 *
 * Code generation for function 'integrate_RRR_dyn_CL_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "integrate_RRR_dyn_CL_terminate.h"
#include "_coder_integrate_RRR_dyn_CL_mex.h"
#include "integrate_RRR_dyn_CL_data.h"

/* Function Definitions */
void integrate_RRR_dyn_CL_atexit(void)
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

void integrate_RRR_dyn_CL_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (integrate_RRR_dyn_CL_terminate.c) */
