#include <iostream>
#include "String.hpp"

int main(){

    String s("Hello World");

    String s1(s), s2;

    std::cout << s2.Length() << '\n';

    std::cin >> s2;

    std::cout << s2 << '\n';
    std::cout << s2.Length() << '\n';

    s2 = s;

    std::cout << s << '\n';
    std::cout << s1 << '\n';
    std::cout << s2 << '\n';

    s += " I am Mario";
    s += '!';
    std::cout << s.Length() << '\n';

    for(size_t i = 0; i < s.Length(); ++i)
        if(s[i] == '!')
            std::cout << "Exclamation\n";

    String s3 = s + String(" Pesho");
    std::cout << s3 << '\n';
    
    std::cout << s3.Empty() << '\n';
    s3.Clear();
    std::cout << s3.Empty() << '\n';

    return 0;

}