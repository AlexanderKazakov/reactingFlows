#ifndef IMPLICITEULERMETHODSYSTEM_HPP
#define	IMPLICITEULERMETHODSYSTEM_HPP

#include "src/EquationSystem.hpp"

/**
 * A system of non-linear equations that appears on every step of
 * Implicit Euler method for ODE solving
 */
template<class RightSideOfODE>
class ImplicitEulerMethodSystem : public EquationSystem {
public:
	ImplicitEulerMethodSystem();
	void setTau(const double _tau);
	int getSize() const;

	double getValue(const int i, const double* u) const;
	double getDerivative(const int i, const int j, const double* u) const;
	void getFirstApproximation(double* u) const;
	void printCompleteSolution(const double* u) const;
	double residualError(const double* u) const;
	void setCustomParam(const double& param) {setTau(param);};
	void setCustomValue(const double* value) {setPreviousValue(value);};
	void getCustomValue(double* value) const {getPreviousValue(value);};

	void setPreviousValue(const double* _previousValue);
	void getPreviousValue(double* _previousValue) const;
	

private:
	/**
	 * If the ODE is:
	 * d\vec{y} / dt = \vec{f}(t, \vec{y})
	 * This system represents the function \vec{f}(t, \vec{y})
	 */
	RightSideOfODE rightSideOfODE;
	double* previousValue;
	double tau = 0;
};

#endif	/* IMPLICITEULERMETHODSYSTEM_HPP */

