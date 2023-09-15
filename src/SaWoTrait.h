#ifndef SaWoTrait_INCLUDED
#define SaWoTrait_INCLUDED

#include "CappedProperty.h"

class SaWoTrait : public CappedProperty {
    public:
        SaWoTrait(int dice);
        virtual int get() const;
        virtual std::string toString() const;
        virtual int getDifficulty() const;
};

#endif