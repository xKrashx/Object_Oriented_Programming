#pragma once
#include <iostream>
#include <cmath>

class Point
{
public:
    Point();
    Point(double x, double y);

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

    void Print(std::ostream &os) const;

    double DistanceTo(const Point &other) const;

    double DotProduct(const Point &other);
    double VectorLen();
    Point CreateVector(const Point& other);
    bool CheckForCollinearity(Point& other);
private:
    double x;
    double y;
};
