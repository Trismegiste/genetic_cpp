#ifndef Character_INCLUDED
#define Character_INCLUDED

#include "MutableFighter.h"
#include <unordered_map>

class Character : public MutableFighter {
protected:
  bool shaken;
  int usedBenny;
  int wound;

public:
  Character(std::unordered_map<std::string, Property *> param)
      : MutableFighter(param) {}
  virtual void newGeneration();
  virtual int getCost() const;
  virtual void restart();
  virtual bool isDead() const;
  virtual void receiveAttack(MutableFighter *pc);
  virtual int getInitiative();
  virtual int getFitness() const;
};

#endif