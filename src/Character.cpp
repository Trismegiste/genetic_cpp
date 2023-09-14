#include "Character.h"
#include "LevelHeadedEdge.h"
#include "QuickEdge.h"

void Character::newGeneration() {
    victory = 0;
}

void Character::restart() {
    wound = 0;
    usedBenny = 0;
    shaken = false;
}

bool Character::isDead() const { return wound > 3; }

void Character::receiveAttack(MutableFighter *pc) { wound++; }

int Character::getInitiative() {
    int first = static_cast<LevelHeadedEdge*>(genome["levelhead"])->drawCard();
    int init = static_cast<QuickEdge*>(genome["quick"])->retryCard(first);

    return init;
}

int Character::getFitness() const { return victory; }