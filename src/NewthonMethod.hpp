#ifndef NEWTHONMETHOD_HPP
#define	NEWTHONMETHOD_HPP

#include <gsl/gsl_linalg.h>

#include "src/EquationSystem.hpp"

class NewthonMethod {
public:
	bool logging = false;

	/**
	 * Solve given system of equations using Neuthon's Method
	 * The system must have two first derivatives confined 
	 * and the first derivative must be non-zero.
     * @param system system to solve
     * @param solution pointer to array of doubles of size == size of the system
	 * to place the solution in
     */
	void solve(const EquationSystem& system, double* solution);
private:
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
	void doIteration(const EquationSystem& system, double* solution);

};

#endif	/* NEWTHONMETHOD_HPP */

