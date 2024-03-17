#include <iostream>
#include "complex.hpp"

int main(){
    Complex c;
    Complex p;
    Complex sum;
    Complex mult;
    Complex subt;
    Complex test(5,6);
    c.setIm(4);
    c.setRe(8);
    p.setIm(2);
    p.setRe(16);
    sum = c+p;
    subt = c-p;
    mult = c*p;
    c.print();
    std::cout<<std::endl;
    p.print();
    std::cout<<std::endl;
    sum.print();
    std::cout<<std::endl;
    subt.print();
    std::cout<<std::endl;
    mult.print();
    std::cout<<std::endl;
    test.print();
    return 0;
}