#ifndef GASDETONATIONSYSTEM_HPP
#define	GASDETONATIONSYSTEM_HPP

#include "src/EquationSystem.hpp"
#include "src/Mixture.hpp"

/**
 * A system of non-linear equations describes the behaviour of the parameters
 * of the gas behind the front of discontinuity caused by detonation
 * p - pressure
 * eta == 1 / rho - unit volume
 * T - absolute temperature
 * Q - energy of the reaction
 * All values in SI
 */
class GasDetonationSystem : public EquationSystem {
public:
	GasDetonationSystem();

	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;

private:
	/* The mixture of products of reaction behind the front of discontinuity */
	Mixture behind;
	/* The mixture of sources of reaction before the front of discontinuity */
	Mixture before;
	
	double T0 = 0;
	double p0 = 0;
	double eta0 = 0;
	double Q = 0;
	
};

#endif	/* GASDETONATIONSYSTEM_HPP */

