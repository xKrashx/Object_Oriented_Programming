#pragma once
#include <fstream> 
#include <cmath>

class Point
{
protected:
    int x;
    int y;
public:
    Point();
    Point(const int x, const int y);

    const int GetX() const;
    const int GetY() const;
    
    void SetX(const int x);
    void SetY(const int y);

    void Print(std::ostream& os) const;
    double DistanceTo(const Point& other) const;
    Point& operator=(const Point& other);
    
    ~Point();
};

