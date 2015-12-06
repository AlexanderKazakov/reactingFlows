#include <math.h>
#include <iostream>

#include "test/TestODESystem.hpp"


TestODESystem::TestODESystem() : EquationSystem(1) {
}

double TestODESystem::getValue(const int i, const double* u) const {
	
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

double TestODESystem::getDerivative(const int i, const int j,
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

void TestODESystem::getFirstApproximation(double* u) const {
	for(int i = 0; i < getSize(); i++)
		u[i] = 1;
}

void TestODESystem::printCompleteSolution(const double* u) const {
	for(int i = 0; i < getSize(); i++)
		std::cout << "u[" << i << "] = " << u[i] << std::endl;
	std::cout << std::endl;
}

