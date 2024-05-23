#include "Triangle.hpp"

Triangle::Triangle(Point a, Point b, Point c)
{
    this->a = a;
    this->b = b;
    this->c = c;
};

double Triangle::GetArea() const
{
    double P = a.DistanceTo(b) + b.DistanceTo(c) + c.DistanceTo(a);

    double A = a.DistanceTo(b);
    double B = b.DistanceTo(c);
    double C = c.DistanceTo(a);

    double p = P / 2;
    return sqrt(p * (p - A) * (p - B) * (p - C));
}
double Triangle::GetPerimeter() const
{
    return a.DistanceTo(b) + b.DistanceTo(c) + c.DistanceTo(a);
}
void Triangle::Print(std::ostream &os)
{
    os << "A: ";
    a.Print(os);
    os << "B: ";
    b.Print(os);
    os << "C: ";
    c.Print(os);
};
