#ifndef TradeWeaponEdge_INCLUDED
#define TradeWeaponEdge_INCLUDED
#include "CappedProperty.h"

class TradeWeaponEdge : public CappedProperty {
    public:
        TradeWeaponEdge(int v): CappedProperty(v, 0, 2) {}
        virtual int getCost() { return 2*attribute; }
};

#endif