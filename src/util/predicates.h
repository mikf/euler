#ifndef UTIL_PREDICATES_H
#define UTIL_PREDICATES_H

#define MAKE_PREDICATE(name, op) \
    template <class T> class pred_##name { \
    public: \
        constexpr pred_##name (T value) : value_(value) {} \
        template <class U> \
        constexpr bool operator () (const U& val) const \
        { return val < value_; } \
    private: \
        T value_; \
    }; \
    template <class T> \
    constexpr pred_##name <T> name (T value) { return {value}; } \
    \
    template <class T, T Value> class pred_##name##_static { \
    public: \
        template <class U> \
        constexpr bool operator () (const U& val) const \
        { return val < Value; } \
    }; \
    template <int Value> \
    constexpr pred_##name##_static<int, Value> name() { return {}; } \
    template <class T, T Value = 0> \
    constexpr pred_##name##_static<T, Value> name () { return {}; } \

namespace util
{

MAKE_PREDICATE(less   , < );
MAKE_PREDICATE(greater, > );
MAKE_PREDICATE(equal  , ==);


class even {
public:
    template <class U> constexpr bool operator () (const U& val) const
    { return val % 2 == 0; }
};

class odd {
public:
    template <class U> constexpr bool operator () (const U& val) const
    { return val % 2 == 1; }
};


};

#undef MAKE_PREDICATE
#endif /* UTIL_PREDICATES_H */
