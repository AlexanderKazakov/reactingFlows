#include <math.h>

#include "src/ImplicitEulerMethod.hpp"

ImplicitEulerMethod::ImplicitEulerMethod(EquationSystem* rightSideOfODE,
                                         double tau, double T) :
		implicitEulerMethodSystem(rightSideOfODE, tau), tau(tau), T(T) {	
	
	theNewtonMethod.logging = false;
	resultFile.open("Zeldovich.txt", std::ios::out);
}

ImplicitEulerMethod::~ImplicitEulerMethod() {
	resultFile.close();
}

void ImplicitEulerMethod::calculate() {
	double* initial = new double [implicitEulerMethodSystem.getSize()];
	implicitEulerMethodSystem.getFirstApproximation(initial);
	implicitEulerMethodSystem.printCompleteSolution(initial);
	printSolutionToFile(t, initial);
	
	while (t < T && nextStep());
	delete [] initial;
}

bool ImplicitEulerMethod::nextStep() {
	double* solution = new double[implicitEulerMethodSystem.getSize()];
	if( !theNewtonMethod.solve(implicitEulerMethodSystem, solution) ) {
		return false;
	}
	implicitEulerMethodSystem.printCompleteSolution(solution);
	printSolutionToFile(t, solution);
	
	implicitEulerMethodSystem.setPreviousValue(solution);
	delete [] solution;
	t += tau;
	return true;
}

void ImplicitEulerMethod::printSolutionToFile(double t, double* solution) {
	resultFile << t << '\t';
	for(int i = 0; i < implicitEulerMethodSystem.getSize(); i++) {
		resultFile << solution[i] << '\t';
	}
	resultFile << std::endl;
}
