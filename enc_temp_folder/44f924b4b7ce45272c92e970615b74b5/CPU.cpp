#include "stdafx.h"
#include "CPU.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <algorithm>
#include <valarray>  
#include "ProgressBar.h"
#include "tinyxml2.h"


CPU::CPU(QStringList filenames, const std::vector<std::unique_ptr<ResizableRubberband> > *rbs, QString saveName, bool check, bool fpsChecked, int fpsValue)
{
	debug = check;
	std::vector<std::unique_ptr<ResizableRubberband> >::const_iterator it;
	std::vector <int>::iterator jt;
	cv::Mat test = cv::imread(filenames[0].toStdString(), CV_LOAD_IMAGE_COLOR);
	cv::VideoWriter out;
	// video 
	if (fpsChecked) {
		QString videoName = saveName.mid(0, saveName.length() - 3);
		videoName.append("avi");
		out.open(videoName.toStdString(), cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fpsValue, test.size(), true);
	}
	// csv
	QFile resultsCSV(saveName);

	// metadata
	tinyxml2::XMLDocument* metadata = new tinyxml2::XMLDocument();

	if (resultsCSV.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&resultsCSV);

		stream << "Picture,";

		for (it = rbs->begin(); it != rbs->end(); it++) {
			stream << "ROI " << it->get()->number << ",";
		}

		stream  << endl << ",";

		for (it = rbs->begin(); it != rbs->end(); it++) {
			stream << it->get()->width() << " x " << it->get()->height() << ",";
		}

		stream << endl << "Detection Type,";

		for (it = rbs->begin(); it != rbs->end(); it++) {
			std::vector <int> filter = it->get()->getFilters();
			for (jt = filter.begin(); jt != filter.end(); jt++) {
				if ((*jt) == 0) {
					stream << "Cloud Coverage (%),";
				}
				else if ((*jt) == 1) {
					stream << "Snow Coverage (%),";
				}
			}
		}
		stream << endl;

		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			// load the image in
			cv::Mat image = cv::imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);

			// if image isn't corrupted
			if (image.data) {
				stream << i << ",";

				// for each rubber band
				for (it = rbs->begin(); it != rbs->end(); it++) {
					//get the ROI
					QRect region = it->get()->geometry();
					cv::Rect roi((int)region.x(), (int)region.y(), region.width(), region.height());
					cv::Mat imageROI = image(roi).clone();

					//get filters
					std::vector <int> filter = it->get()->getFilters();

					//for each filter on the rubberBand
					for (jt = filter.begin(); jt != filter.end(); jt++) {
						// snow
						if ((*jt) == 0) {
							stream << cloudFilterDebug(imageROI) << ",";
						}
						// cloud
						else if ((*jt) == 1) {
							stream << snowFilterDebug(imageROI) << ",";
						}

					}
					//WHY CANT I GET THIS WORKING
					/*if (fpsChecked) {
						imageROI.copyTo(image(roi));
					}*/
				}
				/*if (fpsChecked) {
					// write to the video
					out.write(image);
				}*/
			}
			// out error to csv
			else {
				stream << i << ",";
				stream << "image cannot be read";
			}
			stream << endl;
		}
	}
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

float CPU::snowFilterDebug(cv::Mat &roi)
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
	cv::GaussianBlur(luminancePlanes[0], luminancePlanes[0], cv::Size(15, 15), 0);

	//get output
	cv::Mat output, output2;
	cv::threshold(luminancePlanes[0], output, lumThreshold, 255, CV_THRESH_BINARY);
	cv::threshold(planes[0], output2, blueThreshold, 255, CV_THRESH_BINARY);
	cv::bitwise_and(output, output2, roi);
	if(debug)
		imshow("Check Image", roi);
	return float(cv::countNonZero(roi) / (roi.rows*roi.cols));
}

float CPU::cloudFilterDebug(cv::Mat &roi)
{
	float threshold = 38;

	std::vector<cv::Mat> planes(3);
	cv::split(roi, planes);

	cv::Mat sub;
	cv::subtract(planes[0], planes[2], sub);

	cv::threshold(sub, roi, threshold, 255, CV_THRESH_BINARY_INV);

	if (debug)
		imshow("Check Image", roi);
	int test = cv::countNonZero(roi);
	int test2 = roi.rows*roi.cols;
	float result = float(cv::countNonZero(roi)) / float(roi.rows*roi.cols);
	return float(cv::countNonZero(roi)) / float(roi.rows*roi.cols) * 100;
}