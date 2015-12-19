#ifndef IMPLICITEULERMETHOD_HPP
#define	IMPLICITEULERMETHOD_HPP

#include <fstream>

#include "src/ImplicitEulerMethodSystem.hpp"
#include "src/NewtonMethod.hpp"


template<class RightSideOfODE>
class ImplicitEulerMethod {
public:
	ImplicitEulerMethod();
	void setTauAndT(double _tau, double _T);
	~ImplicitEulerMethod();
	void calculate();
	
private:
	NewtonMethod<ImplicitEulerMethodSystem<RightSideOfODE>> theNewtonMethod;
	ImplicitEulerMethodSystem<RightSideOfODE> implicitEulerMethodSystem;
	double tau = 0; // time step
	double t = 0; // current time
	double T = 0; // required time
	
	std::fstream resultFile;
	void printSolutionToFile(double t, double* solution);

	bool nextStep();
};

#endif	/* IMPLICITEULERMETHOD_HPP */

