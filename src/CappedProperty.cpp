#include "CappedProperty.h"
#include <cstdlib>

CappedProperty::CappedProperty(int v, int inf, int sup): attribute(v), minValue(inf), maxValue(sup) {}

int CappedProperty::get() {
    return attribute;
}

void CappedProperty::mutate() {
    if (attribute == minValue) {
        attribute++;
    } else if (attribute == maxValue) {
        attribute--;
    } else {
        attribute += (std::rand() < (RAND_MAX/2)) ? -1 : 1;
    }
}