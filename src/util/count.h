#ifndef UTIL_COUNT_H
#define UTIL_COUNT_H

#include <iterator>

namespace util
{

template <class C>
inline auto count(const C& container)
    -> decltype(std::distance(container.begin(), container.end()))
{
    return std::distance(container.begin(), container.end());
}

}

#endif /* UTIL_COUNT_H */
