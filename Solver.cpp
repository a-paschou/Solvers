#include "Solver.h"
#include "DirectSolution.h"
#include "GradientBased.h"
//Solver::Solver(std::vector<double>*, Matrix*)
//	: rhs{ rhs }, lhs{ lhs }
//{
//}

void Solver::Solve()
{
}

void Solver::ImportData(Matrix* lhs, std::vector<double>* rhs)
{
	this->lhs = lhs;
	this->rhs = rhs;
}

//void Solver::BuildSolver(SolutionType solutionType)
//{
//	this->solutionType = solutionType;
//}

//void Solver::Solve()
//{
//	switch (solutionType)
//	{
//	case SolutionType::DirectSolution:
//		DirectSolution::Solve(rhs, lhs);
//		break;
//	case SolutionType::StationaryPoint:
//		break;
//	case SolutionType::GradientBased:
//		GradientBased::Solve(rhs, lhs);
//		break;
//	default:
//		break;
//	}
//}
