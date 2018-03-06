#include "stdafx.h"
#include "CPU.h"

#include "cuda.h"


CPU::CPU(QStringList filenames, const std::vector<std::unique_ptr<ResizableRubberband> > *rbs)
{
	std::vector<std::unique_ptr<ResizableRubberband> >:: const_iterator it;
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

void CPU::snowFilterDebug(cv::Mat roi, ResizableRubberband * rb)
{
	// median filter?
	cv::Vec3b white(255, 255, 255);
	cv::Vec3b black(0, 0, 0);
	int imageCoverage = 0;

	// for each row and column in the image
	/*for (int row = 0; row < roi.rows; row++) {
		for (int col = 0; col < roi.cols; col++) {

		}
	}*/
	//
	//cv::bilateralFilter(roi, roi, 5);
	cv::Mat output;
	cv::cvtColor(roi, output, cv::COLOR_BGR2GRAY);
	//cv::medianBlur(output, output, 5);
	//cv::adaptiveThreshold(output, output, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);
	//cv::GaussianBlur(output, output, cv::Size (3,3), 0);
	cv::threshold(output, output, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
	imshow("Check Image", output);


}

void CPU::cloudFilter(cv::Mat roi, ResizableRubberband* rb)
{
	float threshold = 38;
	int imageCoverage = 0;

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