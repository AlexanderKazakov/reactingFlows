#ifndef NONLINEAREQUATIONSYSTEM_HPP
#define	NONLINEAREQUATIONSYSTEM_HPP

#include "src/EquationSystem.hpp"

class NonLinearEquationSystem : public EquationSystem {
public:
	NonLinearEquationSystem();
	double getValue(const int i, const double* u) const;
	double getDerivative(const int i, const int j, const double* u) const;
	void getFirstApproximation(double* u) const;
	void printCompleteSolution(const double* u) const {};
	double residualError(const double* u) const;
	void setCustomParam(const double& param) {};
	void setCustomValue(const double* value) {};
	void getCustomValue(const double* value) const {};
private:
	
};

#endif	/* NONLINEAREQUATIONSYSTEM_HPP */

