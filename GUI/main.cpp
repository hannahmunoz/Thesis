#include "stdafx.h"
#include "GUI.h"
#include "FileExplorer.h"
#include <QtWidgets/QApplication>
#include <QPixmap>


int main(int argc, char *argv[])
{
	// loads the main window
	QApplication a(argc, argv);
	GUI w;
	w.show();
	//w.showFullScreen();
	return a.exec();
}
