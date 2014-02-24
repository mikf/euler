#include "euler.h"
#include "util/reduce.h"
#include <array>
#include <algorithm>
using namespace util;
using namespace math;

// A permutation is an ordered arrangement of objects. For example, 3124 is one
// possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
// are listed numerically or alphabetically, we call it lexicographic order.
// The lexicographic permutations of 0, 1 and 2 are:
//
//      012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
// 5, 6, 7, 8 and 9?

std::string euler024()
{
    std::array<unsigned char, 10> a {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(auto i = 1; i < 1000000; ++i)
        std::next_permutation(a.begin(), a.end());

    return reduce(a, std::string(), [] (std::string s, unsigned char c)
    {
        s.push_back(c+'0');
        return s;
    });
}

static bool reg_ = euler::set("24", euler024);
