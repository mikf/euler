#include "euler.h"
#include <gmpxx.h>
using namespace util;
using namespace math;

// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

std::string euler005()
{
    mpz_class num = 1;

    for(int i = 2; i < 20; ++i)
        mpz_lcm_ui(num.get_mpz_t(), num.get_mpz_t(), i);

    return num.get_str();
}

static bool reg_ = euler::set("5", euler005);
