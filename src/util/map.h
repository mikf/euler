#ifndef UTIL_MAP_H
#define UTIL_MAP_H

#include <iterator>
#include <type_traits>

namespace util
{

// forward declarations
template <class C, class F>
class map_iterator;
template <class C, class F>
class map_container;



template <class C, class F>
class map_iterator
    : public std::iterator<std::input_iterator_tag,
                           typename map_container<C, F>::value_type>
{
public:
    typedef typename map_container<C, F>::base_iterator base_iterator;
    typedef typename map_container<C, F>::value_type    value_type;

    constexpr map_iterator(const base_iterator & iter,
                           const map_container<C, F> & parent)
        : parent_(parent), iter_(iter)
    {}

    constexpr bool operator == (const map_iterator<C, F> & other) const
    { return iter_ == other.iter_; }

    constexpr bool operator != (const map_iterator<C, F> & other) const
    { return !(*this == other); }

    value_type operator * () const
    { return parent_.func_(*iter_); }

    void operator ++ ()
    { ++iter_; }

private:
    const map_container<C, F> & parent_;
    base_iterator iter_;
};



template <class C, class F>
class map_container
{
public:
    typedef typename C::const_iterator base_iterator;
    typedef typename std::iterator_traits<base_iterator>::value_type base_value_type;

    typedef typename std::result_of<F(base_value_type)>::type value_type;
    typedef map_iterator<C, F> iterator;
    typedef map_iterator<C, F> const_iterator;

    constexpr map_container(const C& container, F func)
        : container_(container), func_(func)
    {}

    constexpr iterator begin() const { return iterator(container_.begin(), *this); }
    constexpr iterator end  () const { return iterator(container_.end  (), *this); }

private:
    const C & container_;
    F func_;

    friend class map_iterator<C, F>;
};



template <class Container, class UnaryFunction>
constexpr map_container<Container, UnaryFunction>
map(const Container& container, UnaryFunction f)
{
    return map_container<Container, UnaryFunction>(container, f);
}


// common mappings
class to_digits
{
public:
    constexpr inline unsigned int operator () (const char c) const
    { return c - '0'; }
};

// ...


}

#endif /* UTIL_MAP_H */
