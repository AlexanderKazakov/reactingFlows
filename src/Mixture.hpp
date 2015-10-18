#ifndef MIXTURE_HPP
#define	MIXTURE_HPP

#include <utility>

#include "src/Reagent.hpp"

/**
 * Represents storage of reagents with their relative mass proportions
 * which the mixture contains
 */
class Mixture {
public:
	/**
	 * Prepare specified mixture
	 * @param _reagents vector of pairs <name of a reagent, relative mass proportion>
	 */
	void setReagents(std::vector<std::pair<std::string, double>> _reagents);
	/* @return the average (by mass) inverse molar mass of the mixture */
	double getMeanInverseMolarMass() const;
	/* isentropic volume exponent at specified temperature T */
	double gamma(const double& T) const;
	/* derivative by T of isentropic volume exponent at specified temperature T */
	double gammaDer(const double& T) const;
private:
	/* vector of pairs <reagent, its relative mass proportion> */
	std::vector<std::pair<Reagent, double>> reagents;
	/* the average (by mass) inverse molar mass of the mixture */
	double meanInverseMolarMass = 0;	
	/* Calculate meanInverseMolarMass that doesn't then change while program execution */
	void calcMeanInverseMolarMass();

};

#endif	/* MIXTURE_HPP */

