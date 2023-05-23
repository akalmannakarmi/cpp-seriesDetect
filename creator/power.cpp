#include "sampleSequence.h"
#include <iostream>
#include <cmath>


class PowerSequence : public Sequence {
    private:
        Number base;
        Sequence* powSeq;

    public:
    ~PowerSequence(){
        if (powSeq != nullptr) {
            delete powSeq;
        }
    }

    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences) override {
        base = nums[0];
        while (base>1){
            bool found=true;
            for(int i=0;i<nums.size();i++){
                int p = round(log(nums[i].get())/log(base.get()));
                if(pow(base.get(),p)!=nums[i].get()){
                    found=false;
                    break;
                }
            }
            if(found){
                break;
            }else{
                --base;
            }
        }
        if(base==Number(1)){
            return false;
        }
        std::vector<Number> powers;
        for(int i=0;i<nums.size();i++){
            powers.push_back(Number(round(log(nums[i].get())/log(base.get()))));
        }
        std::cout<<"Find"<<std::endl;
        if (findSequence(powSeq,sequences,powers)){
            type="Power with exponent:"+powSeq->type;
            std::cout<<"Found"<<std::endl;
            return true;
        }
        std::cout<<"NotFound"<<std::endl;
        return false;
    }

    virtual Number term(long long int n) override {
        if (powSeq==nullptr)
            return 0;
        return Number(pow(base.get(),powSeq->term(n).get()));
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new PowerSequence();
}