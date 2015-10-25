#include "src/NewthonMethod.hpp"

#include <fstream>

#include "src/util.hpp"

void NewthonMethod::solve(const EquationSystem& system, double* solution) {
	int n = system.getSize();
	previousDelta = new double[n];
	for(int i = 0; i < n; i++) previousDelta[i] = 0;
	A = gsl_matrix_alloc(n, n);
	x = gsl_vector_alloc(n);
	b = gsl_vector_alloc(n);
	gslPermutation = gsl_permutation_alloc(n);
	std::fstream residualErrorFile;
	
	system.getFirstApproximation(solution);
	
	const double initialResidualError = system.residualError(solution);
	if(logging) {
		residualErrorFile.open("residualError.txt", std::ios::out);
		std::cout << "NewthonMethod: Residual error before iterations: " <<
			system.residualError(solution) << std::endl;
		residualErrorFile << system.residualError(solution) / initialResidualError << std::endl;
	}
	
	const double epsilon = 1e-14 * system.residualError(solution);
	int counter = 0;
	while(system.residualError(solution) > epsilon) {
		doIteration(system, solution);
		if(logging) {
			std::cout << "NewthonMethod: Residual error after next iteration: " <<
				system.residualError(solution) << std::endl;
			residualErrorFile << system.residualError(solution) / initialResidualError << std::endl;
		}
		counter++;
	}
	
	std::cout << "The method converged in " << counter << " iterations\n";
	if(logging) residualErrorFile.close();
	//delete [] previousDelta;
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

	//printSLE(A, x, b, n);
	if(logging) checkSLE(A, x, b, n);
	
	gsl_linalg_LU_decomp(A, gslPermutation, &gslSignum);
	gsl_linalg_LU_solve(A, gslPermutation, b, x);
	
	for(int i = 0; i < n; i++) {
		const double deltaU = gsl_vector_get(x, i) / 2;
		solution[i] += deltaU;
		//previousDelta[i] = deltaU;
	}
}

