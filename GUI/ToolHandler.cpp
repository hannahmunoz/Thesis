#include "stdafx.h"
#include "ToolHandler.h"
#include "DrawHandler.h"

#include "qapplication.h"




ToolHandler::ToolHandler() {
	// set the selections to null
	currentSelection = NULL;
	previousSelection = NULL;
}

void ToolHandler::menuHandler(QListWidgetItem *current, QListWidgetItem * previous) {
	// check that something has been selected in the tool box
	if (current != NULL) {
		// change the current seletion
		currentSelection = current;
		// ROI
		if (current->text().compare("Region of Interest") == 0) {
			// Change cursor type, more logic will go here
			QApplication::setOverrideCursor(QCursor(Qt::CrossCursor));
			//boxSelection();
		}
		// Select
		else if (current->text().compare("Select") == 0) {
			// change cursor type, more logic will go here
			QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
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
{	// ROI logic, not implemented yet. 
	if (currentSelection != NULL) {
		if (currentSelection->text().compare("Region of Interest") == 0) {
			/*Rect Rec(100, 100, 200, 200);
			rectangle(ui->, Rec, Scalar(255), 1, 8, 0);*/
			//QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		}
	}
}

std::string ToolHandler::getCurrentSelection()
{
	if (currentSelection != NULL) {
		return currentSelection->text().toStdString();
	}
	else {
		return "Select";
	}
}







