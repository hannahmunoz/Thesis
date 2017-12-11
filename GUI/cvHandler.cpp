#include "stdafx.h"
#include "GUI.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include <QFile>
#include <QTextStream>

using namespace cv;

void GUI::testResults()
{

	float threshold = 0.60;
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("CSV Files (*.csv);; All files (*.*)"));
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly))
	{
		ui.PictureProcessingBar->show();
		ui.PictureProcessingBar->setRange(0, filenames.size());
		QTextStream stream(&file);
		stream << "Picture," << "ROI 1";
		stream << "," << "Coverage \%";
		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			ui.PictureProcessingBar->setValue(i);
			Mat image;
			image = imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);

			// if image isn't corrupted
			if (image.data) {
				/*std::vector<Mat> bgr_planes;
				split(image, bgr_planes);

				/// Normalize the result to [ 0, histImage.rows ]
				normalize(bgr_planes[0], bgr_planes[0], 0, 0.0, NORM_MINMAX, -1, Mat());
				normalize(bgr_planes[2], bgr_planes[2], 0, 0.0, NORM_MINMAX, -1, Mat());*/
				stream << i << ",";
				int imageCoverage = 0;

				for (int row = 0; row < image.rows; row++) {
					for (int col = 0; col < image.cols; col++) {
						Vec3b intensity = image.at <Vec3b>(row, col);
						if (threshold > (float) intensity.val[2] / (float) intensity.val[0]){
							imageCoverage++;
						}
						else {

						}
					}
				}

				stream << (((float)imageCoverage/((float)image.rows*(float)image.cols))*100);
			}
			// out error to csv
			else {
				stream << i << ",";
				stream << "image cannot be read";
			}
			stream << endl;
		}

		ui.PictureProcessingBar->hide();
	}
}

void GUI::threadExport() {
	// can I move this to a thread?
	// will have to be changed once the ROI are added
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("Video Files (*.avi);; All files (*.*)"));
	ui.PictureProcessingBar->show();
	ui.PictureProcessingBar->setRange(0, filenames.size());
	Mat img = imread(filenames[0].toStdString(), CV_LOAD_IMAGE_COLOR);
	Size s = img.size();
	std::cout << s.width << ", " << s.height << std::endl;
	VideoWriter out(filename.toStdString(), VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, Size(s.width, s.height), true);
	if (out.isOpened()) {
		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			if (!img.empty()) {
				out.write(Mat(imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR)));
			}
			ui.PictureProcessingBar->setValue(i);
		}
	}
	ui.PictureProcessingBar->hide();
}


void GUI::Export(){

	//std::thread first(threadExport);

	//first.join();
}

