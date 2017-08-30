#pragma once
#include <QObject>
#include "DrawHandler.h"

class ToolHandler : public QObject
{
	Q_OBJECT

	public:
	ToolHandler();

	public slots:
		void menuHandler(QListWidgetItem *current, QListWidgetItem * previous);
		void boxSelection();
		std::string getCurrentSelection();

	private:
		QListWidgetItem *currentSelection;
		QListWidgetItem *previousSelection;

};

