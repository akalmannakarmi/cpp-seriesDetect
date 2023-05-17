#include "sampleSequence.h"
#include <iostream>
#include <cmath>

enum sqType{
    POWER,
    GEOBASE,
    GEOPOWER,
    ARTHBASE,
    ARTHPOWER
}

class SquareNumbers : public Sequence {
    private:
        Number a;
        sqType subType;

    public:
    ~SquareNumbers(){
        if (baseSeq != nullptr) {
            delete baseSeq;
        }
        if (powSeq != nullptr) {
            delete powSeq;
        }
    }

    bool detectSquare(std::vector<Number> &nums){
        for (int i=0;i<nums.size();i++){
            if(sqrt(nums[i])*sqrt(nums[i])!=nums[i]){
                return false;
            }
        }
        a=nums[0];
        sqType = SQUARE;
        type="Square Numbers Start:"+a.toString();
        return true;
    }
    bool detectCube(std::vector<Number> &nums){
        for (int i=0;i<nums.size();i++){
            if(cbrt(nums[i])*cbrt(nums[i])!=nums[i]){
                return false;
            }
        }
        a=nums[0];
        sqType = CUBE;
        type="Cubic Numbers Start:"+a.toString();
        return true;
    }

    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences) override {
        if(detectSquare(nums)){
            return true;
        }else if (detectCube(nums)){
            return true;
        }
        
        return false;
    }

    virtual Number term(long long int n) override {
        if (baseSeq!=nullptr && powSeq!=nullptr)
            return 0;
        return baseSeq->term(n)^powSeq->term(n).getInt();
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new SquareNumbers();
}