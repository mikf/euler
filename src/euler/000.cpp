#include "euler.h"
using namespace util;
using namespace math;

std::string euler000()
{
    return std::to_string(
        0
    );
}

static bool reg_ = euler::set("0", euler000);
