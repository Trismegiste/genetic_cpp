#ifndef MutableFighter_INCLUDED
#define MutableFighter_INCLUDED

#include "Property.h"
#include <string>
#include <unordered_map>

class MutableFighter {
protected:
  int victory;
  std::unordered_map<std::string, Property *> genome;

public:
  virtual void newGeneration() = 0;
  virtual int getCost() = 0;
  virtual void restart() = 0;
  virtual void incVictory();
  virtual bool isDead() = 0;
  virtual void receiveAttack(MutableFighter *pc) = 0;
  virtual int getVictory();
  virtual int getInitiative() = 0;
  MutableFighter(std::unordered_map<std::string, Property *> param);
  virtual ~MutableFighter();
  virtual int getFitness() = 0;
};

#endif