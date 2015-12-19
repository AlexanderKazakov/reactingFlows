#include <math.h>

#include "src/ImplicitEulerMethod.hpp"
#include "src/ZeldovichSystem.hpp"
#include "test/TestODESystem.hpp"

template<class RightSideOfODE>
ImplicitEulerMethod<RightSideOfODE>::ImplicitEulerMethod() {
	theNewtonMethod.logging = false;
}

template<class RightSideOfODE>
void ImplicitEulerMethod<RightSideOfODE>::setTauAndT(double _tau, double _T) {	
		
	tau = _tau;
	T = _T;
	implicitEulerMethodSystem.setTau(_tau);
}

template<class RightSideOfODE>
ImplicitEulerMethod<RightSideOfODE>::~ImplicitEulerMethod() {
//	resultFile.close();
}

template<class RightSideOfODE>
void ImplicitEulerMethod<RightSideOfODE>::calculate() {
	double* initial = new double [implicitEulerMethodSystem.getSize()];
	implicitEulerMethodSystem.getFirstApproximation(initial);
//	implicitEulerMethodSystem.printCompleteSolution(initial);
//	printSolutionToFile(t, initial);
	
	while (t < T && nextStep());
	delete [] initial;
}

template<class RightSideOfODE>
bool ImplicitEulerMethod<RightSideOfODE>::nextStep() {
	double* solution = new double[implicitEulerMethodSystem.getSize()];
	if( !theNewtonMethod.solve(solution) ) {
		implicitEulerMethodSystem.getPreviousValue(solution);
		if (fabs(solution[0] - 1.98) > 0.1) throw "rho invalid";
		if (fabs(solution[1] - 1.02) > 0.1) throw "u invalid";
		if (fabs(solution[2] - 1.72) > 0.1) throw "p invalid";
		if (fabs(solution[3] - 0.00) > 0.1) throw "Z invalid";
		return false;
	}
//	implicitEulerMethodSystem.printCompleteSolution(solution);
//	printSolutionToFile(t, solution);
	
	implicitEulerMethodSystem.setPreviousValue(solution);
	delete [] solution;
	t += tau;
	return true;
}

template<class RightSideOfODE>
void ImplicitEulerMethod<RightSideOfODE>::printSolutionToFile(double t, double* solution) {
//	resultFile << t << '\t';
//	for(int i = 0; i < implicitEulerMethodSystem.getSize(); i++) {
//		resultFile << solution[i] << '\t';
//	}
//	resultFile << std::endl;
}

template class ImplicitEulerMethod<ZeldovichSystem>;
template class ImplicitEulerMethod<TestODESystem>;