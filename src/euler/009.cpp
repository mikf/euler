#include "euler.h"
using namespace util;
using namespace math;

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for
// which,
//          a^2 + b^2 = c^2
//
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

std::string euler009()
{
    int a, b, c;
    for(a = 1; a <= 998; ++a)
    {
        for(b = 1; b <= 999-a; ++b)
        {
            c = 1000-a-b;
            if(a*a + b*b == c*c)
                return std::to_string(a*b*c);
        }
    }
    return "0";
}

static bool reg_ = euler::set("9", euler009);
