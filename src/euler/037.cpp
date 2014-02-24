#include "euler.h"
#include "util/count.h"
#include "math/digits.h"
#include "math/primes.h"
using namespace util;
using namespace math;

// The number 3797 has an interesting property. Being prime itself, it is
// possible to continuously remove digits from left to right, and remain prime
// at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
// left: 3797, 379, 37, and 3.
//
// Find the sum of the only eleven primes that are both truncatable from left
// to right and right to left.
//
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

static prime_t pow(prime_t base, int exp)
{
    prime_t result = 1;
    for(int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

static bool is_truncatable_prime_left(prime_t p)
{
    auto mod = pow(10, count(digits(p)) - 1);

    p %= mod;
    while(p)
    {
        if(not is_prime(p))
            return false;
        mod /= 10;
        p %= mod;
    }
    return true;
}

static bool is_truncatable_prime_right(prime_t p)
{
    p /= 10;
    while(p)
    {
        if(not is_prime(p))
            return false;
        p /= 10;
    }
    return true;
}

static bool is_truncatable_prime(prime_t p)
{
    return p > 10
        and is_truncatable_prime_left(p)
        and is_truncatable_prime_right(p);
}

std::string euler037()
{
    prime_t result = 0;
    int     count  = 0;

    for(auto p : primes())
    {
        if(is_truncatable_prime(p))
        {
            result += p;
            if(++count == 11)
                break;
        }
    }

    return std::to_string(result);
}

static bool reg_ = euler::set("37", euler037);
