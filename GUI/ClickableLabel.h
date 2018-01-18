#pragma once
#include <memory>
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
		void setPix(QString file);

	signals:
		void clicked();
		void returnROI(std::vector<ResizableRubberband*>);
		void GUIPass(QRect);

	public slots:
		void removeRubberBand(int);
		void getROI();
		//void moveUp(int);
		void passToGUI(int);
		void setSelection(QString);


	protected:
		void mousePressEvent(QMouseEvent* event);
		void mouseMoveEvent(QMouseEvent* event);
		void mouseReleaseEvent(QMouseEvent* event);


	private:
		QPixmap p;
		QPainter painter;
		QTimer timer;
		QPoint origin;
		QString current;
		std::unique_ptr<ResizableRubberband> rubberBand;
		std::vector <std::unique_ptr<ResizableRubberband>> rubberBands;
};

