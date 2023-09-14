#include "LevelHeadedEdge.h"
#include "random_helper.h"

LevelHeadedEdge::LevelHeadedEdge(int v) : CappedProperty(v, 0, 2) {
}

int LevelHeadedEdge::getCost() const {
    return 2 * gene; 
}

std::string LevelHeadedEdge::toString() const {
    auto s = std::to_string(gene);
    return s;
}

Property* LevelHeadedEdge::clone() const {
    return new LevelHeadedEdge(gene);
}

int LevelHeadedEdge::drawCard() const {
    int keep = 0;

    for(int k = 0; k <= gene; k++) { // one or two more than the default card, therefore "<="
        int draw = chaos::randomRange(1, 54);
        if (draw > keep) {
            keep = draw;
        }
    }

    return keep;
}
