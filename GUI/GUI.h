#pragma once

#include <QtWidgets/QMainWindow>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

#include "ui_GUI.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public: 
	GUI(QWidget *parent = Q_NULLPTR);
	
	void singleImage (QLabel *image, QString file);
	void threadExport();
	private slots:
		//menu bar funtions
		void on_action_Open_triggered();
		void on_action_Edit_triggered();
		void loadPictures(int center);
		void passSelection(QListWidgetItem *);
		void testResults(std::vector<ResizableRubberband*>);
		void exportData();
		void loadMDWindow();
		void loadExportWindow(QAction *);
		void changeHist(QRect);
		void selection(QAction* action);
		void processSelection(int);

	signals:
		void imageSet(cv::Mat image);
		void onChange(QString);

	private:
		Ui::GUIClass ui;
		QString filepath;
		QStringList filenames;
		QRect ROI;
};

//Q_DECLARE_METATYPE(Mat)


