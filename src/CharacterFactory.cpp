#include "CharacterFactory.h"
#include "Character.h"

MutableFighter* CharacterFactory::create(std::unordered_map<std::string, int> param) {
}

MutableFighter* CharacterFactory::createRandom() {
    return new Character();
}

MutableFighter* CharacterFactory::createSpawn(std::vector<MutableFighter*> partner) {

}