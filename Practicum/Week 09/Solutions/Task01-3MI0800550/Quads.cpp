#include "Quads.hpp"

Trapezoid::Trapezoid(Point &A, Point &B, Point &C, Point &D)
{
    Point AB = A.CreateVector(B);
    Point CD = C.CreateVector(D);

    Point AC = A.CreateVector(C);
    Point BD = B.CreateVector(D);

    if (AB.CheckForCollinearity(CD))
    {
        double dot_prod = AC.GetX() * BD.GetX() + AC.GetY() * BD.GetY();
        if (abs(dot_prod) > 0.00001)
        {
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
    }
}

Parallelogram::Parallelogram(Point &A, Point &B, Point &C, Point &D)
{
    Point AB = A.CreateVector(B);
    Point CD = C.CreateVector(D);
    Point BC = B.CreateVector(C);
    Point AD = A.CreateVector(D);

    if (AB.CheckForCollinearity(CD) && BC.CheckForCollinearity(AD))
    {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    else
        throw std::invalid_argument("Opposite sides must be parallel");
}

Rhombus::Rhombus(Point &A, Point &B, Point &C, Point &D)
{
    Point AB = A.CreateVector(B);
    Point CD = C.CreateVector(D);
    Point BC = B.CreateVector(C);
    Point AD = A.CreateVector(D);

    Point AC = A.CreateVector(C);
    Point BD = B.CreateVector(D);

    if (AB.VectorLen() == CD.VectorLen() &&
        CD.VectorLen() == BC.VectorLen() &&
        BC.VectorLen() == AD.VectorLen() &&
        AD.VectorLen() == AB.VectorLen())
    {

        if (AB.CheckForCollinearity(CD) && BC.CheckForCollinearity(AD))
        {
            double dot_product = AC.GetX() * BD.GetX() + AC.GetY() * BD.GetY();

            if (abs(AC.DotProduct(BD)) < 0.00001)
            {
                this->A = A;
                this->B = B;
                this->C = C;
                this->D = D;
            }
            else
                throw std::invalid_argument("Diagonals must be perpendicular");
        }
        else
            throw std::invalid_argument("Opposite sides must be parallel");
    }
    else
        throw std::invalid_argument("Sides must be equal");
}

Rectangle::Rectangle(Point &A, Point &B, Point &C, Point &D)
{
    Point AB = A.CreateVector(B);
    Point CD = C.CreateVector(D);
    Point BC = B.CreateVector(C);
    Point AD = A.CreateVector(D);

    if (AB.DotProduct(BC) < 0.0001 && CD.DotProduct(AD) < 0.0001)
    {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    else
        throw std::invalid_argument("Sides must be perpendicular");
}

Square::Square(Point &A, Point &B, Point &C, Point &D)
{
    Point AB = A.CreateVector(B);
    Point CD = C.CreateVector(D);
    Point BC = B.CreateVector(C);
    Point AD = A.CreateVector(D);

    if (AB.VectorLen() == CD.VectorLen() &&
        CD.VectorLen() == BC.VectorLen() &&
        BC.VectorLen() == AD.VectorLen() &&
        AD.VectorLen() == AB.VectorLen())
    {
        if (AB.DotProduct(BC) < 0.0001 && CD.DotProduct(AD) < 0.0001)
        {
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }
        else
            throw std::invalid_argument("Sides must be perpendicular");
    }
    else
        throw std::invalid_argument("Sides must be equal");
}
