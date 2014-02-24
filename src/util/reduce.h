#ifndef UTIL_REDUCE_H
#define UTIL_REDUCE_H

#include <numeric>
#include <iterator>
#include <type_traits>

namespace util
{

// Wrapper for calling std::accumulate with the begin() and end() iterators of
// a given container (e.g. vector, list, custom container-class, ...)

template <class C, class BinaryOperation>
auto reduce(const C& container, BinaryOperation op)
    -> decltype(std::accumulate(container.begin(), container.end(),
        *container.begin(), op))
{
    typedef typename std::iterator_traits<typename C::iterator>::value_type T;

    auto begin = container.begin();
    auto end   = container.end();
    if(begin == end)
        return T();

    auto init = *begin;
    return std::accumulate(++begin, end, init, op);
}

template <class C, class T, class BinaryOperation>
inline auto reduce(const C& container, T&& init, BinaryOperation op)
    -> decltype(std::accumulate(container.begin(), container.end(), init, op))
{
    return std::accumulate(container.begin(), container.end(), init, op);
}

}
#endif /* UTIL_REDUCE_H */
