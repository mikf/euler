#include "euler.h"
#include "util/sum.h"
#include "util/range.h"
#include "util/range.h"
#include "math/digits.h"
#include <unordered_set>
#include <iostream>
using namespace util;
using namespace math;

// We shall say that an n-digit number is pandigital if it makes use of all the
// digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
// through 5 pandigital.
//
// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
// multiplicand, multiplier, and product is 1 through 9 pandigital.
//
// Find the sum of all products whose multiplicand/multiplier/product identity
// can be written as a 1 through 9 pandigital.
//
// HINT: Some products can be obtained in more than one way so be sure to only
// include it once in your sum.

bool is_pandigital_multiple(int a, int b)
{
    std::array<bool, 10> set {false};
    int num = 0;

    for(auto d : {digits(a), digits(b), digits(a*b)})
    {
        for(auto n : d)
        {
            if(set[n] or n == 0)
                return false;
            set[n] = true;
            ++num;
        }
    }
    return num == 9;
}

std::string euler032()
{
    std::unordered_set<int> products;

    for(auto i : range<2, 1000>())
    {
        for(auto j : range(i+1, 10000))
        {
            const int tmp = i*j;
            if(tmp >= 10000)
                break;
            if(is_pandigital_multiple(i, j))
                products.insert(tmp);
        }
    }

    return std::to_string( sum(products) );
}

static bool reg_ = euler::set("32", euler032);
