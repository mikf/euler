#include <iostream>
#include "euler/euler.h"
#include "util/foreach.h"

int main(int argc, char * argv[])
{
    for(auto arg : each(argv+1, argc-1))
    {
        euler::func_t func = euler::get(arg);
        if(func)
        {
            std::cout << arg << ": ";
            std::cout.flush();
            std::cout << func() << std::endl;
        }
        else
        {
            std::cout << arg << ": -" << std::endl;
        }
    }
    return 0;
}
