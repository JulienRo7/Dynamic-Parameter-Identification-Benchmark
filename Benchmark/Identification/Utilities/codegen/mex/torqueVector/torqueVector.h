/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * torqueVector.h
 *
 * Code generation for function 'torqueVector'
 *
 */

#ifndef TORQUEVECTOR_H
#define TORQUEVECTOR_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "torqueVector_types.h"

/* Function Declarations */
extern void torqueVector(const emlrtStack *sp, const emxArray_real_T *Tau,
  emxArray_real_T *Y_tau);

#endif

/* End of code generation (torqueVector.h) */
