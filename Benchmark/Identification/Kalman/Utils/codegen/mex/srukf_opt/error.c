/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo y_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "/opt/MATLAB/R2018a/toolbox/shared/coder/coder/+coder/+internal/error.m"/* pName */
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  static const char_T varargin_1[4] = { 's', 'q', 'r', 't' };

  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4, 4,
    varargin_1);
}

void c_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI, "MATLAB:nomem", "MATLAB:nomem",
    0);
}

void d_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 'q', 'r', 'f' };

  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo", 5,
    4, 14, varargin_1, 12, varargin_2);
}

void e_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'o', 'r', 'g', 'q', 'r' };

  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo", 5,
    4, 14, varargin_1, 12, varargin_2);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
}

void f_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo", 5,
    4, 19, varargin_1, 12, varargin_2);
}

void g_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 'q', 'p', '3' };

  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo", 5,
    4, 14, varargin_1, 12, varargin_2);
}

void h_error(const emlrtStack *sp, int32_T varargin_2)
{
  static const char_T varargin_1[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'o', 'r', 'm', 'q', 'r' };

  emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
    "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo", 5,
    4, 14, varargin_1, 12, varargin_2);
}

/* End of code generation (error.c) */
