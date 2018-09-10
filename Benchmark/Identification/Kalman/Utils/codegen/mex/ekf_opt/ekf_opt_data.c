/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ekf_opt_data.c
 *
 * Code generation for function 'ekf_opt_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ekf_opt.h"
#include "ekf_opt_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "ekf_opt",                           /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo l_emlrtRSI = { 18,         /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 48,        /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo ib_emlrtRSI = { 251,       /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo jb_emlrtRSI = { 76,        /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo qb_emlrtRSI = { 42,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo rb_emlrtRSI = { 44,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 61,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 62,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 64,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 65,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo wb_emlrtRSI = { 70,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo xb_emlrtRSI = { 71,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 73,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo ac_emlrtRSI = { 74,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo bc_emlrtRSI = { 82,        /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 118,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 121,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 122,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 194,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 410,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 414,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 454,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 457,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 510,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 511,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 515,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 516,       /* lineNo */
  "stateJacobian",                     /* fcnName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/EKF/stateJacobian.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 52,        /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRTEInfo k_emlrtRTEI = { 88,       /* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

/* End of code generation (ekf_opt_data.c) */
