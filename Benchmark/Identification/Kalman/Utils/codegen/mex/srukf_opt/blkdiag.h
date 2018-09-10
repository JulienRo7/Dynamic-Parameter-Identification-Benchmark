/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * blkdiag.h
 *
 * Code generation for function 'blkdiag'
 *
 */

#ifndef BLKDIAG_H
#define BLKDIAG_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "srukf_opt_types.h"

/* Function Declarations */
extern void blkdiag(const real_T varargin_1_data[], const int32_T
                    varargin_1_size[2], const real_T varargin_2_data[], const
                    int32_T varargin_2_size[2], const real_T varargin_3_data[],
                    const int32_T varargin_3_size[2], real_T y_data[], int32_T
                    y_size[2]);

#endif

/* End of code generation (blkdiag.h) */
