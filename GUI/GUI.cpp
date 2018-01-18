#include "stdafx.h"
#include "GUI.h"

#include "ClickableLabel.h"
#include <qfile.h>
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qpixmap.h>
#include <Metadata.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
using namespace cv;

//main window
GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	// create window
	ui.setupUi(this);

	//set up the processing bar
	//connect(ui.PictureProcessingBar, SIGNAL(signalProgress(int)), ui.PictureProcessingBar, SLOT(setValue(int)));
	ui.PictureProcessingBar->hide();

	//set up the slider
	connect(ui.ImageScroller, SIGNAL(valueChanged(int)), this, SLOT(loadPictures(int)));
	ui.ImageScroller->setRange(0, 0);

	//set up the toolbox
	//populateToolbox();
	//tools = new ToolHandler();
	//connect(ui.Toolbox, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), tools, SLOT(menuHandler (QListWidgetItem *, QListWidgetItem *)));
	connect(ui.toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(selection(QAction*)));
	connect(this, SIGNAL(onChange(QString)), ui.PictureFrame, SLOT(setSelection(QString)));

	//label events
	//connect(ui.Toolbox, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT( passSelection(QListWidgetItem *)));

	//connect RGB Viewer
	connect(this, SIGNAL(imageSet(cv::Mat)), this, SLOT(loadRGB(cv::Mat)));

	//connect Process Button
	//connect(ui.ProcessButton, SIGNAL(clicked()), ui.PictureFrame, SLOT(getROI()));
	//connect(ui.PictureFrame, SIGNAL(returnROI(std::vector<ResizableRubberband*>)), this, SLOT(testResults(std::vector<ResizableRubberband*>)));
	//connect(ui.ProcessButton, SIGNAL(clicked()), this, SLOT(testResults()));
	//connect(ui.ExportButton, SIGNAL(clicked()), this, SLOT(Export()));
	//ui.ProcessButton->setEnabled(false);
	//ui.ExportButton->setEnabled(false);

	//connect edit
	connect(ui.menuEdit, SIGNAL(triggered(QAction *)), this, SLOT(loadMDWindow()));

	connect(ui.PictureFrame, SIGNAL(GUIPass(QRect)), this, SLOT(changeHist(QRect)));

}

void GUI::loadPictures(int center)
{
	//load pictures
	ui.PictureFrame->setPix(filenames.at(center));
	// and center
	singleImage(ui.CenterScollImage, filenames.at(center));
	emit imageSet(imread(filenames.at(center).toStdString(), CV_LOAD_IMAGE_COLOR));

	//lefts
	if (center - 2 >= 0) {
		singleImage(ui.FarLeftScrollImage, filenames.at(center - 2));
	}
	else {
		singleImage(ui.FarLeftScrollImage, NULL);
	}
	if (center - 1 >= 0) {
		singleImage(ui.LeftScrollImage, filenames.at(center-1));
	}
	else {
		singleImage(ui.LeftScrollImage, NULL);
	}

	//Rights
	if (center + 1 < filenames.size()) {
		singleImage(ui.RightScrollImage, filenames.at(center + 1));
	}
	else {
		singleImage(ui.RightScrollImage, NULL);
	}
	if (center + 2 < filenames.size()) {
		singleImage(ui.FarRightScrollImage, filenames.at(center + 2));
	}
	else {
		singleImage(ui.FarRightScrollImage, NULL);
	}
}

void GUI::passSelection(QListWidgetItem *item)
{
	// pass current selection to the tool box
	//ui.PictureFrame->setSelection(tools->getCurrentSelection());
}


void GUI::singleImage(QLabel *image, QString file) {
	// set a single image in a label
	image->setPixmap(QPixmap(file).scaled(image->width(), image->height(), Qt::KeepAspectRatio));
}

// I didn't write this 
// https://docs.opencv.org/2.4/doc/tutorials/imgproc/histograms/histogram_calculation/histogram_calculation.html
// creates the RGB historgram on the side from the main image
/*void GUI::loadRGB(Mat image) {
	if (!ROI.isNull()) {
		cv::Rect openroi(ROI.x(), ROI.y(), ROI.width(), ROI.height());
		imshow("Test", image(openroi));
		image = image (openroi);
	}

	std::vector<Mat> bgr_planes;
	split(image, bgr_planes);
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true;
	bool accumulate = false;
	Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	int bin_w = cvRound((double)ui.RGBView->width() / histSize);
	Mat histImage(ui.RGBView->height(), ui.RGBView->width(), CV_8UC3, Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), ui.RGBView->height() - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), ui.RGBView->height() - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), ui.RGBView->height() - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), ui.RGBView->height() - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), ui.RGBView->height() - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), ui.RGBView->height() - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}
	
	cvtColor(histImage, histImage, CV_BGR2RGB);
	ui.RGBView->setPixmap(QPixmap::fromImage( QImage((unsigned char*) histImage.data, histImage.cols,
						  histImage.rows, histImage.step, QImage::Format_RGB888)));

}*/



void GUI::loadMDWindow()
{
	// creates a new window for the metadata creator
	Metadata *mdWindow = new Metadata();
	mdWindow->show();
}

void GUI::changeHist(QRect roi)
{
	ROI = roi;
	QImage temp = QImage(ui.PictureFrame->pixmap()->toImage());
	if (ui.PictureFrame->pixmap()->toImage().format() == QImage::Format_RGB32)
	{
		temp = temp.convertToFormat(QImage::Format_RGB888);
	}
	temp = temp.rgbSwapped();
	//loadRGB(Mat(temp.height(), temp.width(), CV_8UC3, const_cast<uchar*>(temp.bits()), static_cast<size_t>(temp.bytesPerLine())));
}

void GUI::selection(QAction* action) {
	emit onChange (action->iconText());
}






