#include "euler.h"
#include <array>
#include <algorithm>
#include <cstdint>
using namespace util;
using namespace math;

// The number, 1406357289, is a 0 to 9 pandigital number because it is made up
// of each of the digits 0 to 9 in some order, but it also has a rather
// interesting sub-string divisibility property.
//
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
// note the following:
//
//      d2d3d4  = 406 is divisible by 2
//      d3d4d5  = 063 is divisible by 3
//      d4d5d6  = 635 is divisible by 5
//      d5d6d7  = 357 is divisible by 7
//      d6d7d8  = 572 is divisible by 11
//      d7d8d9  = 728 is divisible by 13
//      d8d9d10 = 289 is divisible by 17
//
// Find the sum of all 0 to 9 pandigital numbers with this property.

template <class T>
static bool is_substring_divisible(const T& a)
{
    unsigned int val;

    val = a[7]*100 + a[8]*10 + a[9];
    if(val % 17 != 0) return false;

    val /= 10;
    val += a[6]*100;
    if(val % 13 != 0) return false;

    val /= 10;
    val += a[5]*100;
    if(val % 11 != 0) return false;

    val /= 10;
    val += a[4]*100;
    if(val %  7 != 0) return false;

    val /= 10;
    val += a[3]*100;
    if(val %  5 != 0) return false;

    val /= 10;
    val += a[2]*100;
    if(val %  3 != 0) return false;

    val /= 10;
    val += a[1]*100;
    if(val %  2 != 0) return false;

    return true;
}

static bool is_substring_divisible_2(std::uint64_t num)
{
    return num /       1 % 1000 % 17 == 0
       and num /      10 % 1000 % 13 == 0
       and num /     100 % 1000 % 11 == 0
       and num /    1000 % 1000 %  7 == 0
       and num /   10000 % 1000 %  5 == 0
       and num /  100000 % 1000 %  3 == 0
       and num / 1000000 % 1000 %  2 == 0;
}

std::string euler043()
{
    std::uint64_t result = 0;
    std::array<unsigned int, 10> num = {
        0, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    while(std::next_permutation(num.begin(), num.end()))
    {
        if(is_substring_divisible(num))
        {
            result += num[0] * 1000000000ULL
                   +  num[1] *  100000000ULL
                   +  num[2] *   10000000ULL
                   +  num[3] *    1000000ULL
                   +  num[4] *     100000ULL
                   +  num[5] *      10000ULL
                   +  num[6] *       1000ULL
                   +  num[7] *        100ULL
                   +  num[8] *         10ULL
                   +  num[9] *          1ULL;
        }
    }

/*
 *  ~2 times slower method
 *
 *  while(std::next_permutation(num.begin(), num.end()))
 *  {
 *      tmp = num[0] * 1000000000ULL
 *         +  num[1] *  100000000ULL
 *         +  num[2] *   10000000ULL
 *         +  num[3] *    1000000ULL
 *         +  num[4] *     100000ULL
 *         +  num[5] *      10000ULL
 *         +  num[6] *       1000ULL
 *         +  num[7] *        100ULL
 *         +  num[8] *         10ULL
 *         +  num[9] *          1ULL;
 *      if(is_substring_divisible_2(tmp))
 *          result += tmp;
 *  }
 */

    return std::to_string(result);
}

static bool reg_ = euler::set("43", euler043);
