#include <math.h>

#include "src/ImplicitEulerMethod.hpp"

ImplicitEulerMethod::ImplicitEulerMethod(EquationSystem* rightSideOfODE,
                                         double tau, double T) :
		implicitEulerMethodSystem(rightSideOfODE, tau), tau(tau), T(T) {	
	
	theNewtonMethod.logging = false;
}

void ImplicitEulerMethod::calculate() {
	double* initialApprox = new double [implicitEulerMethodSystem.getSize()];
	implicitEulerMethodSystem.getFirstApproximation(initialApprox);
	implicitEulerMethodSystem.printCompleteSolution(initialApprox);
	while (t < T) {
		nextStep();
	}
}

void ImplicitEulerMethod::nextStep() {
	double* solution = new double[implicitEulerMethodSystem.getSize()];
	theNewtonMethod.solve(implicitEulerMethodSystem, solution);
	
	implicitEulerMethodSystem.printCompleteSolution(solution);
	
	implicitEulerMethodSystem.setPreviousValue(solution);
	delete [] solution;
	t += tau;
}

