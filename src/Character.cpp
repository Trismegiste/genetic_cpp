#include "Character.h"

void Character::newGeneration() { victory = 0; }

int Character::getCost() { return 0; }

void Character::restart() {
  wound = 0;
  usedBenny = 0;
  shaken = false;
}

bool Character::isDead() { return wound > 3; }

void Character::receiveAttack(MutableFighter *pc) { wound++; }

int Character::getInitiative() { return 5; }

int Character::getFitness() { return victory; }