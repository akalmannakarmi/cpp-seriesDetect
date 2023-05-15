#include "number.h"
#include <numeric>
#include <cmath>

Number::Number(){
    n.rational.isRational=0;
    n.integer=0;
}
Number::Number(long long int i){
    n.rational.isRational=0;
    n.integer=i;
}
Number::Number(int numerator,unsigned int denominator){
    n.rational.isRational=1;
    n.rational.numerator=numerator;
    n.rational.denominator=denominator;
}

double Number::get(){
    if(n.rational.isRational==1){
        return (double)n.rational.numerator/n.rational.denominator;
    }
    return n.integer;
}
long long int Number::getInt(unsigned short int points){
    if(n.rational.isRational==1){
        return n.rational.numerator*pow(10,points)/n.rational.denominator;
    }
    return n.integer;
}
std::string Number::toString(){
    if (n.rational.isRational == 1) {
        return std::to_string(n.rational.numerator) + "/" + std::to_string(n.rational.denominator);
    } else {
        return std::to_string(n.integer);
    }
}
void Number::reduce(){
    if(n.rational.isRational==1){
        int gcd = std::gcd(n.rational.numerator,n.rational.denominator);
        n.rational.numerator/=gcd;
        n.rational.denominator/=gcd;
        if (n.rational.denominator==1){
            n.rational.isRational=0;
            n.integer=n.rational.numerator;
        }
    }
}
Number Number::flip(){
    Number result(0,1);
    if(n.rational.isRational==1){
        if(n.rational.numerator<0){
            result.n.rational.numerator=-n.rational.denominator;
            result.n.rational.denominator=-n.rational.numerator;
        }else{
            result.n.rational.numerator=n.rational.denominator;
            result.n.rational.denominator=n.rational.numerator;
        }
    }else{
        result.n.rational.numerator=1;
        result.n.rational.denominator=n.integer;
    }
    result.reduce();
    return result;
}

void Number::operator= (const Number &a){
    n = a.n;
}
Number Number::operator+ (const Number &a){
    Number result(0,1);
    if(n.rational.isRational==1 && a.n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator*a.n.rational.denominator+a.n.rational.numerator*n.rational.denominator;
        result.n.rational.denominator=n.rational.denominator*a.n.rational.denominator;
    }else if (n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator+a.n.integer*n.rational.denominator;
        result.n.rational.denominator=n.rational.denominator;
    }else if (a.n.rational.isRational==1){
        result.n.rational.numerator=n.integer*a.n.rational.denominator+a.n.rational.numerator;
        result.n.rational.denominator=a.n.rational.denominator;
    }else{
        result.n.rational.isRational=0;
        result.n.integer=n.integer+a.n.integer;
    }
    result.reduce();
    return result;
}
Number Number::operator- (const Number &a){
    Number result(0,1);
    if(n.rational.isRational==1 && a.n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator*a.n.rational.denominator-a.n.rational.numerator*n.rational.denominator;
        result.n.rational.denominator=n.rational.denominator*a.n.rational.denominator;
    }else if (n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator-a.n.integer*n.rational.denominator;
        result.n.rational.denominator=n.rational.denominator;
    }else if (a.n.rational.isRational==1){
        result.n.rational.numerator=n.integer*a.n.rational.denominator-a.n.rational.numerator;
        result.n.rational.denominator=a.n.rational.denominator;
    }else{
        result.n.rational.isRational=0;
        result.n.integer=n.integer-a.n.integer;
    }
    result.reduce();
    return result;
}
Number Number::operator* (const Number &a){
    Number result(0,1);
    if(n.rational.isRational==1 && a.n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator*a.n.rational.numerator;
        result.n.rational.denominator=n.rational.denominator*a.n.rational.denominator;
    }else if (n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator*a.n.integer;
        result.n.rational.denominator=n.rational.denominator;
    }else if (a.n.rational.isRational==1){
        result.n.rational.numerator=n.integer*a.n.rational.numerator;
        result.n.rational.denominator=a.n.rational.denominator;
    }else{
        result.n.rational.isRational=0;
        result.n.integer=n.integer*a.n.integer;
    }
    result.reduce();
    return result;
}
Number Number::operator/ (const Number &a){
    Number result(0,1);
    if(n.rational.isRational==1 && a.n.rational.isRational==1){
        if(a.n.rational.numerator<0){
            result.n.rational.numerator=n.rational.numerator*a.n.rational.denominator*-1;
            result.n.rational.denominator=n.rational.denominator*(a.n.rational.numerator*-1);
        }else{
            result.n.rational.numerator=n.rational.numerator*a.n.rational.denominator;
            result.n.rational.denominator=n.rational.denominator*a.n.rational.numerator;
        }
    }else if (n.rational.isRational==1){
        if(a.n.integer<0){
            result.n.rational.numerator=n.rational.numerator*-1;
            result.n.rational.denominator=n.rational.denominator*(a.n.integer*-1);
        }else{
            result.n.rational.numerator=n.rational.numerator;
            result.n.rational.denominator=n.rational.denominator*a.n.integer;
        }
    }else if (a.n.rational.isRational==1){
        if(a.n.rational.numerator<0){
            result.n.rational.numerator=n.integer*a.n.rational.denominator*-1;
            result.n.rational.denominator=a.n.rational.numerator*-1;
        }else{
            result.n.rational.numerator=n.integer*a.n.rational.denominator;
            result.n.rational.denominator=a.n.rational.numerator;
        }
    }else{
        if(a.n.integer<0){
            result.n.rational.numerator=n.integer*-1;
            result.n.rational.denominator=a.n.integer*-1;
        }else{
            result.n.rational.numerator=n.integer;
            result.n.rational.denominator=a.n.integer;
        }
    }
    result.reduce();
    return result;
}
Number Number::operator^(int a){
    Number result;
    if(n.rational.isRational==1){
        result.n.rational.numerator=pow(n.rational.numerator,a);
        result.n.rational.denominator=pow(n.rational.denominator,a);
    }else{
        result.n.integer=pow(n.integer,a);
    }
    result.reduce();
    return result;
}
int Number::operator% (const Number &a){
    int result=0;
    if(n.rational.isRational==0 && a.n.rational.isRational==0){
        if (a.n.integer==0){
            result = 0;
        }else{
            result=n.integer%a.n.integer;
        }
    }else if (n.rational.isRational==1){
        if (a.n.integer==0){
            result = 0;
        }else{
            result = getInt()%a.n.integer;
        }
    }else if (a.n.rational.isRational==1){
        int m = (a.n.rational.numerator/a.n.rational.denominator);
        if (m==0){
            result = 0;
        }else{
            result = n.integer%m;
        }
    }else{
        int m = (a.n.rational.numerator/a.n.rational.denominator);
        if (m==0){
            result = 0;
        }else{
            result=getInt()%m;
        }
    }
    return result;
}
void Number::operator++(){
    if(n.rational.isRational==1){
        n.rational.numerator+=n.rational.denominator;
    }else{
        n.integer++;
    }
    reduce();
}
void Number::operator--(){
    if(n.rational.isRational==1){
        n.rational.numerator-=n.rational.denominator;
    }else{
        n.integer--;
    }
    reduce();
}


