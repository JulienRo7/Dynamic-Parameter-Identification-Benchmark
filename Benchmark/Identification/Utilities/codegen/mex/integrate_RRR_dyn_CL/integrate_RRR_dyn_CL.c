/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * integrate_RRR_dyn_CL.c
 *
 * Code generation for function 'integrate_RRR_dyn_CL'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "integrate_RRR_dyn_CL_emxutil.h"
#include "ode45.h"
#include "RRR_dyn_CL.h"
#include "integrate_RRR_dyn_CL_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 5,     /* lineNo */
  "integrate_RRR_dyn_CL",              /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 19,  /* lineNo */
  "integrate_RRR_dyn_CL",              /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 22,  /* lineNo */
  "integrate_RRR_dyn_CL",              /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 5,   /* lineNo */
  5,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 8, /* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 1, /* lineNo */
  24,                                  /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 18,/* lineNo */
  9,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  5,                                   /* colNo */
  "X",                                 /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  13,                                  /* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  22,                                  /* lineNo */
  23,                                  /* colNo */
  "X",                                 /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  59,                                  /* colNo */
  "t",                                 /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  66,                                  /* colNo */
  "t",                                 /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  75,                                  /* colNo */
  "X",                                 /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "Y_i",                               /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  9,                                   /* colNo */
  "X",                                 /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  27,                                  /* lineNo */
  5,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m"/* pName */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  11,                                  /* colNo */
  "Qpp",                               /* aName */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  28,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  11,                                  /* colNo */
  "iDq",                               /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  24,                                  /* colNo */
  "iDq",                               /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  41,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  11,                                  /* colNo */
  "iDq",                               /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  17,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  18,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  40,                                  /* colNo */
  "iDq",                               /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 8,     /* lineNo */
  23,                                  /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 8,   /* lineNo */
  23,                                  /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 10,  /* lineNo */
  16,                                  /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 11,  /* lineNo */
  16,                                  /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 31,  /* lineNo */
  62,                                  /* colNo */
  "linspace",                          /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/linspace.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 8,   /* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 8,   /* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 10,  /* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 11,  /* lineNo */
  1,                                   /* colNo */
  "integrate_RRR_dyn_CL",              /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/integrate_RRR_dyn_CL.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  3,                                   /* lineNo */
  19,                                  /* colNo */
  "t",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  36,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  23,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  12,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  13,                                  /* colNo */
  "X",                                 /* aName */
  "controler_RRR",                     /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/controler_RRR.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void integrate_RRR_dyn_CL(const emlrtStack *sp, const real_T X_0_data[], const
  int32_T X_0_size[1], const real_T Theta_data[], const int32_T Theta_size[1],
  real_T t_0, real_T t_f, real_T N, emxArray_real_T *t, emxArray_real_T *X,
  emxArray_real_T *Qpp)
{
  real_T delta1;
  int32_T i0;
  real_T T;
  real_T delta2;
  int32_T i;
  emxArray_real_T *iDq;
  int8_T tmp_data[6];
  int32_T iv0[1];
  int32_T b_i;
  emxArray_real_T *unusedU0;
  emxArray_real_T *Y_i;
  int32_T c_tunableEnvironment_f2_size_id;
  int32_T loop_ub;
  real_T tunableEnvironment_f2_data[17];
  int32_T j;
  real_T Q[3];
  static const real_T dv1[3] = { 0.0, 1.5707963267948966, 0.1 };

  real_T Qp[3];
  real_T b_Qpp[3];
  real_T state[9];
  real_T Sojt;
  real_T Xd[6];
  static const real_T p[30] = { 1.0232, -1.3361, 1.4907, -0.0364, -1.1414,
    -0.0956, 0.5488, -0.3174, -0.789, 0.6212, 0.144, -1.3454, -0.4648, 0.4712,
    1.195, -0.5457, 1.7466, -0.9469, -0.0857, 0.0472, -0.896, 1.8578, 1.1808,
    -0.2942, -1.8484, 1.0053, -3.419, 1.9982, 0.4955, -0.4288 };

  real_T a[3];
  real_T b_a[3];
  static const int16_T c_a[9] = { -1000, 0, 0, 0, -1750, 0, 0, 0, -1750 };

  static const int16_T d_a[9] = { 400, 0, 0, 0, 750, 0, 0, 0, 750 };

  static const int16_T e_a[9] = { 100, 0, 0, 0, 400, 0, 0, 0, 400 };

  int32_T X_size[1];
  real_T X_data[6];
  int32_T t0_tunableEnvironment_f2_size[1];
  real_T t0_tunableEnvironment_f2_data[17];
  real_T b_t[2];
  int32_T b_X_size[1];
  int8_T i1;
  int32_T tmp_size[1];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  X = [Qp;Q] */
  st.site = &emlrtRSI;
  delta1 = N;
  if (N < 0.0) {
    delta1 = 0.0;
  }

  delta1 = muDoubleScalarFloor(delta1);
  if (!(delta1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(delta1, &e_emlrtDCI, &st);
  }

  i0 = t->size[0] * t->size[1];
  t->size[0] = 1;
  t->size[1] = (int32_T)delta1;
  emxEnsureCapacity_real_T(&st, t, i0, &emlrtRTEI);
  if (t->size[1] >= 1) {
    t->data[t->size[1] - 1] = t_f;
    if (t->size[1] >= 2) {
      t->data[0] = t_0;
      if (t->size[1] >= 3) {
        if (((t_0 < 0.0) != (t_f < 0.0)) && ((muDoubleScalarAbs(t_0) >
              8.9884656743115785E+307) || (muDoubleScalarAbs(t_f) >
              8.9884656743115785E+307))) {
          delta1 = t_0 / ((real_T)t->size[1] - 1.0);
          delta2 = t_f / ((real_T)t->size[1] - 1.0);
          i0 = t->size[1];
          for (i = 0; i <= i0 - 3; i++) {
            t->data[i + 1] = (t_0 + delta2 * (1.0 + (real_T)i)) - delta1 * (1.0
              + (real_T)i);
          }
        } else {
          delta1 = (t_f - t_0) / ((real_T)t->size[1] - 1.0);
          i0 = t->size[1];
          for (i = 0; i <= i0 - 3; i++) {
            t->data[i + 1] = t_0 + (1.0 + (real_T)i) * delta1;
          }
        }
      }
    }
  }

  /*  Sampling times */
  T = (t_f - t_0) / N;
  i0 = X->size[0] * X->size[1];
  X->size[0] = X_0_size[0];
  if (!(N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N, &b_emlrtDCI, sp);
  }

  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &emlrtDCI, sp);
  }

  X->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(sp, X, i0, &b_emlrtRTEI);
  if (!(N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N, &g_emlrtDCI, sp);
  }

  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &f_emlrtDCI, sp);
  }

  i = X_0_size[0] * (int32_T)N;
  for (i0 = 0; i0 < i; i0++) {
    X->data[i0] = 0.0;
  }

  emxInit_real_T(sp, &iDq, 2, &c_emlrtRTEI, true);

  /*  State of the robot: joint positions and joint velocities */
  i0 = iDq->size[0] * iDq->size[1];
  iDq->size[0] = 3;
  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &c_emlrtDCI, sp);
  }

  iDq->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(sp, iDq, i0, &c_emlrtRTEI);
  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &h_emlrtDCI, sp);
  }

  i = 3 * (int32_T)N;
  for (i0 = 0; i0 < i; i0++) {
    iDq->data[i0] = 0.0;
  }

  /*  integral of error in  position */
  i0 = Qpp->size[0] * Qpp->size[1];
  Qpp->size[0] = 3;
  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &d_emlrtDCI, sp);
  }

  Qpp->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(sp, Qpp, i0, &d_emlrtRTEI);
  if (N != (int32_T)muDoubleScalarFloor(N)) {
    emlrtIntegerCheckR2012b(N, &i_emlrtDCI, sp);
  }

  i = 3 * (int32_T)N;
  for (i0 = 0; i0 < i; i0++) {
    Qpp->data[i0] = 0.0;
  }

  i = (int8_T)X_0_size[0] - 1;
  for (i0 = 0; i0 <= i; i0++) {
    tmp_data[i0] = (int8_T)i0;
  }

  i0 = (int32_T)N;
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &emlrtBCI, sp);
  }

  iv0[0] = (int8_T)X_0_size[0];
  emlrtSubAssignSizeCheckR2012b(&iv0[0], 1, &X_0_size[0], 1, &emlrtECI, sp);
  i = (int8_T)X_0_size[0];
  for (i0 = 0; i0 < i; i0++) {
    X->data[tmp_data[i0]] = X_0_data[i0];
  }

  /*  opts = odeset('RelTol',1e-2,'AbsTol',1e-4); */
  emlrtForLoopVectorCheckR2012b(2.0, 1.0, N, mxDOUBLE_CLASS, (int32_T)(N + -1.0),
    &p_emlrtRTEI, sp);
  b_i = 0;
  emxInit_real_T1(sp, &unusedU0, 1, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &Y_i, 2, &e_emlrtRTEI, true);
  if (0 <= (int32_T)(N + -1.0) - 1) {
    c_tunableEnvironment_f2_size_id = Theta_size[0];
    i = Theta_size[0];
    loop_ub = Theta_size[0];
    if (0 <= i - 1) {
      memcpy(&tunableEnvironment_f2_data[0], &Theta_data[0], (uint32_T)(i *
              (int32_T)sizeof(real_T)));
    }
  }

  while (b_i <= (int32_T)(N + -1.0) - 1) {
    st.site = &b_emlrtRSI;
    i0 = t->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &q_emlrtBCI, &st);
    }

    delta1 = t->data[j - 1];

    /*  Generate a desired trajectory in the joint space for the RR robot  */
    /*  Dt = 1; */
    /*  omega_1= 1*2*pi/Dt; */
    /*  omega_2= 2*omega_1; */
    /*   */
    /*  if t <= Dt */
    /*      Q = [0; pi/2; 0]; */
    /*      Qp = zeros(3,1); */
    /*        */
    /*  elseif t>Dt && t <= 2*Dt */
    /*      Q = [0; pi/5; pi/5]; */
    /*      Qp = zeros(3,1); */
    /*   */
    /*  elseif t>2*Dt && t<=3*Dt */
    /*      Q = [pi/2; pi/5; pi/5]; */
    /*      Qp = zeros(3,1); */
    /*        */
    /*  elseif t>4*Dt && t <= 6*Dt */
    /*      Q = [-pi/2; -pi/5; -pi/5-pi/2]; */
    /*      Qp = zeros(3,1); */
    /*   */
    /*  elseif t > 6*Dt && t <= 10*Dt */
    /*      Q = [-pi/2 + (t-6*Dt)*pi/8; -pi/5 + (t-6*Dt)*(pi/2+pi/5)/4; -pi/5-pi/2 + (t-6*Dt)*(pi/5+pi/2)/4]; */
    /*      Qp = [pi/8; (pi/2+pi/5)/4; (pi/5+pi/2)/4]; */
    /*  else */
    /*      Q = [0; pi/2; 0]; */
    /*      Qp = zeros(3,1); */
    /*  end */
    /*  */
    /*  A1 = 3*pi/2; */
    /*  A2 = 4*pi/5; */
    /*  A3 = 4*pi/5; */
    /*   */
    /*  T1 = 10; */
    /*  T2 = 5; */
    /*  T3 = 3; */
    /*   */
    /*  f1 = 1/T1; */
    /*  f2 = 1/T2; */
    /*  f3 = 1/T3; */
    /*   */
    /*  Q  = [ A1 * sin(2*pi*f1*t);pi/2+A2 * sin(2*pi*f2*t); A3 * sin(2*pi*f3*t)]; */
    /*  Qp = [ 2*pi*f1*A1*cos(2*pi*f1*t);2*pi*f2*A2*cos(2*pi*f2*t); 2*pi*f3*A3 * cos(2*pi*f3*t)]; */
    /*  Q =  [-pi/2; 0; 0]; */
    /*  Qp = [0; 0; 0]; */
    /*  */
    /*  return the state of the robot folowing the trajectory */
    /*  t is the desired time */
    /*  p is the parameter vector */
    /*  r is the fixed parameter vector */
    /*  state contains positions, velocities and acceleration of the robot in the */
    /*  joint space */
    /* -> omega is fixed and the same for each joint in order to have periodic trajectory */
    /*  n_ddl = 3; */
    /*  N = 5; */
    for (i = 0; i < 3; i++) {
      Q[i] = dv1[i];
      Qp[i] = 0.0;
      b_Qpp[i] = 0.0;
    }

    i = 0;
    while (i < 3) {
      j = 0;
      while (j < 5) {
        delta2 = muDoubleScalarCos(0.62831853071795862 * (1.0 + (real_T)j) *
          delta1);
        Sojt = muDoubleScalarSin(0.62831853071795862 * (1.0 + (real_T)j) *
          delta1);
        Q[i] = (Q[i] + p[10 * i + j] / (0.62831853071795862 * (1.0 + (real_T)j))
                * Sojt) - p[(10 * i + j) + 5] / (0.62831853071795862 * (1.0 +
          (real_T)j)) * delta2;
        Qp[i] = (Qp[i] + p[10 * i + j] * delta2) + p[(10 * i + j) + 5] * Sojt;
        b_Qpp[i] = (b_Qpp[i] + p[(10 * i + j) + 5] * (1.0 + (real_T)j) * delta2)
          - p[10 * i + j] * (1.0 + (real_T)j) * Sojt;
        j++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_Qpp[i] *= 0.62831853071795862;
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i = 0; i < 3; i++) {
      state[i] = Q[i];
      state[i + 3] = Qp[i];
      state[i + 6] = b_Qpp[i];
      Xd[i] = state[i + 3];
      Xd[i + 3] = state[i];
    }

    if (2.0 + (real_T)b_i == 2.0) {
      i0 = iDq->size[1];
      j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, &j_emlrtBCI, &st);
      }

      i0 = X->size[1];
      j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, &i_emlrtBCI, &st);
      }

      i = X->size[0];
      for (i0 = 0; i0 < 3; i0++) {
        j = 4 + i0;
        if (!(j <= i)) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i, &s_emlrtBCI, &st);
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        iDq->data[i0] = T * (X->data[3 + i0] - Xd[3 + i0]);
      }
    } else {
      i = X->size[0];
      for (i0 = 0; i0 < 3; i0++) {
        j = 4 + i0;
        if (!(j <= i)) {
          emlrtDynamicBoundsCheckR2012b(j, 1, i, &r_emlrtBCI, &st);
        }
      }

      i0 = X->size[1];
      j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, &l_emlrtBCI, &st);
      }

      i = iDq->size[1];
      i0 = (int32_T)((2.0 + (real_T)b_i) - 2.0);
      if (!((i0 >= 1) && (i0 <= i))) {
        emlrtDynamicBoundsCheckR2012b(i0, 1, i, &k_emlrtBCI, &st);
      }

      i = iDq->size[1];
      i0 = (int32_T)((2.0 + (real_T)b_i) - 1.0);
      if (!((i0 >= 1) && (i0 <= i))) {
        emlrtDynamicBoundsCheckR2012b(i0, 1, i, &m_emlrtBCI, &st);
      }

      for (i0 = 0; i0 < 3; i0++) {
        Qp[i0] = iDq->data[i0 + iDq->size[0] * ((int32_T)((2.0 + (real_T)b_i) -
          2.0) - 1)] + T * (X->data[(i0 + X->size[0] * ((int32_T)((2.0 + (real_T)
          b_i) - 1.0) - 1)) + 3] - Xd[3 + i0]);
      }

      for (i0 = 0; i0 < 3; i0++) {
        iDq->data[i0 + iDq->size[0] * ((int32_T)((2.0 + (real_T)b_i) - 1.0) - 1)]
          = Qp[i0];
      }
    }

    i = X->size[0];
    for (i0 = 0; i0 < 3; i0++) {
      j = 4 + i0;
      if (!(j <= i)) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i, &t_emlrtBCI, &st);
      }
    }

    i0 = X->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &n_emlrtBCI, &st);
    }

    i = X->size[0];
    for (i0 = 0; i0 < 3; i0++) {
      j = 1 + i0;
      if (!(j <= i)) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i, &u_emlrtBCI, &st);
      }
    }

    i0 = X->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &o_emlrtBCI, &st);
    }

    i0 = iDq->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &p_emlrtBCI, &st);
    }

    for (i0 = 0; i0 < 3; i0++) {
      Qp[i0] = X->data[(i0 + X->size[0] * ((int32_T)((2.0 + (real_T)b_i) - 1.0)
        - 1)) + 3] - Xd[3 + i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      b_Qpp[i0] = X->data[i0 + X->size[0] * ((int32_T)((2.0 + (real_T)b_i) - 1.0)
        - 1)] - Xd[i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      a[i0] = 0.0;
      b_a[i0] = 0.0;
      for (j = 0; j < 3; j++) {
        a[i0] += (real_T)c_a[i0 + 3 * j] * Qp[j];
        b_a[i0] += (real_T)e_a[i0 + 3 * j] * b_Qpp[j];
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      delta1 = 0.0;
      for (j = 0; j < 3; j++) {
        delta1 += (real_T)d_a[i0 + 3 * j] * iDq->data[j + iDq->size[0] *
          ((int32_T)((2.0 + (real_T)b_i) - 1.0) - 1)];
      }

      Q[i0] = (a[i0] - b_a[i0]) - delta1;
    }

    /*  Xp = [Qpp;Qp] */
    i = X->size[0];
    i0 = X->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &b_emlrtBCI, sp);
    }

    X_size[0] = i;
    for (i0 = 0; i0 < i; i0++) {
      X_data[i0] = X->data[i0 + X->size[0] * (j - 1)];
    }

    st.site = &c_emlrtRSI;
    RRR_dyn_CL(&st, X_data, X_size, Q, Theta_data, Theta_size, Xd);
    i = Qpp->size[1];
    i0 = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((i0 >= 1) && (i0 <= i))) {
      emlrtDynamicBoundsCheckR2012b(i0, 1, i, &h_emlrtBCI, sp);
    }

    for (i0 = 0; i0 < 3; i0++) {
      Qpp->data[i0 + Qpp->size[0] * ((int32_T)((2.0 + (real_T)b_i) - 1.0) - 1)] =
        Xd[i0];
    }

    /*      timer = tic; */
    for (i = 0; i < 3; i++) {
      b_Qpp[i] = Q[i];
    }

    for (i = 0; i < 3; i++) {
      Qp[i] = b_Qpp[i];
    }

    t0_tunableEnvironment_f2_size[0] = c_tunableEnvironment_f2_size_id;
    if (0 <= loop_ub - 1) {
      memcpy(&t0_tunableEnvironment_f2_data[0], &tunableEnvironment_f2_data[0],
             (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    i0 = t->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &c_emlrtBCI, sp);
    }

    i0 = t->size[1];
    j = (int32_T)(2.0 + (real_T)b_i);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &d_emlrtBCI, sp);
    }

    i0 = X->size[1];
    j = (int32_T)((2.0 + (real_T)b_i) - 1.0);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &e_emlrtBCI, sp);
    }

    b_t[0] = t->data[(int32_T)((2.0 + (real_T)b_i) - 1.0) - 1];
    b_t[1] = t->data[b_i + 1];
    i = X->size[0];
    b_X_size[0] = i;
    for (i0 = 0; i0 < i; i0++) {
      X_data[i0] = X->data[i0 + X->size[0] * ((int32_T)((2.0 + (real_T)b_i) -
        1.0) - 1)];
    }

    st.site = &d_emlrtRSI;
    ode45(&st, Qp, t0_tunableEnvironment_f2_data, t0_tunableEnvironment_f2_size,
          b_t, X_data, b_X_size, unusedU0, Y_i);
    i1 = (int8_T)X->size[0];
    i = i1 - 1;
    for (i0 = 0; i0 <= i; i0++) {
      tmp_data[i0] = (int8_T)i0;
    }

    i0 = X->size[1];
    j = (int32_T)(2.0 + (real_T)b_i);
    if (!((j >= 1) && (j <= i0))) {
      emlrtDynamicBoundsCheckR2012b(j, 1, i0, &g_emlrtBCI, sp);
    }

    i0 = Y_i->size[0];
    i = Y_i->size[0];
    if (!((i >= 1) && (i <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &f_emlrtBCI, sp);
    }

    tmp_size[0] = 6;
    for (i0 = 0; i0 < 6; i0++) {
      X_data[i0] = Y_i->data[(i + Y_i->size[0] * i0) - 1];
    }

    iv0[0] = i1;
    emlrtSubAssignSizeCheckR2012b(&iv0[0], 1, &tmp_size[0], 1, &b_emlrtECI, sp);
    for (i0 = 0; i0 < 6; i0++) {
      X->data[tmp_data[i0] + X->size[0] * (b_i + 1)] = X_data[i0];
    }

    b_i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(sp, &Y_i);
  emxFree_real_T(sp, &unusedU0);
  emxFree_real_T(sp, &iDq);

  /*  Plotting for debug */
  /*   */
  /*  Xd = zeros(3, N); */
  /*  for i = 1:N */
  /*     xd = traj_gen_RRR(t(i)); */
  /*     Xd(:,i)=xd(4:6); */
  /*  end */
  /*   */
  /*   */
  /*  figure */
  /*  subplot(3,1,1) */
  /*  hold on */
  /*  plot(t, X(4, :)); */
  /*  plot(t, Xd(1,:)); */
  /*  % plot(t, Qpp(1,:)); */
  /*  % plot(t, iDq(1,:)); */
  /*  hold off */
  /*  legend('q1', 'qd1') */
  /*   */
  /*  subplot(3,1,2) */
  /*  hold on */
  /*  plot(t, X(5, :)); */
  /*  plot(t, Xd(2,:)); */
  /*  % plot(t, Qpp(2,:)); */
  /*  % plot(t, iDq(2,:)); */
  /*  hold off */
  /*  legend('q2', 'qd2') */
  /*   */
  /*  subplot(3,1,3) */
  /*  hold on */
  /*  plot(t, X(6, :)); */
  /*  plot(t, Xd(3,:)); */
  /*  % plot(t, Qpp(3,:)); */
  /*  % plot(t, iDq(3,:)); */
  /*  hold off */
  /*  legend('q3', 'qd3') */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (integrate_RRR_dyn_CL.c) */
