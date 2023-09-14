#ifndef Skill_INCLUDED
#define Skill_INCLUDED

#include "SaWoTrait.h"
#include "Attribute.h"

class Skill : public SaWoTrait {
    protected:
        const Attribute attribute;
    public:
        Skill(const Attribute& attr, int dice) : SaWoTrait(dice), attribute(attr) {}

        virtual int getCost() const {
            int cost;
            int attr = attribute.get();

            if (get() <= attr) {
                cost = get() / 2 - 2;
            } else {
                cost = attr / 2 - 2 + get() - attr;
            }

            return cost;
        }

        virtual Property* clone() const {            
            return new Skill(attribute, get());
        }
};

#endif