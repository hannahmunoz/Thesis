#include "stdafx.h"
#include "ClickableLabel.h"

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
	channels = new ColorChannelViewer(this);
}

ClickableLabel::~ClickableLabel() 
{
	// destructor does nothing
}

void ClickableLabel::getROI()
{
	//emit returnROI(rubberBands);
}

void ClickableLabel::passToGUI(int num)
{
	int passNum;
	for (int i = 0; i < rubberBands.size(); i++) {
		if (rubberBands[i]->number == num) {
			emit GUIPass(rubberBands[i]->geometry());
		}
		break;
	}
	
}

/*void ClickableLabel::moveUp(int num)
{
}*/

// called when a mouse click is detected
void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	if (current.compare("Rectangle ROI") == 0 && event->buttons() == Qt::LeftButton) {
		origin = this->mapFromGlobal(this->mapToGlobal(event->pos()));
		if (!rubberBand) {
			rubberBand = std::make_unique<ResizableRubberband>(rubberBands.size() + 1, this);
		}
	}
	else if (event->buttons() == Qt::RightButton) {
		this->setContextMenuPolicy(Qt::CustomContextMenu);
		connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
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
		if (rubberBand->height() > 30 && rubberBand->width() > 30) {
			(rubberBands).push_back(std::move (rubberBand));
			rubberBands.back()->show();
		}
		else {
			rubberBand->hide();
		}
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

void ClickableLabel::showContextMenu(const QPoint &pos) {

	QMenu contextMenu(tr("Menu"), this);
	//QAction action1("Show RGB", this);
	action1.setText("Show RGB");
	action1.setCheckable(true);
	//contextMenu.addAction("Show RGB", this, SLOT (showRGB()));
	connect(&action1, SIGNAL(triggered()), this, SLOT(RGBHandler()));
	contextMenu.addAction(&action1);
	contextMenu.exec(mapToGlobal(pos));
}

void ClickableLabel::setSelection(QString c)
{
	// changes current selection to whatever c is
	current = c;
}

void ClickableLabel::RGBHandler()
{
	if (action1.isChecked()) {
		channels->displayRGB("Main Window Histogram");
	}
}

void ClickableLabel::colorWidgetDestroyed(QObject *)
{
	action1.setChecked(false);
}


void ClickableLabel::setPix(QString file)
{
	// creates and sets a pixmap image
	p = QPixmap(file);
	this->setMaximumSize(p.size());
	setPixmap(p);
	channels->init(QImage(p.toImage()));
	RGBHandler();
}

void ClickableLabel::removeRubberBand(int rb) {
	for (int i = 0; i < rubberBands.size(); i++) {
		if (rubberBands[i]->isHidden()) {
			rubberBands[i].release();
			rubberBands[i] = NULL;
			rubberBands.erase(rubberBands.begin() + i);
		}
		if (rubberBands[i]->number == rb) {
			rubberBands[i]->hide();
			rubberBands[i].release();
			rubberBands[i] = NULL;
			rubberBands.erase(rubberBands.begin() + i);
			for (int j = i; j < rubberBands.size(); j++) {
				rubberBands[j]->number--;
			}
			break;
		}
	}
}


