#pragma once

#include <QRubberBand>
#include <Qt>
#include <QObject>
#include <opencv2/opencv.hpp>


class ResizableRubberband : public QWidget
{
	Q_OBJECT

	public:
		ResizableRubberband(int num, QWidget* parent = 0);
		~ResizableRubberband();

	signals:
		void sendNumber(int);
		void focusReceived();
		void toParentLabel(int);

	private slots:
		void showContextMenu(const QPoint&);
		void remove();
		void changeHistogram();
	//	void deleteRubberBand();

	private:
		QRubberBand* rubberband;
		QHBoxLayout* layout;
		void resizeEvent(QResizeEvent *);
		void paintEvent(QPaintEvent * event);
		void mousePressEvent(QMouseEvent * event);
		bool eventFilter(QObject *object, QEvent *event);
	
	public:
		int number;
};

