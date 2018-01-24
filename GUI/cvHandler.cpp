#include "stdafx.h"
#include "GUI.h"

#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include <QFile>
#include <QTextStream>


using namespace cv;



//outputs snow/cloud coverage % to a csv
void GUI::testResults(std::vector<ResizableRubberband*> rbs)
{	// probably move to thread?
	// threshold value
	// > means snow/cloud
	float threshold = 0.75;
	// have the user create a save file
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("CSV Files (*.csv);; All files (*.*)"));
	QFile file(filename);

	//open file to write
	if (file.open(QIODevice::WriteOnly))
	{
		// set up the ProgressBar
		//.PictureProcessingBar->show();
		//ui.PictureProcessingBar->setRange(0, filenames.size());

		// change mouse
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

		// open output stream 
		QTextStream stream(&file);

		//headers
		stream << "Picture," << "ROI " << endl;
		stream << "Date," << "Coverage (percentage)" <<endl;

		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			// increase progress
			//ui.PictureProcessingBar->setValue(i);
			// load the image in
			Mat image = imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);

			// if image isn't corrupted
			if (image.data) {

				// for each region of interest
				for (int j = 0; j < rbs.size(); j++) {
					QRect region = rbs.at(j)->geometry();
					// Y coord isnt working correctly. No idea why.
					float  ratioW = (float)image.cols / (float)ui.PictureFrame->width();
					float  ratioH = (float) image.rows / (float)ui.PictureFrame->height();
					cv::Rect roi( (int) region.x() * ratioW, (int)region.y() * ratioH, region.width(), region.height());
					//Mat imageROI = image(roi);
					Mat imageROI = image(roi);

					//test image showing
					cv::imshow("image", imageROI);

					//Mat imageCheck = imread(filenames[i].toStdString(), 0);

					// output image number
					// will need to be changed to parse datetime stamp if avaible
					stream << i << ",";
					// inital cover percentage = 0
					int imageCoverage = 0;

					// for each row and column in the image
					for (int row = 0; row < imageROI.rows; row++) {
						for (int col = 0; col < imageROI.cols; col++) {
							// get pixel color intensity
							Vec3b intensity = image.at <Vec3b>(row, col);
							// check threshold value
							// probably move to a function so it can be changed easily
							if (threshold > (float) intensity.val[2] / (float)intensity.val[0]) {

								//imageCheck.at<uchar>(row, col) = 0;

							}
							else {
								//increase coverage percentage 
								imageCoverage++;
								//imageCheck.at<uchar>(row, col) = 255;
								// do nothing
							}
						}
					}

						// ouput coverage percentage
						// test outputs
						//imshow("Main Image", image);
						//imshow("Gray image", imageCheck);
						stream << (((float)imageCoverage / ((float)imageROI.rows*(float)imageROI.cols)) * 100);
					}
				}
				// out error to csv
				else {
					stream << i << ",";
					stream << "image cannot be read";
				}
				stream << endl;
			
		}

		// hide the processing bar again
		//ui.PictureProcessingBar->hide();

		// change mouse
		QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
	}
}

void GUI::threadExport() {
	// can I move this to a thread?
	// will have to be changed once the ROI are added

	//
/*	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("Video Files (*.avi);; All files (*.*)"));
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
	ui.PictureProcessingBar->hide();*/
}


void GUI::Export(){
	//needs to be moved to a thread

	// open save file
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("Video Files (*.avi);; All files (*.*)"));

	// show processing bar
	//ui.PictureProcessingBar->show();
	//ui.PictureProcessingBar->setRange(0, filenames.size());

	//change mouse
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

	// get image
	Mat img = imread(filenames[0].toStdString(), CV_LOAD_IMAGE_COLOR);
	//find size
	Size s = img.size();
	// create output video
	// 10 fps
	// at 1 for demo
	VideoWriter out(filename.toStdString(), VideoWriter::fourcc('M', 'J', 'P', 'G'), 1, Size(s.width, s.height), true);
	if (out.isOpened()) {
		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			// if valid image
			if (!img.empty()) {
				// write to the video
				out.write(Mat(imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR)));
			}
			// increase progress
			//ui.PictureProcessingBar->setValue(i);
		}
	}
	// hide processing bar
	//ui.PictureProcessingBar->hide();

	// change mouse
	QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
}

