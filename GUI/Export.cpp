#include "stdafx.h"
#include "Export.h"
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\core\cuda\common.hpp>




Export::Export(QWidget *parent)
	:  QDialog(parent)
{
	ui.setupUi(this);
	int devices = cv::cuda::getCudaEnabledDeviceCount();
	if (devices == 0) {
		ui.GPUBox->setEnabled(false);
	}
	else {
		ui.GPUBox->setMaximum(devices);
	}

	// video export
	connect(ui.videoExport, SIGNAL(stateChanged(int)), this, SLOT(videoExport(int)));
	ui.fpsBox->setEnabled(false);
}

Export::~Export()
{
}


void Export::accept()
{
	int process = -1;
	// set up radio validation
	if (ui.cpuButton->isChecked() || ui.MutliGPU->isChecked()) {
		//CPU
		if (ui.cpuButton->isChecked()) {
			process = 0;
		}
		else {
			// Single GPU
			if (ui.GPUBox->value() == 1) {
				process = 1;
			}
			// Multiple GPU
			else {

			}
		}
	}
	//QString filename = QFileDialog::getSaveFileName(this, tr("Save Results"), "/", tr("CSV Files (*.csv);; All files (*.*)"));
	QString filename = "";
	emit choice (process, ui.checkBox->isChecked(), filename);
	this->close();
}
void Export::videoExport(int state)
{
	if (state == 0) {
		ui.fpsBox->setEnabled(false);
	}
	else if (state == 2) {
		ui.fpsBox->setEnabled(true);
	}
}
