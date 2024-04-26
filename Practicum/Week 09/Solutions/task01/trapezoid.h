#pragma once
#include "quadrilateral.h"

class Trapezoid: public Quadrilateral
{
private:
    
public:
    Trapezoid();
    Trapezoid(const Point& A, const Point& B, const Point& C, const Point& D);
    // double GetArea();
    // double GetPerimeter();
    // void Print(std::ostream& os);
    
};