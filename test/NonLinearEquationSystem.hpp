#ifndef NONLINEAREQUATIONSYSTEM_HPP
#define	NONLINEAREQUATIONSYSTEM_HPP

#include "src/EquationSystem.hpp"

class NonLinearEquationSystem : public EquationSystem {
public:
	NonLinearEquationSystem();
	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j, 
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	virtual void printCompleteSolution(const double* u) const override {};

private:
	
};

#endif	/* NONLINEAREQUATIONSYSTEM_HPP */

