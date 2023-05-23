#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int generateNthPrime(int n, int sNum) {
    std::vector<int> primes;
    int num = sNum;

    while (primes.size() < n) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        ++num;
    }

    return primes.back();
}

int main() {
    int n, sNum;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Enter the starting number (sNum): ";
    std::cin >> sNum;

    int nthPrime = generateNthPrime(n, sNum);
    std::cout << "The nth prime number starting from " << sNum << " is: " << nthPrime << std::endl;

    return 0;
}
