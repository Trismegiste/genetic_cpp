#ifndef MutableFighterFactory_INCLUDED
#define MutableFighterFactory_INCLUDED

#include <unordered_map>
#include <string>
#include <vector>
#include "MutableFighter.h"

class MutableFighterFactory {
    public:
        virtual MutableFighter* create(std::unordered_map<std::string, int> param) const = 0;
        virtual MutableFighter* createRandom() const  = 0;
        virtual MutableFighter* createSpawn(const std::vector<MutableFighter*>& partner) const = 0;
};

#endif