#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <string>
#include "number.h"

class Sequence{
    protected:
        typedef Sequence* (*createSequence)();
    public:
    std::string type = "Unknown Type";
    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences);
    virtual Number term(long long int n);
    bool findSequence(Sequence* &s,std::vector<createSequence> &sequences,std::vector<Number> &arr);
};
#endif