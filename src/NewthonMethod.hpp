#ifndef NEWTHONMETHOD_HPP
#define	NEWTHONMETHOD_HPP

#include "EquationSystem.hpp"

class NewthonMethod {
public:
	/**
	 * Solve given system of equations using Neuthon's Method
	 * The system must have two first derivatives confined 
	 * and the first drivative must be non-zero.
     * @param system system to solve
     * @param solution pointer to array of doubles of size == size of the system
	 * to place the solution in
     */
	void solve(const EquationSystem& system, double* solution);
private:

};

#endif	/* NEWTHONMETHOD_HPP */

