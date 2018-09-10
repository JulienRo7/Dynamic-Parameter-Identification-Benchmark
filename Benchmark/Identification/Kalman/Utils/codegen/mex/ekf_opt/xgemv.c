/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ekf_opt.h"
#include "xgemv.h"

/* Variable Definitions */
static const real_T dv0[21] = { 0.2, 0.075, 0.225, 0.97777777777777775,
  -3.7333333333333334, 3.5555555555555554, 2.9525986892242035,
  -11.595793324188385, 9.8228928516994358, -0.29080932784636487,
  2.8462752525252526, -10.757575757575758, 8.9064227177434727,
  0.27840909090909088, -0.2735313036020583, 0.091145833333333329, 0.0,
  0.44923629829290207, 0.65104166666666663, -0.322376179245283,
  0.13095238095238096 };

/* Function Definitions */
void b_xgemv(real_T alpha1, const real_T A[42], int32_T ix0, real_T y[6])
{
  int32_T ix;
  int32_T iac;
  real_T c;
  int32_T iy;
  int32_T ia;
  if (!(alpha1 == 0.0)) {
    ix = ix0;
    for (iac = 0; iac <= 31; iac += 6) {
      c = alpha1 * dv0[ix - 1];
      iy = 0;
      for (ia = iac; ia < iac + 6; ia++) {
        y[iy] += A[ia] * c;
        iy++;
      }

      ix++;
    }
  }
}

void xgemv(int32_T n, real_T alpha1, const real_T A[42], int32_T ix0, real_T y[6])
{
  int32_T ix;
  int32_T c;
  int32_T iac;
  real_T b_c;
  int32_T iy;
  int32_T ia;
  if (!(alpha1 == 0.0)) {
    ix = ix0;
    c = 6 * (n - 1);
    for (iac = 1; iac <= c + 1; iac += 6) {
      b_c = alpha1 * dv0[ix - 1];
      iy = 0;
      for (ia = iac; ia <= iac + 5; ia++) {
        y[iy] += A[ia - 1] * b_c;
        iy++;
      }

      ix++;
    }
  }
}

/* End of code generation (xgemv.c) */
