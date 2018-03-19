#pragma once
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2\core\cuda\common.hpp"

#include "ResizableRubberband.h"

class CPU
{
public:
	CPU(QStringList, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs);
	~CPU();

private:
	void snowFilter(cv::Mat, ResizableRubberband*);
	void snowFilterDebug(cv::Mat, ResizableRubberband*);
	void cloudFilter(cv::Mat, ResizableRubberband*);
	void cloudFilterDebug(cv::Mat, ResizableRubberband*);
	void Mat2Vec(std::vector <uchar> &vec, cv::Mat mat);

	static bool minFunc(const float i, const float j);
};

