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
      virtual std::string toString() const;
      virtual Property* clone() const;

};

#endif