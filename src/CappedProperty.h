#ifndef CappedProperty_INCLUDED
#define CappedProperty_INCLUDED
#include "Property.h"

class CappedProperty : public Property {
    protected:
        int minValue;
        int maxValue;
    public:
        CappedProperty(int v, int inf, int sup);
        virtual void mutate();
};

#endif