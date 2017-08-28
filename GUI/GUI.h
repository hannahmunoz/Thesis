#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);

	private slots:
		//menu bar funtions
		void on_action_Open_triggered();

private:
	Ui::GUIClass ui;
	QString filepath;
};
