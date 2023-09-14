#ifndef MultiAttackStrat_INCLUDED
#define MultiAttackStrat_INCLUDED

#include "CappedProperty.h"

class MultiAttackStrat : public CappedProperty {
    public:
        MultiAttackStrat(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
};

#endif