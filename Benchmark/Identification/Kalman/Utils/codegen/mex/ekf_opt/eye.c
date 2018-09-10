/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eye.c
 *
 * Code generation for function 'eye'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "ekf_opt.h"
#include "eye.h"

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI = { 49, /* lineNo */
  "eye",                               /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/eye.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 19, /* lineNo */
  "checkAndSaturateExpandSize",        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/checkAndSaturateExpandSize.m"/* pathName */
};

static emlrtRTEInfo p_emlrtRTEI = { 55,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

/* Function Definitions */
void eye(const emlrtStack *sp, real_T varargin_1, real_T I_data[], int32_T
         I_size[2])
{
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &pc_emlrtRSI;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  I_size[0] = (int32_T)varargin_1;
  I_size[1] = (int32_T)varargin_1;
  loop_ub = (int32_T)varargin_1 * (int32_T)varargin_1;
  if (0 <= loop_ub - 1) {
    memset(&I_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  if ((int32_T)varargin_1 > 0) {
    for (loop_ub = 0; loop_ub < (int32_T)varargin_1; loop_ub++) {
      I_data[loop_ub + (int32_T)varargin_1 * loop_ub] = 1.0;
    }
  }
}

/* End of code generation (eye.c) */