void Number::operator=(long long int a){
    n.integer=a;
    n.rational.isRational=0;
    reduce();
}
Number Number::operator+(long long int a){
    Number result;
    if (n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator+n.rational.denominator*a;
        result.n.rational.denominator=n.rational.denominator;
    }else{
        result.n.integer+=a;
    }
    result.reduce();
    return result;
}
Number Number::operator-(long long int a){
    Number result;
    if (n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator-n.rational.denominator*a;
        result.n.rational.denominator=n.rational.denominator;
    }else{
        result.n.integer-=a;
    }
    result.reduce();
    return result;
}
Number Number::operator*(long long int a){
    Number result;
    if (n.rational.isRational==1){
        result.n.rational.numerator=n.rational.numerator*a;
        result.n.rational.denominator=n.rational.denominator;
    }else{
        result.n.integer=n.integer*a;
    }
    result.reduce();
    return result;
}
Number Number::operator/(long long int a){
    Number result;
    if (n.rational.isRational==1){
        if(a<0){
            result.n.rational.numerator=n.rational.numerator*-1;
            result.n.rational.denominator=n.rational.denominator*a*-1;
        }
        else{
            result.n.rational.numerator=n.rational.numerator;
            result.n.rational.denominator=n.rational.denominator*a;
        }
    }else{
        if(a<0){
            result.n.rational.numerator=n.integer*-1;
            result.n.rational.denominator=a*-1;
        }
        else{
            result.n.rational.numerator=n.integer;
            result.n.rational.denominator=a;
        }
    }
    result.reduce();
    return result;
}


bool Number::operator==(const Number &a){
    if(n.rational.isRational==0 && a.n.rational.isRational==0){
        return n.integer==a.n.integer;
    }else if (n.rational.isRational==0 || a.n.rational.isRational==0){
        return false;
    }
    return (n.rational.numerator==a.n.rational.numerator && n.rational.denominator==a.n.rational.denominator);
}
bool Number::operator!=(const Number &a){
    return !operator==(a);
}
bool Number::operator<(const Number &a){
    if(n.rational.isRational==1 && a.n.rational.isRational==1){
        return get()<((double)a.n.rational.numerator/a.n.rational.denominator);
    }else if (n.rational.isRational==1){
        return get()<a.n.integer;
    }else if (a.n.rational.isRational==1){
        return n.integer<((double)a.n.rational.numerator/a.n.rational.denominator);
    }else{
        return n.integer<a.n.integer;
    }
}
bool Number::operator>(const Number &a){
    if(n.rational.isRational==1 && a.n.rational.isRational==1){
        return get()>((double)a.n.rational.numerator/a.n.rational.denominator);
    }else if (n.rational.isRational==1){
        return get()>a.n.integer;
    }else if (a.n.rational.isRational==1){
        return n.integer>((double)a.n.rational.numerator/a.n.rational.denominator);
    }else{
        return n.integer>a.n.integer;
    }
}
bool Number::operator<=(const Number &a){
    return !operator>(a);
}
bool Number::operator>=(const Number &a){
    return !operator<(a);
}