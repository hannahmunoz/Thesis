#include "stdafx.h"
#include "SingleGPU.h"
#include "singleGPUCUDA.cuh"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <opencv2\core\cuda\common.hpp>
#include <opencv2\core\cuda_stream_accessor.hpp>
#include "device_launch_parameters.h"



SingleGPU::SingleGPU(QStringList filenames, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, bool checked)
{
	debug = checked;
	std::vector<std::unique_ptr<ResizableRubberband> >::const_iterator it;
	std::vector <int>::iterator jt;

	// begin timing
	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER t1, t2;           // ticks
	double elapsedTime;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);

	// For every image in the series
	for (int i = 0; i < filenames.size(); i++) {
		// load the image in
		cv::Mat image = cv::imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);

		// if image isn't corrupted
		if (image.data) {

			// for each rubber band
			for (it = rbs->begin(); it != rbs->end(); it++) {
				//get the ROI
				QRect region = it->get()->geometry();
				cv::Rect roi((int)region.x(), (int)region.y(), region.width(), region.height());
				cv::cuda::GpuMat imageROI(image(roi));

				//get filters
				std::vector <int> filter = it->get()->getFilters();

				//for each filter on the rubberBand
				for (jt = filter.begin(); jt != filter.end(); jt++) {
					// snow
					if ((*jt) == 0) {
						cloudFilterDebug(imageROI);
					}
					// cloud
					else if ((*jt) == 1) {
						snowFilterDebug(imageROI);
					}
				}
				imageROI.release();
			}
		}
	}

	//end time
	QueryPerformanceCounter(&t2);

	//millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	//std::cout << "SINGLE GPU TIME: " << elapsedTime << endl;
}


SingleGPU::~SingleGPU()
{
}


float SingleGPU::snowFilterDebug(cv::cuda::GpuMat roi)
{
	int blueThreshold = 127;
	int lumThreshold = 18;

	//BGR
	std::vector<cv::cuda::GpuMat> planes(3);
	cv::cuda::split(roi, planes);

	//HLS
	cv::cuda::GpuMat luminace;
	cv::cuda::cvtColor(roi, luminace, cv::COLOR_BGR2HLS);
	std::vector<cv::cuda::GpuMat> luminancePlanes(3);
	cv::cuda::split(luminace, luminancePlanes);
	cv::Ptr<cv::cuda::Filter> filter = cv::cuda::createGaussianFilter(luminancePlanes[0].type(), luminancePlanes[0].type(), cv::Size(5, 5), 0);
	filter->apply(luminancePlanes[0], luminancePlanes[0]);

	//get output
	cv::cuda::GpuMat output, output2;
	cv::cuda::threshold(luminancePlanes[0], output, lumThreshold, 255, CV_THRESH_BINARY);
	cv::cuda::threshold(planes[0], output2, blueThreshold, 255, CV_THRESH_BINARY);
	cv::cuda::bitwise_and(output, output2, output);

	//download
	int imageCoverage = cv::cuda::countNonZero(output);
	if (debug) {
		cv::Mat CPUout;
		output.download(CPUout);
		imshow("Check Image", CPUout);
	}

	//releases
	planes[0].release();
	planes[1].release();
	planes[2].release();

	luminace.release();

	luminancePlanes[0].release();
	luminancePlanes[1].release();
	luminancePlanes[2].release();

	output.release();
	output2.release();

	return float(imageCoverage / (roi.rows*roi.cols));
}

float SingleGPU::cloudFilterDebug(cv::cuda::GpuMat roi)
{
	float threshold = 38;

	std::vector<cv::cuda::GpuMat> planes(3);
	cv::cuda::split(roi, planes);

	cv::cuda::GpuMat sub;
	cv::cuda::subtract(planes[0], planes[2], sub);

	cv::cuda::threshold(sub, sub, threshold, 255, CV_THRESH_BINARY_INV);
	int imageCoverage = cv::cuda::countNonZero(sub);

	if (debug) {
		cv::Mat CPU(sub);
		imshow("Check Image", CPU);
	}

	planes[0].release();
	planes[1].release();
	planes[2].release();
	sub.release();

	return float(imageCoverage / (roi.rows*roi.cols));
}
