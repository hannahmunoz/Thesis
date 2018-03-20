#pragma once
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2\core\cuda\common.hpp"

#include "ResizableRubberband.h"

class MultiGPU
{
public:
	MultiGPU(QStringList filenames, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, bool checked, int selection);
	~MultiGPU();

private:
	int numGPU;
};

