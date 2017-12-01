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
	int threshold = 30;
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("CSV Files (*.csv);; All files (*.*)"));
	QFile file(filename);
	if (file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			Mat image;
			image = imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);
			std::vector<Mat> bgr_planes;
			split(image, bgr_planes);

			/// Normalize the result to [ 0, histImage.rows ]
			normalize(bgr_planes[0], bgr_planes[0], 0, 0.0, NORM_MINMAX, -1, Mat());
			normalize(bgr_planes[2], bgr_planes[2], 0, 0.0, NORM_MINMAX, -1, Mat());


			// if image isn't corrupted
			if (image.data) {
				stream << i << ",";
				/*for (int row = 0; row < bgr_planes[0]->row; row++) {
					for (int col = 0; col < bgr_planes[0]->col; col++) {
						if (threshold > bgr_planes[2].at <char>(row, col) / bgr_planes[0].at <char>(row, col)) {

						}
						else {

						}
					}
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

