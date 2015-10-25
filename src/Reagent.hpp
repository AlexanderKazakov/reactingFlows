#ifndef REAGENT_HPP
#define	REAGENT_HPP

#include <string>
#include <vector>
#include <iostream>

#define CONST_GAMMA 0
#define NON_DIMENSIONALIZATION 1
#define DEFLAGRATION 0
#define PLOT_ISENTROPICS 0


/* Parameters of non-dimensionalization */
#if NON_DIMENSIONALIZATION
static const double p_dimensionless = 1e+6;
static const double Q_dimensionless = 1e+6;
static const double T_dimensionless = 1e+3;
static const double R_dimensionless = 1e+3;
#else
static const double p_dimensionless = 1;
static const double Q_dimensionless = 1;
static const double T_dimensionless = 1;
static const double R_dimensionless = 1;
#endif

static const double R = 8.31 / R_dimensionless;


/**
 * To store parameters of a reagent
 */
class Reagent {
public:
	Reagent(const std::string name);
	
	std::string name;
	/* molar mass */
	double mu;	
	/* thermal capacity at specified temperature T */
	double Cv(const double& T) const;
	/* derivative by T of thermal capacity at specified temperature T */
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

