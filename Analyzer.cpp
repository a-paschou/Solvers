#include "Analyzer.h"
#include "DirectSolution.h"
#include <iostream>

Analyzer::Analyzer(Model* model, Solver* solver)
	: model {model}, solver{ solver }
{
}

void Analyzer::Solve()
{
	solver->ImportData(model->GetLeftHandSide(), model->GetRightHandSide());
	solver->Solve();
}

void Analyzer::ChangeSolver(Solver* newSolver)
{
	this->solver = newSolver;
}
