#include "stdafx.h"
#include "ClickableLabel.h"

#include "opencv2\core.hpp"
#include "opencv2\highgui.hpp"
#include "opencv2\imgproc.hpp"
using namespace cv;



ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f): QLabel(parent) 
{
	rubberBand = NULL;
	channels = new ColorChannelViewer();
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
			rubberBand = std::make_unique<ResizableRubberband>(rubberBands.size() + 1, origin, this);
			emit pixChange(matImage);
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
		channels->displayRGB("Main Window Histogram", this);
	}
	else {
		channels->windowDestroyed();
	}
}

void ClickableLabel::colorWidgetDestroyed(QObject *e)
{
	action1.setChecked(false);
	channels->windowDestroyed();
}


void ClickableLabel::setPix(QString file)
{
	// creates and sets a pixmap image
	p = QPixmap(file);
	this->setFixedSize(p.size());
	this->show();
	setPixmap(p);

	//get the matrix version for ROI handling
	matImage = imread(file.toStdString(), CV_LOAD_IMAGE_COLOR);

	//Do other stuff
	channels->init(matImage);
	emit pixChange(matImage);
	RGBHandler();
}

QPixmap ClickableLabel::getPix()
{
	return p;
}

std::vector<std::unique_ptr<ResizableRubberband>> const & ClickableLabel::getRubberbands() const
{
	return rubberBands;
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


