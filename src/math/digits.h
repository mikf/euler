#ifndef MATH_DIGITS_H
#define MATH_DIGITS_H

#include <iterator>

namespace math
{

template <class T>
class digits_iterator
    : public std::iterator<std::forward_iterator_tag, T>
{
public:

    constexpr digits_iterator(T value)
        : value_(value)
    {}

    bool operator == (const digits_iterator<T> & other) const
    { return value_ == other.value_; }

    bool operator != (const digits_iterator<T> & other) const
    { return !(*this == other); }

    constexpr T operator * () const
    { return value_ % 10; }

    void operator ++ ()
    { value_ /= 10; }

private:
    T value_;
};



template <>
class digits_iterator<const char *>
    : public std::iterator<std::forward_iterator_tag, int>
{
public:

    constexpr digits_iterator(const char * str)
        : str_(str)
    {}

    bool operator == (const digits_iterator<const char *> & other) const
    { return *str_ == *other.str_; }

    bool operator != (const digits_iterator<const char *> & other) const
    { return !(*this == other); }

    constexpr int operator * () const
    { return *str_ - '0'; }

    void operator ++ ()
    { ++str_; }

private:
    const char * str_;
};



template <class T>
class digits_container
{
public:
    typedef digits_iterator<T> iterator;
    typedef digits_iterator<T> const_iterator;

    constexpr digits_container(T value)
        : value_(value)
    {}

    constexpr iterator begin() const { return iterator(value_); }
    constexpr iterator end  () const { return iterator(0);      }

private:
    T value_;
};


template <class T>
constexpr digits_container<T> digits(T number)
{
    return digits_container<T>(number);
}

}

#endif /* MATH_DIGITS_H */
