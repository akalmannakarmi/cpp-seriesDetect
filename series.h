#ifndef SERIES_H
#define SERIES_H

#include <vector>
#include "number.h"

class Series{
    private:
        Number a;
        Number c;
        unsigned short int type;
    
    public:
    Series(std::vector<Number> &nums);

    Number term(long long int n);

    static Number arthmetic(std::vector<Number> &nums);
    static Number geometic(std::vector<Number> &nums);
    static Number harmonic(std::vector<Number> &nums);
};

#include "series.cpp"
#endif