/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ode45.c
 *
 * Code generation for function 'ode45'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "ode45.h"
#include "eps.h"
#include "xgemv.h"
#include "ntrp45.h"
#include "integrate_RRR_dyn_CL_emxutil.h"
#include "error.h"
#include "warning.h"
#include "num2str.h"
#include "norm.h"
#include "rdivide.h"
#include "ode2345.h"
#include "RRR_dyn_CL.h"
#include "scalexpAlloc.h"
#include "abs.h"
#include "integrate_RRR_dyn_CL_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 17,  /* lineNo */
  "ode45",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/ode45.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 515, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 454, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 448, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 379, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 366, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 369, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 368, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 348, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 338, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 336, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 327,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 325,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 308,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 281,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 273,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 82, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 11, /* lineNo */
  "callODEFunctionNSM",                /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/callODEFunctionNSM.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 37, /* lineNo */
  "function_handle",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/function_handle.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 35, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 60, /* lineNo */
  "binaryMinOrMax",                    /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/binaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 45, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 40, /* lineNo */
  "mpower",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 52, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 118,/* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 114,/* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 25, /* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 214,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 215,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 539,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 540,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 303,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 1, /* lineNo */
  22,                                  /* colNo */
  "ode45",                             /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/ode45.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 25,/* lineNo */
  18,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 454,/* lineNo */
  17,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 115,/* lineNo */
  10,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 17,/* lineNo */
  19,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 49,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 99,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 268,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

