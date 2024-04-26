#include "Point.hpp"
#include "Quads.hpp"

int main()
{
    Point A(0, 0),
        B(2, 0),
        C(2, 2),
        D(0, 2);
    Square s(A, B, C, D);
    std::cout << s.GetArea() << std::endl;


    return 0;
}