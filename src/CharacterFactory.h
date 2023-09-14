#ifndef CharacterFactory_INCLUDED
#define CharacterFactory_INCLUDED

#include "MutableFighterFactory.h"

class CharacterFactory : public MutableFighterFactory {
    protected:
        static const std::unordered_map<std::string, int> defaultGenome;

    public:
        virtual MutableFighter* create(std::unordered_map<std::string, int> param) const;
        virtual MutableFighter* createRandom() const;
        virtual MutableFighter* createSpawn(const std::vector<MutableFighter*>& partner) const;

};

#endif