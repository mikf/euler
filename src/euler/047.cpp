#include "euler.h"
#include "util/range.h"
#include "math/primefactors.h"
#include <unordered_set>
using namespace util;
using namespace math;

// The first two consecutive numbers to have two distinct prime factors are:
//
//      14 = 2 × 7
//      15 = 3 × 5
//
// The first three consecutive numbers to have three distinct prime factors are:
//
//      644 = 2² × 7 × 23
//      645 = 3 × 5 × 43
//      646 = 2 × 17 × 19.
//
// Find the first four consecutive integers to have four distinct prime factors.
// What is the first of these numbers?

enum { size = 4 };

bool has_distinct_primefactors(int i)
{
    auto    pf = primefactors(i);
    prime_t pf_current = 0;
    int     pf_count   = 0;

    for(auto it = pf.begin(), end = pf.end(); it != end; ++it)
    {
        if(*it != pf_current)
        {
            pf_current = *it;
            if(++pf_count == size)
            {
                ++it;
                return it == end;
            }
        }
    }
    return false;
}

std::string euler047()
{
    std::unordered_set<prime_t> set;
    std::size_t count = 0;

    for(auto i : range<100000, 1000000>())
    {
        if(has_distinct_primefactors(i))
        {
            if(++count == size)
                return std::to_string(i - size + 1);
        }
        else
        {
            count = 0;
        }
    }

    return "no solution found";
}

static bool reg_ = euler::set("47", euler047);
