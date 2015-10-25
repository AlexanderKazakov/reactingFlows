#include "src/Mixture.hpp"

void Mixture::setReagents(std::vector<std::pair<std::string, double>> _reagents) {
	for(auto& reagent : _reagents)
		reagents.push_back(std::make_pair(Reagent(reagent.first), reagent.second));
	calcMeanInverseMolarMass();
}

double Mixture::getMeanInverseMolarMass() const {
	return meanInverseMolarMass;
}

void Mixture::calcMeanInverseMolarMass() {
	meanInverseMolarMass = 0;
	for(auto& reagent : reagents)
		meanInverseMolarMass += reagent.second / reagent.first.mu;
}

double Mixture::gamma(const double& T) const {
	double meanCv = 0; // average thermal capacity in units of R
	for(auto& reagent : reagents)
		meanCv += reagent.second * reagent.first.Cv(T) / reagent.first.mu;
	return 1 + R * meanInverseMolarMass / meanCv;
}

double Mixture::gammaDer(const double& T) const {
	double meanCv = 0; // average thermal capacity in units of R
	for(auto& reagent : reagents)
		meanCv += reagent.second * reagent.first.Cv(T) / reagent.first.mu;
	
	double meanCvDer = 0; // average derivative by T of thermal capacity in units of R
	for(auto& reagent : reagents)
		meanCvDer += reagent.second * reagent.first.CvDer(T) / reagent.first.mu;
	
	return - R * meanInverseMolarMass / (meanCv*meanCv) * meanCvDer;
}
