#pragma once

#include <Qt>
#include <QLabel>
#include <QWidget>
#include <qpixmap.h>
#include <qpainter.h>
#include <qcolor.h>
#include <qimage.h>

// straight from https://wiki.qt.io/Clickable_QLabel

class ClickableLabel : public QLabel
{
	Q_OBJECT

public:
	explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ClickableLabel();
	void paintEvent(QPaintEvent *);
	void setSelection(std::string);
	void setPix(QString file);

	signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);


private:
	QPixmap p;
	QPainter painter;
	QTimer timer;
	std::string current;
};

