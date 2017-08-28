#include "stdafx.h"
#include "FileExplorer.h"


FileExplorer::FileExplorer()
{
	dir = new QDir;
}


FileExplorer::~FileExplorer()
{
	delete dir;
	dir = NULL;
}


