/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ekf_opt_types.h
 *
 * Code generation for function 'ekf_opt'
 *
 */

#ifndef EKF_OPT_TYPES_H
#define EKF_OPT_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T_23
#define struct_emxArray_real_T_23

struct emxArray_real_T_23
{
  real_T data[23];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_23*/

#ifndef typedef_emxArray_real_T_23
#define typedef_emxArray_real_T_23

typedef struct emxArray_real_T_23 emxArray_real_T_23;

#endif                                 /*typedef_emxArray_real_T_23*/

#ifndef struct_sdJZyASe8DDuih1dvKnCxiG_tag
#define struct_sdJZyASe8DDuih1dvKnCxiG_tag

struct sdJZyASe8DDuih1dvKnCxiG_tag
{
  emxArray_real_T_23 f1;
};

#endif                                 /*struct_sdJZyASe8DDuih1dvKnCxiG_tag*/

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1

typedef struct sdJZyASe8DDuih1dvKnCxiG_tag cell_wrap_1;

#endif                                 /*typedef_cell_wrap_1*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/
#endif

/* End of code generation (ekf_opt_types.h) */
