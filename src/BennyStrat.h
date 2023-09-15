#ifndef BennyStrat_INCLUDED
#define BennyStrat_INCLUDED

#include "CappedProperty.h"
#include <string>
#include <vector>

class BennyStrat : public CappedProperty {
    public:
        static const std::vector<std::string> choice;
        static const int SHAKEN_STRAT = 2;
        static const int ATTACK_STRAT = 0;

        BennyStrat(int v) : CappedProperty(v, 0, 3){};
        virtual int getCost() const { return 0; };
        virtual std::string toString() const;
        virtual Property* clone() const;
        static int getRandomStrat();
};

#endif