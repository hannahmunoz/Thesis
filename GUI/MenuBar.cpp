#include "stdafx.h"
#include "GUI.h"
void GUI::on_action_Open_triggered()
{
	//set the parameters of the file finder
	QFileDialog filefinder;
	QStringList typeFilter;
	typeFilter << "image/jpeg"
		<< "image/png";
	filefinder.setMimeTypeFilters(typeFilter);

	// opens file handler
	filenames = QFileDialog::getOpenFileNames(this, "Select Pictures", "C:\\");

	// checks that images were selected
	if (filenames.size() > 0) {
		// adjusts the scroller
		ui.ImageScroller->setRange(0, filenames.size() - 1);
		//loads the picture
		loadPictures(0);
	}

	//otherwise do stuff with the image
}

void GUI::on_action_Edit_triggered()
{


}