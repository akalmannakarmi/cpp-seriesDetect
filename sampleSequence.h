#pragma once

#include<iostream>
#include <vector>

class Number{
    private:
    union Num {
        long long int integer:sizeof(int)*8*2-1;
        struct Rational{
            int numerator: sizeof(int)*8;
            unsigned int denominator: sizeof(int)*8-1;
            unsigned int isRational: 1;
        }rational;
    } n;

    public:
    Number();
    Number(long long int i);
    Number(int numerator,unsigned int denominator);

    double get();
    long long int getInt(unsigned short int points=0);
    std::string toString();
    void reduce();
    Number flip();

    void operator= (const Number &a);
    Number operator+ (const Number &a);
    Number operator- (const Number &a);
    Number operator* (const Number &a);
    Number operator/ (const Number &a);
    Number operator^ (int a);
    int operator% (const Number &a);
    void operator++ ();
    void operator-- ();

    void operator= (long long int a);
    Number operator+ (long long int a);
    Number operator- (long long int a);
    Number operator* (long long int a);
    Number operator/ (long long int a);

    bool operator== (const Number &a);
    bool operator!= (const Number &a);
    bool operator< (const Number &a);
    bool operator> (const Number &a);
    bool operator<= (const Number &a);
    bool operator>= (const Number &a);


    friend std::ostream& operator<<(std::ostream& s, const Number& a) {
        if(a.n.rational.isRational==1){
            return s<<"Number("<<a.n.rational.numerator<<"/"<<a.n.rational.denominator<<")";
        }
        return s << "Number("<<a.n.integer<<")";
    }
};
class Sequence{
    public:
    std::string type = "Unknown Type";
    virtual bool detect(std::vector<Number> &nums,std::vector<std::string> dlls= {});
    virtual Number term(long long int n);
};