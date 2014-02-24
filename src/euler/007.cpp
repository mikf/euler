#include "euler.h"
#include "math/primes.h"
#include <iterator>
using namespace util;
using namespace math;

// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
// that the 6th prime is 13.
//
// What is the 10001st prime number?

std::string euler007()
{
    auto p = primes().begin();
    std::advance(p, 10000);
    return std::to_string(*p);
}

static bool reg_ = euler::set("7", euler007);
