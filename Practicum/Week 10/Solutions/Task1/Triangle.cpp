#include "Triangle.hpp"

#include <cmath>
#include <stdexcept>
#include <new>

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
{
    // Условие за съществуване на триъгълник: a < c + b,  b < а + c,  c < a + b
    
    double a = p1.DistanceTo(p2), b = p2.DistanceTo(p3), c = p3.DistanceTo(p1);

    if(a >= c + b || b >= a + c || c >= a + b)
    {
        throw std::invalid_argument("The triangle does not exist!");
    }

    this->p1 = p1; this->p2 = p2; this->p3 = p3;
    this->a = a; this->b = b; this->c = c;
}

Triangle* Triangle::Clone() const 
{ 
    return new Triangle(*this); 
}

double Triangle::GetPerimeter() const
{
    return this->a + this->b + this->c;
}

double Triangle::GetArea() const
{
    double p = (this->a + this->b + this->c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;
    
    this->p1.Print(os);
    os << ' ';
    this->p2.Print(os);
    os << ' ';
    this->p3.Print(os);
}
