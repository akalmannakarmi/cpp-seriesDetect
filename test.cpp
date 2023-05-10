#include <iostream>
#include <cmath>
struct Rational {
    int numerator: sizeof(int)*8;
    unsigned int denominator: sizeof(int)*8-1;
    unsigned int isRational: 1;
};
union Num {
    long long int integer:sizeof(int)*8*2-1;
    Rational rational;
};
int main() {
    Num num{0};
    num.rational.isRational = 0;
    num.integer=pow(2,63/2);
    if (num.rational.isRational==1){
        std::cout<<num.rational.numerator<<'/'<<num.rational.denominator<<std::endl;
    }else{
        std::cout<<num.integer<<std::endl;
    }
    
    std::cout<<"ALL"<<std::endl;
    std::cout<<num.rational.numerator<<'/'<<num.rational.denominator<<std::endl;
    std::cout<<num.integer<<std::endl;

    
    num.rational.isRational = 1;
    std::cout<<"test"<<4294967295<<std::endl;
    num.rational.numerator=2147483647;
    num.rational.denominator=2147483649;
    if (num.rational.isRational==1){
        std::cout<<num.rational.numerator<<'/'<<num.rational.denominator<<std::endl;
    }else{
        std::cout<<num.integer<<std::endl;
    }
    
    std::cout<<"ALL"<<std::endl;
    std::cout<<num.rational.numerator<<'/'<<num.rational.denominator<<std::endl;
    std::cout<<num.integer<<std::endl;

    return 0;
}
