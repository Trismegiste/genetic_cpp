#include <iostream>
#include "FreeEcosystem.h"
#include "CharacterFactory.h"

int main(int argc, char *argv[])
{
    int maxGeneration = 100;
    CharacterFactory factory;
    FreeEcosystem world(23, &factory);

    for (int generation = 0; generation < maxGeneration; generation++) {
        world.evolve(9, 0.01);
    }

    std::cout << "Hello world !" << std::endl;
    std::cout << world.getSize() << std::endl;



}
