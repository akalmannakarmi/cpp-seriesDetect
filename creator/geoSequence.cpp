#include "sampleSequence.h"

class GeoSequence : public Sequence{
    private:
        Number a;
        Number r;
    
    public:
    virtual bool detect(std::vector<Number> &nums) override{
        r = nums[1]/nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i]/nums[i-1]!=r){
                return false;
            }
        }
        a=nums[0];
        return true;
    }
    virtual Number term(long long int n) override{
        return a*(r^(n-1));
    }
};
extern "C" __declspec(dllexport) Sequence* create(){
    return new GeoSequence();
}