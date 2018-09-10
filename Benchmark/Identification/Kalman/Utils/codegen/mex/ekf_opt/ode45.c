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
#include "ekf_opt.h"
#include "ode45.h"
#include "eps.h"
#include "ekf_opt_emxutil.h"
#include "error.h"
#include "ntrp45.h"
#include "warning.h"
#include "norm.h"
#include "ode2345.h"
#include "propagate_RRR_Additive.h"
#include "xgemv.h"

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = { 17,  /* lineNo */
  "ode45",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/ode45.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 515, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 454, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 379, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 366, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 369, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 368, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 338, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 327, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 308, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 273, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 82,  /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 11,  /* lineNo */
  "callODEFunctionNSM",                /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/callODEFunctionNSM.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 37, /* lineNo */
  "function_handle",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/function_handle.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 40, /* lineNo */
  "mpower",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 15, /* lineNo */
  "num2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/num2str.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 25, /* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 53,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 214,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 215,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 539,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 540,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 1, /* lineNo */
  22,                                  /* colNo */
  "ode45",                             /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/ode45.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 303,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 454,/* lineNo */
  17,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 49,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 268,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRSInfo wc_emlrtRSI = { 53, /* lineNo */
  "flt2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[23]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[23]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[23]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[23])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m10;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m10, 2, pArrays, "sprintf", true,
    location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2] = { 1, 23 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

void ode45(const emlrtStack *sp, const cell_wrap_1 ode_tunableEnvironment[2],
           const real_T tspan[2], const real_T b_y0[6], emxArray_real_T
           *varargout_1, emxArray_real_T *varargout_2)
{
  real_T tfinal;
  boolean_T MinStepExit;
  emxArray_real_T *tout;
  real_T f0[6];
  int32_T j;
  emxArray_real_T *yout;
  int32_T nout;
  real_T twidth;
  real_T hmax;
  real_T hmin;
  real_T absh;
  int32_T i;
  real_T y[6];
  real_T t;
  real_T f[42];
  real_T tdir;
  boolean_T Done;
  emxArray_real_T *b_yout;
  int32_T exitg1;
  boolean_T NoFailedAttempts;
  int32_T exitg2;
  int32_T Bcolidx;
  real_T tnew;
  real_T ynew[6];
  real_T err;
  real_T b_f[6];
  static const real_T b[7] = { 0.0012326388888888888, 0.0,
    -0.0042527702905061394, 0.036979166666666667, -0.05086379716981132,
    0.0419047619047619, -0.025 };

  const mxArray *b_y;
  int32_T outidx;
  const mxArray *m0;
  static const int32_T iv2[2] = { 1, 7 };

  static const char_T rfmt[7] = { '%', '2', '3', '.', '1', '5', 'e' };

  const mxArray *c_y;
  real_T toutnew[4];
  real_T tref[3];
  real_T dv1[18];
  char_T cv0[23];
  real_T youtnew[24];
  static const int32_T iv3[2] = { 1, 7 };

  char_T cv1[23];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
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
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &m_emlrtRSI;
  tfinal = tspan[1];
  if (tspan[0] == tspan[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
      "MATLAB:odearguments:TspanEndpointsNotDistinct",
      "MATLAB:odearguments:TspanEndpointsNotDistinct", 0);
  }

  MinStepExit = true;
  if ((!(tspan[1] > tspan[0])) && (!(tspan[0] > tspan[1]))) {
    MinStepExit = false;
  }

  if (!MinStepExit) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
      "MATLAB:odearguments:TspanNotMonotonic",
      "MATLAB:odearguments:TspanNotMonotonic", 0);
  }

  emxInit_real_T1(&st, &tout, 2, &b_emlrtRTEI, true);
  b_st.site = &x_emlrtRSI;
  c_st.site = &y_emlrtRSI;
  d_st.site = &ab_emlrtRSI;
  __anon_fcn(&d_st, ode_tunableEnvironment[0].f1.data, ode_tunableEnvironment[0]
             .f1.size, ode_tunableEnvironment[1].f1.data,
             ode_tunableEnvironment[1].f1.size, b_y0, f0);
  j = tout->size[0] * tout->size[1];
  tout->size[0] = 1;
  tout->size[1] = 200;
  emxEnsureCapacity_real_T(&st, tout, j, &b_emlrtRTEI);
  for (j = 0; j < 200; j++) {
    tout->data[j] = 0.0;
  }

  emxInit_real_T1(&st, &yout, 2, &c_emlrtRTEI, true);
  j = yout->size[0] * yout->size[1];
  yout->size[0] = 6;
  yout->size[1] = 200;
  emxEnsureCapacity_real_T(&st, yout, j, &c_emlrtRTEI);
  for (j = 0; j < 1200; j++) {
    yout->data[j] = 0.0;
  }

  nout = 1;
  tout->data[0] = tspan[0];
  for (j = 0; j < 6; j++) {
    yout->data[j] = b_y0[j];
  }

  twidth = muDoubleScalarAbs(tspan[1] - tspan[0]);
  hmax = muDoubleScalarMin(twidth, muDoubleScalarMax(0.1 * twidth,
    3.5527136788005009E-15 * muDoubleScalarMax(muDoubleScalarAbs(tspan[0]),
    muDoubleScalarAbs(tspan[1]))));
  if (!(hmax > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &n_emlrtRTEI,
      "MATLAB:odearguments:MaxStepLEzero", "MATLAB:odearguments:MaxStepLEzero",
      0);
  }

  b_st.site = &w_emlrtRSI;
  hmin = 16.0 * eps(tspan[0]);
  absh = muDoubleScalarMin(hmax, muDoubleScalarAbs(tspan[1] - tspan[0]));
  for (i = 0; i < 6; i++) {
    y[i] = f0[i] / muDoubleScalarMax(muDoubleScalarAbs(b_y0[i]), 0.01);
  }

  twidth = norm(y) / 0.31848573644279776;
  if (absh * twidth > 1.0) {
    absh = 1.0 / twidth;
  }

  absh = muDoubleScalarMax(absh, hmin);
  t = tspan[0];
  for (i = 0; i < 6; i++) {
    y[i] = b_y0[i];
  }

  memset(&f[0], 0, 42U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    f[j] = f0[j];
  }

  tdir = muDoubleScalarSign(tspan[1] - tspan[0]);
  MinStepExit = false;
  Done = false;
  emxInit_real_T1(&st, &b_yout, 2, &g_emlrtRTEI, true);
  do {
    exitg1 = 0;
    b_st.site = &v_emlrtRSI;
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
      exitg2 = 0;
      Bcolidx = 1;
      for (j = 0; j < 5; j++) {
        Bcolidx += j;
        b_st.site = &u_emlrtRSI;
        c_st.site = &y_emlrtRSI;
        for (i = 0; i < 6; i++) {
          f0[i] = y[i];
        }

        xgemv(j + 1, twidth, f, Bcolidx, f0);
        d_st.site = &ab_emlrtRSI;
        __anon_fcn(&d_st, ode_tunableEnvironment[0].f1.data,
                   ode_tunableEnvironment[0].f1.size, ode_tunableEnvironment[1].
                   f1.data, ode_tunableEnvironment[1].f1.size, f0, *(real_T (*)
                    [6])&f[6 * (j + 1)]);
      }

      tnew = t + twidth;
      if (Done) {
        tnew = tfinal;
      }

      for (i = 0; i < 6; i++) {
        ynew[i] = y[i];
      }

      b_xgemv(twidth, f, Bcolidx + 5, ynew);
      b_st.site = &t_emlrtRSI;
      c_st.site = &y_emlrtRSI;
      d_st.site = &ab_emlrtRSI;
      __anon_fcn(&d_st, ode_tunableEnvironment[0].f1.data,
                 ode_tunableEnvironment[0].f1.size, ode_tunableEnvironment[1].
                 f1.data, ode_tunableEnvironment[1].f1.size, ynew, f0);
      for (j = 0; j < 6; j++) {
        f[36 + j] = f0[j];
      }

      maxAbsThresh(y, ynew, f0);
      for (j = 0; j < 6; j++) {
        twidth = 0.0;
        for (Bcolidx = 0; Bcolidx < 7; Bcolidx++) {
          twidth += f[j + 6 * Bcolidx] * b[Bcolidx];
        }

        b_f[j] = twidth / f0[j];
      }

      err = absh * norm(b_f);
      if (err > 0.01) {
        if (absh <= hmin) {
          b_st.site = &s_emlrtRSI;
          c_st.site = &nb_emlrtRSI;
          b_y = NULL;
          m0 = emlrtCreateCharArray(2, iv2);
          emlrtInitCharArrayR2013a(&c_st, 7, m0, &rfmt[0]);
          emlrtAssign(&b_y, m0);
          c_y = NULL;
          m0 = emlrtCreateDoubleScalar(t);
          emlrtAssign(&c_y, m0);
          d_st.site = &wc_emlrtRSI;
          emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, c_y, &c_emlrtMCI),
                           "sprintf", cv0);
          b_st.site = &r_emlrtRSI;
          c_st.site = &nb_emlrtRSI;
          b_y = NULL;
          m0 = emlrtCreateCharArray(2, iv3);
          emlrtInitCharArrayR2013a(&c_st, 7, m0, &rfmt[0]);
          emlrtAssign(&b_y, m0);
          c_y = NULL;
          m0 = emlrtCreateDoubleScalar(hmin);
          emlrtAssign(&c_y, m0);
          d_st.site = &wc_emlrtRSI;
          emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, c_y, &c_emlrtMCI),
                           "sprintf", cv1);
          b_st.site = &q_emlrtRSI;
          b_warning(&b_st, cv0, cv1);
          MinStepExit = true;
          exitg2 = 1;
        } else {
          if (NoFailedAttempts) {
            NoFailedAttempts = false;
            b_st.site = &p_emlrtRSI;
            c_st.site = &kb_emlrtRSI;
            d_st.site = &lb_emlrtRSI;
            absh = muDoubleScalarMax(hmin, absh * muDoubleScalarMax(0.1, 0.8 *
              muDoubleScalarPower(0.01 / err, 0.2)));
          } else {
            absh = muDoubleScalarMax(hmin, 0.5 * absh);
          }

          twidth = tdir * absh;
          Done = false;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (MinStepExit) {
      exitg1 = 1;
    } else {
      outidx = nout;
      twidth = tnew - t;
      for (j = 0; j < 3; j++) {
        hmin = t + twidth * (0.25 + 0.25 * (real_T)j);
        toutnew[j] = hmin;
        tref[j] = hmin;
      }

      toutnew[3] = tnew;
      ntrp45(tref, t, y, tnew - t, f, dv1);
      for (j = 0; j < 3; j++) {
        for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
          youtnew[Bcolidx + 6 * j] = dv1[Bcolidx + 6 * j];
        }
      }

      for (j = 0; j < 6; j++) {
        youtnew[18 + j] = ynew[j];
      }

      nout += 4;
      if (nout > tout->size[1]) {
        i = tout->size[1];
        j = tout->size[0] * tout->size[1];
        tout->size[1] = i + 200;
        emxEnsureCapacity_real_T(&st, tout, j, &f_emlrtRTEI);
        for (j = 0; j < 200; j++) {
          tout->data[i + j] = 0.0;
        }

        b_st.site = &o_emlrtRSI;
        c_st.site = &ob_emlrtRSI;
        d_st.site = &pb_emlrtRSI;
        i = yout->size[1];
        j = b_yout->size[0] * b_yout->size[1];
        b_yout->size[0] = 6;
        b_yout->size[1] = i + 200;
        emxEnsureCapacity_real_T(&c_st, b_yout, j, &g_emlrtRTEI);
        for (j = 0; j < i; j++) {
          for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
            b_yout->data[Bcolidx + b_yout->size[0] * j] = yout->data[Bcolidx + 6
              * j];
          }
        }

        for (j = 0; j < 200; j++) {
          for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
            b_yout->data[Bcolidx + b_yout->size[0] * (j + i)] = 0.0;
          }
        }

        j = yout->size[0] * yout->size[1];
        yout->size[0] = 6;
        yout->size[1] = b_yout->size[1];
        emxEnsureCapacity_real_T(&c_st, yout, j, &h_emlrtRTEI);
        i = b_yout->size[1];
        for (j = 0; j < i; j++) {
          for (Bcolidx = 0; Bcolidx < 6; Bcolidx++) {
            yout->data[Bcolidx + yout->size[0] * j] = b_yout->data[Bcolidx +
              b_yout->size[0] * j];
          }
        }
      }

      for (i = 0; i < 4; i++) {
        tout->data[i + outidx] = toutnew[i];
        for (j = 0; j < 6; j++) {
          yout->data[j + yout->size[0] * (i + outidx)] = youtnew[j + 6 * i];
        }
      }

      if (Done) {
        exitg1 = 1;
      } else {
        if (NoFailedAttempts) {
          twidth = err / 0.01;
          b_st.site = &n_emlrtRSI;
          c_st.site = &kb_emlrtRSI;
          d_st.site = &lb_emlrtRSI;
          if (twidth < 0.0) {
            e_st.site = &mb_emlrtRSI;
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
        for (i = 0; i < 6; i++) {
          y[i] = ynew[i];
          f[i] = f[36 + i];
        }
      }
    }
  } while (exitg1 == 0);

  emxFree_real_T(&st, &b_yout);
  if (1 > nout) {
    i = 0;
  } else {
    i = nout;
  }

  j = varargout_1->size[0];
  varargout_1->size[0] = i;
  emxEnsureCapacity_real_T1(&st, varargout_1, j, &d_emlrtRTEI);
  for (j = 0; j < i; j++) {
    varargout_1->data[j] = tout->data[j];
  }

  emxFree_real_T(&st, &tout);
  if (1 > nout) {
    i = 0;
  } else {
    i = nout;
  }

  j = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = i;
  varargout_2->size[1] = 6;
  emxEnsureCapacity_real_T(&st, varargout_2, j, &e_emlrtRTEI);
  for (j = 0; j < 6; j++) {
    for (Bcolidx = 0; Bcolidx < i; Bcolidx++) {
      varargout_2->data[Bcolidx + varargout_2->size[0] * j] = yout->data[j +
        yout->size[0] * Bcolidx];
    }
  }

  emxFree_real_T(&st, &yout);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ode45.c) */
