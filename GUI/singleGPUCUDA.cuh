#ifndef SINGLEGPUCUDA_H_
#define SINGLEGPUCUDA_H_

#include <opencv2\core\cuda\common.hpp>
#include <opencv2\core\cuda_stream_accessor.hpp>

#include "cuda.h"
#include "cuda_runtime.h"

__global__ void findThreshold(cv::cuda::GpuMat b_hist, int *threshold); //cv::cuda::GpuMat b_hist, int *threshold
void getThreshold(cv::cuda::GpuMat b_hist, int *threshold);

#endif // SINGLEGPUCUDA_H_