/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * blkdiag.c
 *
 * Code generation for function 'blkdiag'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "blkdiag.h"

/* Function Declarations */
static void output_size(const int32_T varargin_1_size[2], const int32_T
  varargin_2_size[2], const int32_T varargin_3_size[2], int32_T *nrows, int32_T *
  ncols);

/* Function Definitions */
static void output_size(const int32_T varargin_1_size[2], const int32_T
  varargin_2_size[2], const int32_T varargin_3_size[2], int32_T *nrows, int32_T *
  ncols)
{
  *nrows = (varargin_1_size[0] + varargin_2_size[0]) + varargin_3_size[0];
  *ncols = (varargin_1_size[1] + varargin_2_size[1]) + varargin_3_size[1];
}

void blkdiag(const real_T varargin_1_data[], const int32_T varargin_1_size[2],
             const real_T varargin_2_data[], const int32_T varargin_2_size[2],
             const real_T varargin_3_data[], const int32_T varargin_3_size[2],
             real_T y_data[], int32_T y_size[2])
{
  int32_T nrows;
  int32_T r;
  int32_T i0;
  int32_T c;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  output_size(varargin_1_size, varargin_2_size, varargin_3_size, &nrows, &r);
  y_size[0] = nrows;
  y_size[1] = r;
  r *= nrows;
  if (0 <= r - 1) {
    memset(&y_data[0], 0, (uint32_T)(r * (int32_T)sizeof(real_T)));
  }

  if ((varargin_1_size[0] > 0) && (varargin_1_size[1] > 0)) {
    r = varargin_1_size[1];
    for (i0 = 0; i0 < r; i0++) {
      c = varargin_1_size[0];
      for (i1 = 0; i1 < c; i1++) {
        y_data[i1 + nrows * i0] = varargin_1_data[i1 + varargin_1_size[0] * i0];
      }
    }
  }

  if ((varargin_2_size[0] > 0) && (varargin_2_size[1] > 0)) {
    if (varargin_1_size[0] + 1 > varargin_1_size[0] + varargin_2_size[0]) {
      i0 = 1;
    } else {
      i0 = varargin_1_size[0] + 1;
    }

    if (varargin_1_size[1] + 1 > varargin_1_size[1] + varargin_2_size[1]) {
      i1 = 1;
    } else {
      i1 = varargin_1_size[1] + 1;
    }

    r = varargin_2_size[1];
    for (i2 = 0; i2 < r; i2++) {
      c = varargin_2_size[0];
      for (i3 = 0; i3 < c; i3++) {
        y_data[((i0 + i3) + nrows * ((i1 + i2) - 1)) - 1] = varargin_2_data[i3 +
          varargin_2_size[0] * i2];
      }
    }
  }

  r = varargin_1_size[0] + varargin_2_size[0];
  c = varargin_1_size[1] + varargin_2_size[1];
  if ((varargin_3_size[0] > 0) && (varargin_3_size[1] > 0)) {
    if (r + 1 > r + varargin_3_size[0]) {
      i0 = 1;
    } else {
      i0 = r + 1;
    }

    if (c + 1 > c + varargin_3_size[1]) {
      i1 = 1;
    } else {
      i1 = c + 1;
    }

    r = varargin_3_size[1];
    for (i2 = 0; i2 < r; i2++) {
      c = varargin_3_size[0];
      for (i3 = 0; i3 < c; i3++) {
        y_data[((i0 + i3) + nrows * ((i1 + i2) - 1)) - 1] = varargin_3_data[i3 +
          varargin_3_size[0] * i2];
      }
    }
  }
}

/* End of code generation (blkdiag.c) */
