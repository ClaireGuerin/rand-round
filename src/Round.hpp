#ifndef RANDROUND_ROUND_HPP
#define RANDROUND_ROUND_HPP

#include <cmath>
#include <random>
#include <map>

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

    template <typename RENG>
    void plot(const double x, RENG& rng, int nRep) {
        std::map<double, int> hist;
        for(int n=0; n<nRep; ++n) {
            ++hist[randround::round(x, rng)];
        }

        std::cout << "Random rounding of " << x << ":\n";
        for(const auto& pair : hist) {
        std::cout << std::setw(2) << pair.first
                  << ' ' << std::string(pair.second/(nRep/25), '*') 
                  << ' ' << 100.0 * pair.second / static_cast<double>(nRep) << '%' << '\n';
    }
    }
}

#endif