/* Function Definitions */
void ode45(const emlrtStack *sp, const real_T ode_tunableEnvironment_f1[3],
           const real_T ode_tunableEnvironment_f2_data[], const int32_T
           ode_tunableEnvironment_f2_size[1], const real_T tspan[2], const
           real_T y0_data[], const int32_T y0_size[1], emxArray_real_T
           *varargout_1, emxArray_real_T *varargout_2)
{
  real_T tfinal;
  int32_T b_y0[1];
  real_T f0[6];
  emxArray_real_T *tout;
  int32_T i2;
  emxArray_real_T *yout;
  int32_T nout;
  real_T twidth;
  real_T hmax;
  real_T hmin;
  real_T absh;
  real_T varargin_1_data[6];
  int32_T varargin_1_size[1];
  int32_T Bcolidx;
  real_T ystage_data[6];
  int8_T varargin_2[2];
  boolean_T empty_non_axis_sizes;
  boolean_T MinStepExit;
  boolean_T exitg1;
  real_T b_f0[6];
  real_T t;
  int32_T y_size[1];
  real_T f_data[42];
  real_T y_data[6];
  real_T tdir;
  boolean_T Done;
  emxArray_real_T *result;
  emxArray_real_T *b_yout;
  int32_T exitg2;
  boolean_T NoFailedAttempts;
  int32_T exitg3;
  int32_T j;
  real_T tnew;
  char_T TRANSA;
  char_T TRANSB;
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  static const real_T B[7] = { 0.0012326388888888888, 0.0,
    -0.0042527702905061394, 0.036979166666666667, -0.05086379716981132,
    0.0419047619047619, -0.025 };

  real_T err;
  char_T cv0[23];
  char_T cv1[23];
  int32_T outidx;
  real_T toutnew[4];
  real_T tref[3];
  real_T b_varargin_1_data[18];
  int32_T b_varargin_1_size[2];
  int32_T i3;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &o_emlrtRSI;
  if (y0_size[0] == 0) {
    emlrtErrorWithMessageIdR2018a(&st, &u_emlrtRTEI,
      "MATLAB:odearguments:TspanOrY0NotSupplied",
      "MATLAB:odearguments:TspanOrY0NotSupplied", 3, 4, 5, "ode45");
  }

  tfinal = tspan[1];
  if (tspan[0] == tspan[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI,
      "MATLAB:odearguments:TspanEndpointsNotDistinct",
      "MATLAB:odearguments:TspanEndpointsNotDistinct", 0);
  }

  if (!ismonotonic(tspan)) {
    emlrtErrorWithMessageIdR2018a(&st, &w_emlrtRTEI,
      "MATLAB:odearguments:TspanNotMonotonic",
      "MATLAB:odearguments:TspanNotMonotonic", 0);
  }

  b_st.site = &fb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &hb_emlrtRSI;
  b_y0[0] = y0_size[0];
  e_st.site = &d_emlrtRSI;
  RRR_dyn_CL(&e_st, y0_data, b_y0, ode_tunableEnvironment_f1,
             ode_tunableEnvironment_f2_data, ode_tunableEnvironment_f2_size, f0);
  if (6 != y0_size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &x_emlrtRTEI, "Coder:toolbox:SizeIC",
      "Coder:toolbox:SizeIC", 0);
  }

  emxInit_real_T(&st, &tout, 2, &f_emlrtRTEI, true);
  i2 = tout->size[0] * tout->size[1];
  tout->size[0] = 1;
  tout->size[1] = 200;
  emxEnsureCapacity_real_T(&st, tout, i2, &f_emlrtRTEI);
  for (i2 = 0; i2 < 200; i2++) {
    tout->data[i2] = 0.0;
  }

  emxInit_real_T(&st, &yout, 2, &g_emlrtRTEI, true);
  i2 = yout->size[0] * yout->size[1];
  yout->size[0] = 6;
  yout->size[1] = 200;
  emxEnsureCapacity_real_T(&st, yout, i2, &g_emlrtRTEI);
  for (i2 = 0; i2 < 1200; i2++) {
    yout->data[i2] = 0.0;
  }

  nout = 1;
  tout->data[0] = tspan[0];
  for (i2 = 0; i2 < 6; i2++) {
    yout->data[i2] = y0_data[i2];
  }

  twidth = muDoubleScalarAbs(tspan[1] - tspan[0]);
  hmax = muDoubleScalarMin(twidth, muDoubleScalarMax(0.1 * twidth,
    3.5527136788005009E-15 * muDoubleScalarMax(muDoubleScalarAbs(tspan[0]),
    muDoubleScalarAbs(tspan[1]))));
  if (!(hmax > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &y_emlrtRTEI,
      "MATLAB:odearguments:MaxStepLEzero", "MATLAB:odearguments:MaxStepLEzero",
      0);
  }

  b_st.site = &eb_emlrtRSI;
  hmin = 16.0 * eps(tspan[0]);
  absh = muDoubleScalarMin(hmax, muDoubleScalarAbs(tspan[1] - tspan[0]));
  b_y0[0] = 6;
  b_abs(y0_data, b_y0, varargin_1_data, varargin_1_size);
  b_st.site = &db_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  d_st.site = &jb_emlrtRSI;
  e_st.site = &kb_emlrtRSI;
  f_st.site = &lb_emlrtRSI;
  g_st.site = &mb_emlrtRSI;
  b_y0[0] = (int8_T)varargin_1_size[0];
  if (!dimagree(b_y0, varargin_1_size)) {
    emlrtErrorWithMessageIdR2018a(&g_st, &t_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  for (Bcolidx = 0; Bcolidx < (int8_T)varargin_1_size[0]; Bcolidx++) {
    ystage_data[Bcolidx] = muDoubleScalarMax(varargin_1_data[Bcolidx], 0.001);
  }

  b_st.site = &db_emlrtRSI;
  varargin_2[0] = (int8_T)varargin_1_size[0];
  varargin_2[1] = 1;
  empty_non_axis_sizes = false;
  MinStepExit = true;
  Bcolidx = 0;
  exitg1 = false;
  while ((!exitg1) && (Bcolidx < 2)) {
    if (!(6 + -5 * Bcolidx == varargin_2[Bcolidx])) {
      MinStepExit = false;
      exitg1 = true;
    } else {
      Bcolidx++;
    }
  }

  if (MinStepExit) {
    empty_non_axis_sizes = true;
  }

  if (!empty_non_axis_sizes) {
    emlrtErrorWithMessageIdR2018a(&b_st, &s_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  for (i2 = 0; i2 < 6; i2++) {
    b_f0[i2] = f0[i2] / ystage_data[i2];
  }

  twidth = norm(b_f0) / 0.20095091452076641;
  if (absh * twidth > 1.0) {
    absh = 1.0 / twidth;
  }

  absh = muDoubleScalarMax(absh, hmin);
  t = tspan[0];
  y_size[0] = 6;
  for (i2 = 0; i2 < 6; i2++) {
    y_data[i2] = y0_data[i2];
  }

  memset(&f_data[0], 0, 42U * sizeof(real_T));
  for (i2 = 0; i2 < 6; i2++) {
    f_data[i2] = f0[i2];
  }

  tdir = muDoubleScalarSign(tspan[1] - tspan[0]);
  MinStepExit = false;
  Done = false;
  emxInit_real_T(&st, &result, 2, &n_emlrtRTEI, true);
  emxInit_real_T(&st, &b_yout, 2, &l_emlrtRTEI, true);
  do {
    exitg2 = 0;
    b_st.site = &cb_emlrtRSI;
    hmin = 16.0 * eps(t);
    absh = muDoubleScalarMin(hmax, muDoubleScalarMax(hmin, absh));
    twidth = tdir * absh;
    if (1.1 * absh >= muDoubleScalarAbs(tfinal - t)) {
      twidth = tfinal - t;
      absh = muDoubleScalarAbs(twidth);
      Done = true;
    }

    NoFailedAttempts = true;
    do {
      exitg3 = 0;
      Bcolidx = 1;
      for (j = 0; j < 5; j++) {
        Bcolidx += j;
        b_y0[0] = 6;
        memcpy(&ystage_data[0], &y_data[0], (uint32_T)(6 * (int32_T)sizeof
                (real_T)));
        b_st.site = &bb_emlrtRSI;
        xgemv(j + 1, twidth, f_data, Bcolidx, ystage_data);
        b_st.site = &ab_emlrtRSI;
        c_st.site = &gb_emlrtRSI;
        d_st.site = &hb_emlrtRSI;
        e_st.site = &d_emlrtRSI;
        RRR_dyn_CL(&e_st, ystage_data, b_y0, ode_tunableEnvironment_f1,
                   ode_tunableEnvironment_f2_data,
                   ode_tunableEnvironment_f2_size, f0);
        for (i2 = 0; i2 < 6; i2++) {
          f_data[i2 + 6 * (j + 1)] = f0[i2];
        }
      }

      tnew = t + twidth;
      if (Done) {
        tnew = tfinal;
      }

      b_y0[0] = 6;
      memcpy(&ystage_data[0], &y_data[0], (uint32_T)(6 * (int32_T)sizeof(real_T)));
      b_st.site = &y_emlrtRSI;
      b_xgemv(twidth, f_data, Bcolidx + 5, ystage_data);
      b_st.site = &x_emlrtRSI;
      c_st.site = &gb_emlrtRSI;
      d_st.site = &hb_emlrtRSI;
      e_st.site = &d_emlrtRSI;
      RRR_dyn_CL(&e_st, ystage_data, b_y0, ode_tunableEnvironment_f1,
                 ode_tunableEnvironment_f2_data, ode_tunableEnvironment_f2_size,
                 f0);
      for (i2 = 0; i2 < 6; i2++) {
        f_data[i2 + 36] = f0[i2];
      }

      b_st.site = &w_emlrtRSI;
      c_st.site = &sb_emlrtRSI;
      d_st.site = &ub_emlrtRSI;
      d_st.site = &tb_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      twidth = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)6;
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)7;
      lda_t = (ptrdiff_t)6;
      ldb_t = (ptrdiff_t)7;
      ldc_t = (ptrdiff_t)6;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &twidth, &f_data[0], &lda_t, &B
            [0], &ldb_t, &beta1, &b_f0[0], &ldc_t);
      maxAbsThresh(y_data, y_size, ystage_data, varargin_1_data, varargin_1_size);
      b_st.site = &w_emlrtRSI;
      rdivide(&b_st, b_f0, varargin_1_data, varargin_1_size, f0, b_y0);
      err = absh * b_norm(f0);
      if (err > 0.001) {
        if (absh <= hmin) {
          b_st.site = &v_emlrtRSI;
          num2str(&b_st, t, cv0);
          b_st.site = &u_emlrtRSI;
          num2str(&b_st, hmin, cv1);
          b_st.site = &t_emlrtRSI;
          b_warning(&b_st, cv0, cv1);
          MinStepExit = true;
          exitg3 = 1;
        } else {
          if (NoFailedAttempts) {
            NoFailedAttempts = false;
            b_st.site = &s_emlrtRSI;
            c_st.site = &nb_emlrtRSI;
            d_st.site = &ob_emlrtRSI;
            absh = muDoubleScalarMax(hmin, absh * muDoubleScalarMax(0.1, 0.8 *
              muDoubleScalarPower(0.001 / err, 0.2)));
          } else {
            absh = muDoubleScalarMax(hmin, 0.5 * absh);
          }

          twidth = tdir * absh;
          Done = false;
        }
      } else {
        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (MinStepExit) {
      exitg2 = 1;
    } else {
      outidx = nout;
      twidth = tnew - t;
      for (i2 = 0; i2 < 3; i2++) {
        beta1 = t + twidth * (0.25 + 0.25 * (real_T)i2);
        toutnew[i2] = beta1;
        tref[i2] = beta1;
      }

      toutnew[3] = tnew;
      b_st.site = &r_emlrtRSI;
      ntrp45(tref, t, y_data, y_size, tnew - t, f_data, b_varargin_1_data,
             b_varargin_1_size);
      b_st.site = &r_emlrtRSI;
      c_st.site = &dc_emlrtRSI;
      if (!(b_varargin_1_size[0] == 0)) {
        Bcolidx = b_varargin_1_size[0];
      } else {
        Bcolidx = 6;
      }

      d_st.site = &ec_emlrtRSI;
      if ((b_varargin_1_size[0] == Bcolidx) || (b_varargin_1_size[0] == 0)) {
        empty_non_axis_sizes = true;
      } else {
        empty_non_axis_sizes = false;
        emlrtErrorWithMessageIdR2018a(&d_st, &r_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if (6 != Bcolidx) {
        empty_non_axis_sizes = false;
      }

      if (!empty_non_axis_sizes) {
        emlrtErrorWithMessageIdR2018a(&d_st, &r_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      empty_non_axis_sizes = (Bcolidx == 0);
      if (empty_non_axis_sizes || (!(b_varargin_1_size[0] == 0))) {
        j = 3;
      } else {
        j = 0;
      }

      i2 = result->size[0] * result->size[1];
      result->size[0] = Bcolidx;
      result->size[1] = j + 1;
      emxEnsureCapacity_real_T(&c_st, result, i2, &j_emlrtRTEI);
      for (i2 = 0; i2 < j; i2++) {
        for (i3 = 0; i3 < Bcolidx; i3++) {
          result->data[i3 + result->size[0] * i2] = b_varargin_1_data[i3 +
            Bcolidx * i2];
        }
      }

      for (i2 = 0; i2 < 1; i2++) {
        for (i3 = 0; i3 < Bcolidx; i3++) {
          result->data[i3 + result->size[0] * (i2 + j)] = ystage_data[i3 +
            Bcolidx * i2];
        }
      }

      nout += 4;
      if (nout > tout->size[1]) {
        Bcolidx = tout->size[1];
        i2 = tout->size[0] * tout->size[1];
        tout->size[1] = Bcolidx + 200;
        emxEnsureCapacity_real_T(&st, tout, i2, &k_emlrtRTEI);
        for (i2 = 0; i2 < 200; i2++) {
          tout->data[Bcolidx + i2] = 0.0;
        }

        b_st.site = &q_emlrtRSI;
        c_st.site = &dc_emlrtRSI;
        d_st.site = &ec_emlrtRSI;
        Bcolidx = yout->size[1];
        i2 = b_yout->size[0] * b_yout->size[1];
        b_yout->size[0] = 6;
        b_yout->size[1] = Bcolidx + 200;
        emxEnsureCapacity_real_T(&c_st, b_yout, i2, &l_emlrtRTEI);
        for (i2 = 0; i2 < Bcolidx; i2++) {
          for (i3 = 0; i3 < 6; i3++) {
            b_yout->data[i3 + b_yout->size[0] * i2] = yout->data[i3 + 6 * i2];
          }
        }

        for (i2 = 0; i2 < 200; i2++) {
          for (i3 = 0; i3 < 6; i3++) {
            b_yout->data[i3 + b_yout->size[0] * (i2 + Bcolidx)] = 0.0;
          }
        }

        i2 = yout->size[0] * yout->size[1];
        yout->size[0] = 6;
        yout->size[1] = b_yout->size[1];
        emxEnsureCapacity_real_T(&c_st, yout, i2, &m_emlrtRTEI);
        Bcolidx = b_yout->size[1];
        for (i2 = 0; i2 < Bcolidx; i2++) {
          for (i3 = 0; i3 < 6; i3++) {
            yout->data[i3 + yout->size[0] * i2] = b_yout->data[i3 + b_yout->
              size[0] * i2];
          }
        }
      }

      for (Bcolidx = 0; Bcolidx < 4; Bcolidx++) {
        tout->data[Bcolidx + outidx] = toutnew[Bcolidx];
        for (j = 0; j < 6; j++) {
          yout->data[j + yout->size[0] * (Bcolidx + outidx)] = result->data[j +
            result->size[0] * Bcolidx];
        }
      }

      if (Done) {
        exitg2 = 1;
      } else {
        if (NoFailedAttempts) {
          twidth = err / 0.001;
          b_st.site = &p_emlrtRSI;
          c_st.site = &nb_emlrtRSI;
          d_st.site = &ob_emlrtRSI;
          if (twidth < 0.0) {
            e_st.site = &pb_emlrtRSI;
            error(&e_st);
          }

          twidth = 1.25 * muDoubleScalarPower(twidth, 0.2);
          if (twidth > 0.2) {
            absh /= twidth;
          } else {
            absh *= 5.0;
          }
        }

        t = tnew;
        y_size[0] = 6;
        memcpy(&y_data[0], &ystage_data[0], (uint32_T)(6 * (int32_T)sizeof
                (real_T)));
        for (i2 = 0; i2 < 6; i2++) {
          f_data[i2] = f_data[i2 + 36];
        }
      }
    }
  } while (exitg2 == 0);

  emxFree_real_T(&st, &b_yout);
  emxFree_real_T(&st, &result);
  if (1 > nout) {
    Bcolidx = 0;
  } else {
    Bcolidx = nout;
  }

  i2 = varargout_1->size[0];
  varargout_1->size[0] = Bcolidx;
  emxEnsureCapacity_real_T1(&st, varargout_1, i2, &h_emlrtRTEI);
  for (i2 = 0; i2 < Bcolidx; i2++) {
    varargout_1->data[i2] = tout->data[i2];
  }

  emxFree_real_T(&st, &tout);
  if (1 > nout) {
    Bcolidx = 0;
  } else {
    Bcolidx = nout;
  }

  i2 = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = Bcolidx;
  varargout_2->size[1] = 6;
  emxEnsureCapacity_real_T(&st, varargout_2, i2, &i_emlrtRTEI);
  for (i2 = 0; i2 < 6; i2++) {
    for (i3 = 0; i3 < Bcolidx; i3++) {
      varargout_2->data[i3 + varargout_2->size[0] * i2] = yout->data[i2 +
        yout->size[0] * i3];
    }
  }

  emxFree_real_T(&st, &yout);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ode45.c) */
