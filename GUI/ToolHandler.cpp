#include "stdafx.h"
#include "ToolHandler.h"
#include "qapplication.h"

ToolHandler::ToolHandler() {

}

void ToolHandler::menuHandler(QListWidgetItem *current, QListWidgetItem * previous) {
	
	if (current->text().compare("Select Area") == 0) {
		QApplication::setOverrideCursor(QCursor(Qt::CrossCursor));
	}

	if (previous != NULL) {
		if (previous->text().compare("Select Area") == 0) {
			QApplication::restoreOverrideCursor();
		}
	}
}

