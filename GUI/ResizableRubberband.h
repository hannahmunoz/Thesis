#pragma once

#include <QRubberBand>
#include <Qt>
#include <QObject>


class ResizableRubberband : public QWidget
{
	Q_OBJECT

	public:
		ResizableRubberband(QPoint origin, QWidget* parent = 0);
		~ResizableRubberband();

	signals:
		void deleteRubberBand();

	private:
		QRubberBand* rubberband;
		QHBoxLayout* layout;
		void resizeEvent(QResizeEvent *);
		void paintEvent(QPaintEvent * event);
		void mousePressEvent(QMouseEvent * event);
		void mouseMoveEvent(QMouseEvent * event);
};

