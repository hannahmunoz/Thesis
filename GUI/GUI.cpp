#include "stdafx.h"
#include "GUI.h"

#include "ClickableLabel.h"
#include <qfile.h>
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qpixmap.h>
#include <Metadata.h>
#include <Export.h>
#include <CPU.h>
#include <SingleGPU.h>
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

	//set up the slider
	connect(ui.ImageScroller, SIGNAL(valueChanged(int)), this, SLOT(loadPictures(int)));
	ui.ImageScroller->setRange(0, 0);

	//set up the toolbar
	connect(ui.toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(selection(QAction*)));
	connect(this, SIGNAL(onChange(QString)), ui.PictureFrame, SLOT(setSelection(QString)));

	//connect edit
	connect(ui.menuEdit, SIGNAL(triggered(QAction *)), this, SLOT(loadMDWindow()));
	connect(ui.menuExport, SIGNAL(triggered(QAction *)), this, SLOT(loadExportWindow(QAction *)));

	connect(ui.PictureFrame, SIGNAL(GUIPass(QRect)), this, SLOT(changeHist(QRect)));
}

void GUI::loadPictures(int center)
{
	ui.WelcomeLabel->setHidden(true);
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

void GUI::loadExportWindow(QAction *t)
{
	Export *exwindow = new Export();
	connect(exwindow, SIGNAL(choice(int, bool, QString, bool, int)), this, SLOT(processSelection(int, bool, QString, bool, int)));
	//exwindow->show();
	exwindow->exec();
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

void GUI::processSelection(int selection, bool checked, QString saveName, bool fpsChecked, int fpsValue)
{
	const std::vector<std::unique_ptr<ResizableRubberband> > *rbs = &(ui.PictureFrame->getRubberbands());
	if (rbs->size() > 0 && !saveName.isEmpty()) {
		if (selection == 0) {
			CPU *process = new CPU(filenames, rbs, saveName, checked, fpsChecked, fpsValue);
		}
		else {
			//if (numGPU == 1) {
				SingleGPU *process = new SingleGPU(filenames, rbs, saveName, checked, fpsChecked, fpsValue);
			//}
			//else {
				//MultiGPU *process = new MultiGPU (filenames, rbs, saveName, checked, fpsChecked, fpsValue);
			//}
		}

	}
}






