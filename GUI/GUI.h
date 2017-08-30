#pragma once

#include <QtWidgets/QMainWindow>
#include "ToolHandler.h"
#include "ui_GUI.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);
	
	void singleImage (QLabel *image, QString file);
	void populateToolbox();

	private slots:
		//menu bar funtions
		void on_action_Open_triggered();
		void loadPictures(int center);
		void passSelection(QListWidgetItem *);


private:
	Ui::GUIClass ui;
	ToolHandler* tools;
	QString filepath;
	QStringList filenames;
};
