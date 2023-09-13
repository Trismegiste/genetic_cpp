#include "CharacterFactory.h"
#include "AttackStrat.h"
#include "Character.h"
#include "TradeWeaponEdge.h"
#include <unordered_map>

const std::unordered_map<std::string, int> CharacterFactory::defaultGenome = {{"attack",0},{"trademark",0}};

MutableFighter *
CharacterFactory::create(std::unordered_map<std::string, int> param) {
  std::unordered_map<std::string, int> defaultParam = CharacterFactory::defaultGenome;
  for(auto override : param) {
    defaultParam[override.first] = override.second;
  }

  std::unordered_map<std::string, Property *> genome = {
    {"attack", new AttackStrat(defaultParam["attack"])},
    {"trademark", new TradeWeaponEdge(defaultParam["trademark"])}
  };

  return new Character(genome);
}

MutableFighter *CharacterFactory::createRandom() {
  std::unordered_map<std::string, int> param = {
    {"attack", 1},
    {"trademark", 1}
  };

  return create(param);
}

MutableFighter *
CharacterFactory::createSpawn(std::vector<MutableFighter *> partner) {}