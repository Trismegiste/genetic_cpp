#include "Skill.h"

Skill::Skill(const Attribute& attr, int dice) : SaWoTrait(dice), attribute(attr) {
}

int Skill::getCost() const {
    int cost;
    int attr = attribute.get();

    if (get() <= attr) {
        cost = get() / 2 - 2;
    } else {
        cost = attr / 2 - 2 + get() - attr;
    }

    return cost;
}

Property* Skill::clone() const {            
    return new Skill(attribute, get());
}
