#ifndef BlockEdge_INCLUDED
#define BlockEdge_INCLUDED

#include "CappedProperty.h"

class BlockEdge : public CappedProperty {
    public:
        BlockEdge(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
};

#endif