#include "DarwinWorld.h"

DarwinWorld::DarwinWorld(int size, MutableFighterFactory* fac): factory(fac) {
    for(int k=0; k<size; k++) {
        population.push_back(fac->createRandom());
    }
}

int DarwinWorld::getSize() const {
    return population.size();
}

DarwinWorld::~DarwinWorld() {
    for(int k=0; k<getSize(); k++) {
        delete population[k];
    }
}