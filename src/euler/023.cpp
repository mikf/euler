#include "euler.h"
#include "util/sum.h"
#include "util/filter.h"
#include "util/range.h"
#include "math/divisors.h"
#include <set>
#include <unordered_set>
#include <iterator>
#include <iostream>
using namespace util;
using namespace math;

// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number. For example, the sum of the proper divisors of
// 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper divisors is less than
// n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
// number that can be written as the sum of two abundant numbers is 24. By
// mathematical analysis, it can be shown that all integers greater than
// 28123 can be written as the sum of two abundant numbers. However, this upper
// limit cannot be reduced any further by analysis even though it is known that
// the greatest number that cannot be expressed as the sum of two abundant
// numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the sum
// of two abundant numbers.

bool is_abundant(int x)
{
    return x < sum(proper_divisors(x));
}

std::string euler023()
{
    enum { limit = 28124 };
    auto nlist = range<1, limit>();
    auto alist = filter(nlist, is_abundant);

    std::unordered_set<int> numbers  {nlist.begin(), nlist.end()};
    std::unordered_set<int> abundant {alist.begin(), alist.end()};

    auto end = abundant.end();
    for(auto i1 = abundant.begin(); i1 != end; ++i1)
    {
        for(auto i2 = i1; i2 != end; ++i2)
        {
            const auto tmp = *i1 + *i2;
            if(tmp < limit)
                numbers.erase(tmp);
        }
    }

    return std::to_string(sum(numbers));
}

static bool reg_ = euler::set("23", euler023);
