#include "euler.h"
#include "util/range.h"
#include "util/map.h"
#include "math/collatz.h"
#include <cstdint>
#include <algorithm>
#include <tuple>
#include <iterator>
using namespace util;
using namespace math;

// The following iterative sequence is defined for the set of positive integers:
//
//      n → n/2 (n is even)
//      n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following
// sequence:    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//
// It can be seen that this sequence (starting at 13 and finishing at 1)
// contains 10 terms. Although it has not been proved yet (Collatz Problem), it
// is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.

std::string euler014()
{
    auto numbers = range<std::uint32_t, 13,1000000>();
    auto lengths = map(numbers, [] (std::uint32_t x)
    {
        auto c = collatz(x);
        return std::make_pair( x, std::distance(c.begin(), c.end())+1 );
    });

    std::uint32_t num = 0;
    std::uint32_t max = 0;
    for(auto i : lengths)
    {
        if(i.second > max)
            std::tie(num, max) = i;
    }

    return std::to_string(num);
}

static bool reg_ = euler::set("14", euler014);
