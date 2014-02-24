#ifndef UTIL_FILTER_H
#define UTIL_FILTER_H

#include <iterator>

namespace util
{

// forward declarations
template <class C, class F>
class filter_iterator;
template <class C, class F>
class filter_container;



template <class C, class F>
class filter_iterator
    : public std::iterator<std::input_iterator_tag,
                           typename filter_container<C, F>::value_type>
{
public:
    typedef typename filter_container<C, F>::base_iterator base_iterator;
    typedef typename filter_container<C, F>::value_type    value_type;

    filter_iterator(const base_iterator & iter,
                    const filter_container<C, F> & parent)
        : parent_(parent), iter_(iter)
    {
        if(iter_ == parent_.end_)
            return;

        if(not parent_.filter_(*iter_))
            ++(*this);
    }

    bool operator == (const filter_iterator<C, F> & other) const
    { return iter_ == other.iter_; }

    bool operator != (const filter_iterator<C, F> & other) const
    { return !(*this == other); }

    value_type operator * () const
    { return *iter_; }

    void operator ++ ()
    {
        while(iter_ != parent_.end_)
        {
            ++iter_;
            if(parent_.filter_(*iter_))
                break;
        }
    }

private:
    const filter_container<C, F> & parent_;
    base_iterator iter_;
};



template <class C, class F>
class filter_container
{
public:
    typedef typename C::const_iterator base_iterator;
    typedef typename std::iterator_traits<base_iterator>::value_type value_type;
    typedef typename std::iterator_traits<base_iterator>::pointer    pointer;
    typedef typename std::iterator_traits<base_iterator>::reference  reference;
    typedef filter_iterator<C, F> iterator;
    typedef filter_iterator<C, F> const_iterator;

    constexpr filter_container(const C& container, F filter)
        : begin_(container.begin()), end_(container.end()), filter_(filter)
    {}

    constexpr iterator begin() const { return iterator(begin_, *this); }
    constexpr iterator end()   const { return iterator(end_  , *this); }

private:
    base_iterator begin_;
    base_iterator end_;
    F             filter_;

    friend class filter_iterator<C, F>;
};



template <class Container, class UnaryFunction>
constexpr filter_container<Container, UnaryFunction>
filter(const Container& container, UnaryFunction f)
{
    return filter_container<Container, UnaryFunction>(container, f);
}

}

#endif /* UTIL_FILTER_H */
