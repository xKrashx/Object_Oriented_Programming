#include "Parallelogram.h"
#include "quadrilateral.h"

Parallelogram::Parallelogram(){}

Parallelogram::Parallelogram(const Point &A, const Point &B, const Point &C, const Point &D)
{
    GeoVector a(A,B);
    GeoVector b(C,D);
    GeoVector c(B,C);
    GeoVector d(A,D);
    
    if (!a.isCollinear(b) && !c.isCollinear(d)) throw std::invalid_argument("There must be two pairs of parallel sides");

    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

double Parallelogram::GetArea()
{
    return 0.0;
}
