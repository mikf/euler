#ifndef MATH_TRIANGLE_NUMBERS_H
#define MATH_TRIANGLE_NUMBERS_H

#include <iterator>
#include <cstdint>

namespace math
{

typedef std::uint32_t triangle_t;

class triangle_iterator
    : public std::iterator<std::forward_iterator_tag, triangle_t>
{
public:
    typedef triangle_t value_type;

    constexpr inline explicit triangle_iterator(triangle_t value)
        : value_(value), step_(1)
    {}

    constexpr inline bool operator == (const triangle_iterator & other) const
    { return value_ == other.value_; }

    constexpr inline bool operator != (const triangle_iterator & other) const
    { return !(*this == other); }

    constexpr inline value_type operator * () const
    { return value_; }

    inline void operator ++ ()
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

    constexpr inline explicit triangle_container(){}

    constexpr inline iterator begin() const { return iterator(1); }
    constexpr inline iterator end()   const { return iterator(0); }
};



constexpr inline triangle_container triangle()
{
    return {};
}

}

#endif /* MATH_TRIANGLE_NUMBERS_H */
