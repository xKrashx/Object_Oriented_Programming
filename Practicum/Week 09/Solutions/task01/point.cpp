#include "point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

const int Point::GetX() const
{
    return this->x;
}
const int Point::GetY() const
{
    return this->y;
}

void Point::SetX(const int x)
{
    this->x = x;
}
void Point::SetY(const int x)
{
    this->y = y;
}

void Point::Print(std::ostream& os) const
{
    os << "(" << this->x << "," << this->y << ")" << std::endl;
}

double Point::DistanceTo(const Point& other) const
{
    return sqrt(pow(this->x - other.x,2) + pow(this->y - other.y,2));
}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}


Point::~Point(){}