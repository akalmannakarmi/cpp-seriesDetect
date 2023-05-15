#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include "number.h"

class Sequence{
    public:
    virtual bool detect(std::vector<Number> &nums);
    virtual Number term(long long int n);
};
#endif