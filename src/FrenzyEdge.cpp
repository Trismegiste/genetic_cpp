#include "FrenzyEdge.h"

FrenzyEdge::FrenzyEdge(int v) : CappedProperty(v, 0, 2) {
}

int FrenzyEdge::getCost() const {
    return 2 * gene; 
}

std::string FrenzyEdge::toString() const {
    auto s = std::to_string(gene);
    return s;
}

Property* FrenzyEdge::clone() const {
    return new FrenzyEdge(gene);
}