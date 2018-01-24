#include "stdafx.h"
#include "ResizableRubberband.h"
#include <QLabel>
#include <QWidget>
#include <QPainter>

ResizableRubberband::ResizableRubberband( int num, QWidget* parent) : QWidget(parent)
{
	//setStyleSheet("selection-background-color: yellow");;
	setWindowFlags(Qt::SubWindow);
	layout = new QHBoxLayout(this);
	layout->setContentsMargins(QMargins());	
	layout->addWidget(new QSizeGrip(this), 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(new QSizeGrip(this), 0, Qt::AlignBottom | Qt:: AlignRight);
	number = num;

	rubberband = new QRubberBand(QRubberBand::Rectangle, this);
	QGraphicsColorizeEffect *e = new QGraphicsColorizeEffect(rubberband);
	e->setColor(QColor("white"));
	rubberband->setGraphicsEffect(e);
	rubberband->setFocusPolicy(Qt::ClickFocus);
	//connect(this, SIGNAL(focusReceived()), this, SLOT(changeHistogram()));
	connect(this, SIGNAL(sendNumber(int)), parent, SLOT(removeRubberBand(int)));
	connect(this, SIGNAL(toParentLabel(int)), parent, SLOT(passToGUI(int)));

	rubberband->show();
	setLayout(layout);
	show();
	rubberband->installEventFilter(this);
	focus = false;
}


ResizableRubberband::~ResizableRubberband()
{

}


void ResizableRubberband::mousePressEvent(QMouseEvent* event) {
	
	if (event->buttons() == Qt::RightButton || event->buttons() == Qt::LeftButton) {
		rubberband->setFocus();
	}
	 if (event->buttons() == Qt::RightButton) {
		 this->setContextMenuPolicy(Qt::CustomContextMenu);
		 connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showContextMenu(const QPoint &)));
	}

}

void ResizableRubberband::showContextMenu(const QPoint &pos) {

	QMenu contextMenu(tr("Menu"), this);
	QAction action1("Delete", this);
	QAction action2("Show RGB", this);
	//QAction action2("Move Up", this);
	//QAction action3("Move Down", this);

	//connect(&action1, SIGNAL(triggered()), this, SLOT(deleteLater()));
	connect(&action1, SIGNAL(triggered()), this, SLOT(remove()));
	//connect(&action2, SIGNAL(triggered()), this->parent(), SLOT(moveUp(int)));

	contextMenu.addAction(&action1);
//	contextMenu.addSeparator();
	//contextMenu.addAction(&action2);
	//contextMenu.addAction(&action3);
	//contextMenu.addSeparator();

	contextMenu.exec(mapToGlobal(pos));
}

bool ResizableRubberband::eventFilter(QObject * object, QEvent * event)
{
	if (event->type() == event->FocusIn) {
		QGraphicsColorizeEffect *e = new QGraphicsColorizeEffect(rubberband);
		e->setColor(QColor("red"));
		rubberband->setGraphicsEffect(e);
		emit focusReceived();
		focus = true;
		return true;
	}
	 if (event->type() == QEvent::KeyPress && focus) {
		QKeyEvent* key = static_cast<QKeyEvent*>(event);
		if (key->key() == Qt::Key_Backspace || key->key() == Qt::Key_Delete) {
			remove();
		}
	}
	QFocusEvent *fevent = dynamic_cast <QFocusEvent *> (event);
	 if ( event->type() == event->FocusOut && fevent->reason() != QFocusEvent::ContextMenu ){
		QGraphicsColorizeEffect *e = new QGraphicsColorizeEffect(rubberband);
		e->setColor(QColor("white"));
		rubberband->setGraphicsEffect(e);
		focus = false;
		return true;	
	}
	return false;
}

void ResizableRubberband::resizeEvent(QResizeEvent *) {
	rubberband->resize(size());
}

void ResizableRubberband::remove() {
	emit sendNumber(number);
}

void ResizableRubberband::changeHistogram()
{
	emit toParentLabel(number);
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
