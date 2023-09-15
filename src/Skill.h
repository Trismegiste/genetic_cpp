#ifndef Skill_INCLUDED
#define Skill_INCLUDED

#include "SaWoTrait.h"
#include "Attribute.h"

class Skill : public SaWoTrait {
    protected:
        const Attribute attribute;
    public:
        Skill(const Attribute& attr, int dice);
        virtual int getCost() const;
        virtual Property* clone() const;
};

#endif