#ifndef __TRIANGLE_HPP
#define __TRIANGLE_HPP

#include <iostream>

#include "Point.hpp"

class Triangle
{
    public:
        Triangle(const Point& p1, const Point& p2, const Point& p3);

        double GetPerimeter() const;
        double GetArea() const;
        
        void Print(std::ostream& os = std::cout) const;

    private:
        Point p1, p2, p3;
        double a, b, c;
};

#endif
