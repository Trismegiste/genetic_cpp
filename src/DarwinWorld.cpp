#include "DarwinWorld.h"
#include <iostream>
#include <unordered_map>
#include <algorithm>

DarwinWorld::DarwinWorld(int size, const MutableFighterFactory& fac, const PopulationLogger& popLogger) : factory(fac), logger(popLogger) {
  for (int k = 0; k < size; k++) {
    population.push_back(fac.createRandom());
  }
}

int DarwinWorld::getSize() const { return population.size(); }

DarwinWorld::~DarwinWorld() {
  for (int k = 0; k < getSize(); k++) {
    delete population[k];
  }
}

void DarwinWorld::evolve(int round, float extinctRatio) {
  // re-initialise pop
  for (auto const &pc : population) {
    pc->newGeneration();
  }

  tournament(round);

  std::sort( population.begin(), population.end(), [](const auto& lhs, const auto& rhs)
  {
    return lhs->getFitness() > rhs->getFitness();
  });
  
  selectPopulation(extinctRatio);

  logger.log(population);
}

void DarwinWorld::tournament(int round) {
  for (size_t idx1 = 0; idx1 != population.size(); idx1++) {
    for (size_t idx2 = 0; idx2 != population.size(); idx2++) {
      if (idx2 > idx1) {
        evaluateBestFighter(round, population[idx1], population[idx2]);
      }
    }
  }
}

void DarwinWorld::evaluateBestFighter(int round, MutableFighter *pc1,
                                      MutableFighter *pc2) {
  int delta = pc1->getCost() - pc2->getCost();
  std::unordered_map<MutableFighter *, int> win;
  win[pc1] = 0;
  win[pc2] = 0;

  for (int k = 0; k < round; k++) {
    pc1->restart();
    pc2->restart();
    MutableFighter *winner = battle(pc1, pc2);
    win[winner]++;
  }

  if ((win[pc1] > win[pc2]) && (delta <= 0)) {
    pc1->incVictory();
  }
  if ((win[pc1] < win[pc2]) && (delta >= 0)) {
    pc2->incVictory();
  }
}

void DarwinWorld::selectPopulation(float extinctRatio) {
  int extinctCount = static_cast<int>(extinctRatio * getSize());
  std::vector<MutableFighter*> best(population.begin(), population.begin() + extinctCount);

  for (int idx = getSize() - extinctCount; idx < getSize(); idx++) {
      MutableFighter* child = factory.createSpawn(best);
      child->mutate();
      delete population[idx];
      population[idx] = child;
  }
}