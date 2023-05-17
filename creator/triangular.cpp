#include "sampleSequence.h"

class TriangularSequence : public Sequence {
    private:
        Number a;

    public:
    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences) override {
        Number r(0);
        int n =0;
        while (r<nums[0]){
            r=(n * (n + 1)) / 2;
            n++;
        }
        if(r!=nums[0]){
            return false;
        }
        a=Number(n-1);
        for(int i=1;i<nums.size();i++){
            if((n * (n + 1)) / 2!=nums[i].get()){
                return false;
            }
            n++;
        }
        type = "Triangular start:" + a.toString();
        return true;
    }

    virtual Number term(long long int n) override {
        n+= a.getInt();
        return (n * (n + 1)) / 2;
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new TriangularSequence();
}