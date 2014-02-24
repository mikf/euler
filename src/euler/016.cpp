#include "euler.h"
#include "util/sum.h"
#include "util/map.h"
#include "util/range.h"
#include "math/digits.h"
#include <cstdint>
#include <vector>
#include <gmpxx.h>
using namespace util;
using namespace math;

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?

std::string euler016()
{
    mpz_class num;
    mpz_ui_pow_ui(num.get_mpz_t(), 2, 1000);

    return std::to_string(
        sum( map(num.get_str(), to_digits()) )
    );
}

static bool reg_ = euler::set("16", euler016);
