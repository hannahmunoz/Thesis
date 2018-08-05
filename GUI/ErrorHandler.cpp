#include "stdafx.h"
#include "ErrorHandler.h"


ErrorHandler::ErrorHandler(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}


ErrorHandler::~ErrorHandler()
{
}

void ErrorHandler::setLabel(QString errorMsg)
{
	ui.ErrorText->setText(errorMsg);
}
