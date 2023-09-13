#ifndef CharacterFactory_INCLUDED
#define CharacterFactory_INCLUDED

#include "MutableFighterFactory.h"

class CharacterFactory : public MutableFighterFactory {
    protected:
        static const std::unordered_map<std::string, int> defaultGenome;

    public:
        virtual MutableFighter* create(std::unordered_map<std::string, int> param);
        virtual MutableFighter* createRandom();
        virtual MutableFighter* createSpawn(std::vector<MutableFighter*> partner);

};

#endif