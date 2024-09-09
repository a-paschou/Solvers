#pragma once
#include "Solver.h"
#include <vector>
#include "Matrix.h"
#include "FactorizationType.h"
class DirectSolution : public Solver
{
private:
	FactorizationType factorizationType;
public:
	DirectSolution(FactorizationType factorizationType = FactorizationType::Cholesky);
	virtual void Solve() override;
	void ForwardSubstitution(Matrix*);
	void BackwardSubstitution(Matrix*);
	void SolveDiagonalMatrix(Matrix*);
	void Update();
};

