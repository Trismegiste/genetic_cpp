#ifndef Attribute_INCLUDED
#define Attribute_INCLUDED

#include "SaWoTrait.h"

class Attribute : public SaWoTrait {
    public:
        Attribute(int dice) : SaWoTrait(dice) {}

        virtual int getCost() const {
            return gene * 2;
        }

        virtual Property* clone() const {
            return new Attribute(get());
        }
};

#endif