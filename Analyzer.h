#pragma once
#include "Solver.h"
#include "Model.h"

class Analyzer
{
private:
	Solver* solver;
	Model* model;
public:
	Analyzer(Model*, Solver*);
	virtual void Solve();
	void ChangeSolver(Solver*);
};

