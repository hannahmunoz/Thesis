#include "singleGPUCUDA.cuh"
#include "device_launch_parameters.h"


__global__ void findThreshold(cv::cuda::GpuMat b_hist, int *threshold) {
	/*std::vector<int>blue = (b_hist.datastart(), b_hist.dataend());

	std::vector<uchar> blueCheck;
	Mat2Vec(blueCheck, planes[0]);*/
	int *blue = (int*)b_hist.data;
	//int *blue = (int*)b_hist.data;

	//int threshold = 127;
	for (int i = 127; i <= b_hist.cols; i++) {
		if ((blue[i] > blue[i + 1] && blue[i] < blue[i - 1])) {
			threshold[0] = i;
			break;
		}
	}
}

void getThreshold(cv::cuda::GpuMat b_hist, int *threshold) {
		int *t;
		cudaMalloc((void**)&t, sizeof(int));
		cudaMemcpy(t, threshold, sizeof(int), cudaMemcpyHostToDevice);
		findThreshold <<< 1, 1 >>> ( b_hist, threshold);

}