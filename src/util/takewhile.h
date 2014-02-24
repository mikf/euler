#ifndef UTIL_TAKEWHILE_H
#define UTIL_TAKEWHILE_H

#include <iterator>

namespace util
{

// forward declarations
template <class C, class P>
class takewhile_iterator;
template <class C, class P>
class takewhile_container;



template <class C, class P>
class takewhile_iterator
    : public std::iterator<std::input_iterator_tag,
                           typename takewhile_container<C, P>::value_type>
{
public:
    typedef typename takewhile_container<C, P>::base_iterator base_iterator;
    typedef typename takewhile_container<C, P>::value_type    value_type;

    constexpr takewhile_iterator(const base_iterator & iter,
                                 const takewhile_container<C, P> & parent,
                                 bool active)
        : parent_(parent), iter_(iter), active_(active)
    {}

    bool operator == (const takewhile_iterator<C, P> & other) const
    {
        if(active_)
        {
            if(other.active_)
                return iter_ == other.iter_;
            else
                return false;
        }
        else
        {
            return !other.active_;
        }
    }

    bool operator != (const takewhile_iterator<C, P> & other) const
    { return !(*this == other); }

    value_type operator * () const
    { return *iter_; }

    void operator ++ ()
    {
        ++iter_;
        if(iter_ == parent_.container_.end() or not parent_.predicate_(*iter_))
            active_ = false;
    }

private:
    const takewhile_container<C, P> & parent_;
    base_iterator iter_;
    mutable bool active_;
};



template <class C, class P>
class takewhile_container
{
public:
    typedef typename C::const_iterator base_iterator;
    typedef typename std::iterator_traits<base_iterator>::value_type value_type;

    typedef takewhile_iterator<C, P> iterator;
    typedef takewhile_iterator<C, P> const_iterator;

    constexpr takewhile_container(const C & container, P pred)
        : container_(container), predicate_(pred)
    {}

    constexpr iterator begin() const { return iterator(container_.begin(), *this, true ); }
    constexpr iterator end  () const { return iterator(container_.end  (), *this, false); }

private:
    const C & container_;
    P         predicate_;

    friend class takewhile_iterator<C, P>;
};



template <class Container, class UnaryFunction>
constexpr takewhile_container<Container, UnaryFunction>
takewhile(const Container& container, UnaryFunction pred)
{
    return takewhile_container<Container, UnaryFunction>(container, pred);
}

}

#endif /* UTIL_TAKEWHILE_H */
