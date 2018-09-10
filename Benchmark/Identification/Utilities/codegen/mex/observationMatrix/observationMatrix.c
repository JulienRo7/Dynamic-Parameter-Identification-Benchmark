/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * observationMatrix.c
 *
 * Code generation for function 'observationMatrix'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "observationMatrix.h"
#include "observationMatrix_emxutil.h"
#include "observationMatrix_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 4,   /* lineNo */
  1,                                   /* colNo */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  16,                                  /* colNo */
  "Q",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  18,                                  /* colNo */
  "Q",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  16,                                  /* colNo */
  "Q",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  18,                                  /* colNo */
  "Q",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  16,                                  /* colNo */
  "Q",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  18,                                  /* colNo */
  "Q",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  18,                                  /* colNo */
  "Qp",                                /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  20,                                  /* colNo */
  "Qp",                                /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  18,                                  /* colNo */
  "Qp",                                /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  20,                                  /* colNo */
  "Qp",                                /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  18,                                  /* colNo */
  "Qp",                                /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  20,                                  /* colNo */
  "Qp",                                /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  20,                                  /* colNo */
  "Qpp",                               /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  22,                                  /* colNo */
  "Qpp",                               /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  20,                                  /* colNo */
  "Qpp",                               /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  22,                                  /* colNo */
  "Qpp",                               /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  20,                                  /* colNo */
  "Qpp",                               /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  22,                                  /* colNo */
  "Qpp",                               /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  9,                                   /* colNo */
  "W",                                 /* aName */
  "observationMatrix",                 /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/observationMatrix.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void observationMatrix(const emlrtStack *sp, const emxArray_real_T *Q, const
  emxArray_real_T *Qp, const emxArray_real_T *Qpp, emxArray_real_T *W)
{
  int32_T i0;
  int32_T loop_ub;
  int32_T i1;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t20;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t30;
  real_T t31;
  real_T t32;
  real_T b_Qpp[51];
  int32_T b_W;
  int32_T i2;
  int32_T i3;
  i0 = W->size[0] * W->size[1];
  W->size[0] = Q->size[0] * Q->size[1];
  W->size[1] = 17;
  emxEnsureCapacity_real_T(sp, W, i0, &emlrtRTEI);
  loop_ub = Q->size[0] * Q->size[1] * 17;
  for (i0 = 0; i0 < loop_ub; i0++) {
    W->data[i0] = 0.0;
  }

  /* gravity vector */
  /*  Building of the observation matrix W for the current iteration of Theta: */
  loop_ub = 0;
  while (loop_ub <= Q->size[0] - 1) {
    i0 = Q->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &b_emlrtBCI, sp);
    }

    i0 = Q->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, sp);
    }

    i0 = Q->size[1];
    if (!(2 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i0, &d_emlrtBCI, sp);
    }

    i0 = Q->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, sp);
    }

    i0 = Q->size[1];
    if (!(3 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(3, 1, i0, &f_emlrtBCI, sp);
    }

    i0 = Q->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &e_emlrtBCI, sp);
    }

    i0 = Qp->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &h_emlrtBCI, sp);
    }

    i0 = Qp->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &g_emlrtBCI, sp);
    }

    i0 = Qp->size[1];
    if (!(2 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i0, &j_emlrtBCI, sp);
    }

    i0 = Qp->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &i_emlrtBCI, sp);
    }

    i0 = Qp->size[1];
    if (!(3 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(3, 1, i0, &l_emlrtBCI, sp);
    }

    i0 = Qp->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &k_emlrtBCI, sp);
    }

    i0 = Qpp->size[1];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &n_emlrtBCI, sp);
    }

    i0 = Qpp->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &m_emlrtBCI, sp);
    }

    i0 = Qpp->size[1];
    if (!(2 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i0, &p_emlrtBCI, sp);
    }

    i0 = Qpp->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, sp);
    }

    i0 = Qpp->size[1];
    if (!(3 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(3, 1, i0, &r_emlrtBCI, sp);
    }

    i0 = Qpp->size[0];
    i1 = loop_ub + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &q_emlrtBCI, sp);
    }

    /*  Compute the observation matrix: */
    /* REGRESSOR */
    /*     REGRESSOR = REGRESSOR(GX,GY,GZ,Q1,Q2,Q3,QP1,QP2,QP3,QPP1,QPP2,QPP3) */
    /*     This function was generated by the Symbolic Math Toolbox version 8.0. */
    /*     13-Apr-2018 14:57:52 */
    t2 = Q->data[loop_ub + Q->size[0]] * 2.0;
    t3 = Q->data[loop_ub + (Q->size[0] << 1)] + t2;
    t4 = muDoubleScalarSin(t3);
    t5 = Qpp->data[loop_ub] * 0.5;
    t7 = t2 + Q->data[loop_ub + (Q->size[0] << 1)] * 2.0;
    t8 = muDoubleScalarSin(t7);
    t9 = Q->data[loop_ub] + Q->data[loop_ub + Q->size[0]];
    t10 = Q->data[loop_ub] - Q->data[loop_ub + Q->size[0]];
    t11 = (-Q->data[loop_ub] + Q->data[loop_ub + Q->size[0]]) + Q->data[loop_ub
      + (Q->size[0] << 1)];
    t12 = (Q->data[loop_ub] + Q->data[loop_ub + Q->size[0]]) + Q->data[loop_ub +
      (Q->size[0] << 1)];
    t13 = muDoubleScalarSin(t2);
    t14 = muDoubleScalarCos(t2);
    t15 = Qp->data[loop_ub + Qp->size[0]] * Qp->data[loop_ub + Qp->size[0]];
    t16 = muDoubleScalarSin(Q->data[loop_ub + Q->size[0]]);
    t17 = muDoubleScalarCos(Q->data[loop_ub + Q->size[0]]);
    t18 = muDoubleScalarCos(t7);
    t2 = Q->data[loop_ub + Q->size[0]] + Q->data[loop_ub + (Q->size[0] << 1)];
    t20 = muDoubleScalarSin(t2);
    t2 = muDoubleScalarCos(t2);
    t7 = Qp->data[loop_ub + (Qp->size[0] << 1)] * Qp->data[loop_ub + (Qp->size[0]
      << 1)];
    t23 = muDoubleScalarSin(Q->data[loop_ub + (Q->size[0] << 1)]);
    t24 = Qp->data[loop_ub] * Qp->data[loop_ub];
    t25 = muDoubleScalarCos(Q->data[loop_ub + (Q->size[0] << 1)]);
    t26 = muDoubleScalarCos(Q->data[loop_ub]);
    t27 = muDoubleScalarSin(Q->data[loop_ub]);
    t28 = Qpp->data[loop_ub + Qpp->size[0]] + Qpp->data[loop_ub + (Qpp->size[0] <<
      1)];
    t30 = (9.81 * t2 - 0.0 * t20 * t26) - 0.0 * t20 * t27;
    t31 = Qpp->data[loop_ub] * t20;
    t32 = Qpp->data[loop_ub] * t2;

    /*  , sign(qp1), 0, 0, 0, sign(qp2), 0, 0, 0, sign(qp3) */
    b_Qpp[0] = Qpp->data[loop_ub];
    b_Qpp[1] = 0.0;
    b_Qpp[2] = 0.0;
    b_Qpp[3] = (t5 - Qpp->data[loop_ub] * t14 * 0.5) + Qp->data[loop_ub] *
      Qp->data[loop_ub + Qp->size[0]] * t13;
    b_Qpp[4] = t13 * t24 * -0.5;
    b_Qpp[5] = 0.0;
    b_Qpp[6] = Qpp->data[loop_ub + Qpp->size[0]] * t16 + t15 * t17;
    b_Qpp[7] = Qpp->data[loop_ub] * t16;
    b_Qpp[8] = 0.0;
    b_Qpp[9] = (((Qpp->data[loop_ub] * t25 + Qpp->data[loop_ub] *
                  muDoubleScalarCos(t3)) - Qp->data[loop_ub] * Qp->data[loop_ub
                 + Qp->size[0]] * t4 * 2.0) - Qp->data[loop_ub] * Qp->
                data[loop_ub + (Qp->size[0] << 1)] * t4) - Qp->data[loop_ub] *
      Qp->data[loop_ub + (Qp->size[0] << 1)] * t23;
    b_Qpp[10] = (((Qpp->data[loop_ub + Qpp->size[0]] * t25 * 2.0 + Qpp->
                   data[loop_ub + (Qpp->size[0] << 1)] * t25) + t4 * t24) - t7 *
                 t23) - Qp->data[loop_ub + Qp->size[0]] * Qp->data[loop_ub +
      (Qp->size[0] << 1)] * t23 * 2.0;
    b_Qpp[11] = (Qpp->data[loop_ub + Qpp->size[0]] * t25 + t15 * t23) + t24 *
      (t4 * 0.5 + t23 * 0.5);
    b_Qpp[12] = 0.0;
    b_Qpp[13] = Qpp->data[loop_ub + Qpp->size[0]];
    b_Qpp[14] = 0.0;
    b_Qpp[15] = ((t5 - Qpp->data[loop_ub] * t18 * 0.5) + Qp->data[loop_ub] *
                 Qp->data[loop_ub + Qp->size[0]] * t8) + Qp->data[loop_ub] *
      Qp->data[loop_ub + (Qp->size[0] << 1)] * t8;
    b_Qpp[16] = t8 * t24 * -0.5;
    b_Qpp[17] = t8 * t24 * -0.5;
    b_Qpp[18] = 0.0;
    b_Qpp[19] = t28;
    b_Qpp[20] = t28;
    b_Qpp[21] = ((0.0 * muDoubleScalarCos(t9) * 0.5 + 0.0 * muDoubleScalarCos
                  (t10) * 0.5) - 0.0 * muDoubleScalarSin(t9) * 0.5) - 0.0 *
      muDoubleScalarSin(t10) * 0.5;
    b_Qpp[22] = (9.81 * t17 - 0.0 * t16 * t26) - 0.0 * t16 * t27;
    b_Qpp[23] = 0.0;
    b_Qpp[24] = ((0.0 * muDoubleScalarCos(t11) * 0.5 + 0.0 * muDoubleScalarCos
                  (t12) * 0.5) + 0.0 * muDoubleScalarSin(t11) * 0.5) - 0.0 *
      muDoubleScalarSin(t12) * 0.5;
    b_Qpp[25] = t30;
    b_Qpp[26] = t30;
    b_Qpp[27] = Qpp->data[loop_ub] * t13 + Qp->data[loop_ub] * Qp->data[loop_ub
      + Qp->size[0]] * t14 * 2.0;
    b_Qpp[28] = -t14 * t24;
    b_Qpp[29] = 0.0;
    b_Qpp[30] = Qpp->data[loop_ub + Qpp->size[0]] * t17 - t15 * t16;
    b_Qpp[31] = Qpp->data[loop_ub] * t17;
    b_Qpp[32] = 0.0;
    b_Qpp[33] = (Qpp->data[loop_ub] * t8 + Qp->data[loop_ub] * Qp->data[loop_ub
                 + Qp->size[0]] * t18 * 2.0) + Qp->data[loop_ub] * Qp->
      data[loop_ub + (Qp->size[0] << 1)] * t18 * 2.0;
    b_Qpp[34] = -t18 * t24;
    b_Qpp[35] = -t18 * t24;
    b_Qpp[36] = (((Qpp->data[loop_ub + Qpp->size[0]] * t20 + Qpp->data[loop_ub +
                   (Qpp->size[0] << 1)] * t20) + t15 * t2) + t2 * t7) + Qp->
      data[loop_ub + Qp->size[0]] * Qp->data[loop_ub + (Qp->size[0] << 1)] * t2 *
      2.0;
    b_Qpp[37] = t31;
    b_Qpp[38] = t31;
    b_Qpp[39] = (((Qpp->data[loop_ub + Qpp->size[0]] * t2 + Qpp->data[loop_ub +
                   (Qpp->size[0] << 1)] * t2) - t15 * t20) - t20 * t7) -
      Qp->data[loop_ub + Qp->size[0]] * Qp->data[loop_ub + (Qp->size[0] << 1)] *
      t20 * 2.0;
    b_Qpp[40] = t32;
    b_Qpp[41] = t32;
    b_Qpp[42] = Qp->data[loop_ub];
    b_Qpp[43] = 0.0;
    b_Qpp[44] = 0.0;
    b_Qpp[45] = 0.0;
    b_Qpp[46] = Qp->data[loop_ub + Qp->size[0]];
    b_Qpp[47] = 0.0;
    b_Qpp[48] = 0.0;
    b_Qpp[49] = 0.0;
    b_Qpp[50] = Qp->data[loop_ub + (Qp->size[0] << 1)];
    i0 = 3 * (1 + loop_ub) - 2;
    b_W = W->size[0];
    for (i1 = 0; i1 < 17; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        i3 = i2 + i0;
        if (!((i3 >= 1) && (i3 <= b_W))) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, b_W, &s_emlrtBCI, sp);
        }

        W->data[(i3 + W->size[0] * i1) - 1] = b_Qpp[i2 + 3 * i1];
      }
    }

    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (observationMatrix.c) */
