#pragma once
#include "Point.hpp"
#include <vector>

class Quadrilateral
{
protected:
    Point A;
    Point B;
    Point C;
    Point D;
public:
    Quadrilateral(){};
    Quadrilateral(Point A, Point B, Point C, Point D);
    virtual double GetArea() const;
    virtual double GetPerimeter() const;
    void Print(std::ostream& os);
};
