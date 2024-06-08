/*
    Unify the definitions of the two sumArray functions into one
*/

#include <iostream>

template <typename T>
T sumArray(T const * const a, int const count) {

    T result = 0;
    for (int i = 0; i < count; ++i)
        result += a[i];
    return result;

}

void main(int argc, char *argv[])
{
    int a[5] = { 1, 2, 3, 4, 5 };
    float f[5] = { 0.f, 1.f, 2.f, 3.f, 4.f };

    std::cout << sumArray(a, 5) << " " << sumArray(f, 5) << std::endl;
}