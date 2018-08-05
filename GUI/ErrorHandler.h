#pragma once

#include <QDialog>
#include "ui_Error.h"

class ErrorHandler : public QDialog
{
	Q_OBJECT

public:
	ErrorHandler(QDialog *parent = Q_NULLPTR);
	~ErrorHandler();

	void setLabel(QString);

private:
	Ui::ErrorWindow ui;
};