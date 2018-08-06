#include "stdafx.h"
#include "MultiGPU.h"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <opencv2\core\cuda\common.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/cuda/common.hpp>
#include <cmath>
#include <vector>
#include <book.h>

#include "device_launch_parameters.h"
#include "ErrorHandler.h"
#include <direct.h>
#define GetCurrentDir _getcwd

struct DataStruct
{
	int numGPU;
	int deviceID;
	const std::vector< std::unique_ptr<ResizableRubberband> > *rbs;
	QStringList filenames;
};

MultiGPU::MultiGPU(QStringList filenames, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, QString saveName, bool checked, bool fpsChecked, int fpsValue, int numGPU)
{
	if (cv::cuda::getCudaEnabledDeviceCount() <= 0) {
		ErrorHandler *eWindow = new ErrorHandler();
		QString errorMsg = "No CUDA compatible GPU avaible";
		eWindow->setLabel(errorMsg);
		eWindow->exec();
		return;
	}

	CUTThread *threads = new CUTThread[numGPU];
	DataStruct* threadData = new DataStruct[numGPU];

	cv::cuda::GpuMat test;
	test.create(1, 1, CV_8U);


	debug = checked;
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

	std::string metaName = saveName.mid(0, saveName.length() - 3).toStdString();
	metaName.append("xml");

	char temp[FILENAME_MAX];
	GetCurrentDir(temp, FILENAME_MAX);
	std::string metaPath(temp);
	metaPath.append("/userMetadata.xml");

	std::ifstream src(metaPath.c_str(), std::ios::binary);
	std::ofstream  dst(metaName.c_str(), std::ios::binary);
	dst << src.rdbuf();

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
			if (filter.empty()) {
				ErrorHandler *eWindow = new ErrorHandler();
				QString errorMsg = "ROI " + QString::number(it->get()->number) + " has no detection type.";
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


		//loop through GPU
		for (int i = 0; i < numGPU; i++) {
			// fill thread data
			threadData[i].deviceID = i;
			threadData[i].numGPU = numGPU;
			threadData[i].rbs = rbs;
			threadData[i].filenames = filenames;
			threads[i] = start_thread(threadRoutine, &(threadData[i]));
		}
		wait_for_threads(threads, numGPU);

		stream << QString::fromStdString(filenames[i].toStdString()) << ",";

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

void* threadRoutine(void *tData) {
		DataStruct *data = (DataStruct*)tData;
		cv::cuda::setDevice(data->deviceID);
		cv::cuda::Stream stream;
		std::vector<cv::cuda::GpuMat> planes(3);
		cv::cuda::GpuMat output, output2, image;
		cv::Mat cpu;
		std::vector<std::unique_ptr<ResizableRubberband> >::const_iterator it;
		std::vector <int>::iterator jt;

		int imageNum = data->filenames.size() / data->numGPU;
		int startNum = imageNum * (data->deviceID);
		//printf ("%d, %d, %d\n", imageNum, startNum,  imageNum * (data->deviceID + 1));
		for (int i = startNum; i < imageNum * (data->deviceID + 1) && i < data->filenames.size(); i++) {
			cv::Mat image = cv::imread(data->filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);
			// if image isn't corrupted
			if (image.data) {
				// for each rubber band
				for (it = data->rbs->begin(); it != data->rbs->end(); it++) {
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
							//result = cloudFilterDebug(imageROI);
						}
						// cloud
						else if ((*jt) == 1) {
							//result = snowFilterDebug(imageROI);
						}
					}
					imageROI.release();
				}
			}
		}
}


MultiGPU::~MultiGPU()
{
}


