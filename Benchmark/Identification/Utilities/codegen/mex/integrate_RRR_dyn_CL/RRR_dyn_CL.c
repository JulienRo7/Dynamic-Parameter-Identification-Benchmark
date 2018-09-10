/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RRR_dyn_CL.c
 *
 * Code generation for function 'RRR_dyn_CL'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "RRR_dyn_CL.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 20,  /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 21,  /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 22,  /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 23,  /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 29,  /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 18,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 1,   /* lineNo */
  "mldivide",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mldivide.p"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 48,  /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 251, /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 76,  /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  6,                                   /* lineNo */
  7,                                   /* colNo */
  "X",                                 /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  7,                                   /* colNo */
  "X",                                 /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  7,                                   /* colNo */
  "X",                                 /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  6,                                   /* colNo */
  "X",                                 /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  6,                                   /* colNo */
  "X",                                 /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  6,                                   /* colNo */
  "X",                                 /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "G_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/G_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "G_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/G_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void RRR_dyn_CL(const emlrtStack *sp, const real_T X_data[], const int32_T
                X_size[1], const real_T tau[3], const real_T Theta_data[], const
                int32_T Theta_size[1], real_T Xp[6])
{
  real_T Qp[3];
  real_T t2;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T x[9];
  real_T Fv[9];
  int32_T r1;
  int32_T r2;
  real_T M[9];
  real_T t6;
  real_T t8;
  real_T t19;
  real_T t20;
  real_T t24;
  real_T t26;
  real_T t29;
  real_T t3;
  real_T X[9];
  real_T Y[3];
  int32_T r3;
  real_T Qpp[3];
  int32_T rtemp;
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

  /*  Return the closed loop dynamics of the RRR robots with a torque input tau */
  /*  X = [Qp;Q] */
  /*  Dynamics */
  if (!(1 <= X_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, X_size[0], &v_emlrtBCI, sp);
  }

  if (!(2 <= X_size[0])) {
    emlrtDynamicBoundsCheckR2012b(2, 1, X_size[0], &w_emlrtBCI, sp);
  }

  if (!(3 <= X_size[0])) {
    emlrtDynamicBoundsCheckR2012b(3, 1, X_size[0], &x_emlrtBCI, sp);
  }

  if (!(4 <= X_size[0])) {
    emlrtDynamicBoundsCheckR2012b(4, 1, X_size[0], &y_emlrtBCI, sp);
  }

  if (!(5 <= X_size[0])) {
    emlrtDynamicBoundsCheckR2012b(5, 1, X_size[0], &ab_emlrtBCI, sp);
  }

  if (!(6 <= X_size[0])) {
    emlrtDynamicBoundsCheckR2012b(6, 1, X_size[0], &bb_emlrtBCI, sp);
  }

  Qp[0] = X_data[0];
  Qp[1] = X_data[1];
  Qp[2] = X_data[2];

  /*  [m/s²] */
  /*  [m/s²] */
  /*  [m/s²] */
  st.site = &e_emlrtRSI;

  /* M_THETA */
  /*     M = M_THETA(THETA1,THETA2,THETA3,THETA4,THETA5,THETA6,THETA7,THETA10,THETA11,THETA12,THETA13,THETA14,Q2,Q3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     13-Apr-2018 15:06:21 */
  if (!(1 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, Theta_size[0], &cb_emlrtBCI, &st);
  }

  if (!(2 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(2, 1, Theta_size[0], &db_emlrtBCI, &st);
  }

  if (!(3 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(3, 1, Theta_size[0], &eb_emlrtBCI, &st);
  }

  if (!(4 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Theta_size[0], &fb_emlrtBCI, &st);
  }

  if (!(5 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(5, 1, Theta_size[0], &gb_emlrtBCI, &st);
  }

  if (!(6 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(6, 1, Theta_size[0], &hb_emlrtBCI, &st);
  }

  if (!(7 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(7, 1, Theta_size[0], &ib_emlrtBCI, &st);
  }

  if (!(10 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(10, 1, Theta_size[0], &jb_emlrtBCI, &st);
  }

  if (!(11 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(11, 1, Theta_size[0], &kb_emlrtBCI, &st);
  }

  if (!(12 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(12, 1, Theta_size[0], &lb_emlrtBCI, &st);
  }

  if (!(13 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(13, 1, Theta_size[0], &mb_emlrtBCI, &st);
  }

  if (!(14 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(14, 1, Theta_size[0], &nb_emlrtBCI, &st);
  }

  t2 = X_data[4] * 2.0;
  t4 = t2 + X_data[5] * 2.0;
  t5 = X_data[4] + X_data[5];
  t7 = Theta_data[13] * muDoubleScalarCos(t5);
  t5 = Theta_data[12] * muDoubleScalarSin(t5);
  t14 = ((t7 + t5) + Theta_data[10] * muDoubleScalarCos(X_data[4])) +
    Theta_data[2] * muDoubleScalarSin(X_data[4]);
  t15 = muDoubleScalarCos(X_data[5]);
  t16 = Theta_data[3] * t15;
  t17 = t7 + t5;
  t18 = Theta_data[6] + t16;
  t5 = X_data[5] + t2;
  x[0] = (((((((Theta_data[0] + Theta_data[1] * 0.5) + Theta_data[5] * 0.5) +
              t16) + Theta_data[3] * muDoubleScalarCos(t5)) - Theta_data[1] *
            muDoubleScalarCos(t2) * 0.5) - Theta_data[5] * muDoubleScalarCos(t4)
           * 0.5) + Theta_data[9] * muDoubleScalarSin(t2)) + Theta_data[11] *
    muDoubleScalarSin(t4);
  x[1] = t14;
  x[2] = t17;
  x[3] = t14;
  x[4] = (Theta_data[4] + Theta_data[6]) + Theta_data[3] * t15 * 2.0;
  x[5] = t18;
  x[6] = t17;
  x[7] = t18;
  x[8] = Theta_data[6];
  Fv[0] = (((((((Theta_data[0] + Theta_data[1] * 0.5) + Theta_data[5] * 0.5) +
               t16) + Theta_data[3] * muDoubleScalarCos(t5)) - Theta_data[1] *
             muDoubleScalarCos(t2) * 0.5) - Theta_data[5] * muDoubleScalarCos(t4)
            * 0.5) + Theta_data[9] * muDoubleScalarSin(t2)) + Theta_data[11] *
    muDoubleScalarSin(t4);
  Fv[1] = t14;
  Fv[2] = t17;
  Fv[3] = t14;
  Fv[4] = (Theta_data[4] + Theta_data[6]) + Theta_data[3] * t15 * 2.0;
  Fv[5] = t18;
  Fv[6] = t17;
  Fv[7] = t18;
  Fv[8] = Theta_data[6];
  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      M[r2 + 3 * r1] = Fv[r2 + 3 * r1];
    }
  }

  st.site = &f_emlrtRSI;

  /* C_THETA */
  /*     C = C_THETA(THETA2,THETA3,THETA4,THETA6,THETA10,THETA11,THETA12,THETA13,THETA14,Q2,Q3,QP1,QP2,QP3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     13-Apr-2018 15:06:22 */
  if (!(2 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(2, 1, Theta_size[0], &ob_emlrtBCI, &st);
  }

  if (!(3 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(3, 1, Theta_size[0], &pb_emlrtBCI, &st);
  }

  if (!(4 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Theta_size[0], &qb_emlrtBCI, &st);
  }

  if (!(6 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(6, 1, Theta_size[0], &rb_emlrtBCI, &st);
  }

  if (!(10 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(10, 1, Theta_size[0], &sb_emlrtBCI, &st);
  }

  if (!(11 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(11, 1, Theta_size[0], &tb_emlrtBCI, &st);
  }

  if (!(12 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(12, 1, Theta_size[0], &ub_emlrtBCI, &st);
  }

  if (!(13 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(13, 1, Theta_size[0], &vb_emlrtBCI, &st);
  }

  if (!(14 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(14, 1, Theta_size[0], &wb_emlrtBCI, &st);
  }

  t2 = X_data[4] * 2.0;
  t4 = t2 + X_data[5] * 2.0;
  t6 = Theta_data[11] * muDoubleScalarCos(t4);
  t8 = Theta_data[5] * muDoubleScalarSin(t4) * 0.5;
  t17 = muDoubleScalarSin(X_data[5] + t2);
  t5 = X_data[4] + X_data[5];
  t16 = (((t6 + t8) + Theta_data[9] * muDoubleScalarCos(t2)) + Theta_data[1] *
         muDoubleScalarSin(t2) * 0.5) - Theta_data[3] * t17;
  t18 = Theta_data[12] * muDoubleScalarCos(t5);
  t19 = muDoubleScalarSin(t5);
  t20 = muDoubleScalarSin(X_data[5]);
  t17 = ((t6 + t8) - Theta_data[3] * t20 * 0.5) - Theta_data[3] * t17 * 0.5;
  t15 = t18 - Theta_data[13] * t19;
  t24 = X_data[2] * t15;
  t26 = X_data[0] * t16;
  t29 = X_data[0] * t17;
  st.site = &g_emlrtRSI;

  /* G_THETA */
  /*     G = G_THETA(THETA8,THETA9,GX,GY,GZ,Q1,Q2,Q3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     13-Apr-2018 15:06:22 */
  if (!(8 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(8, 1, Theta_size[0], &xb_emlrtBCI, &st);
  }

  if (!(9 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(9, 1, Theta_size[0], &yb_emlrtBCI, &st);
  }

  t2 = X_data[4] + X_data[5];
  t3 = muDoubleScalarCos(t2);
  t4 = muDoubleScalarCos(X_data[4]);
  t5 = muDoubleScalarCos(X_data[3]);
  t6 = muDoubleScalarSin(t2);
  t7 = muDoubleScalarSin(X_data[3]);
  t8 = muDoubleScalarSin(X_data[4]);
  st.site = &h_emlrtRSI;
  b_st.site = &j_emlrtRSI;
  if (Theta_size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&b_st, &q_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }

  for (r1 = 0; r1 < 3; r1++) {
    r2 = 15 + r1;
    if (!(r2 <= Theta_size[0])) {
      emlrtDynamicBoundsCheckR2012b(r2, 1, Theta_size[0], &ac_emlrtBCI, sp);
    }
  }

  memset(&Fv[0], 0, 9U * sizeof(real_T));
  for (r1 = 0; r1 < 3; r1++) {
    Fv[r1 + 3 * r1] = Theta_data[r1 + 14];
  }

  /*  computation of the joint acceleration */
  st.site = &i_emlrtRSI;
  X[0] = X_data[1] * t16 + X_data[2] * t17;
  X[1] = -t26;
  X[2] = -t29;
  X[3] = (t24 + t26) + X_data[1] * (((t18 - Theta_data[13] * t19) + Theta_data[2]
    * muDoubleScalarCos(X_data[4])) - Theta_data[10] * muDoubleScalarSin(X_data
    [4]));
  X[4] = -Theta_data[3] * X_data[2] * t20;
  X[5] = Theta_data[3] * X_data[1] * t20;
  X[6] = (t24 + t29) + X_data[1] * t15;
  X[7] = -Theta_data[3] * t20 * (X_data[1] + X_data[2]);
  X[8] = 0.0;
  Y[0] = -(Theta_data[7] * t4 + Theta_data[8] * t3) * (0.0 * t7 - 0.0 * t5);
  Y[1] = ((((Theta_data[7] * 9.81 * t4 + Theta_data[8] * 9.81 * t3) -
            Theta_data[8] * 0.0 * t5 * t6) - Theta_data[7] * 0.0 * t5 * t8) -
          Theta_data[8] * 0.0 * t6 * t7) - Theta_data[7] * 0.0 * t7 * t8;
  Y[2] = -Theta_data[8] * ((-9.81 * t3 + 0.0 * t5 * t6) + 0.0 * t6 * t7);
  for (r1 = 0; r1 < 3; r1++) {
    t5 = 0.0;
    for (r2 = 0; r2 < 3; r2++) {
      t5 += X[r1 + 3 * r2] * Qp[r2];
    }

    t17 = 0.0;
    for (r2 = 0; r2 < 3; r2++) {
      t17 += Fv[r1 + 3 * r2] * Qp[r2];
    }

    Qpp[r1] = ((tau[r1] - t5) - Y[r1]) - t17;
  }

  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  r1 = 0;
  r2 = 1;
  r3 = 2;
  t17 = muDoubleScalarAbs(x[0]);
  t5 = muDoubleScalarAbs(t14);
  if (t5 > t17) {
    t17 = t5;
    r1 = 1;
    r2 = 0;
  }

  if (muDoubleScalarAbs(M[2]) > t17) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  M[r2] = x[r2] / x[r1];
  M[r3] /= M[r1];
  M[3 + r2] -= M[r2] * M[3 + r1];
  M[3 + r3] -= M[r3] * M[3 + r1];
  M[6 + r2] -= M[r2] * M[6 + r1];
  M[6 + r3] -= M[r3] * M[6 + r1];
  if (muDoubleScalarAbs(M[3 + r3]) > muDoubleScalarAbs(M[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  M[3 + r3] /= M[3 + r2];
  M[6 + r3] -= M[3 + r3] * M[6 + r2];
  if ((M[r1] == 0.0) || (M[3 + r2] == 0.0) || (M[6 + r3] == 0.0)) {
    d_st.site = &m_emlrtRSI;
    e_st.site = &n_emlrtRSI;
    warning(&e_st);
  }

  Y[1] = Qpp[r2] - Qpp[r1] * M[r2];
  Y[2] = (Qpp[r3] - Qpp[r1] * M[r3]) - Y[1] * M[3 + r3];
  Y[2] /= M[6 + r3];
  Y[0] = Qpp[r1] - Y[2] * M[6 + r1];
  Y[1] -= Y[2] * M[6 + r2];
  Y[1] /= M[3 + r2];
  Y[0] -= Y[1] * M[3 + r1];
  Y[0] /= M[r1];
  for (r1 = 0; r1 < 3; r1++) {
    Xp[r1] = muDoubleScalarMin(100.0, muDoubleScalarMax(-100.0, Y[r1]));
    Xp[r1 + 3] = Qp[r1];
  }
}

/* End of code generation (RRR_dyn_CL.c) */
