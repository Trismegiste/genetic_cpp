#ifndef DarwinWorld_INCLUDED
#define DarwinWorld_INCLUDED

#include <vector>
#include "MutableFighterFactory.h"
#include "MutableFighter.h"

class DarwinWorld {
    protected:
        std::vector<MutableFighter*> population;
        MutableFighterFactory* factory;

    protected:
        virtual void selectPopulation(float extinctRatio) = 0;

    public:
        DarwinWorld(int size, MutableFighterFactory* fac);
        ~DarwinWorld();
        int getSize() const;
};

#endif