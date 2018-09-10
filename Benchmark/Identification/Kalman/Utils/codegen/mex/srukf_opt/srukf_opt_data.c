/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * srukf_opt_data.c
 *
 * Code generation for function 'srukf_opt_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "srukf_opt_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "srukf_opt",                         /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo x_emlrtRSI = { 40,         /* lineNo */
  "mpower",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

emlrtRSInfo bb_emlrtRSI = { 12,        /* lineNo */
  "sqrt",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 22,        /* lineNo */
  "repmat",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

emlrtRSInfo gb_emlrtRSI = { 25,        /* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo hb_emlrtRSI = { 100,       /* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 18,        /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 76,        /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 9,         /* lineNo */
  "sum",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 64,        /* lineNo */
  "sumprod",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 134,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 177,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 195,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo sd_emlrtRSI = { 45,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 48,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

emlrtRSInfo ud_emlrtRSI = { 35,        /* lineNo */
  "xnrm2",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/xnrm2.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 30,        /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 38,        /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 47,        /* lineNo */
  "triu",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/triu.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 48,        /* lineNo */
  "triu",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/triu.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 55,        /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

emlrtRSInfo ne_emlrtRSI = { 144,       /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

emlrtRSInfo oe_emlrtRSI = { 77,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/xtrsm.m"/* pathName */
};

emlrtRSInfo pe_emlrtRSI = { 76,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/xtrsm.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 114,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo te_emlrtRSI = { 118,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo ye_emlrtRSI = { 113,       /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo af_emlrtRSI = { 115,       /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo bf_emlrtRSI = { 120,       /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRTEInfo c_emlrtRTEI = { 1,        /* lineNo */
  56,                                  /* colNo */
  "srukf_opt",                         /* fName */
  "/home/quentin/Desktop/MatlabCommented05092018/Benchmark/Identification/Kalman/UKF/srukf_opt.m"/* pName */
};

emlrtMCInfo emlrtMCI = { 41,           /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

emlrtMCInfo d_emlrtMCI = { 53,         /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pName */
};

emlrtRTEInfo cb_emlrtRTEI = { 88,      /* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

const char_T cv0[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x',
  's', 'i', 'z', 'e' };

emlrtRSInfo gg_emlrtRSI = { 53,        /* lineNo */
  "flt2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pathName */
};

emlrtRSInfo hg_emlrtRSI = { 41,        /* lineNo */
  "repmat",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

/* End of code generation (srukf_opt_data.c) */
