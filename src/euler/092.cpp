#include "euler.h"
#include "util/range.h"
#include "util/map.h"
#include "util/sum.h"
#include "math/digits.h"
using namespace util;
using namespace math;

static constexpr unsigned int sq[] = {
    0, 1, 4, 9, 16, 25, 36, 49, 64, 81
};

struct digit_squares
{
    constexpr unsigned int operator () (unsigned int n)
    { return sq[n]; }
};

std::string euler092()
{
    unsigned int count = 0;
    digit_squares ds;

    for(auto v : range<unsigned int, 1, 10000000>())
    {
        while(v != 1 and v != 89)
            v = sum(map(digits(v), ds));
        if(v == 89)
            ++count;
    }
    return std::to_string(count);
}

static bool reg_ = euler::set("92", euler092);
