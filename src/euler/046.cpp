#include "euler.h"
#include "math/primes.h"
#include "util/range.h"
#include <array>
using namespace util;
using namespace math;

// It was proposed by Christian Goldbach that every odd composite number can be
// written as the sum of a prime and twice a square.
//
//       9 =  7 + 2 × 1^2
//      15 =  7 + 2 × 2^2
//      21 =  3 + 2 × 3^2
//      25 =  7 + 2 × 3^2
//      27 = 19 + 2 × 2^2
//      33 = 31 + 2 × 1^2
//
// It turns out that the conjecture was false.
//
// What is the smallest odd composite that cannot be written as the sum of a
// prime and twice a square?

enum { limit = 10000 };
typedef std::array<bool, limit> array_t;

void fill_array(array_t & num)
{
    int n;
    for(auto p : primes())
    {
        if(p >= limit)
            return;

        for(auto i : range<1, limit>())
        {
            n = p + 2*i*i;
            if(n >= limit)
                break;
            num[n] = true;
        }
    }
}

std::string euler046()
{
    array_t num {false};
    fill_array(num);

    for(std::size_t i = 3; i < limit; i += 2)
    {
        if(not num[i] and not is_prime(i))
            return std::to_string(i);
    }

    return "0";
}

static bool reg_ = euler::set("46", euler046);
