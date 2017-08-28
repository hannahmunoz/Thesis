#include "stdafx.h"
#include "GUI.h"
#include <qfile.h>
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qpixmap.h>

GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.PictureProcessingBar->hide();

	connect(ui.ImageScroller, SIGNAL(valueChanged(int)), this, SLOT(loadPictures(int)));

	ui.ImageScroller->setRange(0, 0);
}

void GUI::on_action_Open_triggered()
{
	//with help from http://www.qtcentre.org/threads/34226-QFileDialog-select-multiple-directories?p=220108#post220108

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

}

void GUI::loadPictures(int center)
{
	//load main picture
	singleImage(ui.PictureFrame, filenames.at(center));
	// and center
	singleImage(ui.CenterScollImage, filenames.at(center));

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


void GUI::singleImage(QLabel *image, QString file) {
	image->setPixmap(QPixmap(file).scaled(image->width(), image->height(), Qt::KeepAspectRatio));

}


