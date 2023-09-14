#ifndef TextLogger_INCLUDED
#define TextLogger_INCLUDED

#include "PopulationLogger.h"

class TextLogger : public PopulationLogger {
    protected:
        float viewedRatio;
    public:
        TextLogger(float viewedRatio);
        virtual void log(const std::vector<MutableFighter*> &population) const;
        virtual void endLog() const {};
};

#endif