#ifndef AttackStrat_INCLUDED
#define AttackStrat_INCLUDED
#include "CappedProperty.h"
#include "Property.h"
#include <iostream>
#include <string>
#include <vector>

class AttackStrat : public CappedProperty {

    public:
      static const std::vector<std::string> choice;

      AttackStrat(int v) : CappedProperty(v, 0, 1){};
      virtual int getCost() const { return 0; };
      friend std::ostream &operator<<(std::ostream &output, const AttackStrat &a) {
        output << AttackStrat::choice[a.gene];
        return output;
      }
};

#endif