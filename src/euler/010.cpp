#include "euler.h"
#include "util/sum.h"
#include "util/takewhile.h"
#include "util/predicates.h"
#include "util/range.h"
#include "math/primes.h"
#include <iostream>
using namespace util;
using namespace math;

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.

std::string euler010()
{
    return std::to_string(
        sum(takewhile( primes(), less<2000000>() ))
    );
}

static bool reg_ = euler::set("10", euler010);
