#ifndef ZELDOVICHSYSTEM_HPP
#define	ZELDOVICHSYSTEM_HPP

#include <math.h>

#include "src/EquationSystem.hpp"
#include "src/Reagent.hpp"

/**
 * A system of non-linear equations describes the right side
 * of Zeldovich ODE from task 2
 */
class ZeldovichSystem : public EquationSystem {
public:
	ZeldovichSystem();
	~ZeldovichSystem();

	virtual double getValue(const int i, const double* f) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* f) const override;
	virtual void getFirstApproximation(double* f) const override;
	virtual void printCompleteSolution(const double* f) const override;

private:
	const double A = 1.64e+9 / A_dimensionless;
	const double Ea = 167e+3 / E_dimensionless;
	const double Q = 3.58e+6 / Q_dimensionless;
	const double mu = 0.027 / m_dimensionless;
	const double gamma = 1.197;
	
	const double p0 = 1e+5 / p_dimensionless;
	const double T0 = 293 / T_dimensionless;
	double rho0 = p0 * mu / (R * T0);
	double Dcj = sqrt((gamma*gamma - 1) * Q / 2 + gamma * p0 / rho0)
	           + sqrt((gamma*gamma - 1) * Q / 2);

};

#endif	/* ZELDOVICHSYSTEM_HPP */

