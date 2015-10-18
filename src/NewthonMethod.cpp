#include "src/NewthonMethod.hpp"

#include <iostream>

void NewthonMethod::solve(const EquationSystem& system, double* solution) {
	int n = system.getSize();
	A = gsl_matrix_alloc(n, n);
	x = gsl_vector_alloc(n);
	b = gsl_vector_alloc(n);
	gslPermutation = gsl_permutation_alloc(n);
	
	system.getFirstApproximation(solution);
	
	std::cout << "NewthonMethod: Residual error before iterations: " <<
		system.residualError(solution) << std::endl;
	std::cout << "NewthonMethod: Roots: ";
	for(int i = 0; i < system.getSize(); i++)
		std::cout << solution[i] << "\t";
	std::cout << "\n";
	while(system.residualError(solution) > 0.1) {
		doIteration(system, solution);
		std::cout << "NewthonMethod: Residual error after next iteration: " <<
			system.residualError(solution) << std::endl;
		std::cout << "NewthonMethod: Roots: ";
		for(int i = 0; i < system.getSize(); i++)
			std::cout << solution[i] << "\t";
		std::cout << "\n";
	}

	gsl_vector_free(x);
	gsl_vector_free(b);
	gsl_permutation_free(gslPermutation);
	gsl_matrix_free(A);
}

void NewthonMethod::doIteration(const EquationSystem& system, double* solution) {
	int n = system.getSize();
	for(int i = 0; i < n; i++)
		gsl_vector_set(b, i, - system.getValue(i, solution));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			gsl_matrix_set(A, i, j, system.getDerivative(i, j, solution));

	gsl_linalg_LU_decomp(A, gslPermutation, &gslSignum);
	gsl_linalg_LU_solve(A, gslPermutation, b, x);
	
	for(int i = 0; i < n; i++)
		solution[i] += gsl_vector_get(x, i) / 2;
}

