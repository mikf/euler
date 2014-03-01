#include "euler.h"
#include <fstream>
#include <cmath>
using namespace util;
using namespace math;

// Comparing two numbers written in index form like 2^11 and 3^7 is not
// difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.
//
// However, confirming that 632382^518061 > 519432^525806 would be much more
// difficult, as both numbers contain over three million digits.
//
// Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text
// file containing one thousand lines with a base/exponent pair on each line,
// determine which line number has the greatest numerical value.
//
// NOTE: The first two lines in the file represent the numbers in the example
// given above.

std::string euler099()
{
    std::ifstream file {"res/base_exp.txt"};
    double        num, max = 0.0;
    unsigned int  base, exp;
    unsigned int  line = 0;
    unsigned int  max_line;
    char          d;

    while(line < 1000)
    {
        ++line;
        file >> base >> d >> exp;
        num = exp * std::log(base);

        if(max < num)
        {
            max      = num;
            max_line = line;
        }
    }

    return std::to_string(max_line);
}

static bool reg_ = euler::set("99", euler099);
