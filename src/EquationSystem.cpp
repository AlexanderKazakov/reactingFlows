#include "src/EquationSystem.hpp"
#include "src/GasDetonationSystem.hpp"
#include "src/ImplicitEulerMethodSystem.hpp"
#include "src/SystemToPlotHugoniotIsentropic.hpp"
#include "src/SystemToPlotShockIsentropic.hpp"
#include "src/ZeldovichSystem.hpp"
#include "test/LinearEquationSystem.hpp"
#include "test/NonLinearEquationSystem.hpp"
#include "test/TestODESystem.hpp"

#include <math.h>

EquationSystem::EquationSystem(const int size) : size(size) 
{
}

int EquationSystem::getSize() const {
	return size;
}

double EquationSystem::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < size; i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}

double EquationSystem::getValue(const int i, const double* u) const {
	switch (implementation) {
		case GAS_DETONATION:
			return static_cast<const GasDetonationSystem*>(this)->getValue(i, u);
		case IMPLICIT_EULER_METHOD:
			return static_cast<const ImplicitEulerMethodSystem*>(this)->getValue(i, u);
		case PLOT_HUGONIOT_ISENTROPIC:
			return static_cast<const SystemToPlotHugoniotIsentropic*>(this)->getValue(i, u);
		case PLOT_SHOCK_ISENTROPIC:
			return static_cast<const SystemToPlotShockIsentropic*>(this)->getValue(i, u);
		case ZELDOVICH:
			return static_cast<const ZeldovichSystem*>(this)->getValue(i, u);
		case LINEAR_EQUATION:
			return static_cast<const LinearEquationSystem*>(this)->getValue(i, u);
		case NON_LINEAR_EQUATION:
			return static_cast<const NonLinearEquationSystem*>(this)->getValue(i, u);
		case TEST_ODE:
			return static_cast<const TestODESystem*>(this)->getValue(i, u);
		default:
			throw "No such implementation";
	}
}

double EquationSystem::getDerivative(const int i, const int j, const double* u) const {
	switch (implementation) {
		case GAS_DETONATION:
			return static_cast<const GasDetonationSystem*>(this)->getDerivative(i, j, u);
		case IMPLICIT_EULER_METHOD:
			return static_cast<const ImplicitEulerMethodSystem*>(this)->getDerivative(i, j, u);
		case PLOT_HUGONIOT_ISENTROPIC:
			return static_cast<const SystemToPlotHugoniotIsentropic*>(this)->getDerivative(i, j, u);
		case PLOT_SHOCK_ISENTROPIC:
			return static_cast<const SystemToPlotShockIsentropic*>(this)->getDerivative(i, j, u);
		case ZELDOVICH:
			return static_cast<const ZeldovichSystem*>(this)->getDerivative(i, j, u);
		case LINEAR_EQUATION:
			return static_cast<const LinearEquationSystem*>(this)->getDerivative(i, j, u);
		case NON_LINEAR_EQUATION:
			return static_cast<const NonLinearEquationSystem*>(this)->getDerivative(i, j, u);
		case TEST_ODE:
			return static_cast<const TestODESystem*>(this)->getDerivative(i, j, u);
		default:
			throw "No such implementation";
	}
}

void EquationSystem::getFirstApproximation(double* u) const {
	switch (implementation) {
		case GAS_DETONATION:
			return static_cast<const GasDetonationSystem*>(this)->getFirstApproximation(u);
		case IMPLICIT_EULER_METHOD:
			return static_cast<const ImplicitEulerMethodSystem*>(this)->getFirstApproximation(u);
		case PLOT_HUGONIOT_ISENTROPIC:
			return static_cast<const SystemToPlotHugoniotIsentropic*>(this)->getFirstApproximation(u);
		case PLOT_SHOCK_ISENTROPIC:
			return static_cast<const SystemToPlotShockIsentropic*>(this)->getFirstApproximation(u);
		case ZELDOVICH:
			return static_cast<const ZeldovichSystem*>(this)->getFirstApproximation(u);
		case LINEAR_EQUATION:
			return static_cast<const LinearEquationSystem*>(this)->getFirstApproximation(u);
		case NON_LINEAR_EQUATION:
			return static_cast<const NonLinearEquationSystem*>(this)->getFirstApproximation(u);
		case TEST_ODE:
			return static_cast<const TestODESystem*>(this)->getFirstApproximation(u);
		default:
			throw "No such implementation";
	}
}

void EquationSystem::printCompleteSolution(const double* u) const {
	switch (implementation) {
		case GAS_DETONATION:
			return static_cast<const GasDetonationSystem*>(this)->printCompleteSolution(u);
		case IMPLICIT_EULER_METHOD:
			return static_cast<const ImplicitEulerMethodSystem*>(this)->printCompleteSolution(u);
		case PLOT_HUGONIOT_ISENTROPIC:
			return static_cast<const SystemToPlotHugoniotIsentropic*>(this)->printCompleteSolution(u);
		case PLOT_SHOCK_ISENTROPIC:
			return static_cast<const SystemToPlotShockIsentropic*>(this)->printCompleteSolution(u);
		case ZELDOVICH:
			return static_cast<const ZeldovichSystem*>(this)->printCompleteSolution(u);
		case LINEAR_EQUATION:
			return static_cast<const LinearEquationSystem*>(this)->printCompleteSolution(u);
		case NON_LINEAR_EQUATION:
			return static_cast<const NonLinearEquationSystem*>(this)->printCompleteSolution(u);
		case TEST_ODE:
			return static_cast<const TestODESystem*>(this)->printCompleteSolution(u);
		default:
			throw "No such implementation";
	}
}



