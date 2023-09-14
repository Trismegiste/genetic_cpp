#include "TradeWeaponEdge.h"

TradeWeaponEdge::TradeWeaponEdge(int v) : CappedProperty(v, 0, 2) {
}

int TradeWeaponEdge::getCost() const {
    return 2 * gene; 
}

std::string TradeWeaponEdge::toString() const {
    auto s = std::to_string(gene); return s;
}

Property* TradeWeaponEdge::clone() const {
    return new TradeWeaponEdge(gene);
}