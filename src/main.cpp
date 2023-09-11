#include <iostream>
#include "FreeEcosystem.h"
#include "CharacterFactory.h"

int main(int argc, char *argv[])
{
    CharacterFactory factory;
    FreeEcosystem world(42, &factory);

    std::cout << "Hello world !" << std::endl;
    std::cout << world.getSize() << std::endl;

}
