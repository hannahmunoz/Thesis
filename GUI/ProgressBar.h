#pragma once

#include <QDialog>
#include "ui_progress.h"

class ProgressBar : public QDialog
{
	Q_OBJECT
	public:
		ProgressBar (int size, QWidget *parent = Q_NULLPTR);
		~ProgressBar();

	public slots:
		void recieveUpdate(int);
		
	private:
		Ui::Progress ui;
};

