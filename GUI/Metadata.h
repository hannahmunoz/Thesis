#pragma once

#include <QWidget>
#include "ui_Metadata.h"

class Metadata : public QWidget
{
	Q_OBJECT

public:
	Metadata(QWidget *parent = Q_NULLPTR);
	~Metadata();

private:
	Ui::Metadata ui;
};