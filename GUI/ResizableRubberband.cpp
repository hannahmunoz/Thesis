#include "stdafx.h"
#include "ResizableRubberband.h"
#include <QLabel>
#include <QWidget>
#include <QPainter>

ResizableRubberband::ResizableRubberband(int num, QPoint o, QWidget* parent) : QWidget(parent)
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
	//connect(parent, SIGNAL(pixChange(cv::Mat)), this, SLOT(pix(cv::Mat)));

	rubberband->show();
	setLayout(layout);
	show();
	rubberband->installEventFilter(this);
	focus = false;
	//channels = new ColorChannelViewer();
	origin = o;
}


ResizableRubberband::~ResizableRubberband()
{
	 
}

std::vector<int> ResizableRubberband::getFilters()
{
	return filterType;
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
	//action2.setText("Show RGB");
	//action2.setCheckable(true);
	action2.setText("Cloud Detection");
	action2.setCheckable(true);
	action3.setText("Snow Detection");
	action3.setCheckable(true);

	//connect(&action1, SIGNAL(triggered()), this, SLOT(deleteLater()));
	connect(&action1, SIGNAL(triggered()), this, SLOT(remove()));
	//connect(&action2, SIGNAL(triggered()), this, SLOT(RGBHandler()));
	//contextMenu.addAction(&action2);
	contextMenu.addAction(&action1);
	contextMenu.addSeparator();
	contextMenu.addAction(&action2);
	contextMenu.addAction(&action3);
	connect(&action2, SIGNAL(triggered()), this, SLOT(checkFilter()));
	connect(&action3, SIGNAL(triggered()), this, SLOT(checkFilter()));

	//contextMenu.addSeparator();

	contextMenu.exec(mapToGlobal(pos));
}

/*void ResizableRubberband::RGBHandler()
{
	if (action2.isChecked()) {
		channels->displayRGB("ROI " + QString(number) + " Histogram", this);
	}
	else {
		channels->windowDestroyed();
	}
}

void ResizableRubberband::pix(cv::Mat img)
{
	channels->init(img(cv::Rect(origin.x(), origin.y(), rubberband->geometry().width(), rubberband->geometry().height())));
}

void ResizableRubberband::colorWidgetDestroyed(QObject *e)
{
	action2.setChecked(false);
	channels->windowDestroyed();
}*/

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

void ResizableRubberband::checkFilter()
{
	if (action2.isChecked() && std::find(filterType.begin(), filterType.end(), 0) == filterType.end()) {
		filterType.push_back(0);
	}
	else if (!action2.isChecked() && std::find(filterType.begin(), filterType.end(), 0) != filterType.end()) {
		filterType.erase(std::remove(filterType.begin(), filterType.end(), 0), filterType.end());
	}
	if (action3.isChecked() && std::find(filterType.begin(), filterType.end(), 1) == filterType.end()) {
		filterType.push_back(1);
	}
	else if (!action3.isChecked() && std::find(filterType.begin(), filterType.end(), 1) != filterType.end()) {
		filterType.erase(std::remove(filterType.begin(), filterType.end(), 1), filterType.end());
	}

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
