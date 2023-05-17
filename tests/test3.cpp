# include <iostream>
#include <cmath>
bool isPrime(int num) {
    if (num < 2)
        return false;
    int sqrtNum = sqrt(num);
    for (int i = 2; i <= sqrtNum; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
int main(){
std::cout<<"num:";
int a;
std::cin>>a;
std::cout<<isPrime(a);
return 0;
}

