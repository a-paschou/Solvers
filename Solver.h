#pragma once
#include <vector>
#include "Matrix.h"
#include "SolutionType.h"

class Solver
{
protected:
	std::vector<double>* rhs;
	Matrix* lhs;
	std::vector<double>* solution = new std::vector<double>();
public:
	//Solver(std::vector<double>*, Matrix*);
	//void BuildSolver(SolutionType);
	virtual void Solve();
	void ImportData(Matrix*, std::vector<double>*);
};
