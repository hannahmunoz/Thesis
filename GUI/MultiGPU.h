#pragma once
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2\core\cuda\common.hpp"

#include "ResizableRubberband.h"

class MultiGPU
{
public:
	MultiGPU(QStringList filenames, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, QString saveName, bool checked, bool fpsChecked, int fpsValue, int numGPU);
	~MultiGPU();

private:
	//float snowFilterDebug(cv::cuda::GpuMat);
	//float cloudFilterDebug(cv::cuda::GpuMat);


	//std::vector<cv::cuda::GpuMat> planes;
	//std::vector<cv::cuda::GpuMat> luminancePlanes;
	bool debug;
};
void* threadRoutine(void *tData);

