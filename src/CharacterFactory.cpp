#include "CharacterFactory.h"
#include "AttackStrat.h"
#include "Character.h"
#include "TradeWeaponEdge.h"
#include "Attribute.h"
#include "Skill.h"
#include "BennyStrat.h"
#include <unordered_map>
#include "random_helper.h"

const std::unordered_map<std::string, int> CharacterFactory::defaultGenome = {
    {"attack", 0},
    {"trademark", 0},
    {"agility", 6},
    {"vigor", 6},
    {"strength", 6},
    {"spirit", 6},
    {"fighting", 6},
    {"benny", 0}
};

MutableFighter *
CharacterFactory::create(std::unordered_map<std::string, int> param)  const {
    std::unordered_map<std::string, int> defaultParam = CharacterFactory::defaultGenome;

    for(auto override : param) {
        defaultParam[override.first] = override.second;
    }

    Attribute* agility = new Attribute(defaultParam["agility"]);
    std::unordered_map<std::string, Property *> genome = {
        {"attack", new AttackStrat(defaultParam["attack"])},
        {"trademark", new TradeWeaponEdge(defaultParam["trademark"])},
        {"agility", agility},
        {"fighting", new Skill(*agility, defaultParam["fighting"])},
        {"vigor", new Attribute(defaultParam["vigor"])},
        {"strength", new Attribute(defaultParam["strength"])},        
        {"spirit", new Attribute(defaultParam["spirit"])},
        {"benny", new BennyStrat(defaultParam["benny"])}
    };

    return new Character(genome);
}

MutableFighter *CharacterFactory::createRandom() const {
    std::unordered_map<std::string, int> param = {
        {"attack", chaos::randomRange(0, 1)},
        {"trademark", chaos::randomRange(0, 2)},
        {"agility", 4 + 2 * chaos::randomRange(0, 4)},
        {"fighting", 4 + 2 * chaos::randomRange(0, 4)},
        {"vigor", 4 + 2 * chaos::randomRange(0, 4)},
        {"strength", 4 + 2 * chaos::randomRange(0, 4)},
        {"spirit", 4 + 2 * chaos::randomRange(0, 4)},
        {"benny", BennyStrat::getRandomStrat()}
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
