#include "euler.h"
#include "math/primefactors.h"
#include "util/max.h"
using namespace util;
using namespace math;

// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?

std::string euler003()
{
    return std::to_string(
        max( primefactors(600851475143ULL) )
    );
}

static bool reg_ = euler::set("3", euler003);
