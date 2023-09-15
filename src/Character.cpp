#include "Character.h"
#include "LevelHeadedEdge.h"
#include "QuickEdge.h"
#include "Skill.h"
#include "AttackStrat.h"
#include "Property.h"
#include "BennyStrat.h"

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

bool Character::isShaken() const {
    return shaken;
}

void Character::useBenny() {
    if (!hasBenny()) {
        throw std::runtime_error("No more benny to use");
    }
    usedBenny++;
}

void Character::tryUnshake() {
    int unshake = rollTrait("spirit");
    if (unshake >= 4) {
        shaken = false;
        return;
    }

    if ((genome["benny"]->get() == BennyStrat::SHAKEN_STRAT) && (hasBenny())) {
        shaken = false;
        useBenny();
    }
}

int Character::rollTrait(std::string trait) const {

}
