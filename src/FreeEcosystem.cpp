#include "FreeEcosystem.h"
#include <cstdlib>

FreeEcosystem::FreeEcosystem(int size, MutableFighterFactory* fac):DarwinWorld(size, fac) {}

void FreeEcosystem::selectPopulation(float extinctRatio) {
}

MutableFighter* FreeEcosystem::battle(MutableFighter* pc1, MutableFighter* pc2) {
    while (!pc1->isDead() && !pc2->isDead()) {
        std::vector<MutableFighter*> player = getInitiativeTurn(pc1, pc2);
        if (!player[0]->isDead()) {
            player[1]->receiveAttack(player[0]);
        }
        if (!player[1]->isDead()) {
            player[0]->receiveAttack(player[1]);
        }
    }

    return pc1->isDead() ? pc2 : pc1;
}

std::vector<MutableFighter*> FreeEcosystem::getInitiativeTurn(MutableFighter* pc1, MutableFighter* pc2) {
    std::vector<MutableFighter*> turn(2);
    int init1 = pc1->getInitiative();
    int init2 = pc2->getInitiative();

    if (init1 == init2) {
        init1 += (std::rand() < (RAND_MAX / 2)) ? 1 : -1;
    }

    if (init1 > init2) {
        turn[0] = pc1;
        turn[1] = pc2;
    } else if (init1 < init2) {
        turn[0] = pc2;
        turn[1] = pc1;
    }

    return turn;
}