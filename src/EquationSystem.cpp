#include "src/EquationSystem.hpp"

#include <math.h>

EquationSystem::EquationSystem(const int size) : size(size) 
{
}

int EquationSystem::getSize() const {
	return size;
}

double EquationSystem::residualError(const double* u) const {
	double ans = 0;
	for(int i = 0; i < size; i++) {
		double error = getValue(i, u);
		ans += error*error;
	}
	return sqrt(ans);
}
