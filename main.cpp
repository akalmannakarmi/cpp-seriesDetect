#include <iostream>
#include <vector>
#include "tools.cpp"
#include "number.h"
#include "series.h"

int main(){
    std::string seriesStr;
    std::cout<<"Enter Series:";
    std::cin>>seriesStr;
    std::vector<Number> arr = stringToArray(seriesStr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;
    Series s(arr);
    long long int term;
    std::cout<<"Term:";
    std::cin>>term;
    std::cout<<"t"<<term<<":"<<s.term(term)<<std::endl;
    return 0;
}