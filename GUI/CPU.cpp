#include "stdafx.h"
#include "CPU.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <algorithm>
#include <valarray>  

#include "cuda.h"
#include "ProgressBar.h"


CPU::CPU(QStringList filenames, const std::vector<std::unique_ptr<ResizableRubberband> > *rbs, QString saveName, bool check)
{
	debug = check;
	std::vector<std::unique_ptr<ResizableRubberband> >::const_iterator it;
	std::vector <int>::iterator jt;
	float cloudResult, snowResult;

	// begin timing
	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER t1, t2;           // ticks
	double elapsedTime;

	//ProgressBar *pwindow = new ProgressBar(filenames.size());
	//connect(this, SIGNAL(progress(int)), pwindow, SLOT(recieveUpdate(int)));
	//pwindow->exec();

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);

	// For every image in the series
	for (int i = 0; i < filenames.size(); i++) {
		// load the image in
		cv::Mat image = cv::imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);
		//replace later with metdata from image?
	//	std::vector <float> result;
	//	result.push_back(i);
		// if image isn't corrupted
		if (image.data) {

			// for each rubber band
			for (it = rbs->begin(); it != rbs->end(); it++) {
			//	result.push_back(it->get()->number);
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
						//result.push_back(0);
						//result.push_back (cloudFilter(imageROI));
						cloudResult = cloudFilterDebug(imageROI);
					}
					// cloud
					else if ((*jt) == 1) {
						 snowResult = snowFilterDebug(imageROI);
					}
				}
			}
		}
		// emit progress(i);
		//results.push_back(result);
	}

	//end time
	QueryPerformanceCounter(&t2);

	//millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	//std::cout << "CPU TIME: " << elapsedTime << endl;
	//printResults(elapsedTime, saveName, rbs->size());
}

void CPU::printResults(double time, QString saveName, size_t Size)
{
	std::vector <std::vector <float> >::iterator it;
	QFile file(saveName);
	if (file.open(QIODevice::WriteOnly))
	{
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		// open output stream 
		QTextStream stream(&file);
		// for all results
		for (it = results.begin(); it != results.end(); it++) {
			for (int i = 0; i < (int)Size; i++) {

			}

		}

		QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
	}
}


CPU::~CPU()
{
}

float CPU::snowFilterDebug(cv::Mat roi)
{
	int blueThreshold = 127;
	int lumThreshold = 18;

	//BGR
	std::vector<cv::Mat> planes(3);
	cv::split(roi, planes);

	//HLS
	cv::Mat luminace;
	cv::cvtColor(roi, luminace, cv::COLOR_BGR2HLS);
	std::vector<cv::Mat> luminancePlanes(3);
	cv::split(luminace, luminancePlanes);
	cv::GaussianBlur(luminancePlanes[0], luminancePlanes[0], cv::Size(5, 5), 0);

	//get output
	cv::Mat output, output2;
	cv::threshold(luminancePlanes[0], output, lumThreshold, 255, CV_THRESH_BINARY);
	cv::threshold(planes[0], output2, blueThreshold, 255, CV_THRESH_BINARY);
	cv::bitwise_and(output, output2, output);
	if(debug)
		imshow("Check Image", output);
	return float(cv::countNonZero(output) / (roi.rows*roi.cols));
}

float CPU::cloudFilterDebug(cv::Mat roi)
{
	float threshold = 38;

	std::vector<cv::Mat> planes(3);
	cv::split(roi, planes);

	cv::Mat sub;
	cv::subtract(planes[0], planes[2], sub);

	cv::threshold(sub, sub, threshold, 255, CV_THRESH_BINARY_INV);

	if (debug)
		imshow("Check Image", sub);
	return float(cv::countNonZero(sub) / (roi.rows*roi.cols));
}