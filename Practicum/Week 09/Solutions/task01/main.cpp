#include <iostream>
#include "trapezoid.h"

int main()
{
    Point a(0,0);
    Point b(5,0);
    Point c(4,3);
    Point d(1,3);
    
    Trapezoid abcd(a,b,c,d);
    double face = abcd.GetArea();
    std::cout << face << std::endl;
    return 0;
}