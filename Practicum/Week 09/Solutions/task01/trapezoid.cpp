#include "trapezoid.h"
#include "GeoVector.h"

Trapezoid::Trapezoid(){}

Trapezoid::Trapezoid(const Point &A, const Point &B, const Point &C, const Point &D)
{
    GeoVector a(A,B);
    GeoVector b(C,D);
    GeoVector c(B,C);
    GeoVector d(A,D);

    if(!a.isCollinear(b)) throw std::invalid_argument("AB must be paralel to CD");
    if(a.isCollinear(b))
    {
        if(c.isCollinear(d)) throw std::invalid_argument("There must be onli two paralel sides");
    } 

    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}