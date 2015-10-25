#include "src/ConstMixture.hpp"

void ConstMixture::setReagents(std::vector<std::pair<std::string, double>> _reagents) {
	for(auto& reagent : _reagents)
		reagents.push_back(std::make_pair(Reagent(reagent.first), reagent.second));
	calcMeanInverseMolarMass();
}

double ConstMixture::getMeanInverseMolarMass() const {
	return meanInverseMolarMass;
}

void ConstMixture::calcMeanInverseMolarMass() {
	meanInverseMolarMass = 0;
	for(auto& reagent : reagents)
		meanInverseMolarMass += reagent.second / reagent.first.mu;
}

double ConstMixture::gamma(const double& T) const {
	return 1.3;
}

double ConstMixture::gammaDer(const double& T) const {
	return 0;
}
