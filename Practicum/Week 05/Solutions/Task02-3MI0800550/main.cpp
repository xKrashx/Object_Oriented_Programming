#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector v(5,2);
    // v.PushBack(21);

    // v.PushBack(123);

    std::cout << v.Capacity() << std::endl;
    v.SetAt(1, 12);
    std::cout << v << std::endl;
    std::cout << v[1] << std::endl;
    return 0;
}