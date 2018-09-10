/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "ukf_opt.h"
#include "sum.h"

/* Function Definitions */
void sum(const real_T x_data[], const int32_T x_size[2], real_T y_data[],
         int32_T y_size[1])
{
  int32_T vstride;
  int8_T sz[2];
  int32_T j;
  int32_T k;
  int32_T xoffset;
  if ((x_size[0] == 0) || (x_size[1] == 0)) {
    for (vstride = 0; vstride < 2; vstride++) {
      sz[vstride] = (int8_T)x_size[vstride];
    }

    y_size[0] = sz[0];
    vstride = sz[0];
    if (0 <= vstride - 1) {
      memset(&y_data[0], 0, (uint32_T)(vstride * (int32_T)sizeof(real_T)));
    }
  } else {
    vstride = x_size[0];
    y_size[0] = (int8_T)x_size[0];
    for (j = 0; j < vstride; j++) {
      y_data[j] = x_data[j];
    }

    for (k = 2; k <= x_size[1]; k++) {
      xoffset = (k - 1) * vstride;
      for (j = 0; j < vstride; j++) {
        y_data[j] += x_data[xoffset + j];
      }
    }
  }
}

/* End of code generation (sum.c) */
