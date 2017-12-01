#include "stdafx.h"
#include "ClickableLabel.h"
#include "ToolHandler.h"


ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f): QLabel(parent) 
{
	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(200);
}

ClickableLabel::~ClickableLabel() 
{
	
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton)
		dragStartPosition = event->pos();
	emit clicked();
}

void ClickableLabel::mouseMoveEvent(QMouseEvent * event)
{
	// check that we're still dragging
	/*if (!(event->buttons() & qt::leftbutton))
		return;
	if ((event->pos() - dragstartposition).manhattanlength () < qapplication::startdragdistance())
		return;*/
	QDrag *drag = new QDrag(this);
	drag->pixmap();

}

void ClickableLabel::paintEvent(QPaintEvent *event) {
	QLabel::paintEvent(event);
	if (!p.isNull()) {
		if (!current.empty()) {
			if (current.compare("Select Area") == 0) {
				painter.begin(this);
				painter.setPen(Qt::blue);
				painter.setFont(QFont("Arial", 30));
				painter.drawText(rect(), Qt::AlignCenter, "Qt");
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
	current = c;
}

void ClickableLabel::setPix(QString file)
{
	p = QPixmap(file);
	setPixmap(p);
}


