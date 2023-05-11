#include <vector>
#include <sstream>
#include "number.h"

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
