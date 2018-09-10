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
#include "integrate_RRR_dyn_CL.h"
#include "xgemv.h"
#include "blas.h"

/* Variable Definitions */
static const real_T dv0[21] = { 0.2, 0.075, 0.225, 0.97777777777777775,
  -3.7333333333333334, 3.5555555555555554, 2.9525986892242035,
  -11.595793324188385, 9.8228928516994358, -0.29080932784636487,
  2.8462752525252526, -10.757575757575758, 8.9064227177434727,
  0.27840909090909088, -0.2735313036020583, 0.091145833333333329, 0.0,
  0.44923629829290207, 0.65104166666666663, -0.322376179245283,
  0.13095238095238096 };

/* Function Definitions */
void b_xgemv(real_T alpha1, const real_T A_data[], int32_T ix0, real_T y_data[])
{
  real_T beta1;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  beta1 = 1.0;
  TRANSA = 'N';
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)6;
  lda_t = (ptrdiff_t)6;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &dv0[ix0 - 1], &incx_t,
        &beta1, &y_data[0], &incy_t);
}

void xgemv(int32_T n, real_T alpha1, const real_T A_data[], int32_T ix0, real_T
           y_data[])
{
  real_T beta1;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  beta1 = 1.0;
  TRANSA = 'N';
  m_t = (ptrdiff_t)6;
  n_t = (ptrdiff_t)n;
  lda_t = (ptrdiff_t)6;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A_data[0], &lda_t, &dv0[ix0 - 1], &incx_t,
        &beta1, &y_data[0], &incy_t);
}

/* End of code generation (xgemv.c) */
