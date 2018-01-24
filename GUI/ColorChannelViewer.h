#pragma once
#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
#include <Qt>
#include <QLabel>
#include <QWidget>
#include <qpixmap.h>
#include <qimage.h>

#include "ui_histogramViewer.h"

class ColorChannelViewer :public QWidget
{
	public:
		ColorChannelViewer(QWidget* parent);
		~ColorChannelViewer();

		void init(QImage img);
		void displayRGB(QString title);


	private:
		std::vector<cv::Mat> bgr_planes;
		std::vector<cv::Mat> YCbCr_planes;
		std::vector<cv::Mat> LAB_planes;
		std::vector<cv::Mat> HSV_planes;

		QWidget *rgbWindow;
		Ui::HistogramViewer ui;
		QString title;
};

