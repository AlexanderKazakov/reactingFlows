#include <math.h>

#include "src/SystemToPlotShockIsentropic.hpp"

SystemToPlotShockIsentropic::SystemToPlotShockIsentropic() :
		EquationSystem(3) {
	
	before.setReagents({std::make_pair("C2H2", 0.0705),
	                    std::make_pair("O2",   0.2168),
	                    std::make_pair("N2",   0.7127)});
	Q = 0;
	p0 = 1e+5 / p_dimensionless;
	T0 = 298 / T_dimensionless;
	eta0 = R * T0 * before.getMeanInverseMolarMass() / p0;
}

void SystemToPlotShockIsentropic::setGivenEta(const double& _givenEta) {
	givenEta = _givenEta;
}

double SystemToPlotShockIsentropic::getValue(const int i, const double* u) const {
	const double p = u[0];
	const double eta = u[1];
	const double T = u[2];
	
	if (i == 0)
		return  p * eta * (before.gamma(T0) - 1) - p0 * eta0 * (before.gamma(T) - 1) 
		     + (p + p0) * (eta - eta0) * (before.gamma(T) - 1) * (before.gamma(T0) - 1) / 2 
			 -  Q * (before.gamma(T) - 1) * (before.gamma(T0) - 1);
	
	else if (i == 1)
		return eta - givenEta;
	
	else if (i == 2)
		return p * eta - R * T * before.getMeanInverseMolarMass();
	
	else 
		throw -1;
}

double SystemToPlotShockIsentropic::getDerivative(const int i, const int j,
                                          const double* u) const {
	const double p = u[0];
	const double eta = u[1];
	const double T = u[2];
	
	if (i == 0) {
		
		if (j == 0) 
			return  eta * (before.gamma(T0) - 1) 
			     + (eta - eta0) * (before.gamma(T) - 1) * (before.gamma(T0) - 1) / 2;
		
		else if (j == 1)
			return  p * (before.gamma(T0) - 1) 
			     + (p + p0) * (before.gamma(T) - 1) * (before.gamma(T0) - 1) / 2;
		
		else if (j == 2)
			return ( - p0 * eta0 - Q * (before.gamma(T0) - 1)
			     + (p + p0) * (eta - eta0) * (before.gamma(T0) - 1) ) * before.gammaDer(T);
		
		else 
			throw -2;
	} 
	
	else if (i == 1) {
		
		if (j == 0)
			return 0;
		
		else if (j == 1)
			return 1;
		
		else if (j == 2)
			return 0;
		
		else 
			throw -2;
	} 
	
	else if (i == 2) {
		
		if (j == 0)
			return eta;
		
		else if (j == 1)
			return p;
		
		else if (j == 2) 
			return - R * before.getMeanInverseMolarMass();
		
		else 
			throw -2;
	} 
	
	else
		throw -2;
}

void SystemToPlotShockIsentropic::getFirstApproximation(double* u) const {
	u[0] = p0;
	u[1] = givenEta;
	u[2] = T0;
}

void SystemToPlotShockIsentropic::printCompleteSolution(const double* u) const {
	const double p = u[0] * p_dimensionless;
	const double eta = u[1]; // eta_dimensionless = 1
	const double T = u[2] * T_dimensionless;
	
	const double D = eta0 * sqrt(fabs((p - p0) / (eta0 - eta)));
	const double v = (eta0 - eta) * sqrt(fabs((p - p0) / (eta0 - eta)));
	const double gamma = before.gamma(u[2]);
	
	std::cout << "Results:\n"
		<< "p = " << p << "\n"
		<< "rho = " << 1.0 / eta << "\n"
		<< "T = " << T << "\n"
		<< "v = " << v << "\n"
		<< "D = " << D << "\n"
		<< "gamma = " << gamma << "\n";

}


double SystemToPlotShockIsentropic::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < getSize(); i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}