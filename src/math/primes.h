#ifndef MATH_PRIMES_H
#define MATH_PRIMES_H

#include <vector>
#include <iterator>
#include <cstdint>

namespace math
{

class prime_iterator;
class prime_container;


typedef std::uint32_t prime_t;
typedef std::vector<prime_t> prime_list_t;

class prime_iterator
    : public std::iterator<std::forward_iterator_tag, prime_t>
{
public:
    constexpr explicit prime_iterator(std::size_t index)
        : index_(index)
    {}

    constexpr bool operator == (const prime_iterator & other) const
    { return index_ == other.index_; }

    constexpr bool operator != (const prime_iterator & other) const
    { return !(*this == other); }

    inline value_type operator * () const;
    void operator ++ ();

private:
    std::size_t index_;
};



class prime_container
{
public:
    typedef prime_iterator iterator;
    typedef prime_iterator const_iterator;

    static prime_list_t primes;
    static void generate_next();

    constexpr explicit prime_container(){}

    constexpr iterator begin() const { return iterator( 0); }
    constexpr iterator end()   const { return iterator(-1); }
};

inline prime_iterator::value_type prime_iterator::operator * () const
{ return prime_container::primes[index_]; }


constexpr prime_container primes()
{
    return prime_container();
}

bool is_prime(prime_t p);

template <class T>
inline bool is_prime(T p)
{
    if(p <= 1)
        return false;
    return is_prime(prime_t(p));
}

}

#endif /* MATH_PRIMES_H */
