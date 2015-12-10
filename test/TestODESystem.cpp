#include <math.h>
#include <iostream>

#include "test/TestODESystem.hpp"


TestODESystem::TestODESystem() : EquationSystem(2) {
	a = -10;
	b = -1;
	A[0][0] = A[1][1] = (a + b) / 2;
	A[0][1] = A[1][0] = (a - b) / 2;
}

double TestODESystem::getValue(const int i, const double* u) const {
	double ans[2];
	ans[0] = A[0][0] * u[0] + A[0][1] * u[1];
	ans[1] = A[1][0] * u[0] + A[1][1] * u[1];
	
	return ans[i];
}

double TestODESystem::getDerivative(const int i, const int j,
                                      const double* u) const {
	
	return A[i][j];
}

void TestODESystem::getFirstApproximation(double* u) const {
	u[0] = 0; u[1] = 2;
}

void TestODESystem::printCompleteSolution(const double* u) const {
	for(int i = 0; i < getSize(); i++)
		std::cout << "u[" << i << "] = " << u[i] << std::endl;
	std::cout << std::endl;
}

void TestODESystem::getAnalyticalSolution(double* analytSol, const double t) const {
	analytSol[0] = exp(a * t) - exp(b * t);
	analytSol[1] = exp(a * t) + exp(b * t);
}
