#ifndef IMPLICITEULERMETHODSYSTEM_HPP
#define	IMPLICITEULERMETHODSYSTEM_HPP

#include "src/EquationSystem.hpp"

/**
 * A system of non-linear equations that appears on every step of
 * Implicit Euler method for ODE solving
 */
class ImplicitEulerMethodSystem : public EquationSystem {
public:
	ImplicitEulerMethodSystem(EquationSystem* rightSideOfODE, double tau);

	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	virtual void printCompleteSolution(const double* u) const override;

	void setPreviousValue(double* _previousValue);
	

private:
	/**
	 * If the ODE is:
	 * d\vec{y} / dt = \vec{f}(t, \vec{y})
	 * This system represents the function \vec{f}(t, \vec{y})
	 */
	EquationSystem* rightSideOfODE;
	double* previousValue;
	double tau = 0;
};

#endif	/* IMPLICITEULERMETHODSYSTEM_HPP */

