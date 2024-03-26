#include <iostream>
#include "point.h"

void read(Point& point)
{
    std::cout << "Enter value for x: ";
    std::cin >> point.x;
    streamRecovery(point.x);
    
    std::cout << "Enter value for y: ";
    std::cin >> point.y;
    streamRecovery(point.x);
}

void print(const Point& point)
{
    std::cout << '(' << point.x << ", " << point.y << ')' << std::endl;
}

void translate(Point& point, float offX, float offY)
{
    point.x += offX;
    point.y += offY;
}

void streamRecovery(float& num)
{
    while(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore();

        std::cout << "Invalid input! Try again: ";
        std::cin >> num;
    }
}
