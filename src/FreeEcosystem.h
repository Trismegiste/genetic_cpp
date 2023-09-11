#ifndef FreeEcosystem_INCLUDED
#define FreeEcosystem_INCLUDED

#include "DarwinWorld.h"

class FreeEcosystem : public DarwinWorld {
  
    protected:
        virtual void selectPopulation(float extinctRatio);

    public:
        FreeEcosystem(int size, MutableFighterFactory* fac);

};

#endif