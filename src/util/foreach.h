#ifndef UTIL_FOREACH_H
#define UTIL_FOREACH_H

namespace util
{
    template <typename T>
    class foreach
    {
    public:
        typedef const T * iterator;
        constexpr inline foreach(const T * array, size_t num)
            : begin_(array), end_(array + num)
        {}
        constexpr inline iterator begin() const { return begin_;  }
        constexpr inline iterator end  () const { return end_;    }

    private:
        iterator begin_, end_;
    };

}

template <typename T>
inline constexpr util::foreach<T> each(const T * array, size_t num)
{
    return util::foreach<T>(array, num);
}

template <typename T, std::size_t N>
inline constexpr util::foreach<T> each(const T (&array)[N])
{
    return util::foreach<T>(array, N);
}


#endif /* UTIL_FOREACH_H */
