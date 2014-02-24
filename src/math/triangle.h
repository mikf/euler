#ifndef MATH_TRIANGLE_NUMBERS_H
#define MATH_TRIANGLE_NUMBERS_H

#include <vector>
#include <iterator>
#include <cstdint>

namespace math
{

class prime_iterator;
class prime_container;


typedef std::uint32_t triangle_t;

class triangle_iterator
    : public std::iterator<std::forward_iterator_tag, triangle_t>
{
public:
    typedef triangle_t value_type;

    constexpr explicit triangle_iterator(triangle_t value)
        : value_(value), step_(1)
    {}

    constexpr bool operator == (const triangle_iterator & other) const
    { return value_ == other.value_; }

    constexpr bool operator != (const triangle_iterator & other) const
    { return !(*this == other); }

    constexpr value_type operator * () const
    { return value_; }

    void operator ++ ()
    {
        ++step_;
        value_ += step_;
    }

private:
    triangle_t value_, step_;
};



class triangle_container
{
public:
    typedef triangle_iterator iterator;
    typedef triangle_iterator const_iterator;

    constexpr explicit triangle_container(){}

    iterator begin() const { return iterator(1); }
    iterator end()   const { return iterator(0); }
};



constexpr triangle_container triangle()
{
    return triangle_container();
}

}

#endif /* MATH_TRIANGLE_NUMBERS_H */
