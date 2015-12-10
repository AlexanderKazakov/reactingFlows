#ifndef IMPLICITEULERMETHOD_HPP
#define	IMPLICITEULERMETHOD_HPP

#include <fstream>

#include "src/ImplicitEulerMethodSystem.hpp"
#include "src/NewtonMethod.hpp"


class ImplicitEulerMethod {
public:
	ImplicitEulerMethod(EquationSystem* rightSideOfODE, double tau, double T);
	~ImplicitEulerMethod();
	void calculate();
	
private:
	NewtonMethod theNewtonMethod;
	ImplicitEulerMethodSystem implicitEulerMethodSystem;
	double tau = 0; // time step
	double t = 0; // current time
	double T = 0; // required time
	
	std::fstream resultFile;
	void printSolutionToFile(double t, double* solution);

	bool nextStep();
};

#endif	/* IMPLICITEULERMETHOD_HPP */

