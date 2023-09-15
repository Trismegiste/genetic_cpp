#ifndef DICE_ROLLER_INCLUDED
#define DICE_ROLLER_INCLUDED

#include "SaWoTrait.h"

namespace DiceRoller {
    int rollExplodingDie(int face);
    int roll(SaWoTrait* trait);
    int rollJoker(SaWoTrait* trait, int joker);
}

#endif