#include "sampleSequence.h"

class SquareNumbers : public Sequence {
    private:
        Number a;
        Number d;

    public:
    virtual bool detect(std::vector<Number>& nums,std::vector<std::string> dlls) override {
        d = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] != d) {
                return false;
            }
        }
        a = nums[0];
        return true;
    }

    virtual Number term(long long int n) override {
        return a + d * (n - 1);
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new SquareNumbers();
}