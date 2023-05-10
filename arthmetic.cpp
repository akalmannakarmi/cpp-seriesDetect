#include <vector>
#include <sstream>
#include "structures.h"

std::vector<int> stringToArray(std::string str) {
    std::vector<int> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, ',')) {
        result.push_back(std::stoi(token));
    }
    return result;
}