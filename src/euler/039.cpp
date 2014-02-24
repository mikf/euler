#include "euler.h"
#include "util/range.h"
#include "util/range.h"
using namespace util;
using namespace math;

// If p is the perimeter of a right angle triangle with integral length sides,
// {a,b,c}, there are exactly three solutions for p = 120.
//
//      {20,48,52}, {24,45,51}, {30,40,50}
//
// For which value of p ≤ 1000, is the number of solutions maximised?

std::size_t num_triangle_solutions(int p)
{
    std::size_t num = 0;

    for(auto a : range(p/2))
    {
        for(auto b : range(a, p/2))
        {
            const int c = p-a-b;
            if(a*a + b*b == c*c)
                ++num;
        }
    }

    return num;
}

std::string euler039()
{
    int result = 0;
    int max    = 0;

    for(auto p : range<1001>())
    {
        const int num = num_triangle_solutions(p);
        if(max < num)
        {
            max = num;
            result = p;
        }
    }

    return std::to_string(result);
}

static bool reg_ = euler::set("39", euler039);
