#ifndef QuickEdge_INCLUDED
#define QuickEdge_INCLUDED

#include "CappedProperty.h"

class QuickEdge : public CappedProperty {
    public:
        QuickEdge(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
        int retryCard(int current) const;
};

#endif