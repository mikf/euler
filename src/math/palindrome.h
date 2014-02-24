#ifndef MATH_PALINDROME_H
#define MATH_PALINDROME_H

namespace math
{

template <unsigned int Base, class T>
bool is_palindrome(T value)
{
    static_assert(std::is_integral<T>::value, "");

    T original = value;
    T reverse  = 0;
    while(value)
    {
        reverse *= Base;
        reverse += value % Base;
        value   /= Base;
    }
    return original == reverse;
}

template <class T>
inline bool is_palindrome(T value)
{
    return is_palindrome<10, T>(value);
}

template <class T>
bool is_palindrome_slow(T value)
{
    std::string s = std::to_string(value);
    for(auto i = s.begin(), e = s.end()-1; i < e; ++i, --e)
        if(*i != *e)
            return false;
    return true;
}

}

#endif /* MATH_PALINDROME_H */
