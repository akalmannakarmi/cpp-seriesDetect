#include "sampleSequence.h"
#include <windows.h>
#include <cmath>

class SquareNumbers : public Sequence {
    private:
        Sequence *baseSeq=nullptr;
        Sequence *powSeq=nullptr;

    public:
    ~SquareNumbers(){
        if (baseSeq != nullptr) {
            delete baseSeq;
        }
        if (powSeq != nullptr) {
            delete powSeq;
        }
    }

    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences) override {
        std::vector<Number> bases;
        std::vector<Number> expos;
        double result;
        bool found;
        for (int i=0;i<nums.size();i++){
            for (int base = 1; base<=nums[i].get(); base++) {
                result=0;found=false;
                for (int exponent = 0;  result >= nums[i].get(); exponent++) {
                    result = pow(base, exponent);
                    if (result == nums[i].get()) {
                        bases.push_back(Number(base));
                        expos.push_back(Number(exponent));
                        found = true;break;
                    }
                }
                if(!found)
                    return false;
            }
        }
        if(findSequence(baseSeq,sequences,bases) && findSequence(powSeq,sequences,expos))
            type = "Power (Base:"+baseSeq->type+",Exponent:"+powSeq->type+")";
            return true;
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