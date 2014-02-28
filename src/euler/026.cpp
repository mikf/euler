#include "euler.h"
#include "util/range.h"
#include "util/map.h"
#include "util/max.h"
#include <set>
using namespace util;
using namespace math;
using std::to_string;

// A unit fraction contains 1 in the numerator. The decimal representation of
// the unit fractions with denominators 2 to 10 are given:
//
//      1/2  = 0.5
//      1/3  = 0.(3)
//      1/4  = 0.25
//      1/5  = 0.2
//      1/6  = 0.1(6)
//      1/7  = 0.(142857)
//      1/8  = 0.125
//      1/9  = 0.(1)
//      1/10 = 0.1
//
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
// seen that 1/7 has a 6-digit recurring cycle.
//
// Find the value of d < 1000 for which 1/d contains the longest recurring
// cycle in its decimal fraction part.

template <typename T1, typename T2>
std::string to_string(const std::pair<T1, T2>& t)
{
    return "(" + to_string(std::get<0>(t)) +
          ", " + to_string(std::get<1>(t)) + ")";
}

struct cycle
{
    typedef std::map<int, int> map_t;
    typedef map_t::const_iterator iter_t;

    template <typename T>
    std::pair<std::size_t, T> operator () (const T& div) const
    {
        return {size(div), div};
    }

    template <typename T>
    std::size_t size(const T& div) const
    {
        map_t  lookup = { {1, 0} };
        iter_t pos;
        int    step = 0;
        int    rem = 1;

        while(true)
        {
            // caculate one digit of the fraction
            rem = (10*rem) % div;
            if(rem == 0)
                return 0;
            ++step;

            // insert the reminder into a lookup table
            pos = lookup.find(rem);
            if(pos == lookup.end())
                lookup.insert(pos, {rem, step});
            else
                // the same reminder was already seen previously -> cycle
                break;
        }
        return step - pos->second;
    }

    template<typename T>
    std::string to_string(const T& div)
    {
        std::string str {"0."};
        map_t  lookup = { {1, 0} };
        iter_t pos;
        int    step = 0;
        int    rem = 1;

        while(true)
        {
            // caculate one digit of the fraction
            str += to_string((10*rem) / div);
            rem  = (10*rem) % div;
            if(rem == 0)
                break;
            ++step;

            // insert the reminder into a lookup table
            pos = lookup.find(rem);
            if(pos == lookup.end())
                lookup.insert(pos, {rem, step});
            else
            {
                // the same reminder was already seen previously -> cycle
                str += "...";
                break;
            }
        }
        return str;
    }
};

std::string euler026()
{
    return to_string(
        max(map(range<1, 1000>(), cycle())).second
    );
}

static bool reg_ = euler::set("26", euler026);
