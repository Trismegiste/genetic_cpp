#include "CharacterFactory.h"
#include "AttackStrat.h"
#include "Character.h"
#include "TradeWeaponEdge.h"
#include <unordered_map>

MutableFighter *
CharacterFactory::create(std::unordered_map<std::string, int> param) {}

MutableFighter *CharacterFactory::createRandom() {
  std::unordered_map<std::string, Property *> param;
  param["trademark"] = new TradeWeaponEdge(1);
  param["attack"] = new AttackStrat(1);

  return new Character(param);
}

MutableFighter *
CharacterFactory::createSpawn(std::vector<MutableFighter *> partner) {}