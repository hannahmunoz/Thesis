#include "stdafx.h"
#include "CPU.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <algorithm>
#include <valarray>  

#include "cuda.h"


CPU::CPU(QStringList filenames, const std::vector<std::unique_ptr<ResizableRubberband> > *rbs)
{
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
				cv::Mat imageROI = image(roi);

				//get filters
				std::vector <int> filter = it->get()->getFilters();

				//for each filter on the rubberBand
				for (jt = filter.begin(); jt != filter.end(); jt++) {
					// snow
					if ((*jt) == 0) {
						cloudFilterDebug(imageROI, it->get());
					}
					// cloud
					else if ((*jt) == 1) {
						snowFilterDebug(imageROI, it->get());
					}
				}
			}
		}
	}

	//end time
	QueryPerformanceCounter(&t2);

	//millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	std::cout << "CPU TIME: " << elapsedTime << endl;
}


CPU::~CPU()
{
}

void CPU::snowFilter(cv::Mat roi, ResizableRubberband* rb)
{

}

bool CPU::minFunc(const float i, const float j) { return  i > 127.0; }

void CPU::snowFilterDebug(cv::Mat roi, ResizableRubberband * rb)
{

	cv::Vec3b white(255, 255, 255);
	cv::Vec3b black(0, 0, 0);
	int imageCoverage = 0;

	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	cv::Mat b_hist, g_hist, r_hist;

	//BGR
	cv::Mat output;
	roi.copyTo(output);

	std::vector<cv::Mat> planes(3);
	cv::split(output, planes);

	calcHist(&planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, true, false);
	//calcHist(&planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, true, false);
	//calcHist(&planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, true, false);
	cv::GaussianBlur(b_hist, b_hist, cv::Size(5, 5), 0);

	std::vector<int>blue; (b_hist.begin<float>(), b_hist.end<float>());
	//std::vector<int>green(b_hist.begin<float>(), b_hist.end<float>());
	//std::vector<int>red(r_hist.begin<float>(), r_hist.end<float>());

	std::vector<uchar> blueCheck;
	Mat2Vec(blueCheck, planes[0]);

	int threshold = 127;
	for (int i = 127; i <= blue.size(); i++) {
		if ((blue[i] > blue[i+1] && blue[i] < blue[i - 1])) {
			threshold = i;
			break;
		}
	}

	cv::Mat luminace;
	cv::cvtColor(roi, luminace, cv::COLOR_BGR2HLS);

	std::vector<cv::Mat> luminancePlanes(3);
	cv::split(luminace, luminancePlanes);
	cv::GaussianBlur(luminancePlanes[0], luminancePlanes[0], cv::Size(5, 5), 0);
	std::vector <uchar> lum;
	Mat2Vec(lum, luminancePlanes[0]);

	// for each row and column in the image
	for (int row = 0; row < roi.rows; row++) {
		for (int col = 0; col <roi.cols; col++) {
			if (threshold < blueCheck [row*roi.cols+col] && lum [row*roi.cols + col]  > 20) {
				output.at <cv::Vec3b>(cv::Point(col, row)) = white;
			}
			else {
				output.at <cv::Vec3b>(cv::Point(col, row)) = black;
			}
		}
	}
	imshow("Check Image", output);
}


void CPU::Mat2Vec(std::vector <uchar> &vec, cv::Mat mat) {
	if (mat.isContinuous()) {
		vec.assign(mat.datastart, mat.dataend);
	}
	else {
		for (int i = 0; i < mat.rows; ++i) {
			vec.insert(vec.end(), mat.ptr<uchar>(i), mat.ptr<uchar>(i) + mat.cols);
		}
	}
}

void CPU::cloudFilter(cv::Mat roi, ResizableRubberband* rb)
{
	float threshold = 38;
	int imageCoverage = 0;

	//BGR
	std::vector<cv::Mat> planes(3);
	cv::split(roi, planes);

	cv::Mat sub;
	cv::subtract(planes[0], planes[2], sub);

	for (int row = 0; row < roi.rows; row++) {
		for (int col = 0; col < roi.cols; col++) {
			if (threshold > sub.at <uchar>(row, col)) {
				imageCoverage++;
			}
		}
	}
}

void CPU::cloudFilterDebug(cv::Mat roi, ResizableRubberband* rb)
{
	float threshold = 38;
	cv::Vec3b white(255, 255, 255);
	cv::Vec3b black(0, 0, 0);

	std::vector<cv::Mat> planes(3);
	cv::split(roi, planes);

	cv::Mat sub;
	cv::subtract(planes[0], planes[2], sub);

	cv::Mat output;
	roi.copyTo(output);

	for (int row = 0; row < roi.rows; row++) {
		for (int col = 0; col < roi.cols; col++){
			if (threshold > sub.at <uchar>(row, col)) {
				output.at <cv::Vec3b>(cv::Point(col, row)) = white;
			}
			else {
				output.at <cv::Vec3b>(cv::Point(col, row)) = black;
			}
		}
	}

	imshow("Check Image", output);
}