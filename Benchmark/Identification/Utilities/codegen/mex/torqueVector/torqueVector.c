/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * torqueVector.c
 *
 * Code generation for function 'torqueVector'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "torqueVector.h"
#include "torqueVector_emxutil.h"
#include "torqueVector_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 5,   /* lineNo */
  1,                                   /* colNo */
  "torqueVector",                      /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/torqueVector.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  26,                                  /* colNo */
  "Tau",                               /* aName */
  "torqueVector",                      /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/torqueVector.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  9,                                   /* colNo */
  "Y_tau",                             /* aName */
  "torqueVector",                      /* fName */
  "/home/quentin/Desktop/MatlabCommented10092018/Benchmark/Identification/Utilities/torqueVector.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void torqueVector(const emlrtStack *sp, const emxArray_real_T *Tau,
                  emxArray_real_T *Y_tau)
{
  int32_T n;
  int32_T i0;
  int32_T loop_ub;
  int32_T j;
  int32_T i1;
  int32_T i2;

  /*  Building the sampled torque vector */
  n = Tau->size[1];
  i0 = Y_tau->size[0];
  Y_tau->size[0] = Tau->size[0] * Tau->size[1];
  emxEnsureCapacity_real_T(sp, Y_tau, i0, &emlrtRTEI);
  loop_ub = Tau->size[0] * Tau->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Y_tau->data[i0] = 0.0;
  }

  loop_ub = 0;
  while (loop_ub <= Tau->size[0] - 1) {
    j = 1;
    while (j - 1 <= n - 1) {
      i0 = Tau->size[0];
      i1 = 1 + loop_ub;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, sp);
      }

      i0 = Tau->size[1];
      if (!((j >= 1) && (j <= i0))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i0, &emlrtBCI, sp);
      }

      i0 = Y_tau->size[0];
      i2 = loop_ub * n + j;
      if (!((i2 >= 1) && (i2 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i0, &b_emlrtBCI, sp);
      }

      Y_tau->data[i2 - 1] = Tau->data[(i1 + Tau->size[0] * (j - 1)) - 1];
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    loop_ub++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (torqueVector.c) */
