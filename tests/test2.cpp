#include "arthSequence.h"

#include <iostream>
#include <vector>
#include <sstream>

std::vector<Number> stringToArray(std::string str) {
    std::vector<Number> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, ',')) {
        size_t pos = token.find('/');
        if (pos != std::string::npos) {
            std::string token1 = token.substr(0, pos);
            std::string token2 = token.substr(pos + 1);
            Number n1(std::stoi(token1),std::stoi(token2));
            result.push_back(n1);
        } else {
            Number n(std::stoi(token));
            result.push_back(n);
        }
    }
    return result;
}

int main(){
    std::string seriesStr;
    std::cout<<"Enter Series:";
    std::cin>>seriesStr;
    std::vector<Number> arr = stringToArray(seriesStr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout<<std::endl;
    ArthSequence s;
    s.detect(arr);
    long long int term;
    std::cout<<"Term:";
    std::cin>>term;
    std::cout<<"t"<<term<<":"<<s.term(term)<<std::endl;
    return 0;
}