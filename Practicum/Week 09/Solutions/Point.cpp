#include "Point.hpp"

#include <cmath>

Point::Point() : Point(0, 0)
{ }

Point::Point(double x, double y) : x(x), y(y)
{ }

double Point::GetX() const 
{
    return this->x;
}

double Point::GetY() const 
{
    return this->y;
}

void Point::SetX(double x) 
{
    this->x = x;
}

void Point::SetY(double y) 
{
    this->y = y;
}

void Point::Print(std::ostream& os) const 
{
    if(os.fail() || os.bad()) return;
    os << '(' << this->x << ',' << this->y << ')';
}

double Point::DistanceTo(const Point& other) const 
{
    return sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
}
