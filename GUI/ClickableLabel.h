#pragma once

#include <QLabel>
#include <QWidget>
#include <Qt>

// straight from https://wiki.qt.io/Clickable_QLabel

class ClickableLabel : public QLabel
{
	Q_OBJECT

public:
	explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ClickableLabel();
	void paintEvent(QPaintEvent *);
	void setSelection(std::string);

	signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);


private:	
	QPainter painter;
	QTimer timer;
	std::string current;
};

