#include "euler.h"
#include "util/range.h"
#include "util/filter.h"
#include "util/sum.h"
using namespace util;

// If we list all the natural numbers below 10 that are multiples of 3 or 5, we
// get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

std::string euler001()
{
    return std::to_string(
        sum(filter(range<1000>(),
            [] (int x) { return x % 3 == 0 || x % 5 == 0; }
        ))
    );
}

static bool reg_ = euler::set("1", euler001);
