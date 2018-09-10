/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_ukf_opt_api.c
 *
 * Code generation for function '_coder_ukf_opt_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "_coder_ukf_opt_api.h"
#include "ukf_opt_data.h"

/* Function Declarations */
static void b_emlrt_marshallOut(const real_T u_data[], const int32_T u_size[2],
  const mxArray *y);
static const mxArray *c_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static const mxArray *d_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t_km1,
  const char_T *identifier);
static const mxArray *e_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *f_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *g_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Rn, const
  char_T *identifier, real_T **y_data, int32_T y_size[2]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2]);
static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *sigmaComputeMethod, const char_T *identifier);
static boolean_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static real_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2]);
static boolean_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallOut(const real_T u_data[], const int32_T u_size[2],
  const mxArray *y)
{
  emlrtMxSetData((mxArray *)y, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)y, u_size, 2);
}

static const mxArray *c_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m9;
  static const int32_T iv20[2] = { 0, 0 };

  y = NULL;
  m9 = emlrtCreateNumericArray(2, iv20, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m9, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m9, u_size, 2);
  emlrtAssign(&y, m9);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1])
{
  const mxArray *y;
  const mxArray *m10;
  static const int32_T iv21[1] = { 0 };

  y = NULL;
  m10 = emlrtCreateNumericArray(1, iv21, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m10, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m10, u_size, 1);
  emlrtAssign(&y, m10);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t_km1,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(t_km1), &thisId);
  emlrtDestroyArray(&t_km1);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m11;
  static const int32_T iv22[2] = { 0, 0 };

  y = NULL;
  m11 = emlrtCreateNumericArray(2, iv22, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m11, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m11, u_size, 2);
  emlrtAssign(&y, m11);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1])
{
  const mxArray *y;
  const mxArray *m8;
  static const int32_T iv19[1] = { 0 };

  y = NULL;
  m8 = emlrtCreateNumericArray(1, iv19, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m8, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m8, u_size, 1);
  emlrtAssign(&y, m8);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m12;
  static const int32_T iv23[2] = { 0, 0 };

  y = NULL;
  m12 = emlrtCreateNumericArray(2, iv23, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m12, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m12, u_size, 2);
  emlrtAssign(&y, m12);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(x_km1), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&x_km1);
}

static const mxArray *g_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m13;
  static const int32_T iv24[2] = { 0, 0 };

  y = NULL;
  m13 = emlrtCreateNumericArray(2, iv24, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m13, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m13, u_size, 2);
  emlrtAssign(&y, m13);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r1;
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u_km1, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r2;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(u_km1), &thisId, &r2, y_size);
  *y_data = r2;
  emlrtDestroyArray(&u_km1);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r3;
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r3, y_size);
  *y_data = r3;
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *P, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r4;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(P), &thisId, &r4, y_size);
  *y_data = r4;
  emlrtDestroyArray(&P);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r5;
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r5, y_size);
  *y_data = r5;
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Rn, const
  char_T *identifier, real_T **y_data, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *r6;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(Rn), &thisId, &r6, y_size);
  *y_data = r6;
  emlrtDestroyArray(&Rn);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[2])
{
  real_T *r7;
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r7, y_size);
  *y_data = r7;
  emlrtDestroyArray(&u);
}

static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *sigmaComputeMethod, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(sigmaComputeMethod), &thisId);
  emlrtDestroyArray(&sigmaComputeMethod);
  return y;
}

