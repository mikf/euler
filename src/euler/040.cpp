#include "euler.h"
#include "util/range.h"
#include "util/map.h"
#include "util/reduce.h"
#include <array>
#include <functional>
using namespace util;
using namespace math;

// An irrational decimal fraction is created by concatenating the positive
// integers:
//
//      0.123456789101112131415161718192021...
//
// It can be seen that the 12th digit of the fractional part is 1.
//
// If d(n) represents the nth digit of the fractional part, find the value of
// the following expression.
//
// d(1) × d(10) × d(100) × d(1000) × d(10000) × d(100000) × d(1000000)

std::string euler040()
{
    std::string d;
    int result = 1;

    d.reserve(1001000);
    for(auto i : range<1000000>())
    {
        d += std::to_string(i);
        if(d.size() > 1000000)
            break;
    }

    for(auto a : {d[1], d[10], d[100], d[1000], d[10000], d[100000], d[1000000]})
        result *= int(a-'0');

    return std::to_string(result);
}

static bool reg_ = euler::set("40", euler040);
