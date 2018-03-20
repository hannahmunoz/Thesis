#include "stdafx.h"
#include "MultiGPU.h"


MultiGPU::MultiGPU(QStringList filenames, const std::vector< std::unique_ptr<ResizableRubberband> > *rbs, bool checked, int selection)
{
	numGPU = selection;
}


MultiGPU::~MultiGPU()
{
}
