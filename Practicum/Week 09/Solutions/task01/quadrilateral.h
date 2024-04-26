#pragma once
#include "point.h"
#include "GeoVector.h"

class Quadrilateral
{
protected:
    Point A;
    Point B;
    Point C;
    Point D;
public:
    Quadrilateral(){};
    Quadrilateral(const Point& A, const Point& B, const Point& C, const Point& D);
    virtual double GetArea();
    virtual double GetPerimeter();
    virtual void Print(std::ostream& os);
    ~Quadrilateral();
};