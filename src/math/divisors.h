#ifndef MATH_DIVISORS_H
#define MATH_DIVISORS_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace math
{

template <class T>
std::vector<T> divisors(T num)
{
    using std::sqrt;
    using std::sort;

    std::vector<T> div {1, num};
    std::uint32_t i = 2;
    std::uint32_t e = sqrt(num);

    for(; i <= e; ++i)
    {
        if(num % i == 0)
        {
            div.push_back(i);
            div.push_back(num / i);
        }
    }
    if(e*e == num)
        div.pop_back();

    // sort(div.begin(), div.end());
    return div;
}

template <class T>
std::vector<T> proper_divisors(T num)
{
    using std::sqrt;
    std::vector<T> div {1};
    std::uint32_t i = 2;
    std::uint32_t e = sqrt(num);

    for(; i <= e; ++i)
        if(num % i == 0)
        {
            div.push_back(i);
            div.push_back(num / i);
        }
    if(e*e == num)
        div.pop_back();
    return div;
}

}

#endif /* MATH_DIVISORS_H */
