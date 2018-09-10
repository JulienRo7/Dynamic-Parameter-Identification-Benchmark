/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_torqueVector_api.c
 *
 * Code generation for function '_coder_torqueVector_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "torqueVector.h"
#include "_coder_torqueVector_api.h"
#include "torqueVector_emxutil.h"
#include "torqueVector_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_torqueVector_api",           /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Tau, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 10001, 3 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv2[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv2);
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Tau, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Tau), &thisId, y);
  emlrtDestroyArray(&Tau);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[1] = { 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(1, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m1, u->size, 1);
  emlrtAssign(&y, m1);
  return y;
}

void torqueVector_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                      *plhs[1])
{
  emxArray_real_T *Tau;
  emxArray_real_T *Y_tau;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Tau, 2, &b_emlrtRTEI, true);
  emxInit_real_T1(&st, &Y_tau, 1, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Tau", Tau);

  /* Invoke the target function */
  torqueVector(&st, Tau, Y_tau);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(Y_tau);
  Y_tau->canFreeData = false;
  emxFree_real_T(&st, &Y_tau);
  Tau->canFreeData = false;
  emxFree_real_T(&st, &Tau);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_torqueVector_api.c) */
