#include <cstdlib>
#include <iostream>

#include "src/NewtonMethod.hpp"
#include "test/LinearEquationSystem.hpp"
#include "test/NonLinearEquationSystem.hpp"

#include "src/ImplicitEulerMethod.hpp"
#include "test/TestODESystem.hpp"

using namespace std;

/**
 * Test for implicit Euler method
 */
int testTask2(int argc, char** argv) {
	std::cout << "Testing ImplicitEulerMethod:" << std::endl;
	ImplicitEulerMethod implicitEulerMethod(new TestODESystem(), 0.05, 1.0);
	implicitEulerMethod.calculate();
	return 0;
}


/*
 * Test for NewtonMethod
 */
int testTask1(int argc, char** argv) {
	NewtonMethod newtonMethod;
//	newtonMethod.logging = true;
	
	std::cout << "Testing on system of linear equations: \n";
	LinearEquationSystem linearEquationSystem;
	double* solution = new double[linearEquationSystem.getSize()];
	newtonMethod.solve(linearEquationSystem, solution);
	std::cout << "Find root: ";
	for(int i = 0; i < linearEquationSystem.getSize(); i++)
		std::cout << solution[i] << "\t";
	std::cout << "\n\n\n";
	
	std::cout << "Testing on non-linear system: \n";
	NonLinearEquationSystem nonLinearEquationSystem;
	double* solution2 = new double[nonLinearEquationSystem.getSize()];
	newtonMethod.solve(nonLinearEquationSystem, solution2);
	std::cout << "Find root: ";
	for(int i = 0; i < nonLinearEquationSystem.getSize(); i++)
		std::cout << solution2[i] << "\t";
	std::cout << "\n";
	
	delete [] solution;
	delete [] solution2;
	return 0;
}


int main(int argc, char** argv) {
	testTask1(argc, argv);
	testTask2(argc, argv);
}