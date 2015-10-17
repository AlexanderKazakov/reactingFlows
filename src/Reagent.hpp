#ifndef REAGENT_HPP
#define	REAGENT_HPP

#include <string>
#include <vector>
#include <iostream>

/**
 * A struct to store parameters of a reagent
 */
class Reagent {
public:
	Reagent(const std::string name);
	
	std::string name;
	/* molar mass */
	double mu;	
	/* thermal capacity at specified temperature T in units of R */
	double Cv(const double& T) const;
	/* derivative by T of thermal capacity at specified temperature T in units of R */
	double CvDer(const double& T) const;
private:
	/* coefficients in Cv (thermal capacity) correlation from temperature */
	std::vector<double> a; // for temperature less 1e+3 K
	std::vector<double> b; // for temperature more 1e+3 K
	
	/**
     * @param base
     * @param exponent
     * @return base^exponent
     */
	double pow(const double& base, const int exponent) const;
};

#endif	/* REAGENT_HPP */

