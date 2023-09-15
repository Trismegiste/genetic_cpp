#include "random_helper.h"
#include "dice_roller.h"
#include <algorithm>

int DiceRoller::rollExplodingDie(int face) {
    int sum = 0;
    int d;
    do {
        d = chaos::randomRange(1, face);
        sum += d;
    } while (d == face);

    return sum;
}

int DiceRoller::roll(SaWoTrait* trait) {
    return DiceRoller::rollExplodingDie(trait->get());
}

int DiceRoller::rollJoker(SaWoTrait* trait, int joker = 6) {
    return std::max(DiceRoller::rollExplodingDie(trait->get()), DiceRoller::rollExplodingDie(joker));
}
