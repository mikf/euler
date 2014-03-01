#include "euler.h"
#include "util/range.h"
#include "math/digits.h"
#include <cstdint>
#include <algorithm>
using namespace util;
using namespace math;

// It can be seen that the number, 125874, and its double, 251748, contain
// exactly the same digits, but in a different order.
//
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
// contain the same digits.

static bool is_permuted_multiple(std::uint32_t num)
{
    auto d1 = digits(num);
    for(auto n : range<2, 7>())
    {
        auto d2 = digits(num*n);
        if(not std::is_permutation(d1.begin(), d1.end(), d2.begin()))
            return false;
    }
    return true;
}

std::string euler052()
{
    std::uint32_t start = 100;

    while(true)
    {
        for(auto i : range(start, (start*10) / 6 + 1))
        {
            if(is_permuted_multiple(i))
                return std::to_string(i);
        }
        start *= 10;
    }

    return "no solution found";
}

static bool reg_ = euler::set("52", euler052);
