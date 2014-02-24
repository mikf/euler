#ifndef MATH_COLLATZ_H
#define MATH_COLLATZ_H

#include <iterator>
#include <type_traits>

namespace math
{

// forward declarations
template <class T>
class collatz_iterator;
template <class T>
class collatz_container;



template <class T>
class collatz_iterator
    : public std::iterator<std::input_iterator_tag, T>
{
public:
    constexpr collatz_iterator(T value)
        : value_(value)
    {}

    bool operator == (const collatz_iterator<T> & other) const
    { return value_ == other.value_; }

    bool operator != (const collatz_iterator<T> & other) const
    { return !(*this == other); }

    T operator * () const
    { return value_; }

    void operator ++ ()
    {
        if(value_ & 1)
            value_ = 3*value_ + 1;
        else
            value_ >>= 1;
    }

private:
    T value_;
};



template <class T>
class collatz_container
{
public:
    typedef collatz_iterator<T> iterator;
    typedef collatz_iterator<T> const_iterator;

    constexpr collatz_container(T value)
        : value_(value)
    {}

    constexpr iterator begin() const { return iterator(value_); }
    constexpr iterator end  () const { return iterator(1); }

private:
    T value_;
};



template <class T> constexpr collatz_container<T> collatz(T value)
{
    return collatz_container<T>(value);
}

}

#endif /* MATH_COLLATZ_H */
