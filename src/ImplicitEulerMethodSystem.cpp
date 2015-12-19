#include <math.h>

#include "src/ImplicitEulerMethodSystem.hpp"
#include "src/ZeldovichSystem.hpp"
#include "test/TestODESystem.hpp"

template<class RightSideOfODE>
ImplicitEulerMethodSystem<RightSideOfODE>::ImplicitEulerMethodSystem() :
		EquationSystem(0) {
	previousValue = new double [rightSideOfODE.getSize()];
	rightSideOfODE.getFirstApproximation(previousValue);
}

template<class RightSideOfODE>
int ImplicitEulerMethodSystem<RightSideOfODE>::getSize() const {
	return rightSideOfODE.getSize();
}

template<class RightSideOfODE>
void ImplicitEulerMethodSystem<RightSideOfODE>::setTau(double _tau) {
	tau = _tau;
}

template<class RightSideOfODE>
double ImplicitEulerMethodSystem<RightSideOfODE>::getValue(const int i, const double* u) const {
	
	return u[i] - tau * rightSideOfODE.getValue(i, u) - previousValue[i];
}

template<class RightSideOfODE>
double ImplicitEulerMethodSystem<RightSideOfODE>::getDerivative(const int i, const int j,
                                                const double* u) const {
	return (i == j) - tau * rightSideOfODE.getDerivative(i, j, u);
}

template<class RightSideOfODE>
void ImplicitEulerMethodSystem<RightSideOfODE>::getFirstApproximation(double* u) const {
	for(int i = 0; i < getSize(); i++)
		u[i] = previousValue[i];
}

template<class RightSideOfODE>
void ImplicitEulerMethodSystem<RightSideOfODE>::setPreviousValue(double* _previousValue) {
	for(int i = 0; i < getSize(); i++)
		previousValue[i] = _previousValue[i];
}

template<class RightSideOfODE>
void ImplicitEulerMethodSystem<RightSideOfODE>::getPreviousValue(double* _previousValue) {
	for(int i = 0; i < getSize(); i++)
		_previousValue[i] = previousValue[i];
}

template<class RightSideOfODE>
void ImplicitEulerMethodSystem<RightSideOfODE>::printCompleteSolution(const double* u) const {
	rightSideOfODE.printCompleteSolution(u);
}

template<class RightSideOfODE>
double ImplicitEulerMethodSystem<RightSideOfODE>::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < getSize(); i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}


template class ImplicitEulerMethodSystem<ZeldovichSystem>;
template class ImplicitEulerMethodSystem<TestODESystem>;