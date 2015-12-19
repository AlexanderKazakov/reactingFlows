#ifndef NEWTONMETHOD_HPP
#define	NEWTONMETHOD_HPP

#include <gsl/gsl_linalg.h>

#include "src/EquationSystem.hpp"

template<class System>
class NewtonMethod {
public:
	NewtonMethod();
	bool logging = false;

	/**
	 * Solve given system of equations using Neuton's Method
	 * The system must have two first derivatives confined 
	 * and the first derivative must be non-zero.
     * @param solution pointer to array of doubles of size == size of the system
	 * to place the solution in
	 * @return is method converged in 1000 iterations
     */
	bool solve(double* solution);
private:
	System system;
	/* Jacobian of the system */
	gsl_matrix *A;
	/* Minus value of system function */
	gsl_vector *b;
	/* Correction of the solution on some iteration */
	gsl_vector *x;
	/* For gsl purposes */
	gsl_permutation *gslPermutation;
	int gslSignum;
	
	/* to store step on previous iteration */
	double *previousDelta;
	
	/**
	 * Do next iteration
     */
	void doIteration(double* solution);

};

#endif	/* NEWTONMETHOD_HPP */

