#pragma once
#include "Point.hpp"

class Triangle
{
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle(){};
    Triangle(Point a, Point b, Point c);
    double GetArea() const;
    void Print(std::ostream &os);
};
