#ifndef IMPLICITEULERMETHOD_HPP
#define	IMPLICITEULERMETHOD_HPP

#include "src/ImplicitEulerMethodSystem.hpp"
#include "src/NewtonMethod.hpp"


class ImplicitEulerMethod {
public:
	ImplicitEulerMethod(EquationSystem* rightSideOfODE, double tau, double T);
	void calculate();
	
private:
	NewtonMethod theNewtonMethod;
	ImplicitEulerMethodSystem implicitEulerMethodSystem;
	double tau = 0; // time step
	double t = 0; // current time
	double T = 0; // required time
	
	void nextStep();
};

#endif	/* IMPLICITEULERMETHOD_HPP */

