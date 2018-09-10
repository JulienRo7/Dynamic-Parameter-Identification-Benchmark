/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xtrsm.c
 *
 * Code generation for function 'xtrsm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "xtrsm.h"
#include "blas.h"

/* Function Definitions */
void b_xtrsm(int32_T m, int32_T n, const emxArray_real_T *A, int32_T lda, real_T
             B_data[], int32_T ldb)
{
  real_T alpha1;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  if ((m < 1) || (n < 1)) {
  } else {
    alpha1 = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'R';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &alpha1, &A->data[0],
          &lda_t, &B_data[0], &ldb_t);
  }
}

void xtrsm(int32_T m, int32_T n, const emxArray_real_T *A, int32_T lda, real_T
           B_data[], int32_T ldb)
{
  real_T alpha1;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  if ((m < 1) || (n < 1)) {
  } else {
    alpha1 = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'R';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &alpha1, &A->data[0],
          &lda_t, &B_data[0], &ldb_t);
  }
}

/* End of code generation (xtrsm.c) */
