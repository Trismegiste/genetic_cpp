#include "AttackStrat.h"
#include "CharacterFactory.h"
#include "FreeEcosystem.h"
#include "TextLogger.h"
#include <iostream>

int main() {
  int maxGeneration = 100;
  int popSize = 1000;
  float extinctRatio = 0.01;
  int battleRound = 9;

  CharacterFactory factory;
  TextLogger logger(extinctRatio);
  FreeEcosystem world(popSize, factory, logger);

  for (int generation = 0; generation < maxGeneration; generation++) {
    std::cout << "==Generation " << generation << "==" << std::endl;
    world.evolve(battleRound, extinctRatio);
  }

  return 0;
}
