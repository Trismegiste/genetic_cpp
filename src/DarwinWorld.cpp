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

void DarwinWorld::evolve(int round, float extinctRatio) {
    // re-initialise pop
    for(auto const& pc: population) {
        pc->newGeneration();
    }
/*
    $this->tournament($round);

    usort($this->population, function ($a, $b) {
        return $b->getFitness() - $a->getFitness();
    });

    $this->selectPopulation($extinctRatio);

    $this->logger->log($this->population);*/
}