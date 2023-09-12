#include "MutableFighter.h"

void MutableFighter::incVictory() {
    victory++;
}

int MutableFighter::getVictory() {
    return victory;
}

MutableFighter::MutableFighter(std::unordered_map<std::string, Property*> param): genome(param) {
}

MutableFighter::~MutableFighter() {
     for (auto& [key, value]: genome) { 
        delete value;
    }
}