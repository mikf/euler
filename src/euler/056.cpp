#include "euler.h"
#include "util/range.h"
#include "util/sum.h"
#include "math/digits.h"
#include <gmpxx.h>
using namespace util;
using namespace math;

// A googol (10^100) is a massive number: one followed by one-hundred zeros;
// 100^100 is almost unimaginably large: one followed by two-hundred zeros.
// Despite their size, the sum of the digits in each number is only 1.
//
// Considering natural numbers of the form, ab, where a, b < 100, what is the
// maximum digital sum?

std::string euler056()
{
    mpz_class num;
    std::uint32_t result = 0;

    for(auto a : range<1, 100>())
    {
        for(auto b : range<1, 100>())
        {
            mpz_ui_pow_ui(num.get_mpz_t(), a, b);
            result = std::max(result, sum(digits(num)));
        }
    }
    return std::to_string(result);
}

static bool reg_ = euler::set("56", euler056);
