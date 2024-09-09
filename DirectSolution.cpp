#include "DirectSolution.h"
#include <iostream>
#include "ISolver.h"
#include "FactorizationFactory.h"

DirectSolution::DirectSolution(FactorizationType factorizationType)
	: factorizationType{ factorizationType }
{
}

void DirectSolution::Solve()
{
	solution = new std::vector<double>(rhs->size(), 0);
	FactorizationFactory* factory;
	switch (factorizationType)
	{
	case FactorizationType::LU:
		factory = new FactorizationFactory(lhs, FactorizationType::LU);
		ForwardSubstitution(factory->matrices->at(0));
		Update();
		BackwardSubstitution(factory->matrices->at(1));
		break;
	case FactorizationType::LDU:
		factory = new FactorizationFactory(lhs, FactorizationType::LDU);
		ForwardSubstitution(factory->matrices->at(0));
		Update();
		SolveDiagonalMatrix(factory->matrices->at(1));
		Update();
		BackwardSubstitution(factory->matrices->at(2));
		break;
	case FactorizationType::Cholesky:
		factory = new FactorizationFactory(lhs, FactorizationType::Cholesky);
		ForwardSubstitution(factory->matrices->at(0));
		Update();
		BackwardSubstitution(factory->matrices->at(0)->Transpose());
		break;
	case FactorizationType::LDL:
		factory = new FactorizationFactory(lhs, FactorizationType::LDL);
		ForwardSubstitution(factory->matrices->at(0));
		Update();
		SolveDiagonalMatrix(factory->matrices->at(1));
		Update();
		BackwardSubstitution(factory->matrices->at(0)->Transpose());
		break;
	default:
		break;
		delete factory;
	}
}

void DirectSolution::ForwardSubstitution(Matrix* lhs)
{
	int* dimensions = lhs->GetMatrixDimensions();
	for (size_t i = 0; i < solution->size(); i++)
	{
		double sum{ 0 };
		for (size_t j = 0; j < i; j++)
		{
			sum += lhs->FindValue(i, j) * solution->at(j);
		}
		double value{ (rhs->at(i) - sum) / lhs->FindValue(i,i) };
		solution->at(i) = value;
	}
}

void DirectSolution::BackwardSubstitution(Matrix* lhs)
{
	int* dimensions = lhs->GetMatrixDimensions();
	for (int i = (solution->size() - 1); i >= 0; i--)
	{
		double sum{ 0 };
		for (size_t j = (i + 1); j < dimensions[1]; j++)
		{
			sum += lhs->FindValue(i, j) * solution->at(j);
		}
		double value{ (rhs->at(i) - sum) / lhs->FindValue(i,i) };
		solution->at(i) = value;
	}
}

void DirectSolution::SolveDiagonalMatrix(Matrix* lhs)
{
	int* dimensions = lhs->GetMatrixDimensions();
	for (size_t i = 0; i < solution->size(); i++)
	{
		double value{ rhs->at(i) / lhs->FindValue(i,i) };
		solution->at(i) = value;
	}
}

void DirectSolution::Update()
{
	rhs = solution;
	solution = new std::vector<double>(rhs->size(), 0);
}
