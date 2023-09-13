#ifndef RANDOM_HELPER_INCLUDED
#define RANDOM_HELPER_INCLUDED

#include <cstdlib>

namespace chaos {
    int zeroOrOne() {
        return (std::rand() < (RAND_MAX / 2)) ? 0 : 1;
    }

    int oneOrMinusOne() {
        return (std::rand() < (RAND_MAX / 2)) ? -1 : 1;
    }
}

#endif