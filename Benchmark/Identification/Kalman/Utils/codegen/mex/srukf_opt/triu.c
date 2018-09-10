/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * triu.c
 *
 * Code generation for function 'triu'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "srukf_opt.h"
#include "triu.h"

/* Function Definitions */
void triu(real_T x_data[], int32_T x_size[2])
{
  int32_T m;
  int32_T istart;
  int32_T jend;
  int32_T j;
  int32_T i;
  m = x_size[0];
  if ((x_size[0] == 0) || (x_size[1] == 0) || (1 >= x_size[0])) {
  } else {
    istart = 2;
    if (x_size[0] - 2 < x_size[1] - 1) {
      jend = x_size[0] - 1;
    } else {
      jend = x_size[1];
    }

    for (j = 1; j <= jend; j++) {
      for (i = istart; i <= m; i++) {
        x_data[(i + x_size[0] * (j - 1)) - 1] = 0.0;
      }

      istart++;
    }
  }
}

/* End of code generation (triu.c) */
