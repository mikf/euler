#ifndef UTIL_ZIP_H
#define UTIL_ZIP_H

#include <tuple>
#include <iterator>
#include "indices.h"

namespace util
{


// Helper class to implement operator== (see below) and operator++
template <typename Tuple, std::size_t N, std::size_t M>
struct zip_helper
{
    // Return true if at least one iterator is equal to another.
    // This is necessary to allow for a working comparison with an end-iterator
    // and, in turn, range-based for loops.
    static constexpr inline bool equal(const Tuple & lhs, const Tuple & rhs)
    {
        return std::get<N>(lhs) == std::get<N>(rhs)
            ? true
            : zip_helper<Tuple, N+1, M>::equal(lhs, rhs);
    }

    static inline void increment(Tuple & t)
    {
        ++std::get<N>(t);
        zip_helper<Tuple, N+1, M>::increment(t);
    }

};

template <typename Tuple, std::size_t M>
struct zip_helper<Tuple, M, M>
{
    static constexpr inline bool equal(const Tuple &, const Tuple &)
    { return false; }

    static constexpr inline void increment(Tuple &)
    {}
};



template <typename... Params>
class zip_iterator
    : public std::iterator<std::input_iterator_tag,
                std::tuple<typename std::iterator_traits<
                    typename Params::const_iterator
                >::value_type...>
            >
{
public:
    typedef std::tuple<typename Params::const_iterator...> base_iterator_tuple;
    typedef typename zip_iterator::value_type value_type;

    constexpr inline zip_iterator(typename Params::const_iterator&&... iters)
        : iters_(std::forward<typename Params::const_iterator>(iters)...)
    {}

    constexpr inline bool operator == (const zip_iterator& other)
    {
        return zip_helper<base_iterator_tuple, 0, sizeof...(Params)>
            ::equal(iters_, other.iters_);
    }

    constexpr inline bool operator != (const zip_iterator& other)
    { return !(*this == other); }

    constexpr inline value_type operator * () const
    { return dereference( IndicesFor<Params...>{} ); }

    inline void operator ++ ()
    {
        zip_helper<base_iterator_tuple, 0, sizeof...(Params)>
            ::increment(iters_);
    }

private:
    base_iterator_tuple iters_;

    template <typename... Ps>
    friend bool equal(const zip_iterator&, const zip_iterator&);

    template <std::size_t... Indices>
    constexpr inline value_type dereference(indices<Indices...>) const
    {
        return std::forward_as_tuple(
            *std::get<Indices>(iters_)...
        );
    }
};



template <typename... Params>
bool equal(const zip_iterator<Params...>& lhs,
           const zip_iterator<Params...>& rhs)
{
    return lhs.iters_ == rhs.iters_;
}



template <typename... Params>
class zip_container
{
public:
    typedef zip_iterator<Params...> iterator;
    typedef iterator                const_iterator;

    constexpr inline zip_container(const Params&... containers)
        : containers_(containers...)
    {}

    constexpr inline iterator begin() const
    { return begin_impl( IndicesFor<Params...>{} ); }

    constexpr inline iterator end() const
    { return end_impl( IndicesFor<Params...>{} ); }

private:
    std::tuple<const Params&...> containers_;

    template <std::size_t... Indices>
    constexpr inline iterator begin_impl(indices<Indices...>) const
    { return { std::get<Indices>(containers_).begin()... }; }

    template <std::size_t... Indices>
    constexpr inline iterator end_impl(indices<Indices...>) const
    { return { std::get<Indices>(containers_).end()... }; }
};



template <typename... Params>
constexpr inline zip_container<Params...> zip(const Params&... containers)
{
    return { containers... };
}



}

#endif /* UTIL_ZIP_H */
