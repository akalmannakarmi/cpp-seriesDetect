#include "sampleSequence.h"

class ArthSequence : public Sequence {
    private:
        Number first;
        Number second;

    public:
    virtual bool detect(std::vector<Number>& nums,std::vector<std::string> dlls) override {
        Number prev2 = nums[0];
        Number prev1 = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i]!=prev2+prev1) {
                return false;
            }
            prev2 = prev1;
            prev1 = nums[i];
        }
        first = nums[0];
        second = nums[1];
        type = "Fibonacci Sequence";
        return true;
    }

    virtual Number term(long long int n) override {
        if(n==1){
            return first;
        }else if (n==2){
            return second;
        }
        
        Number result,prev1=second,prev2=first;
        for(int i=2;i<n;i++){
            result = prev2+prev1;
            prev2=prev1;
            prev1=result;
        }
        return result;
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new ArthSequence();
}