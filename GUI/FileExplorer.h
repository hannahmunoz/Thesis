#pragma once
#include <QDir>

class FileExplorer
{
public:
	FileExplorer();
	~FileExplorer();


private:
	QDir *dir;
};

