#include "euler.h"
#include "util/sum.h"
#include "util/map.h"
#include "util/range.h"
#include <cstdint>
using namespace util;
using namespace math;

// Starting with the number 1 and moving to the right in a clockwise direction
// a 5 by 5 spiral is formed as follows:
//
//      21 22 23 24 25
//      20  7  8  9 10
//      19  6  1  2 11
//      18  5  4  3 12
//      17 16 15 14 13
//
// It can be verified that the sum of the numbers on the diagonals is 101.
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
// formed in the same way?

std::string euler028()
{
    std::uint64_t result = 1;

    result += sum(map(range<std::uint64_t, 1, 501>(),
        [] (std::uint64_t x) { return 4ULL*x*x - 2ULL*x + 1ULL; }));
    result += sum(map(range<std::uint64_t, 1, 501>(),
        [] (std::uint64_t x) { return 4ULL*x*x + 0ULL*x + 1ULL; }));
    result += sum(map(range<std::uint64_t, 1, 501>(),
        [] (std::uint64_t x) { return 4ULL*x*x + 2ULL*x + 1ULL; }));
    result += sum(map(range<std::uint64_t, 1, 501>(),
        [] (std::uint64_t x) { return 4ULL*x*x + 4ULL*x + 1ULL; }));

    return std::to_string(result);
}

static bool reg_ = euler::set("28", euler028);
