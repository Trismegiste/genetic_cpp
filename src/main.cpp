#include "AttackStrat.h"
#include "CharacterFactory.h"
#include "FreeEcosystem.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int maxGeneration = 100;
  CharacterFactory factory;
  FreeEcosystem world(22, &factory);

  for (int generation = 0; generation < maxGeneration; generation++) {
    std::cout << "Generation " << generation << std::endl;
    world.evolve(9, 0.01);
  }

  std::cout << "Hello world !" << std::endl;
  std::cout << world.getSize() << std::endl;

  AttackStrat strat(1);
  std::cout << strat << std::endl;
}
