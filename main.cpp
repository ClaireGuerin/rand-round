#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include "src/Round.hpp"

int main() {

    std::default_random_engine reng;

    // `7.5` becomes 7 (floored) with 50% chance, and becomes 8 (ceiled) with 50% chance.
    double num50 = 7.5;
    randround::plot(num50, reng, 10000);

    // `6.6` becomes 6 (floored) with 40% chance, and becomes 7 (ceiled) with 60% chance.
    double num60 = 6.6;
    randround::plot(num60, reng, 10000);

    // `-2.3` becomes -2 (floored) with 30% chance, and becomes -3 (ceiled) with 70% chance.
    double num30 = -2.3;
    randround::plot(num30, reng, 10000);

    return 0;
}