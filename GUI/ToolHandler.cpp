#include "stdafx.h"
#include "ToolHandler.h"
#include "DrawHandler.h"
#include "qapplication.h"
#include "opencv2\core.hpp"

ToolHandler::ToolHandler() {
	currentSelection = NULL;
	previousSelection = NULL;
}

void ToolHandler::menuHandler(QListWidgetItem *current, QListWidgetItem * previous) {
	currentSelection = current;
	if (current->text().compare("Select Area") == 0) {
		QApplication::setOverrideCursor(QCursor(Qt::CrossCursor));
	}

	if (previous != NULL) {
		previousSelection = previous;
		if (previous->text().compare("Select Area") == 0) {
			QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
		}
	}
}

void ToolHandler::boxSelection()
{
	if (currentSelection != NULL) {
		if (currentSelection->text().compare("Select Area") == 0) {

			//QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		}
	}
}

std::string ToolHandler::getCurrentSelection()
{
	return currentSelection->text().toStdString();
}







