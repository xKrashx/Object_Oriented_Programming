#ifndef __POINT_H
#define __POINT_H

struct Point
{
    float x, y;
};

void read(Point& point);
void print(const Point& point);

void translate(Point& point, float offX, float offY);

void streamRecovery(float& num);

#endif
