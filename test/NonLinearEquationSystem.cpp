#include "test/NonLinearEquationSystem.hpp"

NonLinearEquationSystem::NonLinearEquationSystem() : EquationSystem(2)
{
}

double NonLinearEquationSystem::getValue(const int i, const double* u) const {
	const double x = u[0]; const double y = u[1];
	if      (i == 0) return x*x*y*y*y + x*x*x*y*y - 12;
	else if (i == 1) return x*x*x*y*y*y*y + x*x*x*x*y*y*y - 24;
	else throw -4;
}

double NonLinearEquationSystem::getDerivative(const int i, const int j, const double* u) const {
	const double x = u[0]; const double y = u[1];
	if (i == 0) {
		if (j == 0)
			return 2*x*y*y*y + 3*x*x*y*y;
		
		else if (j == 1)
			return 3*x*x*y*y + 2*x*x*x*y;
		
		else 
			throw -4;
	}
	
	else if (i == 1) {
		if (j == 0)
			return 3*x*x*y*y*y*y + 4*x*x*x*y*y*y;
		
		else if (j == 1)
			return 3*x*x*x*x*y*y + 4*x*x*x*y*y*y;
	
		else throw -4;
	}
	
	else 
		throw -4;
}

void NonLinearEquationSystem::getFirstApproximation(double* u) const {
	u[0] = 3; u[1] = 5;
}

