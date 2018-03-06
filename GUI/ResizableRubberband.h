#pragma once

#include <QRubberBand>
#include <Qt>
#include <QObject>
#include <QMainWindow>

#include <opencv2/opencv.hpp>

#include "ColorChannelViewer.h"


class ResizableRubberband : public QWidget
{
	Q_OBJECT

	public:
		ResizableRubberband(int num, QPoint origin, QWidget* parent = 0);
		~ResizableRubberband();
		std::vector <int> getFilters();

	signals:
		void sendNumber(int);
		void focusReceived();
		void toParentLabel(int);

	private slots:
		void showContextMenu(const QPoint&);
		void remove();
		void changeHistogram();
		void checkFilter();
		//void RGBHandler();
		//void pix(cv::Mat);
		//void colorWidgetDestroyed(QObject * e);

	private:
		QRubberBand* rubberband;
		QHBoxLayout* layout;
		QPoint origin;
		void resizeEvent(QResizeEvent *);
		void paintEvent(QPaintEvent * event);
		void mousePressEvent(QMouseEvent * event);
		bool eventFilter(QObject *object, QEvent *event);
		bool focus;
		QAction action2;
		QAction action3;
		std::vector <int> filterType;
		//ColorChannelViewer *channels;

	public:
		int number;
};

