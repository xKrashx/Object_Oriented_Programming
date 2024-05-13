#include "Circle.hpp"

#include <stdexcept>
#include <new>

const double Circle::PI = 3.14;

Circle::Circle(const Point& center, double radius)
{
    if(radius < 0)
    {
        throw std::invalid_argument("The circle does not exist!");
    }

    this->center = center;
    this->radius = radius;
}

Circle* Circle::Clone() const 
{ 
    return new Circle(*this); 
}

double Circle::GetPerimeter() const
{
    return 2 * PI * this->radius;
}

double Circle::GetArea() const
{
    return PI * this->radius * this->radius;
}

void Circle::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;
    
    os << "center: "; this->center.Print(os);
    os << ", r = " << this->radius;
}
