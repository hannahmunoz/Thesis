#pragma once
#include <QObject>

class ToolHandler : public QObject
{
	Q_OBJECT

	public:
	ToolHandler();

	public slots:
		void menuHandler(QListWidgetItem *current, QListWidgetItem * previous);
		void boxSelection();

private:
	QListWidgetItem *currentSelection;
	QListWidgetItem *previousSelection;

};

