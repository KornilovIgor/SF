#include <iostream>

template <typename T>
const T& Max(const T &a, const T &b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

template <typename T>
const T& Max(const T &a, const T &b, const T &c)
{
    return Max((Max(a, b)), c);
}