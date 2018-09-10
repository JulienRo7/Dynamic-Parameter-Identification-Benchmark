/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ukf_opt_mexutil.c
 *
 * Code generation for function 'ukf_opt_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "ukf_opt_mexutil.h"
#include "ukf_opt_data.h"

/* Variable Definitions */
static ukf_optTLS *ukf_optTLSGlobal;

#pragma omp threadprivate (ukf_optTLSGlobal)

/* Function Definitions */
const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const mxArray
  *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m15;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m15, 2, pArrays, "sprintf", true,
    location);
}

void emlrtFreeThreadStackData(const emlrtStack *sp)
{
  int32_T i;
  jmp_buf * volatile emlrtJBStack;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel for schedule(static)\
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs()))

  for (i = 1; i <= omp_get_max_threads(); i++) {
    free(ukf_optTLSGlobal);
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

ukf_optTLS *emlrtGetThreadStackData(void)
{
  return ukf_optTLSGlobal;
}

void emlrtInitThreadStackData(const emlrtStack *sp)
{
  int32_T i;
  jmp_buf * volatile emlrtJBStack;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel for schedule(static)\
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs()))

  for (i = 1; i <= omp_get_max_threads(); i++) {
    ukf_optTLSGlobal = (ukf_optTLS *)malloc(1U * sizeof(ukf_optTLS));
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void l_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

/* End of code generation (ukf_opt_mexutil.c) */
