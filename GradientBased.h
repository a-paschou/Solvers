#pragma once
#include "Solver.h"
#include <vector>
#include "Matrix.h"
class GradientBased : public Solver
{
public:
	GradientBased();
	virtual void Solve() override;
};