/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_integrate_RRR_dyn_CL_api.c
 *
 * Code generation for function '_coder_integrate_RRR_dyn_CL_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "_coder_integrate_RRR_dyn_CL_api.h"
#include "integrate_RRR_dyn_CL_emxutil.h"
#include "integrate_RRR_dyn_CL_data.h"

/* Variable Definitions */
static emlrtRTEInfo o_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_integrate_RRR_dyn_CL_api",   /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X_0, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Theta, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t_0, const
  char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv11[2] = { 0, 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv11, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m4, u->size, 2);
  emlrtAssign(&y, m4);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X_0, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(X_0), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&X_0);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv12[2] = { 0, 0 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv12, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m5, u->size, 2);
  emlrtAssign(&y, m5);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r1;
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Theta, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r2;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(Theta), &thisId, &r2, y_size);
  *y_data = r2;
  emlrtDestroyArray(&Theta);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv10[2] = { 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv10, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m3, u->size, 2);
  emlrtAssign(&y, m3);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r3;
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r3, y_size);
  *y_data = r3;
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t_0, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(t_0), &thisId);
  emlrtDestroyArray(&t_0);
  return y;
}

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 6 };

  const boolean_T bv0[1] = { true };

  int32_T iv13[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv13);
  ret_size[0] = iv13[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 17 };

  const boolean_T bv1[1] = { true };

  int32_T iv14[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv14);
  ret_size[0] = iv14[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void integrate_RRR_dyn_CL_api(const mxArray * const prhs[5], int32_T nlhs, const
  mxArray *plhs[3])
{
  emxArray_real_T *t;
  emxArray_real_T *X;
  emxArray_real_T *Qpp;
  real_T (*X_0_data)[6];
  int32_T X_0_size[1];
  real_T (*Theta_data)[17];
  int32_T Theta_size[1];
  real_T t_0;
  real_T t_f;
  real_T N;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &t, 2, &o_emlrtRTEI, true);
  emxInit_real_T(&st, &X, 2, &o_emlrtRTEI, true);
  emxInit_real_T(&st, &Qpp, 2, &o_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X_0", (real_T **)&X_0_data,
                     X_0_size);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Theta", (real_T **)&Theta_data,
                     Theta_size);
  t_0 = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_0");
  t_f = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "t_f");
  N = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "N");

  /* Invoke the target function */
  integrate_RRR_dyn_CL(&st, *X_0_data, X_0_size, *Theta_data, Theta_size, t_0,
                       t_f, N, t, X, Qpp);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(t);
  t->canFreeData = false;
  emxFree_real_T(&st, &t);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(X);
  }

  X->canFreeData = false;
  emxFree_real_T(&st, &X);
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(Qpp);
  }

  Qpp->canFreeData = false;
  emxFree_real_T(&st, &Qpp);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_integrate_RRR_dyn_CL_api.c) */
