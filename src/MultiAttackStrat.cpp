#include "MultiAttackStrat.h"

MultiAttackStrat::MultiAttackStrat(int v) : CappedProperty(v, 1, 3) {
}

int MultiAttackStrat::getCost() const {
    return 0; 
}

std::string MultiAttackStrat::toString() const {
    auto s = std::to_string(gene);
    return s;
}

Property* MultiAttackStrat::clone() const {
    return new MultiAttackStrat(gene);
}