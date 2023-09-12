#ifndef Character_INCLUDED
#define Character_INCLUDED

#include "MutableFighter.h"

class Character: public MutableFighter {
    protected:
        bool shaken;
        int usedBenny;
        int wound;

    public:
        virtual void newGeneration();
        virtual int getCost();
        virtual void restart();
        virtual bool isDead();
        virtual void receiveAttack(MutableFighter* pc);
        virtual int getInitiative();


};

#endif