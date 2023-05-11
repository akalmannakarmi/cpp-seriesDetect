#include <iostream>
#include <ctime>
#include "number.h"


void add(Number,Number,Number,Number);
void sub(Number,Number,Number,Number);
void mult(Number,Number,Number,Number);
void div(Number,Number,Number,Number);
void mod(Number,Number,Number,Number);
void inr(Number,Number,Number,Number);
void dcr(Number,Number,Number,Number);
void equal(Number,Number,Number,Number);
void nEqual(Number,Number,Number,Number);
void lessThan(Number,Number,Number,Number);
void greatThan(Number,Number,Number,Number);
void lessThanEqual(Number,Number,Number,Number);
void greatThanEqual(Number,Number,Number,Number);

int main(){
    std::clock_t start = std::clock();

    Number i1(2);
    Number i2(3);
    Number r1(13,3);
    Number r2(40,5);

    add(i1,i2,r1,r2);
    sub(i1,i2,r1,r2);
    mult(i1,i2,r1,r2);
    div(i1,i2,r1,r2);
    mod(i1,i2,r1,r2);
    inr(i1,i2,r1,r2);
    dcr(i1,i2,r1,r2);
    equal(i1,i2,r1,r2);
    nEqual(i1,i2,r1,r2);
    lessThan(i1,i2,r1,r2);
    greatThan(i1,i2,r1,r2);
    lessThanEqual(i1,i2,r1,r2);
    greatThanEqual(i1,i2,r1,r2);

    std::cout << "Full time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    return 0;
}

void add(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    Number res1 = i1+i2;
    Number res2 = i1+r2;
    Number res3 = r1+i2;
    Number res4 = r1+r2;

    std::cout << "Add time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1+i2="<<res1<<std::endl;
    std::cout<<"i1+r2="<<res2<<std::endl;
    std::cout<<"r1+i2="<<res3<<std::endl;
    std::cout<<"r1+r2="<<res4<<std::endl;
}
void sub(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    Number res1 = i1-i2;
    Number res2 = i1-r2;
    Number res3 = r1-i2;
    Number res4 = r1-r2;

    std::cout << "Sub time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1-i2="<<res1<<std::endl;
    std::cout<<"i1-r2="<<res2<<std::endl;
    std::cout<<"r1-i2="<<res3<<std::endl;
    std::cout<<"r1-r2="<<res4<<std::endl;
}
void mult(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    Number res1 = i1*i2;
    Number res2 = i1*r2;
    Number res3 = r1*i2;
    Number res4 = r1*r2;

    std::cout << "Mult time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1*i2="<<res1<<std::endl;
    std::cout<<"i1*r2="<<res2<<std::endl;
    std::cout<<"r1*i2="<<res3<<std::endl;
    std::cout<<"r1*r2="<<res4<<std::endl;
}
void div(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    Number res1 = i1/i2;
    Number res2 = i1/r2;
    Number res3 = r1/i2;
    Number res4 = r1/r2;

    std::cout << "Div time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1/i2="<<res1<<std::endl;
    std::cout<<"i1/r2="<<res2<<std::endl;
    std::cout<<"r1/i2="<<res3<<std::endl;
    std::cout<<"r1/r2="<<res4<<std::endl;
}
void mod(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    Number res1 = i1%i2;
    Number res2 = i1%r2;
    Number res3 = r1%i2;
    Number res4 = r1%r2;

    std::cout << "mod time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1%i2="<<res1<<std::endl;
    std::cout<<"i1%r2="<<res2<<std::endl;
    std::cout<<"r1%i2="<<res3<<std::endl;
    std::cout<<"r1%r2="<<res4<<std::endl;
}
void inr(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    ++i1;
    ++i2;
    ++r1;
    ++r2;

    std::cout << "Increment time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"++i1"<<i1<<std::endl;
    std::cout<<"++i2"<<i2<<std::endl;
    std::cout<<"++r1"<<r1<<std::endl;
    std::cout<<"++r12"<<r2<<std::endl;
}
void dcr(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    --i1;
    --i2;
    --r1;
    --r2;

    std::cout << "Decrement time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"--i1"<<i1<<std::endl;
    std::cout<<"--i2"<<i2<<std::endl;
    std::cout<<"--r1"<<r1<<std::endl;
    std::cout<<"--r12"<<r2<<std::endl;
}

void equal(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    bool res1 = i1==i2;
    bool res2 = i1==r2;
    bool res3 = r1==i2;
    bool res4 = r1==r2;

    std::cout << "Equal time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1==i2="<<res1<<std::endl;
    std::cout<<"i1==r2="<<res2<<std::endl;
    std::cout<<"r1==i2="<<res3<<std::endl;
    std::cout<<"r1==r2="<<res4<<std::endl;
}
void nEqual(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    bool res1 = i1!=i2;
    bool res2 = i1!=r2;
    bool res3 = r1!=i2;
    bool res4 = r1!=r2;

    std::cout << "not Equal time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1!=i2="<<res1<<std::endl;
    std::cout<<"i1!=r2="<<res2<<std::endl;
    std::cout<<"r1!=i2="<<res3<<std::endl;
    std::cout<<"r1!=r2="<<res4<<std::endl;
}
void lessThan(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    bool res1 = i1<i2;
    bool res2 = i1<r2;
    bool res3 = r1<i2;
    bool res4 = r1<r2;

    std::cout << "Less than time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1<i2="<<res1<<std::endl;
    std::cout<<"i1<r2="<<res2<<std::endl;
    std::cout<<"r1<i2="<<res3<<std::endl;
    std::cout<<"r1<r2="<<res4<<std::endl;
}
void greatThan(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    bool res1 = i1>i2;
    bool res2 = i1>r2;
    bool res3 = r1>i2;
    bool res4 = r1>r2;

    std::cout << "not Equal time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1>i2="<<res1<<std::endl;
    std::cout<<"i1>r2="<<res2<<std::endl;
    std::cout<<"r1>i2="<<res3<<std::endl;
    std::cout<<"r1>r2="<<res4<<std::endl;
}
void lessThanEqual(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    bool res1 = i1<=i2;
    bool res2 = i1<=r2;
    bool res3 = r1<=i2;
    bool res4 = r1<=r2;

    std::cout << "Less than time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1<=i2="<<res1<<std::endl;
    std::cout<<"i1<=r2="<<res2<<std::endl;
    std::cout<<"r1<=i2="<<res3<<std::endl;
    std::cout<<"r1<=r2="<<res4<<std::endl;
}
void greatThanEqual(Number i1,Number i2,Number r1,Number r2){
    std::clock_t start = std::clock();

    bool res1 = i1>=i2;
    bool res2 = i1>=r2;
    bool res3 = r1>=i2;
    bool res4 = r1>=r2;

    std::cout << "not Equal time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
    std::cout<<"i1>=i2="<<res1<<std::endl;
    std::cout<<"i1>=r2="<<res2<<std::endl;
    std::cout<<"r1>=i2="<<res3<<std::endl;
    std::cout<<"r1>=r2="<<res4<<std::endl;
}