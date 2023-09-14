#include "NerveOfSteelEdge.h"

NerveOfSteelEdge::NerveOfSteelEdge(int v) : CappedProperty(v, 0, 2) {
}

int NerveOfSteelEdge::getCost() const {
    return 2 * gene; 
}

std::string NerveOfSteelEdge::toString() const {
    auto s = std::to_string(gene);
    return s;
}

Property* NerveOfSteelEdge::clone() const {
    return new NerveOfSteelEdge(gene);
}