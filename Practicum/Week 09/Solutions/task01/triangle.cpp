#include "triangle.h"

Triangle::Triangle(){}

Triangle::Triangle(const Point& A, const Point& B, const Point& C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}  

double Triangle::GetArea() const 
{
    double p = (A.DistanceTo(B) + B.DistanceTo(C) + C.DistanceTo(A)) / 2;
    return sqrt(p*(p - A.DistanceTo(B))*(p - B.DistanceTo(C))*(p - A.DistanceTo(C)));
}

Triangle::~Triangle(){};