/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ukf_opt.c
 *
 * Code generation for function 'ukf_opt'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "sum.h"
#include "ukf_opt_mexutil.h"
#include "indexShapeCheck.h"
#include "propagate_RRR_Additive.h"
#include "mrdivide.h"
#include "bsxfun.h"
#include "repmat.h"
#include "sqrt.h"
#include "svd.h"
#include "eml_int_forloop_overflow_check.h"
#include "xpotrf.h"
#include "error1.h"
#include "blkdiag.h"
#include "ukf_opt_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 50,    /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 51,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 53,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 64,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 67,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 68,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 70,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 73,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 84,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 86,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 90,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 91,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 96,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 97,  /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 100, /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 103, /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 106, /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 109, /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 112, /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 115, /* lineNo */
  "ukf_opt",                           /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 34,  /* lineNo */
  "chol",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/chol.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 74, /* lineNo */
  "chol",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/chol.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 91, /* lineNo */
  "chol",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/chol.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 92, /* lineNo */
  "chol",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/chol.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 52, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 114,/* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 118,/* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  25,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  69,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  19,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  21,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  66,                                  /* colNo */
  "state",                             /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  87,                                  /* colNo */
  "pNoise",                            /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  17,                                  /* colNo */
  "X_x_kkm1",                          /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  84,                                  /* lineNo */
  5,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  21,                                  /* colNo */
  "X_x_kkm1",                          /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  41,                                  /* colNo */
  "mNoise",                            /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  86,                                  /* lineNo */
  23,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  90,                                  /* lineNo */
  10,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  15,                                  /* colNo */
  "Y_kkm1",                            /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  86,                                  /* lineNo */
  5,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  91,                                  /* lineNo */
  10,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  93,                                  /* lineNo */
  8,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { 2,   /* nDims */
  100,                                 /* lineNo */
  12,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { 2,   /* nDims */
  103,                                 /* lineNo */
  10,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { 2,   /* nDims */
  106,                                 /* lineNo */
  10,                                  /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  112,                                 /* lineNo */
  5,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { 2,   /* nDims */
  115,                                 /* lineNo */
  5,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { 1,   /* nDims */
  115,                                 /* lineNo */
  1,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { 2,   /* nDims */
  115,                                 /* lineNo */
  1,                                   /* colNo */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 54,/* lineNo */
  15,                                  /* colNo */
  "chol",                              /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/chol.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 80,/* lineNo */
  23,                                  /* colNo */
  "chol",                              /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/chol.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  20,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  20,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  5,                                   /* colNo */
  "X",                                 /* aName */
  "ukf_opt",                           /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/ukf_opt.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void ukf_opt(const emlrtStack *sp, real_T t_km1, real_T t_k, const real_T
             x_km1_data[], const int32_T x_km1_size[1], const real_T u_km1_data[],
             const int32_T u_km1_size[1], real_T P_data[], int32_T P_size[2],
             const real_T y_k_data[], const int32_T y_k_size[1], const real_T
             Rv_data[], const int32_T Rv_size[2], const real_T Rn_data[], const
             int32_T Rn_size[2], real_T alpha, real_T beta, real_T kappa,
             boolean_T sigmaComputeMethod, real_T x_data[], int32_T x_size[1],
             real_T K_data[], int32_T K_size[2], real_T inov_data[], int32_T
             inov_size[1], real_T x_kkm1_data[], int32_T x_kkm1_size[1], real_T
             P_kkm1_data[], int32_T P_kkm1_size[2], real_T P_xy_data[], int32_T
             P_xy_size[2], real_T P_yy_data[], int32_T P_yy_size[2])
{
  boolean_T b0;
  int32_T L;
  int32_T Ns;
  real_T lambda;
  real_T b_gamma;
  real_T W_m_0;
  real_T W_c_0;
  real_T W_i;
  int32_T P_aug_size[2];
  int32_T x_aug_km1_size[1];
  int32_T loop_ub;
  real_T x_aug_km1_data[49];
  int32_T b_index;
  int32_T U_size[2];
  int32_T gamma_sqrt_P_aug_size[2];
  int32_T V_size[2];
  int32_T i13;
  int32_T U[2];
  int32_T jmax;
  int32_T b_loop_ub;
  int32_T i14;
  int32_T i;
  boolean_T empty_non_axis_sizes;
  char_T TRANSA;
  char_T TRANSB;
  int32_T c_loop_ub;
  int32_T i15;
  ptrdiff_t m_t;
  int32_T b_size_idx_0;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T X_aug_km1_size_idx_1;
  int32_T state_size[2];
  int32_T pNoise_size[2];
  real_T state_data[2277];
  int32_T mNoise_size[2];
  real_T pNoise_data[2277];
  int32_T X_x_kkm1_size[2];
  int32_T Y_kkm1_size[2];
  int32_T b_sp;
  real_T mNoise_data[297];
  real_T Y_kkm1_data[297];
  real_T X_data[23];
  int32_T X_size[1];
  real_T X_x_kkm1_data[2277];
  int32_T b_X_x_kkm1_size[2];
  real_T b_data[23];
  int32_T d_loop_ub;
  int32_T i16;
  int8_T tmp_data[23];
  int32_T b_state_size[1];
  real_T b_state_data[23];
  real_T y_data[23];
  int32_T b_Y_kkm1_size[2];
  int32_T b_pNoise_size[1];
  real_T b_pNoise_data[23];
  int32_T y_kkm1_size[1];
  real_T y_kkm1_data[3];
  int32_T c_X_x_kkm1_size[2];
  int8_T b_tmp_data[3];
  int32_T iv29[1];
  real_T b_mNoise_data[3];
  real_T X[3];
  int32_T y_size[2];
  real_T b_y_data[529];
  jmp_buf * volatile emlrtJBStack;
  ukf_optTLS *ukf_optTLSThread;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack f_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  ukf_optTLSThread = emlrtGetThreadStackData();
  b0 = false;

  /*  UKF: Unscented Kalman Filter */
  /*  This code is inspired form www.anuncommonlab.com. */
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
  /*  UKF tunning parameters: */
  /*        0 <  Alpha <= 1 */
  /*        0 <= Beta */
  /*        0 <= Kappa <= 3 */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  OUTPUTS: */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  x:        estimated state */
  /*  P:        estimated state covariance */
  /*  K:        Kalman Gain */
  /*  inov:     inovation signal */
  /*  x_kkm1:   predicted state mean */
  /*  P_kkm1:   predicted state covariance */
  /*  P_xy:     predicted state and observation covariance */
  /*  P_yy:     inovation covariance */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Dimensions: */
  /*  Number of states */
  /*  Number of noise states */
  /*  Number of observations */
  L = (x_km1_size[0] + Rv_size[0]) + Rn_size[0];

  /*  Dimension of augmented state */
  Ns = (L << 1) + 1;

  /*  Number of sigma points */
  /*  Weights: */
  st.site = &emlrtRSI;
  b_st.site = &u_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  lambda = alpha * alpha * ((real_T)L + kappa) - (real_T)L;
  b_gamma = (real_T)L + lambda;
  st.site = &b_emlrtRSI;
  b_sqrt(&st, &b_gamma);
  W_m_0 = lambda / ((real_T)L + lambda);
  st.site = &c_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  W_c_0 = ((W_m_0 + 1.0) - alpha * alpha) + beta;
  W_i = 1.0 / (2.0 * ((real_T)L + lambda));

  /*  Create the augmented system. */
  blkdiag(P_data, P_size, Rv_data, Rv_size, Rn_data, Rn_size,
          ukf_optTLSThread->f0.P_aug_data, P_aug_size);
  x_aug_km1_size[0] = (x_km1_size[0] + Rv_size[0]) + Rn_size[0];
  loop_ub = x_km1_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&x_aug_km1_data[0], &x_km1_data[0], (uint32_T)(loop_ub * (int32_T)
            sizeof(real_T)));
  }

  loop_ub = Rv_size[0];
  if (0 <= loop_ub - 1) {
    memset(&x_aug_km1_data[x_km1_size[0]], 0, (uint32_T)(((loop_ub + x_km1_size
              [0]) - x_km1_size[0]) * (int32_T)sizeof(real_T)));
  }

  loop_ub = Rn_size[0];
  if (0 <= loop_ub - 1) {
    memset(&x_aug_km1_data[x_km1_size[0] + Rv_size[0]], 0, (uint32_T)
           (((((loop_ub + x_km1_size[0]) + Rv_size[0]) - x_km1_size[0]) -
             Rv_size[0]) * (int32_T)sizeof(real_T)));
  }

  /*  Create the sigma points: */
  b_index = sigmaComputeMethod;
  switch (b_index) {
   case 0:
    /*  Compute sqrt(P_aug) with Cholesky factorization */
    st.site = &d_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    if (P_aug_size[0] != P_aug_size[1]) {
      emlrtErrorWithMessageIdR2018a(&b_st, &u_emlrtRTEI, "Coder:MATLAB:square",
        "Coder:MATLAB:square", 0);
    }

    if (P_aug_size[1] != 0) {
      c_st.site = &ab_emlrtRSI;
      b_index = xpotrf(&c_st, P_aug_size[1], ukf_optTLSThread->f0.P_aug_data,
                       P_aug_size[1]);
      if (b_index == 0) {
        jmax = P_aug_size[1];
      } else {
        jmax = b_index - 1;
        emlrtErrorWithMessageIdR2018a(&b_st, &v_emlrtRTEI, "Coder:MATLAB:posdef",
          "Coder:MATLAB:posdef", 0);
      }

      c_st.site = &bb_emlrtRSI;
      if ((!(1 > jmax)) && (jmax > 2147483646)) {
        d_st.site = &nb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (b_index = 2; b_index - 1 <= jmax; b_index++) {
        c_st.site = &cb_emlrtRSI;
        if ((!(b_index > jmax)) && (jmax > 2147483646)) {
          d_st.site = &nb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (i = b_index; i <= jmax; i++) {
          ukf_optTLSThread->f0.P_aug_data[(i + P_aug_size[0] * (b_index - 2)) -
            1] = 0.0;
        }
      }
    }

    gamma_sqrt_P_aug_size[0] = P_aug_size[1];
    gamma_sqrt_P_aug_size[1] = P_aug_size[0];
    loop_ub = P_aug_size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_loop_ub = P_aug_size[1];
      for (i14 = 0; i14 < b_loop_ub; i14++) {
        ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[i14 + gamma_sqrt_P_aug_size[0]
          * i13] = b_gamma * ukf_optTLSThread->f0.P_aug_data[i13 + P_aug_size[0]
          * i14];
      }
    }
    break;

   case 1:
    /*  Compute sqrt(P_aug) with SVD in case there is a 0 eigenvalue */
    st.site = &e_emlrtRSI;
    svd(&st, ukf_optTLSThread->f0.P_aug_data, P_aug_size,
        ukf_optTLSThread->f0.U_data, U_size,
        ukf_optTLSThread->f0.gamma_sqrt_P_aug_data, gamma_sqrt_P_aug_size,
        ukf_optTLSThread->f0.V_data, V_size);
    P_aug_size[0] = U_size[0];
    P_aug_size[1] = U_size[1];
    loop_ub = U_size[0] * U_size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      ukf_optTLSThread->f0.P_aug_data[i13] = b_gamma *
        ukf_optTLSThread->f0.U_data[i13];
    }

    st.site = &f_emlrtRSI;
    b_index = U_size[0];
    loop_ub = U_size[0] * U_size[1];
    for (i13 = 0; i13 < loop_ub; i13++) {
      ukf_optTLSThread->f0.X_aug_km1_data[i13] = b_gamma *
        ukf_optTLSThread->f0.U_data[i13];
    }

    b_st.site = &f_emlrtRSI;
    c_sqrt(&b_st, ukf_optTLSThread->f0.gamma_sqrt_P_aug_data,
           gamma_sqrt_P_aug_size);
    loop_ub = gamma_sqrt_P_aug_size[0] * gamma_sqrt_P_aug_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&ukf_optTLSThread->f0.b_data[0],
             &ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[0], (uint32_T)(loop_ub *
              (int32_T)sizeof(real_T)));
    }

    b_st.site = &oc_emlrtRSI;
    if (!(U_size[1] == gamma_sqrt_P_aug_size[0])) {
      if (((U_size[0] == 1) && (U_size[1] == 1)) || ((gamma_sqrt_P_aug_size[0] ==
            1) && (gamma_sqrt_P_aug_size[1] == 1))) {
        emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
          "Coder:MATLAB:innerdim", "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((U_size[1] == 1) || (gamma_sqrt_P_aug_size[0] == 1)) {
      U_size[1] = gamma_sqrt_P_aug_size[1];
      loop_ub = P_aug_size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        b_loop_ub = gamma_sqrt_P_aug_size[1];
        for (i14 = 0; i14 < b_loop_ub; i14++) {
          ukf_optTLSThread->f0.U_data[i13 + U_size[0] * i14] = 0.0;
          c_loop_ub = P_aug_size[1];
          for (i15 = 0; i15 < c_loop_ub; i15++) {
            ukf_optTLSThread->f0.U_data[i13 + U_size[0] * i14] +=
              ukf_optTLSThread->f0.P_aug_data[i13 + P_aug_size[0] * i15] *
              ukf_optTLSThread->f0.b_data[i15 + gamma_sqrt_P_aug_size[0] * i14];
          }
        }
      }
    } else {
      b_st.site = &nc_emlrtRSI;
      if ((U_size[0] == 0) || (U_size[1] == 0) || (gamma_sqrt_P_aug_size[0] == 0)
          || (gamma_sqrt_P_aug_size[1] == 0)) {
        U_size[1] = gamma_sqrt_P_aug_size[1];
        loop_ub = b_index * gamma_sqrt_P_aug_size[1];
        if (0 <= loop_ub - 1) {
          memset(&ukf_optTLSThread->f0.U_data[0], 0, (uint32_T)(loop_ub *
                  (int32_T)sizeof(real_T)));
        }
      } else {
        c_st.site = &pc_emlrtRSI;
        c_st.site = &qc_emlrtRSI;
        TRANSA = 'N';
        TRANSB = 'N';
        lambda = 1.0;
        b_gamma = 0.0;
        m_t = (ptrdiff_t)U_size[0];
        n_t = (ptrdiff_t)gamma_sqrt_P_aug_size[1];
        k_t = (ptrdiff_t)U_size[1];
        lda_t = (ptrdiff_t)U_size[0];
        ldb_t = (ptrdiff_t)U_size[1];
        ldc_t = (ptrdiff_t)U_size[0];
        U_size[1] = gamma_sqrt_P_aug_size[1];
        dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
              &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
              &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
              &ukf_optTLSThread->f0.U_data[0], &ldc_t);
      }
    }

    st.site = &f_emlrtRSI;
    loop_ub = U_size[0] * U_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&ukf_optTLSThread->f0.X_aug_km1_data[0],
             &ukf_optTLSThread->f0.U_data[0], (uint32_T)(loop_ub * (int32_T)
              sizeof(real_T)));
    }

    b_size_idx_0 = V_size[1];
    loop_ub = V_size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      b_loop_ub = V_size[1];
      for (i14 = 0; i14 < b_loop_ub; i14++) {
        ukf_optTLSThread->f0.b_data[i14 + b_size_idx_0 * i13] =
          ukf_optTLSThread->f0.V_data[i13 + V_size[0] * i14];
      }
    }

    b_st.site = &oc_emlrtRSI;
    if (!(U_size[1] == V_size[1])) {
      if (((U_size[0] == 1) && (U_size[1] == 1)) || ((V_size[1] == 1) &&
           (V_size[0] == 1))) {
        emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
          "Coder:MATLAB:innerdim", "Coder:MATLAB:innerdim", 0);
      }
    }

    if ((U_size[1] == 1) || (V_size[1] == 1)) {
      gamma_sqrt_P_aug_size[0] = U_size[0];
      gamma_sqrt_P_aug_size[1] = V_size[0];
      loop_ub = U_size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        b_loop_ub = V_size[0];
        for (i14 = 0; i14 < b_loop_ub; i14++) {
          ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[i13 +
            gamma_sqrt_P_aug_size[0] * i14] = 0.0;
          c_loop_ub = U_size[1];
          for (i15 = 0; i15 < c_loop_ub; i15++) {
            ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[i13 +
              gamma_sqrt_P_aug_size[0] * i14] += ukf_optTLSThread->f0.U_data[i13
              + U_size[0] * i15] * ukf_optTLSThread->f0.b_data[i15 +
              b_size_idx_0 * i14];
          }
        }
      }
    } else {
      b_st.site = &nc_emlrtRSI;
      if ((U_size[0] == 0) || (U_size[1] == 0) || (V_size[1] == 0) || (V_size[0]
           == 0)) {
        gamma_sqrt_P_aug_size[0] = U_size[0];
        gamma_sqrt_P_aug_size[1] = V_size[0];
        loop_ub = U_size[0] * V_size[0];
        if (0 <= loop_ub - 1) {
          memset(&ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[0], 0, (uint32_T)
                 (loop_ub * (int32_T)sizeof(real_T)));
        }
      } else {
        c_st.site = &pc_emlrtRSI;
        c_st.site = &qc_emlrtRSI;
        TRANSA = 'N';
        TRANSB = 'N';
        lambda = 1.0;
        b_gamma = 0.0;
        m_t = (ptrdiff_t)U_size[0];
        n_t = (ptrdiff_t)V_size[0];
        k_t = (ptrdiff_t)U_size[1];
        lda_t = (ptrdiff_t)U_size[0];
        ldb_t = (ptrdiff_t)U_size[1];
        ldc_t = (ptrdiff_t)U_size[0];
        gamma_sqrt_P_aug_size[0] = U_size[0];
        gamma_sqrt_P_aug_size[1] = V_size[0];
        dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
              &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
              &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
              &ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[0], &ldc_t);
      }
    }
    break;

   default:
    st.site = &g_emlrtRSI;
    h_error(&st);
    break;
  }

  st.site = &h_emlrtRSI;
  repmat(&st, x_aug_km1_data, x_aug_km1_size, L, ukf_optTLSThread->f0.U_data,
         U_size);
  for (i13 = 0; i13 < 2; i13++) {
    U[i13] = U_size[i13];
    V_size[i13] = gamma_sqrt_P_aug_size[i13];
  }

  if ((U[0] != V_size[0]) || (U[1] != V_size[1])) {
    emlrtSizeEqCheckNDR2012b(&U[0], &V_size[0], &c_emlrtECI, sp);
  }

  st.site = &h_emlrtRSI;
  repmat(&st, x_aug_km1_data, x_aug_km1_size, L, ukf_optTLSThread->f0.P_aug_data,
         P_aug_size);
  for (i13 = 0; i13 < 2; i13++) {
    U[i13] = P_aug_size[i13];
    V_size[i13] = gamma_sqrt_P_aug_size[i13];
  }

  if ((U[0] != V_size[0]) || (U[1] != V_size[1])) {
    emlrtSizeEqCheckNDR2012b(&U[0], &V_size[0], &d_emlrtECI, sp);
  }

  st.site = &h_emlrtRSI;
  loop_ub = U_size[0] * U_size[1] - 1;
  for (i13 = 0; i13 <= loop_ub; i13++) {
    ukf_optTLSThread->f0.U_data[i13] +=
      ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[i13];
  }

  loop_ub = P_aug_size[0] * P_aug_size[1] - 1;
  for (i13 = 0; i13 <= loop_ub; i13++) {
    ukf_optTLSThread->f0.P_aug_data[i13] -=
      ukf_optTLSThread->f0.gamma_sqrt_P_aug_data[i13];
  }

  b_st.site = &uc_emlrtRSI;
  if (!(x_aug_km1_size[0] == 0)) {
    L = x_aug_km1_size[0];
  } else if (!((U_size[0] == 0) || (U_size[1] == 0))) {
    L = U_size[0];
  } else if (!((P_aug_size[0] == 0) || (P_aug_size[1] == 0))) {
    L = P_aug_size[0];
  } else {
    L = 0;
    if (U_size[0] > 0) {
      L = U_size[0];
    }

    if (P_aug_size[0] > L) {
      L = P_aug_size[0];
    }
  }

  c_st.site = &vc_emlrtRSI;
  if ((x_aug_km1_size[0] == L) || (x_aug_km1_size[0] == 0)) {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
    emlrtErrorWithMessageIdR2018a(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((U_size[0] == L) || ((U_size[0] == 0) || (U_size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (!empty_non_axis_sizes) {
    emlrtErrorWithMessageIdR2018a(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((P_aug_size[0] == L) || ((P_aug_size[0] == 0) || (P_aug_size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (!empty_non_axis_sizes) {
    emlrtErrorWithMessageIdR2018a(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (L == 0);
  if (empty_non_axis_sizes || (!(x_aug_km1_size[0] == 0))) {
    b_index = 1;
  } else {
    b_index = 0;
  }

  if (empty_non_axis_sizes || (!((U_size[0] == 0) || (U_size[1] == 0)))) {
    i = U_size[1];
  } else {
    i = 0;
  }

  if (empty_non_axis_sizes || (!((P_aug_size[0] == 0) || (P_aug_size[1] == 0))))
  {
    jmax = P_aug_size[1];
  } else {
    jmax = 0;
  }

  X_aug_km1_size_idx_1 = (b_index + i) + jmax;
  for (i13 = 0; i13 < b_index; i13++) {
    for (i14 = 0; i14 < L; i14++) {
      ukf_optTLSThread->f0.X_aug_km1_data[i14 + L * i13] = x_aug_km1_data[i14 +
        L * i13];
    }
  }

  for (i13 = 0; i13 < i; i13++) {
    for (i14 = 0; i14 < L; i14++) {
      ukf_optTLSThread->f0.X_aug_km1_data[i14 + L * (i13 + b_index)] =
        ukf_optTLSThread->f0.U_data[i14 + L * i13];
    }
  }

  for (i13 = 0; i13 < jmax; i13++) {
    for (i14 = 0; i14 < L; i14++) {
      ukf_optTLSThread->f0.X_aug_km1_data[i14 + L * ((i13 + b_index) + i)] =
        ukf_optTLSThread->f0.P_aug_data[i14 + L * i13];
    }
  }

  /*  Predict sigma points and measurements: */
  if (1 > x_km1_size[0]) {
    loop_ub = 0;
  } else {
    if (!(1 <= L)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L, &bb_emlrtBCI, sp);
    }

    if (!(x_km1_size[0] <= L)) {
      emlrtDynamicBoundsCheckR2012b(x_km1_size[0], 1, L, &cb_emlrtBCI, sp);
    }

    loop_ub = x_km1_size[0];
  }

  state_size[0] = loop_ub;
  state_size[1] = X_aug_km1_size_idx_1;
  for (i13 = 0; i13 < X_aug_km1_size_idx_1; i13++) {
    for (i14 = 0; i14 < loop_ub; i14++) {
      state_data[i14 + loop_ub * i13] = ukf_optTLSThread->f0.X_aug_km1_data[i14
        + L * i13];
    }
  }

  loop_ub = Rv_size[0];
  pNoise_size[0] = Rv_size[0];
  pNoise_size[1] = X_aug_km1_size_idx_1;
  for (i13 = 0; i13 < X_aug_km1_size_idx_1; i13++) {
    for (i14 = 0; i14 < loop_ub; i14++) {
      i15 = (i14 + x_km1_size[0]) + 1;
      if (!((i15 >= 1) && (i15 <= L))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, L, &jb_emlrtBCI, sp);
      }

      pNoise_data[i14 + loop_ub * i13] = ukf_optTLSThread->f0.X_aug_km1_data
        [(i15 + L * i13) - 1];
    }
  }

  loop_ub = Rn_size[0];
  b_index = (x_km1_size[0] + Rv_size[0]) + 1;
  mNoise_size[0] = Rn_size[0];
  mNoise_size[1] = X_aug_km1_size_idx_1;
  for (i13 = 0; i13 < X_aug_km1_size_idx_1; i13++) {
    for (i14 = 0; i14 < loop_ub; i14++) {
      i15 = i14 + b_index;
      if (!((i15 >= 1) && (i15 <= L))) {
        emlrtDynamicBoundsCheckR2012b(i15, 1, L, &kb_emlrtBCI, sp);
      }

      mNoise_data[i14 + loop_ub * i13] = ukf_optTLSThread->f0.X_aug_km1_data
        [(i15 + L * i13) - 1];
    }
  }

  X_x_kkm1_size[0] = x_km1_size[0];
  X_x_kkm1_size[1] = Ns;
  Y_kkm1_size[0] = Rn_size[0];
  Y_kkm1_size[1] = Ns;
  b_index = Ns - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(X_data,X_size,d_loop_ub,i16,b_emlrtJBEnviron) \
 firstprivate(e_st,f_st,emlrtHadParallelError,tmp_data,b_state_size,b_state_data,b_pNoise_size,b_pNoise_data,b_tmp_data,iv29,b0,b_mNoise_data,X)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      e_st.prev = sp;
      e_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      e_st.site = NULL;
      emlrtSetJmpBuf(&e_st, &b_emlrtJBEnviron);
      f_st.prev = &e_st;
      f_st.tls = e_st.tls;
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (b_sp = 0; b_sp <= b_index; b_sp++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        d_loop_ub = (int8_T)X_x_kkm1_size[0] - 1;
        for (i16 = 0; i16 <= d_loop_ub; i16++) {
          tmp_data[i16] = (int8_T)i16;
        }

        i16 = b_sp + 1;
        if (!((i16 >= 1) && (i16 <= X_x_kkm1_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, X_x_kkm1_size[1], &fb_emlrtBCI,
            &e_st);
        }

        d_loop_ub = state_size[0];
        i16 = 1 + b_sp;
        if (!((i16 >= 1) && (i16 <= state_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, state_size[1], &db_emlrtBCI,
            &e_st);
        }

        b_state_size[0] = state_size[0];
        for (i16 = 0; i16 < d_loop_ub; i16++) {
          b_state_data[i16] = state_data[i16 + state_size[0] * b_sp];
        }

        d_loop_ub = pNoise_size[0];
        i16 = 1 + b_sp;
        if (!((i16 >= 1) && (i16 <= pNoise_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, pNoise_size[1], &eb_emlrtBCI,
            &e_st);
        }

        b_pNoise_size[0] = pNoise_size[0];
        for (i16 = 0; i16 < d_loop_ub; i16++) {
          b_pNoise_data[i16] = pNoise_data[i16 + pNoise_size[0] * b_sp];
        }

        f_st.site = &i_emlrtRSI;
        propagate_RRR_Additive(&f_st, t_km1, t_k, b_state_data, b_state_size,
          u_km1_data, u_km1_size, b_pNoise_data, b_pNoise_size, X_data, X_size);
        b_state_size[0] = (int8_T)X_x_kkm1_size[0];
        emlrtSubAssignSizeCheckR2012b(&b_state_size[0], 1, &X_size[0], 1,
          &e_emlrtECI, &e_st);
        d_loop_ub = X_size[0];
        for (i16 = 0; i16 < d_loop_ub; i16++) {
          X_x_kkm1_data[tmp_data[i16] + X_x_kkm1_size[0] * b_sp] = X_data[i16];
        }

        d_loop_ub = X_x_kkm1_size[0];
        i16 = 1 + b_sp;
        if (!((i16 >= 1) && (i16 <= X_x_kkm1_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, X_x_kkm1_size[1], &gb_emlrtBCI,
            &e_st);
        }

        for (i16 = 0; i16 < d_loop_ub; i16++) {
          X_data[i16] = X_x_kkm1_data[i16 + X_x_kkm1_size[0] * b_sp];
        }

        /*  This step is required by the parfor in matlab */
        f_st.site = &j_emlrtRSI;
        indexShapeCheck(&f_st, X_x_kkm1_size[0]);
        i16 = b_sp + 1;
        if (!((i16 >= 1) && (i16 <= mNoise_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, mNoise_size[1], &hb_emlrtBCI,
            &e_st);
        }

        if (3 != mNoise_size[0]) {
          emlrtSizeEqCheck1DR2012b(3, mNoise_size[0], &f_emlrtECI, &e_st);
        }

        d_loop_ub = (int8_T)Y_kkm1_size[0] - 1;
        for (i16 = 0; i16 <= d_loop_ub; i16++) {
          b_tmp_data[i16] = (int8_T)i16;
        }

        i16 = b_sp + 1;
        if (!((i16 >= 1) && (i16 <= Y_kkm1_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i16, 1, Y_kkm1_size[1], &ib_emlrtBCI,
            &e_st);
        }

        b_state_size[0] = (int8_T)Y_kkm1_size[0];
        if (!b0) {
          iv29[0] = 3;
          b0 = true;
        }

        emlrtSubAssignSizeCheckR2012b(&b_state_size[0], 1, &iv29[0], 1,
          &h_emlrtECI, &e_st);
        d_loop_ub = mNoise_size[0];
        for (i16 = 0; i16 < d_loop_ub; i16++) {
          b_mNoise_data[i16] = mNoise_data[i16 + mNoise_size[0] * b_sp];
        }

        for (i16 = 0; i16 < 3; i16++) {
          d_loop_ub = 4 + i16;
          if (!(d_loop_ub <= X_x_kkm1_size[0])) {
            emlrtDynamicBoundsCheckR2012b(d_loop_ub, 1, X_x_kkm1_size[0],
              &lb_emlrtBCI, &e_st);
          }

          X[i16] = X_data[d_loop_ub - 1] + b_mNoise_data[i16];
        }

        d_loop_ub = (int8_T)Y_kkm1_size[0];
        for (i16 = 0; i16 < d_loop_ub; i16++) {
          Y_kkm1_data[b_tmp_data[i16] + Y_kkm1_size[0] * b_sp] = X[i16];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&e_st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());

  /*  Expected prediction and measurement: */
  if (2 > X_x_kkm1_size[1]) {
    i13 = 0;
    i14 = 0;
  } else {
    i13 = 1;
    i14 = X_x_kkm1_size[1];
  }

  loop_ub = X_x_kkm1_size[0];
  x_kkm1_size[0] = X_x_kkm1_size[0];
  for (i15 = 0; i15 < loop_ub; i15++) {
    x_kkm1_data[i15] = W_m_0 * X_x_kkm1_data[i15];
  }

  b_loop_ub = X_x_kkm1_size[0];
  b_X_x_kkm1_size[0] = X_x_kkm1_size[0];
  b_X_x_kkm1_size[1] = i14 - i13;
  c_loop_ub = i14 - i13;
  for (i14 = 0; i14 < c_loop_ub; i14++) {
    for (i15 = 0; i15 < b_loop_ub; i15++) {
      state_data[i15 + b_loop_ub * i14] = X_x_kkm1_data[i15 + X_x_kkm1_size[0] *
        (i13 + i14)];
    }
  }

  st.site = &k_emlrtRSI;
  sum(state_data, b_X_x_kkm1_size, b_data, x_aug_km1_size);
  b_loop_ub = x_aug_km1_size[0];
  for (i13 = 0; i13 < b_loop_ub; i13++) {
    b_data[i13] *= W_i;
  }

  if (X_x_kkm1_size[0] != x_aug_km1_size[0]) {
    emlrtSizeEqCheck1DR2012b(X_x_kkm1_size[0], x_aug_km1_size[0], &g_emlrtECI,
      sp);
  }

  b_loop_ub = X_x_kkm1_size[0];
  for (i13 = 0; i13 < b_loop_ub; i13++) {
    x_kkm1_data[i13] += b_data[i13];
  }

  if (2 > Y_kkm1_size[1]) {
    i13 = 0;
    i14 = 0;
  } else {
    i13 = 1;
    i14 = Y_kkm1_size[1];
  }

  b_loop_ub = Y_kkm1_size[0];
  for (i15 = 0; i15 < b_loop_ub; i15++) {
    y_data[i15] = W_m_0 * Y_kkm1_data[i15];
  }

  b_loop_ub = Y_kkm1_size[0];
  b_Y_kkm1_size[0] = Y_kkm1_size[0];
  b_Y_kkm1_size[1] = i14 - i13;
  c_loop_ub = i14 - i13;
  for (i14 = 0; i14 < c_loop_ub; i14++) {
    for (i15 = 0; i15 < b_loop_ub; i15++) {
      mNoise_data[i15 + b_loop_ub * i14] = Y_kkm1_data[i15 + Y_kkm1_size[0] *
        (i13 + i14)];
    }
  }

  st.site = &l_emlrtRSI;
  sum(mNoise_data, b_Y_kkm1_size, b_data, x_aug_km1_size);
  b_loop_ub = x_aug_km1_size[0];
  for (i13 = 0; i13 < b_loop_ub; i13++) {
    b_data[i13] *= W_i;
  }

  if (Y_kkm1_size[0] != x_aug_km1_size[0]) {
    emlrtSizeEqCheck1DR2012b(Y_kkm1_size[0], x_aug_km1_size[0], &i_emlrtECI, sp);
  }

  y_kkm1_size[0] = Y_kkm1_size[0];
  b_loop_ub = Y_kkm1_size[0];
  for (i13 = 0; i13 < b_loop_ub; i13++) {
    y_kkm1_data[i13] = y_data[i13] + b_data[i13];
  }

  if (y_k_size[0] != Y_kkm1_size[0]) {
    emlrtSizeEqCheck1DR2012b(y_k_size[0], Y_kkm1_size[0], &j_emlrtECI, sp);
  }

  inov_size[0] = y_k_size[0];
  b_loop_ub = y_k_size[0];
  for (i13 = 0; i13 < b_loop_ub; i13++) {
    inov_data[i13] = y_k_data[i13] - y_kkm1_data[i13];
  }

  /*  Remove expectations from X_x_kkm1 and y_kkm1: */
  c_X_x_kkm1_size[0] = X_x_kkm1_size[0];
  c_X_x_kkm1_size[1] = X_x_kkm1_size[1];
  b_loop_ub = X_x_kkm1_size[0] * X_x_kkm1_size[1];
  if (0 <= b_loop_ub - 1) {
    memcpy(&state_data[0], &X_x_kkm1_data[0], (uint32_T)(b_loop_ub * (int32_T)
            sizeof(real_T)));
  }

  st.site = &m_emlrtRSI;
  bsxfun(&st, state_data, c_X_x_kkm1_size, x_kkm1_data, x_kkm1_size,
         X_x_kkm1_data, X_x_kkm1_size);
  st.site = &n_emlrtRSI;
  bsxfun(&st, Y_kkm1_data, Y_kkm1_size, y_kkm1_data, y_kkm1_size, state_data,
         state_size);
  Y_kkm1_size[0] = state_size[0];
  b_loop_ub = state_size[0] * state_size[1];
  if (0 <= b_loop_ub - 1) {
    memcpy(&Y_kkm1_data[0], &state_data[0], (uint32_T)(b_loop_ub * (int32_T)
            sizeof(real_T)));
  }

  /*  Calculate covariance of the prediction: */
  if (2 > X_x_kkm1_size[1]) {
    i13 = 1;
    i14 = 1;
    i15 = 0;
    b_index = 0;
  } else {
    i13 = 2;
    i14 = X_x_kkm1_size[1] + 1;
    i15 = 1;
    b_index = X_x_kkm1_size[1];
  }

  b_loop_ub = X_x_kkm1_size[0];
  c_loop_ub = X_x_kkm1_size[0];
  for (i = 0; i < b_loop_ub; i++) {
    y_data[i] = W_c_0 * X_x_kkm1_data[i];
  }

  if (0 <= c_loop_ub - 1) {
    memcpy(&b_data[0], &X_x_kkm1_data[0], (uint32_T)(c_loop_ub * (int32_T)sizeof
            (real_T)));
  }

  P_kkm1_size[0] = X_x_kkm1_size[0];
  P_kkm1_size[1] = X_x_kkm1_size[0];
  jmax = X_x_kkm1_size[0];
  for (i = 0; i < jmax; i++) {
    for (L = 0; L < c_loop_ub; L++) {
      P_kkm1_data[i + b_loop_ub * L] = y_data[i] * b_data[L];
    }
  }

  st.site = &o_emlrtRSI;
  c_loop_ub = X_x_kkm1_size[0];
  X_aug_km1_size_idx_1 = i14 - i13;
  jmax = i14 - i13;
  for (i = 0; i < jmax; i++) {
    for (L = 0; L < c_loop_ub; L++) {
      ukf_optTLSThread->f0.X_aug_km1_data[L + c_loop_ub * i] = X_x_kkm1_data[L +
        X_x_kkm1_size[0] * ((i13 + i) - 1)];
    }
  }

  jmax = X_x_kkm1_size[0];
  b_size_idx_0 = b_index - i15;
  for (i = 0; i < jmax; i++) {
    Ns = b_index - i15;
    for (L = 0; L < Ns; L++) {
      ukf_optTLSThread->f0.b_data[L + b_size_idx_0 * i] = X_x_kkm1_data[i +
        X_x_kkm1_size[0] * (i15 + L)];
    }
  }

  b_st.site = &oc_emlrtRSI;
  if (!(i14 - i13 == b_size_idx_0)) {
    if (((X_x_kkm1_size[0] == 1) && (i14 - i13 == 1)) || ((b_size_idx_0 == 1) &&
         (X_x_kkm1_size[0] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((i14 - i13 == 1) || (b_size_idx_0 == 1)) {
    P_aug_size[0] = X_x_kkm1_size[0];
    P_aug_size[1] = X_x_kkm1_size[0];
    Ns = X_x_kkm1_size[0];
    for (i13 = 0; i13 < Ns; i13++) {
      for (i14 = 0; i14 < jmax; i14++) {
        ukf_optTLSThread->f0.P_aug_data[i13 + c_loop_ub * i14] = 0.0;
        for (i15 = 0; i15 < X_aug_km1_size_idx_1; i15++) {
          ukf_optTLSThread->f0.P_aug_data[i13 + c_loop_ub * i14] +=
            ukf_optTLSThread->f0.X_aug_km1_data[i13 + c_loop_ub * i15] *
            ukf_optTLSThread->f0.b_data[i15 + b_size_idx_0 * i14];
        }
      }
    }
  } else {
    b_st.site = &nc_emlrtRSI;
    if ((X_x_kkm1_size[0] == 0) || (i14 - i13 == 0) || (b_size_idx_0 == 0) ||
        (X_x_kkm1_size[0] == 0)) {
      P_aug_size[0] = X_x_kkm1_size[0];
      P_aug_size[1] = X_x_kkm1_size[0];
      c_loop_ub = X_x_kkm1_size[0] * X_x_kkm1_size[0];
      if (0 <= c_loop_ub - 1) {
        memset(&ukf_optTLSThread->f0.P_aug_data[0], 0, (uint32_T)(c_loop_ub *
                (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &pc_emlrtRSI;
      c_st.site = &qc_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      b_gamma = 0.0;
      m_t = (ptrdiff_t)X_x_kkm1_size[0];
      n_t = (ptrdiff_t)X_x_kkm1_size[0];
      k_t = (ptrdiff_t)(i14 - i13);
      lda_t = (ptrdiff_t)X_x_kkm1_size[0];
      ldb_t = (ptrdiff_t)(i14 - i13);
      ldc_t = (ptrdiff_t)X_x_kkm1_size[0];
      P_aug_size[0] = X_x_kkm1_size[0];
      P_aug_size[1] = X_x_kkm1_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
            &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
            &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
            &ukf_optTLSThread->f0.P_aug_data[0], &ldc_t);
    }
  }

  c_loop_ub = P_aug_size[0] * P_aug_size[1] - 1;
  for (i13 = 0; i13 <= c_loop_ub; i13++) {
    ukf_optTLSThread->f0.P_aug_data[i13] *= W_i;
  }

  for (i13 = 0; i13 < 2; i13++) {
    V_size[i13] = P_kkm1_size[i13];
    U[i13] = P_aug_size[i13];
  }

  if ((V_size[0] != U[0]) || (V_size[1] != U[1])) {
    emlrtSizeEqCheckNDR2012b(&V_size[0], &U[0], &k_emlrtECI, sp);
  }

  c_loop_ub = X_x_kkm1_size[0] * X_x_kkm1_size[0] - 1;
  for (i13 = 0; i13 <= c_loop_ub; i13++) {
    P_kkm1_data[i13] += ukf_optTLSThread->f0.P_aug_data[i13];
  }

  /*  Covariance of predicted observation: */
  if (2 > state_size[1]) {
    i13 = 1;
    i14 = 1;
    i15 = 0;
    b_index = 0;
  } else {
    i13 = 2;
    i14 = state_size[1] + 1;
    i15 = 1;
    b_index = state_size[1];
  }

  c_loop_ub = state_size[0];
  jmax = state_size[0];
  for (i = 0; i < c_loop_ub; i++) {
    y_data[i] = W_c_0 * Y_kkm1_data[i];
  }

  if (0 <= jmax - 1) {
    memcpy(&b_data[0], &Y_kkm1_data[0], (uint32_T)(jmax * (int32_T)sizeof(real_T)));
  }

  y_size[0] = state_size[0];
  y_size[1] = state_size[0];
  Ns = state_size[0];
  for (i = 0; i < Ns; i++) {
    for (L = 0; L < jmax; L++) {
      b_y_data[i + c_loop_ub * L] = y_data[i] * b_data[L];
    }
  }

  st.site = &p_emlrtRSI;
  c_loop_ub = state_size[0];
  X_aug_km1_size_idx_1 = i14 - i13;
  jmax = i14 - i13;
  for (i = 0; i < jmax; i++) {
    for (L = 0; L < c_loop_ub; L++) {
      ukf_optTLSThread->f0.X_aug_km1_data[L + c_loop_ub * i] = Y_kkm1_data[L +
        Y_kkm1_size[0] * ((i13 + i) - 1)];
    }
  }

  jmax = state_size[0];
  b_size_idx_0 = b_index - i15;
  for (i = 0; i < jmax; i++) {
    Ns = b_index - i15;
    for (L = 0; L < Ns; L++) {
      ukf_optTLSThread->f0.b_data[L + b_size_idx_0 * i] = Y_kkm1_data[i +
        Y_kkm1_size[0] * (i15 + L)];
    }
  }

  b_st.site = &oc_emlrtRSI;
  if (!(i14 - i13 == b_size_idx_0)) {
    if (((state_size[0] == 1) && (i14 - i13 == 1)) || ((b_size_idx_0 == 1) &&
         (state_size[0] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((i14 - i13 == 1) || (b_size_idx_0 == 1)) {
    P_aug_size[0] = state_size[0];
    P_aug_size[1] = state_size[0];
    Ns = state_size[0];
    for (i13 = 0; i13 < Ns; i13++) {
      for (i14 = 0; i14 < jmax; i14++) {
        ukf_optTLSThread->f0.P_aug_data[i13 + c_loop_ub * i14] = 0.0;
        for (i15 = 0; i15 < X_aug_km1_size_idx_1; i15++) {
          ukf_optTLSThread->f0.P_aug_data[i13 + c_loop_ub * i14] +=
            ukf_optTLSThread->f0.X_aug_km1_data[i13 + c_loop_ub * i15] *
            ukf_optTLSThread->f0.b_data[i15 + b_size_idx_0 * i14];
        }
      }
    }
  } else {
    b_st.site = &nc_emlrtRSI;
    if ((state_size[0] == 0) || (i14 - i13 == 0) || (b_size_idx_0 == 0) ||
        (state_size[0] == 0)) {
      P_aug_size[0] = state_size[0];
      P_aug_size[1] = state_size[0];
      c_loop_ub = state_size[0] * state_size[0];
      if (0 <= c_loop_ub - 1) {
        memset(&ukf_optTLSThread->f0.P_aug_data[0], 0, (uint32_T)(c_loop_ub *
                (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &pc_emlrtRSI;
      c_st.site = &qc_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      b_gamma = 0.0;
      m_t = (ptrdiff_t)state_size[0];
      n_t = (ptrdiff_t)state_size[0];
      k_t = (ptrdiff_t)(i14 - i13);
      lda_t = (ptrdiff_t)state_size[0];
      ldb_t = (ptrdiff_t)(i14 - i13);
      ldc_t = (ptrdiff_t)state_size[0];
      P_aug_size[0] = state_size[0];
      P_aug_size[1] = state_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
            &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
            &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
            &ukf_optTLSThread->f0.P_aug_data[0], &ldc_t);
    }
  }

  c_loop_ub = P_aug_size[0] * P_aug_size[1] - 1;
  for (i13 = 0; i13 <= c_loop_ub; i13++) {
    ukf_optTLSThread->f0.P_aug_data[i13] *= W_i;
  }

  for (i13 = 0; i13 < 2; i13++) {
    V_size[i13] = y_size[i13];
    U[i13] = P_aug_size[i13];
  }

  if ((V_size[0] != U[0]) || (V_size[1] != U[1])) {
    emlrtSizeEqCheckNDR2012b(&V_size[0], &U[0], &l_emlrtECI, sp);
  }

  P_yy_size[0] = state_size[0];
  P_yy_size[1] = state_size[0];
  c_loop_ub = state_size[0] * state_size[0];
  for (i13 = 0; i13 < c_loop_ub; i13++) {
    P_yy_data[i13] = b_y_data[i13] + ukf_optTLSThread->f0.P_aug_data[i13];
  }

  /*  Covariance of predicted observation and predicted state: */
  if (2 > X_x_kkm1_size[1]) {
    i13 = 1;
    i14 = 1;
  } else {
    i13 = 2;
    i14 = X_x_kkm1_size[1] + 1;
  }

  if (2 > state_size[1]) {
    i15 = 0;
    b_index = 0;
  } else {
    i15 = 1;
    b_index = state_size[1];
  }

  c_loop_ub = X_x_kkm1_size[0];
  jmax = state_size[0];
  for (i = 0; i < c_loop_ub; i++) {
    y_data[i] = W_c_0 * X_x_kkm1_data[i];
  }

  if (0 <= jmax - 1) {
    memcpy(&b_data[0], &Y_kkm1_data[0], (uint32_T)(jmax * (int32_T)sizeof(real_T)));
  }

  y_size[0] = X_x_kkm1_size[0];
  y_size[1] = state_size[0];
  Ns = X_x_kkm1_size[0];
  for (i = 0; i < Ns; i++) {
    for (L = 0; L < jmax; L++) {
      b_y_data[i + c_loop_ub * L] = y_data[i] * b_data[L];
    }
  }

  st.site = &q_emlrtRSI;
  c_loop_ub = X_x_kkm1_size[0];
  X_aug_km1_size_idx_1 = i14 - i13;
  jmax = i14 - i13;
  for (i = 0; i < jmax; i++) {
    for (L = 0; L < c_loop_ub; L++) {
      ukf_optTLSThread->f0.X_aug_km1_data[L + c_loop_ub * i] = X_x_kkm1_data[L +
        X_x_kkm1_size[0] * ((i13 + i) - 1)];
    }
  }

  jmax = state_size[0];
  b_size_idx_0 = b_index - i15;
  for (i = 0; i < jmax; i++) {
    Ns = b_index - i15;
    for (L = 0; L < Ns; L++) {
      ukf_optTLSThread->f0.b_data[L + b_size_idx_0 * i] = Y_kkm1_data[i +
        Y_kkm1_size[0] * (i15 + L)];
    }
  }

  b_st.site = &oc_emlrtRSI;
  if (!(i14 - i13 == b_size_idx_0)) {
    if (((X_x_kkm1_size[0] == 1) && (i14 - i13 == 1)) || ((b_size_idx_0 == 1) &&
         (state_size[0] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((i14 - i13 == 1) || (b_size_idx_0 == 1)) {
    P_aug_size[0] = X_x_kkm1_size[0];
    P_aug_size[1] = state_size[0];
    Ns = X_x_kkm1_size[0];
    for (i13 = 0; i13 < Ns; i13++) {
      for (i14 = 0; i14 < jmax; i14++) {
        ukf_optTLSThread->f0.P_aug_data[i13 + c_loop_ub * i14] = 0.0;
        for (i15 = 0; i15 < X_aug_km1_size_idx_1; i15++) {
          ukf_optTLSThread->f0.P_aug_data[i13 + c_loop_ub * i14] +=
            ukf_optTLSThread->f0.X_aug_km1_data[i13 + c_loop_ub * i15] *
            ukf_optTLSThread->f0.b_data[i15 + b_size_idx_0 * i14];
        }
      }
    }
  } else {
    b_st.site = &nc_emlrtRSI;
    if ((X_x_kkm1_size[0] == 0) || (i14 - i13 == 0) || (b_size_idx_0 == 0) ||
        (state_size[0] == 0)) {
      P_aug_size[0] = X_x_kkm1_size[0];
      P_aug_size[1] = state_size[0];
      c_loop_ub = X_x_kkm1_size[0] * state_size[0];
      if (0 <= c_loop_ub - 1) {
        memset(&ukf_optTLSThread->f0.P_aug_data[0], 0, (uint32_T)(c_loop_ub *
                (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &pc_emlrtRSI;
      c_st.site = &qc_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      b_gamma = 0.0;
      m_t = (ptrdiff_t)X_x_kkm1_size[0];
      n_t = (ptrdiff_t)state_size[0];
      k_t = (ptrdiff_t)(i14 - i13);
      lda_t = (ptrdiff_t)X_x_kkm1_size[0];
      ldb_t = (ptrdiff_t)(i14 - i13);
      ldc_t = (ptrdiff_t)X_x_kkm1_size[0];
      P_aug_size[0] = X_x_kkm1_size[0];
      P_aug_size[1] = state_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
            &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
            &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
            &ukf_optTLSThread->f0.P_aug_data[0], &ldc_t);
    }
  }

  c_loop_ub = P_aug_size[0] * P_aug_size[1] - 1;
  for (i13 = 0; i13 <= c_loop_ub; i13++) {
    ukf_optTLSThread->f0.P_aug_data[i13] *= W_i;
  }

  for (i13 = 0; i13 < 2; i13++) {
    V_size[i13] = y_size[i13];
    U[i13] = P_aug_size[i13];
  }

  if ((V_size[0] != U[0]) || (V_size[1] != U[1])) {
    emlrtSizeEqCheckNDR2012b(&V_size[0], &U[0], &m_emlrtECI, sp);
  }

  P_xy_size[0] = X_x_kkm1_size[0];
  P_xy_size[1] = state_size[0];
  c_loop_ub = X_x_kkm1_size[0] * state_size[0];
  for (i13 = 0; i13 < c_loop_ub; i13++) {
    P_xy_data[i13] = b_y_data[i13] + ukf_optTLSThread->f0.P_aug_data[i13];
  }

  /*  Compute the Kalman gain: */
  st.site = &r_emlrtRSI;
  mrdivide(&st, P_xy_data, P_xy_size, P_yy_data, P_yy_size, K_data, K_size);

  /*  Correct the state: */
  st.site = &s_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  if (!(K_size[1] == y_k_size[0])) {
    if (((K_size[0] == 1) && (K_size[1] == 1)) || (y_k_size[0] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((K_size[1] == 1) || (y_k_size[0] == 1)) {
    x_size[0] = K_size[0];
    c_loop_ub = K_size[0];
    for (i13 = 0; i13 < c_loop_ub; i13++) {
      x_data[i13] = 0.0;
      jmax = K_size[1];
      for (i14 = 0; i14 < jmax; i14++) {
        x_data[i13] += K_data[i13 + K_size[0] * i14] * inov_data[i14];
      }
    }
  } else {
    b_st.site = &nc_emlrtRSI;
    if ((K_size[0] == 0) || (K_size[1] == 0) || (y_k_size[0] == 0)) {
      x_size[0] = K_size[0];
      c_loop_ub = K_size[0];
      if (0 <= c_loop_ub - 1) {
        memset(&x_data[0], 0, (uint32_T)(c_loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &pc_emlrtRSI;
      c_st.site = &qc_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      b_gamma = 0.0;
      m_t = (ptrdiff_t)K_size[0];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)K_size[1];
      lda_t = (ptrdiff_t)K_size[0];
      ldb_t = (ptrdiff_t)K_size[1];
      ldc_t = (ptrdiff_t)K_size[0];
      x_size[0] = K_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda, &K_data[0], &lda_t,
            &inov_data[0], &ldb_t, &b_gamma, &x_data[0], &ldc_t);
    }
  }

  if (loop_ub != x_size[0]) {
    emlrtSizeEqCheck1DR2012b(loop_ub, x_size[0], &n_emlrtECI, sp);
  }

  x_size[0] = loop_ub;
  for (i13 = 0; i13 < loop_ub; i13++) {
    x_data[i13] += x_kkm1_data[i13];
  }

  /*  Correct the covariance: */
  st.site = &t_emlrtRSI;
  loop_ub = K_size[0] * K_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&ukf_optTLSThread->f0.X_aug_km1_data[0], &K_data[0], (uint32_T)
           (loop_ub * (int32_T)sizeof(real_T)));
  }

  loop_ub = state_size[0] * state_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&ukf_optTLSThread->f0.b_data[0], &P_yy_data[0], (uint32_T)(loop_ub *
            (int32_T)sizeof(real_T)));
  }

  b_st.site = &oc_emlrtRSI;
  if (!(K_size[1] == state_size[0])) {
    if (((K_size[0] == 1) && (K_size[1] == 1)) || (state_size[0] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((K_size[1] == 1) || (state_size[0] == 1)) {
    P_aug_size[0] = K_size[0];
    P_aug_size[1] = state_size[0];
    loop_ub = K_size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      c_loop_ub = P_yy_size[1];
      for (i14 = 0; i14 < c_loop_ub; i14++) {
        ukf_optTLSThread->f0.P_aug_data[i13 + P_aug_size[0] * i14] = 0.0;
        jmax = K_size[1];
        for (i15 = 0; i15 < jmax; i15++) {
          ukf_optTLSThread->f0.P_aug_data[i13 + P_aug_size[0] * i14] +=
            K_data[i13 + K_size[0] * i15] * P_yy_data[i15 + P_yy_size[0] * i14];
        }
      }
    }
  } else {
    b_st.site = &nc_emlrtRSI;
    if ((K_size[0] == 0) || (K_size[1] == 0) || (state_size[0] == 0) ||
        (state_size[0] == 0)) {
      P_aug_size[0] = K_size[0];
      P_aug_size[1] = state_size[0];
      loop_ub = K_size[0] * state_size[0];
      if (0 <= loop_ub - 1) {
        memset(&ukf_optTLSThread->f0.P_aug_data[0], 0, (uint32_T)(loop_ub *
                (int32_T)sizeof(real_T)));
      }
    } else {
      c_st.site = &pc_emlrtRSI;
      c_st.site = &qc_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      b_gamma = 0.0;
      m_t = (ptrdiff_t)K_size[0];
      n_t = (ptrdiff_t)state_size[0];
      k_t = (ptrdiff_t)K_size[1];
      lda_t = (ptrdiff_t)K_size[0];
      ldb_t = (ptrdiff_t)K_size[1];
      ldc_t = (ptrdiff_t)K_size[0];
      P_aug_size[0] = K_size[0];
      P_aug_size[1] = state_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
            &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
            &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
            &ukf_optTLSThread->f0.P_aug_data[0], &ldc_t);
    }
  }

  st.site = &t_emlrtRSI;
  loop_ub = P_aug_size[0] * P_aug_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&ukf_optTLSThread->f0.X_aug_km1_data[0],
           &ukf_optTLSThread->f0.P_aug_data[0], (uint32_T)(loop_ub * (int32_T)
            sizeof(real_T)));
  }

  b_size_idx_0 = K_size[1];
  loop_ub = K_size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    c_loop_ub = K_size[1];
    for (i14 = 0; i14 < c_loop_ub; i14++) {
      ukf_optTLSThread->f0.b_data[i14 + b_size_idx_0 * i13] = K_data[i13 +
        K_size[0] * i14];
    }
  }

  b_st.site = &oc_emlrtRSI;
  if (!(P_aug_size[1] == K_size[1])) {
    if (((P_aug_size[0] == 1) && (P_aug_size[1] == 1)) || ((K_size[1] == 1) &&
         (K_size[0] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &x_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI, "Coder:MATLAB:innerdim",
        "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((P_aug_size[1] == 1) || (K_size[1] == 1)) {
    U_size[0] = P_aug_size[0];
    U_size[1] = K_size[0];
    loop_ub = P_aug_size[0];
    for (i13 = 0; i13 < loop_ub; i13++) {
      c_loop_ub = K_size[0];
      for (i14 = 0; i14 < c_loop_ub; i14++) {
        ukf_optTLSThread->f0.U_data[i13 + U_size[0] * i14] = 0.0;
        jmax = P_aug_size[1];
        for (i15 = 0; i15 < jmax; i15++) {
          ukf_optTLSThread->f0.U_data[i13 + U_size[0] * i14] +=
            ukf_optTLSThread->f0.P_aug_data[i13 + P_aug_size[0] * i15] *
            ukf_optTLSThread->f0.b_data[i15 + b_size_idx_0 * i14];
        }
      }
    }
  } else {
    b_st.site = &nc_emlrtRSI;
    if ((P_aug_size[0] == 0) || (P_aug_size[1] == 0) || (K_size[1] == 0) ||
        (K_size[0] == 0)) {
      U_size[0] = P_aug_size[0];
      U_size[1] = K_size[0];
      loop_ub = P_aug_size[0] * K_size[0];
      if (0 <= loop_ub - 1) {
        memset(&ukf_optTLSThread->f0.U_data[0], 0, (uint32_T)(loop_ub * (int32_T)
                sizeof(real_T)));
      }
    } else {
      c_st.site = &pc_emlrtRSI;
      c_st.site = &qc_emlrtRSI;
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      b_gamma = 0.0;
      m_t = (ptrdiff_t)P_aug_size[0];
      n_t = (ptrdiff_t)K_size[0];
      k_t = (ptrdiff_t)P_aug_size[1];
      lda_t = (ptrdiff_t)P_aug_size[0];
      ldb_t = (ptrdiff_t)P_aug_size[1];
      ldc_t = (ptrdiff_t)P_aug_size[0];
      U_size[0] = P_aug_size[0];
      U_size[1] = K_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda,
            &ukf_optTLSThread->f0.X_aug_km1_data[0], &lda_t,
            &ukf_optTLSThread->f0.b_data[0], &ldb_t, &b_gamma,
            &ukf_optTLSThread->f0.U_data[0], &ldc_t);
    }
  }

  for (i13 = 0; i13 < 2; i13++) {
    V_size[i13] = P_kkm1_size[i13];
    U[i13] = U_size[i13];
  }

  if ((V_size[0] != U[0]) || (V_size[1] != U[1])) {
    emlrtSizeEqCheckNDR2012b(&V_size[0], &U[0], &o_emlrtECI, sp);
  }

  if (23 < X_x_kkm1_size[0]) {
    emlrtDimSizeGeqCheckR2012b(23, X_x_kkm1_size[0], &p_emlrtECI, sp);
    emlrtDimSizeGeqCheckR2012b(23, X_x_kkm1_size[0], &q_emlrtECI, sp);
  }

  P_size[0] = X_x_kkm1_size[0];
  P_size[1] = X_x_kkm1_size[0];
  loop_ub = X_x_kkm1_size[0];
  for (i13 = 0; i13 < loop_ub; i13++) {
    for (i14 = 0; i14 < b_loop_ub; i14++) {
      P_data[i14 + P_size[0] * i13] = P_kkm1_data[i14 + b_loop_ub * i13] -
        ukf_optTLSThread->f0.U_data[i14 + U_size[0] * i13];
    }
  }

  /*  ukf */
}

/* End of code generation (ukf_opt.c) */
