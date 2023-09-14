#ifndef NerveOfSteelEdge_INCLUDED
#define NerveOfSteelEdge_INCLUDED

#include "CappedProperty.h"

class NerveOfSteelEdge : public CappedProperty {
    public:
        NerveOfSteelEdge(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
};

#endif