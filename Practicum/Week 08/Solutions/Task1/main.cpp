#include <iostream>
#include <cassert>

#include "ComplexNumber.hpp"

int main()
{
    ComplexNumber c1, c2(3, 4);

    std::cout << "c1: " << c1 << " => " << (!c1 ? "is the complex zero" : "is not the complex zero") << std::endl;
    std::cout << "c2: " << c2 << " => " << (!c2 ? "is the complex zero" : "is not the complex zero") << std::endl;
    
    std::cout << "Modulus of " << c2 << " is " << c2.AbsComplex() << std::endl;
    std::cout << "complex conjugate of " << c2 << " is " << c2.ComplexConjugate() << std::endl;

    c1.SetRe(1); c1.SetIm(2);
    std::cout << c1 << " + " << c2 << " = " << (c1 += c2) << std::endl;

    c1 -= c2;
    assert(c1 == ComplexNumber(1, 2));

    std::cout << c1 << " * " << c2 << " = " << (c1 * c2) << std::endl;
    std::cout << 3 << " * " << c1 << " = " << (3 * c1) << std::endl;

    ComplexNumber c3;
    std::cout << "Enter c3: ";
    std::cin >> c3;
    std::cout << "c3: " << c3 << std::endl;

    return 0;
}
