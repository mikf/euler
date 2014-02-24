#ifndef UTIL_MAX_H
#define UTIL_MAX_H

#include <algorithm>
#include <functional>

namespace util
{

// template <class C>
// inline auto max(const C& container)
    // -> decltype(*std::max_element(container.begin(), container.end()))
// {
    // return *std::max_element(container.begin(), container.end());
// }

template <class C>
inline auto max(const C& container)
    -> decltype(*container.begin())
{
    auto it   = container.begin();
    auto end  = container.end();
    auto max_ = *it;

    ++it;
    for(; it != end; ++it)
    {
        if(max_ < *it)
            max_ = *it;
    }

    return max_;
}

}

#endif /* UTIL_MAX_H */
