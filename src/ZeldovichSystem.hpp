#ifndef ZELDOVICHSYSTEM_HPP
#define	ZELDOVICHSYSTEM_HPP

#include "src/EquationSystem.hpp"

/**
 * A system of non-linear equations describes the behaviour of the parameters
 * of the gas behind the front of discontinuity caused by detonation
 * p - pressure
 * eta == 1 / rho - unit volume
 * T - absolute temperature
 * Q - energy of the reaction
 * All values in SI
 */
class ZeldovichSystem : public EquationSystem {
public:
	ZeldovichSystem();

	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	virtual void printCompleteSolution(const double* u) const override;



private:

};

#endif	/* ZELDOVICHSYSTEM_HPP */

