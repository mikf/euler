#include "euler.h"
#include "util/range.h"
#include <gmpxx.h>
using namespace util;
using namespace math;

// The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
//
// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

std::string euler048()
{
    mpz_class num, tmp;
    for(auto i : range<1, 1001>())
    {
        mpz_ui_pow_ui(tmp.get_mpz_t(), i, i);
        num += tmp;
    }

    std::string result = num.get_str();
    result.erase(result.begin(), result.end()-10);
    return result;
}

static bool reg_ = euler::set("48", euler048);
