#include "src/Reagent.hpp"

/**
 * The task is reaction number 2 with Cv correlation from table 1
 * @param name name of reagent
 */
Reagent::Reagent(const std::string name) : name(name) {
	
	if (name == "C2H2") {
		mu = 26e-3;
		a = {1.598133250e05, -2.216675050e03, 1.265725610e01, -7.980170140e-03,
		     8.055801510e-06, -2.433944610e-09, -7.509454610e-14};
		b = {1.713792120e06, -5.928970950e03, 1.236115640e01, 1.314706250e-04,
		     -1.362869040e-07, 2.712746060e-11, -1.302086850e-15};
	}
	
	else if (name == "O2") {
		mu = 32e-3;
		a = {-3.425563420e04, 4.847000970e02, 1.119010961, 4.293889240e-03,
		     -6.836300520e-07, -2.023372700e-09, 1.039040018e-12};
		b = {-1.037939022e06, 2.344830282e03, 1.819732036, 1.267847582e-03,
		     -2.188067988e-07, 2.053719572e-11, -8.193467050e-16};
	}
	
	else if (name == "N2") {
		mu = 28e-3;
		a = {2.210371497e04, -3.818461820e02, 6.082738360, -8.530914410e-03, 
		     1.384646189e-05, -9.625793620e-09, 2.519705809e-12};
		b = {5.877124060e05, -2.239249073e03, 6.066949220, -6.139685500e-04,
		     1.491806679e-07, -1.923105485e-11, 1.061954386e-15};
	}
	
	else if (name == "CO2") {
		mu = 44e-3;
		a = {4.943783640e04, -6.264292080e02, 5.301813360, 2.503600571e-03,
		     -2.124700099e-07, -7.691486800e-10, 2.849979913e-13};
		b = {1.176969434e05, -1.788801467e03, 8.291543530, -9.224778310e-05,
		     4.869635410e-09, -1.892063841e-12, 6.330675090e-16};
	}
	
	else if (name == "H2O") {
		mu = 18e-3;
		a = {-3.947960830e04, 5.755731020e02, 9.317826530e-01, 7.222712860e-03,
		     -7.342557370e-06, 4.955043490e-09, -1.336933246e-12};
		b = {1.034972096e06, -2.412698562e03, 4.646110780, 2.291998307e-03,
		     -6.836830480e-07, 9.426468930e-11, -4.822380530e-15};
	}
	
	else {
		throw -3;
	}

}

double Reagent::Cv(const double& T) const {
	double ans = - 1.0;
	
	if ( T <= 1e+3 )
		for(uint i = 0; i < a.size(); i++)
			ans += a[i] * pow(T, i-2);
	
	else
		for(uint i = 0; i < b.size(); i++)
			ans += b[i] * pow(T, i-2);
	
	return ans;
}

double Reagent::CvDer(const double& T) const {
	double ans = 0.0;
	
	if ( T <= 1e+3 )
		for(uint i = 0; i < a.size(); i++)
			ans += (i-2) * a[i] * pow(T, i-3);
	
	else
		for(uint i = 0; i < b.size(); i++)
			ans += (i-2) * b[i] * pow(T, i-3);
	
	return ans;
}

double Reagent::pow(const double& base, const int exponent) const {
	if(exponent < 0) return 1.0 / pow(base, -exponent);
	if(exponent == 0) return 1;
	return base * pow(base, exponent - 1);
}

