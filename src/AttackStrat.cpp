#include "AttackStrat.h"

const std::vector<std::string> AttackStrat::choice = {"standard", "wild"};

std::string AttackStrat::toString() const {
    return AttackStrat::choice[gene];
}