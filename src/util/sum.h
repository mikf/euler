#ifndef UTIL_SUM_H
#define UTIL_SUM_H

#include <numeric>
#include <iterator>

namespace util
{

// Wrapper for calling std::accumulate with the begin() and end() iterators of
// a given container (e.g. vector, list, custom container-class, ...)
template <class C>
inline auto sum(const C& container)
    -> decltype(std::accumulate(container.begin(), container.end(),
        typename std::iterator_traits<typename C::iterator>::value_type()))
{
    return std::accumulate(container.begin(), container.end(),
        typename std::iterator_traits<typename C::iterator>::value_type());
}

template <class T, class C>
inline auto sum(const C& container, T init = T())
    -> decltype(std::accumulate(container.begin(), container.end(), init))
{
    return std::accumulate(container.begin(), container.end(), init);
}

}

#endif /* UTIL_SUM_H */
