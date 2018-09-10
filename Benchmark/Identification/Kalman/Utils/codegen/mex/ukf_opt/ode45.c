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
#include "ukf_opt.h"
#include "ode45.h"
#include "eps.h"
#include "ukf_opt_emxutil.h"
#include "error.h"
#include "ntrp45.h"
#include "warning.h"
#include "norm.h"
#include "ode2345.h"
#include "propagate_RRR_Additive.h"
#include "abs.h"
#include "ukf_opt_mexutil.h"
#include "ukf_opt_data.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 61,  /* lineNo */
  "power",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 57, /* lineNo */
  "xgemv",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/xgemv.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 17, /* lineNo */
  "ode45",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/ode45.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 515,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 454,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 379,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 366,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 369,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 368,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 338,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 336,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 327,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 325,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 308,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 273,/* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 82, /* lineNo */
  "ode2345",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 11, /* lineNo */
  "callODEFunctionNSM",                /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/callODEFunctionNSM.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 37, /* lineNo */
  "function_handle",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/function_handle.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 58, /* lineNo */
  "xgemv",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+refblas/xgemv.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 15, /* lineNo */
  "num2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/num2str.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 53,/* lineNo */
  27,                                  /* colNo */
  "flt2str",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 1, /* lineNo */
  56,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 214,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 215,/* lineNo */
  5,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 539,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 540,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 1, /* lineNo */
  22,                                  /* colNo */
  "ode45",                             /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/ode45.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 303,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 454,/* lineNo */
  17,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 49,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 268,/* lineNo */
  15,                                  /* colNo */
  "ode2345",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/funfun/private/ode2345.m"/* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[23]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[23]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[23]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[23])
{
  q_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  emlrtAssertMATLABThread(sp, &c_emlrtRTEI);
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2] = { 1, 23 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

void ode45(const emlrtStack *sp, const cell_wrap_2 ode_tunableEnvironment[2],
           const real_T tspan[2], const real_T b_y0[6], emxArray_real_T
           *varargout_1, emxArray_real_T *varargout_2)
{
  real_T tfinal;
  emxArray_real_T *tout;
  real_T f0[6];
  int32_T iac;
  emxArray_real_T *yout;
  int32_T nout;
  real_T twidth;
  real_T hmax;
  real_T hmin;
  real_T absh;
  real_T ystage[6];
  int32_T i;
  real_T ynew[6];
  real_T t;
  real_T f[42];
  real_T y[6];
  real_T tdir;
  boolean_T MinStepExit;
  boolean_T Done;
  emxArray_real_T *b_yout;
  int32_T exitg1;
  boolean_T NoFailedAttempts;
  int32_T exitg2;
  int32_T Bcolidx;
  int32_T j;
  real_T tnew;
  int32_T c;
  real_T b_c;
  static const real_T x[21] = { 0.2, 0.075, 0.225, 0.97777777777777775,
    -3.7333333333333334, 3.5555555555555554, 2.9525986892242035,
    -11.595793324188385, 9.8228928516994358, -0.29080932784636487,
    2.8462752525252526, -10.757575757575758, 8.9064227177434727,
    0.27840909090909088, -0.2735313036020583, 0.091145833333333329, 0.0,
    0.44923629829290207, 0.65104166666666663, -0.322376179245283,
    0.13095238095238096 };

  int32_T iy;
  int32_T ia;
  real_T err;
  static const real_T b[7] = { 0.0012326388888888888, 0.0,
    -0.0042527702905061394, 0.036979166666666667, -0.05086379716981132,
    0.0419047619047619, -0.025 };

  const mxArray *b_y;
  const mxArray *m3;
  static const int32_T iv4[2] = { 1, 7 };

  static const char_T rfmt[7] = { '%', '2', '3', '.', '1', '5', 'e' };

  real_T toutnew[4];
  const mxArray *c_y;
  real_T tref[3];
  real_T dv0[18];
  char_T cv2[23];
  real_T youtnew[24];
  static const int32_T iv5[2] = { 1, 7 };

  char_T cv3[23];
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
  st.site = &ad_emlrtRSI;
  tfinal = tspan[1];
  if (tspan[0] == tspan[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
      "MATLAB:odearguments:TspanEndpointsNotDistinct",
      "MATLAB:odearguments:TspanEndpointsNotDistinct", 0);
  }

  if (!ismonotonic(tspan)) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
      "MATLAB:odearguments:TspanNotMonotonic",
      "MATLAB:odearguments:TspanNotMonotonic", 0);
  }

  emxInit_real_T1(&st, &tout, 2, &e_emlrtRTEI, true);
  b_st.site = &nd_emlrtRSI;
  c_st.site = &od_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  __anon_fcn(&d_st, ode_tunableEnvironment[0].f1.data, ode_tunableEnvironment[0]
             .f1.size, ode_tunableEnvironment[1].f1.data,
             ode_tunableEnvironment[1].f1.size, b_y0, f0);
  iac = tout->size[0] * tout->size[1];
  tout->size[0] = 1;
  tout->size[1] = 200;
  emxEnsureCapacity_real_T(&st, tout, iac, &e_emlrtRTEI);
  for (iac = 0; iac < 200; iac++) {
    tout->data[iac] = 0.0;
  }

  emxInit_real_T1(&st, &yout, 2, &f_emlrtRTEI, true);
  iac = yout->size[0] * yout->size[1];
  yout->size[0] = 6;
  yout->size[1] = 200;
  emxEnsureCapacity_real_T(&st, yout, iac, &f_emlrtRTEI);
  for (iac = 0; iac < 1200; iac++) {
    yout->data[iac] = 0.0;
  }

  nout = 1;
  tout->data[0] = tspan[0];
  for (iac = 0; iac < 6; iac++) {
    yout->data[iac] = b_y0[iac];
  }

  twidth = muDoubleScalarAbs(tspan[1] - tspan[0]);
  hmax = muDoubleScalarMin(twidth, muDoubleScalarMax(0.1 * twidth,
    3.5527136788005009E-15 * muDoubleScalarMax(muDoubleScalarAbs(tspan[0]),
    muDoubleScalarAbs(tspan[1]))));
  if (!(hmax > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
      "MATLAB:odearguments:MaxStepLEzero", "MATLAB:odearguments:MaxStepLEzero",
      0);
  }

  b_st.site = &md_emlrtRSI;
  hmin = 16.0 * eps(tspan[0]);
  absh = muDoubleScalarMin(hmax, muDoubleScalarAbs(tspan[1] - tspan[0]));
  b_abs(b_y0, ystage);
  for (i = 0; i < 6; i++) {
    ynew[i] = f0[i] / muDoubleScalarMax(ystage[i], 0.01);
  }

  twidth = norm(ynew) / 0.31848573644279776;
  if (absh * twidth > 1.0) {
    absh = 1.0 / twidth;
  }

  absh = muDoubleScalarMax(absh, hmin);
  t = tspan[0];
  for (i = 0; i < 6; i++) {
    y[i] = b_y0[i];
  }

  memset(&f[0], 0, 42U * sizeof(real_T));
  for (iac = 0; iac < 6; iac++) {
    f[iac] = f0[iac];
  }

  tdir = muDoubleScalarSign(tspan[1] - tspan[0]);
  MinStepExit = false;
  Done = false;
  emxInit_real_T1(&st, &b_yout, 2, &j_emlrtRTEI, true);
  do {
    exitg1 = 0;
    b_st.site = &ld_emlrtRSI;
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
      Bcolidx = 5;
      for (j = 0; j < 5; j++) {
        Bcolidx += j;
        b_st.site = &kd_emlrtRSI;
        for (i = 0; i < 6; i++) {
          ystage[i] = y[i];
        }

        c_st.site = &ob_emlrtRSI;
        if (!(twidth == 0.0)) {
          i = Bcolidx + 1;
          c = 6 * j;
          for (iac = 1; iac <= c + 1; iac += 6) {
            b_c = twidth * x[i - 6];
            iy = 0;
            d_st.site = &ae_emlrtRSI;
            for (ia = iac; ia <= iac + 5; ia++) {
              ystage[iy] += f[ia - 1] * b_c;
              iy++;
            }

            i++;
          }
        }

        b_st.site = &jd_emlrtRSI;
        c_st.site = &od_emlrtRSI;
        d_st.site = &pd_emlrtRSI;
        __anon_fcn(&d_st, ode_tunableEnvironment[0].f1.data,
                   ode_tunableEnvironment[0].f1.size, ode_tunableEnvironment[1].
                   f1.data, ode_tunableEnvironment[1].f1.size, ystage, *(real_T
                    (*)[6])&f[6 * (j + 1)]);
      }

      tnew = t + twidth;
      if (Done) {
        tnew = tfinal;
      }

      b_st.site = &id_emlrtRSI;
      for (i = 0; i < 6; i++) {
        ynew[i] = y[i];
      }

      c_st.site = &ob_emlrtRSI;
      if (!(twidth == 0.0)) {
        for (iac = 0; iac <= 31; iac += 6) {
          b_c = twidth * x[Bcolidx];
          iy = 0;
          d_st.site = &ae_emlrtRSI;
          for (ia = iac; ia < iac + 6; ia++) {
            ynew[iy] += f[ia] * b_c;
            iy++;
          }

          Bcolidx++;
        }
      }

      b_st.site = &hd_emlrtRSI;
      c_st.site = &od_emlrtRSI;
      d_st.site = &pd_emlrtRSI;
      __anon_fcn(&d_st, ode_tunableEnvironment[0].f1.data,
                 ode_tunableEnvironment[0].f1.size, ode_tunableEnvironment[1].
                 f1.data, ode_tunableEnvironment[1].f1.size, ynew, ystage);
      for (iac = 0; iac < 6; iac++) {
        f[36 + iac] = ystage[iac];
      }

      maxAbsThresh(y, ynew, ystage);
      for (iac = 0; iac < 6; iac++) {
        twidth = 0.0;
        for (c = 0; c < 7; c++) {
          twidth += f[iac + 6 * c] * b[c];
        }

        f0[iac] = twidth / ystage[iac];
      }

      err = absh * norm(f0);
      if (err > 0.01) {
        if (absh <= hmin) {
          b_st.site = &gd_emlrtRSI;
          c_st.site = &be_emlrtRSI;
          emlrtAssertMATLABThread(&c_st, &b_emlrtRTEI);
          b_y = NULL;
          m3 = emlrtCreateCharArray(2, iv4);
          emlrtInitCharArrayR2013a(&c_st, 7, m3, &rfmt[0]);
          emlrtAssign(&b_y, m3);
          c_y = NULL;
          m3 = emlrtCreateDoubleScalar(t);
          emlrtAssign(&c_y, m3);
          d_st.site = &uf_emlrtRSI;
          emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, c_y, &e_emlrtMCI),
                           "sprintf", cv2);
          b_st.site = &fd_emlrtRSI;
          c_st.site = &be_emlrtRSI;
          emlrtAssertMATLABThread(&c_st, &b_emlrtRTEI);
          b_y = NULL;
          m3 = emlrtCreateCharArray(2, iv5);
          emlrtInitCharArrayR2013a(&c_st, 7, m3, &rfmt[0]);
          emlrtAssign(&b_y, m3);
          c_y = NULL;
          m3 = emlrtCreateDoubleScalar(hmin);
          emlrtAssign(&c_y, m3);
          d_st.site = &uf_emlrtRSI;
          emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, c_y, &e_emlrtMCI),
                           "sprintf", cv3);
          b_st.site = &ed_emlrtRSI;
          b_warning(&b_st, cv2, cv3);
          MinStepExit = true;
          exitg2 = 1;
        } else {
          if (NoFailedAttempts) {
            NoFailedAttempts = false;
            b_st.site = &dd_emlrtRSI;
            c_st.site = &u_emlrtRSI;
            d_st.site = &v_emlrtRSI;
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
      iy = nout;
      twidth = tnew - t;
      for (iac = 0; iac < 3; iac++) {
        b_c = t + twidth * (0.25 + 0.25 * (real_T)iac);
        toutnew[iac] = b_c;
        tref[iac] = b_c;
      }

      toutnew[3] = tnew;
      ntrp45(tref, t, y, tnew - t, f, dv0);
      for (iac = 0; iac < 3; iac++) {
        for (c = 0; c < 6; c++) {
          youtnew[c + 6 * iac] = dv0[c + 6 * iac];
        }
      }

      for (iac = 0; iac < 6; iac++) {
        youtnew[18 + iac] = ynew[iac];
      }

      nout += 4;
      if (nout > tout->size[1]) {
        i = tout->size[1];
        iac = tout->size[0] * tout->size[1];
        tout->size[1] = i + 200;
        emxEnsureCapacity_real_T(&st, tout, iac, &i_emlrtRTEI);
        for (iac = 0; iac < 200; iac++) {
          tout->data[i + iac] = 0.0;
        }

        b_st.site = &cd_emlrtRSI;
        c_st.site = &uc_emlrtRSI;
        d_st.site = &vc_emlrtRSI;
        i = yout->size[1];
        iac = b_yout->size[0] * b_yout->size[1];
        b_yout->size[0] = 6;
        b_yout->size[1] = i + 200;
        emxEnsureCapacity_real_T(&c_st, b_yout, iac, &j_emlrtRTEI);
        for (iac = 0; iac < i; iac++) {
          for (c = 0; c < 6; c++) {
            b_yout->data[c + b_yout->size[0] * iac] = yout->data[c + 6 * iac];
          }
        }

        for (iac = 0; iac < 200; iac++) {
          for (c = 0; c < 6; c++) {
            b_yout->data[c + b_yout->size[0] * (iac + i)] = 0.0;
          }
        }

        iac = yout->size[0] * yout->size[1];
        yout->size[0] = 6;
        yout->size[1] = b_yout->size[1];
        emxEnsureCapacity_real_T(&c_st, yout, iac, &k_emlrtRTEI);
        i = b_yout->size[1];
        for (iac = 0; iac < i; iac++) {
          for (c = 0; c < 6; c++) {
            yout->data[c + yout->size[0] * iac] = b_yout->data[c + b_yout->size
              [0] * iac];
          }
        }
      }

      for (i = 0; i < 4; i++) {
        tout->data[i + iy] = toutnew[i];
        for (j = 0; j < 6; j++) {
          yout->data[j + yout->size[0] * (i + iy)] = youtnew[j + 6 * i];
        }
      }

      if (Done) {
        exitg1 = 1;
      } else {
        if (NoFailedAttempts) {
          twidth = err / 0.01;
          b_st.site = &bd_emlrtRSI;
          c_st.site = &u_emlrtRSI;
          d_st.site = &v_emlrtRSI;
          if (twidth < 0.0) {
            e_st.site = &w_emlrtRSI;
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

  iac = varargout_1->size[0];
  varargout_1->size[0] = i;
  emxEnsureCapacity_real_T1(&st, varargout_1, iac, &g_emlrtRTEI);
  for (iac = 0; iac < i; iac++) {
    varargout_1->data[iac] = tout->data[iac];
  }

  emxFree_real_T(&st, &tout);
  if (1 > nout) {
    i = 0;
  } else {
    i = nout;
  }

  iac = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = i;
  varargout_2->size[1] = 6;
  emxEnsureCapacity_real_T(&st, varargout_2, iac, &h_emlrtRTEI);
  for (iac = 0; iac < 6; iac++) {
    for (c = 0; c < i; c++) {
      varargout_2->data[c + varargout_2->size[0] * iac] = yout->data[iac +
        yout->size[0] * c];
    }
  }

  emxFree_real_T(&st, &yout);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ode45.c) */
