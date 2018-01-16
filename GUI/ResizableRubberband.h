#pragma once

#include <QRubberBand>
#include <Qt>
#include <QObject>
#include <opencv2/opencv.hpp>


class ResizableRubberband : public QWidget
{
	Q_OBJECT

	public:
		ResizableRubberband(QPoint origin, QWidget* parent = 0);
		~ResizableRubberband();

	signals:
		void deletion();

	private slots:
		void showContextMenu(const QPoint&);
	//	void deleteRubberBand();

	private:
		QRubberBand* rubberband;
		QHBoxLayout* layout;
		void resizeEvent(QResizeEvent *);
		void paintEvent(QPaintEvent * event);
		void mousePressEvent(QMouseEvent * event);
		void mouseMoveEvent(QMouseEvent * event);
};

