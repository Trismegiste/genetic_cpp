#include "CappedProperty.h"
#include "Property.h"
#include "random_helper.h"

CappedProperty::CappedProperty(int v, int inf, int sup)
    : Property(v), minValue(inf), maxValue(sup) {}

void CappedProperty::mutate() {
  if (gene == minValue) {
    gene++;
  } else if (gene == maxValue) {
    gene--;
  } else {
    gene += chaos::oneOrMinusOne();
  }
}