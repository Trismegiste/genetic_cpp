#ifndef MutableFighter_INCLUDED
#define MutableFighter_INCLUDED

#include "Property.h"
#include <string>
#include <unordered_map>
#include <iostream>

class MutableFighter {
protected:
  int victory;
  std::unordered_map<std::string, Property *> genome;

public:
  MutableFighter(std::unordered_map<std::string, Property *> param);
  virtual ~MutableFighter();
  virtual void newGeneration() = 0;
  virtual int getCost() const;
  virtual void restart() = 0;
  virtual void incVictory();
  virtual bool isDead() const = 0;
  virtual void receiveAttack(MutableFighter *pc) = 0;
  virtual int getVictory() const;
  virtual int getInitiative() = 0;
  virtual int getFitness() const = 0;
  virtual void mutate();
  virtual const std::unordered_map<std::string, Property *>& getGenome() const;

  friend std::ostream &operator<<(std::ostream &output, const MutableFighter &a) {
    for (auto& [key, value]: a.genome) { 
        output << key << ":" << value->toString() << " ";
    }
    output << "win:" << a.getVictory() << " cost:" << a.getCost();
    return output;
  }
};

#endif