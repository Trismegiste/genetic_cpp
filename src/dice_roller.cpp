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

int DiceRoller::roll(const SaWoTrait* trait) {
    return DiceRoller::rollExplodingDie(trait->get());
}

int DiceRoller::rollJoker(const SaWoTrait* trait, int joker) {
    return std::max(DiceRoller::rollExplodingDie(trait->get()), DiceRoller::rollExplodingDie(joker));
}

std::vector<int> DiceRoller::rollJokerRateOfFire(const SaWoTrait* aTrait, int rate, int joker) {
    std::vector<int> pool;
    pool.push_back(DiceRoller::rollExplodingDie(joker));
    for (int k = 0; k < rate; k++) {
        pool.push_back(DiceRoller::rollExplodingDie(aTrait->get()));
    }
    std::sort(pool.begin(), pool.end());  // Triez dans l'ordre croissant
    pool.erase(pool.begin()); // Supprimez le plus petit élément

    return pool;
}