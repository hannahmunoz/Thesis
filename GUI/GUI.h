#pragma once

#include <QtWidgets/QMainWindow>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

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
		void on_action_Edit_triggered();
		void loadPictures(int center);
		void passSelection(QListWidgetItem *);
		void loadRGB(cv::Mat image);
		void testResults();

	signals:
		void imageSet(cv::Mat image);


	private:
		Ui::GUIClass ui;
		ToolHandler* tools;
		QString filepath;
		QStringList filenames;
};

//Q_DECLARE_METATYPE(Mat)


