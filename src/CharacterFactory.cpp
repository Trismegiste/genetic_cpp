#include "CharacterFactory.h"
#include "AttackStrat.h"
#include "Character.h"
#include "TradeWeaponEdge.h"
#include <unordered_map>
#include "random_helper.h"

const std::unordered_map<std::string, int> CharacterFactory::defaultGenome = {{"attack",0},{"trademark",0}};

MutableFighter *
CharacterFactory::create(std::unordered_map<std::string, int> param)  const {
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

MutableFighter *CharacterFactory::createRandom() const {
  std::unordered_map<std::string, int> param = {
    {"attack", chaos::randomRange(0, 1)},
    {"trademark", chaos::randomRange(0, 2)}
  };

  return create(param);
}

MutableFighter* CharacterFactory::createSpawn(const std::vector<MutableFighter*>& partner) const {
  int numPartners = partner.size();
  std::unordered_map<std::string, Property*> crossed;

  // Sélectionner au hasard des propriétés de partenaires
  for (const auto& entry : CharacterFactory::defaultGenome) {
      int choice = chaos::randomRange(0, numPartners - 1);
      crossed[entry.first] = partner[choice]->getGenome().at(entry.first)->clone();
  }

  return new Character(crossed);
}
