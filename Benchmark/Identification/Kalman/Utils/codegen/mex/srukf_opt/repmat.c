/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "repmat.h"
#include "xgetrf.h"
#include "srukf_opt_mexutil.h"
#include "srukf_opt_data.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 58, /* lineNo */
  "repmat",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 65, /* lineNo */
  "repmat",                            /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 55,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const real_T a_data[], const int32_T a_size[1],
            real_T varargin_2, real_T b_data[], int32_T b_size[2])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 15 };

  static const int32_T iv1[2] = { 1, 15 };

  int32_T nrows;
  int32_T jtilecol;
  int32_T ibtile;
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  if (varargin_2 != varargin_2) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", "Coder:MATLAB:NonIntegerInput", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if ((int8_T)a_size[0] != a_size[0]) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(sp, 15, m0, &cv0[0]);
    emlrtAssign(&y, m0);
    st.site = &hg_emlrtRSI;
    i_error(&st, y, &emlrtMCI);
  }

  if ((int8_T)(int32_T)varargin_2 != (int32_T)varargin_2) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(sp, 15, m0, &cv0[0]);
    emlrtAssign(&y, m0);
    st.site = &hg_emlrtRSI;
    i_error(&st, y, &emlrtMCI);
  }

  b_size[0] = (int8_T)a_size[0];
  b_size[1] = (int8_T)(int32_T)varargin_2;
  nrows = a_size[0];
  st.site = &db_emlrtRSI;
  for (jtilecol = 1; jtilecol <= (int32_T)varargin_2; jtilecol++) {
    ibtile = (jtilecol - 1) * nrows;
    st.site = &eb_emlrtRSI;
    for (k = 1; k <= nrows; k++) {
      b_data[(ibtile + k) - 1] = a_data[k - 1];
    }
  }
}

/* End of code generation (repmat.c) */
