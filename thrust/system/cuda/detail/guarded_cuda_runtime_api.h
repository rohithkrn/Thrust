#include <hip/hip_runtime.h>
/*
 *  Copyright 2008-2013 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <thrust/detail/config.h>

// the purpose of this header is to check for the existence of macros
// such as __host__ and __device__, which may already be defined by thrust
// and to undefine them before entering cuda_runtime_api.h (which will redefine them)

// we only try to do this stuff if cuda/include/host_defines.h has been included
//#if !defined(__HOST_DEFINES_H__)
/* In ROCm 1.5, host_defines.h has a macro HIP_INCLUDE_HIP_HCC_DETAIL_HOST_DEFINES_H whereas in ROCm 1.4 the macro is defined as HOST_DEFINES_H. 
While using ROCm 1.4 use the macros defined in ROCm 1.4 */
#if ((defined(__HCC__) && !defined(HIP_INCLUDE_HIP_HCC_DETAIL_HOST_DEFINES_H)) || (defined(__NVCC__) && !defined(__HOST_DEFINES_H__)))
#ifdef __host__
#undef __host__
#endif // __host__

#ifdef __device__
#undef __device__
#endif // __device__

#endif // __HOST_DEFINES_H__

#include <hip/hip_runtime_api.h>

