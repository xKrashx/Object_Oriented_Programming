#include "Quadrilateral.hpp"
#include "Triangle.hpp"

Quadrilateral::Quadrilateral(Point A, Point B, Point C, Point D)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
}

double Quadrilateral::GetArea() const
{
    Triangle ABC(A, B, C),
        CAD(C, A, D);

    return ABC.GetArea() + CAD.GetArea();
}

double Quadrilateral::GetPerimeter() const
{
    double a = A.DistanceTo(B);
    double b = B.DistanceTo(C);
    double c = C.DistanceTo(D);
    double d = D.DistanceTo(A);

    return a + b + c + d;
}

void Quadrilateral::Print(std::ostream& os)
{
    os << "A:"; A.Print(os);
    os << "B:"; B.Print(os);
    os << "C:"; C.Print(os);
    os << "D:"; D.Print(os);
}
