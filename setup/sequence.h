#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include "number.h"

class Sequence{
    public:
    std::string type = "Unknown Type";
    virtual bool detect(std::vector<Number> &nums,std::vector<std::string> dlls= {});
    virtual Number term(long long int n);
};
#endif