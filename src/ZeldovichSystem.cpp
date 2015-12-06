#include <math.h>
#include <iostream>

#include "src/ZeldovichSystem.hpp"


ZeldovichSystem::ZeldovichSystem() : EquationSystem(1) {
}

double ZeldovichSystem::getValue(const int i, const double* u) const {
	
	return - u[i];
	
	if (i == 0)
		return  0;
	
	else if (i == 1)
		return 0;
	
	else if (i == 2)
		return 0;
	
	else if (i == 3)
		return 0;
	
	else 
		throw -1;
}

double ZeldovichSystem::getDerivative(const int i, const int j,
                                      const double* u) const {
	
	return - (i == j);
	
	if (i == 0) {
		
		if (j == 0) 
			return  0;
		
		else if (j == 1)
			return  0;
		
		else if (j == 2)
			return 0;
		
		else if (j == 3)
			return 0;
		
		else 
			throw -2;
	} 
	
	else if (i == 1) {
		
		if (j == 0)
			return 0;
		
		else if (j == 1)
			return 0;
		
		else if (j == 2)
			return 0;
		
		else if (j == 3)
			return 0;
		
		else 
			throw -2;
	} 
	
	else if (i == 2) {
		
		if (j == 0)
			return 0;
		
		else if (j == 1)
			return 0;
		
		else if (j == 2) 
			return 0;
		
		else if (j == 3)
			return 0;
		
		else 
			throw -2;
	} 
	
	else if (i == 3) {
		
		if (j == 0)
			return 0;
		
		else if (j == 1)
			return 0;
		
		else if (j == 2) 
			return 0;
		
		else if (j == 3)
			return 0;
		
		else 
			throw -2;
	} 
	
	else
		throw -2;
}

void ZeldovichSystem::getFirstApproximation(double* u) const {
	for(int i = 0; i < getSize(); i++)
		u[i] = 1;
}

void ZeldovichSystem::printCompleteSolution(const double* u) const {
	for(int i = 0; i < getSize(); i++)
		std::cout << "u[" << i << "] = " << u[i] << std::endl;
	std::cout << std::endl;
}

