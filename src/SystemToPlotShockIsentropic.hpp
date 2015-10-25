#ifndef SYSTEMTOPLOTSHOCKISENTROPIC_HPP
#define	SYSTEMTOPLOTSHOCKISENTROPIC_HPP

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
class SystemToPlotShockIsentropic : public EquationSystem {
public:
	SystemToPlotShockIsentropic(const double& givenEta);

	virtual double getValue(const int i, const double* u) const override;
	virtual double getDerivative(const int i, const int j,
	                             const double* u) const override;
	virtual void getFirstApproximation(double* u) const override;
	
	void printCompleteSolution(const double* u) const;

private:
#if CONST_GAMMA
	/* The mixture of sources of reaction */
	ConstMixture before;
#else
	/* The mixture of sources of reaction */
	Mixture before;
#endif
	
	double T0 = 0;
	double p0 = 0;
	double eta0 = 0;
	double Q = 0;
	/* given eta */
	double givenEta = 0;
	
	
};

#endif	/* SYSTEMTOPLOTSHOCKISENTROPIC_HPP */

