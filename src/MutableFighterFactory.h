#ifndef MutableFighterFactory_INCLUDED
#define MutableFighterFactory_INCLUDED

#include <unordered_map>
#include <string>
#include <vector>
#include "MutableFighter.h"

class MutableFighterFactory {
    public:
        virtual MutableFighter* create(std::unordered_map<std::string, int> param) = 0;
        virtual MutableFighter* createRandom() = 0;
        virtual MutableFighter* createSpawn(std::vector<MutableFighter*> partner) = 0;
};

#endif