#include "euler.h"
#include "util/sum.h"
#include "util/range.h"
#include "util/filter.h"
#include "util/map.h"
#include "math/digits.h"
using namespace util;
using namespace math;

// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
//
// Find the sum of all numbers which are equal to the sum of the factorial of
// their digits.
//
// Note: as 1! = 1 and 2! = 2 are not sums they are not included.

static const std::array<int, 10> fac_{
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
};

static constexpr int factorial(int x)
{
    return fac_[x];
}

static bool is_digit_factorial(int x)
{
    return x == sum(map(digits(x), factorial));
}

std::string euler034()
{
    return std::to_string(
        sum(filter(range<10, 1000000>(), is_digit_factorial))
    );
}

static bool reg_ = euler::set("34", euler034);
