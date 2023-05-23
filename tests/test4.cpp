#include <ctime>
#include <iostream>
#include <vector>
int main(){
    std::vector<double> fpses;
    for(int j=0;j<100;j++){
        std::clock_t start = std::clock();
        for(int i=0;i<5000000;i++){

        }
        double fps = 1/((double)(std::clock() - start)/CLOCKS_PER_SEC);
        fpses.push_back(fps);
        // std::cout << "Add time: " << (double)(std::clock() - start)/CLOCKS_PER_SEC << " seconds" << std::endl;
        std::cout << "Fps: " << fps << std::endl;
    }
    double av=0;
    for(int i=0;i<fpses.size();i++){
        av+=fpses[i];
    }
    av/=fpses.size();
    std::cout<<"Average:"<<av<<std::endl;
    return 0;
}