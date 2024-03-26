#include <iostream>

#include "point.h"
#include "triangle.h"
#include "quadrilateral.h"

int main()
{
    std::cout << "Point" << std::endl;

    Point p;
    read(p);
    print(p);

    translate(p, 0.5, 0.5);
    std::cout << "The translated points are:" << std::endl;
    print(p);

    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "Triangle" << std::endl;

    Triangle tr;
    read(tr);
    print(tr);

    translate(tr, 1, 1);
    std::cout << "The translated points are:" << std::endl;
    print(tr);

    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "Quadrilateral" << std::endl;

    Quadrilateral q;
    read(q);
    print(q);

    translate(q, 2, 2);
    std::cout << "The translated points are:" << std::endl;
    print(q);

    std::cout << "-----------------------------------------------" << std::endl;

    return 0;
}
