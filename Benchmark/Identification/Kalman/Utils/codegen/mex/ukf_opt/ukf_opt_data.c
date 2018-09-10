/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ukf_opt_data.c
 *
 * Code generation for function 'ukf_opt_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "ukf_opt_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "ukf_opt",                           /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo u_emlrtRSI = { 40,         /* lineNo */
  "mpower",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 49,         /* lineNo */
  "power",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo kb_emlrtRSI = { 45,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 48,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

emlrtRSInfo nb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 12,        /* lineNo */
  "svd",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 28,        /* lineNo */
  "anyNonFinite",                      /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/anyNonFinite.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 36,        /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 96,        /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 171,       /* lineNo */
  "xgesvd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 114,       /* lineNo */
  "xgesvd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 107,       /* lineNo */
  "xgesvd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 56,        /* lineNo */
  "xgesvd",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 15,        /* lineNo */
  "sqrt",                              /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 31,        /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 22,        /* lineNo */
  "repmat",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 25,        /* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo vc_emlrtRSI = { 100,       /* lineNo */
  "cat",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo yc_emlrtRSI = { 18,        /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

emlrtRSInfo yd_emlrtRSI = { 76,        /* lineNo */
  "lusolve",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

emlrtRSInfo ce_emlrtRSI = { 9,         /* lineNo */
  "sum",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 64,        /* lineNo */
  "sumprod",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 134,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo fe_emlrtRSI = { 177,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 195,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo ve_emlrtRSI = { 76,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/xtrsm.m"/* pathName */
};

emlrtRSInfo we_emlrtRSI = { 77,        /* lineNo */
  "xtrsm",                             /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/+blas/xtrsm.m"/* pathName */
};

emlrtMCInfo b_emlrtMCI = { 41,         /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

emlrtMCInfo e_emlrtMCI = { 53,         /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pName */
};

emlrtRTEInfo p_emlrtRTEI = { 88,       /* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

const char_T cv0[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a', 'x',
  's', 'i', 'z', 'e' };

emlrtRSInfo uf_emlrtRSI = { 53,        /* lineNo */
  "flt2str",                           /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/flt2str.m"/* pathName */
};

emlrtRSInfo vf_emlrtRSI = { 41,        /* lineNo */
  "repmat",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

/* End of code generation (ukf_opt_data.c) */
