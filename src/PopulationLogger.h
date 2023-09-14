#ifndef PopulationLogger_INCLUDED
#define PopulationLogger_INCLUDED

#include <vector>
#include "MutableFighter.h"

class PopulationLogger {
    public:
        virtual void log(const std::vector<MutableFighter*> &population) const = 0;
        virtual void endLog() const = 0;
};

#endif