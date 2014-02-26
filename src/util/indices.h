#ifndef UTIL_VARIADIC_TEMPLATE_INDICES_H
#define UTIL_VARIADIC_TEMPLATE_INDICES_H

#include <cstddef>
#include <tuple>

namespace util
{

template <std::size_t... Indices>
struct indices {};

template <std::size_t N, std::size_t... Indices>
struct build_indices
    : public build_indices<N-1, N-1, Indices...> {};

template <std::size_t... Indices>
struct build_indices<0, Indices...>
    : public indices<Indices...> {};

template <typename... Params>
using IndicesFor = build_indices<sizeof...(Params)>;

}

#endif /* UTIL_VARIADIC_TEMPLATE_INDICES_H */
