#ifndef Property_INCLUDED
#define Property_INCLUDED

class Property {
    public:
        virtual int get() = 0;
        virtual void mutate() = 0;
        virtual int getCost() = 0;
};

#endif