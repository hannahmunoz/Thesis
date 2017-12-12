#include "stdafx.h"
#include "GUI.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include <QFile>
#include <QTextStream>


using namespace cv;

//outputs snow/cloud coverage % to a csv
void GUI::testResults()
{	// probably move to thread?

	// threshold value
	// > means snow/cloud
	float threshold = 0.60;
	// have the user create a save file
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("CSV Files (*.csv);; All files (*.*)"));
	QFile file(filename);

	//open file to write
	if (file.open(QIODevice::WriteOnly))
	{
		// set up the ProgressBar
		ui.PictureProcessingBar->show();
		ui.PictureProcessingBar->setRange(0, filenames.size());

		// change mouse
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

		// open output stream 
		QTextStream stream(&file);

		//headers
		stream << "Picture," << "ROI 1";
		stream << "," << "Coverage (percentage)";

		// For every image in the series
		for (int i = 0; i < filenames.size(); i++) {
			// increase progress
			ui.PictureProcessingBar->setValue(i);
			// load the image in
			Mat image;
			image = imread(filenames[i].toStdString(), CV_LOAD_IMAGE_COLOR);

			// if image isn't corrupted
			if (image.data) {
				// output image number
				// will need to be changed to parse datetime stamp if avaible
				stream << i << ",";
				// inital cover percentage = 0
				int imageCoverage = 0;

				// for each row and column in the image
				for (int row = 0; row < image.rows; row++) {
					for (int col = 0; col < image.cols; col++) {
						// get pixel color intensity
						Vec3b intensity = image.at <Vec3b>(row, col);
						// check threshold value
						// probably move to a function so it can be changed easily
						if (threshold > (float) intensity.val[2] / (float) intensity.val[0]){
							//increase coverage percentage 
							imageCoverage++;
						}
						else {
							// do nothing
						}
					}
				}

				// ouput coverage percentage
				stream << (((float)imageCoverage/((float)image.rows*(float)image.cols))*100);
			}
			// out error to csv
			else {
				stream << i << ",";
				stream << "image cannot be read";
			}
			stream << endl;
		}

		// hide the processing bar again
		ui.PictureProcessingBar->hide();

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
	ui.PictureProcessingBar->show();
	ui.PictureProcessingBar->setRange(0, filenames.size());

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
			ui.PictureProcessingBar->setValue(i);
		}
	}
	// hide processing bar
	ui.PictureProcessingBar->hide();

	// change mouse
	QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
}

