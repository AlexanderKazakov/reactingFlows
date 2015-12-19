#include "test/LinearEquationSystem.hpp"

#include <math.h>

LinearEquationSystem::LinearEquationSystem() : EquationSystem(LES_SIZE) {
}

double LinearEquationSystem::getValue(const int i, const double* u) const {
	double ans = 0;
	for(int j = 0; j < LES_SIZE; j++)
		ans += A[i][j] * u[j];
	ans -= b[i];
	return ans;
}

double LinearEquationSystem::getDerivative(const int i, const int j, const double* u) const {
	return A[i][j];
}

void LinearEquationSystem::getFirstApproximation(double* u) const {
	for(int i = 0; i < LES_SIZE; i++)
		u[i] = b[i];
}


double LinearEquationSystem::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < getSize(); i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}