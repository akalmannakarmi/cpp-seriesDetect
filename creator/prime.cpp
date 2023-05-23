#include "sampleSequence.h"
#include <cmath>

class primeSequence : public Sequence {
    private:
        Number a;

    public:
    bool isPrime(Number num) {
        if (num <= 1)
            return false;

        for (int i = 2; i * i <= num.get(); ++i) {
            if (num % i == 0)
                return false;
        }

        return true;
    }


    virtual bool detect(std::vector<Number> &nums,std::vector<createSequence> &sequences) override {
        if(!isPrime(nums[0]))
            return false;
        a = nums[0];
        Number k = a;
        for (int i = 1; i < nums.size(); i++) {
            while (true){
                ++k;
                if(isPrime(k)){
                    if(k==nums[i]){
                        break;
                    }else{
                        return false;
                    }
                }
            }   
        }
        type = "Prime Start:" + a.toString();
        return true;
    }

    virtual Number term(long long int n) override {
        std::vector<Number> primes;
        Number num = a;

        while (primes.size() < n) {
            if (isPrime(num)) {
                primes.push_back(num);
            }
            ++num;
        }

        return primes.back();
    }
};

extern "C" __declspec(dllexport) Sequence* create() {
    return new primeSequence();
}