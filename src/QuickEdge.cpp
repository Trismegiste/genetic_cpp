#include "QuickEdge.h"
#include "random_helper.h"

QuickEdge::QuickEdge(int v) : CappedProperty(v, 0, 1) {
}

int QuickEdge::getCost() const {
    return 2 * gene; 
}

std::string QuickEdge::toString() const {
    std::string s;
    if (gene == 0) {
        s = "no";
    } else {
        s = "yes";
    }
    return s;
}

Property* QuickEdge::clone() const {
    return new QuickEdge(gene);
}

int QuickEdge::retryCard(int current) const {
    if (gene == 0) {
        return current;
    }

    int retry = 1;
    while (retry < 3) {
        if (current > 20) {
            return current;
        }
        int newcard = chaos::randomRange(1, 54);
        if (newcard > current) {
            current = newcard;
        }
        retry++;
    }

    return current;
}
