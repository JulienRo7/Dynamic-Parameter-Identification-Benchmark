/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ntrp45.h
 *
 * Code generation for function 'ntrp45'
 *
 */

#ifndef NTRP45_H
#define NTRP45_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "ekf_opt_types.h"

/* Function Declarations */
extern void ntrp45(const real_T t[3], real_T t0, const real_T b_y0[6], real_T h,
                   const real_T f[42], real_T y[18]);

#endif

/* End of code generation (ntrp45.h) */
