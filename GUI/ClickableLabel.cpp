#include "stdafx.h"
#include "ClickableLabel.h"
#include "ToolHandler.h"

#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
using namespace cv;



ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f): QLabel(parent) 
{
	// start the timer
	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	// label checks for clicks ever 200 msec
	timer.start(200);
}

ClickableLabel::~ClickableLabel() 
{
	// destructor does nothing
}

// called when a mouse click is detected
void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	// unimplmented
	// eventually for when ROI are working
	/*if (event->button() == Qt::LeftButton)
		dragStartPosition = event->pos();
	emit clicked();*/
	/*Rect Rec(0, 0, 700, 150);
	// https://asmaloney.com/2013/11/code/converting-between-cvmat-and-qimage-or-qpixmap/
	QImage swapped = p.toImage();
	if (swapped.format() == QImage::Format_RGB32)
	{
		swapped = swapped.convertToFormat(QImage::Format_RGB888);
	}

	swapped = swapped.rgbSwapped();

	Mat temp (swapped.height(), swapped.width(), CV_8UC3, const_cast <uchar*>(swapped.bits()), static_cast<size_t>(swapped.bytesPerLine()));

	rectangle(temp, Rec, Scalar(255), 1, 8, 0);
	QImage image(temp.data, temp.cols, temp.rows, static_cast<int>(temp.step),QImage::Format_RGB888);*/
	//p.fromImage(image);
}

void ClickableLabel::mouseMoveEvent(QMouseEvent * event)
{
	// check that we're still dragging
	/*if (!(event->buttons() & qt::leftbutton))
		return;
	if ((event->pos() - dragstartposition).manhattanlength () < qapplication::startdragdistance())
		return;*/
	// for when ROI work
	QDrag *drag = new QDrag(this);
	drag->pixmap();

}

// paint event for drawing the ROI to the user
void ClickableLabel::paintEvent(QPaintEvent *event) {
	// currently just shows "Qt" on select area selection
	QLabel::paintEvent(event);
	// make sure we're working on a picture
	if (!p.isNull()) {
		// check that the user wants to select a ROI
		if (!current.empty()) {
			if (current.compare("Region of Interest") == 0) {
				painter.begin(this);
				painter.setPen(Qt::blue);
				painter.drawRect(0, 0, 700, 120);
				/*painter.setFont(QFont("Arial", 30));
				painter.drawText(rect(), Qt::AlignCenter, "Qt");*/
				painter.end();
				//setPixmap(p);
			}
			//else {
				//painter.drawText(rect(), Qt::AlignCenter, "qT");
			//}
		}
	}
}

void ClickableLabel::setSelection(std::string c)
{
	// changes current selection to whatever c is
	current = c;
}

void ClickableLabel::setPix(QString file)
{
	// creates and sets a pixmap image
	p = QPixmap(file);
	setPixmap(p);
}


