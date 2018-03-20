#include "stdafx.h"
#include "ProgressBar.h"


ProgressBar::ProgressBar(int size, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.progressBar->setRange(0, size);
}


ProgressBar::~ProgressBar()
{
}

void ProgressBar::recieveUpdate(int i) {
	ui.progressBar->setValue(i);
}
