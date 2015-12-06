#ifndef SYSTEMTOPLOTHUGONIOTISENTROPIC_HPP
#define	SYSTEMTOPLOTHUGONIOTISENTROPIC_HPP

#include "src/EquationSystem.hpp"
#include "src/Mixture.hpp"
#include "src/ConstMixture.hpp"

/**
 * A system to calculate Hugoniot isentropic parameters by given eta
 * p - pressure
 * eta == 1 / rho - unit volume
 * T - absolute temperature
 * Q - energy of the reaction
 * All values in SI
 */
class SystemToPlotHugoniotIsentropic : public EquationSystem {
public:
	SystemToPlotHugoniotIsentropic(const double& givenEta);

	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	virtual void printCompleteSolution(const double* u) const override;

private:
#if CONST_GAMMA
	/* The mixture of products of reaction behind the front of discontinuity */
	ConstMixture behind;
	/* The mixture of sources of reaction before the front of discontinuity */
	ConstMixture before;
#else
	/* The mixture of products of reaction behind the front of discontinuity */
	Mixture behind;
	/* The mixture of sources of reaction before the front of discontinuity */
	Mixture before;
#endif
	
	double T0 = 0;
	double p0 = 0;
	double eta0 = 0;
	double Q = 0;
	/* given eta */
	double givenEta = 0;
	
	
};

#endif	/* SYSTEMTOPLOTHUGONIOTISENTROPIC_HPP */

