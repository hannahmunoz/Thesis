#pragma once
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2\core\cuda\common.hpp"

#include "ResizableRubberband.h"


class SingleGPU
{
public:
	SingleGPU(QStringList, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, bool);
	~SingleGPU();
private:
	float snowFilterDebug(cv::cuda::GpuMat);
	float cloudFilterDebug(cv::cuda::GpuMat);

	bool debug;
};

