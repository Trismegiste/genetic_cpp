#ifndef Character_INCLUDED
#define Character_INCLUDED

#include "MutableFighter.h"
#include <unordered_map>

class Character : public MutableFighter {
    protected:
        bool shaken = false;
        int usedBenny = 0;
        int wound = 0;
        int benniesCount = 3;
        int weapon = 8;

    public:
        Character(std::unordered_map<std::string, Property *> param)
            : MutableFighter(param) {}
        virtual void newGeneration();
        virtual void restart();
        virtual bool isDead() const;
        virtual void receiveAttack(MutableFighter *pc);
        virtual int getInitiative();
        virtual int getFitness() const;
        int getParry();
        int getToughness();

    protected:
        bool hasBenny() const;
        bool isShaken() const;
        void useBenny();
        void tryUnshake();
        int rollTrait(std::string trait) const;


};

#endif