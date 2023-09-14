#ifndef TradeWeaponEdge_INCLUDED
#define TradeWeaponEdge_INCLUDED
#include "CappedProperty.h"

class TradeWeaponEdge : public CappedProperty {
public:
  TradeWeaponEdge(int v) : CappedProperty(v, 0, 2) {}
  virtual int getCost() const { return 2 * gene; }
  virtual std::string toString() const { auto s = std::to_string(gene); return s;}
  virtual Property* clone() const {
    return new TradeWeaponEdge(gene);
  }
};

#endif