#include "euler.h"
#include "util/takewhile.h"
#include "util/predicates.h"
#include "util/filter.h"
#include "util/count.h"
#include "math/primes.h"
#include "math/digits.h"
using namespace util;
using namespace math;

// The number, 197, is called a circular prime because all rotations of the
// digits: 197, 971, and 719, are themselves prime.
//
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
// 73, 79, and 97.
//
// How many circular primes are there below one million?

static prime_t pow(prime_t base, int exp)
{
    prime_t result = 1;
    for(int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

static prime_t circulate(prime_t p)
{
    prime_t t, s;

    s = count(digits(p)) - 1;
    t = p % 10;
    return p / 10 + t * pow(10, s);
}

static bool is_circular_prime(prime_t p)
{
    prime_t c = circulate(p);
    while(c != p)
    {
        if(not is_prime(c))
            return false;
        c = circulate(c);
    }
    return true;
}

std::string euler035()
{
    return std::to_string(
        count(filter(
            takewhile(primes(), less<1000000>()),
            is_circular_prime
        ))
    );
}

static bool reg_ = euler::set("35", euler035);
