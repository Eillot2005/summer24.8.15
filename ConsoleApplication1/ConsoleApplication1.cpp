#include <iostream>

template <typename T>
struct Cls
{
    static void func(T& b)
    {
        std::cout << 1 << std::endl;
    }
};

template <>
struct Cls<int>
{
    static void func(int& b)
    {
        std::cout << 2 << std::endl;
    }
};

template <typename T>
void some_func(T&& a)
{
    Cls<T>::func(a);
}

int main()
{
    int i{ 3 };
    some_func(i);
    some_func(3);
}