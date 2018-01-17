#pragma once

#include <vector>
#include <Qt>
#include <QLabel>
#include <QWidget>
#include <qpixmap.h>
#include <qpainter.h>
#include <qcolor.h>
#include <qimage.h>
#include "ResizableRubberband.h"

// straight from https://wiki.qt.io/Clickable_QLabel

class ClickableLabel : public QLabel
{
	Q_OBJECT

	public:
		explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
		~ClickableLabel();
		//void paintEvent(QPaintEvent *);
		void setSelection(std::string);
		void setPix(QString file);

	signals:
		void clicked();
		void returnROI(std::vector<ResizableRubberband*>);


	public slots:
		void removeRubberBand(int);
		void getROI();

	protected:
		void mousePressEvent(QMouseEvent* event);
		void mouseMoveEvent(QMouseEvent* event);
		void mouseReleaseEvent(QMouseEvent* event);


	private:
		QPixmap p;
		QPainter painter;
		QTimer timer;
		QPoint origin;
		std::string current;
		ResizableRubberband* rubberBand;
		std::vector<ResizableRubberband*> rubberBands;
};

