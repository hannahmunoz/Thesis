#pragma once
#include <memory>
#include <vector>

#include "ResizableRubberband.h"

class CPU
{
public:
	CPU(const std::vector<std::unique_ptr<ResizableRubberband> > *rbs);
	~CPU();
};

