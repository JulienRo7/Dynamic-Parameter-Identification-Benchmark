/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ntrp45.c
 *
 * Code generation for function 'ntrp45'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "integrate_RRR_dyn_CL.h"
#include "ntrp45.h"
#include "blas.h"

/* Function Definitions */
void ntrp45(const real_T t[3], real_T t0, const real_T y0_data[], const int32_T
            y0_size[1], real_T h, const real_T f_data[], real_T y_data[],
            int32_T y_size[2])
{
  int32_T i;
  real_T fhBI1_data[6];
  real_T b[7];
  static const real_T b_b[7] = { -2.859375, 0.0, 4.0431266846361185, -3.90625,
    2.7939268867924527, -1.5714285714285714, 1.5 };

  char_T TRANSA;
  char_T TRANSB;
  real_T alpha1;
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  real_T fhBI2_data[6];
  static const real_T c_b[7] = { 3.0833333333333335, 0.0, -6.2893081761006293,
    10.416666666666666, -6.8773584905660377, 3.6666666666666665, -4.0 };

  real_T fhBI3_data[6];
  static const real_T d_b[7] = { -1.1328125, 0.0, 2.6954177897574123, -5.859375,
    3.7610554245283021, -1.9642857142857142, 2.5 };

  real_T fhBI4_data[6];
  static const real_T B[7] = { -5.71875, 0.0, 8.0862533692722369, -7.8125,
    5.5878537735849054, -3.1428571428571428, 3.0 };

  real_T b_y_data[6];
  static const real_T b_B[7] = { 9.25, 0.0, -18.867924528301888, 31.25,
    -20.632075471698112, 11.0, -12.0 };

  static const real_T c_B[7] = { -4.53125, 0.0, 10.781671159029649, -23.4375,
    15.044221698113208, -7.8571428571428568, 10.0 };

  int32_T k;
  for (i = 0; i < 6; i++) {
    fhBI1_data[i] = f_data[i] * h;
  }

  for (i = 0; i < 7; i++) {
    b[i] = h * b_b[i];
  }

  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)7;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)7;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &f_data[0], &lda_t, &b[0],
        &ldb_t, &beta1, &fhBI2_data[0], &ldc_t);
  for (i = 0; i < 7; i++) {
    b[i] = h * c_b[i];
  }

  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)7;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)7;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &f_data[0], &lda_t, &b[0],
        &ldb_t, &beta1, &fhBI3_data[0], &ldc_t);
  for (i = 0; i < 7; i++) {
    b[i] = h * d_b[i];
  }

  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)7;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)7;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &f_data[0], &lda_t, &b[0],
        &ldb_t, &beta1, &fhBI4_data[0], &ldc_t);
  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)7;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)7;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &f_data[0], &lda_t, &B[0],
        &ldb_t, &beta1, &b_y_data[0], &ldc_t);
  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)7;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)7;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &f_data[0], &lda_t, &b_B[0],
        &ldb_t, &beta1, &b_y_data[0], &ldc_t);
  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)7;
  lda_t = (ptrdiff_t)6;
  ldb_t = (ptrdiff_t)7;
  ldc_t = (ptrdiff_t)6;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &f_data[0], &lda_t, &c_B[0],
        &ldb_t, &beta1, &b_y_data[0], &ldc_t);
  y_size[0] = y0_size[0];
  y_size[1] = 3;
  for (i = 0; i < 3; i++) {
    alpha1 = (t[i] - t0) / h;
    for (k = 0; k < y0_size[0]; k++) {
      y_data[k + y_size[0] * i] = (((fhBI4_data[k] * alpha1 + fhBI3_data[k]) *
        alpha1 + fhBI2_data[k]) * alpha1 + fhBI1_data[k]) * alpha1 + y0_data[k];
    }
  }
}

/* End of code generation (ntrp45.c) */
