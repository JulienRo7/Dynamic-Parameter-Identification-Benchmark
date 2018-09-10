/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ukf_opt_mex.c
 *
 * Code generation for function '_coder_ukf_opt_mex'
 *
 */

/* Include files */
#include "ukf_opt.h"
#include "_coder_ukf_opt_mex.h"
#include "ukf_opt_terminate.h"
#include "_coder_ukf_opt_api.h"
#include "ukf_opt_initialize.h"
#include "ukf_opt_data.h"

/* Variable Definitions */
static jmp_buf emlrtJBEnviron;

/* Function Declarations */
static void ukf_opt_mexFunction(int32_T nlhs, mxArray *plhs[8], int32_T nrhs,
  const mxArray *prhs[12]);

/* Function Definitions */
static void ukf_opt_mexFunction(int32_T nlhs, mxArray *plhs[8], int32_T nrhs,
  const mxArray *prhs[12])
{
  const mxArray *outputs[8];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 12) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 12, 4,
                        7, "ukf_opt");
  }

  if (nlhs > 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "ukf_opt");
  }

  /* Call the function. */
  ukf_opt_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  ukf_opt_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexAtExit(ukf_opt_atexit);

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  emlrtLoadLibrary("/opt/MATLAB/R2018a/sys/os/glnxa64/libiomp5.so");

  /* Module initialization. */
  ukf_opt_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    /* Dispatch the entry-point. */
    ukf_opt_mexFunction(nlhs, plhs, nrhs, prhs);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_ukf_opt_mex.c) */
