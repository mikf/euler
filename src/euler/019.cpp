#include "euler.h"
#include "util/range.h"
#include "util/map.h"
#include "util/sum.h"
#include <array>
using namespace util;
using namespace math;

// You are given the following information, but you may prefer to do some
// research for yourself.
//
//    - 1 Jan 1900 was a Monday.
//
//    - Thirty days has September,
//      April, June and November.
//      All the rest have thirty-one,
//      Saving February alone,
//      Which has twenty-eight, rain or shine.
//      And on leap years, twenty-nine.
//
//    - A leap year occurs on any year evenly divisible by 4, but not on a
//      century unless it is divisible by 400.
//
// How many Sundays fell on the first of the month during the twentieth century
// (1 Jan 1901 to 31 Dec 2000)?

constexpr std::array<int, 12> days_normal = {
//  Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dez
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
constexpr std::array<int, 12> days_leap = {
//  Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dez
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

constexpr bool is_leap_year(int year)
{
    return year %   4 == 0
      and (year % 100 != 0 or year % 400 == 0);
}

constexpr int num_days(int year)
{
    return is_leap_year(year) ? 366 : 365;
}

std::string euler019()
{
    int sundays = 0;
    int d = num_days(1900) % 7;

    for(auto year : range<1901, 2001>())
    {
        for(auto days : is_leap_year(year) ? days_leap : days_normal)
        {
            if(d == 6)
                ++sundays;
            d = (d + days) % 7;
        }
    }

    return std::to_string(sundays);
}

static bool reg_ = euler::set("19", euler019);
