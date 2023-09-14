#ifndef FrenzyEdge_INCLUDED
#define FrenzyEdge_INCLUDED

#include "CappedProperty.h"

class FrenzyEdge : public CappedProperty {
    public:
        FrenzyEdge(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
};

#endif