#include "stdafx.h"
#include "ResizableRubberband.h"
#include <QLabel>
#include <QWidget>
#include <QPainter>

ResizableRubberband::ResizableRubberband(QPoint origin, QWidget* parent) : QWidget(parent)
{
	//setStyleSheet("selection-background-color: yellow");;
	setWindowFlags(Qt::SubWindow);
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(QMargins());	
	layout->addWidget(new QSizeGrip(this), 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(new QSizeGrip(this), 0, Qt::AlignBottom | Qt:: AlignRight);
	rubberband = new QRubberBand(QRubberBand::Rectangle, this);

	//rubberband->setGeometry(QRect(origin, QSize()));
	rubberband->show();
	setLayout(layout);
	show();
}


ResizableRubberband::~ResizableRubberband()
{	
}

void ResizableRubberband::mousePressEvent(QMouseEvent* event) {
	 if (event->buttons() == Qt::RightButton) {
		 emit deleteRubberBand();
	}
}

void ResizableRubberband::mouseMoveEvent(QMouseEvent* event) {

}


void ResizableRubberband::resizeEvent(QResizeEvent *) {
	rubberband->resize(size());
}

void ResizableRubberband::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.setPen(QPen(Qt::black, 2));
	if (size().width() >10 && size().height() >10)
	{
		p.drawText(20, 20, QString("%1,%2").arg(size().width()).arg(size().height()));
	}
}
