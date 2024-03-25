#include <iostream>
#include "String.hpp"

int main()
{
    String s("hello ");
    String a(" world");
    // String c = s.Combine(a);
    // s.Clear();
    std::cout << s[1] << std::endl;

    return 0;
}