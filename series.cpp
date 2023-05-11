#include <vector>
#include "number.h"
#include "Series.h"

// Types
// 1=arth
// 2=geo
// 3=hamo

Series::Series(std::vector<Number> &nums){
    a=nums[0];
    type=0;
    c=arthmetic(nums);
    if(c!=0){
        type=1;
    }else{
        c=geometic(nums);
        if(c!=0){
            type=2;
        }else{
            c=harmonic(nums);
            if(c!=0){
                type=3;
            }
        }
    }
}

Number Series::term(long long int n){
    switch (type)
    {
    case 1:
        return a+c*(n-1);
    case 2:
        return a*(c^(n-1));
    case 3:
        return (a.flip()+c*(n-1)).flip();
    default:
        return Number();
    }
}

Number Series::arthmetic(std::vector<Number> &nums){
    Number result;
    Number d = nums[1]-nums[0];
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i]-nums[i-1]!=d){
            return result;
        }
    }
    return d;
}
Number Series::geometic(std::vector<Number> &nums){
    Number result;
    Number r = nums[1]/nums[0];
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i]/nums[i-1]!=r){
            return result;
        }
    }
    return r;
}
Number Series::harmonic(std::vector<Number> &nums){
    Number result;
    Number d = nums[1].flip()-nums[0].flip();
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i].flip()-nums[i-1].flip()!=d){
            return result;
        }
    }
    return d;
}