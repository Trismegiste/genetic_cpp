#include "BennyStrat.h"
#include "random_helper.h"

const std::vector<std::string> BennyStrat::choice = {"attack", "soak", "shaken", "damage"};

std::string BennyStrat::toString() const {
    return BennyStrat::choice[gene];
}

int BennyStrat::getRandomStrat() {
    return chaos::randomRange(0, BennyStrat::choice.size() - 1);
}

Property* BennyStrat::clone() const {
    return new BennyStrat(gene);
}