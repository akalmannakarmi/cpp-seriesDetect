#include "sampleSequence.h"

class HarmoSquence : public Sequence{
    private:
        Number a;
        Number d;

    public:
    virtual bool detect(std::vector<Number> &nums) override {
        Number prev = nums[0].flip();
        Number next = nums[1].flip();
        d = next - prev;
        prev = next;

        for (int i = 2; i < nums.size(); i++) {
            next = nums[i].flip();
            if (next - prev != d) {
                return false;
            }
            prev = next;
        }

        a = nums[0];
        return true;
    }

    virtual Number term(long long int n) override {
        return (a.flip()+d*(n-1)).flip();
    }
};
extern "C" __declspec(dllexport) Sequence* create(){
    return new HarmoSquence();
}