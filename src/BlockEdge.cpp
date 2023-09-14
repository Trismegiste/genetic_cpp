#include "BlockEdge.h"

BlockEdge::BlockEdge(int v) : CappedProperty(v, 0, 2) {
}

int BlockEdge::getCost() const {
    return 2 * gene; 
}

std::string BlockEdge::toString() const {
    auto s = std::to_string(gene);
    return s;
}

Property* BlockEdge::clone() const {
    return new BlockEdge(gene);
}