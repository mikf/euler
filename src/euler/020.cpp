#include "euler.h"
#include "util/sum.h"
#include "util/map.h"
#include <gmpxx.h>
using namespace util;
using namespace math;

// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27
//
// Find the sum of the digits in the number 100!

std::string euler020()
{
    mpz_class num;
    mpz_fac_ui(num.get_mpz_t(), 100);

    return std::to_string(
        sum(map(num.get_str(), to_digits()))
    );
}

static bool reg_ = euler::set("20", euler020);
