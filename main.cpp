#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <map>
#include "src/Round.hpp"

int main() {

    std::default_random_engine reng;

    // `7.5` becomes 7 (floored) with 50% chance, and becomes 8 (ceiled) with 50% chance.
    double num50 = 7.5;

    std::map<double, int> hist;
    for(int n=0; n<10000; ++n) {
        ++hist[randround::round(num50, reng)];
    }

    std::cout << "Random rounding of " << num50 << ":\n";
    for(const auto& pair : hist) {
        std::cout << std::setw(2) << pair.first
                  << ' ' << std::string(pair.second/400, '*') << '\n';
    }


    // `6.6` becomes 6 (floored) with 40% chance, and becomes 7 (ceiled) with 60% chance.
    double num60 = 6.6;

    std::map<double, int> hist60;
    for(int n=0; n<10000; ++n) {
        ++hist60[randround::round(num60, reng)];
    }

    std::cout << "Random rounding of " << num60 << ":\n";
    for(const auto& pair : hist60) {
        std::cout << std::setw(2) << pair.first
                  << ' ' << std::string(pair.second/400, '*') << '\n';
    }

    // `-2.3` becomes -2 (floored) with 30% chance, and becomes -3 (ceiled) with 70% chance.
    double num30 = -2.3;

    std::map<double, int> hist30;
    for(int n=0; n<10000; ++n) {
        ++hist30[randround::round(num30, reng)];
    }

    std::cout << "Random rounding of " << num30 << ":\n";
    for(const auto& pair : hist30) {
        std::cout << std::setw(2) << pair.first
                  << ' ' << std::string(pair.second/400, '*') << '\n';
    }

    return 0;
}