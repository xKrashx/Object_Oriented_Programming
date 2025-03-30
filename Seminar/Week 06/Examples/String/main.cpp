#include <iostream>
#include "String.hpp"

int main(){

    String s("Hello World");

    String s1(s), s2;

    std::cout << s2.Length() << '\n';

    s2 = s;

    std::cout << s.c_str() << '\n';
    std::cout << s1.c_str() << '\n';
    std::cout << s2.c_str() << '\n';

    s.Append(" I am Mario");
    std::cout << s.Length() << '\n';

    for(size_t i = 0; i < s.Length(); ++i)
        if(s.At(i) == '!')
            std::cout << "Exclamation\n";

    String s3 = s.Combine(String(" Pesho"));
    std::cout << s3.c_str() << '\n';
    
    std::cout << s3.Empty() << '\n';
    s3.Clear();
    std::cout << s3.Empty() << '\n';

    return 0;

}