#pragma once

#include <QDialog>
#include "ui_Export.h"

class Export : public QDialog
{
	Q_OBJECT

public:
	Export( QWidget *parent = Q_NULLPTR);
	~Export();

	public slots:
		void accept();
		void videoExport(int);
	
	signals:
		void choice(int, bool, QString, bool, int);

private:
	Ui::Export ui;
};
