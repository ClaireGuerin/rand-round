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
        auto floor_this = bDist(rng);

        if (floor_this) {
            return floor;
        } else {
            if (floor < 0) {
                return floor - 1;
            } else {
                return floor + 1;
            }
        }
    }
}

#endif