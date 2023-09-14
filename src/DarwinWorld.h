#ifndef DarwinWorld_INCLUDED
#define DarwinWorld_INCLUDED

#include <vector>
#include "MutableFighterFactory.h"
#include "MutableFighter.h"
#include "PopulationLogger.h"

class DarwinWorld {
    protected:
        std::vector<MutableFighter*> population;
        const MutableFighterFactory& factory;
        const PopulationLogger& logger;

    protected:
        virtual void selectPopulation(float extinctRatio) = 0;
        void tournament(int round);
        void evaluateBestFighter(int round, MutableFighter* pc1, MutableFighter* pc2);
        virtual MutableFighter* battle(MutableFighter* pc1, MutableFighter* pc2) = 0;
        virtual std::vector<MutableFighter*> getInitiativeTurn(MutableFighter* pc1, MutableFighter* pc2) = 0;

    public:
        DarwinWorld(int size, const MutableFighterFactory& fac, const PopulationLogger& popLogger);
        ~DarwinWorld();
        int getSize() const;
        virtual void evolve(int round, float extinctRatio);

};

#endif