#include "euler.h"
#include "util/range.h"
#include "math/palindrome.h"
#include <algorithm>
using namespace util;
using namespace math;

// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.

std::string euler004()
{
    auto max = 0;
    auto numbers = range<100, 1000>();

    for(auto i : numbers)
    {
        for(auto j : numbers)
        {
            auto k = i * j;
            if(is_palindrome(k))
                max = std::max(max, k);
        }
    }
    return std::to_string(max);
}

static bool reg_ = euler::set("4", euler004);
