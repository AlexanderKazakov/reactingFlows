#include <cstdlib>

#include "NewthonMethod.hpp"
#include "GasDetonationSystem.hpp"

using namespace std;

/*
 * The first home task of the P.Utkin course
 * "Numerical simulation of reacting flows"
 * All values in SI system
 */

int main(int argc, char** argv) {
	
	GasDetonationSystem gasDetonationSystem;
	double solution[3];
	NewthonMethod newthonMethod;
	newthonMethod.solve(gasDetonationSystem, solution);
	
	
	
	return 0;
}

