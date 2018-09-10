/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_observationMatrix_api.c
 *
 * Code generation for function '_coder_observationMatrix_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "observationMatrix.h"
#include "_coder_observationMatrix_api.h"
#include "observationMatrix_emxutil.h"
#include "observationMatrix_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_observationMatrix_api",      /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q, const
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

  int32_T iv1[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Q), &thisId, y);
  emlrtDestroyArray(&Q);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

void observationMatrix_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1])
{
  emxArray_real_T *Q;
  emxArray_real_T *Qp;
  emxArray_real_T *Qpp;
  emxArray_real_T *W;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Q, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &Qp, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &Qpp, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &W, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Q", Q);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Qp", Qp);
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Qpp", Qpp);

  /* Invoke the target function */
  observationMatrix(&st, Q, Qp, Qpp, W);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(W);
  W->canFreeData = false;
  emxFree_real_T(&st, &W);
  Qpp->canFreeData = false;
  emxFree_real_T(&st, &Qpp);
  Qp->canFreeData = false;
  emxFree_real_T(&st, &Qp);
  Q->canFreeData = false;
  emxFree_real_T(&st, &Q);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_observationMatrix_api.c) */
