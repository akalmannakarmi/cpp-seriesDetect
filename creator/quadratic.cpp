#include "sampleSequence.h"

class quadraticSequence : public Sequence {
    private:
        Number a;
        Number d1;
        Number dd;

    public:
    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences) override {
        Number prev = nums[1] - nums[0];
        Number next = nums[2] - nums[1];
        d1 = prev;
        dd = next-prev;
        prev = next;
        for (int i = 3; i < nums.size(); i++) {
            next=nums[i]-nums[i-1];
            if (next-prev != dd) {
                return false;
            }
            prev=next;
        }
        a = nums[0];
        type = "Quadratic Start:" + a.toString();
        return true;
    }

    virtual Number term(long long int n) override {
        Number d;
        for(int i=1;i<n;i++){
            d= d + d1 + dd * (i - 1);
        }
        return a + d;
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new quadraticSequence();
}