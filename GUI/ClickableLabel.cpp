#include "stdafx.h"
#include "ClickableLabel.h"
#include "ToolHandler.h"


ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f): QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	emit clicked();
}

void ClickableLabel::paintEvent(QPaintEvent *) {
	if (!current.empty()){
		if (current.compare("Select Area") == 0) {
			painter.begin(this);
			painter.setPen(Qt::blue);
			painter.setFont(QFont("Arial", 30));
			painter.drawText(rect(), Qt::AlignCenter, "Qt");
			painter.end();
		}
		else {
			//painter.drawText(rect(), Qt::AlignCenter, "qT");
		}
	}
}

void ClickableLabel::setSelection(std::string c)
{
	current = c;
};


