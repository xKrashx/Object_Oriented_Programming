#include "GeoVector.h"

GeoVector::GeoVector()
{
    this->x = 0;
    this->y = 0;
}

GeoVector::GeoVector(const Point& A, const Point& B)
{
    this->x = B.GetX() - A.GetY();
    this->y = B.GetY() - A.GetY();
}
GeoVector GeoVector::CreateVector(const Point &A, const Point &B)
{
    return GeoVector(A,B);
}

bool GeoVector::isCollinear(const GeoVector& other)
{
    return this->x * other.y == this->y * other.x;
}

GeoVector::~GeoVector(){}