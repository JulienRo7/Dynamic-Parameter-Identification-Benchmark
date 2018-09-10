/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cholupdate.c
 *
 * Code generation for function 'cholupdate'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "cholupdate.h"
#include "triu.h"
#include "error.h"
#include "srukf_opt_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo he_emlrtRSI = { 35, /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 79, /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 87, /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 89, /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 98, /* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 104,/* lineNo */
  "cholupdate",                        /* fcnName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pathName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "cholupdate",                        /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 23,/* lineNo */
  23,                                  /* colNo */
  "cholupdate",                        /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 80,/* lineNo */
  23,                                  /* colNo */
  "cholupdate",                        /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 91,/* lineNo */
  23,                                  /* colNo */
  "cholupdate",                        /* fName */
  "/opt/MATLAB/R2018a/toolbox/eml/lib/matlab/matfun/cholupdate.m"/* pName */
};

/* Function Declarations */
static real_T CholeskyRankOneDowndate(const emlrtStack *sp, real_T R_data[],
  int32_T R_size[2], real_T x_data[], int32_T x_size[1]);
static void rotate(real_T x, real_T y, real_T *c, real_T *s, real_T *r);

/* Function Definitions */
static real_T CholeskyRankOneDowndate(const emlrtStack *sp, real_T R_data[],
  int32_T R_size[2], real_T x_data[], int32_T x_size[1])
{
  real_T p;
  int32_T n;
  int32_T loop_ub;
  real_T c_data[23];
  real_T s_data[23];
  boolean_T errorCondition;
  real_T nrmx;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  p = 0.0;
  n = R_size[0];
  if (R_size[0] != 0) {
    loop_ub = (int8_T)x_size[0];
    if (0 <= loop_ub - 1) {
      memset(&c_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    loop_ub = (int8_T)x_size[0];
    if (0 <= loop_ub - 1) {
      memset(&s_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    st.site = &ie_emlrtRSI;
    errorCondition = false;
    for (loop_ub = 0; loop_ub < R_size[0]; loop_ub++) {
      if (errorCondition || (R_data[loop_ub + R_size[0] * loop_ub] == 0.0)) {
        errorCondition = true;
      } else {
        errorCondition = false;
      }
    }

    if (errorCondition) {
      emlrtErrorWithMessageIdR2018a(sp, &mb_emlrtRTEI,
        "MATLAB:cholupdate:singularCholeskyFactor",
        "MATLAB:cholupdate:singularCholeskyFactor", 0);
    }

    if (errorCondition) {
      p = 2.0;
    } else {
      st.site = &je_emlrtRSI;
      nrmx = 1.0;
      DIAGA = 'N';
      TRANSA = 'C';
      UPLO = 'U';
      SIDE = 'L';
      m_t = (ptrdiff_t)R_size[0];
      n_t = (ptrdiff_t)1;
      lda_t = (ptrdiff_t)R_size[0];
      ldb_t = (ptrdiff_t)R_size[0];
      dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &nrmx, &R_data[0], &lda_t,
            &x_data[0], &ldb_t);
      st.site = &ke_emlrtRSI;
      n_t = (ptrdiff_t)R_size[0];
      m_t = (ptrdiff_t)1;
      nrmx = dnrm2(&n_t, &x_data[0], &m_t);
      errorCondition = (nrmx >= 1.0);
      if (errorCondition) {
        emlrtErrorWithMessageIdR2018a(sp, &nb_emlrtRTEI,
          "MATLAB:cholupdate:downdatedMatrixNotPosDef",
          "MATLAB:cholupdate:downdatedMatrixNotPosDef", 0);
      }

      if (errorCondition) {
        p = 1.0;
      } else {
        st.site = &le_emlrtRSI;
        nrmx = 1.0 - nrmx * nrmx;
        if (nrmx < 0.0) {
          b_st.site = &bb_emlrtRSI;
          b_error(&b_st);
        }

        nrmx = muDoubleScalarSqrt(nrmx);
        for (loop_ub = R_size[0] - 1; loop_ub + 1 > 0; loop_ub--) {
          rotate(nrmx, x_data[loop_ub], &c_data[loop_ub], &s_data[loop_ub],
                 &nrmx);
          x_data[loop_ub] = 0.0;
        }

        st.site = &me_emlrtRSI;
        for (loop_ub = 0; loop_ub < n; loop_ub++) {
          for (i = loop_ub; i + 1 > 0; i--) {
            nrmx = s_data[i] * R_data[i + R_size[0] * loop_ub];
            R_data[i + R_size[0] * loop_ub] = c_data[i] * R_data[i + R_size[0] *
              loop_ub] - s_data[i] * x_data[loop_ub];
            x_data[loop_ub] = c_data[i] * x_data[loop_ub] + nrmx;
          }
        }
      }
    }
  }

  return p;
}

static void rotate(real_T x, real_T y, real_T *c, real_T *s, real_T *r)
{
  real_T absx;
  real_T absy;
  real_T t;
  real_T xx;
  real_T rho;
  absx = muDoubleScalarAbs(x);
  absy = muDoubleScalarAbs(y);
  if (absy == 0.0) {
    *c = 1.0;
    *s = 0.0;
    *r = x;
  } else if (absx == 0.0) {
    *c = 0.0;
    *s = 1.0;
    *r = y;
  } else {
    t = absx + absy;
    xx = x / t;
    absy = y / t;
    absx = muDoubleScalarAbs(xx);
    rho = muDoubleScalarHypot(absx, muDoubleScalarAbs(absy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * absy / rho;
    rho *= t;
    *r = rho * xx;
  }
}

void b_cholupdate(const emlrtStack *sp, const real_T R_data[], const int32_T
                  R_size[2], const real_T x_data[], const int32_T x_size[1],
                  real_T R1_data[], int32_T R1_size[2])
{
  int32_T loop_ub;
  int32_T b_x_size[1];
  real_T b_x_data[23];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (R_size[0] != R_size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &ib_emlrtRTEI, "MATLAB:square",
      "MATLAB:square", 0);
  }

  if (x_size[0] != R_size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &hb_emlrtRTEI,
      "MATLAB:cholupdate:incorrectSecondInputArgument",
      "MATLAB:cholupdate:incorrectSecondInputArgument", 2, 12, R_size[0]);
  }

  R1_size[0] = R_size[0];
  R1_size[1] = R_size[1];
  loop_ub = R_size[0] * R_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&R1_data[0], &R_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  triu(R1_data, R1_size);
  b_x_size[0] = x_size[0];
  loop_ub = x_size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&b_x_data[0], &x_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &he_emlrtRSI;
  CholeskyRankOneDowndate(&st, R1_data, R1_size, b_x_data, b_x_size);
}

void cholupdate(const emlrtStack *sp, const real_T R_data[], const int32_T
                R_size[2], const real_T x_data[], const int32_T x_size[1],
                real_T R1_data[], int32_T R1_size[2])
{
  int32_T loop_ub;
  real_T c_data[23];
  real_T s_data[23];
  real_T t;
  int32_T i;
  real_T z;
  if (R_size[0] != R_size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &ib_emlrtRTEI, "MATLAB:square",
      "MATLAB:square", 0);
  }

  if (x_size[0] != R_size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &hb_emlrtRTEI,
      "MATLAB:cholupdate:incorrectSecondInputArgument",
      "MATLAB:cholupdate:incorrectSecondInputArgument", 2, 12, R_size[0]);
  }

  R1_size[0] = R_size[0];
  R1_size[1] = R_size[1];
  loop_ub = R_size[0] * R_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&R1_data[0], &R_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  triu(R1_data, R1_size);
  if (R1_size[0] != 0) {
    loop_ub = (int8_T)x_size[0];
    if (0 <= loop_ub - 1) {
      memset(&c_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    loop_ub = (int8_T)x_size[0];
    if (0 <= loop_ub - 1) {
      memset(&s_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }

    rotate(R1_data[0], x_data[0], &c_data[0], &s_data[0], &R1_data[0]);
    for (loop_ub = 1; loop_ub < R1_size[0]; loop_ub++) {
      t = x_data[loop_ub];
      for (i = 0; i < loop_ub; i++) {
        z = s_data[i] * t;
        t = c_data[i] * t - s_data[i] * R1_data[i + R1_size[0] * loop_ub];
        R1_data[i + R1_size[0] * loop_ub] = c_data[i] * R1_data[i + R1_size[0] *
          loop_ub] + z;
      }

      rotate(R1_data[loop_ub + R1_size[0] * loop_ub], t, &c_data[loop_ub],
             &s_data[loop_ub], &R1_data[loop_ub + R1_size[0] * loop_ub]);
    }
  }
}

/* End of code generation (cholupdate.c) */
