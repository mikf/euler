#include "euler.h"
#include "util/range.h"
#include "util/takewhile.h"
#include "util/predicates.h"
#include "math/primes.h"
#include <iostream>
using namespace util;
using namespace math;

// Euler discovered the remarkable quadratic formula:
//
//      n² + n + 41
//
// It turns out that the formula will produce 40 primes for the consecutive
// values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41
// is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly
// divisible by 41.
//
// The incredible formula  n² − 79n + 1601 was discovered, which produces 80
// primes for the consecutive values n = 0 to 79. The product of the
// coefficients, −79 and 1601, is −126479.
//
// Considering quadratics of the form:
//
//      n² + an + b, where |a| < 1000 and |b| < 1000
//
//      where |n| is the modulus/absolute value of n
//      e.g. |11| = 11 and |−4| = 4
//
// Find the product of the coefficients, a and b, for the quadratic expression
// that produces the maximum number of primes for consecutive values of n,
// starting with n = 0.

std::string euler027()
{
    int max = 0;
    int result;

    for(auto b : takewhile(primes(), less<1000>()))
    {
        for(auto a : range<int, -999, 1000, 2>())
        {
            int num = 0;
            for(auto n : range<int, 0, 100>())
            {
                if(not is_prime(n*n + a*n + int(b)))
                    break;
                ++num;
            }
            if(num > max)
            {
                max = num;
                result = a*b;
            }
        }
    }

    return std::to_string(result);
}

static bool reg_ = euler::set("27", euler027);
