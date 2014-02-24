#ifndef UTIL_FILE_H
#define UTIL_FILE_H

#include <iterator>
#include <string>

namespace util
{

// forward declarations
template <class T>
class file_iterator;
template <class T>
class file_container;



// TODO: implement random access iterator interface
template <class T>
class file_iterator
    : public std::iterator<std::input_iterator_tag, std::string>
{
public:
    file_iterator(T value, T step)
        : value_(value), step_(step)
    {}

    bool operator == (const file_iterator<T> & other) const
    { return value_ == other.value_; }

    bool operator != (const file_iterator<T> & other) const
    { return !(*this == other); }

    T operator * () const
    { return value_; }

    void operator ++ ()
    { value_ += step_; }

private:
    T value_, step_;
};



template <class T>
class file_container
{
public:
    typedef T                 value_type;
    typedef T*                pointer;
    typedef T&                reference;
    typedef file_iterator<T> iterator;
    typedef file_iterator<T> const_iterator;

    file_container(T start, T end, T step)
        : start_(start), end_(end), step_(step)
    {
        end_ = start + step * ((end - start - 1) / step + 1);
    }

    iterator begin() const { return iterator(start_, step_); }
    iterator end  () const { return iterator(end_  , step_); }

private:
    T start_, end_, step_;
    friend class file_iterator<T>;
};



template <class T>
file_container<T> file(T end)
{
    return file_container<T>(0, end, 1);
}

template <class T>
file_container<T> file(T start, T end, T step = 1)
{
    return file_container<T>(start, end, step);
}

}

#endif /* UTIL_RANGE_H */