static boolean_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 23 };

  const boolean_T bv0[1] = { true };

  int32_T iv25[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv25);
  ret_size[0] = iv25[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 3 };

  const boolean_T bv1[1] = { true };

  int32_T iv26[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv1[0],
    iv26);
  ret_size[0] = iv26[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 23, 23 };

  const boolean_T bv2[2] = { true, true };

  int32_T iv27[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv2[0],
    iv27);
  ret_size[0] = iv27[0];
  ret_size[1] = iv27[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[2])
{
  static const int32_T dims[2] = { 3, 3 };

  const boolean_T bv3[2] = { true, true };

  int32_T iv28[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv3[0],
    iv28);
  ret_size[0] = iv28[0];
  ret_size[1] = iv28[1];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static boolean_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

void ukf_opt_api(const mxArray * const prhs[12], int32_T nlhs, const mxArray
                 *plhs[8])
{
  real_T (*x_data)[23];
  real_T (*K_data)[1127];
  real_T (*inov_data)[3];
  real_T (*x_kkm1_data)[23];
  real_T (*P_kkm1_data)[529];
  real_T (*P_xy_data)[69];
  real_T (*P_yy_data)[9];
  const mxArray *prhs_copy_idx_4;
  real_T t_km1;
  real_T t_k;
  real_T (*x_km1_data)[23];
  int32_T x_km1_size[1];
  real_T (*u_km1_data)[3];
  int32_T u_km1_size[1];
  real_T (*P_data)[529];
  int32_T P_size[2];
  real_T (*y_k_data)[3];
  int32_T y_k_size[1];
  real_T (*Rv_data)[529];
  int32_T Rv_size[2];
  real_T (*Rn_data)[9];
  int32_T Rn_size[2];
  real_T alpha;
  real_T beta;
  real_T kappa;
  boolean_T sigmaComputeMethod;
  int32_T x_size[1];
  int32_T K_size[2];
  int32_T inov_size[1];
  int32_T x_kkm1_size[1];
  int32_T P_kkm1_size[2];
  int32_T P_xy_size[2];
  int32_T P_yy_size[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  x_data = (real_T (*)[23])mxMalloc(sizeof(real_T [23]));
  K_data = (real_T (*)[1127])mxMalloc(sizeof(real_T [1127]));
  inov_data = (real_T (*)[3])mxMalloc(sizeof(real_T [3]));
  x_kkm1_data = (real_T (*)[23])mxMalloc(sizeof(real_T [23]));
  P_kkm1_data = (real_T (*)[529])mxMalloc(sizeof(real_T [529]));
  P_xy_data = (real_T (*)[69])mxMalloc(sizeof(real_T [69]));
  P_yy_data = (real_T (*)[9])mxMalloc(sizeof(real_T [9]));
  prhs_copy_idx_4 = emlrtProtectR2012b(prhs[4], 4, true, 529);

  /* Marshall function inputs */
  t_km1 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "t_km1");
  t_k = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "t_k");
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "x_km1", (real_T **)&x_km1_data,
                     x_km1_size);
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "u_km1", (real_T **)&u_km1_data,
                     u_km1_size);
  k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_4), "P", (real_T **)&P_data,
                     P_size);
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "y_k", (real_T **)&y_k_data,
                     y_k_size);
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "Rv", (real_T **)&Rv_data,
                     Rv_size);
  m_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "Rn", (real_T **)&Rn_data,
                     Rn_size);
  alpha = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "alpha");
  beta = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "beta");
  kappa = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "kappa");
  sigmaComputeMethod = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]),
    "sigmaComputeMethod");

  /* Invoke the target function */
  ukf_opt(&st, t_km1, t_k, *x_km1_data, x_km1_size, *u_km1_data, u_km1_size,
          *P_data, P_size, *y_k_data, y_k_size, *Rv_data, Rv_size, *Rn_data,
          Rn_size, alpha, beta, kappa, sigmaComputeMethod, *x_data, x_size,
          *K_data, K_size, *inov_data, inov_size, *x_kkm1_data, x_kkm1_size,
          *P_kkm1_data, P_kkm1_size, *P_xy_data, P_xy_size, *P_yy_data,
          P_yy_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*x_data, x_size);
  if (nlhs > 1) {
    b_emlrt_marshallOut(*P_data, P_size, prhs_copy_idx_4);
    plhs[1] = prhs_copy_idx_4;
  }

  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(*K_data, K_size);
  }

  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(*inov_data, inov_size);
  }

  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(*x_kkm1_data, x_kkm1_size);
  }

  if (nlhs > 5) {
    plhs[5] = e_emlrt_marshallOut(*P_kkm1_data, P_kkm1_size);
  }

  if (nlhs > 6) {
    plhs[6] = f_emlrt_marshallOut(*P_xy_data, P_xy_size);
  }

  if (nlhs > 7) {
    plhs[7] = g_emlrt_marshallOut(*P_yy_data, P_yy_size);
  }
}

/* End of code generation (_coder_ukf_opt_api.c) */
