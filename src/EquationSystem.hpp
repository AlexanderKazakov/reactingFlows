#ifndef EQUATIONSYSTEM_HPP
#define	EQUATIONSYSTEM_HPP

/**
 * An abstract class for system of equations representation.
 * All concrete system should derived from it.
 * The general view of the system is 
 * \vec{f}(\vec{u}) = \vec{0}.
 * The number of variables is equal to the number of equations.
 */
class EquationSystem {
public:
	EquationSystem(const int size);
	
private:
	/* Size of \vec{f} and \vec{u} */
	const int size;
	/**
	 * The value of the i-th component of the system function in point u
     * @param i index of \vec{f} component
     * @param u pointer to array of doubles of size == size of the system
     * @return value in point u
     */
	virtual double getValue(const int i, const double* u) const = 0;
	/**
	 * The Jacobian d \vec{f} / d \vec{u}
     * @param i index of string
	 * @param j index of column
     * @param u pointer to array of doubles of size == size of the system
     * @return derivative of i-th component of \vec{f} by j-th component 
	 * of argument vector in point u
     */
	virtual double getDerivative(const int i, const int j, 
	                             const double* u) const = 0;
};

#endif	/* EQUATIONSYSTEM_HPP */

