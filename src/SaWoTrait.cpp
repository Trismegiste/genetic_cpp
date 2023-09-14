#include "SaWoTrait.h"

SaWoTrait::SaWoTrait(int dice) : CappedProperty(dice / 2 - 2, 0, 4) {
}

int SaWoTrait::get() const {
    return 2 * gene + 4;
};

std::string SaWoTrait::toString() const {
    auto s = std::to_string(get());
    return "d" + s;
};
