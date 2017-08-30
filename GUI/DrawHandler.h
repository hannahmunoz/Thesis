#pragma once

#include <QLabel>

class DrawHandler : public QLabel
{
	Q_OBJECT
	public:
		DrawHandler();
		~DrawHandler();
		void paintBox();

	private:
		QPainter *painter;
};

