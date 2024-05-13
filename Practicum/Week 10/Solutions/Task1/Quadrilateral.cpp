#include "Quadrilateral.hpp"
#include "Triangle.hpp"

#include <cmath>
#include <stdexcept>
#include <new>

const double Quadrilateral::EPS = 0.0001;

Quadrilateral::Quadrilateral(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
    try
    {
        Triangle t1(p1, p2, p3), t2(p1, p3, p4);
    }
    catch(const std::invalid_argument& e)
    {
        throw std::invalid_argument("The quadrilateral does not exist!");
    }
    
    this->p1 = p1; this->p2 = p2; this->p3 = p3; this->p4 = p4;
}

Quadrilateral* Quadrilateral::Clone() const 
{ 
    return new Quadrilateral(*this); 
}

double Quadrilateral::GetPerimeter() const
{
    return p1.DistanceTo(p2) + p2.DistanceTo(p3) + p3.DistanceTo(p4) + p4.DistanceTo(p1);
}

double Quadrilateral::GetArea() const
{   
    Triangle t1(p1, p2, p3), t2(p1, p3, p4);
    return t1.GetArea() + t2.GetArea();
}

void Quadrilateral::Print(std::ostream& os) const
{
    if(os.fail() || os.bad()) return;

    this->p1.Print(os);
    os << ' ';
    this->p2.Print(os);
    os << ' ';
    this->p3.Print(os);
    os << ' ';
    this->p4.Print(os);
}

const Point& Quadrilateral::GetP1() const
{
    return this->p1;
}

const Point& Quadrilateral::GetP2() const
{
    return this->p2;
}

const Point& Quadrilateral::GetP3() const
{
    return this->p3;
}

const Point& Quadrilateral::GetP4() const
{
    return this->p4;
}
