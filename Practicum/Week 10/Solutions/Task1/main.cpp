#include <iostream>
#include <stdexcept>

#include "Point.hpp"
#include "Triangle.hpp"
#include "Quadrilateral.hpp"
#include "Trapezoid.hpp"
#include "Parallelogram.hpp"
#include "Rhombus.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "FigureCollection.hpp"

void TestFigures()
{
    std::cout << "Circle" << std::endl;
    try
    {
        Circle c(Point(0, 0), 2);
        c.Print();
        std::cout << "\nP = " << c.GetPerimeter() << std::endl; // P = 12.56
        std::cout << "S = " << c.GetArea() << std::endl;        // S = 12.56
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----------------------------------" << std::endl;
    try
    {
        Triangle t1(Point(0, 0), Point(1, 0), Point(2, 0));
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Triangle" << std::endl;
    try
    {
        Triangle t2(Point(0, 0), Point(2, 0), Point(1, 1));
        t2.Print();
        std::cout << "\nP = " << t2.GetPerimeter() << std::endl; // P = 4.82843
        std::cout << "S = " << t2.GetArea() << std::endl;        // S = 1
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Quadrilateral" << std::endl;
    try
    {
        Quadrilateral q(Point(0, 0), Point(2, 0), Point(3, 2), Point(1, 3));
        q.Print();
        std::cout << "\nP = " << q.GetPerimeter() << std::endl; // P = 9.63441
        std::cout << "S = " << q.GetArea() << std::endl;        // S = 5.5
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }   
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Trapezoid" << std::endl;
    try
    {
        Trapezoid tr(Point(0, 0), Point(2, 0), Point(3, 2), Point(-3, 2));
        tr.Print();
        std::cout << "\nP = " << tr.GetPerimeter() << std::endl; // P = 13.8416
        std::cout << "S = " << tr.GetArea() << std::endl;        // S = 8
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    } 
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Parallelogram" << std::endl;
    try
    {
        Parallelogram p(Point(0, 0), Point(3, 0), Point(4, 2), Point(1, 2));
        p.Print();
        std::cout << "\nP = " << p.GetPerimeter() << std::endl; // P = 10.4721
        std::cout << "S = " << p.GetArea() << std::endl;        // S = 6
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    } 
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Rhombus" << std::endl;
    try
    {
        Rhombus rh(Point(0, 0), Point(2, 0), Point(3, 1.7321), Point(1, 1.7321));
        rh.Print();
        std::cout << "\nP = " << rh.GetPerimeter() << std::endl; // P = 8
        std::cout << "S = " << rh.GetArea() << std::endl;        // S = 3.4642
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    } 
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Rectangle" << std::endl;
    try
    {
        Rectangle rec(Point(0, 0), Point(3, 0), Point(3, 2), Point(0, 2));
        rec.Print();
        std::cout << "\nP = " << rec.GetPerimeter() << std::endl; // P = 10
        std::cout << "S = " << rec.GetArea() << std::endl;        // S = 6
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Square" << std::endl;
    try
    {
        Square sq(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
        sq.Print();
        std::cout << "\nP = " << sq.GetPerimeter() << std::endl; // P = 8
        std::cout << "S = " << sq.GetArea() << std::endl;        // S = 4
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void TestFigureCollection()
{
    FigureCollection collection;

    collection.Add(Circle(Point(0, 0), 2));
    collection.Add(Triangle(Point(0, 0), Point(2, 0), Point(1, 1)));
    collection.Add(Quadrilateral(Point(0, 0), Point(2, 0), Point(3, 2), Point(1, 3)));
    collection.Add(Trapezoid(Point(0, 0), Point(2, 0), Point(3, 2), Point(-3, 2)));
    collection.Add(Parallelogram(Point(0, 0), Point(3, 0), Point(4, 2), Point(1, 2)));
    collection.Add(Rhombus(Point(0, 0), Point(2, 0), Point(3, 1.7321), Point(1, 1.7321)));
    collection.Add(Rectangle(Point(0, 0), Point(3, 0), Point(3, 2), Point(0, 2)));
    collection.Add(Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));

    unsigned int size = collection.GetSize();
    std::cout << "size = " << size << std::endl;

    for(int i = 0; i < size; i++)
    {
        collection.Print(i);
        std::cout << "P = " << collection[i]->GetPerimeter() << std::endl;
        std::cout << "S = " << collection[i]->GetArea() << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }

    while(size > 0)
    {
        collection.Remove(size - 1);
        size--;
    }
    
    std::cout << "size = " << size << std::endl;
    collection.Print();
}

int main()
{
    // TestFigures();
    TestFigureCollection();
    return 0;
}
