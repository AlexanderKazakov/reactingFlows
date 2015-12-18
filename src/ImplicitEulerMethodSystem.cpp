#include <math.h>

#include "src/ImplicitEulerMethodSystem.hpp"


ImplicitEulerMethodSystem::ImplicitEulerMethodSystem(EquationSystem* rightSideOfODE, double tau) : 
		EquationSystem(rightSideOfODE->getSize()), rightSideOfODE(rightSideOfODE), tau(tau)
{
	previousValue = new double [getSize()];
	rightSideOfODE->getFirstApproximation(previousValue);
}

double ImplicitEulerMethodSystem::getValue(const int i, const double* u) const {
	
	return u[i] - tau * rightSideOfODE->getValue(i, u) - previousValue[i];
}

double ImplicitEulerMethodSystem::getDerivative(const int i, const int j,
                                                const double* u) const {
	return (i == j) - tau * rightSideOfODE->getDerivative(i, j, u);
}

void ImplicitEulerMethodSystem::getFirstApproximation(double* u) const {
	for(int i = 0; i < getSize(); i++)
		u[i] = previousValue[i];
}

void ImplicitEulerMethodSystem::setPreviousValue(double* _previousValue) {
	for(int i = 0; i < getSize(); i++)
		previousValue[i] = _previousValue[i];
}

void ImplicitEulerMethodSystem::getPreviousValue(double* _previousValue) {
	for(int i = 0; i < getSize(); i++)
		_previousValue[i] = previousValue[i];
}

void ImplicitEulerMethodSystem::printCompleteSolution(const double* u) const {
	rightSideOfODE->printCompleteSolution(u);
}