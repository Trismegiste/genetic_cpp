#include "CappedProperty.h"
#include "Property.h"
#include <cstdlib>

CappedProperty::CappedProperty(int v, int inf, int sup)
    : Property(v), minValue(inf), maxValue(sup) {}

void CappedProperty::mutate() {
  if (gene == minValue) {
    gene++;
  } else if (gene == maxValue) {
    gene--;
  } else {
    gene += (std::rand() < (RAND_MAX / 2)) ? -1 : 1;
  }
}