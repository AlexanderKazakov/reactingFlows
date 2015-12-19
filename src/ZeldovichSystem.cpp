#include <iostream>

#include "src/ZeldovichSystem.hpp"


ZeldovichSystem::ZeldovichSystem() : EquationSystem(4) {
}

ZeldovichSystem::~ZeldovichSystem() {
//	std::cout << "rho_dimensionless = " << rho_dimensionless << std::endl;
//	std::cout << "u_dimensionless = " << u_dimensionless << std::endl;
//	std::cout << "p_dimensionless = " << p_dimensionless << std::endl;
//	std::cout << "l_dimensionless = " << l_dimensionless << std::endl;
//	std::cout << "T_dimensionless = " << T_dimensionless << std::endl;
}

double ZeldovichSystem::getValue(const int i, const double* f) const {
	
	double rho = f[0];
	double u = f[1];
	double p = f[2];
	double Z = f[3];
	
	double T = p * mu / rho / R;
	double c = sqrt(gamma * R * T / mu);
	
	double dZdx = - A * rho * Z * exp( - Ea / R / T) / u;
	double dudx = - Q * u * (gamma - 1) * dZdx / (c*c - u*u);
	double drhodx = - rho * dudx / u;
	double dpdx = - rho * u * dudx;
	
	
	if (i == 0)
		return  drhodx;
	
	else if (i == 1)
		return dudx;
	
	else if (i == 2)
		return dpdx;
	
	else if (i == 3)
		return dZdx;
	
	else 
		throw -1;
}

double ZeldovichSystem::getDerivative(const int i, const int j,
                                      const double* f) const {
	
	double rho = f[0];
	double u = f[1];
	double p = f[2];
	double Z = f[3];
		
	// look at wxmaxima directory
	
	if (i == 0) {
		
		if (j == 0) 
			return (rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*Z*(gamma-1)*(Ea*p*rho*gamma-3*mu*p*p*gamma-Ea*rho*rho*u*u+2*mu*p*rho*u*u))/(mu*p*u*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 1)
			return  (rho*rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*Z*(gamma-1)*(p*gamma-3*rho*u*u))/(u*u*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 2)
			return -(rho*rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*Z*(gamma-1)*(Ea*p*rho*gamma-mu*p*p*gamma-Ea*rho*rho*u*u))/(mu*p*p*u*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 3)
			return -(rho*rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*(gamma-1))/(u*(p*gamma-rho*u*u));
		
		else 
			throw -2;
	} 
	
	else if (i == 1) {
		
		if (j == 0)
			return -(rho*exp(-(Ea*rho)/(mu*p))*A*Q*Z*(gamma-1)*(Ea*p*rho*gamma-2*mu*p*p*gamma-Ea*rho*rho*u*u+mu*p*rho*u*u))/(mu*p*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 1)
			return (2*rho*rho*rho*exp(-(Ea*rho)/(mu*p))*u*A*Q*Z*(gamma-1))/(p*gamma-rho*u*u)*(p*gamma-rho*u*u);
		
		else if (j == 2)
			return (rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*Z*(gamma-1)*(Ea*p*rho*gamma-mu*p*p*gamma-Ea*rho*rho*u*u))/(mu*p*p*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 3)
			return (rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*(gamma-1))/(p*gamma-rho*u*u);
		
		else 
			throw -2;
	} 
	
	else if (i == 2) {
		
		if (j == 0)
			return (rho*rho*exp(-(Ea*rho)/(mu*p))*u*A*Q*Z*(gamma-1)*(Ea*p*rho*gamma-3*mu*p*p*gamma-Ea*rho*rho*u*u+2*mu*p*rho*u*u))/(mu*p*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 1)
			return -(rho*rho*rho*exp(-(Ea*rho)/(mu*p))*A*Q*Z*(gamma-1)*(p*gamma+rho*u*u))/(p*gamma-rho*u*u)*(p*gamma-rho*u*u);
		
		else if (j == 2) 
			return -(rho*rho*rho*exp(-(Ea*rho)/(mu*p))*u*A*Q*Z*(gamma-1)*(Ea*p*rho*gamma-mu*p*p*gamma-Ea*rho*rho*u*u))/(mu*p*p*(p*gamma-rho*u*u)*(p*gamma-rho*u*u));
		
		else if (j == 3)
			return -(rho*rho*rho*exp(-(Ea*rho)/(mu*p))*u*A*Q*(gamma-1))/(p*gamma-rho*u*u);
		
		else 
			throw -2;
	} 
	
	else if (i == 3) {
		
		if (j == 0)
			return ((Ea*rho-mu*p)*exp(-(Ea*rho)/(mu*p))*A*Z)/(mu*p*u);
		
		else if (j == 1)
			return (rho*exp(-(Ea*rho)/(mu*p))*A*Z)/u*u;
		
		else if (j == 2) 
			return -(Ea*rho*rho*exp(-(Ea*rho)/(mu*p))*A*Z)/(mu*p*p*u);
		
		else if (j == 3)
			return -(rho*exp(-(Ea*rho)/(mu*p))*A)/u;
		
		else 
			throw -2;
	} 
	
	else
		throw -2;
}

void ZeldovichSystem::getFirstApproximation(double* f) const {
	
	f[2] /* p(0) */ = 2 * rho0 * Dcj*Dcj / (gamma + 1) 
  	                - (gamma - 1) / (gamma + 1) * p0;
	
	f[1] /* u(0) */ = Dcj - (f[2] - p0) /
		sqrt( rho0 * ((gamma + 1) * f[2] / 2 + (gamma - 1) * p0 / 2) );
	
	f[0] /* rho(0) */ = rho0 * Dcj / f[1];
	
	f[3] /* Z(0) */ = 1.0;
	
}

void ZeldovichSystem::printCompleteSolution(const double* f) const {
	double rho = f[0];
	double u = f[1];
	double p = f[2];
	double Z = f[3];
	
	double T = p * mu / rho / R;
	double c = sqrt(gamma * R * T / mu);
	
	std::cout << "rho = " << rho << " u = " << u << " p = " << p 
		<< " Z = " << Z << " T = " << T << " u / c = " << u / c << std::endl;
}


double ZeldovichSystem::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < getSize(); i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}