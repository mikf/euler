#ifndef UTIL_STATIC_RANGE_H
#define UTIL_STATIC_RANGE_H

#include <iterator>

namespace util
{

// forward declarations
template <class T, T Step>
class static_range_iterator;
template <class T, T Start, T End, T Step = 1>
class static_range_container;



template <class T, T Step>
class static_range_iterator
    : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    typedef static_range_iterator<T, Step> _Iter;
    typedef std::iterator<std::random_access_iterator_tag, T> _Base;
    typedef typename _Base::difference_type difference_type;

    constexpr explicit static_range_iterator(const T value)
        : value_(value)
    {}

    // comparison
    constexpr bool operator == (const _Iter & other) const
    { return value_ == other.value_; }

    constexpr bool operator != (const _Iter & other) const
    { return value_ != other.value_; }

    constexpr bool operator  < (const _Iter & other) const
    { return value_  < other.value_; }

    constexpr bool operator  > (const _Iter & other) const
    { return value_  > other.value_; }

    constexpr bool operator <= (const _Iter & other) const
    { return value_ <= other.value_; }

    constexpr bool operator >= (const _Iter & other) const
    { return value_ >= other.value_; }

    // access
    constexpr const T& operator * () const
    { return value_; }

    T& operator * ()
    { return value_; }

    constexpr const T* operator -> () const
    { return &value_; }

    T* operator -> ()
    { return &value_; }

    // iteration
    void operator ++ ()
    { value_ += Step; }

    void operator -- ()
    { value_ -= Step; }

    void operator += (std::size_t n)
    { value_ += Step * n; }

    void operator -= (std::size_t n)
    { value_ -= Step * n; }

    constexpr _Iter operator + (std::size_t n) const
    { return {value_ + Step * n}; }

    constexpr _Iter operator - (std::size_t n) const
    { return {value_ - Step * n}; }

    constexpr difference_type operator - (const _Iter & other) const
    { return (value_ - other.value_) / Step; }

private:
    T value_;
};



template <class T, T Start, T End, T Step>
class static_range_container
{
public:
    enum { RealEnd = Start + Step * ((End - Start - 1) / Step + 1) };

    typedef T  value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef static_range_iterator<T, Step> iterator;
    typedef static_range_iterator<T, Step> const_iterator;

    constexpr explicit static_range_container() {}

    constexpr iterator begin() const { return iterator(Start);   }
    constexpr iterator end  () const { return iterator(RealEnd); }
};



template <int Start, int End, int Step = 1>
constexpr static_range_container<int, Start, End, Step> range()
{
    return static_range_container<int, Start, End, Step>();
}

template <int End>
constexpr static_range_container<int, 0, End, 1> range()
{
    return static_range_container<int, 0, End, 1>();
}

template <class T, T Start, T End, T Step = 1>
constexpr static_range_container<T, Start, End, Step> range()
{
    return static_range_container<T, Start, End, Step>();
}

}

#endif /* UTIL_RANGE_H */
