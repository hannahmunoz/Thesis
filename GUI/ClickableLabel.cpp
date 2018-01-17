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
	rubberBand = NULL;
}

ClickableLabel::~ClickableLabel() 
{
	// destructor does nothing
}

void ClickableLabel::getROI()
{
	emit returnROI(rubberBands);
}

// called when a mouse click is detected
void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	if (!current.empty()) {
		if (current.compare("Region of Interest") == 0 && event->buttons() == Qt::LeftButton) {
			origin = this->mapFromGlobal(this->mapToGlobal(event->pos()));
			if (!rubberBand) {
				rubberBand = new ResizableRubberband(event->pos(), rubberBands.size()+1, this);
				connect(rubberBand, SIGNAL(sendNumber(int)), this, SLOT(removeRubberBand(int)));
			}
		}
	}
}

void ClickableLabel::mouseMoveEvent(QMouseEvent * event)
{
	if (rubberBand) {
		rubberBand->setGeometry(QRect(origin, event->pos()).normalized());

	/*	QToolTip::showText(event->globalPos(), QString("%1,%2")
			.arg(rubberBand->size().width())
			.arg(rubberBand->size().height()), this);*/
	}
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent * event)
{
	if (rubberBand) {
		rubberBands.push_back(rubberBand);
		rubberBands.back()->show();
		rubberBand = NULL;
	}
}

// paint event for drawing the ROI to the user
//void ClickableLabel::paintEvent(QPaintEvent *event) {
//	//// currently just shows "Qt" on select area selection
//	QLabel::paintEvent(event);
//	// make sure we're working on a picture
//	if (!p.isNull()) {
//		// check that the user wants to select a ROI
//		if (!current.empty()) {
//			if (current.compare("Region of Interest") == 0) {
//				painter.begin(this);
//				painter.setPen(QPen(Qt::red, 3, Qt::DashLine));
//				painter.drawRect(0, 0, 700, 120);
//				/*painter.setFont(QFont("Arial", 30));
//				painter.drawText(rect(), Qt::AlignCenter, "Qt");*/
//				painter.end();
//				//setPixmap(p);
//			}
//			//else {
//				//painter.drawText(rect(), Qt::AlignCenter, "qT");
//			//}
//		}
//	}
//}

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



void ClickableLabel::removeRubberBand(int rb) {
	for (int i = 0; i < rubberBands.size(); i++) {
		if (rubberBands[i]->number == rb) {
			rubberBands.erase(rubberBands.begin() + i);
			for (int j = i; j < rubberBands.size(); j++) {
				rubberBands[j]->number--;
			}
			break;
		}
	}
}


