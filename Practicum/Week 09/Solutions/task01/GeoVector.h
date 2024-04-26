#pragma once
#include "point.h"

class GeoVector: public Point
{
private:
    
public:
    GeoVector();
    GeoVector(const Point& A, const Point& B);
    GeoVector CreateVector(const Point& A, const Point& B);
    bool isCollinear(const GeoVector& other);
    ~GeoVector();
};

