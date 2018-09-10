/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ekf_opt_api.c
 *
 * Code generation for function '_coder_ekf_opt_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ekf_opt.h"
#include "_coder_ekf_opt_api.h"
#include "ekf_opt_data.h"

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[529]);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t_km1,
  const char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const real_T u[69]);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *d_emlrt_marshallOut(const real_T u[3]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *e_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static const mxArray *emlrt_marshallOut(const real_T u[23]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static const mxArray *f_emlrt_marshallOut(const real_T u[9]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Rn, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[529])
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv14[2] = { 0, 0 };

  static const int32_T iv15[2] = { 23, 23 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv14, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m4, iv15, 2);
  emlrtAssign(&y, m4);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t_km1,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(t_km1), &thisId);
  emlrtDestroyArray(&t_km1);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[69])
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv16[2] = { 0, 0 };

  static const int32_T iv17[2] = { 23, 3 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv16, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m5, iv17, 2);
  emlrtAssign(&y, m5);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = n_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const real_T u[3])
{
  const mxArray *y;
  const mxArray *m6;
  static const int32_T iv18[1] = { 0 };

  static const int32_T iv19[1] = { 3 };

  y = NULL;
  m6 = emlrtCreateNumericArray(1, iv18, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m6, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m6, iv19, 1);
  emlrtAssign(&y, m6);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(x_km1), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&x_km1);
}

static const mxArray *e_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1])
{
  const mxArray *y;
  const mxArray *m7;
  static const int32_T iv20[1] = { 0 };

  y = NULL;
  m7 = emlrtCreateNumericArray(1, iv20, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m7, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m7, u_size, 1);
  emlrtAssign(&y, m7);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[23])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv12[1] = { 0 };

  static const int32_T iv13[1] = { 23 };

  y = NULL;
  m3 = emlrtCreateNumericArray(1, iv12, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv13, 1);
  emlrtAssign(&y, m3);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r1;
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

static const mxArray *f_emlrt_marshallOut(const real_T u[9])
{
  const mxArray *y;
  const mxArray *m8;
  static const int32_T iv21[2] = { 0, 0 };

  static const int32_T iv22[2] = { 3, 3 };

  y = NULL;
  m8 = emlrtCreateNumericArray(2, iv21, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m8, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m8, iv22, 2);
  emlrtAssign(&y, m8);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r2;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(u_km1), &thisId, &r2, y_size);
  *y_data = r2;
  emlrtDestroyArray(&u_km1);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r3;
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r3, y_size);
  *y_data = r3;
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r4;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(P_km1), &thisId, &r4, y_size);
  *y_data = r4;
  emlrtDestroyArray(&P_km1);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r5;
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r5, y_size);
  *y_data = r5;
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Rn, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r6;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(Rn), &thisId, &r6, y_size);
  *y_data = r6;
  emlrtDestroyArray(&Rn);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r7;
  r_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r7, y_size);
  *y_data = r7;
  emlrtDestroyArray(&u);
}

static real_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 23 };

  const boolean_T bv0[1] = { true };

  int32_T iv23[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv23);
  ret_size[0] = iv23[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 3 };

  const boolean_T bv1[1] = { true };

  int32_T iv24[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv24);
  ret_size[0] = iv24[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 23, 23 };

  const boolean_T bv2[2] = { true, true };

  int32_T iv25[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv2[0],
    iv25);
  ret_size[0] = iv25[0];
  ret_size[1] = iv25[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 3, 3 };

  const boolean_T bv3[2] = { true, true };

  int32_T iv26[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv3[0],
    iv26);
  ret_size[0] = iv26[0];
  ret_size[1] = iv26[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

void ekf_opt_api(const mxArray * const prhs[8], int32_T nlhs, const mxArray
                 *plhs[8])
{
  real_T (*x)[23];
  real_T (*P)[529];
  real_T (*K)[69];
  real_T (*inov)[3];
  real_T (*x_kkm1_data)[23];
  real_T (*P_kkm1)[529];
  real_T (*P_xy)[69];
  real_T (*P_yy)[9];
  real_T t_km1;
  real_T t_k;
  real_T (*x_km1_data)[23];
  int32_T x_km1_size[1];
  real_T (*u_km1_data)[3];
  int32_T u_km1_size[1];
  real_T (*P_km1_data)[529];
  int32_T P_km1_size[2];
  real_T (*y_k_data)[3];
  int32_T y_k_size[1];
  real_T (*Rv_data)[529];
  int32_T Rv_size[2];
  real_T (*Rn_data)[9];
  int32_T Rn_size[2];
  int32_T x_kkm1_size[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  x = (real_T (*)[23])mxMalloc(sizeof(real_T [23]));
  P = (real_T (*)[529])mxMalloc(sizeof(real_T [529]));
  K = (real_T (*)[69])mxMalloc(sizeof(real_T [69]));
  inov = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  x_kkm1_data = (real_T (*)[23])mxMalloc(sizeof(real_T [23]));
  P_kkm1 = (real_T (*)[529])mxMalloc(sizeof(real_T [529]));
  P_xy = (real_T (*)[69])mxMalloc(sizeof(real_T [69]));
  P_yy = (real_T (*)[9])mxMalloc(sizeof(real_T [9]));

  /* Marshall function inputs */
  t_km1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t_km1");
  t_k = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "t_k");
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "x_km1", (real_T **)&x_km1_data,
                     x_km1_size);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "u_km1", (real_T **)&u_km1_data,
                     u_km1_size);
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "P_km1", (real_T **)&P_km1_data,
                     P_km1_size);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "y_k", (real_T **)&y_k_data,
                     y_k_size);
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "Rv", (real_T **)&Rv_data,
                     Rv_size);
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Rn", (real_T **)&Rn_data,
                     Rn_size);

  /* Invoke the target function */
  ekf_opt(&st, t_km1, t_k, *x_km1_data, x_km1_size, *u_km1_data, u_km1_size,
          *P_km1_data, P_km1_size, *y_k_data, y_k_size, *Rv_data, Rv_size,
          *Rn_data, Rn_size, *x, *P, *K, *inov, *x_kkm1_data, x_kkm1_size,
          *P_kkm1, *P_xy, *P_yy);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*x);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*P);
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(*K);
  }

  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(*inov);
  }

  if (nlhs > 4) {
    plhs[4] = e_emlrt_marshallOut(*x_kkm1_data, x_kkm1_size);
  }

  if (nlhs > 5) {
    plhs[5] = b_emlrt_marshallOut(*P_kkm1);
  }

  if (nlhs > 6) {
    plhs[6] = c_emlrt_marshallOut(*P_xy);
  }

  if (nlhs > 7) {
    plhs[7] = f_emlrt_marshallOut(*P_yy);
  }
}

/* End of code generation (_coder_ekf_opt_api.c) */
