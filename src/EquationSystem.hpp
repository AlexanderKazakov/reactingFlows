#ifndef EQUATIONSYSTEM_HPP
#define	EQUATIONSYSTEM_HPP

/**
 * A base class for system of equations representation.
 * All concrete system should realize its methods.
 * The general view of the system is 
 * \vec{f}(\vec{u}) = \vec{0}.
 * The number of variables is equal to the number of equations.
 */
class EquationSystem {
private:
	/* Size of \vec{f} and \vec{u} */
	const int size;
protected:
	enum IMPLEMENTATION {BASE, GAS_DETONATION, IMPLICIT_EULER_METHOD, PLOT_HUGONIOT_ISENTROPIC, 
			PLOT_SHOCK_ISENTROPIC, ZELDOVICH, LINEAR_EQUATION, NON_LINEAR_EQUATION, TEST_ODE};
	IMPLEMENTATION implementation = IMPLEMENTATION::BASE;
public:
	EquationSystem(const int size);
	int getSize() const;
	/**
	 * The square norm of error
     */
	double residualError(const double* u) const;
	/**
	 * The value of the i-th component of the system function in point u
     * @param i index of \vec{f} component
     * @param u pointer to array of doubles of size == size of the system
     * @return value in point u
     */
	double getValue(const int i, const double* u) const;
	/**
	 * The Jacobian d \vec{f} / d \vec{u}
     * @param i index of string
	 * @param j index of column
     * @param u pointer to array of doubles of size == size of the system
     * @return derivative of i-th component of \vec{f} by j-th component 
	 * of argument vector in point u
     */
	double getDerivative(const int i, const int j, const double* u) const;
	/**
	 * Give some reasonable first approximation for the root of equation
     * @param u pointer to array of doubles of size == size of the system 
	 * to place first approximation in
     */
	void getFirstApproximation(double* u) const;

	void printCompleteSolution(const double* u) const;
};

#endif	/* EQUATIONSYSTEM_HPP */

