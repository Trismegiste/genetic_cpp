#include "AttackStrat.h"
#include "CharacterFactory.h"
#include "FreeEcosystem.h"
#include "TextLogger.h"
#include <iostream>
#include <ctime>

int main() {
    int maxGeneration = 3;
    int popSize = 200;
    float extinctRatio = 0.01;
    int battleRound = 9;

    CharacterFactory factory;
    TextLogger logger(extinctRatio);
    FreeEcosystem world(popSize, factory, logger);

    const std::clock_t c_start = std::clock();
    for (int generation = 0; generation < maxGeneration; generation++) {
        std::cout << "==Generation " << generation << "==" << std::endl;
        world.evolve(battleRound, extinctRatio);
    }    
    const std::clock_t c_end = std::clock();
    std::cout << "Chrono=" << 1.0 * (c_end - c_start) / CLOCKS_PER_SEC << std::endl;

    return 0;
}
