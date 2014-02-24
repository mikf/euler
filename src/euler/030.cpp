#include "euler.h"
#include "util/map.h"
#include "util/sum.h"
#include "util/filter.h"
#include "util/range.h"
#include "math/digits.h"
#include <iostream>
using namespace util;
using namespace math;

// Surprisingly there are only three numbers that can be written as the sum of
// fourth powers of their digits:
//
//      1634 = 1^4 + 6^4 + 3^4 + 4^4
//      8208 = 8^4 + 2^4 + 0^4 + 8^4
//      9474 = 9^4 + 4^4 + 7^4 + 4^4
//
// As 1 = 1^4 is not a sum it is not included. The sum of these numbers is
// 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth
// powers of their digits.

std::string euler030()
{
    std::uint32_t result = 0;

    for(auto i : range<2, 200000>())
    {
        if( i == sum(map(digits(i), [] (int x) { return x*x*x*x*x; })) )
            result += i;
    }

    return std::to_string(result);
}

static bool reg_ = euler::set("30", euler030);
