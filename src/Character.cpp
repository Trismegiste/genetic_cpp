#include "Character.h"
#include "LevelHeadedEdge.h"
#include "QuickEdge.h"
#include "Skill.h"
#include "AttackStrat.h"
#include "Property.h"
#include "BennyStrat.h"
#include "dice_roller.h"
#include "MultiAttackStrat.h"
#include <algorithm>

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
    std::vector<int> attacks = static_cast<Character*>(pc)->getAttack();
/*
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

    if ((genome["benny"]->get() == BennyStrat::SHAKEN_STRAT) && hasBenny()) {
        shaken = false;
        useBenny();
    }
}

int Character::rollTrait(const std::string& trait) {
    return DiceRoller::rollJoker(static_cast<SaWoTrait*>(genome[trait])) + getWoundsPenalty();    
}

int Character::getWoundsPenalty() {
    int ignore = genome["nervesteel"]->get();
    int effectiveWound = (wound > ignore) ? (wound - ignore) : 0;

    return -effectiveWound;
}

std::vector<int> Character::getAttack() {
    if (isShaken()) {
        tryUnshake();
    }
    if (isShaken()) {
        return {0};
    }

    int nb = genome["multiattack"]->get();
    int rofEdge = genome["frenzy"]->get();
    int rof = rofEdge;
    std::vector<int> roll;
    for (int k = 0; k < nb; k++) {
        if (rof == 0) {
            roll.push_back(getOneAttack());
        } else {
            std::vector<int> rateOfFireRoll = getOneAttackRateOfFire(rofEdge);
            roll.insert(roll.end(), rateOfFireRoll.begin(), rateOfFireRoll.end());
            rof--;
        }
    }

    return roll;
}

int Character::getOneAttack() {
    int roll = rollFighting();
    if ((roll < 4) && (genome["benny"]->get() == BennyStrat::ATTACK_STRAT) && hasBenny()) {
        roll = rollFighting();
        useBenny();
    }

    return roll;
}

std::vector<int> Character::getOneAttackRateOfFire(int rateOfFire) {
    std::vector<int> roll = rollFightingRateOfFire(rateOfFire);

    if ((*std::max_element(roll.begin(), roll.end()) < 4) && (genome["benny"]->get() == BennyStrat::ATTACK_STRAT) && hasBenny()) {
        roll = rollFightingRateOfFire(rateOfFire);
        useBenny();
    }

    return roll;
}

int Character::rollFighting() {
    return rollTrait("fighting") +
        genome["trademark"]->get() +
        static_cast<AttackStrat*>(genome["attack"])->getBonus() +
        static_cast<MultiAttackStrat*>(genome["multiattack"])->getPenalty();
}

std::vector<int> Character::rollFightingRateOfFire(int rateOfFire) {
    std::vector<int> pool = DiceRoller::rollJokerRateOfFire(static_cast<SaWoTrait*>(genome["fighting"]), rateOfFire);

    for (int& value : pool) {
        value += getWoundsPenalty() +
            genome["trademark"]->get() +
            static_cast<AttackStrat*>(genome["attack"])->getBonus() +
            static_cast<MultiAttackStrat*>(genome["multiattack"])->getPenalty();
    }

    return pool;
}
