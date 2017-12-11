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
	if (current != NULL) {
		currentSelection = current;
		if (current->text().compare("Region of Interest") == 0) {
			QApplication::setOverrideCursor(QCursor(Qt::CrossCursor));
		}
		else if (current->text().compare("Select") == 0) {
			QApplication::setOverrideCursor(QCursor(Qt::CrossCursor));
		}
	}

	if (previous != NULL) {
		previousSelection = previous;
		if (previous->text().compare("Region of Interest") == 0) {
			QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
		}
	}
}

void ToolHandler::boxSelection()
{
	if (currentSelection != NULL) {
		if (currentSelection->text().compare("Region of Interest") == 0) {

			//QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		}
	}
}

std::string ToolHandler::getCurrentSelection()
{
	return currentSelection->text().toStdString();
}







