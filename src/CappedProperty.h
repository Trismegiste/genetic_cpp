#ifndef CappedProperty_INCLUDED
#define CappedProperty_INCLUDED
#include "Property.h"

class CappedProperty : public Property {
    protected:
        int attribute;
        int minValue;
        int maxValue;
    public:
        CappedProperty(int v, int inf, int sup);
        virtual int get();
        virtual void mutate();
};

#endif