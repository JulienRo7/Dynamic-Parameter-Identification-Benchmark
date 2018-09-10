/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * propagate_RRR_Additive.c
 *
 * Code generation for function 'propagate_RRR_Additive'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "propagate_RRR_Additive.h"
#include "srukf_opt_emxutil.h"
#include "warning.h"
#include "ode45.h"
#include "srukf_opt_data.h"

/* Variable Definitions */
static emlrtRSInfo ib_emlrtRSI = { 6,  /* lineNo */
  "propagate_RRR_Additive",            /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/Utils/propagate_RRR_Additive.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 8,  /* lineNo */
  "propagate_RRR_Additive",            /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/Utils/propagate_RRR_Additive.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 20, /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 21, /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 22, /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 23, /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 29, /* lineNo */
  "RRR_dyn_CL",                        /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 1,  /* lineNo */
  "mldivide",                          /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mldivide.p"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 48, /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 251,/* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "propagate_RRR_Additive",            /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/Utils/propagate_RRR_Additive.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  8,                                   /* colNo */
  "y",                                 /* aName */
  "propagate_RRR_Additive",            /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/Utils/propagate_RRR_Additive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  12,                                  /* lineNo */
  5,                                   /* colNo */
  "propagate_RRR_Additive",            /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/Utils/propagate_RRR_Additive.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  70,                                  /* colNo */
  "x_km1",                             /* aName */
  "propagate_RRR_Additive",            /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/Utils/propagate_RRR_Additive.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  29,                                  /* lineNo */
  43,                                  /* colNo */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "M_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/M_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  11,                                  /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  12,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "C_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/C_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "G_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/G_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  16,                                  /* colNo */
  "Theta",                             /* aName */
  "G_theta",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/G_theta.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  17,                                  /* colNo */
  "Theta",                             /* aName */
  "RRR_dyn_CL",                        /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Utilities/RRR_dyn_CL.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void __anon_fcn(const emlrtStack *sp, const real_T u_km1_data[], const int32_T
                u_km1_size[1], const real_T Theta_data[], const int32_T
                Theta_size[1], const real_T y[6], real_T varargout_1[6])
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
  real_T b_y[9];
  real_T Y[3];
  int32_T r3;
  real_T Qpp[3];
  int32_T rtemp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
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

  /*  Return the closed loop dynamics of the RRR robots with a torque input tau */
  /*  X = [Qp;Q] */
  /*  Dynamics */
  Qp[0] = y[0];
  Qp[1] = y[1];
  Qp[2] = y[2];

  /*  [m/s²] */
  /*  [m/s²] */
  /*  [m/s²] */
  b_st.site = &cc_emlrtRSI;

  /* M_THETA */
  /*     M = M_THETA(THETA1,THETA2,THETA3,THETA4,THETA5,THETA6,THETA7,THETA10,THETA11,THETA12,THETA13,THETA14,Q2,Q3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     13-Apr-2018 15:06:21 */
  if (!(1 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(1, 1, Theta_size[0], &c_emlrtBCI, &b_st);
  }

  if (!(2 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(2, 1, Theta_size[0], &d_emlrtBCI, &b_st);
  }

  if (!(3 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(3, 1, Theta_size[0], &e_emlrtBCI, &b_st);
  }

  if (!(4 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Theta_size[0], &f_emlrtBCI, &b_st);
  }

  if (!(5 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(5, 1, Theta_size[0], &g_emlrtBCI, &b_st);
  }

  if (!(6 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(6, 1, Theta_size[0], &h_emlrtBCI, &b_st);
  }

  if (!(7 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(7, 1, Theta_size[0], &i_emlrtBCI, &b_st);
  }

  if (!(10 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(10, 1, Theta_size[0], &j_emlrtBCI, &b_st);
  }

  if (!(11 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(11, 1, Theta_size[0], &k_emlrtBCI, &b_st);
  }

  if (!(12 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(12, 1, Theta_size[0], &l_emlrtBCI, &b_st);
  }

  if (!(13 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(13, 1, Theta_size[0], &m_emlrtBCI, &b_st);
  }

  if (!(14 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(14, 1, Theta_size[0], &n_emlrtBCI, &b_st);
  }

  t2 = y[4] * 2.0;
  t4 = t2 + y[5] * 2.0;
  t5 = y[4] + y[5];
  t7 = Theta_data[13] * muDoubleScalarCos(t5);
  t5 = Theta_data[12] * muDoubleScalarSin(t5);
  t14 = ((t7 + t5) + Theta_data[10] * muDoubleScalarCos(y[4])) + Theta_data[2] *
    muDoubleScalarSin(y[4]);
  t15 = muDoubleScalarCos(y[5]);
  t16 = Theta_data[3] * t15;
  t17 = t7 + t5;
  t18 = Theta_data[6] + t16;
  t5 = y[5] + t2;
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

  b_st.site = &dc_emlrtRSI;

  /* C_THETA */
  /*     C = C_THETA(THETA2,THETA3,THETA4,THETA6,THETA10,THETA11,THETA12,THETA13,THETA14,Q2,Q3,QP1,QP2,QP3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     13-Apr-2018 15:06:22 */
  if (!(2 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(2, 1, Theta_size[0], &o_emlrtBCI, &b_st);
  }

  if (!(3 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(3, 1, Theta_size[0], &p_emlrtBCI, &b_st);
  }

  if (!(4 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(4, 1, Theta_size[0], &q_emlrtBCI, &b_st);
  }

  if (!(6 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(6, 1, Theta_size[0], &r_emlrtBCI, &b_st);
  }

  if (!(10 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(10, 1, Theta_size[0], &s_emlrtBCI, &b_st);
  }

  if (!(11 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(11, 1, Theta_size[0], &t_emlrtBCI, &b_st);
  }

  if (!(12 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(12, 1, Theta_size[0], &u_emlrtBCI, &b_st);
  }

  if (!(13 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(13, 1, Theta_size[0], &v_emlrtBCI, &b_st);
  }

  if (!(14 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(14, 1, Theta_size[0], &w_emlrtBCI, &b_st);
  }

  t2 = y[4] * 2.0;
  t4 = t2 + y[5] * 2.0;
  t6 = Theta_data[11] * muDoubleScalarCos(t4);
  t8 = Theta_data[5] * muDoubleScalarSin(t4) * 0.5;
  t17 = muDoubleScalarSin(y[5] + t2);
  t5 = y[4] + y[5];
  t16 = (((t6 + t8) + Theta_data[9] * muDoubleScalarCos(t2)) + Theta_data[1] *
         muDoubleScalarSin(t2) * 0.5) - Theta_data[3] * t17;
  t18 = Theta_data[12] * muDoubleScalarCos(t5);
  t19 = muDoubleScalarSin(t5);
  t20 = muDoubleScalarSin(y[5]);
  t17 = ((t6 + t8) - Theta_data[3] * t20 * 0.5) - Theta_data[3] * t17 * 0.5;
  t15 = t18 - Theta_data[13] * t19;
  t24 = y[2] * t15;
  t26 = y[0] * t16;
  t29 = y[0] * t17;
  b_st.site = &ec_emlrtRSI;

  /* G_THETA */
  /*     G = G_THETA(THETA8,THETA9,GX,GY,GZ,Q1,Q2,Q3) */
  /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
  /*     13-Apr-2018 15:06:22 */
  if (!(8 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(8, 1, Theta_size[0], &x_emlrtBCI, &b_st);
  }

  if (!(9 <= Theta_size[0])) {
    emlrtDynamicBoundsCheckR2012b(9, 1, Theta_size[0], &y_emlrtBCI, &b_st);
  }

  t2 = y[4] + y[5];
  t3 = muDoubleScalarCos(t2);
  t4 = muDoubleScalarCos(y[4]);
  t5 = muDoubleScalarCos(y[3]);
  t6 = muDoubleScalarSin(t2);
  t7 = muDoubleScalarSin(y[3]);
  t8 = muDoubleScalarSin(y[4]);
  b_st.site = &fc_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  if (Theta_size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&c_st, &cb_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }

  for (r1 = 0; r1 < 3; r1++) {
    r2 = 15 + r1;
    if (!(r2 <= Theta_size[0])) {
      emlrtDynamicBoundsCheckR2012b(r2, 1, Theta_size[0], &ab_emlrtBCI, &st);
    }
  }

  memset(&Fv[0], 0, 9U * sizeof(real_T));
  for (r1 = 0; r1 < 3; r1++) {
    Fv[r1 + 3 * r1] = Theta_data[r1 + 14];
  }

  /*  computation of the joint acceleration */
  if (u_km1_size[0] != 3) {
    emlrtSizeEqCheck1DR2012b(u_km1_size[0], 3, &b_emlrtECI, &st);
  }

  b_st.site = &gc_emlrtRSI;
  b_y[0] = y[1] * t16 + y[2] * t17;
  b_y[1] = -t26;
  b_y[2] = -t29;
  b_y[3] = (t24 + t26) + y[1] * (((t18 - Theta_data[13] * t19) + Theta_data[2] *
    muDoubleScalarCos(y[4])) - Theta_data[10] * muDoubleScalarSin(y[4]));
  b_y[4] = -Theta_data[3] * y[2] * t20;
  b_y[5] = Theta_data[3] * y[1] * t20;
  b_y[6] = (t24 + t29) + y[1] * t15;
  b_y[7] = -Theta_data[3] * t20 * (y[1] + y[2]);
  b_y[8] = 0.0;
  Y[0] = -(Theta_data[7] * t4 + Theta_data[8] * t3) * (0.0 * t7 - 0.0 * t5);
  Y[1] = ((((Theta_data[7] * 9.81 * t4 + Theta_data[8] * 9.81 * t3) -
            Theta_data[8] * 0.0 * t5 * t6) - Theta_data[7] * 0.0 * t5 * t8) -
          Theta_data[8] * 0.0 * t6 * t7) - Theta_data[7] * 0.0 * t7 * t8;
  Y[2] = -Theta_data[8] * ((-9.81 * t3 + 0.0 * t5 * t6) + 0.0 * t6 * t7);
  for (r1 = 0; r1 < 3; r1++) {
    t5 = 0.0;
    for (r2 = 0; r2 < 3; r2++) {
      t5 += b_y[r1 + 3 * r2] * Qp[r2];
    }

    t17 = 0.0;
    for (r2 = 0; r2 < 3; r2++) {
      t17 += Fv[r1 + 3 * r2] * Qp[r2];
    }

    Qpp[r1] = ((u_km1_data[r1] - t5) - Y[r1]) - t17;
  }

  c_st.site = &hc_emlrtRSI;
  d_st.site = &ic_emlrtRSI;
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
    e_st.site = &jc_emlrtRSI;
    if (!emlrtSetWarningFlag(&e_st)) {
      f_st.site = &kc_emlrtRSI;
      warning(&f_st);
    }
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
    varargout_1[r1] = muDoubleScalarMin(100.0, muDoubleScalarMax(-100.0, Y[r1]));
    varargout_1[r1 + 3] = Qp[r1];
  }
}

void propagate_RRR_Additive(const emlrtStack *sp, real_T t_km1, real_T t_k,
  const real_T x_km1_data[], const int32_T x_km1_size[1], const real_T
  u_km1_data[], const int32_T u_km1_size[1], const real_T q_km1_data[], const
  int32_T q_km1_size[1], real_T x_data[], int32_T x_size[1])
{
  int32_T i4;
  int32_T y;
  boolean_T nonSingletonDimFound;
  int32_T Theta_size_idx_0;
  int32_T loop_ub;
  real_T Theta_data[23];
  cell_wrap_2 tunableEnvironment[2];
  cell_wrap_2 t0_tunableEnvironment[2];
  emxArray_real_T *unusedU0;
  emxArray_real_T *b_y;
  real_T b_t_km1[2];
  real_T tmp_data[29];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Here x_km1 refers to the augmented state: */
  if (7 > x_km1_size[0]) {
    i4 = 1;
    y = 0;
  } else {
    i4 = 7;
    y = x_km1_size[0];
  }

  st.site = &ib_emlrtRSI;
  if (!(x_km1_size[0] != 1)) {
    nonSingletonDimFound = false;
    if ((int8_T)((y - i4) + 1) != 1) {
      nonSingletonDimFound = true;
    }

    if (nonSingletonDimFound) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }
  } else {
    nonSingletonDimFound = false;
  }

  b_st.site = &kb_emlrtRSI;
  if (nonSingletonDimFound) {
    emlrtErrorWithMessageIdR2018a(&b_st, &cb_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }

  Theta_size_idx_0 = (y - i4) + 1;
  loop_ub = (y - i4) + 1;
  for (y = 0; y < loop_ub; y++) {
    Theta_data[y] = x_km1_data[(i4 + y) - 1];
  }

  st.site = &jb_emlrtRSI;
  b_st.site = &kb_emlrtRSI;
  if (x_km1_size[0] == 1) {
    emlrtErrorWithMessageIdR2018a(&b_st, &cb_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }

  tunableEnvironment[0].f1.size[0] = u_km1_size[0];
  loop_ub = u_km1_size[0];
  for (i4 = 0; i4 < loop_ub; i4++) {
    tunableEnvironment[0].f1.data[i4] = u_km1_data[i4];
  }

  tunableEnvironment[1].f1.size[0] = Theta_size_idx_0;
  for (i4 = 0; i4 < Theta_size_idx_0; i4++) {
    tunableEnvironment[1].f1.data[i4] = Theta_data[i4];
  }

  for (i4 = 0; i4 < 2; i4++) {
    t0_tunableEnvironment[i4] = tunableEnvironment[i4];
  }

  for (i4 = 0; i4 < 6; i4++) {
    y = 1 + i4;
    if (!(y <= x_km1_size[0])) {
      emlrtDynamicBoundsCheckR2012b(y, 1, x_km1_size[0], &b_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &unusedU0, 1, &d_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_y, 2, &d_emlrtRTEI, true);
  b_t_km1[0] = t_km1;
  b_t_km1[1] = t_k;
  st.site = &jb_emlrtRSI;
  ode45(&st, t0_tunableEnvironment, b_t_km1, *(real_T (*)[6])&x_km1_data[0],
        unusedU0, b_y);
  i4 = b_y->size[0];
  y = b_y->size[0];
  if (!((y >= 1) && (y <= i4))) {
    emlrtDynamicBoundsCheckR2012b(y, 1, i4, &emlrtBCI, sp);
  }

  emxFree_real_T(sp, &unusedU0);
  for (i4 = 0; i4 < 6; i4++) {
    tmp_data[i4] = b_y->data[(y + b_y->size[0] * i4) - 1];
  }

  emxFree_real_T(sp, &b_y);
  if (0 <= Theta_size_idx_0 - 1) {
    memcpy(&tmp_data[6], &Theta_data[0], (uint32_T)(Theta_size_idx_0 * (int32_T)
            sizeof(real_T)));
  }

  i4 = 6 + Theta_size_idx_0;
  if (i4 != q_km1_size[0]) {
    emlrtSizeEqCheck1DR2012b(i4, q_km1_size[0], &emlrtECI, sp);
  }

  x_size[0] = 6 + Theta_size_idx_0;
  loop_ub = 6 + Theta_size_idx_0;
  for (i4 = 0; i4 < loop_ub; i4++) {
    x_data[i4] = tmp_data[i4] + q_km1_data[i4];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (propagate_RRR_Additive.c) */
