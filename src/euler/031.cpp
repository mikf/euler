#include "euler.h"
#include "util/range.h"
#include <array>
#include <vector>
using namespace util;
using namespace math;

// In England the currency is made up of pound, £, and pence, p, and there are
// eight coins in general circulation:
//
//      1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
//
// It is possible to make £2 in the following way:
//
//      1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
//
// How many different ways can £2 be made using any number of coins?

static constexpr int size = 8;

static constexpr std::array< int, size > value = {
    1, 2, 5, 10, 20, 50, 100, 200
};

std::string euler031()
{
    std::vector< std::array<int, size> > T;

    // fill lookup table t with initial values
    T.push_back({1, 1, 1, 1, 1, 1, 1, 1});
    for(auto i : range<1, 201>())
        T.push_back({0, 0, 0, 0, 0, 0, 0, 0});

    // fill table via dynamic programming
    for(auto N : range<1, 201>())
    {
        auto combinations = 0;
        for(auto V : range<0, size>())
        {
            if(value[V] <= N)
                combinations += T[N-value[V]][V];
            T[N][V] = combinations;
        }
    }

    return std::to_string(
        T[200][size-1]
    );
}

static bool reg_ = euler::set("31", euler031);
