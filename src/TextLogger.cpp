#include "TextLogger.h"
#include <iostream>

TextLogger::TextLogger(float ratio) : viewedRatio(ratio) {}

void TextLogger::log(const std::vector<MutableFighter*> &population) const {
    for (size_t idx = 0; idx < (viewedRatio * population.size()); idx++) {
        std::cout << idx << " - " << *(population[idx]) << std::endl;
    }
}
