#include "random_helper.h"

int chaos::zeroOrOne() {
    return (std::rand() < (RAND_MAX / 2)) ? 0 : 1;
}

int chaos::oneOrMinusOne() {
    return (std::rand() < (RAND_MAX / 2)) ? -1 : 1;
}

int chaos::randomRange(int min, int includedMax) {
    return (int) ((float) std::rand() / RAND_MAX * (includedMax - min + 1)) + min;
}