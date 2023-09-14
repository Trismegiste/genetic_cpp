#ifndef LevelHeadedEdge_INCLUDED
#define LevelHeadedEdge_INCLUDED

#include "CappedProperty.h"

class LevelHeadedEdge : public CappedProperty {
    public:
        LevelHeadedEdge(int v);
        virtual int getCost() const;
        virtual std::string toString() const;
        virtual Property* clone() const;
        int drawCard() const;
};

#endif