#ifndef RANDOM_HELPER_INCLUDED
#define RANDOM_HELPER_INCLUDED

#include <cstdlib>

namespace chaos {
    int zeroOrOne();
    int oneOrMinusOne();
    int randomRange(int min, int includedMax);
}

#endif