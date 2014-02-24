#ifndef MATH_PRIMEFACTORS_H
#define MATH_PRIMEFACTORS_H

#include "primes.h"

namespace math
{

template <class T>
class primefactor_iterator
    : public std::iterator<std::forward_iterator_tag, prime_t>
{
public:
    explicit primefactor_iterator(prime_iterator iter, T value)
        : iter_(iter), value_(value)
    {
        ++(*this);
    }

    constexpr bool operator == (const primefactor_iterator & other) const
    { return value_ == other.value_; }

    constexpr bool operator != (const primefactor_iterator & other) const
    { return !(*this == other); }

    prime_t operator * () const
    { return *iter_; }

    void operator ++ ()
    {
        if(value_ > 1)
        {
            for(; value_ % *iter_ != 0; ++iter_);
            value_ /= *iter_;
        }
        else
        {
            value_ = 0;
        }
    }

private:
    prime_iterator iter_;
    T value_;
};



template <class T>
class primefactor_container
{
public:
    typedef primefactor_iterator<T> iterator;
    typedef primefactor_iterator<T> const_iterator;

    constexpr explicit primefactor_container(T value)
        : value_(value)
    {}

    iterator begin() const { return iterator(primes().begin(), value_); }
    iterator end()   const { return iterator(primes().end(), 0); }

private:
    T value_;
};


template <class T>
constexpr primefactor_container<T> primefactors(T value)
{
    return primefactor_container<T>(value);
}

// template <class T = std::uint32_t>
// std::vector<T> primefactors(T number)
// {
    // static_assert(std::is_integral<T>::value, "Only integral types suported");
//
    // std::vector<std::uint32_t> pfactors;
    // for(auto p : primes( std::sqrt(number) ))
    // {
        // while(number % p == 0)
        // {
            // number /= p;
            // pfactors.push_back(p);
        // }
    // }
    // pfactors.push_back(number);
    // return pfactors;
// }

}

#endif /* MATH_PRIMEFACTORS_H */
