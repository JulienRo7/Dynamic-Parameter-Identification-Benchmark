/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RRR_dyn_CL.h
 *
 * Code generation for function 'RRR_dyn_CL'
 *
 */

#ifndef RRR_DYN_CL_H
#define RRR_DYN_CL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "integrate_RRR_dyn_CL_types.h"

/* Function Declarations */
extern void RRR_dyn_CL(const emlrtStack *sp, const real_T X_data[], const
  int32_T X_size[1], const real_T tau[3], const real_T Theta_data[], const
  int32_T Theta_size[1], real_T Xp[6]);

#endif

/* End of code generation (RRR_dyn_CL.h) */
