#include <cstdlib>

#include "src/NewthonMethod.hpp"
#include "src/GasDetonationSystem.hpp"

using namespace std;

/*
 * The first home task of the P.Utkin course
 * "Numerical simulation of reacting flows"
 * All values in SI system
 */

int main(int argc, char** argv) {
	
	GasDetonationSystem gasDetonationSystem;
	double* solution = new double[gasDetonationSystem.getSize()];
	NewthonMethod newthonMethod;
	newthonMethod.solve(gasDetonationSystem, solution);
	
	delete [] solution;
	return 0;
}

