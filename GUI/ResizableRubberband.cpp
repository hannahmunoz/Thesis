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

void ResizableRubberband::setOrigin(QPoint o)
{
	origin = o;
}

QPoint ResizableRubberband::getOrigin()
{
	return origin;
}


void ResizableRubberband::mousePressEvent(QMouseEvent* event) {
	 if (event->buttons() == Qt::RightButton) {
		 this->setContextMenuPolicy(Qt::CustomContextMenu);
		 connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
		//emit deleteRubberBand();
	}
}

void ResizableRubberband::showContextMenu(const QPoint &pos) {
	QMenu contextMenu(tr("Context menu"), this);

	QAction action1("Delete", this);
	connect(&action1, SIGNAL(triggered()), this, SLOT(deleteLater()));
	contextMenu.addAction(&action1);

	contextMenu.exec(mapToGlobal(pos));
}

/*void ResizableRubberband::deleteRubberBand() {
	emit deletion();
}*/


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
