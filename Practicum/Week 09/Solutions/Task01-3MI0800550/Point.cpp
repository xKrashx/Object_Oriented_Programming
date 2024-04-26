#include "Point.hpp"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

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

void Point::Print(std::ostream &os) const
{
    os << "(" << this->x << " , " << this->y << ")" << std::endl;
}

double Point::DistanceTo(const Point &other) const
{
    return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
}

double Point::DotProduct(const Point &other)
{
    return this->x*other.x + this->y*other.y;
}

double Point::VectorLen()
{
    return sqrt(x*x + y*y);
}

Point Point::CreateVector(const Point &other)
{
    return Point(this->x - other.x, this->y - other.y);
}

bool Point::CheckForCollinearity(Point &other)
{
    return (this->x*other.y == this->y*other.x);
}
