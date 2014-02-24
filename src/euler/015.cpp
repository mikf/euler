#include "euler.h"
#include <gmpxx.h>
using namespace util;
using namespace math;

// Starting in the top left corner of a 2×2 grid, and only being able to move
// to the right and down, there are exactly 6 routes to the bottom right corner.
//
// How many such routes are there through a 20×20 grid?

std::string euler015()
{
    mpz_class result;
    mpz_bin_uiui(result.get_mpz_t(), 40, 20);
    return result.get_str();
}

static bool reg_ = euler::set("15", euler015);
