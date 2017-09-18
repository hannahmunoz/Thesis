#include "stdafx.h"
#include "PixmapLabel.h"
#include "ToolHandler.h"
#include <qpainter.h>
#include <qimage.h>
#include <qpixmap.h>
#include <QLabel>


PixmapLabel::PixmapLabel(QWidget* parent) : QLabel(parent)
{
	connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
	timer.start(200);
}

PixmapLabel::~PixmapLabel()
{
	
}

void PixmapLabel::setPixmapLabel(QPixmap p)
{
	pixmap = p;
	setPixmap(p);
	show();
}

void PixmapLabel::mousePressEvent(QMouseEvent* event) {
	emit clicked();
}

void PixmapLabel::paintEvent(QPaintEvent *event) {
	//if this is assigned to a pixmap
	/*if (pixmap() && !pixmap()->isNull()) {
		QStyle* style = PixmapLabel::style();
		QPainter painter(this);
		drawFrame(&painter);
		QRect cr = contentsRect();
		cr.adjust(margin(), margin(), -margin(), -margin());
		int align = QStyle::visualAlignment(layoutDirection(), alignment());
		QPixmap pix;
		if (hasScaledContents()) { //if scaling is enabled
			QSize scaledSize = cr.size() * devicePixelRatioF();
			//if scaledPixmap is invalid
			if (scaledPixmap.isNull() || scaledPixmap.size() != scaledSize
				|| pixmap()->cacheKey() != cacheKey) {
				//if cachedImage is also invalid
				if (pixmap()->cacheKey() != cacheKey) {
					//reconstruct cachedImage
					cachedImage = pixmap()->toImage();
				}
				QImage scaledImage = cachedImage.scaled(
					scaledSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
				scaledPixmap = QPixmap::fromImage(scaledImage);
				scaledPixmap.setDevicePixelRatio(devicePixelRatioF());
			}
			pix = scaledPixmap;
		}
		else { // no scaling, Just use pixmap()
			pix = *pixmap();
		}
		QStyleOption opt;
		opt.initFrom(this);
		if (!isEnabled())
			pix = style->generatedIconPixmap(QIcon::Disabled, pix, &opt);
		style->drawItemPixmap(&painter, cr, align, pix);
	}
	else { //otherwise (if the label is not assigned to a pixmap)
		   //call base paintEvent
		QLabel::paintEvent(event);
	}*/
	if (!current.empty()) {
		if (current.compare("Select Area") == 0) {
			painter.begin(this);
			painter.setPen(Qt::blue);
			painter.setFont(QFont("Arial", 30));
			painter.drawText(rect(), Qt::AlignCenter, "Qt");
			painter.end();

		}
		//else {
		//painter.drawText(rect(), Qt::AlignCenter, "qT");
		//}
	}
}

void PixmapLabel::setSelection(std::string c)
{
	current = c;
}

QPixmap generatePixmap(QSize size) {
	QPixmap pixmap(size);
	pixmap.fill(Qt::white);
	QPainter p(&pixmap);
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(QPen(Qt::black, 10));
	p.drawEllipse(pixmap.rect());
	p.setPen(QPen(Qt::red, 2));
	p.drawLine(pixmap.rect().topLeft(), pixmap.rect().bottomRight());
	p.drawLine(pixmap.rect().topRight(), pixmap.rect().bottomLeft());
	return pixmap;
}


