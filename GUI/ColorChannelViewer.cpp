#include "stdafx.h"



#include "ColorChannelViewer.h"
#include "ui_histogramViewer.h"


ColorChannelViewer::ColorChannelViewer(QWidget* parent) : QWidget(parent)
{

	rgbWindow = NULL;
	connect(rgbWindow, SIGNAL(destroyed(QObject*)), parent, SLOT(colorWidgetDestroyed(QObject*)));
}

ColorChannelViewer::~ColorChannelViewer()
{
}

void ColorChannelViewer::init(QImage img)
{
	if (img.format() == QImage::Format_RGB32)
	{
		img = img.convertToFormat(QImage::Format_RGB888);
	}
	img = img.rgbSwapped();
	cv::Mat image(img.height(), img.width(), CV_8UC3, const_cast<uchar*>(img.bits()), static_cast<size_t>(img.bytesPerLine()));

	split(image, bgr_planes);

	cv::Mat YCbCr;
	cv::cvtColor(image, YCbCr, cv::COLOR_BGR2YCrCb);
	split(YCbCr, YCbCr_planes);

	cv::Mat LAB;
	cv::cvtColor(image, LAB, cv::COLOR_BGR2Lab);
	split(LAB, LAB_planes);

	cv::Mat HSV;
	cv::cvtColor(image, HSV, cv::COLOR_BGR2HSV );
	split(HSV, HSV_planes);
}


// I didn't write this 
// https://docs.opencv.org/2.4/doc/tutorials/imgproc/histograms/histogram_calculation/histogram_calculation.html
// creates the RGB historgram on the side from the main image
void ColorChannelViewer::displayRGB(QString title)
{
	int width = 300;
	int height = 300;
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true;
	bool accumulate = false;
	cv::Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	int bin_w = cvRound((double)500 / histSize);
	cv::Mat histImage(width, height, CV_8UC3, cv::Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, cv::Point(bin_w*(i - 1), height - cvRound(b_hist.at<float>(i - 1))),
			cv::Point(bin_w*(i), height - cvRound(b_hist.at<float>(i))),
			cv::Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, cv::Point(bin_w*(i - 1), height - cvRound(g_hist.at<float>(i - 1))),
			cv::Point(bin_w*(i), height - cvRound(g_hist.at<float>(i))),
			cv::Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, cv::Point(bin_w*(i - 1), height - cvRound(r_hist.at<float>(i - 1))),
			cv::Point(bin_w*(i), height - cvRound(r_hist.at<float>(i))),
			cv::Scalar(0, 0, 255), 2, 8, 0);
	}

	cvtColor(histImage, histImage, CV_BGR2RGB);

	if (rgbWindow== NULL) {
		rgbWindow = new QWidget;
		ui.setupUi(rgbWindow);
		rgbWindow->setAttribute(Qt::WA_DeleteOnClose);
		rgbWindow->show();
	}
	rgbWindow->setWindowTitle(title);
	ui.histogram->setPixmap(QPixmap::fromImage(QImage((unsigned char*)histImage.data, histImage.cols, histImage.rows, QImage::Format_RGB888)));
}
