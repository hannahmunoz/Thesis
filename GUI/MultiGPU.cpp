#include "stdafx.h"
#include "MultiGPU.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <opencv2\core\cuda\common.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/cuda/common.hpp>



MultiGPU::MultiGPU(QStringList filenames, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, QString saveName, bool checked, bool fpsChecked, int fpsValue, int numGPU)
{
	debug = checked;
	std::vector<std::unique_ptr<ResizableRubberband> >::const_iterator it;
	std::vector <int>::iterator jt;
	planes.resize(3);
	luminancePlanes.resize(3);
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

	if (resultsCSV.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&resultsCSV);

		stream << "Picture,";

		for (it = rbs->begin(); it != rbs->end(); it++) {
			stream << "ROI " << it->get()->number << ",";
		}

		stream << endl << ",";

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
					cv::cuda::GpuMat imageROI(image(roi));

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
					imageROI.release();
					stream << result << ",";

					// highlight ROI in the image
					rectangle(image, roi, cv::Scalar(0, 0, 255), 2, 8, 0);
					cv::putText(image, std::to_string(result), cv::Point(roi.x + 5, roi.y + roi.height - 5), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255), 1.5, 8);
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

	planes[0].release();
	planes[1].release();
	planes[2].release();

	luminancePlanes[0].release();
	luminancePlanes[1].release();
	luminancePlanes[2].release();
}


MultiGPU::~MultiGPU()
{
}
