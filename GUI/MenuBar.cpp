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

	filenames = QFileDialog::getOpenFileNames(this, "Select Pictures", "C:\\");
	if (filenames.size() > 0) {
		ui.ImageScroller->setRange(0, filenames.size() - 1);
		loadPictures(0);

	}

	//otherwise do stuff witht the image
}

void GUI::on_action_Edit_triggered()
{


}