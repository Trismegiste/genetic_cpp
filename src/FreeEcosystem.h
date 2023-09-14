#ifndef FreeEcosystem_INCLUDED
#define FreeEcosystem_INCLUDED

#include "DarwinWorld.h"

class FreeEcosystem : public DarwinWorld {
  
    protected:
        virtual MutableFighter* battle(MutableFighter* pc1, MutableFighter* pc2);
        virtual std::vector<MutableFighter*> getInitiativeTurn(MutableFighter* pc1, MutableFighter* pc2);

    public:
        FreeEcosystem(int size, const MutableFighterFactory& fac, const PopulationLogger& popLogger);

};

#endif