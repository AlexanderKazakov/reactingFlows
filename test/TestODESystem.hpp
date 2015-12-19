#ifndef TESTODESYSTEM_HPP
#define	TESTODESYSTEM_HPP

#include "src/EquationSystem.hpp"


class TestODESystem : public EquationSystem {
public:
	TestODESystem();

	double getValue(const int i, const double* u) const;
	double getDerivative(const int i, const int j, const double* u) const;
	void getFirstApproximation(double* u) const;
	void printCompleteSolution(const double* u) const;
	
	void getAnalyticalSolution(double* analytSol, const double t) const;
	double residualError(const double* u) const;
	void setCustomParam(const double& param) {};
	void setCustomValue(const double* value) {};
	void getCustomValue(const double* value) const {};
private:
	
	double a;
	double b;
	double A[2][2];

};

#endif	/* TESTODESYSTEM_HPP */

