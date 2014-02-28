#ifndef MATH_DIGITS_H
#define MATH_DIGITS_H

#include <iterator>
#include <type_traits>
#include <utility>
#include <cstring>
#include <gmpxx.h>

namespace math
{



template <class T>
class digits_iterator
    : public std::iterator<std::forward_iterator_tag,
        decltype(std::declval<T>() % 10U)>
{
public:
    typedef typename digits_iterator::value_type value_type;

    constexpr digits_iterator(const T& value)
        : value_(value)
    {}

    constexpr bool operator == (const digits_iterator & other) const
    { return value_ == other.value_; }

    constexpr bool operator != (const digits_iterator & other) const
    { return !(*this == other); }

    constexpr value_type operator * () const
    { return value_ % 10U; }

    void operator ++ ()
    { value_ /= 10U; }

private:
    T value_;
};

// template specialization for c-style strings
// example: "1234" -> 1, 2, 3, 4
template <>
class digits_iterator<const char *>
    : public std::iterator<std::forward_iterator_tag, unsigned int>
{
public:
    typedef typename digits_iterator::value_type value_type;

    constexpr digits_iterator(const char * str)
        : str_(str)
    {}

    constexpr bool operator == (const digits_iterator & other) const
    { return str_ == other.str_; }

    constexpr bool operator != (const digits_iterator & other) const
    { return !(*this == other); }

    constexpr value_type operator * () const
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

    // constructors
    constexpr digits_container(const T& value)
        : value_(value)
    {}

    constexpr digits_container(T&& value)
        : value_(std::move(value))
    {}

    // iterator access
    constexpr iterator begin() const { return {value_}; }
    constexpr iterator end  () const { return {0};      }

private:
    T value_;
};

// template specialization to support std::string objects
template <>
class digits_container<std::string>
{
public:
    typedef digits_iterator<const char *> iterator;
    typedef digits_iterator<const char *> const_iterator;

    // constructors
    digits_container(const std::string& str)
        : str_(str)
    {}

    digits_container(std::string&& str)
        : str_(std::move(str))
    {}

    // iterator access
    iterator begin() const { return {str_.c_str()}; }
    iterator end  () const { return {str_.c_str() + str_.size()}; }

private:
    std::string str_;
};

// template specialization to support c-style strings
template <>
class digits_container<const char *>
{
public:
    typedef digits_iterator<const char *> iterator;
    typedef digits_iterator<const char *> const_iterator;

    // constructor
    digits_container(const char * str)
        : str_(str)
    {}

    // iterator access
    iterator begin() const { return {str_}; }
    iterator end  () const { return {str_ + std::strlen(str_)}; }

private:
    const char * str_;
};

// special class to accommodate c-style strings of known size
template <std::size_t N>
class digits_container_ex
{
public:
    typedef digits_iterator<const char *> iterator;
    typedef digits_iterator<const char *> const_iterator;

    // constructor
    digits_container_ex(const char * str)
        : str_(str)
    {}

    // iterator access
    iterator begin() const { return {str_}; }
    iterator end  () const { return {str_ + N}; }

private:
    const char * str_;
};



inline digits_container<std::string> digits(mpz_class& num)
{ return { num.get_str() }; }

inline digits_container<std::string> digits(const mpz_class& num)
{ return { num.get_str() }; }

inline digits_container<std::string> digits(mpz_class&& num)
{ return { num.get_str() }; }

template <std::size_t N>
inline digits_container_ex<N-1> digits(const char (&num)[N])
{ return { num }; }

template <class T>
inline digits_container<typename std::remove_reference<T>::type> digits(T&& num)
{ return { std::forward<T>(num) }; }



}

#endif /* MATH_DIGITS_H */
