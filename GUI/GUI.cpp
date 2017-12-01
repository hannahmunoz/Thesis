#include "stdafx.h"
#include "GUI.h"

#include "ClickableLabel.h"
#include <qfile.h>
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qpixmap.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
using namespace cv;


GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//set up the processing bar
	ui.PictureProcessingBar->hide();

	//set up the slider
	connect(ui.ImageScroller, SIGNAL(valueChanged(int)), this, SLOT(loadPictures(int)));
	ui.ImageScroller->setRange(0, 0);

	//set up the toolbox
	populateToolbox();
	tools = new ToolHandler();
	connect(ui.Toolbox, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), tools, SLOT(menuHandler (QListWidgetItem *, QListWidgetItem *)));

	//label events
	connect(ui.Toolbox, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT( passSelection(QListWidgetItem *)));

	//connect RGB Viewer
	connect(this, SIGNAL(imageSet(cv::Mat)), this, SLOT(loadRGB(cv::Mat)));

	//connect Process Button
	connect(ui.ProcessButton, SIGNAL(clicked()), this, SLOT(testResults()));

}

// where the hell is this call??
/*void GUI::on_action_Open_triggered()
{
	//set the parameters of the file finder
	QFileDialog filefinder;
	QStringList typeFilter;
	typeFilter << "image/jpeg" 
			   << "image/png";
	filefinder.setMimeTypeFilters(typeFilter);

	filenames = QFileDialog::getOpenFileNames(this, "Select Pictures", "C:\\");
	if (filenames.size() > 0) {
		ui.ImageScroller->setRange(0, filenames.size() - 1);
		loadPictures(0);
	}

	//otherwise do stuff witht the image
}*/

void GUI::loadPictures(int center)
{
	//load main picture
	//singleImage(ui.PictureFrame, filenames.at(center));
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
	ui.PictureFrame->setSelection(tools->getCurrentSelection());
}


void GUI::singleImage(QLabel *image, QString file) {
	image->setPixmap(QPixmap(file).scaled(image->width(), image->height(), Qt::KeepAspectRatio));
}

// I didn't write this but idk where it's from
void GUI::loadRGB(Mat image) {
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

}

void GUI::populateToolbox()
{
	new QListWidgetItem(tr("Select Area"), ui.Toolbox);
	new QListWidgetItem(tr("Test"), ui.Toolbox);
}


