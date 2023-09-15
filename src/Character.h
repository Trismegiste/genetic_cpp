#ifndef Character_INCLUDED
#define Character_INCLUDED

#include "MutableFighter.h"
#include <unordered_map>
#include <vector>

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
        int getWoundsPenalty();
        std::vector<int> getAttack();
        int getDamage();
        void receiveDamage(int damage);

    protected:
        bool hasBenny() const;
        bool isShaken() const;
        void useBenny();
        void tryUnshake();
        int rollTrait(const std::string& trait);
        int getOneAttack();
        std::vector<int> getOneAttackRateOfFire(int rateOfFire);
        int rollFighting();
        std::vector<int> rollFightingRateOfFire(int rateOfFire);
        int rollDamage();
        void addWounds(int w);
};

#endif