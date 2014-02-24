#include "euler.h"
#include "util/sum.h"
#include "util/filter.h"
#include "util/range.h"
#include "math/palindrome.h"
using namespace util;
using namespace math;

// The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
//
// Find the sum of all numbers, less than one million, which are palindromic in
// base 10 and base 2.
//
// (Please note that the palindromic number, in either base, may not include
// leading zeros.)

std::string euler036()
{
    return std::to_string(
        sum(filter(range<1,1000000,2>(),
        [] (int x) { return is_palindrome<10>(x) and is_palindrome<2>(x);}
    )));
}

static bool reg_ = euler::set("36", euler036);
