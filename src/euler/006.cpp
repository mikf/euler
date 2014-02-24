#include "euler.h"
#include "util/map.h"
#include "util/sum.h"
#include "util/range.h"
using namespace util;
using namespace math;

// The sum of the squares of the first ten natural numbers is,
//      1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is,
//      (1 + 2 + ... + 10)^2 = 552 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum.

std::string euler006()
{
    auto numbers = range<1, 101>();

    auto sum_squares = sum(map(numbers,
        [] (int x) { return x*x; }
    ));

    auto square_sum = sum(numbers);
    square_sum = square_sum * square_sum;

    return std::to_string(square_sum - sum_squares);
}

static bool reg_ = euler::set("6", euler006);
