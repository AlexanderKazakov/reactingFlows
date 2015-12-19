#include <math.h>

#include "src/GasDetonationSystem.hpp"


GasDetonationSystem::GasDetonationSystem() : EquationSystem(3) {
	
	before.setReagents({std::make_pair("C2H2", 0.0705),
	                    std::make_pair("O2",   0.2168),
	                    std::make_pair("N2",   0.7127)});
												
	behind.setReagents({std::make_pair("CO2",  0.2385),
	                    std::make_pair("H2O",  0.0488),
	                    std::make_pair("N2",   0.7127)});
						
	Q = 3.38e+6 / Q_dimensionless;
	p0 = 1e+5 / p_dimensionless;
	T0 = 298 / T_dimensionless;
	eta0 = R * T0 * before.getMeanInverseMolarMass() / p0;
}

double GasDetonationSystem::getValue(const int i, const double* u) const {
	const double p = u[0];
	const double eta = u[1];
	const double T = u[2];
	
	if (i == 0)
		return  p * eta * (before.gamma(T0) - 1) - p0 * eta0 * (behind.gamma(T) - 1) 
		     + (p + p0) * (eta - eta0) * (behind.gamma(T) - 1) * (before.gamma(T0) - 1) / 2 
			 -  Q * (behind.gamma(T) - 1) * (before.gamma(T0) - 1);
	
	else if (i == 1)
		return eta * (p - p0) + behind.gamma(T) * p * (eta - eta0);
	
	else if (i == 2)
		return p * eta - R * T * behind.getMeanInverseMolarMass();
	
	else 
		throw -1;
}

double GasDetonationSystem::getDerivative(const int i, const int j,
                                          const double* u) const {
	const double p = u[0];
	const double eta = u[1];
	const double T = u[2];
	
	if (i == 0) {
		
		if (j == 0) 
			return  eta * (before.gamma(T0) - 1) 
			     + (eta - eta0) * (behind.gamma(T) - 1) * (before.gamma(T0) - 1) / 2;
		
		else if (j == 1)
			return  p * (before.gamma(T0) - 1) 
			     + (p + p0) * (behind.gamma(T) - 1) * (before.gamma(T0) - 1) / 2;
		
		else if (j == 2)
			return ( - p0 * eta0 - Q * (before.gamma(T0) - 1)
			     + (p + p0) * (eta - eta0) * (before.gamma(T0) - 1) ) * behind.gammaDer(T);
		
		else 
			throw -2;
	} 
	
	else if (i == 1) {
		
		if (j == 0)
			return eta + behind.gamma(T) * (eta - eta0);
		
		else if (j == 1)
			return (p - p0) + behind.gamma(T) * p;
		
		else if (j == 2)
			return p * (eta - eta0) * behind.gammaDer(T);
		
		else 
			throw -2;
	} 
	
	else if (i == 2) {
		
		if (j == 0)
			return eta;
		
		else if (j == 1)
			return p;
		
		else if (j == 2) 
			return - R * behind.getMeanInverseMolarMass();
		
		else 
			throw -2;
	} 
	
	else
		throw -2;
}

void GasDetonationSystem::getFirstApproximation(double* u) const {
#if DEFLAGRATION
	u[0] = p0 / 10;
	u[1] = eta0 * 10;
	u[2] = T0 / 10;
#else
	u[0] = 1e+6*p0;
	u[1] = eta0/100;
	u[2] = 100*T0;
#endif
	
}

void GasDetonationSystem::printCompleteSolution(const double* u) const {
	const double p = u[0] * p_dimensionless;
	const double eta = u[1]; // eta_dimensionless = 1
	const double T = u[2] * T_dimensionless;
	
	const double D = eta0 * sqrt(fabs((p - p0) / (eta0 - eta)));
	const double v = (eta0 - eta) * sqrt(fabs((p - p0) / (eta0 - eta)));
	const double gamma = behind.gamma(u[2]);
	
	std::cout << "Results:\n"
		<< "p = " << p << "\n"
		<< "rho = " << 1.0 / eta << "\n"
		<< "T = " << T << "\n"
		<< "v = " << v << "\n"
		<< "D = " << D << "\n"
		<< "gamma = " << gamma << "\n"
		<< "eta0 = " << eta0 << "\n";

}

double GasDetonationSystem::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < getSize(); i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}