/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ekf_opt.c
 *
 * Code generation for function 'ekf_opt'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "ekf_opt.h"
#include "mrdivide.h"
#include "eye.h"
#include "stateJacobian.h"
#include "indexShapeCheck.h"
#include "propagate_RRR_Additive.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 42,    /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 43,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 47,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 48,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 56,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 59,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 62,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 65,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 72,  /* lineNo */
  "ekf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  53,                                  /* lineNo */
  8,                                   /* colNo */
  "ekf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  56,                                  /* lineNo */
  10,                                  /* colNo */
  "ekf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  68,                                  /* lineNo */
  5,                                   /* colNo */
  "ekf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/ekf_opt.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

/* Function Definitions */
void ekf_opt(const emlrtStack *sp, real_T t_km1, real_T t_k, const real_T
             x_km1_data[], const int32_T x_km1_size[1], const real_T u_km1_data[],
             const int32_T u_km1_size[1], const real_T P_km1_data[], const
             int32_T P_km1_size[2], const real_T y_k_data[], const int32_T
             y_k_size[1], const real_T Rv_data[], const int32_T Rv_size[2],
             const real_T Rn_data[], const int32_T Rn_size[2], real_T x[23],
             real_T P[529], real_T K[69], real_T inov[3], real_T x_kkm1_data[],
             int32_T x_kkm1_size[1], real_T P_kkm1[529], real_T P_xy[69], real_T
             P_yy[9])
{
  int32_T tmp_size[1];
  int32_T coffset;
  real_T tmp_data[23];
  int32_T b_tmp_size[1];
  real_T A[529];
  real_T B_data[529];
  int32_T B_size[2];
  int32_T boffset;
  int32_T a_size_idx_0;
  int32_T aoffset;
  int32_T loop_ub;
  char_T TRANSA;
  real_T a_data[529];
  int32_T i0;
  char_T TRANSB;
  real_T alpha1;
  int32_T i;
  real_T beta1;
  int32_T b_size_idx_1;
  ptrdiff_t m_t;
  int32_T i1;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  real_T b_data[529];
  int32_T B[2];
  int32_T iv0[2];
  real_T b_a_data[529];
  static const real_T b[69] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T a[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c_a_data[9];
  static const real_T b_a[69] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T y[69];
  real_T b_y[9];
  static const int8_T iv1[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T b_K[69];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  EKF: Extended Kalman Filter */
  /*  Authors: Julien Roux, Quentin Leboutet, Alexandre Janot */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  INPUTS: */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  x_km1:    state mean at time k-1 */
  /*  P_km1:    state covariance at time k-1 */
  /*  u_km1:    control input at time k-1 */
  /*  y_k:      noisy observation at time k */
  /*  Rv:       process noise covariance matrix */
  /*  Rn:       observation noise covariance matrix */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  OUTPUTS:  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  x:        estimated state */
  /*  P:        estimated state covariance */
  /*  K:        Kalman Gain */
  /*  inov:     inovation signal */
  /*  x_kkm1:   predicted state mean */
  /*  P_kkm1:   predicted state covariance */
  /*  P_xy:     predicted state and observation covariance */
  /*  P_yy:     inovation covariance   */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Dimensions: */
  /*  Number of states */
  /*  Number of noise states */
  /*  Number of observations */
  /*  Expected prediction and measurement: */
  tmp_size[0] = Rv_size[0];
  coffset = Rv_size[0];
  if (0 <= coffset - 1) {
    memset(&tmp_data[0], 0, (uint32_T)(coffset * (int32_T)sizeof(real_T)));
  }

  st.site = &emlrtRSI;
  propagate_RRR_Additive(&st, t_km1, t_k, x_km1_data, x_km1_size, u_km1_data,
    u_km1_size, tmp_data, tmp_size, x_kkm1_data, x_kkm1_size);
  st.site = &b_emlrtRSI;
  indexShapeCheck(&st, x_kkm1_size[0]);

  /*  Calculate the Jacobian using the state at k-1: */
  b_tmp_size[0] = Rv_size[0];
  st.site = &c_emlrtRSI;
  stateJacobian(&st, t_k - t_km1, x_km1_data, x_km1_size, u_km1_data, u_km1_size,
                b_tmp_size, A);
  st.site = &d_emlrtRSI;
  eye(&st, x_km1_size[0], B_data, B_size);

  /* noiseJacobian(x_km1); */
  /*  Innovation vector: */
  if (y_k_size[0] != 3) {
    emlrtSizeEqCheck1DR2012b(y_k_size[0], 3, &emlrtECI, sp);
  }

  for (boffset = 0; boffset < 3; boffset++) {
    inov[boffset] = y_k_data[boffset] - x_kkm1_data[3 + boffset];
  }

  /*  Covariance of the prediction: */
  st.site = &e_emlrtRSI;
  b_st.site = &rc_emlrtRSI;
  if (!(B_size[1] == Rv_size[0])) {
    if (((B_size[0] == 1) && (B_size[1] == 1)) || ((Rv_size[0] == 1) &&
         (Rv_size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((B_size[1] == 1) || (Rv_size[0] == 1)) {
    a_size_idx_0 = B_size[0];
    aoffset = Rv_size[1];
    coffset = B_size[0];
    for (boffset = 0; boffset < coffset; boffset++) {
      loop_ub = Rv_size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        a_data[boffset + a_size_idx_0 * i0] = 0.0;
        i = B_size[1];
        for (i1 = 0; i1 < i; i1++) {
          a_data[boffset + a_size_idx_0 * i0] += B_data[boffset + B_size[0] * i1]
            * Rv_data[i1 + Rv_size[0] * i0];
        }
      }
    }
  } else if ((B_size[0] == 0) || (B_size[1] == 0) || (Rv_size[0] == 0) ||
             (Rv_size[1] == 0)) {
    a_size_idx_0 = B_size[0];
    aoffset = Rv_size[1];
    coffset = B_size[0] * Rv_size[1];
    if (0 <= coffset - 1) {
      memset(&a_data[0], 0, (uint32_T)(coffset * (int32_T)sizeof(real_T)));
    }
  } else {
    TRANSA = 'N';
    TRANSB = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)B_size[0];
    n_t = (ptrdiff_t)Rv_size[1];
    k_t = (ptrdiff_t)B_size[1];
    lda_t = (ptrdiff_t)B_size[0];
    ldb_t = (ptrdiff_t)B_size[1];
    ldc_t = (ptrdiff_t)B_size[0];
    a_size_idx_0 = B_size[0];
    aoffset = Rv_size[1];
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &B_data[0], &lda_t,
          &Rv_data[0], &ldb_t, &beta1, &a_data[0], &ldc_t);
  }

  st.site = &e_emlrtRSI;
  i = B_size[1];
  b_size_idx_1 = B_size[0];
  coffset = B_size[0];
  for (boffset = 0; boffset < coffset; boffset++) {
    loop_ub = B_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_data[i0 + i * boffset] = B_data[boffset + B_size[0] * i0];
    }
  }

  b_st.site = &rc_emlrtRSI;
  if (!(aoffset == B_size[1])) {
    if (((a_size_idx_0 == 1) && (aoffset == 1)) || ((B_size[1] == 1) && (B_size
          [0] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((aoffset == 1) || (B_size[1] == 1)) {
    B_size[0] = a_size_idx_0;
    B_size[1] = b_size_idx_1;
    for (boffset = 0; boffset < a_size_idx_0; boffset++) {
      for (i0 = 0; i0 < b_size_idx_1; i0++) {
        B_data[boffset + a_size_idx_0 * i0] = 0.0;
        for (i1 = 0; i1 < aoffset; i1++) {
          B_data[boffset + a_size_idx_0 * i0] += a_data[boffset + a_size_idx_0 *
            i1] * b_data[i1 + i * i0];
        }
      }
    }
  } else if ((a_size_idx_0 == 0) || (aoffset == 0) || (B_size[1] == 0) ||
             (B_size[0] == 0)) {
    B_size[0] = a_size_idx_0;
    B_size[1] = b_size_idx_1;
    coffset = a_size_idx_0 * b_size_idx_1;
    if (0 <= coffset - 1) {
      memset(&B_data[0], 0, (uint32_T)(coffset * (int32_T)sizeof(real_T)));
    }
  } else {
    TRANSA = 'N';
    TRANSB = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)a_size_idx_0;
    n_t = (ptrdiff_t)B_size[0];
    k_t = (ptrdiff_t)aoffset;
    lda_t = (ptrdiff_t)a_size_idx_0;
    ldb_t = (ptrdiff_t)aoffset;
    ldc_t = (ptrdiff_t)a_size_idx_0;
    B_size[0] = a_size_idx_0;
    B_size[1] = b_size_idx_1;
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a_data[0], &lda_t,
          &b_data[0], &ldb_t, &beta1, &B_data[0], &ldc_t);
  }

  for (i = 0; i < 2; i++) {
    iv0[i] = 23;
    B[i] = B_size[i];
  }

  if ((23 != B[0]) || (23 != B[1])) {
    emlrtSizeEqCheckNDR2012b(&iv0[0], &B[0], &b_emlrtECI, sp);
  }

  st.site = &e_emlrtRSI;
  b_st.site = &rc_emlrtRSI;
  if (!(23 == P_km1_size[0])) {
    if ((P_km1_size[0] == 1) && (P_km1_size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if (P_km1_size[1] == 0) {
    aoffset = 0;
  } else {
    TRANSA = 'N';
    TRANSB = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)23;
    n_t = (ptrdiff_t)P_km1_size[1];
    k_t = (ptrdiff_t)23;
    lda_t = (ptrdiff_t)23;
    ldb_t = (ptrdiff_t)23;
    ldc_t = (ptrdiff_t)23;
    aoffset = P_km1_size[1];
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &A[0], &lda_t,
          &P_km1_data[0], &ldb_t, &beta1, &b_a_data[0], &ldc_t);
  }

  st.site = &e_emlrtRSI;
  for (boffset = 0; boffset < 23; boffset++) {
    for (i0 = 0; i0 < 23; i0++) {
      a_data[i0 + 23 * boffset] = A[boffset + 23 * i0];
    }
  }

  b_st.site = &rc_emlrtRSI;
  if (!(aoffset == 23)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "Coder:MATLAB:innerdim",
      "Coder:MATLAB:innerdim", 0);
  }

  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)23;
  n_t = (ptrdiff_t)23;
  k_t = (ptrdiff_t)23;
  lda_t = (ptrdiff_t)23;
  ldb_t = (ptrdiff_t)23;
  ldc_t = (ptrdiff_t)23;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b_a_data[0], &lda_t,
        &a_data[0], &ldb_t, &beta1, &P_kkm1[0], &ldc_t);
  for (boffset = 0; boffset < 529; boffset++) {
    P_kkm1[boffset] += B_data[boffset];
  }

  /*  Covariance of predicted observation and predicted state: */
  st.site = &f_emlrtRSI;
  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)23;
  n_t = (ptrdiff_t)3;
  k_t = (ptrdiff_t)23;
  lda_t = (ptrdiff_t)23;
  ldb_t = (ptrdiff_t)23;
  ldc_t = (ptrdiff_t)23;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &P_kkm1[0], &lda_t, &b[0],
        &ldb_t, &beta1, &P_xy[0], &ldc_t);

  /*  Covariance of predicted observation: */
  st.site = &g_emlrtRSI;
  b_st.site = &rc_emlrtRSI;
  if (!(3 == Rn_size[0])) {
    if ((Rn_size[0] == 1) && (Rn_size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if (Rn_size[1] == 0) {
    aoffset = 0;
  } else {
    TRANSA = 'N';
    TRANSB = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)3;
    n_t = (ptrdiff_t)Rn_size[1];
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)3;
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)3;
    aoffset = Rn_size[1];
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &Rn_data[0],
          &ldb_t, &beta1, &c_a_data[0], &ldc_t);
  }

  st.site = &g_emlrtRSI;
  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)3;
  n_t = (ptrdiff_t)23;
  k_t = (ptrdiff_t)23;
  lda_t = (ptrdiff_t)3;
  ldb_t = (ptrdiff_t)23;
  ldc_t = (ptrdiff_t)3;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b_a[0], &lda_t, &P_kkm1[0],
        &ldb_t, &beta1, &y[0], &ldc_t);
  st.site = &g_emlrtRSI;
  b_st.site = &rc_emlrtRSI;
  if (!(aoffset == 3)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "Coder:MATLAB:innerdim",
      "Coder:MATLAB:innerdim", 0);
  }

  for (b_size_idx_1 = 0; b_size_idx_1 < 3; b_size_idx_1++) {
    coffset = b_size_idx_1 * 3;
    boffset = b_size_idx_1 * 3 - 1;
    for (i = 0; i < 3; i++) {
      b_y[coffset + i] = 0.0;
    }

    for (a_size_idx_0 = 0; a_size_idx_0 < 3; a_size_idx_0++) {
      if (iv1[(boffset + a_size_idx_0) + 1] != 0) {
        aoffset = a_size_idx_0 * 3;
        for (i = 0; i < 3; i++) {
          b_y[coffset + i] += (real_T)iv1[(boffset + a_size_idx_0) + 1] *
            c_a_data[aoffset + i];
        }
      }
    }
  }

  for (boffset = 0; boffset < 3; boffset++) {
    for (i0 = 0; i0 < 3; i0++) {
      alpha1 = 0.0;
      for (i1 = 0; i1 < 23; i1++) {
        alpha1 += y[boffset + 3 * i1] * b[i1 + 23 * i0];
      }

      P_yy[boffset + 3 * i0] = alpha1 + b_y[boffset + 3 * i0];
    }
  }

  /*  Kalman gain: */
  st.site = &h_emlrtRSI;
  mrdivide(&st, P_xy, P_yy, K);

  /*  Correct the state: */
  if (x_kkm1_size[0] != 23) {
    emlrtSizeEqCheck1DR2012b(x_kkm1_size[0], 23, &c_emlrtECI, sp);
  }

  /*  Correct the covariance: */
  /*  P = P_kkm1 * (eye(Xdim) - K * C); */
  for (boffset = 0; boffset < 23; boffset++) {
    alpha1 = 0.0;
    for (i0 = 0; i0 < 3; i0++) {
      alpha1 += K[boffset + 23 * i0] * inov[i0];
      b_K[boffset + 23 * i0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        b_K[boffset + 23 * i0] += K[boffset + 23 * i1] * P_yy[i1 + 3 * i0];
      }
    }

    x[boffset] = x_kkm1_data[boffset] + alpha1;
  }

  for (boffset = 0; boffset < 23; boffset++) {
    for (i0 = 0; i0 < 3; i0++) {
      y[i0 + 3 * boffset] = b_K[i0 + 3 * boffset];
    }
  }

  st.site = &i_emlrtRSI;
  for (boffset = 0; boffset < 23; boffset++) {
    for (i0 = 0; i0 < 3; i0++) {
      b_K[i0 + 3 * boffset] = K[boffset + 23 * i0];
    }
  }

  TRANSA = 'N';
  TRANSB = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)23;
  n_t = (ptrdiff_t)23;
  k_t = (ptrdiff_t)3;
  lda_t = (ptrdiff_t)23;
  ldb_t = (ptrdiff_t)3;
  ldc_t = (ptrdiff_t)23;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &y[0], &lda_t, &b_K[0],
        &ldb_t, &beta1, &P[0], &ldc_t);
  for (boffset = 0; boffset < 529; boffset++) {
    P[boffset] = P_kkm1[boffset] - P[boffset];
  }

  /*  ekf */
}

/* End of code generation (ekf_opt.c) */
