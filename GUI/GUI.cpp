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
	ui.PictureFrame->hide();

	//set up the processing bar
	//connect(ui.PictureProcessingBar, SIGNAL(signalProgress(int)), ui.PictureProcessingBar, SLOT(setValue(int)));
	//ui.PictureProcessingBar->hide();

	//set up the slider
	connect(ui.ImageScroller, SIGNAL(valueChanged(int)), this, SLOT(loadPictures(int)));
	ui.ImageScroller->setRange(0, 0);

	//set up the toolbar
	connect(ui.toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(selection(QAction*)));
	connect(this, SIGNAL(onChange(QString)), ui.PictureFrame, SLOT(setSelection(QString)));


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
	QSize temp = ui.PictureFrame->pixmap()->size();
	this->setFixedSize(temp.width() + 100, temp.height() + 250);

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






