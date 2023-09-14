#include "MutableFighter.h"
#include "random_helper.h"

void MutableFighter::incVictory() {
    victory++;
}

int MutableFighter::getVictory() const {
    return victory;
}

MutableFighter::MutableFighter(std::unordered_map<std::string, Property*> param): genome(param) {
}

MutableFighter::~MutableFighter() {
     for (auto& [key, value]: genome) { 
        delete value;
    }
}

int MutableFighter::getCost() const {
    int cost = 0;
    for (const auto& [key, gene] : genome) {
        cost += gene->getCost();
    }
    return cost;
}

void MutableFighter::mutate() {
    int pick = chaos::randomRange(0, genome.size() - 1);
    auto it = genome.begin();
    std::advance(it, pick);
    it->second->mutate();
}

const std::unordered_map<std::string, Property *>& MutableFighter::getGenome() const {
    return genome;
}