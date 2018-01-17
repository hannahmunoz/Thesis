#include "stdafx.h"
#include "ResizableRubberband.h"
#include <QLabel>
#include <QWidget>
#include <QPainter>

ResizableRubberband::ResizableRubberband(QPoint origin, int num, QWidget* parent) : QWidget(parent)
{
	//setStyleSheet("selection-background-color: yellow");;
	setWindowFlags(Qt::SubWindow);
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(QMargins());	
	layout->addWidget(new QSizeGrip(this), 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(new QSizeGrip(this), 0, Qt::AlignBottom | Qt:: AlignRight);
	rubberband = new QRubberBand(QRubberBand::Rectangle, this);
	number = num;
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
		 this->setContextMenuPolicy(Qt::CustomContextMenu);
		 connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
		//emit deleteRubberBand();
	}
}

void ResizableRubberband::showContextMenu(const QPoint &pos) {
	QMenu contextMenu(tr("Context menu"), this);

	QAction action1("Delete", this);
	connect(&action1, SIGNAL(triggered()), this, SLOT(deleteLater()));
	connect(&action1, SIGNAL(triggered()), this, SLOT(remove()));

	contextMenu.addAction(&action1);

	contextMenu.exec(mapToGlobal(pos));
}

void ResizableRubberband::mouseMoveEvent(QMouseEvent* event) {

}


void ResizableRubberband::resizeEvent(QResizeEvent *) {
	rubberband->resize(size());
}

void ResizableRubberband::remove() {
	emit sendNumber(number);
}

void ResizableRubberband::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	
	if (size().width() >10 && size().height() >10)
	{
		p.drawText(15, 25, QString("%1,%2").arg(size().width()).arg(size().height()));
		QFont font = p.font();
		font.setBold(true);
		p.setFont(font);
		p.drawText(15, 15, QString ("%1").arg (number));
	}
}
