#ifndef MATH_FIBONACCI_H
#define MATH_FIBONACCI_H

#include <iterator>

namespace math
{

template <class T>
class fibonacci_iterator
    : public std::iterator<std::forward_iterator_tag, T>
{
public:
    constexpr fibonacci_iterator(T value, T next)
        : value_(value), next_(next)
    {}

    bool operator == (const fibonacci_iterator<T> & other) const
    {
        return value_ == other.value_;
    }

    bool operator != (const fibonacci_iterator<T>  & other) const
    { return !(*this == other); }

    T operator * () const
    { return value_; }

    T* operator -> ()
    { return &value_; }

    const T* operator -> () const
    { return &value_; }

    void operator ++ ()
    {
        T tmp  = value_ + next_;
        value_ = next_;
        next_  = tmp;
    }

private:
    T value_, next_;
};

template <class T>
class fibonacci_container
{
public:
    typedef fibonacci_iterator<T> iterator;
    typedef fibonacci_iterator<T> const_iterator;

    constexpr fibonacci_container(T first, T second)
        : first_(first), second_(second)
    {}

    constexpr iterator begin() const { return iterator(first_, second_); }
    constexpr iterator end()   const { return iterator(0, 0); }

private:
    T first_, second_;
};


template <class T = std::uint32_t>
constexpr fibonacci_container<T> fibonacci(T first = 1, T second = 1)
{
    return fibonacci_container<T>(first, second);
}

}

#endif /* MATH_FIBONACCI_H */
