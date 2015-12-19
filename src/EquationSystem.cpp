#include "src/EquationSystem.hpp"

#include <math.h>

EquationSystem::EquationSystem(const int size) : size(size) 
{
}

int EquationSystem::getSize() const {
	return size;
}