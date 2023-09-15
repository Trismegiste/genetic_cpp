#include "Character.h"
#include "LevelHeadedEdge.h"
#include "QuickEdge.h"
#include "Skill.h"
#include "AttackStrat.h"
#include "Property.h"

void Character::newGeneration() {
    victory = 0;
}

void Character::restart() {
    wound = 0;
    usedBenny = 0;
    shaken = false;
}

bool Character::isDead() const { 
    return wound > 3; 
}

int Character::getInitiative() {
    int first = static_cast<LevelHeadedEdge*>(genome["levelhead"])->drawCard();
    int init = static_cast<QuickEdge*>(genome["quick"])->retryCard(first);

    return init;
}

int Character::getFitness() const { 
    return victory; 
}

int Character::getToughness() {
    return static_cast<Attribute*>(genome["vigor"])->getDifficulty();
}

bool Character::hasBenny() const {
    return usedBenny < benniesCount;
}

void Character::receiveAttack(MutableFighter *pc) {
    int parry = getParry();
  /* std::vector<int> attacks = pc->getAttack();

    for (int attack : attacks) {
        if (attack >= parry) {
            int damage = pc->getDamage();
            if ((attack - parry) >= 4) {
                damage += DiceRoller::rollExplodingDie(6);
            }
            receiveDamage(damage);
        }
    }   */ 
}

int Character::getParry() {
    return static_cast<Skill*>(genome["fighting"])->getDifficulty() +
        genome["block"]->get() -
        static_cast<AttackStrat*>(genome["attack"])->getBonus();
}
