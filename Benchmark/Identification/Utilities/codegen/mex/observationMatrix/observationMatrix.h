/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * observationMatrix.h
 *
 * Code generation for function 'observationMatrix'
 *
 */

#ifndef OBSERVATIONMATRIX_H
#define OBSERVATIONMATRIX_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "observationMatrix_types.h"

/* Function Declarations */
extern void observationMatrix(const emlrtStack *sp, const emxArray_real_T *Q,
  const emxArray_real_T *Qp, const emxArray_real_T *Qpp, emxArray_real_T *W);

#endif

/* End of code generation (observationMatrix.h) */
