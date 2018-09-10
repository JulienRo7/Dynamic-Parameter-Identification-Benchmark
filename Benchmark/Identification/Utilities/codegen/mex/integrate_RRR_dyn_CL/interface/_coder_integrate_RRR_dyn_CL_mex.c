/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_integrate_RRR_dyn_CL_mex.c
 *
 * Code generation for function '_coder_integrate_RRR_dyn_CL_mex'
 *
 */

/* Include files */
#include "integrate_RRR_dyn_CL.h"
#include "_coder_integrate_RRR_dyn_CL_mex.h"
#include "integrate_RRR_dyn_CL_terminate.h"
#include "_coder_integrate_RRR_dyn_CL_api.h"
#include "integrate_RRR_dyn_CL_initialize.h"
#include "integrate_RRR_dyn_CL_data.h"

/* Function Declarations */
static void c_integrate_RRR_dyn_CL_mexFunct(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[5]);

/* Function Definitions */
static void c_integrate_RRR_dyn_CL_mexFunct(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[5])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        20, "integrate_RRR_dyn_CL");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "integrate_RRR_dyn_CL");
  }

  /* Call the function. */
  integrate_RRR_dyn_CL_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  integrate_RRR_dyn_CL_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(integrate_RRR_dyn_CL_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  integrate_RRR_dyn_CL_initialize();

  /* Dispatch the entry-point. */
  c_integrate_RRR_dyn_CL_mexFunct(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_integrate_RRR_dyn_CL_mex.c) */
