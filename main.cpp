#include <iostream>
#include <vector>
#include "arthmetic.cpp"
#include "tools.cpp"

int main(){
    std::string seriesStr;
    std::cout<<"Enter Series:";
    std::cin>>seriesStr;
    std::cout<<"Got:"<<seriesStr<<std::endl;
    std::vector<int> arr = stringToArray(seriesStr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}