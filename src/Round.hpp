#ifndef RANDROUND_ROUND_HPP
#define RANDROUND_ROUND_HPP

#include <cmath>
#include <random>

namespace randround {

    template <typename RENG>
    double round(const double x, RENG& rng) {
        double floor;
        double dec = std::abs(std::modf(x, &floor));
        std::bernoulli_distribution bDist(dec);
        auto ceil_this = bDist(rng);

        if (ceil_this) {
            if (floor < 0) {
                return floor - 1;
            } else {
                return floor + 1;
            }
        } else {
            return floor; 
        }
    }
}

#endif