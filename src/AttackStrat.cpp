#include "AttackStrat.h"

const std::vector<std::string> AttackStrat::choice = {"standard", "wild"};

std::string AttackStrat::toString() const {
    return AttackStrat::choice[gene];
}

Property* AttackStrat::clone() const {
    return new AttackStrat(gene);
}

int AttackStrat::getBonus() const {
    return (gene == 1) ? 2 : 0;
}
