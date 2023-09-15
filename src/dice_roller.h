#ifndef DICE_ROLLER_INCLUDED
#define DICE_ROLLER_INCLUDED

#include "SaWoTrait.h"
#include <vector>

namespace DiceRoller {
    int rollExplodingDie(int face);
    int roll(const SaWoTrait* trait);
    int rollJoker(const SaWoTrait* trait, int joker = 6);
    std::vector<int> rollJokerRateOfFire(const SaWoTrait* aTrait, int rate = 1, int joker = 6);

}

#endif