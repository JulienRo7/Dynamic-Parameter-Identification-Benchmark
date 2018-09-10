/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * srukf_opt_initialize.c
 *
 * Code generation for function 'srukf_opt_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "srukf_opt_initialize.h"
#include "srukf_opt_mexutil.h"
#include "_coder_srukf_opt_mex.h"
#include "srukf_opt_data.h"

/* Function Definitions */
void srukf_opt_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtInitThreadStackData(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (srukf_opt_initialize.c) */
