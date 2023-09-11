#include <iostream>
#include "FreeEcosystem.h"
#include "CharacterFactory.h"

int main(int argc, char *argv[])
{
    CharacterFactory factory;
    FreeEcosystem world(42, &factory);

    world.evolve(9, 0.01);

    std::cout << "Hello world !" << std::endl;
    std::cout << world.getSize() << std::endl;

}
