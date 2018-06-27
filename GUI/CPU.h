#pragma once
#include <memory>
#include <vector>

#include "opencv2/opencv.hpp"
#include "opencv2\core\cuda\common.hpp"

#include "ResizableRubberband.h"
#include <QObject>

class CPU : public QObject
{
	Q_OBJECT

public:
	CPU(QStringList, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, QString, bool, bool, int);
	~CPU();

signals:
	void progress(int);

private:
	float snowFilterDebug(cv::Mat&);
	float cloudFilterDebug(cv::Mat&);
	void printResults(double time, QString saveName, size_t Size);

	std::vector <std::vector <float> > results;
	bool debug;
};