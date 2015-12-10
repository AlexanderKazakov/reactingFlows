#ifndef TESTODESYSTEM_HPP
#define	TESTODESYSTEM_HPP

#include "src/EquationSystem.hpp"


class TestODESystem : public EquationSystem {
public:
	TestODESystem();

	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	virtual void printCompleteSolution(const double* u) const override;
	
	void getAnalyticalSolution(double* analytSol, const double t) const;

private:
	
	double a;
	double b;
	double A[2][2];

};

#endif	/* TESTODESYSTEM_HPP */

