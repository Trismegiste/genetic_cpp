#ifndef BennyStrat_INCLUDED
#define BennyStrat_INCLUDED

#include "CappedProperty.h"
#include <string>
#include <vector>

class BennyStrat : public CappedProperty {
    public:
        static const std::vector<std::string> choice;

        BennyStrat(int v) : CappedProperty(v, 0, 3){};
        virtual int getCost() const { return 0; };
        virtual std::string toString() const;
        virtual Property* clone() const;
        static int getRandomStrat();
};

#endif