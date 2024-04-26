#pragma once
#include "Quadrilateral.hpp"

class Trapezoid : public Quadrilateral
{
private:
    /* data */
public:
    Trapezoid(Point A, Point B, Point C, Point D);
    ~Trapezoid(){};
};

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram() = default;
    Parallelogram(Point A, Point B, Point C, Point D);
    ~Parallelogram(){};
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(Point A, Point B, Point C, Point D);
    ~Rectangle(){};
};

class Square : public Parallelogram
{
public:
    Square(Point A, Point B, Point C, Point D);
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(Point A, Point B, Point C, Point D);
    ~Rhombus(){};
};
