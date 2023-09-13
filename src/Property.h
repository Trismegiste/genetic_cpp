#ifndef Property_INCLUDED
#define Property_INCLUDED

class Property {
protected:
  int gene;

public:
  Property(int s) : gene(s) {}
  virtual int get() const { return gene; };
  virtual void mutate() = 0;
  virtual int getCost() const = 0;
  virtual ~Property() {};
};

#endif