#include "stdafx.h"
#include "CPU.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <algorithm>
#include <valarray>  
#include "ErrorHandler.h"
#include <stdlib.h>

#include <direct.h>
#define GetCurrentDir _getcwd


CPU::CPU(QStringList filenames, const std::vector<std::unique_ptr<ResizableRubberband> > *rbs, QString saveName, bool check, bool fpsChecked, int fpsValue)
{
	debug = check;
	std::vector<std::unique_ptr<ResizableRubberband> >::const_iterator it;
	std::vector <int>::iterator jt;
	// get the metadata
	// Apparently our cameras dont have metadata
	// Exiv2::Image::AutoPtr md = Exiv2::ImageFactory::open(filenames[0].toStdString());
	// md->readMetadata();
	// Exiv2::ExifData &exifData = md->exifData();

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

	std::string metaName = saveName.mid(0, saveName.length() - 3).toStdString();
	metaName.append("xml");

	char temp[FILENAME_MAX];
	GetCurrentDir(temp, FILENAME_MAX);
	std::string metaPath(temp);
	metaPath.append("/userMetadata.xml");

	std::ifstream src(metaPath.c_str(), std::ios::binary);
	std::ofstream  dst(metaName.c_str(), std::ios::binary);
	dst << src.rdbuf();

	// metadata
	//tinyxml2::XMLDocument* metadata = new tinyxml2::XMLDocument();

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
			if (filter.empty()) {
				ErrorHandler *eWindow = new ErrorHandler();
				QString errorMsg = "ROI " + QString::number (it->get()->number) +" has no detection type.";
				eWindow->setLabel(errorMsg);
				eWindow->exec();
				return;
			}
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
				stream << QString::fromStdString (filenames[i].toStdString()) << ",";

				// for each rubber band
				for (it = rbs->begin(); it != rbs->end(); it++) {
					//get the ROI
					QRect region = it->get()->geometry();
					cv::Rect roi((int)region.x(), (int)region.y(), region.width(), region.height());
					cv::Mat imageROI = image(roi).clone();

					//get filters
					std::vector <int> filter = it->get()->getFilters();
					
					float result;
					//for each filter on the rubberBand
					for (jt = filter.begin(); jt != filter.end(); jt++) {
						// snow
						if ((*jt) == 0) {
							result = cloudFilterDebug(imageROI);
						}
						// cloud
						else if ((*jt) == 1) {
							result = snowFilterDebug(imageROI);
						}

					}
					stream << result << ",";

					// highlight ROI in the image
					rectangle(image, roi, cv::Scalar (0,0,255) , 2, 8, 0);
					cv::putText(image, std::to_string (result), cv::Point(roi.x +5, roi.y + roi.height-5), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar (0,0,255), 1.5, 8);
					
					// add coverage percentage


				}
				if (fpsChecked) {
					// write to the video
					out.write(image);
				}
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
	cv::cvtColor(roi, luminace, cv::COLOR_BGR2HSV);
	std::vector<cv::Mat> luminancePlanes(3);
	cv::split(luminace, luminancePlanes);

	cv::GaussianBlur(luminancePlanes[0], luminancePlanes[0], cv::Size(15, 15), 0);

	//get output
	cv::Mat output, output2;
	cv::threshold(luminancePlanes[0], output, lumThreshold, 255, CV_THRESH_BINARY);
	//cv::threshold(luminancePlanes[1], output2, 25, 255, CV_THRESH_BINARY_INV);
	//cv::bitwise_and(output, output2, roi);
	cv::threshold(planes[0], output2, blueThreshold, 255, CV_THRESH_BINARY);
	cv::bitwise_and(output, output2, roi);
	if(debug)
		imshow("Check Image", roi);
	return float(cv::countNonZero(roi)) / float(roi.rows*roi.cols) * 100;
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

	return float(cv::countNonZero(roi)) / float(roi.rows*roi.cols) * 100;
}