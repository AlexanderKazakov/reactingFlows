#include <cstdlib>
#include <iostream>

#include "src/NewthonMethod.hpp"
#include "test/LinearEquationSystem.hpp"
#include "test/NonLinearEquationSystem.hpp"

using namespace std;

/*
 * Test for NewthonMethod
 */

int main(int argc, char** argv) {
	NewthonMethod newthonMethod;
	
	std::cout << "Testing on system of linear equations: \n";
	LinearEquationSystem linearEquationSystem;
	double* solution = new double[linearEquationSystem.getSize()];
	newthonMethod.solve(linearEquationSystem, solution);
	std::cout << "Find root: ";
	for(int i = 0; i < linearEquationSystem.getSize(); i++)
		std::cout << solution[i] << "\t";
	std::cout << "\n\n\n";
	
	std::cout << "Testing on non-linear system: \n";
	NonLinearEquationSystem nonLinearEquationSystem;
	double* solution2 = new double[nonLinearEquationSystem.getSize()];
	newthonMethod.solve(nonLinearEquationSystem, solution2);
	std::cout << "Find root: ";
	for(int i = 0; i < nonLinearEquationSystem.getSize(); i++)
		std::cout << solution2[i] << "\t";
	std::cout << "\n";
	
	delete [] solution;
	delete [] solution2;
	return 0;
}

