#include "src/NewtonMethod.hpp"

#include <fstream>

#include "src/util.hpp"
#include "src/GasDetonationSystem.hpp"
#include "src/SystemToPlotHugoniotIsentropic.hpp"
#include "src/SystemToPlotShockIsentropic.hpp"
#include "src/ImplicitEulerMethodSystem.hpp"
#include "test/LinearEquationSystem.hpp"
#include "test/NonLinearEquationSystem.hpp"
#include "src/ZeldovichSystem.hpp"
#include "test/TestODESystem.hpp"

template<class System>
NewtonMethod<System>::NewtonMethod() {}

template<class System>
bool NewtonMethod<System>::solve(double* solution) {
	int n = system.getSize();
	bool converged = true;
	A = gsl_matrix_alloc(n, n);
	x = gsl_vector_alloc(n);
	b = gsl_vector_alloc(n);
	gslPermutation = gsl_permutation_alloc(n);
//	std::fstream residualErrorFile;
	
	system.getFirstApproximation(solution);
	
	const double initialResidualError = system.residualError(solution);
//	if(logging) {
//		residualErrorFile.open("residualError.txt", std::ios::out);
//		std::cout << "NewtonMethod: Residual error before iterations: " <<
//			system.residualError(solution) << std::endl;
//		residualErrorFile << system.residualError(solution) / initialResidualError << std::endl;
//	}
	
	const double epsilon = 1e-10 * system.residualError(solution);
	int counter = 0;
	while(system.residualError(solution) > epsilon) {
		doIteration(solution);
//		if(logging) {
//			std::cout << "NewtonMethod: Residual error after next iteration: " <<
//				system.residualError(solution) << std::endl;
//			residualErrorFile << system.residualError(solution) / initialResidualError << std::endl;
//		}
		counter++;
		if (counter > 1000) {
			converged = false;
			break;
		}

	}
	
//	if(converged) std::cout << "The method converged in " << counter << " iterations\n";
//	else std::cout << "The method isn't converged in " << counter << " iterations. Skipped.\n";
//	if(logging) residualErrorFile.close();
	gsl_vector_free(x);
	gsl_vector_free(b);
	gsl_permutation_free(gslPermutation);
	gsl_matrix_free(A);
	return converged;
}

template<class System>
void NewtonMethod<System>::doIteration(double* solution) {
	int n = system.getSize();
	for(int i = 0; i < n; i++)
		gsl_vector_set(b, i, - system.getValue(i, solution));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			gsl_matrix_set(A, i, j, system.getDerivative(i, j, solution));

//	printSLE(A, x, b, n);
	if(logging) checkSLE(A, x, b, n);
	
	gsl_linalg_LU_decomp(A, gslPermutation, &gslSignum);
	gsl_linalg_LU_solve(A, gslPermutation, b, x);
	
	for(int i = 0; i < n; i++) {
		const double deltaU = gsl_vector_get(x, i);
		solution[i] += deltaU / 2;
	}
}


template class NewtonMethod<GasDetonationSystem>;
template class NewtonMethod<SystemToPlotHugoniotIsentropic>;
template class NewtonMethod<SystemToPlotShockIsentropic>;
template class NewtonMethod<LinearEquationSystem>;
template class NewtonMethod<NonLinearEquationSystem>;
template class NewtonMethod<ImplicitEulerMethodSystem<ZeldovichSystem>>;
template class NewtonMethod<ImplicitEulerMethodSystem<TestODESystem>>;
