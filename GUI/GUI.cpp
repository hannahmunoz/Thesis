#include "stdafx.h"
#include "GUI.h"
#include <qfile.h>
#include <qfiledialog.h>
#include<qtextstream.h>

GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.PictureProcessingBar->hide();
}

void GUI::on_action_Open_triggered()
{
	//with help from http://www.qtcentre.org/threads/34226-QFileDialog-select-multiple-directories?p=220108#post220108

	//set the parameters of the file finder
	QFileDialog filefinder;
	filefinder.setFileMode( QFileDialog::Directory);
	filefinder.setOption(QFileDialog::DontUseNativeDialog,true);
	QStringList typeFilter;
	typeFilter << "image/jpeg" 
			   << "image/png";
	filefinder.setMimeTypeFilters(typeFilter);


	//
	//filefinder.fin
	QListView *l = filefinder.findChild<QListView*>("listView");
	if (l) {
		l->setSelectionMode(QAbstractItemView::MultiSelection);
	}

	QTreeView *t = filefinder.findChild <QTreeView*>();
	if (t) {
		t->setSelectionMode(QAbstractItemView::MultiSelection);
	}

	filefinder.exec();
	QStringList filenames = filefinder.selectedFiles();


	//otherwise do stuff witht the image

}
