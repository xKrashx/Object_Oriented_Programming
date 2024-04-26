#pragma once
#include "point.h"

class Triangle
{
private:
    Point A;
    Point B;
    Point C;
public:
    Triangle();
    Triangle(const Point& A, const Point& B, const Point& C);   
    double GetArea() const;
    ~Triangle();
};
