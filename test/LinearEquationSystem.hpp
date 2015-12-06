#ifndef LINEAREQUATIONSYSTEM_HPP
#define	LINEAREQUATIONSYSTEM_HPP

#include "src/EquationSystem.hpp"

#define LES_SIZE 3

class LinearEquationSystem : public EquationSystem {
public:
	LinearEquationSystem();
	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j, 
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	virtual void printCompleteSolution(const double* u) const override {};

private:
	const double A[LES_SIZE][LES_SIZE] = {{ 6, 5, 1 },
	                                      { 1, 0, 2 },
	                                      {-6, 3, 4 }};
	const double b[LES_SIZE] = {7, -8, -32};
};

#endif	/* LINEAREQUATIONSYSTEM_HPP */

