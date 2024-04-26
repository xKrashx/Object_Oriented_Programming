#pragma once
#include "quadrilateral.h"

class Parallelogram : public Quadrilateral
{
private:
    
public:
    Parallelogram();
    Parallelogram(const Point& A, const Point& B, const Point& C, const Point& D);
    double GetArea();
    double GetPerimeter();
    void Print();
    ~Parallelogram();
};