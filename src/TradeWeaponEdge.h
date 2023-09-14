#ifndef TradeWeaponEdge_INCLUDED
#define TradeWeaponEdge_INCLUDED
#include "CappedProperty.h"

class TradeWeaponEdge : public CappedProperty {
    public:
        TradeWeaponEdge(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
};

#endif