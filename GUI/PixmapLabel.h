#pragma once

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <qpainter.h>
#include <qimage.h>
#include <qpixmap.h>
#include <QLabel>

// straight from https://stackoverflow.com/questions/40167841/qt-overriding-qlabel-paintevent

class PixmapLabel : public QLabel
{
	Q_OBJECT

public:
	explicit PixmapLabel(QWidget* parent = nullptr);
	~PixmapLabel();
	void setPixmapLabel(QPixmap p);
	void paintEvent(QPaintEvent *);
	void setSelection(std::string);
	//void update();


	signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);


private:	
	QImage cachedImage;
	QPixmap pixmap;
	qint64 cacheKey { 0 };

	QPainter painter;
	QTimer timer;
	std::string current;
};

