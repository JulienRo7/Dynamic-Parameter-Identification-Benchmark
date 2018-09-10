/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * srukf_opt.c
 *
 * Code generation for function 'srukf_opt'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "sum.h"
#include "srukf_opt_emxutil.h"
#include "srukf_opt_mexutil.h"
#include "indexShapeCheck.h"
#include "propagate_RRR_Additive.h"
#include "cholupdate.h"
#include "mrdivide.h"
#include "qr.h"
#include "bsxfun.h"
#include "repmat.h"
#include "blkdiag.h"
#include "sqrt.h"
#include "srukf_opt_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 49,    /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 50,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 52,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 53,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 55,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 63,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 74,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 76,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 80,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 81,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 86,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 87,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 90,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 94,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 96,  /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 100, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 104, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 106, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 112, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 115, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 118, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 119, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 123, /* lineNo */
  "srukf_opt",                         /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 52, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 21, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo r_emlrtRTEI = { 106,/* lineNo */
  5,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 104,/* lineNo */
  5,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 109,/* lineNo */
  8,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 109,/* lineNo */
  1,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 112,/* lineNo */
  82,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 115,/* lineNo */
  11,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  63,                                  /* lineNo */
  25,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  63,                                  /* lineNo */
  62,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  19,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  21,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  66,                                  /* colNo */
  "state",                             /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  87,                                  /* colNo */
  "pNoise",                            /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  17,                                  /* colNo */
  "X_x_kkm1",                          /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  74,                                  /* lineNo */
  5,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  21,                                  /* colNo */
  "X_x_kkm1",                          /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  41,                                  /* colNo */
  "mNoise",                            /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  76,                                  /* lineNo */
  23,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  80,                                  /* lineNo */
  10,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  15,                                  /* colNo */
  "Y_kkm1",                            /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  81,                                  /* lineNo */
  10,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  83,                                  /* lineNo */
  8,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  39,                                  /* colNo */
  "X_x_kkm1",                          /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  41,                                  /* colNo */
  "X_x_kkm1",                          /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  35,                                  /* colNo */
  "Y_kkm1",                            /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  100,                                 /* lineNo */
  37,                                  /* colNo */
  "Y_kkm1",                            /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo k_emlrtECI = { 2,   /* nDims */
  112,                                 /* lineNo */
  10,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  118,                                 /* lineNo */
  5,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  123,                                 /* lineNo */
  36,                                  /* colNo */
  "U",                                 /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo m_emlrtECI = { 1,   /* nDims */
  125,                                 /* lineNo */
  1,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { 2,   /* nDims */
  125,                                 /* lineNo */
  1,                                   /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 88,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 83,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  20,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  20,                                  /* colNo */
  "X_aug_km1",                         /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  5,                                   /* colNo */
  "X",                                 /* aName */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void srukf_opt(const emlrtStack *sp, real_T t_km1, real_T t_k, const real_T
               x_km1_data[], const int32_T x_km1_size[1], const real_T
               u_km1_data[], const int32_T u_km1_size[1], real_T S_data[],
               int32_T S_size[2], const real_T y_k_data[], const int32_T
               y_k_size[1], const real_T Sv_data[], const int32_T Sv_size[2],
               const real_T Sn_data[], const int32_T Sn_size[2], real_T alpha,
               real_T beta, real_T kappa, real_T x_data[], int32_T x_size[1],
               real_T K_data[], int32_T K_size[2], real_T inov_data[], int32_T
               inov_size[1], real_T x_kkm1_data[], int32_T x_kkm1_size[1],
               real_T S_kkm1_data[], int32_T S_kkm1_size[2], real_T P_xy_data[],
               int32_T P_xy_size[2], emxArray_real_T *S_yy)
{
  boolean_T b0;
  int32_T Ydim;
  int32_T L;
  int32_T Ns;
  real_T lambda;
  real_T b_gamma;
  real_T W_m_0;
  real_T W_c_0;
  real_T sqrtW_c_0;
  real_T W_i;
  real_T sqrtW_c_i;
  int32_T x_aug_km1_size[1];
  int32_T loop_ub;
  real_T x_aug_km1_data[49];
  real_T varargin_2_data[2401];
  int32_T varargin_2_size[2];
  int32_T X_aug_km1_size[2];
  int32_T i8;
  int32_T varargin_2[2];
  int32_T X_aug_km1[2];
  real_T varargin_3_data[2401];
  int32_T varargin_3_size[2];
  int32_T result;
  boolean_T empty_non_axis_sizes;
  int32_T b_result;
  int32_T c_result;
  int32_T i9;
  int32_T b_loop_ub;
  int32_T state_size[2];
  int32_T pNoise_size[2];
  real_T state_data[2277];
  int32_T i10;
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
  int32_T c_loop_ub;
  int32_T i11;
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
  int32_T iv27[1];
  real_T b_mNoise_data[3];
  int32_T sqrtW_c_i_size[2];
  real_T X[3];
  real_T unusedU0_data[2277];
  real_T b_S_kkm1_data[2277];
  int32_T sqrtW_c_0_size[1];
  int32_T b_sqrtW_c_i_size[2];
  int32_T b_sqrtW_c_0_size[1];
  emxArray_real_T *b_S_yy;
  emxArray_real_T *b;
  char_T TRANSA;
  char_T TRANSB;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T c_state_size[1];
  int32_T b_S_kkm1_size[2];
  jmp_buf * volatile emlrtJBStack;
  srukf_optTLS *srukf_optTLSThread;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack e_st;
  boolean_T emlrtHadParallelError = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  srukf_optTLSThread = emlrtGetThreadStackData();
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  b0 = false;

  /*  SRUKF: Square Root Unscented Kalman Filter */
  /*  Authors: Julien Roux, Quentin Leboutet, Alexandre Janot */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  INPUTS: */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  x_km1:    state mean at time k-1 */
  /*  S_km1:    matrix square root of state covariance at time k-1 */
  /*  u_km1:    control input at time k-1 */
  /*  y_k:      noisy observation at time k */
  /*  Sv:       matrix square root of process noise covariance matrix */
  /*  Sn:       matrix square root of observation noise covariance matrix */
  /*  UKF tunning parameters: */
  /*        0 <  Alpha <= 1 */
  /*        0 <= Beta */
  /*        0 <= Kappa <= 3 */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  OUTPUTS: */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  x:        estimated state */
  /*  S:        matrix square root of estimated state covariance */
  /*  K:        Kalman Gain */
  /*  inov:     inovation signal */
  /*  x_kkm1:   predicted state mean */
  /*  S_kkm1:   matrix square root of predicted state covariance */
  /*  P_xy:     predicted state and observation covariance */
  /*  S_yy:     matrix square root of inovation covariance */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Dimensions: */
  /*  Number of states */
  /*  Number of noise states */
  Ydim = Sn_size[0];

  /*  Number of observations */
  L = (x_km1_size[0] + Sv_size[0]) + Sn_size[0];

  /*  Dimension of augmented state */
  Ns = (L << 1) + 1;

  /*  Number of sigma points */
  /*  Weights: */
  st.site = &emlrtRSI;
  b_st.site = &x_emlrtRSI;
  lambda = alpha * alpha * ((real_T)L + kappa) - (real_T)L;
  b_gamma = (real_T)L + lambda;
  st.site = &b_emlrtRSI;
  b_sqrt(&st, &b_gamma);
  W_m_0 = lambda / ((real_T)L + lambda);
  st.site = &c_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  W_c_0 = ((W_m_0 + 1.0) - alpha * alpha) + beta;
  sqrtW_c_0 = muDoubleScalarAbs(W_c_0);
  st.site = &d_emlrtRSI;
  b_sqrt(&st, &sqrtW_c_0);
  W_i = 1.0 / (2.0 * ((real_T)L + lambda));
  sqrtW_c_i = W_i;
  st.site = &e_emlrtRSI;
  b_sqrt(&st, &sqrtW_c_i);

  /*  Create the augmented system: */
  x_aug_km1_size[0] = (x_km1_size[0] + Sv_size[0]) + Sn_size[0];
  loop_ub = x_km1_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&x_aug_km1_data[0], &x_km1_data[0], (uint32_T)(loop_ub * (int32_T)
            sizeof(real_T)));
  }

  loop_ub = Sv_size[0];
  if (0 <= loop_ub - 1) {
    memset(&x_aug_km1_data[x_km1_size[0]], 0, (uint32_T)(((loop_ub + x_km1_size
              [0]) - x_km1_size[0]) * (int32_T)sizeof(real_T)));
  }

  loop_ub = Sn_size[0];
  if (0 <= loop_ub - 1) {
    memset(&x_aug_km1_data[x_km1_size[0] + Sv_size[0]], 0, (uint32_T)
           (((((loop_ub + x_km1_size[0]) + Sv_size[0]) - x_km1_size[0]) -
             Sv_size[0]) * (int32_T)sizeof(real_T)));
  }

  /*  Create the sigma points: */
  blkdiag(S_data, S_size, Sv_data, Sv_size, Sn_data, Sn_size, varargin_2_data,
          varargin_2_size);
  X_aug_km1_size[0] = varargin_2_size[0];
  X_aug_km1_size[1] = varargin_2_size[1];
  loop_ub = varargin_2_size[0] * varargin_2_size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    srukf_optTLSThread->f0.X_aug_km1_data[i8] = b_gamma * varargin_2_data[i8];
  }

  st.site = &f_emlrtRSI;
  repmat(&st, x_aug_km1_data, x_aug_km1_size, L, varargin_2_data,
         varargin_2_size);
  for (i8 = 0; i8 < 2; i8++) {
    varargin_2[i8] = varargin_2_size[i8];
    X_aug_km1[i8] = X_aug_km1_size[i8];
  }

  if ((varargin_2[0] != X_aug_km1[0]) || (varargin_2[1] != X_aug_km1[1])) {
    emlrtSizeEqCheckNDR2012b(&varargin_2[0], &X_aug_km1[0], &c_emlrtECI, sp);
  }

  st.site = &f_emlrtRSI;
  repmat(&st, x_aug_km1_data, x_aug_km1_size, L, varargin_3_data,
         varargin_3_size);
  for (i8 = 0; i8 < 2; i8++) {
    varargin_2[i8] = varargin_3_size[i8];
    X_aug_km1[i8] = X_aug_km1_size[i8];
  }

  if ((varargin_2[0] != X_aug_km1[0]) || (varargin_2[1] != X_aug_km1[1])) {
    emlrtSizeEqCheckNDR2012b(&varargin_2[0], &X_aug_km1[0], &d_emlrtECI, sp);
  }

  st.site = &f_emlrtRSI;
  loop_ub = varargin_2_size[0] * varargin_2_size[1] - 1;
  for (i8 = 0; i8 <= loop_ub; i8++) {
    varargin_2_data[i8] += srukf_optTLSThread->f0.X_aug_km1_data[i8];
  }

  loop_ub = varargin_3_size[0] * varargin_3_size[1] - 1;
  for (i8 = 0; i8 <= loop_ub; i8++) {
    varargin_3_data[i8] -= srukf_optTLSThread->f0.X_aug_km1_data[i8];
  }

  b_st.site = &gb_emlrtRSI;
  if (!(x_aug_km1_size[0] == 0)) {
    result = x_aug_km1_size[0];
  } else if (!((varargin_2_size[0] == 0) || (varargin_2_size[1] == 0))) {
    result = varargin_2_size[0];
  } else if (!((varargin_3_size[0] == 0) || (varargin_3_size[1] == 0))) {
    result = varargin_3_size[0];
  } else {
    result = 0;
    if (varargin_2_size[0] > 0) {
      result = varargin_2_size[0];
    }

    if (varargin_3_size[0] > result) {
      result = varargin_3_size[0];
    }
  }

  c_st.site = &hb_emlrtRSI;
  if ((x_aug_km1_size[0] == result) || (x_aug_km1_size[0] == 0)) {
    empty_non_axis_sizes = true;
  } else {
    empty_non_axis_sizes = false;
    emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((varargin_2_size[0] == result) || ((varargin_2_size[0] == 0) ||
       (varargin_2_size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (!empty_non_axis_sizes) {
    emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((varargin_3_size[0] == result) || ((varargin_3_size[0] == 0) ||
       (varargin_3_size[1] == 0))) {
  } else {
    empty_non_axis_sizes = false;
  }

  if (!empty_non_axis_sizes) {
    emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes || (!(x_aug_km1_size[0] == 0))) {
    L = 1;
  } else {
    L = 0;
  }

  if (empty_non_axis_sizes || (!((varargin_2_size[0] == 0) || (varargin_2_size[1]
         == 0)))) {
    b_result = varargin_2_size[1];
  } else {
    b_result = 0;
  }

  if (empty_non_axis_sizes || (!((varargin_3_size[0] == 0) || (varargin_3_size[1]
         == 0)))) {
    c_result = varargin_3_size[1];
  } else {
    c_result = 0;
  }

  X_aug_km1_size[1] = (L + b_result) + c_result;
  for (i8 = 0; i8 < L; i8++) {
    for (i9 = 0; i9 < result; i9++) {
      srukf_optTLSThread->f0.X_aug_km1_data[i9 + result * i8] =
        x_aug_km1_data[i9 + result * i8];
    }
  }

  for (i8 = 0; i8 < b_result; i8++) {
    for (i9 = 0; i9 < result; i9++) {
      srukf_optTLSThread->f0.X_aug_km1_data[i9 + result * (i8 + L)] =
        varargin_2_data[i9 + result * i8];
    }
  }

  for (i8 = 0; i8 < c_result; i8++) {
    for (i9 = 0; i9 < result; i9++) {
      srukf_optTLSThread->f0.X_aug_km1_data[i9 + result * ((i8 + L) + b_result)]
        = varargin_3_data[i9 + result * i8];
    }
  }

  /*  Predict sigma points and measurements: */
  if (1 > x_km1_size[0]) {
    loop_ub = 0;
  } else {
    if (!(1 <= result)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, result, &bb_emlrtBCI, sp);
    }

    if (!(x_km1_size[0] <= result)) {
      emlrtDynamicBoundsCheckR2012b(x_km1_size[0], 1, result, &cb_emlrtBCI, sp);
    }

    loop_ub = x_km1_size[0];
  }

  b_loop_ub = X_aug_km1_size[1];
  state_size[0] = loop_ub;
  state_size[1] = X_aug_km1_size[1];
  for (i8 = 0; i8 < b_loop_ub; i8++) {
    for (i9 = 0; i9 < loop_ub; i9++) {
      state_data[i9 + loop_ub * i8] = srukf_optTLSThread->f0.X_aug_km1_data[i9 +
        result * i8];
    }
  }

  loop_ub = Sv_size[0];
  b_loop_ub = X_aug_km1_size[1];
  pNoise_size[0] = Sv_size[0];
  pNoise_size[1] = X_aug_km1_size[1];
  for (i8 = 0; i8 < b_loop_ub; i8++) {
    for (i9 = 0; i9 < loop_ub; i9++) {
      i10 = (i9 + x_km1_size[0]) + 1;
      if (!((i10 >= 1) && (i10 <= result))) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, result, &ob_emlrtBCI, sp);
      }

      pNoise_data[i9 + loop_ub * i8] = srukf_optTLSThread->f0.X_aug_km1_data
        [(i10 + result * i8) - 1];
    }
  }

  loop_ub = Sn_size[0];
  L = (x_km1_size[0] + Sv_size[0]) + 1;
  b_loop_ub = X_aug_km1_size[1];
  mNoise_size[0] = Sn_size[0];
  mNoise_size[1] = X_aug_km1_size[1];
  for (i8 = 0; i8 < b_loop_ub; i8++) {
    for (i9 = 0; i9 < loop_ub; i9++) {
      i10 = i9 + L;
      if (!((i10 >= 1) && (i10 <= result))) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, result, &pb_emlrtBCI, sp);
      }

      mNoise_data[i9 + loop_ub * i8] = srukf_optTLSThread->f0.X_aug_km1_data
        [(i10 + result * i8) - 1];
    }
  }

  X_x_kkm1_size[0] = x_km1_size[0];
  X_x_kkm1_size[1] = Ns;
  Y_kkm1_size[0] = Sn_size[0];
  Y_kkm1_size[1] = Ns;
  L = Ns - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(X_data,X_size,c_loop_ub,i11,b_emlrtJBEnviron) \
 firstprivate(d_st,e_st,emlrtHadParallelError,tmp_data,b_state_size,b_state_data,b_pNoise_size,b_pNoise_data,b_tmp_data,iv27,b0,b_mNoise_data,X)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      d_st.prev = sp;
      d_st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      d_st.site = NULL;
      emlrtSetJmpBuf(&d_st, &b_emlrtJBEnviron);
      e_st.prev = &d_st;
      e_st.tls = d_st.tls;
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (b_sp = 0; b_sp <= L; b_sp++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        c_loop_ub = (int8_T)X_x_kkm1_size[0] - 1;
        for (i11 = 0; i11 <= c_loop_ub; i11++) {
          tmp_data[i11] = (int8_T)i11;
        }

        i11 = b_sp + 1;
        if (!((i11 >= 1) && (i11 <= X_x_kkm1_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, X_x_kkm1_size[1], &fb_emlrtBCI,
            &d_st);
        }

        c_loop_ub = state_size[0];
        i11 = 1 + b_sp;
        if (!((i11 >= 1) && (i11 <= state_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, state_size[1], &db_emlrtBCI,
            &d_st);
        }

        b_state_size[0] = state_size[0];
        for (i11 = 0; i11 < c_loop_ub; i11++) {
          b_state_data[i11] = state_data[i11 + state_size[0] * b_sp];
        }

        c_loop_ub = pNoise_size[0];
        i11 = 1 + b_sp;
        if (!((i11 >= 1) && (i11 <= pNoise_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, pNoise_size[1], &eb_emlrtBCI,
            &d_st);
        }

        b_pNoise_size[0] = pNoise_size[0];
        for (i11 = 0; i11 < c_loop_ub; i11++) {
          b_pNoise_data[i11] = pNoise_data[i11 + pNoise_size[0] * b_sp];
        }

        e_st.site = &g_emlrtRSI;
        propagate_RRR_Additive(&e_st, t_km1, t_k, b_state_data, b_state_size,
          u_km1_data, u_km1_size, b_pNoise_data, b_pNoise_size, X_data, X_size);
        b_state_size[0] = (int8_T)X_x_kkm1_size[0];
        emlrtSubAssignSizeCheckR2012b(&b_state_size[0], 1, &X_size[0], 1,
          &e_emlrtECI, &d_st);
        c_loop_ub = X_size[0];
        for (i11 = 0; i11 < c_loop_ub; i11++) {
          X_x_kkm1_data[tmp_data[i11] + X_x_kkm1_size[0] * b_sp] = X_data[i11];
        }

        c_loop_ub = X_x_kkm1_size[0];
        i11 = 1 + b_sp;
        if (!((i11 >= 1) && (i11 <= X_x_kkm1_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, X_x_kkm1_size[1], &gb_emlrtBCI,
            &d_st);
        }

        for (i11 = 0; i11 < c_loop_ub; i11++) {
          X_data[i11] = X_x_kkm1_data[i11 + X_x_kkm1_size[0] * b_sp];
        }

        e_st.site = &h_emlrtRSI;
        indexShapeCheck(&e_st, X_x_kkm1_size[0]);
        i11 = b_sp + 1;
        if (!((i11 >= 1) && (i11 <= mNoise_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, mNoise_size[1], &hb_emlrtBCI,
            &d_st);
        }

        if (3 != mNoise_size[0]) {
          emlrtSizeEqCheck1DR2012b(3, mNoise_size[0], &f_emlrtECI, &d_st);
        }

        c_loop_ub = (int8_T)Y_kkm1_size[0] - 1;
        for (i11 = 0; i11 <= c_loop_ub; i11++) {
          b_tmp_data[i11] = (int8_T)i11;
        }

        i11 = b_sp + 1;
        if (!((i11 >= 1) && (i11 <= Y_kkm1_size[1]))) {
          emlrtDynamicBoundsCheckR2012b(i11, 1, Y_kkm1_size[1], &ib_emlrtBCI,
            &d_st);
        }

        b_state_size[0] = (int8_T)Y_kkm1_size[0];
        if (!b0) {
          iv27[0] = 3;
          b0 = true;
        }

        emlrtSubAssignSizeCheckR2012b(&b_state_size[0], 1, &iv27[0], 1,
          &h_emlrtECI, &d_st);
        c_loop_ub = mNoise_size[0];
        for (i11 = 0; i11 < c_loop_ub; i11++) {
          b_mNoise_data[i11] = mNoise_data[i11 + mNoise_size[0] * b_sp];
        }

        for (i11 = 0; i11 < 3; i11++) {
          c_loop_ub = 4 + i11;
          if (!(c_loop_ub <= X_x_kkm1_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, X_x_kkm1_size[0],
              &qb_emlrtBCI, &d_st);
          }

          X[i11] = X_data[c_loop_ub - 1] + b_mNoise_data[i11];
        }

        c_loop_ub = (int8_T)Y_kkm1_size[0];
        for (i11 = 0; i11 < c_loop_ub; i11++) {
          Y_kkm1_data[b_tmp_data[i11] + Y_kkm1_size[0] * b_sp] = X[i11];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&d_st);
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
    i8 = 0;
    i9 = 0;
  } else {
    i8 = 1;
    i9 = X_x_kkm1_size[1];
  }

  loop_ub = X_x_kkm1_size[0];
  x_kkm1_size[0] = X_x_kkm1_size[0];
  for (i10 = 0; i10 < loop_ub; i10++) {
    x_kkm1_data[i10] = W_m_0 * X_x_kkm1_data[i10];
  }

  loop_ub = X_x_kkm1_size[0];
  b_X_x_kkm1_size[0] = X_x_kkm1_size[0];
  b_X_x_kkm1_size[1] = i9 - i8;
  b_loop_ub = i9 - i8;
  for (i9 = 0; i9 < b_loop_ub; i9++) {
    for (i10 = 0; i10 < loop_ub; i10++) {
      state_data[i10 + loop_ub * i9] = X_x_kkm1_data[i10 + X_x_kkm1_size[0] *
        (i8 + i9)];
    }
  }

  st.site = &i_emlrtRSI;
  sum(state_data, b_X_x_kkm1_size, b_data, x_aug_km1_size);
  loop_ub = x_aug_km1_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_data[i8] *= W_i;
  }

  i8 = x_kkm1_size[0];
  if (i8 != x_aug_km1_size[0]) {
    emlrtSizeEqCheck1DR2012b(i8, x_aug_km1_size[0], &g_emlrtECI, sp);
  }

  loop_ub = x_kkm1_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    x_kkm1_data[i8] += b_data[i8];
  }

  if (2 > Y_kkm1_size[1]) {
    i8 = 0;
    i9 = 0;
  } else {
    i8 = 1;
    i9 = Y_kkm1_size[1];
  }

  loop_ub = Y_kkm1_size[0];
  for (i10 = 0; i10 < loop_ub; i10++) {
    y_data[i10] = W_m_0 * Y_kkm1_data[i10];
  }

  loop_ub = Y_kkm1_size[0];
  b_Y_kkm1_size[0] = Y_kkm1_size[0];
  b_Y_kkm1_size[1] = i9 - i8;
  b_loop_ub = i9 - i8;
  for (i9 = 0; i9 < b_loop_ub; i9++) {
    for (i10 = 0; i10 < loop_ub; i10++) {
      mNoise_data[i10 + loop_ub * i9] = Y_kkm1_data[i10 + Y_kkm1_size[0] * (i8 +
        i9)];
    }
  }

  st.site = &j_emlrtRSI;
  sum(mNoise_data, b_Y_kkm1_size, b_data, x_aug_km1_size);
  loop_ub = x_aug_km1_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_data[i8] *= W_i;
  }

  if (Y_kkm1_size[0] != x_aug_km1_size[0]) {
    emlrtSizeEqCheck1DR2012b(Y_kkm1_size[0], x_aug_km1_size[0], &i_emlrtECI, sp);
  }

  y_kkm1_size[0] = Y_kkm1_size[0];
  loop_ub = Y_kkm1_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    y_kkm1_data[i8] = y_data[i8] + b_data[i8];
  }

  if (y_k_size[0] != Y_kkm1_size[0]) {
    emlrtSizeEqCheck1DR2012b(y_k_size[0], Y_kkm1_size[0], &j_emlrtECI, sp);
  }

  inov_size[0] = y_k_size[0];
  loop_ub = y_k_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    inov_data[i8] = y_k_data[i8] - y_kkm1_data[i8];
  }

  /*  Remove expectations from X_x_kkm1 and Z_kkm1: */
  c_X_x_kkm1_size[0] = X_x_kkm1_size[0];
  c_X_x_kkm1_size[1] = X_x_kkm1_size[1];
  loop_ub = X_x_kkm1_size[0] * X_x_kkm1_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&state_data[0], &X_x_kkm1_data[0], (uint32_T)(loop_ub * (int32_T)
            sizeof(real_T)));
  }

  st.site = &k_emlrtRSI;
  bsxfun(&st, state_data, c_X_x_kkm1_size, x_kkm1_data, x_kkm1_size,
         X_x_kkm1_data, X_x_kkm1_size);
  st.site = &l_emlrtRSI;
  bsxfun(&st, Y_kkm1_data, Y_kkm1_size, y_kkm1_data, y_kkm1_size, state_data,
         state_size);
  Y_kkm1_size[0] = state_size[0];
  loop_ub = state_size[0] * state_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&Y_kkm1_data[0], &state_data[0], (uint32_T)(loop_ub * (int32_T)sizeof
            (real_T)));
  }

  /*  Calculate covariance of the prediction: */
  if (2 > Ns) {
    i8 = 0;
    i9 = 0;
  } else {
    if (!(2 <= X_x_kkm1_size[1])) {
      emlrtDynamicBoundsCheckR2012b(2, 1, X_x_kkm1_size[1], &jb_emlrtBCI, sp);
    }

    i8 = 1;
    if (!(Ns <= X_x_kkm1_size[1])) {
      emlrtDynamicBoundsCheckR2012b(Ns, 1, X_x_kkm1_size[1], &kb_emlrtBCI, sp);
    }

    i9 = Ns;
  }

  loop_ub = X_x_kkm1_size[0];
  sqrtW_c_i_size[0] = i9 - i8;
  sqrtW_c_i_size[1] = X_x_kkm1_size[0];
  for (i10 = 0; i10 < loop_ub; i10++) {
    b_loop_ub = i9 - i8;
    for (c_result = 0; c_result < b_loop_ub; c_result++) {
      state_data[c_result + sqrtW_c_i_size[0] * i10] = sqrtW_c_i *
        X_x_kkm1_data[i10 + X_x_kkm1_size[0] * (i8 + c_result)];
    }
  }

  st.site = &m_emlrtRSI;
  qr(&st, state_data, sqrtW_c_i_size, unusedU0_data, varargin_2, b_S_kkm1_data,
     varargin_3_size);

  /*  QR update of state Cholesky factor. NOTE: here S_ is the UPPER Cholesky factor (Matlab excentricity) */
  if (W_c_0 > 0.0) {
    /*  deal with possible negative zero'th covariance weight */
    loop_ub = X_x_kkm1_size[0];
    sqrtW_c_0_size[0] = X_x_kkm1_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_data[i8] = sqrtW_c_0 * X_x_kkm1_data[i8];
    }

    st.site = &n_emlrtRSI;
    cholupdate(&st, b_S_kkm1_data, varargin_3_size, b_data, sqrtW_c_0_size,
               S_kkm1_data, S_kkm1_size);
  } else {
    loop_ub = X_x_kkm1_size[0];
    sqrtW_c_0_size[0] = X_x_kkm1_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_data[i8] = sqrtW_c_0 * X_x_kkm1_data[i8];
    }

    st.site = &o_emlrtRSI;
    b_cholupdate(&st, b_S_kkm1_data, varargin_3_size, b_data, sqrtW_c_0_size,
                 S_kkm1_data, S_kkm1_size);

    /*  NOTE: here Sx_  is the UPPER Cholesky factor (Matlab excentricity) */
  }

  /*  Covariance of predicted observation */
  if (2 > Ns) {
    i8 = 0;
    Ns = 0;
  } else {
    if (!(2 <= state_size[1])) {
      emlrtDynamicBoundsCheckR2012b(2, 1, state_size[1], &lb_emlrtBCI, sp);
    }

    i8 = 1;
    if (!(Ns <= state_size[1])) {
      emlrtDynamicBoundsCheckR2012b(Ns, 1, state_size[1], &mb_emlrtBCI, sp);
    }
  }

  loop_ub = state_size[0];
  b_sqrtW_c_i_size[0] = Ns - i8;
  b_sqrtW_c_i_size[1] = state_size[0];
  for (i9 = 0; i9 < loop_ub; i9++) {
    b_loop_ub = Ns - i8;
    for (i10 = 0; i10 < b_loop_ub; i10++) {
      mNoise_data[i10 + b_sqrtW_c_i_size[0] * i9] = sqrtW_c_i * Y_kkm1_data[i9 +
        Y_kkm1_size[0] * (i8 + i10)];
    }
  }

  st.site = &p_emlrtRSI;
  qr(&st, mNoise_data, b_sqrtW_c_i_size, unusedU0_data, varargin_2,
     b_S_kkm1_data, varargin_3_size);

  /*  QR update of state Cholesky factor. NOTE: here Sx_ */
  /*  is the UPPER Cholesky factor (Matlab excentricity) */
  if (W_c_0 > 0.0) {
    /*  deal with possible negative zero'th covariance weight */
    loop_ub = state_size[0];
    b_sqrtW_c_0_size[0] = state_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_data[i8] = sqrtW_c_0 * Y_kkm1_data[i8];
    }

    st.site = &q_emlrtRSI;
    cholupdate(&st, b_S_kkm1_data, varargin_3_size, b_data, b_sqrtW_c_0_size,
               unusedU0_data, varargin_2);
    i8 = S_yy->size[0] * S_yy->size[1];
    S_yy->size[0] = varargin_2[0];
    S_yy->size[1] = varargin_2[1];
    emxEnsureCapacity_real_T(sp, S_yy, i8, &s_emlrtRTEI);
    loop_ub = varargin_2[0] * varargin_2[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      S_yy->data[i8] = unusedU0_data[i8];
    }
  } else {
    loop_ub = state_size[0];
    b_sqrtW_c_0_size[0] = state_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_data[i8] = sqrtW_c_0 * Y_kkm1_data[i8];
    }

    st.site = &r_emlrtRSI;
    b_cholupdate(&st, b_S_kkm1_data, varargin_3_size, b_data, b_sqrtW_c_0_size,
                 unusedU0_data, varargin_2);
    i8 = S_yy->size[0] * S_yy->size[1];
    S_yy->size[0] = varargin_2[0];
    S_yy->size[1] = varargin_2[1];
    emxEnsureCapacity_real_T(sp, S_yy, i8, &r_emlrtRTEI);
    loop_ub = varargin_2[0] * varargin_2[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      S_yy->data[i8] = unusedU0_data[i8];
    }

    /*  NOTE: here Sx_  is the UPPER Cholesky factor (Matlab excentricity) */
  }

  emxInit_real_T1(sp, &b_S_yy, 2, &t_emlrtRTEI, true);
  L = S_yy->size[1];
  b_result = S_yy->size[0];
  i8 = b_S_yy->size[0] * b_S_yy->size[1];
  b_S_yy->size[0] = S_yy->size[1];
  b_S_yy->size[1] = S_yy->size[0];
  emxEnsureCapacity_real_T(sp, b_S_yy, i8, &t_emlrtRTEI);
  loop_ub = S_yy->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_loop_ub = S_yy->size[1];
    for (i9 = 0; i9 < b_loop_ub; i9++) {
      b_S_yy->data[i9 + b_S_yy->size[0] * i8] = S_yy->data[i8 + S_yy->size[0] *
        i9];
    }
  }

  i8 = S_yy->size[0] * S_yy->size[1];
  S_yy->size[0] = L;
  S_yy->size[1] = b_result;
  emxEnsureCapacity_real_T(sp, S_yy, i8, &u_emlrtRTEI);
  for (i8 = 0; i8 < b_result; i8++) {
    for (i9 = 0; i9 < L; i9++) {
      S_yy->data[i9 + S_yy->size[0] * i8] = b_S_yy->data[i9 + L * i8];
    }
  }

  /*  Covariance of predicted observation and predicted state: */
  if (2 > X_x_kkm1_size[1]) {
    i8 = 1;
    i9 = 1;
  } else {
    i8 = 2;
    i9 = X_x_kkm1_size[1] + 1;
  }

  if (2 > state_size[1]) {
    i10 = 0;
    c_result = 0;
  } else {
    i10 = 1;
    c_result = state_size[1];
  }

  loop_ub = X_x_kkm1_size[0];
  b_loop_ub = state_size[0];
  for (L = 0; L < loop_ub; L++) {
    b_data[L] = W_c_0 * X_x_kkm1_data[L];
  }

  if (0 <= b_loop_ub - 1) {
    memcpy(&y_kkm1_data[0], &Y_kkm1_data[0], (uint32_T)(b_loop_ub * (int32_T)
            sizeof(real_T)));
  }

  P_xy_size[0] = X_x_kkm1_size[0];
  P_xy_size[1] = state_size[0];
  loop_ub = X_x_kkm1_size[0];
  for (L = 0; L < loop_ub; L++) {
    for (b_result = 0; b_result < b_loop_ub; b_result++) {
      P_xy_data[L + P_xy_size[0] * b_result] = b_data[L] * y_kkm1_data[b_result];
    }
  }

  st.site = &s_emlrtRSI;
  loop_ub = X_x_kkm1_size[0];
  pNoise_size[1] = i9 - i8;
  b_loop_ub = i9 - i8;
  for (L = 0; L < b_loop_ub; L++) {
    for (b_result = 0; b_result < loop_ub; b_result++) {
      pNoise_data[b_result + loop_ub * L] = X_x_kkm1_data[b_result +
        X_x_kkm1_size[0] * ((i8 + L) - 1)];
    }
  }

  emxInit_real_T1(&st, &b, 2, &v_emlrtRTEI, true);
  b_loop_ub = state_size[0];
  L = b->size[0] * b->size[1];
  b->size[0] = c_result - i10;
  b->size[1] = state_size[0];
  emxEnsureCapacity_real_T(&st, b, L, &v_emlrtRTEI);
  for (L = 0; L < b_loop_ub; L++) {
    result = c_result - i10;
    for (b_result = 0; b_result < result; b_result++) {
      b->data[b_result + b->size[0] * L] = Y_kkm1_data[L + Y_kkm1_size[0] * (i10
        + b_result)];
    }
  }

  b_st.site = &re_emlrtRSI;
  if (!(i9 - i8 == b->size[0])) {
    if (((X_x_kkm1_size[0] == 1) && (i9 - i8 == 1)) || ((b->size[0] == 1) &&
         (b->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &lb_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &kb_emlrtRTEI,
        "Coder:MATLAB:innerdim", "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((i9 - i8 == 1) || (b->size[0] == 1)) {
    state_size[0] = X_x_kkm1_size[0];
    state_size[1] = b->size[1];
    b_loop_ub = X_x_kkm1_size[0];
    for (i8 = 0; i8 < b_loop_ub; i8++) {
      result = b->size[1];
      for (i9 = 0; i9 < result; i9++) {
        state_data[i8 + loop_ub * i9] = 0.0;
        L = pNoise_size[1];
        for (i10 = 0; i10 < L; i10++) {
          state_data[i8 + loop_ub * i9] += pNoise_data[i8 + loop_ub * i10] *
            b->data[i10 + b->size[0] * i9];
        }
      }
    }
  } else {
    b_st.site = &qe_emlrtRSI;
    if ((X_x_kkm1_size[0] == 0) || (i9 - i8 == 0) || (b->size[0] == 0) ||
        (b->size[1] == 0)) {
      state_size[0] = X_x_kkm1_size[0];
      state_size[1] = b->size[1];
      loop_ub = X_x_kkm1_size[0] * b->size[1];
      if (0 <= loop_ub - 1) {
        memset(&state_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      sqrtW_c_i = 0.0;
      m_t = (ptrdiff_t)X_x_kkm1_size[0];
      n_t = (ptrdiff_t)b->size[1];
      k_t = (ptrdiff_t)(i9 - i8);
      lda_t = (ptrdiff_t)X_x_kkm1_size[0];
      ldb_t = (ptrdiff_t)(i9 - i8);
      ldc_t = (ptrdiff_t)X_x_kkm1_size[0];
      state_size[0] = X_x_kkm1_size[0];
      state_size[1] = b->size[1];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda, &pNoise_data[0], &lda_t,
            &b->data[0], &ldb_t, &sqrtW_c_i, &state_data[0], &ldc_t);
    }
  }

  X_aug_km1_size[0] = state_size[0];
  X_aug_km1_size[1] = state_size[1];
  loop_ub = state_size[0] * state_size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    srukf_optTLSThread->f0.X_aug_km1_data[i8] = W_i * state_data[i8];
  }

  for (i8 = 0; i8 < 2; i8++) {
    varargin_2[i8] = P_xy_size[i8];
    X_aug_km1[i8] = X_aug_km1_size[i8];
  }

  if ((varargin_2[0] != X_aug_km1[0]) || (varargin_2[1] != X_aug_km1[1])) {
    emlrtSizeEqCheckNDR2012b(&varargin_2[0], &X_aug_km1[0], &k_emlrtECI, sp);
  }

  loop_ub = P_xy_size[0] * P_xy_size[1] - 1;
  for (i8 = 0; i8 <= loop_ub; i8++) {
    P_xy_data[i8] += srukf_optTLSThread->f0.X_aug_km1_data[i8];
  }

  /*  Kalman gain: */
  i8 = b->size[0] * b->size[1];
  b->size[0] = S_yy->size[1];
  b->size[1] = S_yy->size[0];
  emxEnsureCapacity_real_T(sp, b, i8, &w_emlrtRTEI);
  loop_ub = S_yy->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_loop_ub = S_yy->size[1];
    for (i9 = 0; i9 < b_loop_ub; i9++) {
      b->data[i9 + b->size[0] * i8] = S_yy->data[i8 + S_yy->size[0] * i9];
    }
  }

  L = S_yy->size[1];
  b_result = S_yy->size[0];
  i8 = b_S_yy->size[0] * b_S_yy->size[1];
  b_S_yy->size[0] = L;
  b_S_yy->size[1] = b_result;
  emxEnsureCapacity_real_T(sp, b_S_yy, i8, &c_emlrtRTEI);
  for (i8 = 0; i8 < b_result; i8++) {
    for (i9 = 0; i9 < L; i9++) {
      b_S_yy->data[i9 + b_S_yy->size[0] * i8] = b->data[i9 + L * i8];
    }
  }

  emxFree_real_T(sp, &b);
  st.site = &t_emlrtRSI;
  mrdivide(&st, P_xy_data, P_xy_size, b_S_yy, state_data, state_size);
  st.site = &t_emlrtRSI;
  mrdivide(&st, state_data, state_size, S_yy, K_data, K_size);

  /*  Correct the state: */
  st.site = &u_emlrtRSI;
  b_st.site = &re_emlrtRSI;
  emxFree_real_T(&b_st, &b_S_yy);
  if (!(K_size[1] == inov_size[0])) {
    if (((K_size[0] == 1) && (K_size[1] == 1)) || (inov_size[0] == 1)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &lb_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &kb_emlrtRTEI,
        "Coder:MATLAB:innerdim", "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((K_size[1] == 1) || (inov_size[0] == 1)) {
    x_size[0] = K_size[0];
    loop_ub = K_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      x_data[i8] = 0.0;
      b_loop_ub = K_size[1];
      for (i9 = 0; i9 < b_loop_ub; i9++) {
        x_data[i8] += K_data[i8 + K_size[0] * i9] * inov_data[i9];
      }
    }
  } else {
    b_st.site = &qe_emlrtRSI;
    if ((K_size[0] == 0) || (K_size[1] == 0) || (inov_size[0] == 0)) {
      x_size[0] = K_size[0];
      loop_ub = K_size[0];
      if (0 <= loop_ub - 1) {
        memset(&x_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      sqrtW_c_i = 0.0;
      m_t = (ptrdiff_t)K_size[0];
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)K_size[1];
      lda_t = (ptrdiff_t)K_size[0];
      ldb_t = (ptrdiff_t)K_size[1];
      ldc_t = (ptrdiff_t)K_size[0];
      x_size[0] = K_size[0];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda, &K_data[0], &lda_t,
            &inov_data[0], &ldb_t, &sqrtW_c_i, &x_data[0], &ldc_t);
    }
  }

  i8 = x_kkm1_size[0];
  i9 = x_size[0];
  if (i8 != i9) {
    emlrtSizeEqCheck1DR2012b(i8, i9, &l_emlrtECI, sp);
  }

  x_size[0] = x_kkm1_size[0];
  loop_ub = x_kkm1_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    x_data[i8] += x_kkm1_data[i8];
  }

  st.site = &v_emlrtRSI;
  b_st.site = &re_emlrtRSI;
  if (!(K_size[1] == S_yy->size[0])) {
    if (((K_size[0] == 1) && (K_size[1] == 1)) || ((S_yy->size[0] == 1) &&
         (S_yy->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(&b_st, &lb_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &kb_emlrtRTEI,
        "Coder:MATLAB:innerdim", "Coder:MATLAB:innerdim", 0);
    }
  }

  if ((K_size[1] == 1) || (S_yy->size[0] == 1)) {
    state_size[0] = K_size[0];
    state_size[1] = S_yy->size[1];
    loop_ub = K_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_loop_ub = S_yy->size[1];
      for (i9 = 0; i9 < b_loop_ub; i9++) {
        state_data[i8 + state_size[0] * i9] = 0.0;
        result = K_size[1];
        for (i10 = 0; i10 < result; i10++) {
          state_data[i8 + state_size[0] * i9] += K_data[i8 + K_size[0] * i10] *
            S_yy->data[i10 + S_yy->size[0] * i9];
        }
      }
    }
  } else {
    b_st.site = &qe_emlrtRSI;
    if ((K_size[0] == 0) || (K_size[1] == 0) || (S_yy->size[0] == 0) ||
        (S_yy->size[1] == 0)) {
      state_size[0] = K_size[0];
      state_size[1] = S_yy->size[1];
      loop_ub = K_size[0] * S_yy->size[1];
      if (0 <= loop_ub - 1) {
        memset(&state_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
      }
    } else {
      TRANSA = 'N';
      TRANSB = 'N';
      lambda = 1.0;
      sqrtW_c_i = 0.0;
      m_t = (ptrdiff_t)K_size[0];
      n_t = (ptrdiff_t)S_yy->size[1];
      k_t = (ptrdiff_t)K_size[1];
      lda_t = (ptrdiff_t)K_size[0];
      ldb_t = (ptrdiff_t)K_size[1];
      ldc_t = (ptrdiff_t)K_size[0];
      state_size[0] = K_size[0];
      state_size[1] = S_yy->size[1];
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &lambda, &K_data[0], &lda_t,
            &S_yy->data[0], &ldb_t, &sqrtW_c_i, &state_data[0], &ldc_t);
    }
  }

  /*  Correct the covariance: */
  L = 0;
  while (L <= Ydim - 1) {
    loop_ub = state_size[0];
    if (!((L + 1 >= 1) && (L + 1 <= state_size[1]))) {
      emlrtDynamicBoundsCheckR2012b(L + 1, 1, state_size[1], &nb_emlrtBCI, sp);
    }

    c_state_size[0] = state_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_data[i8] = state_data[i8 + state_size[0] * L];
    }

    b_S_kkm1_size[0] = S_kkm1_size[0];
    b_S_kkm1_size[1] = S_kkm1_size[1];
    loop_ub = S_kkm1_size[0] * S_kkm1_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&b_S_kkm1_data[0], &S_kkm1_data[0], (uint32_T)(loop_ub * (int32_T)
              sizeof(real_T)));
    }

    st.site = &w_emlrtRSI;
    b_cholupdate(&st, b_S_kkm1_data, b_S_kkm1_size, b_data, c_state_size,
                 S_kkm1_data, S_kkm1_size);
    L++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i8 = S_kkm1_size[1];
  if (23 < i8) {
    emlrtDimSizeGeqCheckR2012b(23, i8, &m_emlrtECI, sp);
  }

  i8 = S_kkm1_size[0];
  if (23 < i8) {
    emlrtDimSizeGeqCheckR2012b(23, i8, &n_emlrtECI, sp);
  }

  S_size[0] = S_kkm1_size[1];
  S_size[1] = S_kkm1_size[0];
  loop_ub = S_kkm1_size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_loop_ub = S_kkm1_size[1];
    for (i9 = 0; i9 < b_loop_ub; i9++) {
      S_data[i9 + S_size[0] * i8] = S_kkm1_data[i8 + S_kkm1_size[0] * i9];
    }
  }

  /*  srukf */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (srukf_opt.c) */
